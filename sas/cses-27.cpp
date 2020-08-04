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
#include <chrono>
using namespace __gnu_pbds; 
using namespace std;
using namespace chrono;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e18
typedef long long int ll;
typedef pair<int,int> pi;
 
#define indexed_multiset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
class Timer{
public:
    Timer(){
        start_t = chrono::high_resolution_clock::now();
    }
 
    ~Timer(){
        end_t = chrono::high_resolution_clock::now();
    }
    void exec_time()
    {
        end_t = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_t - start_t;
        cout << fixed <<  diff.count() << endl;
    }
private:
    chrono::high_resolution_clock::time_point start_t;
    chrono::high_resolution_clock::time_point end_t;
};

int main()
{
    #ifdef OFFLINE 
        Timer t;
        freopen("input.txt","r",stdin);
    #endif
    int n,a,b;
    cin >> n >> a >> b;
    int arr[n];
    indexed_multiset abc;
    ll ans2[n+1];
    ans2[0] = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans2[i+1] = ans2[i] + arr[i]; 
    }

    long long int ans = -INF;
    long long int sum = 0;
    int j = 0;

    for(int i=a-1;i<=b-1;i++){
        sum = ans2[i+1];
        abc.insert(ans2[j]);
        ans = max(ans,sum-*abc.begin());
        j++;
    }
    
    abc.insert(ans2[j]);
    j++;
    abc.erase(abc.find_by_order(abc.order_of_key(ans2[0])));
    for(int i=b;i<n;i++){
        sum = ans2[i+1];
        ans = max(ans,sum-*abc.begin());
        abc.erase(abc.find_by_order(abc.order_of_key(ans2[i-b+1])));
        abc.insert(ans2[j]);
        j++;
    }
    cout << ans << '\n';
    #ifdef OFFLINE 
        t.exec_time();
    #endif
    return 0;
}