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
struct Node{
    long long int start;
    long long int end;
    Node(long long int  s,long long int e){
        start = s;
        end = e;
    }
    Node(){}
};
 
bool operator<(Node a,Node b){
    if(a.end == b.end){
        return a.start <= b.start;
    }
    return a.end < b.end;
}
 
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    Node arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].start;
        cin >> arr[i].end;
    }
    sort(arr,arr+n);
    multiset<int> abc;
    for(int i=0;i<k;i++){
        abc.insert(0);
    }

    int total = 0;
    for(int i=0;i<n;i++){
        auto it = abc.upper_bound(arr[i].start);
        if(it == abc.begin()){
            continue;
        }else{
            it--;
            abc.erase(it);
            total++;
            abc.insert(arr[i].end);
        }
    }
    cout << total << '\n';
    #ifdef OFFLINE 
    #endif
    return 0;
}