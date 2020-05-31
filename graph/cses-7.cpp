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
#define max(n,m) a>b?a:b
#define min(n,m) a<b?a:b
using namespace std;
#define mod 1000000007
typedef long long int ll;
 
bool isvalid(int i,int j,int n,int m){
    if(i < 0 or i>=n){
        return false;
    }
    if(j < 0 or j>=m){
        return false;
    }
    return true;
}

bool isvalid2(int i,int j,int n,int m){
    if(i == 0 or i == n-1){
        return true;
    }

    if(j == 0 or j == m-1){
        return true;
    }
    return false;
}

pair<int,int> ans[1000][1000];
int main()
{
     // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,m;
    int a,b;
    cin >> a >> b;
    char mat[a][b];
    int si,sj;
    int di,dj;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'A'){
                si = i;
                sj = j;
            }

            ans[i][j] = {-1,-1};
        }
    }
 
    bool visited[a][b];
    for(int i=0;i<a;i++){
        fill(visited[i],visited[i]+b,false);
    }
 
    //start bfs
    int dist[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            dist[i][j] = 0;
        }
    }
    queue<pair<int,int>> abc;
    abc.push({si,sj});
    visited[si][sj] = true;
    dist[si][sj] = 0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(mat[i][j] == 'M'){
                abc.push({i,j});
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    n = a;
    m = b;
    bool found = false;
    
    while(abc.size()){
        pair<int,int> temp = abc.front();
        int i = temp.first;
        int j = temp.second;
        int dis  = dist[i][j];
        abc.pop();
        if(isvalid2(i,j,n,m) && mat[i][j] == 'A'){

            bool a,b,c,d;
            a = b = c = d = true;
            
            if(isvalid(i+1,j,n,m)){
                
                if(mat[i+1][j] == 'M' && dist[i][j] == 1 + dist[i+1][j]){
                    
                    a = false;
                }else{
                    a = true;
                }
            }

            if(isvalid(i-1,j,n,m)){
                
                if(mat[i-1][j] == 'M' && dist[i][j] == 1 + dist[i-1][j]){
                    b = false;
                }else{
                    b = true;
                }
            }

            
            if(isvalid(i,j+1,n,m)){
                
                if(mat[i][j+1] == 'M' && dist[i][j] == 1 + dist[i][j+1]){
                    
                    c = false;  
                }else{
                    c = true;
                }
            }

            if(isvalid(i,j-1,n,m)){
                
                if(mat[i][j-1] == 'M' && dist[i][j] == 1 + dist[i][j-1]){
                    d = false;
                }else{
                    d = true;
                }
            }

            if(a==b && b == c && c==d && a== true){
                found = true;
                di = i;
                dj = j;
                break;
            }
        }
        
        if(mat[i][j] == 'M'){
            if(isvalid(i,j-1,n,m)  && (mat[i][j-1] == '.' or mat[i][j-1] == 'A')){
            abc.push({i,j-1});
            mat[i][j-1] = mat[i][j];
            if(mat[i][j] == 'A')
                ans[i][j-1] = {i,j};
            visited[i][j-1] = true;
            dist[i][j-1] = dis + 1;
        }
 
        if(isvalid(i+1,j,n,m)  && (mat[i+1][j] == '.' or mat[i+1][j] == 'A')){
            abc.push({i+1,j});
            mat[i+1][j] = mat[i][j];
            if(mat[i][j] == 'A')
                ans[i+1][j] = {i,j};
            visited[i+1][j] = true;
            dist[i+1][j] = dis + 1;
            
        }
 
        if(isvalid(i,j+1,n,m)  && (mat[i][j+1] == '.' or mat[i][j+1] == 'A')){
            abc.push({i,j+1});
            if(mat[i][j] == 'A')
                ans[i][j+1] = {i,j};
        
            mat[i][j+1] = mat[i][j];
            visited[i][j+1] = true;
            dist[i][j+1] = dis + 1;
            
        }
        
        if(isvalid(i-1,j,n,m) && (mat[i-1][j] == '.' or mat[i-1][j] == 'A')){
            abc.push({i-1,j});
            if(mat[i][j] == 'A')
                ans[i-1][j] = {i,j};
            mat[i-1][j] = mat[i][j];
            visited[i-1][j] = true;
            dist[i-1][j] = dis + 1;
        } 
        }else{

        
        if(isvalid(i,j-1,n,m)  && mat[i][j-1] == '.'){
            abc.push({i,j-1});
            mat[i][j-1] = mat[i][j];
            if(mat[i][j] == 'A')
                ans[i][j-1] = {i,j};
            visited[i][j-1] = true;
            dist[i][j-1] = dis + 1;
        }
 
        if(isvalid(i+1,j,n,m)  && mat[i+1][j] == '.'){
            abc.push({i+1,j});
            mat[i+1][j] = mat[i][j];
            if(mat[i][j] == 'A')
                ans[i+1][j] = {i,j};
            visited[i+1][j] = true;
            dist[i+1][j] = dis + 1;
            
        }
 
        if(isvalid(i,j+1,n,m)  && mat[i][j+1] == '.' ){
            abc.push({i,j+1});
            if(mat[i][j] == 'A')
                ans[i][j+1] = {i,j};
        
            mat[i][j+1] = mat[i][j];
            visited[i][j+1] = true;
            dist[i][j+1] = dis + 1;
            
        }
        
        if(isvalid(i-1,j,n,m) && mat[i-1][j] == '.' ){
            abc.push({i-1,j});
            if(mat[i][j] == 'A')
                ans[i-1][j] = {i,j};
            mat[i-1][j] = mat[i][j];
            visited[i-1][j] = true;
            dist[i-1][j] = dis + 1;
        } 
        }  
    }


    int i = di;
    int j = dj;
    if(found==false){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << '\n';
    string ans2;
    while(true){
        if((i == si && j == sj)){
            break;
        }
        if(ans[i][j].first == i + 1 && ans[i][j].second == j){
            ans2.push_back('U');
        }

        if(ans[i][j].first == i - 1 && ans[i][j].second == j){
            ans2.push_back('D');
        }

        if(ans[i][j].first == i && ans[i][j].second == j + 1){
            ans2.push_back('L');
        }

        if(ans[i][j].first == i && ans[i][j].second == j - 1){
            ans2.push_back('R');
        }

        int temp = ans[i][j].first;
        int temp2 = ans[i][j].second;
        i = temp;
        j = temp2;
        
    }
    cout << ans2.size() << '\n';
    for(int i=0;i<ans2.size();i++){
        cout << ans2[ans2.size()-1-i];
    }
    
    cout << '\n';
    return 0;
}