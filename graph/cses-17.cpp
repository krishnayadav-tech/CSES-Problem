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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
#define MAXN 1000005 
  
// to make graph 
vector<int> v[MAXN]; 
ll ans[MAXN];
vector<int> topological_sorting(int fre[], int n) 
{ 
    queue<int> q; 
    for (int i = 0; i < n; i++) 
        if (!fre[i]) 
            q.push(i); 
  
    vector<int> l; 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        l.push_back(u); 
        for (int i = 0; i < v[u].size(); i++) { 
            fre[v[u][i]]--; 
            ans[v[u][i]] = (ans[u] % mod) + (ans[v[u][i]] % mod);
            ans[v[u][i]]  = ans[v[u][i]] % mod;
            if (!fre[v[u][i]]) 
                q.push(v[u][i]); 
        } 
    } 
    return l; 
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
    // write code
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    int indegree[n] = {0};
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        indegree[b]++;
    }

    
    for(int i=0;i<n;i++){
        ans[i] = 0;
    }
    ans[0] = 1;
    
    vector<int> l = topological_sorting(indegree,n);
    // for(int i=0;i<l.size();i++){
    //     for(int x : v[i]){
    //         ans[x] = ans[x] + ans[i];
    //         ans[x] = ans[x] % mod;
    //         if(i == 0){
    //             cout  << ans[x] << ' ';
    //         }
    //     }
    // }    
     cout << ans[n-1] <<  '\n';
    return 0;
}