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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
void dfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs(x,edge,visited);
        }
    }
}
int main()
{
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<int> edge[n];
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> a;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            dfs(i,edge,visited);
            a.push_back(i);
        }
    }
 
    cout << a.size() - 1 << '\n';
    for(int i=1;i<a.size();i++){
        cout << (a[i-1]+1) << ' ' <<  (a[i]+1) << '\n';
    }
    
    return 0;
}