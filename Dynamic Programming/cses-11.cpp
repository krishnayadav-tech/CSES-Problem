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
bool ans[101][100001];
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
    int n;
    cin >> n;
    int arr[n+1];
    int x = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        x = x + arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=0;i<=n;i++){
        ans[i][0] = true;
    }

    
    for(int i=1;i<=n;i++){
       for(int j=1;j<=x;j++){
           if(j-arr[i]>=0 && ans[i-1][j-arr[i]]){
               ans[i][j] = true;
           }else{
               ans[i][j] = ans[i-1][j];
           }
       } 
    }
    vector<int> ans2;
    for(int i=1;i<=x;i++){
        if(ans[n][i] == true){
            ans2.push_back(i);
        }
    }
    cout << ans2.size() << '\n';
    for(int x : ans2)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
