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
    int n,e,k;
    cin >> n >> e >> k;
    vector<pi> edge[n];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edge[a].push_back({b,c});
    }

    //dijkastra modified
    priority_queue<pl,vector<pl>,greater<pl>> abc;
    multiset<long long int> ans;
    abc.push({0,0});
    int count[n];
    fill(count,count+n,0);
    while(abc.size() && count[n-1] < k){
        pl x = abc.top();
        long long int cost = x.first;
        int node = x.second;
        abc.pop();
        count[node] = count[node] + 1;
        if(node == n-1){
            ans.insert(cost);
        }
        if(count[node] > k)
            continue;
        for(pi y : edge[node]){
            abc.push({cost+y.second,y.first});
        }
    }

    for(long long int x : ans){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}