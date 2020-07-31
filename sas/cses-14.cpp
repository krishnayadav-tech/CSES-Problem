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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e18
typedef long long int ll;
typedef pair<int,int> pi;
long long int modified_bs(long long int start,long long int end,int arr[],int n,int job){
    if(start <= end){
        ll mid = start + (end-start)/2;
        long double temp = 0;
        for(int i=0;i<n;i++){
            temp  = temp + mid/arr[i];
        }

        if(temp >= job){
            temp = 0;
            for(int i=0;i<n;i++){
                temp  = temp + (mid-1)/arr[i];
            }  
            if(temp < job){
                return mid;
            }else{
                return modified_bs(start,mid-1,arr,n,job);
            }
        }

        if(temp < job){
            return modified_bs(mid+1,end,arr,n,job);
        }
    }
    return -1;
}
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,job;
    cin >> n >> job;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    long long int start = 0;
    long long int end = INF;
    ll ans = modified_bs(start,end,arr,n,job);
    cout << ans << '\n';
    return 0;
}