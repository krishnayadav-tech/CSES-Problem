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
stack<int> ans;
bool dfs(int s,int par,vector<int> edge[],bool visited[]){
    visited[s] = true;
    ans.push(s);
    for(int x : edge[s]){
        if(!visited[x]){
            if(dfs(x,s,edge,visited) == true){
                return true;
            }
        }else{
            if(x != par){   
                ans.push(x);
                return true;
            }
        }
    }
    ans.pop();
    return false;
}


int main()
{
    //  freopen("input.txt","r",stdin);
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
    bool visited[n] = {false};
    bool cycle = false;
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            
            cycle = dfs(i,-1,edge,visited);
            if(cycle){
                break;
            }
        }
    }

    if(cycle == false){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

   
    vector<int> temp;
    temp.push_back(ans.top());
    ans.pop();
    while(ans.top() != temp[0]){
        temp.push_back(ans.top());
        ans.pop();
    }
    temp.push_back(ans.top());
    cout << temp.size() << '\n';
    for(int x : temp){
        cout << x+1 << ' ';
    }
    cout << '\n';
    
    
    return 0;
}