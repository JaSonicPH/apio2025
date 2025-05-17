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

// mo's algo start

ll sqrt(ll &n, ll l, ll r) {
    if(l == r+1) return l; 
    int m = (l+r)>>2;
    if(m*m > n) return sqrt(n, l, m);
    else return sqrt(n, m, r);
}

void remove(int idx); // remove an element
void add(int idx); // add an element
int get_answer(); // get answer for current range

int bSz = sqrt(n, -1, n+1);

struct Query{
    int l, r, idx;

    bool operator<(Query o) {
        return make_pair(l/bSz, r) < make_pair(o.l/bSz, r);
    }
};

vector<int> mos(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;

    for(Query q : queries) {
        while(cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while(cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }

        while(cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while(cur_r > q.r) {
            remove(cur_r);
            cur_r++;
        }
        
        answers[q.idx] = get_answer();
    }
    return answers;
}

// mo's algo end

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