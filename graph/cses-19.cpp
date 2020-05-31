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
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    while(q--){
        int a,b;
        cin >> a  >> b;
        int k = b;
        int i =0;
        map<int,int> abc;
        abc.insert({a,0});
        int cylce = 0;
        while(b--){
            a = arr[a-1];
            i++;
            if(abc.find(a) == abc.end())
                abc.insert({a,i});
            else{
                k = k - abc[a];
                cylce = i - abc[a];
                int howmuch = k % cylce;
                while(howmuch--){
                    
                    a = arr[a-1];
                }
                break;
            }
        }
        cout << a << '\n';
    }
    return 0;
}