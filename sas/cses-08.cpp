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

int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    long long int maxsum = -INF;
    long long int maxcur = 0;
    for(int i=0;i<n;i++){
        maxcur = maxcur + arr[i];
        maxsum = max(maxsum,maxcur);
        if(maxcur < 0){
            maxcur = 0;
        }
    }
    cout << maxsum << '\n';
    return 0;
}