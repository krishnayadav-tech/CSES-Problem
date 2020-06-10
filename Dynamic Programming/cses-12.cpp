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
long long int result[2][5000][5000];
bool done[5000][5000];
pair<ll,ll> solve(int i,int j,bool first,int arr[]){
    if(i == j && first){
        return {arr[i],0};
    }

    if(i == j && first == false){
        return {0,arr[i]};
    }
    if(done[i][j]){
        if(first){
            return {result[0][i][j],result[1][i][j]};
        }else{
            return {result[1][i][j],result[0][i][j]};
        }
    }

    pair<ll,ll> temp = solve(i+1,j,!first,arr);
    pair<ll,ll> temp2 = solve(i,j-1,!first,arr);
    pair<ll,ll> temp3;
    if(first == true){
        ll data1 = temp.first;
        ll data2 = temp2.first;
        if(data1 + arr[i] >= data2 + arr[j]){
            temp3 = {data1 + arr[i],temp.second};
        }else{
            temp3 = {data2 + arr[j],temp2.second};
        }
    }else{
        ll data1 = temp.second;
        ll data2 = temp2.second;
        if(data1 + arr[i] >= data2 + arr[j]){
            temp3 = {temp.first,data1 + arr[i]};
        }else{
            temp3 = {temp2.first,data2 + arr[j]};
        }
    }
    done[i][j] = true;
    if(first){
        result[0][i][j] = temp3.first;
        result[1][i][j] = temp3.second;
    }else{
        result[1][i][j] = temp3.first;
        result[0][i][j] = temp3.second;
    }
    return temp3;
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
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    pair<ll,ll> ans = solve(0,n-1,true,arr);
    cout << ans.first << '\n';
    return 0;
}
