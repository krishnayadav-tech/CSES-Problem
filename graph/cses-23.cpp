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
typedef long long int ll;
int arr[100000];
int sizes[100000];
int find(int x){
    if(arr[x] == x){
        return x;
    }else{
        arr[x] = find(arr[x]);
    }
    return arr[x];
}

bool same(int a, int b) {
    return find(a) == find(b);
}

int unite(int a, int b) {
    
    a = find(a);
    b = find(b);
    
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    arr[b] = a;
    return a;
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
    int n,e;
    cin >> n >> e;
    for(int i=0;i<n;i++){
        arr[i] = i;
        sizes[i] = 1;
    }
    int maxes = 1;
    int totals = n;
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int at = find(a);
        int bt = find(b);
        if(at != bt){
            int temp  = unite(a,b);
            totals = totals - 1;
            maxes = max(sizes[temp],maxes);
        }
        cout << totals << ' '  << maxes << '\n';
    }
    return 0;
}