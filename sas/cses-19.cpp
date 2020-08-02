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
    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }   
    stack<int> temp;
    int ans[n+1];
    fill(ans,ans+n+1,0);
    temp.push(n);
    for(int i=n-1;i>=1;i--){
        while(temp.size() && arr[i] < arr[temp.top()]){
            ans[temp.top()] = i;
            temp.pop();
        }
        temp.push(i);
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}