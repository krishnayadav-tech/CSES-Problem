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
bool done[1000][1000];
int ans[1000][1000];
char arr[1000][1000];
bool isvalid(int x,int y,int n,char arr[1000][1000]){
    if(arr[x][y] == '*')
        return false;
    if(x < 0 or x >= n){
        return false;
    }
    if(y < 0 or y >= n){
        return false;
    }
    return true;
}
int solve(int x,int y,int n,char arr[1000][1000]){
    //base case
    if(x == 0 and y == 0 && arr[x][y] == '*')
        return 0;
    if(x == n-1 && y == n-1 && arr[x][y] == '*')
        return 0;
    if(x==n-1 && y == n-1)
        return 1;
    //base case end here
    if(done[x][y] == true)
        return ans[x][y];
        
    int first;
    int second;
    first = second = 0;
    if(isvalid(x+1,y,n,arr)){
        first = solve(x+1,y,n,arr);
    }
    if(isvalid(x,y+1,n,arr)){
        second = solve(x,y+1,n,arr);
    }
    done[x][y] = true;
    ans[x][y] = (first + second) % mod;
    return ans[x][y];
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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    cout << solve(0,0,n,arr) << '\n';
    
    return 0;
}
