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
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
 
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
    string b;
    cin >> b;
    int lps[b.size()];
    fill(lps,lps+b.size(),-1);
    int j = -1;
    for(int i=1;i<b.size();i++){
        if(b[j+1] == b[i])
        {
            j++;
            lps[i] = j;
        }else{
            if(j != -1)
                i--;
            j = -1;
        }
    }
    
    
    set<int> ans;
    int i = b.size()-1;
    while(lps[i] >= 0){
        if(lps[i] >= 0)
            ans.insert(lps[i]+1);
        if(i == 0 or lps[i] == -1)
            break;
        i = lps[i];
    }

    for(int x : ans){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}