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
#include <unistd.h>
#include <cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
typedef pair<ll,int> pi;
int n;
vector<pair<int,ll>> edge[100000];
vector<int> edge_set[100000];
vector<int> edge2[100000];
long long int topo_maxe(int n,int fre[]){
    long long int dist[n];
    fill(dist,dist+n,LONG_MIN);
    queue<int> q; 
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) { 
        int u = q.front();
        q.pop(); 
        for (int i = 0; i < edge2[u].size(); i++) { 
            fre[edge2[u][i]]--; 
            if(dist[edge2[u][i]] < dist[u] + 1){
                dist[edge2[u][i]] = dist[u] + 1;
            }
            if (!fre[edge2[u][i]]) {
                q.push(edge2[u][i]); 
            }
        } 
    } 
    return dist[n-1];
}
void topological_sorting(vector<int> v[],int fre[], int n, ll ans[]) 
{ 
    queue<int> q; 
    for (int i = n-1; i >= 0; i--) 
        if (!fre[i]) {
            q.push(i); 
        }
    while (!q.empty()) { 
        int u = q.front();
        q.pop(); 
        for (int i = 0; i < v[u].size(); i++) { 
            fre[v[u][i]]--; 
            ans[v[u][i]] = (ans[u] % mod) + (ans[v[u][i]] % mod);
            ans[v[u][i]] = ans[v[u][i]] % mod;
            // ans[v[u][i]]  = ans[v[u][i]] % mod;
            if (!fre[v[u][i]]) {
                q.push(v[u][i]); 
            }
        } 
    } 
}
 
int bfs(vector<int> edge2[]){
    int mine = INT_MAX;
    bool visited[n] = {false};
    queue<pair<int,int>> abc;
    abc.push({0,0});
    visited[0] = true;
    while(abc.size()){
    
        auto y = abc.front();
        abc.pop();
        if(y.first == n-1){
            mine = min(y.second,mine);
            return mine;
        }
        for(int x : edge2[y.first]){
            if(visited[x] != true)
                abc.push({x,y.second+1});
            visited[x] = true;
        }
    }
    return mine;
}
 
int main(int size,char** args)
{
    // basic input output preset
    if(size >= 2){
        string args2 = args[1];
        if(args2 == "-onlinejudge"){
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    }
    // write code
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edge[a].push_back({b,c});
    }
 
    ll dist[n];
    fill(dist,dist+n,LONG_MAX);
    priority_queue<pi,vector<pi>,greater<pi>> abc;
    dist[0] = 0;
    abc.push({0,0});
    bool visited[n] = {false};
    int indegree[n] = {0};
    while(abc.size() > 0){
        pi data = abc.top();
        abc.pop();
        if(visited[data.second] == true)
            continue;
        visited[data.second] = true;
        for(pair<int,ll> y : edge[data.second]){
            if(((dist[y.first]) == (data.first + y.second))){
                dist[y.first] = (data.first + y.second);
                abc.push({dist[y.first],y.first});
                edge_set[y.first].push_back(data.second);
            }
            if(((dist[y.first]) > (data.first + y.second))){
                dist[y.first] = (data.first + y.second);
                abc.push({dist[y.first],y.first});
                edge_set[y.first].clear();
                edge_set[y.first].push_back(data.second);
            }
        }
    }
    
    int indegree2[n] = {false};
    cout << dist[n-1] << ' ';
    for(int i=0;i<n;i++){
        for(int x : edge_set[i]){
            edge2[x].push_back(i);
            indegree[i]++;
            indegree2[i]++;
        }
    }
    
    ll ans[n]  = {0};
    fill(ans,ans+n,0);
    ans[0] = 1;
    topological_sorting(edge2,indegree,n,ans);
    cout << ans[n-1] << ' ';
    cout << bfs(edge2) << ' ';
    cout << topo_maxe(n,indegree2) << '\n';
    return 0;
}