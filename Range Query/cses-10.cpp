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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
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
    indexed_multiset ans;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        ans.insert(arr[i]);
    }

    while(q--){
        char c;
        cin >> c;
        if(c=='!'){
            int a,b;
            cin >> a >> b;
            // can be deleted through iterator only atleast for me element removal on value is not working... 
            ans.erase(ans.find_by_order(ans.order_of_key(arr[a])));
            ans.insert(b);
            arr[a] = b;
            continue;
        }
        int a,b;
        cin >> a >> b;
        int x = ans.order_of_key(a);
        int y = ans.order_of_key(b+1);
        cout << y - x << '\n';
    }

    return 0;
}