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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
long long int pascal[1001][1001];
void ncrtable()
{
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for(int i=2;i<=1000;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                pascal[i][j] = 1;
            }else if(j==i){
                pascal[i][j] = 1;
            }else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                pascal[i][j] = pascal[i][j] % 1000000007;
            }
        }
    }
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
    ncrtable();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l,r;
    int k;
    int allc = 0;
    cin >> l >> r >> k;
    for(int i=l;i<=r;i++){
        string s = to_string(i);
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != '0'){
                c++;
            }
        }
        if(c == k){
            allc++;
        }
    }
    cout << allc << '\n';
    return 0;
}