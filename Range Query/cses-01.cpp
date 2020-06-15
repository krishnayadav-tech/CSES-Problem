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
#define mod 1000000007
#define INF 1e9
#define isint(a) ((int)a==a)
typedef long long int ll;
typedef pair<int,int> pi;

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
    int n,q;
    cin >> n >> q; 
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    long long int sum[n+1];
    sum[0] = 0;
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i] + arr[i];
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
    return 0;
}