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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
#define INF 1e16
typedef long long int ll;
typedef pair<int,int> pi;
struct Node{
    int s,e;
    ll data;
    Node(){}
    Node(int s,int e,int d){
        this->s = s;
        this->e = e;
        this->data = d;
    }
};

bool compare(Node a,Node b){
    if(a.s < b.s)
        return true;
    if(a.s == b.s){
        if(a.e < b.e)
            return true;
        else
            return false;
    }
    return false;
}


bool operator<(Node a,Node b){
    if(a.s < b.s)
        return true;
    return false;
}

int n;
bool done[200000];
ll ans[200000];
Node temp;
ll solve(int i,int b,Node arr[]){
    if(i == n){
        return 0;
    }
    temp = {b,0,0};
    i = upper_bound(arr,arr+n,temp) - arr;
    if(done[i])
        return ans[i];

    ll ans2 = 0;
    for(int j=i;j<n;j++){
        if(arr[j].s > b){
            ans2 = max(solve(i+1,arr[j].e,arr) + arr[j].data,ans2);
        }
    }
    done[i] = true;
    ans[i] = ans2;
    return ans2;
}

// C++ program for weighted job scheduling using Dynamic  
// Programming and Binary Search 
#include <iostream> 
#include <algorithm> 
using namespace std; 
  
// A job has start time, finish time and profit. 
struct Job 
{ 
    int start, finish, profit; 
    Job(){}
    Job(int s,int f,int p){
        start = s;
        finish = f;
        profit = p;
    }
}; 
  
// A utility function that is used for sorting events 
// according to finish time 
bool myfunction(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  

int binarySearch(Job jobs[], int index) 
{ 
    int lo = 0, hi = index - 1; 
    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (jobs[mid].finish < jobs[index].start) 
        { 
            if (jobs[mid + 1].finish < jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 

ll findMaxProfit(Job arr[], int n) 
{ 
    sort(arr, arr+n, myfunction); 
    ll *table = new ll[n]; 
    table[0] = arr[0].profit; 
    for (int i=1; i<n; i++) 
    { 
        ll inclProf = arr[i].profit; 
        int l = binarySearch(arr, i); 
        if (l != -1) 
            inclProf += table[l]; 
        table[i] = max(inclProf, table[i-1]); 
    } 
    ll result = table[n-1]; 
    delete[] table; 
    return result; 
} 

int main(int size,char** args)
{
    // basic input output preset
    if(size >= 2){
        string args2 = args[1];
        if(args2 == "-onlinejudge"){
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    }
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> n;
    Job arr[n];
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        arr[i] = Job(a,b,c);
    }    
    
    cout << findMaxProfit(arr, n)<< '\n'; 
    return 0;
}
