#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int sum = 0;
    int temp;
    for(int i=1;i<n;i++){
        cin >> temp;
        sum = sum + temp;
    }
    long long int naturalsum = (n*(n+1))/2;
    cout << naturalsum - sum << '\n';
    return 0;
}