/*
    a^b^c mod m = a^(b^c mod n) mod m, where n = φ(m)
    and if a and m are co prime then n = m - 1
*/
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
int mod = 1000000007;
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;

ll power(ll a,ll b,int mod){
    if(b == 0)
        return 1;
    if(a == 0)
        return 0;
    
    ll temp = power(a,b/2,mod);
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
    int test;
    cin >> test;
    while(test--){
        int a,b,c;
        cin >> a >> b >> c;
        ll secondpow = power(b,c,mod-1);
        cout << power(a,secondpow,mod) << '\n';
    }
    return 0;
}