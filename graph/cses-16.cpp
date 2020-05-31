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
typedef pair<ll,int> pi;
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
    // write code
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<int> edge[n];
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
    }

    //dijkastra
    ll dist[n];
    bool visited[n] = {false};
    priority_queue<pi,vector<pi>,greater<pi>> abc;
    fill(dist,dist+n,INT_MAX);
    dist[0] = 0;
    abc.push({0,0});
    visited[0] = true;
    int last[n];
    while(abc.size() > 0){
        pi data = abc.top();
        abc.pop();
        for(int y : edge[data.second]){
            if(dist[y] > (data.first - 1)){
                dist[y] = (data.first - 1);
                abc.push({dist[y],y});
                last[y] = data.second;
            }
        }
        visited[data.second] = true;
    }

    if(dist[n-1] == INT_MAX){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        cout << -dist[n-1] + 1 << '\n';
        stack<int> ans;
        ans.push(n);
        int i = n-1;
        while(true){
            ans.push(last[i] + 1);
            if(last[i] == 0){
                break;
            }
            i = last[i];
        }
        
        while(ans.size()){
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << '\n';
    }
    return 0;
}