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


int Least_Rotation(string S){
    S = S + S;
    int f[S.size()];
    fill(f,f+S.size(),-1);
    int k = 0;
    for(int j=1;j<S.size();j++){
        int sj = S[j];
        int i = f[j - k - 1];
        while((i != -1) and (sj != S[k + i + 1])){
            if(sj < S[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if (sj != S[k + i + 1]){
            if (sj < S[k])
                k = j;
            f[j - k] = -1;
        }
        else{
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main(int size,char** args)
{
    // basic input output preset
    if(size >= 2){
        string args2 = args[1];
        if(args2 == "-onlinejudge"){
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        }
    }
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);   
    string a;
    cin >> a;
    int index = Least_Rotation(a);
    for(int i=index;i<a.size();i++){
        cout << a[i];
    }
    for(int i=0;i<index;i++){
        cout << a[i];
    }
    cout << '\n';
    return 0;
}