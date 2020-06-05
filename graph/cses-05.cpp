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
vector<int> which;
bool dfs(int s,vector<int> edge[],bool visited[],bool first){
    visited[s] = true;
    which[s] = first;
    for(int x : edge[s]){
        if(!visited[x]){
            if(dfs(x,edge,visited,!first) == false){
                return false;
            }
        }else{
            if(which[x] == first){
                return false;
            }
        }
    }
    return true;
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
    which.resize(n);
    fill(which.begin(),which.end(),-1);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bool visited[n] = {false};
    bool ans;
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            ans = dfs(i,edge,visited,true);
            if(ans == false){
                break;
            }
        }
    }

    if(ans == false)
        cout << "IMPOSSIBLE" << '\n';
    else{
        for(bool x : which){
            cout << (x==true?1:2) << ' ';
        }
        cout << '\n';
    }
    return 0;
}