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
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
vector<int> nodes[200000];
int ans2[200000];
int dist[200000];
int n;
long long int dists[200000];
long long int finalans[200000];
int dfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    int res = 0;
    int i = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            int temp = dfs(x,edge,visited);
            nodes[s].push_back(temp);
            res = res + temp;
            i++;
        }
    }
    ans2[s] = res;
    return res + 1;
}

void disroot(int s,int d,vector<int> edge[],bool visited[]){
    visited[s] = true;
    dist[s] = d;
    for(int x : edge[s]){
        if(visited[x] == false){
            disroot(x,d+1,edge,visited);
        }
    }
}

void dfs2(int s,int p,int depth,ll sum,vector<int> edge[],bool visited[]){
    visited[s] = true;
    if(s == 0){
        finalans[s] = sum;
    }else{
        int temp = (n-1) - nodes[p][depth];
        sum = sum + (temp*1);
        sum = sum - (ans2[s]*1);
        finalans[s] = sum;
    }
    int i = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs2(x,s,i,sum,edge,visited);
            i++;
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
    cin >> n;
    vector<int> edge[n];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    bool visited[n] = {false};
    dfs(0,edge,visited);
    fill(visited,visited+n,false);
    disroot(0,0,edge,visited);
    fill(visited,visited+n,false);
    long long int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + dist[i];
    }
    
    dfs2(0,-1,-1,sum,edge,visited);
    for(int i=0;i<n;i++){
        cout << finalans[i] << ' ';
    }
    cout << '\n';
    return 0;
}