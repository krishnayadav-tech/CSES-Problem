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
struct Node{
    int start;
    int end;
    Node(int s,int e){
        start = s;
        end = e;
    }
    Node(){}
};

bool operator<(Node a,Node b){
    return a.end < b.end;
}
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Node arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].start;
        cin >> arr[i].end;
    }
    sort(arr,arr+n);
    Node lastpick;
    int some = 1;
    lastpick = arr[0];
    for(int i=1;i<n;i++){
        if(lastpick.end <= arr[i].start){
            lastpick = arr[i];
            some++;
        }
    }
    cout << some << endl;
    return 0;
}