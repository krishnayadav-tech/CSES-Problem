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

int n;


struct Matrix{
    ll matrix[100][100];
    Matrix(){
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                matrix[i][j] = 0;
            }
        }
    }
};
Matrix init;
Matrix matrix_mult(Matrix a,Matrix b){
    
    Matrix c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c.matrix[i][j] = (c.matrix[i][j]) + ((a.matrix[i][k] * b.matrix[k][j]) % mod);
                c.matrix[i][j] = c.matrix[i][j] % mod;
            }
        }
    }
    return c;
}

Matrix matrix_exponential(ll n){
    if(n == 0){
        return init;
    }
    if(n == 1){
        return init;
    }

    Matrix result = matrix_exponential(n/2);
    Matrix c = matrix_mult(result,result);
    
    if(n % 2 == 0){
        return c;
    }else{
        return matrix_mult(c,init);
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
    int m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        init.matrix[a-1][b-1]++;
    }
    
    Matrix result = matrix_exponential(k);
    cout << result.matrix[0][n-1] << '\n';
    return 0;
}