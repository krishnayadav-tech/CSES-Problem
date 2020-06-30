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
void z_algorithm(string str, int Z[]) 
{ 
    int n = str.length(); 
    int L, R, k; 
  
    // [L,R] make a window which matches with prefix of s 
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    { 
        // if i>R nothing matches so we will calculate. 
        // Z[i] using naive way. 
        if (i > R) 
        { 
            L = R = i; 
  
            // R-L = 0 in starting, so it will start 
            // checking from 0'th index. For example, 
            // for "ababab" and i = 1, the value of R 
            // remains 0 and Z[i] becomes 0. For string 
            // "aaaaaa" and i = 1, Z[i] and R become 5 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            // k = i-L so k corresponds to number which 
            // matches in [L,R] interval. 
            k = i-L; 
  
            // if Z[k] is less than remaining interval 
            // then Z[i] will be equal to Z[k]. 
            // For example, str = "ababab", i = 3, R = 5 
            // and L = 2 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
  
            // For example str = "aaaaaa" and i = 2, R is 5, 
            // L is 0 
            else
            { 
                // else start from R and check manually 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);   

    string b;
    cin >> b;
    int lps[b.size()];
    int zarr[b.size()];
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
    z_algorithm(b,zarr);
    int ss = b.size();
    for(int i=1;i<b.size();i++){
        if(zarr[i] + i >= b.size()){
            cout << i  << ' ';
        }
    }
    cout << b.size() << '\n';
    return 0;
}

// aabababaaa