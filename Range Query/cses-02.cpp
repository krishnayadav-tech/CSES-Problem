/*square root decompositon*/
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
    int n2 = ceil(sqrt(n));
    int ans[n2];
    fill(ans,ans+n2,INF);
    for(int j=0;j<n2;j++){
        for(int i=j*n2;i<n && i<(j*n2)+n2;i++){
            ans[j] = min(ans[j],arr[i]);
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        int lefti = a/n2;
        int righti = b/n2;
        if(lefti == righti or righti == lefti + 1){
            int mine = INF;
            for(int i=a;i<=b;i++){
                mine = min(mine,arr[i]);
            }
            cout << mine << '\n';
        }else{
            int mine = INF;
            for(int i=a;i<(lefti+1)*n2;i++){
                mine = min(arr[i],mine);
            }

            for(int i=(lefti+1);i<righti;i++){
                mine = min(ans[i],mine);
            }

            for(int i=(righti)*n2;i<=b;i++){
                mine = min(arr[i],mine);
            }
            cout << mine << '\n';
        }
    }
    return 0;
}