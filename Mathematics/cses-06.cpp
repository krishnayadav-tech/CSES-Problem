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

ll modulo_multiplicative_inverse(ll a){
    return power(a,mod-2);
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
    ll fact[1000001];
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<1000001;i++){
        fact[i] = fact[i-1] * i;
        fact[i] = fact[i] % mod;
    }


    int test;
    cin >> test;
    while(test--){
        int a,b;
        cin >> a >> b;
        ll first = fact[a];
        ll second = (fact[b] * fact[a-b]) % mod;
        ll inverse = modulo_multiplicative_inverse(second);
        ll ans = (first * inverse) % mod;
        cout << ans << '\n';
    }
    return 0;
}