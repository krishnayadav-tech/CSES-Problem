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
bool done[1000][100001];
int ans[1001][100001];
int path[1001][100001];
int solve(int x,int n,pair<int,int> arr[]){
    if(x == 0){
        return 0;
    }
    if(done[n][x]){
        return ans[n][x];
    }
    int maxe = 0;
    for(int i=0;i<n;i++){
        if(x - arr[i].first >= 0){
            maxe = max(maxe,arr[i].second+solve(x - arr[i].first,i,arr));
        }
    }
    done[n][x] = true;
    ans[n][x] = maxe;
    return maxe;
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
    int n;
    cin >> n;
    int x;
    cin >> x;
    int price[n];
    int page[n];
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    for(int i=0;i<n;i++){
        cin >> page[i];
    }

    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        arr[i] = {price[i],page[i]};
    }
    
    sort(arr,arr+n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            ans[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-arr[i-1].first >= 0){
                if(ans[i-1][j-arr[i-1].first] + arr[i-1].second >= ans[i-1][j]){
                    ans[i][j] = ans[i-1][j-arr[i-1].first] + arr[i-1].second;
                    path[i][j] = i-1;
                }else{
                    ans[i][j] = ans[i-1][j];
                    path[i][j] = path[i-1][j];
                }
            }else{
                path[i][j] = path[i-1][j];
            }
        }
    }
    
    cout << ans[n][x] << '\n';

    // while(x >= arr[0].first){
    //     cout << arr[path[n][x]].first << ' ';
    //     cout << arr[path[n][x]].second << '\n';
    //     int temp = path[n][x];
    //     x = x - arr[path[n][x]].first;
    //     n = temp;
    // }
    return 0;
}
