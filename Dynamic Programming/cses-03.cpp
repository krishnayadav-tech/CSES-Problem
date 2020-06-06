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
int ans[1000001];
int min_c(int x,int n,int arr[]){
    //base case
    if(x == 0){
        return 1;
    }
    if(ans[x] != -1) 
        return ans[x];
    ll ans2 = 0;
    for(int i=0;i<n;i++){
        if(x-arr[i] >= 0){
            ans2 = ans2 + min_c(x-arr[i],n,arr);
            ans2 = ans2 % mod;
        }
    }
    ans[x] = ans2;
    return ans2;
    //some optimization 
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
    int n,x;
    fill(ans,ans+1000001,-1);
    cin >> n >> x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << min_c(x,n,arr) << '\n';
    return 0;
}
