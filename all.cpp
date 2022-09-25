class Node {
	public:
	int val = 0;
	int lazy = 0;
	Node() {
		val = 0;
		lazy = 0;
	};	
};

class SGTree{
	int left(int ind) {
		return 2 * ind + 1;
	}
	
	int right(int ind) {
		return 2 * ind + 2;
	}
	
	Node merge(Node left, Node right) {
		Node par = Node();
		par.val = left.val + right.val;
		return par;
	}
	
	public:
	vector<Node>seg;
	SGTree(int N) {
		seg.resize(4 * N + 1);
	}	
	
	void build(int ind, int low, int high, vector<int> &arr) {
		if(low == high) {
			seg[ind].val = arr[low];
			return;
		}
		
		int mid = (low + high) >> 1;
		
		build(left(ind), low, mid, arr);
		build(right(ind), mid + 1, high, arr);
		
		seg[ind] = merge(seg[left(ind)], seg[right(ind)]);
	}
	
	void update(int ind, int low, int high, int i, int val) {
		if(low == high) {
			seg[ind].val = val;
			return;
		}
		
		int mid = (low + high) >> 1;
		
		if(i >= low && i <= mid) {
			update(left(ind), low, mid, i, val);
		} else {
			update(right(ind), mid + 1, high, i, val);
		}
		
		seg[ind] = merge(seg[left(ind)], seg[right(ind)]);
	}
	
	Node query(int ind, int low, int high, int l, int r) {
		//update the current ind with its lazy
		if(seg[ind].lazy) {
			seg[ind].val += (high - low + 1) * seg[ind].lazy;
			if(low != high) {
				seg[left(ind)].lazy += seg[ind].lazy;
				seg[right(ind)].lazy += seg[ind].lazy;	
			}
			//make the lazy update of current node = 0;
			seg[ind].lazy = 0;
		}
		//if out of range
		if(r < low || high < l) {
			Node base;
			return base;
		}
		
		//complete overlap
		if(low >= l && high <= r) {
			return seg[ind];
		}
		
		int mid = (low + high) >> 1;
		
		Node left_query = query(left(ind), low, mid, l, r);
		Node right_query = query(right(ind), mid + 1, high, l, r);
		
		return merge(left_query, right_query);
	}
	
	void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
		// step 1 : first update the previous lazy if any
		
		if(seg[ind].lazy != 0) {
			seg[ind].val += (high - low + 1) * seg[ind].lazy;
			if(low != high) {
				seg[left(ind)].lazy += seg[ind].lazy;
				seg[right(ind)].lazy += seg[ind].lazy;	
			}
			//make the lazy update of current node = 0;
			seg[ind].lazy = 0;
		}
		
		//no overlap the return
		if(r < low || l > high || low > high) return;
		
		//current range lies complely inside the given range
		if(low >= l && high <= r) {
			seg[ind].val += (high - low + 1) * val;
			
			//propagate the update to childs and return
			if(low != high) {
				seg[left(ind)].lazy += val;
				seg[right(ind)].lazy += val;
			}
			
			return;
		}
		
		//now the current range partially overlaps
		int mid = (low + high) >> 1;
		
		rangeUpdate(left(ind), low, mid, l, r, val);
		rangeUpdate(right(ind), mid + 1, high, l, r, val);
		
		seg[ind] = merge(seg[left(ind)], seg[right(ind)]);
	}
};
class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEndOfWord;
    map<char, int> num;
};
 
TrieNode* root;
TrieNode* getNewTrieNode() {
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    return pNode;
}
bool search(string key) {
    TrieNode *p = find(key);
    return p != NULL && p -> isEndOfWord;
}
TrieNode* find(string key) {
    TrieNode *p = root;
    for(int i = 0; i < key.size() && p != NULL; ++ i)
        p = p -> next[key[i] - 'a'];
    return p;
}
void insertWord(string word) {
    TrieNode* current = root;
    char s;
    for (int i = 0; i < word.length(); i++) {
        s = word[i];
        if (current->children.find(s)
            == current->children.end()) {
            TrieNode* p = getNewTrieNode();
            (current->children)[s] = p;
            (current->num)[s] = 1;
        }
        else {
            current->num[s] = (current->num)[s] + 1;
        }
        current = (current->children)[s];
    }
    current->isEndOfWord = true;
}
