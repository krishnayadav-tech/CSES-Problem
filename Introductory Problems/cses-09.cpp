#include <iostream>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;
//modulo exponetntial
long long int power(ll base,ll exponent)
{
    if(exponent == 0){
        return 1;
    }
    long long int ans = power(base,exponent/2);
    ll ans2;
    ans2 = (ans % mod) * (ans % mod);
    ans2 = ans2 % mod;
    if(exponent%2 != 0){
        ans2 = ans2 * base;
        ans2 = ans2 % mod;
    }
    return ans2;
}
int main()
{
    long long int n;
    cin >> n;
    cout << power(2,n) << '\n';
    return 0;
}