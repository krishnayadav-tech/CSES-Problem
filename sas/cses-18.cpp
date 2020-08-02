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
struct Node{
    int data;
    int index;
    int index2;
    Node(int d,int i,int i2){
        data = d;
        index = i;
        index2 = i2;
    }
};
bool operator<(Node a,Node b){
    return a.data < b.data;
}
bool operator==(Node a,Node b){
    return a.data == b.data;
}

bool operator>(Node a,Node b){
    return a.data > b.data;
}

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

bool diff(int a,int b,int c,int d){
    if(a!=c and a!=d and b!=c && b!=d){
        return true;
    }
    return false;
}

int main()
{
    #ifdef OFFLINE 
        Timer t;
        freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int x;
    cin >> x;
    bool printed = false;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    set<Node> abc;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            abc.insert({arr[i]+arr[j],i,j});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto it = abc.lower_bound({x-arr[i]-arr[j],0,0});
            auto it2 = abc.upper_bound({x-arr[i]-arr[j],0,0});
            if(it != abc.end() && it->data == x - arr[i] - arr[j]){
    
                while(it != it2){
                    bool dott = diff(i,j,it->index,it->index2);
                    if(dott == true){
                        cout << i+1 << ' ' << j+1 << ' ' << (it->index)+1 << ' ' << (it->index2) + 1 << '\n';
                        printed = true;
                        goto pass;
                    }
                    it++;
                }
            }
        }
    }


    
       
    pass:
    {

    }

    if(printed == false){
        cout << "IMPOSSIBLE" << '\n';
    }
    #ifdef OFFLINE 
        t.exec_time();
    #endif
    return 0;
}