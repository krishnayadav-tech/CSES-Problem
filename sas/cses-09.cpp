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
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
using namespace std;
typedef long long int ll;
typedef pair<int,int> pi;
ll solve(int arr[],int n,int median){
    long long int operation  = 0;
    for(int i=0;i<n;i++){
        operation = operation + abs(arr[i]-median);
    }
    return operation;
}
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long int operation = 0;
    if(n % 2 == 0){
        operation = solve(arr,n,arr[n/2]);
        operation = min(operation,solve(arr,n,arr[(n/2)+1]));
    }else{
        operation = solve(arr,n,arr[n/2]);
    }
    
    cout << operation << endl;
    return 0;
}