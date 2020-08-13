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
ll power(ll a,ll b){
    if(b == 0)
        return 1;
    if(a == 0)
        return 0;
    
    ll temp = power(a,b/2);
    ll ans = ((temp % mod) * (temp % mod)) % mod;
    if(b%2 == 0){
        return ans;
    }else{
        return (ans * (a%mod)) % mod;
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
    ll n;
    cin >> n;
    ll sum = 0;
    ll sqrts = sqrt(n);
    ll mod_inv = power(2,mod-2);
    for(ll i=1;i<=sqrts;i++){
        sum = (sum) + (((n/i)*i) % mod);
        sum = sum % mod;
    }
    ll last = sqrts;
    for(ll i=sqrts;i>=1;i--){
        ll x = ceil(n/i);
        ll ans = ((x%mod) * ((x+1) % mod)) % mod;
        ans = (ans * mod_inv) % mod;
        ll ans2 = ((last%mod) * ((last+1) % mod)) % mod;
        ans2 = (ans2 * mod_inv) % mod;
        ans = (ans - ans2);
        if(ans < 0){
            ans = ans + mod;
        }
        sum = sum + ((ans * i) % mod);
        sum = sum % mod;
        last = x;
    }
    cout << sum << '\n';
    return 0;
}