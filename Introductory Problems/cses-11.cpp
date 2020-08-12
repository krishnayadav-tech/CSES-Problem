#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int test;
    cin >> test;
    for(int i=0;i<test;i++){
        ll a,b;
        cin >> a >> b;
        ll x = (a*2 - b)/3;
        if(x < 0){
            cout << "NO" << "\n";
        }else{
            ll y = (a - 2*x);
            if(y < 0){
                cout << "NO" << '\n';
            }else if(2*x + y == a && 2*y + x == b){
                cout  << "YES" << '\n';
            }else{
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}