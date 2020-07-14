/*
    matrix exponential
    f[n]   = ([0 1])....n [0]
    f[n+1]   ([1 1])....n [1]
*/
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
struct Matrix{
    ll a=0,b=1,c=1,d=1;
};
Matrix twobytwomatrix_mult(Matrix a,Matrix b){
    Matrix c;
    c.a = (((a.a * b.a) % mod) + ((a.b * b.c) % mod)) % mod;
    c.b = (((a.a * b.b) % mod) + ((a.b * b.d) % mod)) % mod;
    c.c = (((a.c * b.a) % mod) + ((a.d * b.c) % mod)) % mod;
    c.d = (((a.c * b.b) % mod) + ((a.d * b.d) % mod)) % mod;
    return c;
}

Matrix matrix_exponential(ll n){
    if(n == 0){
        Matrix c;
        c.b = 0;
        return c;
    }
    if(n == 1){
        return Matrix();
    }

    Matrix a = matrix_exponential(n/2);
    Matrix c = twobytwomatrix_mult(a,a);
    
    if(n % 2 == 0){
        return c;
    }else{
        return twobytwomatrix_mult(c,Matrix());
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
    ll n;
    cin >> n;
    Matrix c = matrix_exponential(n);   
    cout << c.b << endl;
    return 0;
}