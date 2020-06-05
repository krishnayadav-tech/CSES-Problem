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
ll ans2[1000001];
ll way(int n){
    if(n == 0){
        return 1;
    }
    if(ans2[n] != -1)
        return ans2[n];
    ll ans = 0;
    for(int i=1;i<=6;i++){
        if(n-i >= 0){
            ans = ans + way(n-i);
            ans = ans % mod;
        }
    }
    ans2[n] = ans;
    return ans;
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
    fill(ans2,ans2+1000001,-1);
    int n;
    cin >> n;
    cout << way(n) << '\n';
    return 0;
}
