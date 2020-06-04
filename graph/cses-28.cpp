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
int n;
int degree[100000] = {0};
void firstpar(int par,vector<pair<int,bool>> edge[],int node){
    for(int i=0;i<edge[node].size();i++){
        if(edge[node][i].first == par && edge[node][i].second == true){
            edge[node][i].second = false;
            return;
        }
    }
}   
void dfs(int node,int par,vector<pair<int,bool>> edge[],stack<int>& abc){
    vector<pair<int,bool>> :: iterator it;
    firstpar(par,edge,node);
    for(it = edge[node].begin();it!=edge[node].end();it++){
        bool d = (*it).second;
        (*it).second = false;
        if(d == true){
            dfs((*it).first,node,edge,abc);
        }
    }
    abc.push(node);
}

void dfs2(int node,vector<pair<int,bool>> edge[],bool visited[]){
    visited[node] = true;
    for(auto x : edge[node]){
        if(visited[x.first] == false){
            dfs2(x.first,edge,visited);
        }
    }
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
    int e;
    cin >> n >> e;
    vector<pair<int,bool>> edge[n];
    int degree[n] = {0};
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back({b,true});
        edge[b].push_back({a,true});
        degree[a]++;
        degree[b]++;
    }
    bool alleven = true;
    
    for(int i=0;i<n;i++){
        if(degree[i] % 2 != 0){
            alleven = false;
            break;
        }
    }

    int c = 0;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(visited[i] == false && degree[i] != 0){
            dfs2(i,edge,visited);
            c++;
        }
    }
    
    if(alleven == false or degree[0] == 0 or c > 1){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    stack<int> abc;
    dfs(0,-1,edge,abc);
    while(abc.size())
    {
        cout << abc.top() + 1 << ' ';
        abc.pop();
    }
    cout << '\n';
    return 0;
}