#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ll a,b;
        cin >> a >> b;
        if(a > b){
            if(a%2 == 0){
                ll num = a*a;
                num = num - (b-1);
                cout << num << '\n';
            }else{
                ll num = (a-1)*(a-1);
                num = num + (b);
                cout << num << '\n';
            }
        }else{
            if(b%2 == 1){
                ll num = b*b;
                num = num - (a-1);
                cout << num << '\n';
            }else{
                ll num = (b-1)*(b-1);
                num = num + (a);
                cout << num << '\n';
            }
        }
    }
    return 0;
}