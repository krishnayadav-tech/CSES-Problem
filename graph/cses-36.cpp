#include <bits/stdc++.h>
#include <unistd.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const int mod = 1e9+7;
const int INF = 1e9;
class Timer{
public:
    Timer(){
        start_t = chrono::high_resolution_clock::now();
    }
 
    ~Timer(){
        end_t = chrono::high_resolution_clock::now();
    }
    void exec_time()
    {
        end_t = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_t - start_t;
        cout << fixed <<  diff.count() << endl;
    }
private:
    chrono::high_resolution_clock::time_point start_t;
    chrono::high_resolution_clock::time_point end_t;
    
};

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    vector<bool> visited;
    set<pair<int,int>> ans;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
        visited.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
    list<int> path;
    bool getPath(int s){
        if(s == n-1){
            path.push_back(s);
            return true;
        }
        path.push_back(s);
        visited[s]  = true;
        for(int id : adj[s])
        {
            if((edges[id].cap != 0 and edges[id].flow != 0) and (ans.find({edges[id].v,edges[id].u}) == ans.end()))
            {
                bool x = getPath(edges[id].u);
                if(x == true)
                {
                    return true;
                }
            }
        }
        visited[s] = false;
        path.pop_back();
        return false;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main()
{
    #ifdef OFFLINE
        Timer t;
        freopen("input.txt","r",stdin);
        // FILE* y = freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    Dinic d = Dinic(n,0,n-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        d.add_edge(a-1,b-1,1);
    }
    cout << d.flow() << endl;
    while(true){
        d.path.clear();
        fill(d.visited.begin(),d.visited.end(),false);
        d.getPath(0);
        if(d.path.size() == 0)
            break;
        cout << d.path.size() << '\n';
        list<int> :: iterator it,it2;
        it = d.path.begin();
        it2 = it;
        cout << *it+1 << ' ';
        it++;
        while(it != d.path.end()){
            d.ans.insert({*it2,*it});
            cout << *it+1 << ' ';
            it2 = it;
            it++;
        }
        cout << '\n';
    }

    #ifdef OFFLINE
        t.exec_time();
    #endif
    return 0;
}