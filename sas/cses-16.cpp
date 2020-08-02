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
#define INF 1e18
typedef long long int ll;
typedef pair<int,int> pi;
struct Job{
    ll start,end;
    Job(){};
    Job(ll s,ll e){
        start = s;
        end = e;
    }
};

bool isoverlapping(ll a,ll b,ll x,ll y){

    if(x >= a and x <= b){
        return true;
    }
    if(a >= x and a <= y ){
        return true;
    }
    return false;
}

int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    int arr[n];
    Job first[n];
    Job second[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    ll time = 0;
    for(int i=0;i<n;i++){
        first[i] = {time+1,time+arr[i]};
        time = time + arr[i];
    }
    time = 0;
    for(int i=n-1;i>=0;i--){
        second[i] = {time+1,time+arr[i]};
        time = time + arr[i];
    }

    vector<int> overlapindex;
    for(int i=0;i<n;i++){
        bool y = isoverlapping(first[i].start,first[i].end,second[i].start,second[i].end);
        if(y==true){
            overlapindex.push_back(i);
        }
    }   
    
    if(overlapindex.size() == 0){
        cout << time << '\n';
        return 0;
    }

    ll overlap_time = first[overlapindex[0]].end - first[overlapindex[0]].start + 1;
    ll remaining_time = time - overlap_time;
    ll ans2 = max(remaining_time,overlap_time) + overlap_time;
    cout << ans2 << '\n';
    return 0;
}