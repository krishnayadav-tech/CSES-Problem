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
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    int x;
    cin >> x;
    set<Node> abc;
    bool printed = false;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        set<Node> :: iterator it = abc.find({x-temp,0});
        if(it != abc.end())
        {
            cout << (*it).index+1 <<  ' ' << i+1 << endl;
            printed = true;
            break;
        }
        abc.insert({temp,i});
    }
    
    if(printed == false){
        cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}