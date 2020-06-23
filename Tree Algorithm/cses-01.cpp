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
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
int dfs(int s,vector<int> edge[],int e,vector<int>& subordinate,vector<bool>& visited){
    visited[s] = true;
    int res = 0;
    for(int x : edge[s]){
        if(x != e && visited[x] == false){
            res = res + dfs(x,edge,s,subordinate,visited);
        }
    }
    subordinate[s] = res;
    return res + 1;
}
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
    int n;
    cin >> n;
    vector<int> edge[n];
    vector<int> subordinate;
    subordinate.resize(n);
    for(int i=1;i<n;i++){
        int temp;
        cin >> temp;
        edge[temp-1].push_back(i);
        edge[i].push_back(temp-1);
    }

    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i] == false)
            dfs(0,edge,-1,subordinate,visited);
    }

    for(int i=0;i<n;i++){
        cout << subordinate[i] << ' ';
    }
    cout << '\n';
    return 0;
}