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
bool done[1000001];
int ans[1000001];
int solve(int x){
    if(x == 0){
        return 0;
    }
    if(done[x] == true){
        return ans[x];
    }
    string y = to_string(x);
    ll mine = INT_MAX;
    for(int i=0;i<y.size();i++){
        int temp = (y[i] - '0');
        if(temp != 0 && x-temp >=0){
            mine = min(solve(x-temp)+1,mine);
        }
    }
    ans[x] = mine;
    done[x] = true;
    return mine;
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
    cout << solve(n) << '\n';
    return 0;
}
