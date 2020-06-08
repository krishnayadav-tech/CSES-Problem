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
int arr2[102][100001];
bool done[100][100001];
int solve(int i,int x,int m,int n,int arr[]){

    if(i == n){
        return 1;
    }
    if(i != 0 && arr[i] != 0 && abs(x - arr[i]) > 1){
        return 0;
    }
    if(done[x][i] == true)
        return arr2[x][i];
    int ans = 0;
    if(arr[i] == 0){
        int j = max(x - 1,1);
        int k = min(x + 1,m);
        if(i == 0)
            k = m;
        for(int z=j;z<=k;z++){
            ans = ans + solve(i+1,z,m,n,arr);
            ans = ans % mod;
        }
    }else{
        ans = solve(i+1,arr[i],m,n,arr);
        ans = ans % mod;
    }
    done[x][i] = true;
    arr2[x][i] = ans;
    
    return ans;
}
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
    int n,u;
    cin >> n >> u;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    //tabular method
    for(int i=1;i<=u;i++){
        if(arr[n-1] == 0 or arr[n-1] == i)
            arr2[i][n] = 1;
    }
    arr2[0][n] = 0;
    arr2[u+1][n] = 0;
    
    // for(int i=0;i<=u+1;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << arr2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=u;j++){
            if(arr[i-1] == 0 or arr[i-1] == j)
                arr2[j][i] = (((arr2[j][i+1] + arr2[j-1][i+1]) % mod) + arr2[j+1][i+1]) % mod;
                arr2[j][i] = arr2[j][i] % mod;
        }
    }

    
    ll ans =  0;
    for(int i=1;i<=u;i++){
        ans = ans + arr2[i][1];
        ans = ans % mod;
    }
    cout << ans << '\n';
    
    return 0;
}
