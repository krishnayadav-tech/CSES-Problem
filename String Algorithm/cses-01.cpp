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
bool issame(string& a,string& b,int as,int ae,int bs,int be){
    if(b.size() - bs < a.size()){
        return false;
    }

    for(int i=0;i<=ae;i++){
        if(a[i] != b[i+bs])
            return false;
    }
    return true;
}
bool done[5000];
ll dp[5000];
int solve(int index,string& abc,vector<string>& arr){
    if(index == abc.size())
        return 1;
    if(done[index] == true)
        return dp[index];
    int res = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(issame(arr[i],abc,0,arr[i].size() - 1,index,index+arr[i].size()-1)){
            res = res +  (solve(index+arr[i].size(),abc,arr) % mod);
            res = res % mod;
        }
    }
    done[index] = true;
    dp[index] = res;
    return res;
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
    string abc;
    cin >> abc;
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << solve(0,abc,arr) << '\n';
    return 0;
}