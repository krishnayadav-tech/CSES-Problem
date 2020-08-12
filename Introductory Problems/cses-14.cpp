#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
typedef long long int ll;
ll diff = LONG_MAX;
void allcombination(int i,int n,ll cursum,ll sum,int arr[])
{
    if(i == n){
        diff = min(diff,abs(cursum-(sum-cursum)));
        return;
    }
    allcombination(i+1,n,cursum,sum,arr);
    allcombination(i+1,n,cursum+arr[i],sum,arr);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum = sum + arr[i];
    }
    allcombination(0,n,0,sum,arr);
    cout << diff << '\n';
    return 0;
}