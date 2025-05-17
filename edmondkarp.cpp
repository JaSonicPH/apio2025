#include <bits/stdc++.h>
using namespace std;

#define cerr if(true)cerr
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

// start edmonds karp alg

int n;

vector<vector<int>> caps;
unordered_map<int, vector<int>> adjList;

int bfs(int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF(INT)});

    while(!q.empty()) {
        int curr = q.front().fi;
        int flow = q.front().se;
        q.pop();

        for(int i : adj[curr]) {
            if(parent[i] == -1 && caps[curr][i]) {
                parent[i] = curr;
                int new_flow = min(flow, caps[curr][i]);
                if(i == t) {
                    return new_flow;
                }
                q.push({i, new_flow});
            }
        }
    }
}

int maxflow(int s, int t) {
    int res = 0;
    vector<int> parent(n);
    int new_flow;

    while(new_flow += bfs(s, t, parent)) {
        flow += new_flow;
        int node = t;
        while(node != s) {
            int prev = parent[node];
            caps[prev][node] -= new_flow;
            caps[node][prev] += new_flow;
            node = prev;
        } 
    }

    return flow;
}

// end edmonds karp alg


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