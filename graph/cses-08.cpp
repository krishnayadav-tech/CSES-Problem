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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
typedef pair<ll,int> pi;

using namespace __gnu_pbds; 
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define indexed_set tree<pair<long long int,int>, null_type,less<pair<long long int,int>>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<int> edge[n];
    map<pair<int,int>,ll> edge_weight;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        pair<int,int> temp = {a,b};
        if(edge_weight.find(temp) == edge_weight.end())
        {
            edge_weight[temp] = c;
            edge[a].push_back(b);
        }
        else
            edge_weight[temp] = min(edge_weight[temp],c);
    }
    
    long long int dist[n];
    bool visited[n] = {false};
    fill(dist,dist+n,LONG_MAX);
    indexed_set abc;
    abc.insert({0,0});
    dist[0] = 0;
    visited[0] = true;
    //dijkastra
    int howmuch = 0;
    while(abc.size() > 0){
        auto it = abc.begin();
        ll dis = it->first;
        int node = it->second;
        int y = abc.order_of_key(*it);
        abc.erase(abc.find_by_order(y));
        if(dist[node] < dis)
            continue;
        for(int x : edge[node]){
            ll update = dis + edge_weight[{node,x}];
            if(visited[x] == false){
                if(dist[x] > update){
                    dist[x] = update;
                    abc.insert({dist[x],x});
                    visited[node] = true;
                }
            }else{
                if(dist[x] > update){
                    int y_ = abc.order_of_key({dist[x],x});
                    abc.erase(abc.find_by_order(y_));
                    dist[x] = update;
                    abc.insert({dist[x],x});
                    visited[node] = true;
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