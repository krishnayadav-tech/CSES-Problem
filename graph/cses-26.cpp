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
int par[200000];
vector<int> edge[200000];
vector<int> edge2[200000];
set<int> edge3[200000];
set<int> component[200000];
char finalans[200000] = {0};
int indegree[200000] = {0};
int n2;
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
    if(s < (n2/2) && par[(n2/2)+ s] == i)
        return false;
    if(s >= (n2/2) && par[s -(n2/2)] == i) 
        return false;
    
    for(int x : edge[s])
        if(!visited[x])
            if(!dfs2(x,edge,visited,i))
                return false;
    return true;
}

void solvec(int node){
    for(int x : component[node]){
        if(x >= (n2/2) && finalans[x-(n2/2)] == 0){
            finalans[x-(n2/2)] = '-';
        }

        if(x < (n2/2) && finalans[x] == 0)
            finalans[x] = '+';
    }
}

void solve(int comp,int indeg[]){
    queue<int> abc;
    abc.push(comp);
    while(abc.size()){
        int node = abc.front();
        solvec(node);
        abc.pop();
        for(int x : edge3[node]){
            indeg[x]--;
            if(indeg[x] == 0){
                abc.push(x);
            }
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
    int n,e;
    cin >> n >> e;
 
    for(int i=0;i<n;i++){
        int a,b;
        char sa,sb;
        cin >>  sa >> a >> sb >> b;
        a--;b--;
        if(sa == '+' && sb == '+'){
            edge[e+a].push_back(b);
            edge[e+b].push_back(a);
            edge2[b].push_back(e+a);
            edge2[a].push_back(e+b);
            indegree[e+a]++;
            indegree[e+b]++;
        }else if(sa == '+' && sb == '-'){
            edge[e+a].push_back(e+b);
            edge[b].push_back(a);
            edge2[e+b].push_back(e+a);
            edge2[a].push_back(b);
            indegree[e+a]++;
            indegree[b]++;
        }else if(sa == '-' && sb == '+'){
            edge[a].push_back(b);
            edge[e+b].push_back(e+a);
            edge2[b].push_back(a);
            edge2[e+a].push_back(e+b);
            indegree[e+b]++;
            indegree[a]++;
        }else{
            edge[a].push_back(e+b);
            edge[b].push_back(e+a);
            edge2[e+b].push_back(a);
            edge2[e+a].push_back(b);
            indegree[b]++;
            indegree[a]++;
        }
    }
 
    //kosaraju algorithm to find all components
    n2 = 2*e;
    stack<int> st;
    bool visited[n2] = {false};
    for(int i=0;i<n2;i++){
        if(visited[i] == false){
            dfs(i,edge,visited,st);
        }
    }
    
    fill(par,par+n2,-1);
    int i = 0;
    bool possible = true;
    fill(visited,visited+n2,false);
    while(st.size() > 0){
        if(visited[st.top()]){
            st.pop();
            continue;
        }
        if(!dfs2(st.top(),edge2,visited,i)){
            possible = false;
            break;
        }
        i++;
        st.pop();
    }



    if(possible == false){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    

    for(int i=0;i<n2;i++){
        component[par[i]].insert(i);
    }

    int e3s = i;
    int indeg[e3s] = {0};
    for(int i=0;i<n2;i++){
        for(int x : edge2[i])
        {
            if(par[x] == par[i])
                continue;
            if(edge3[par[i]].find(par[x]) == edge3[par[i]].end()){
                edge3[par[i]].insert(par[x]);
                indeg[par[x]]++;
            }
        }
    }

    for(int i=0;i<e3s;i++){
        if(indeg[i] == 0){
            solve(i,indeg);
        }
    }

    for(int i=0;i<e;i++){
        cout << finalans[i] << ' ';
    }
    cout << '\n';
    

    return 0;
}
