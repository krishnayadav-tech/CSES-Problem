#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        long long int Xor = 0;
        vector<int> arr(n);
        for(int& x : arr){
            cin >> x;
            Xor = Xor ^ x;
        }
        if(Xor == 0){
            cout << "second" << '\n';
        }else{
            cout << "first" << '\n';
        }
    }
    return 0;
}