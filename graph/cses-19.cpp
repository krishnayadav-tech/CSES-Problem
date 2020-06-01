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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
int arr[32][200000];
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
    // write code
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        temp--;
        arr[0][i] = temp;
    }

    
    for(int i=1;i<=31;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = arr[i-1][arr[i-1][j]];
        }
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        a = a - 1;
        int x = 1 << 30;
        while(x = (x >> 1)){
            int temp = x & b;
            if(temp != 0)
                a = arr[(int)log2(temp)][a];
        }
        cout << a + 1 << '\n';
    }
    return 0;
}