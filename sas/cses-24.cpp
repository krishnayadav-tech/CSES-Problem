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
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
 
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    int n,k;
    cin >> n >> k;
    int arr[n];
    indexed_multiset abc;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<k;i++){
        abc.insert(arr[i]);
    }
    int operation;
    if(k % 2 == 0){
        auto it = abc.find_by_order((k-1)/2);
        auto it2 = abc.find_by_order((k-1)/2+1);
        operation = min(*it,*it2);
    }else{
        auto it = abc.find_by_order((k-1)/2);
        operation = *it;
    }
    cout << operation << ' ';
    for(int i=k;i<n;i++){
        abc.insert(arr[i]);
        abc.erase(abc.find_by_order(abc.order_of_key(arr[i-k])));
        if(k % 2 == 0){
        auto it = abc.find_by_order((k-1)/2);
        auto it2 = abc.find_by_order((k-1)/2+1);
        operation = min(*it,*it2);
        }else{
            auto it = abc.find_by_order((k-1)/2);
            operation = *it;
        }
        cout << operation << ' ';
    }
    cout << '\n';
    #ifdef OFFLINE 
        t.exec_time();
    #endif
    return 0;
}