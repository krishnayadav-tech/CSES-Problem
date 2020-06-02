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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
typedef pair<int,ll> pi;
typedef pair<ll,int> pl;
vector<pi> edge[100000];
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
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        b--;a--;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    //Prims Algorithm 
    long long int sum = 0;
    priority_queue<pl,vector<pl>,greater<pl>> abc;
    abc.push({0,0});
    bool visited[n] = {false};
    while(abc.size()){
        pl x = abc.top();
        abc.pop();
        if(visited[x.second] == true){
            continue;
        }
        visited[x.second] =  true;
        sum = sum + x.first;
        for(pi y : edge[x.second]){
            abc.push({y.second,y.first});
        }
    }
    bool allvis = true;
    for(int i=0;i<n;i++){
        if(visited[i] == false){
            allvis = false;
            break;
        }
    }
    if(allvis)
    cout << sum << '\n';
    else
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}