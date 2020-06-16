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
    int n,m;
    cin >> n >> m;
    set<pi> ans;
    for(int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        ans.insert({temp,i});
    }
    while(m--){
        int x;
        cin >> x;
        set<pi> :: iterator it = ans.lower_bound({x,0});
        if(it == ans.end()){
            cout << 0 << ' ';
            continue;
        }
        int z = it->first;
        int index = it->second;
        cout << index << ' ';
        z = z-x;
        ans.erase(it);
        ans.insert({z,index});
    }
    // cout << '\n';
    return 0;
}