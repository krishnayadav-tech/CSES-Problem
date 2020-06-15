/*fenwick tree*/
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
int findlsb(int x){
    int i = 1;
    while((x & i) == 0){
        i = i << 1;
    }
    return i;
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
    int n,q;
    cin >> n >> q;
    int arr[n+1];
    arr[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    // Build Fenwick Tree
    int n2 = powl(2,ceil(log2l(n)));
    ll tree[n2+1];
    fill(tree,tree+n2+1,0);
    tree[0] = 0;
    for(int i=1;i<=n;i++){
        int x = i;
        while(x <= n2){
            tree[x] = tree[x] + arr[i];
            x = x + findlsb(x);
        }
    }
    
    while(q--){
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c == '1'){
            int x = a;
            while(x <= n2){
                tree[x] = tree[x] + (b - arr[a]);
                x = x + findlsb(x);
            }
            arr[a] = b;
            continue;
        }
        
        ll sum1 = 0;
        int x = a-1;
        while(x > 0){
            sum1 = sum1 + tree[x];
            x = x - findlsb(x);
        }

        ll sum2 = 0;
        x = b;
        while(x > 0){
            sum2 = sum2 + tree[x];
            x = x - findlsb(x);
        }
        cout <<(sum2 - sum1) << '\n';
    }
    return 0;
}