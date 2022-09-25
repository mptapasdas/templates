#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

const int mod = 1e9+7;
const long long inf = 1e18;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair <int, int> pii;
typedef pair <ll,ll> pll;
typedef vector <int> vint;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef vector <string> vs;
typedef priority_queue <int> pqi;

#define contains(v,id) (v).find(id)!=(v).end()
#define all(id) (id).begin(), (id).end()
#define color(id, D) memset((id), D, sizeof(id))

#define debug(id) cout << #id <<" "; _print(id); cout << endl;

void _print(ll t) {cout << t;}//✅🔥
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

