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

// binlift code start

int lg2(int n) {
    int res = 0;
    while(n > 1){n>>=1;res++;}
    return res;
}

int n;
int mxj = lg2(n);

int jump[n][mxj];
unordered_map<int, vector<int>> adjList;
int depths[n];
int depth = 1;

void dfs(int n, int p = -1) {
    jump[n][0] = p;
    for(int i = 1; 1ll<<i < depth; i++) {
        jump[n][i] = jump[jump[n][i-1]][i-1];
    }

    for(auto i : adjList[n]) if (i != p) {
        depth++;
        dfs(i, n);
    }
}

// run dfs somewhere at the start

int jump(int n, int k) {
    int res = n;
    for(int i = mxj; i >= 0; i--) {
        ll jMt = 1ll<<i;
        if(k >= jMt) {
            res = jump[res][i];
            k -= jMt;
        }
    }
    return res;
}

void lca(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b);
    // b is lower

    for(int i = mxj; i >= 0 && depth[a] < depth[b]; i--) if (depth[b] - depth[a] >= 1ll<<i) b = jump[b][i];

    for(int i = mxj; i >= 0; i--) {
        if(jump[a][i] != jump[b][i]) a = jump[a][i], b = jump[b][i];
    }

    if(a != b) return jump[a][0];
    else return a;
}

// binlift code end

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