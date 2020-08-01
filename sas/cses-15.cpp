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
    int deadline,duration;
    Job(){}
    Job(int deadline,int duration){
        this->deadline = deadline;
        this->duration = duration;
    }
};

bool operator<(Job a,Job b){
    if(a.duration == b.duration){
        return a.deadline <= b.deadline;
    }
    return a.duration < b.duration;
}

bool operator==(Job a,Job b){
    return a.duration == b.duration;
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
    Job arr[n];
    long long int totaltime = 0;
    set<Job> process;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].duration;
        cin >> arr[i].deadline;
        process.insert(arr[i]);
    }

    long long int ans = 0;
    while(process.size()){
        set<Job> :: iterator it = process.begin();
        totaltime = totaltime + it->duration;
        ans = ans + (it->deadline - totaltime);
        process.erase(it);
    }
    cout << ans << '\n';
    return 0;
}