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

bool dfs(int s,vector<pair<int,ll>> edge[],bool visited[],int i,bool rec[],int n){
    rec[s] = true;
    visited[s] = true;
    if(s == n && rec[i] == true){
        return true;
    }
    for(auto x : edge[s]){
        if(!visited[x.first]){
            if(dfs(x.first,edge,visited,i,rec,n)){
                return true;
            }
        }
    }
    rec[s] = false;
    visited[s] = false;
    return false;
}

int main()
{
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> al;
    vector<ll> cost;
    vector<pair<int,ll>> edge[n];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge[a].push_back({b,c});
        al.push_back({a,b});
        cost.push_back(c);
    }
    // belmanford
    ll dist[n];
    fill(dist,dist+n,-100000000000000);
    dist[0] = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
            int a,b,c;
            a = al[j].first;
            b = al[j].second;
            c = cost[j];
            if(dist[b] < dist[a] + c){
                dist[b] = dist[a] + c;
            }
        }
    }
    
    ll ans[n];
    for(int i=0;i<n;i++){
        ans[i] = dist[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
            int a,b,c;
            a = al[j].first;
            b = al[j].second;
            c = cost[j];
            if(dist[b] < dist[a] + c){
                dist[b] = dist[a] + c;
            }
        }
    }
    bool visited[n] = {false};
    bool rec[n] = {false};
    for(int i=0;i<n;i++){
        if(ans[i] != dist[i]){
            fill(visited,visited+n,false);
            fill(rec,rec+n,false);
            if(dfs(0,edge,visited,i,rec,n-1)){
                cout << -1 << '\n';
                return 0;
            }
            
        }
    }
    cout << ans[n-1] << '\n';
    
    return 0;
}