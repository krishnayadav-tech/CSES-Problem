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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
int par[100000];
vector<int> edge[100000];
vector<int> edge2[100000];
ll v_weight[100000];
set<int> edge3[100000];
void dfs(int s,vector<int> edge[],bool visited[],stack<int>& st){
    visited[s] = true;
    for(int x : edge[s])
        if(!visited[x])
            dfs(x,edge,visited,st);
    st.push(s);
}
 
bool dfs2(int s,vector<int> edge[],bool visited[],int i){
    visited[s] = true;
    par[s] = i;
    for(int x : edge[s])
        if(visited[x] == false)
            dfs2(x,edge,visited,i);
    return true;
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    for(int i=0;i<n;i++)
        cin >> v_weight[i];
    
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge2[b].push_back(a);
    }

    //kosaraju 
    stack<int> st;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            dfs(i,edge,visited,st);
        }
    }

    int i = 0;
    bool possible = true;
    fill(visited,visited+n,false);
    while(st.size() > 0){
        if(visited[st.top()]){
            st.pop();
            continue;
        }
        dfs2(st.top(),edge2,visited,i);
        i++;
        st.pop();
    }
    int e3s = i;
    int indeg[e3s] = {0};
    ll dist[e3s] = {0};
    ll dist2[e3s] = {0};
    for(int i=0;i<n;i++){
        dist[par[i]] += v_weight[i];
    }

    for(int i=0;i<n;i++){
        for(int x : edge[i])
        {
            if(par[x] == par[i])
                continue;
            if(edge3[par[i]].find(par[x]) == edge3[par[i]].end()){
                edge3[par[i]].insert(par[x]);
                indeg[par[x]]++;
            }
        }
    }

    //topological_sort max dist 
    queue<int> abc;
    for(int i=0;i<e3s;i++){
        if(indeg[i] == 0){
            abc.push(i);
            dist2[i] = dist[i];
        }
    }

    while(abc.size()){
        int node = abc.front();
        abc.pop();
        for(int x : edge3[node]){
            indeg[x]--;
            if(dist2[x] < dist2[node] + dist[x]){
                dist2[x] = dist2[node] + dist[x];
            }
            if(indeg[x] == 0){
                abc.push(x);
            }
        }
    }
    ll maxe = 0;
    for(int i=0;i<e3s;i++){
        maxe = max(maxe,dist2[i]);
    }
    cout << maxe << '\n';
    return 0;
}