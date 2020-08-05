#include <iostream>
#define MAX(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#include <set>
using namespace std;
const long long int INF = 1e18;
int main()
{
    #ifdef OFFLINE
        freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int arr[n];
    long long int low = -INF;
    long long int high = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        low = MAX(arr[i],low);
        high = high + arr[i];
    }
    long long int mid = 0;
    long long int ans = INF;
    while(low <= high){
        mid = low + (high-low)/2;
        int total = 0;
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + arr[i];
            if(sum == mid){
                total++;
                sum = 0;
            }
            if(sum > mid){
                total++;
                sum = arr[i];
            }
            if(i == n-1 && sum != 0){
                total++;
                sum = 0;
            }
        }
        
        if(total <= k){
            high = mid-1;
            ans = min(ans,mid);
        }else{
            low = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}