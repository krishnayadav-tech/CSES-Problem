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
typedef pair<int,ll> pl;
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
    vector<pl> edge[n];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edge[a].push_back({b,c});
    }

    ll ans[n][2];
    for(int i=0;i<n;i++){
        ans[i][0] = LONG_MAX;
        ans[i][1] = LONG_MAX;
    }
    ans[0][0] = 0;
    ans[0][1] = 0;

    priority_queue <pi,vector<pi>,greater<pi>>abc;
    bool visited[n] = {false};
    abc.push({0,0});
    while(abc.size()){
        auto x = abc.top();
        abc.pop();
        if(visited[x.second] == true){
            continue;
        }
        visited[x.second] = true;
        for(auto y : edge[x.second]){

            if(ans[y.first][0] > ans[x.second][0] + y.second){
                ans[y.first][0] = ans[x.second][0] + y.second;
                abc.push({ans[y.first][0],y.first});
            }

            if(ans[y.first][1] > ans[x.second][0] + (y.second/2)){
                ans[y.first][1] = ans[x.second][0] + (y.second/2);
            }

            if(ans[y.first][1] > ans[x.second][1] + (y.second)){
                ans[y.first][1] = ans[x.second][1] + (y.second);
            }
        }
    }

    cout << ans[n-1][1] << '\n';
    return 0;
}