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
typedef long long int ll;
const ll MOD = 1000000007;
int n, t;
int c[501][250001];
int f(int i, int s)  {
  if (i == n) return s == t;
  if (c[i][s] != -1) return c[i][s];
  ll k = f(i + 1, s);
  if (s + i <= t) k += f(i + 1, s + i);
  k = k % MOD;
  c[i][s] = k;

  return k;
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
    t = x/2;
    for (int i = 0; i <= 500; i++)
      for (int j = 0; j <= 250000; j++)
        c[i][j] = -1;
    
    cout << (f(1,0)) << endl;
    return 0;
}