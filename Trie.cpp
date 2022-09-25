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
