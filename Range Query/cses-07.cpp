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
    char arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    
    int sum[1001][1001];
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            sum[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(arr[i][j] == '*')
                sum[i][j+1] = sum[i][j] + 1;
            else
                sum[i][j+1] = sum[i][j];
        }
    }

    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        for(int i=a-1;i<=c-1;i++){
            ans = ans + (sum[i][d]) - (sum[i][b-1]);
        }
        cout << ans << '\n';
    }
    return 0;
}