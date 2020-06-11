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
int n;
int ans;
void combi(int i,int sum,int sum2){
    
    if(i == n+1 && sum == sum2){
        ans++;
        return;
    }

    if(i == n+1)
        return;
    
    combi(i+1,sum+i,sum2);
    combi(i+1,sum,sum2+i);
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
    cin >> n;
    ll x = (n * (n+1))/2;
    if(x % 2 != 0){
        cout << 0 << endl;
        return 0;
    }

    //
    combi(1,0,0);
    cout << (ans/2) << '\n';
    return 0;
}
