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

int main()
{
      //freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<pair<int,long long int>> edge[n];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge[a].push_back({b,c});
    }

    long long int dist[n];
    bool visited[n] = {false};
    fill(dist,dist+n,LONG_MAX);
    priority_queue<pi,vector<pi>,greater<pi>> abc;
    abc.push({0,0});
    dist[0] = 0;
    visited[0] = true;
    //dijkastra
    while(abc.size() > 0){
        pi temp = abc.top();
        ll dis = temp.first;
        int node = temp.second;
        visited[node] = true;
        abc.pop();
        for(pair<int,long long int> x : edge[node]){
            if(visited[x.first] == false){
                if(dist[x.first] > dis + x.second){
                    dist[x.first] = dis + x.second;
                    abc.push({dist[x.first],x.first});
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}