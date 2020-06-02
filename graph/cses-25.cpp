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
void dfs(int s,vector<int> edge[],bool visited[],stack<int>& st){
    visited[s] = true;
    for(int x : edge[s])
        if(!visited[x])
            dfs(x,edge,visited,st);
    st.push(s);
}

void dfs2(int s,vector<int> edge[],bool visited[],int i){
    visited[s] = true;
    par[s] = i;
    for(int x : edge[s])
        if(!visited[x])
            dfs2(x,edge,visited,i);
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
    vector<int> edge[n];
    vector<int> edge2[n];
    for(int i=0;i<e;i++){
        int a,b;
        cin  >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge2[b].push_back(a);
    }
    stack<int> st;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            dfs(i,edge,visited,st);
        }
    }
    
    int i = 1;
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
    cout << i-1 << '\n';
    for(int i=0;i<n;i++){
        cout << par[i] << ' ';
    }
    cout << '\n';
    return 0;
}