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

ll totaldivisor(ll n){
    long long int sum = 0;
    for(int i=1;i<sqrt(n);i++){
        if(n % i == 0){
            sum = sum + i;
            sum = sum % mod;
            sum = sum + n/i;
            sum = sum % mod;
        }
            
    }
    int sqrt_n = sqrt(n);
    if(sqrt_n * sqrt_n == n)
        sum = sum + sqrt_n;
    sum = sum % mod;
    return sum;
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
    ll n;
    cin >> n;
    cout << totaldivisor(n) << '\n';
    return 0;
}