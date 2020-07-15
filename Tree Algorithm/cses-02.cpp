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
typedef vector<int> vi;
typedef vector<long long int> vl;
set<int> contain;
int i = 0;
void dfs(int s,vi& visited,vi edge[])
{
    visited[s] = 1;
    for(int x : edge[s]){
        if(visited[x] == false)
        {
            dfs(x,visited,edge);
            if(contain.find(x) == contain.end() && contain.find(s) == contain.end())
            {
                contain.insert(x);
                contain.insert(s);
                i++;
            }
        }
    }
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
    vi edge[n];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vi visited(n,0);
    dfs(0,visited,edge);
    cout << i << endl;
    return 0;
}