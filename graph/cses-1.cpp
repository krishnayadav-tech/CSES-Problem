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
int a,b;
bool visited[1000][1000];
char mat[1000][1000];
bool isvalid(int i,int j,int n,int m){
    if(i < 0 or i>=n){
        return false;
    }
    if(j < 0 or j>=m){
        return false;
    }
    return true;
}


void bfs(int i,int j,char mat[][1000],bool visited[][1000]){
    //start bfs
    queue<pair<int,int>> abc;
    abc.push({i,j});
    visited[i][j] = true;
 
    while(abc.size()){
        pair<int,int> temp = abc.front();
        int i = temp.first;
        int j = temp.second;
        abc.pop();
        if(isvalid(i,j-1,a,b) && visited[i][j-1] == false && mat[i][j-1] != '#'){
            abc.push({i,j-1});
            visited[i][j-1] = true;
        }
 
        if(isvalid(i+1,j,a,b) && visited[i+1][j] == false && mat[i+1][j] != '#'){
            abc.push({i+1,j});
            visited[i+1][j] = true;
            
        }
 
        if(isvalid(i,j+1,a,b) && visited[i][j+1] == false && mat[i][j+1] != '#'){
            abc.push({i,j+1});
            visited[i][j+1] = true;
            
            
        }
        
        if(isvalid(i-1,j,a,b) && visited[i-1][j] == false && mat[i-1][j] != '#'){
            abc.push({i-1,j});
            visited[i-1][j] = true;
            
        }   
    }
 
}
 
pair<int,int> ans[1000][1000];
int main()
{
    // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<a;i++){
        fill(visited[i],visited[i]+b,false);
    }
 
    
    int ans = 0 ;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(visited[i][j] == false && mat[i][j] == '.'){
                bfs(i,j,mat,visited);
                ans++;
            }
                
        }
    }
    cout << ans << '\n';
    return 0;
}