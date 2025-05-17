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

// merge sort start 

void conquer(int l_l, int l_r, int r_l, int r_r) {
    // i do not want to write the entire thing just put the sort bruh
    
    // i can vibe code this in contest
}

void divide(int l, int r) {
    if(l != r) {
        int m = (l+r)>>1;
        divide(l, m), divide(m+1, r);
    }
    conquer(l, m, m+1, r);
}

// merge sort end

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