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
    Node(int d,int i){
        data = d;
        index = i;
    }
};
bool operator<(Node a,Node b){
    return a.data < b.data;
}
bool operator==(Node a,Node b){
    return a.data == b.data;
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

struct Number { 
    int num;
    Number(int n) 
    { 
        num = n;
    } 
  
    bool operator==(const Number& p) const
    { 
        return num == p.num; 
    } 
}; 

class CustomHash { 
public: 
  
    size_t operator()(const Number& p) const
    { 
        return (hash<int>()(p.num)) ^  
               (hash<int>()(324298347)); 
    } 
}; 
  
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
    unordered_map<Number, int, CustomHash> ans2; 
    int a,b;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans2[arr[i]]++;
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x_ = arr[i] + arr[j];
            int diff = x - x_;
            if(diff == arr[i]){
                if(ans2[diff] > 1){
                    printed = true;
                }
            }else if(diff == arr[j]){
                if(ans2[diff] > 1){
                    printed = true;
                }
            }else{
                if(ans2[diff] > 0){
                    printed = true;
                }
            }

            if(printed == true){
                a = i;
                b = j;
                break;
            }
        }
        if(printed == true){
            break;
        }
    }

       

    if(printed == false){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        for(int i=b+1;i<n;i++){
            if(arr[i] == x-(arr[a]+arr[b]))
            {
                cout << a+1 << ' ' << b+1 << ' ' << i+1 << '\n';
                break;
            }
        }
    }
    #ifdef OFFLINE 
        t.exec_time();
    #endif
    return 0;
}