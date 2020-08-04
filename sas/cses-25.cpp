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

vector<int> tree2[8*100000];
vector<long long int> tree3[8*100000];
void construct(int i,int ss,int se,int arr[]){
    if(ss == se){
        tree2[i].push_back(arr[ss]);
        tree3[i].push_back(0);
        tree3[i].push_back(arr[ss]);
        return;
    }
    int mid = ss + (se-ss)/2;
    construct((i*2)+1,ss,mid,arr);
    construct((i*2)+2,mid+1,se,arr);
    for(int x : tree2[i*2+1])
        tree2[i].push_back(x);
    for(int x : tree2[i*2+2])
        tree2[i].push_back(x);
    sort(tree2[i].begin(),tree2[i].end());
    long long int total = 0;
    tree3[i].push_back(0);
    for(int x : tree2[i]){
        total = total + x;
        tree3[i].push_back(total);
    }
}

long long int getans(int i,int ss,int se,int rs,int re,ll number){
    if(ss >= rs && se <= re){
        int index = lower_bound(tree2[i].begin(),tree2[i].end(),number) - tree2[i].begin();
        long long int ans1 = (tree3[i][tree2[i].size()] - tree3[i][index]);
        ans1 = ans1 - ((tree2[i].size() - index)*number);
        ans1 = ans1 + ((index*number) - (tree3[i][index]));
        return ans1;
    }
    if(se < rs || ss > re)
        return 0;
    int mid = ss + (se-ss)/2;
    return getans(i*2+1,ss,mid,rs,re,number) + getans(i*2+2,mid+1,se,rs,re,number);
}
 
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
    construct(0,0,n-1,arr);
    
    for(int i=0;i<k;i++){
        abc.insert(arr[i]);
    }
    long long int ans = 0;
    if(k % 2 == 0){
        auto it = abc.find_by_order((k-1)/2);
        auto it2 = abc.find_by_order((k-1)/2+1);
        ans = getans(0,0,n-1,0,k-1,*it);
        ans = min(ans,getans(0,0,n-1,0,k-1,*it2));
        cout << ans << ' ';
    }else{
        auto it = abc.find_by_order((k-1)/2);
        cout << getans(0,0,n-1,0,k-1,*it) <<' ';
    }
    
    for(int i=k;i<n;i++){
        abc.insert(arr[i]);
        abc.erase(abc.find_by_order(abc.order_of_key(arr[i-k])));
        if(k % 2 == 0){
            auto it = abc.find_by_order((k-1)/2);
            auto it2 = abc.find_by_order((k-1)/2+1);
            ans = getans(0,0,n-1,i-k+1,i,*it);
            ans = min(ans,getans(0,0,n-1,i-k+1,i,*it2));
            cout << ans << ' ';
        }else{
            auto it = abc.find_by_order((k-1)/2);
            cout << getans(0,0,n-1,i-k+1,i,*it) <<' ';
        }
    }
    cout << '\n';
    #ifdef OFFLINE 
        t.exec_time();
    #endif
    return 0;
}