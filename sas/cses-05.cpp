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
    Node()
    {

    }
};
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
    indexed_set ans;
    for(int i=0;i<n;i++){
        cin >> arr[i].start;
        cin >> arr[i].end;
        ans.insert(arr[i].start);
        ans.insert(arr[i].end);
    }
    
    int arr2[ans.size()];
    fill(arr2,arr2+ans.size(),0);
    for(int i=0;i<n;i++){
        int x = ans.order_of_key(arr[i].start);
        int y = ans.order_of_key(arr[i].end);
        arr2[x]++;
        arr2[y]--;
    }
    int sum = 0;
    int maxe = 0;
    for(int i=0;i<ans.size();i++){
        sum = sum + arr2[i];
        maxe = max(sum,maxe);
    }
    cout << maxe << endl;
    return 0;
}