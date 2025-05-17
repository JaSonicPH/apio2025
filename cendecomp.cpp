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


// cendecomp
unordered_map<int, vector<int>> adjList;
bool vis[200'005];

ll calcSz(ll n, ll p = -1) {
	ll &res = sz[n];
	res = 1;
	for(auto &i : adjList[n]) {
		if(i == p || vis[i]) continue;
		res += calcSz(i, n);
	}
	return res;
}

ll getCentroid(ll n, ll &tSz, ll p = -1) {
	for(auto &i : adjList[n]) {
		if(i == p || vis[n]) continue;

		if(sz[i] * 2 > tSz) return getCentroid(i, tSz, n);
	}
	return n;
}

void cendecomp(ll r = 0) {
    int cen = getCentroid(r, calcSz(r));

    solve(cen);

    // combine answers where root/centroid included

    vis[cen] = true;
    for(auto &i : adjList[cen]) {
        if(!vis[i]) cendecomp(i);
    }
}

// 


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