#include <bits/stdc++.h>
using namespace std;

#define cerr if(true)cout
#define ll long long
#define str string
#define ull unsigned long long

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<ll, ll>> v2ll;
typedef vector<bool> vb;

#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define F0R(i, a) for(int i=0; i<(a); i++)
#define FORd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for(int i = (a)-1; i >= 0; i--)

const ll seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(seed);

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
void pmin(ll& a, ll b) {a = min(a, b);};
void pmax(ll& a, ll b) {a = max(a, b);};

#define INF(dtype) numeric_limits<dtype>::max()
#define NINF(dtype) numeric_limits<dtype>::min()

const ll MOD = 1E7 + 1;
const char nl = '\n';
const char sp = ' ';

// start treap code

// stores a node
struct Node{
    ll k, p;
    int cnt;
    Node *l, *r;
    Node() {}
    item(ll key) : k(key), p(rng()), cnt(0), l(nullptr), r(nullptr) {}
    item(ll key, ll prio) : k(key), p(prio), cnt(0), l(nullptr), r(nullptr) {}
}

typedef *Node treap;

// splits a treap into two and puts them into l and r (assign l = r = nullptr before!)
void splitTreap(treap t, ll key, treap &l, treap &r) {
    if(!t) l = r = nullptr;
    else if (t->k <= key) splitTreap(t->r, key, t->r, r), l = t;
    else splitTreap(t->l, key, l, t->l), r = t;
}

// inserts a treap element s into the treap t
void insertIntoTreap(treap s, treap &t) {
    if(!t) t = s;
    else if(s->p > t->p) splitTreap(s, s->k, s->l, s->r), t = s;
    else insertIntoTreap(s, t->k < s->k ? t->l : t->r);
}

// merges two treaps, t is the root, l, r must be children of t (?)
void mergeTreaps(treap &t, treap l, treap r) {
    if(!l || !r) t = l ? l : r;
    else if (l->p > r->p) mergeTreaps(l->r, l->r, r), t = l;
    else mergeTreaps(r->r, l, r->r), t = r;
}

// erases an item from the treap
void eraseTreapItem(treap &t, ll key) {
    if(t->k == key) {
        pitem th = t;
        mergeTreaps(t, t->l, t->r);
        delete th;
    } else eraseTreapItem(key < t->k ? t->l : t->r, key);
}

// unite two treaps and return a treap
treap uniteTreaps(treap l, treap r) {
    if(!l || !r) return l ? l : r;
    if(l->p < r->p) swap(l, r);
    treap lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}

int cnt(treap t) {
    return t ? t->cnt : 0;
}

void upd_cnt(treap t) {
    if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

// end treap code



void tc(int testCaseNo) {
    int n; cin >> n;
    
    cout << n;
    return;
}

int main() {
    fastIO

    int t = 1;
    // cin >> t;
    F0R(i, t) {
        tc(i+1);
    }
}