/*
    derangements
    f(1) = 0
    f(2) = 1
    f(n) = n-1(f(n-2)+f(n-1))
*/
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
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
ll dp[1000001];
ll derangements(ll n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(dp[n] != 0)
        return dp[n];
    dp[n] = (n-1)*(derangements(n-1) + derangements(n-2));
    dp[n] = dp[n] % mod;
    return dp[n];
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
    fill(dp,dp+n,0);
    cout << derangements(n) << endl;
    return 0;
}