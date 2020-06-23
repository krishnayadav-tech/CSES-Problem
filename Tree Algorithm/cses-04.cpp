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
vector<pair<int,int>> depthv[200000];
int dfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    int depth = 0;
    int depthno = -1;
    int depth2 = 0;
    int depthno2 = -1;
    int i = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            int deptht = dfs(x,edge,visited);
            if(deptht > depth){
                depth2  = depth;
                depthno2 = depthno;
                depth = deptht;
                depthno = i;
            }else if(deptht > depth2){
                depth2 = deptht;
                depthno2 = i;
            }
            i++;
        }
    }
    depthv[s].push_back({depth,depthno});
    depthv[s].push_back({depth2,depthno2});
    return depth + 1;
}
vector<pair<int,int>> ans[200000];
int ans2[200000];
void dfs2(int s,int p,int depth,vector<int> edge[],bool visited[]){
    visited[s] = true;
    if(s == 0){
        ans[s].push_back(depthv[0][0]);
        ans[s].push_back(depthv[0][1]);
        ans2[s] = max(depthv[0][0].first,depthv[0][1].first);
    }else{
        pair<int,int> firsta = {0,-1};
        pair<int,int> seconda = {0,-1};
        pair<int,int> first = ans[p][0];
        pair<int,int> second = ans[p][1];
        pair<int,int> third = depthv[s][0];
        pair<int,int> fourth = depthv[s][1];
        vector<pair<int,int>> tempv;
        if(first.second != depth){
            first = {first.first+1,-1};
            tempv.push_back(first);
        }
        if(second.second != depth){
            second = {second.first+1, -1};
            tempv.push_back(second);
        }
        tempv.push_back(third);
        tempv.push_back(fourth);
        
        for(int i=0;i<tempv.size();i++){
            if(tempv[i].first > firsta.first){
                seconda = firsta;
                firsta = tempv[i];
            }else if(tempv[i].first > seconda.first){
                seconda = tempv[i];
            }
            ans2[s] = max(ans2[s],tempv[i].first);
        }
        ans[s].push_back(firsta);
        ans[s].push_back(seconda);
        ans2[s] = max(ans2[s],firsta.first);
        ans2[s] = max(ans2[s],seconda.first);
    }
    int i = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs2(x,s,i,edge,visited);
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
    int n;
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
    dfs2(0,-1,-1,edge,visited);
    for(int i=0;i<n;i++){
        cout << ans2[i] << ' ';
    }
    cout << '\n';
    // cout << depthv[0][1].first << ' ';
    return 0;
}