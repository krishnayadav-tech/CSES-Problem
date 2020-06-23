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
int ans = 0;
int dfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    int depth = 0;
    int depth2 = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            int deptht = dfs(x,edge,visited);
            if(deptht > depth){
                depth2  = depth;
                depth = deptht;
            }else if(deptht > depth2){
                depth2 = deptht;
            }
        }
    }
    ans = max(ans,depth+depth2);
    return depth + 1;
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
    cout << ans << '\n';
    return 0;
}