#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ans = n/5;
    ll some = 25;
    while(some <= n)
    {
        ans = ans + (n/some);
        some = some * 5;
    }
    cout << ans << '\n';
    return 0;
}