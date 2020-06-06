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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
int ans[101][1000001];
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
    int n,x;
    cin >> n >> x;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int maxi = x;
    sort(arr,arr+n);

    for(int j=0;j<=n;j++){
        for(int i=0;i<=maxi;i++){
            ans[j][i] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        ans[i][0] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxi;j++){
            if(j-arr[i-1] >= 0)
                ans[i][j] = ans[i-1][j] + ans[i][j-arr[i-1]];
            else
                ans[i][j] = ans[i-1][j];
            ans[i][j]  = ans[i][j] % mod;
        }
    }
    
    cout << ans[n][maxi] << '\n';
    return 0;
}
