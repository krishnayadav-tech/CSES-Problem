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
string a,b;
int result[5000][5000];
bool done[5000][5000];
int LIS(int i,int j){
    if(i == a.size() or j == b.size()){
        int x = ((a.size() - i) - (b.size() - j));
        if(x < 0)
            x = -x;
        return x;
    }
    if(done[i][j])
        return result[i][j];
    ll ans = INT_MAX;
    if(a[i] == b[j])
        ans =  LIS(i+1,j+1);
    else{
        int ans1 =  LIS(i+1,j);
        int ans2 = LIS(i,j+1);
        int ans3 = LIS(i+1,j+1);
        ans = min(min(ans1,ans2),ans3) + 1;
        //cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    }
    done[i][j] = true;
    result[i][j] = ans;
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
    cin >> a >> b;
    cout << LIS(0,0) << '\n';
    return 0;
}
