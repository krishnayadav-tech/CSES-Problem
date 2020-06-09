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
bool done[501][501];
int ans2[501][501];
int cut(int a,int b){
    if(a==b)
        return 0;
    if(done[a][b] == true)
        return ans2[a][b];

    int mine = min(a,b);
    ll ans = INT_MAX;
    for(int i=1;i<a;i++){
        ans = min(ans,1+ cut(i,b) + cut(a-i,b));
    }
    for(int i=1;i<b;i++){
        ans = min(ans,1+ cut(a,i) + cut(a,b-i));
    }

    done[a][b] = true;
    ans2[a][b] = ans;
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
    int a,b;
    cin >> a >> b;
    cout << cut(a,b) << '\n';
    return 0;
}
