#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <sstream>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
typedef pair<ll,int> pi;

struct Edge {
    int a, b;
    ll cost;
    Edge(int a,int b,ll cost){
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
    vector<ll> d(n);
    vector<ll> p(n, -1);
    ll x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << '\n';
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<ll> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES \n";
        for (int v : cycle)
            cout << v+1 << ' ';
        cout << endl;
    }
}
int main()
{
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({a,b,c});
    }
    // belmanford
    solve();
    return 0;
}