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
#include <chrono>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
using namespace std;
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
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int i,j;
    i = 0;
    j = n+1;
    multiset<int> ans;
    ans.insert({n+1-i-1});
    set<int> lamp;
    lamp.insert(0);
    lamp.insert(n+1);
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        auto it = lamp.upper_bound(temp);
        auto it2 = lamp.lower_bound(temp);
        it2--;
        if(*it == n+1){
            int diff = *it - *it2 -1;
            ans.erase(ans.lower_bound(diff));
            ans.insert(temp-*it2);
            ans.insert(*it-temp-1);
            lamp.insert(temp);
        }else{
            int diff = *it - *it2;
            ans.erase(ans.lower_bound(diff));
            ans.insert(temp-*it2);
            ans.insert(*it-temp);
            lamp.insert(temp);
        }
        auto it3 = ans.end();
        it3--;
        cout << *it3 << ' ';
    }
    cout << '\n';
    #ifdef OFFLINE 
        t.exec_time();
    #endif
    return 0;
}