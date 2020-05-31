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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
int main()
{
    // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    long long int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 100000000000000;
        }
        mat[i][i] = 0;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        mat[a][b] = min(c,mat[a][b]);
        mat[b][a] = min(c,mat[a][b]);
    }

    long long int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = mat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(dp[a][b] == 100000000000000){
            cout << -1 << '\n';
        }else
            cout << dp[a][b] << '\n';
    }
    return 0;
}