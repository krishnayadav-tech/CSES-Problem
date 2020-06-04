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
int indegree[200000] = {0};
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

    return 0;
}