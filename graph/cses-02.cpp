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
 
bool isvalid(int i,int j,int n,int m){
    if(i < 0 or i>=n){
        return false;
    }
    if(j < 0 or j>=m){
        return false;
    }
    return true;
}

pair<int,int> ans[1000][1000];
int main()
{
    // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
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
 
            if(mat[i][j] == 'B'){
                di = i;
                dj = j;
            }
            ans[i][j] = {-1,-1};
        }
    }
 
    bool visited[a][b];
    for(int i=0;i<a;i++){
        fill(visited[i],visited[i]+b,false);
    }
 
    //start bfs
    queue<pair<int,int>> abc;
    abc.push({si,sj});
    visited[si][sj] = true;

    while(abc.size()){
        pair<int,int> temp = abc.front();
        int i = temp.first;
        int j = temp.second;
        abc.pop();
        // cout << i << ' ' << j << '\n';
        if(i == di && j == dj){
            break;
        }
        
        if(isvalid(i,j-1,a,b) && visited[i][j-1] == false && mat[i][j-1] != '#'){
            abc.push({i,j-1});
            ans[i][j-1] = {i,j};
            visited[i][j-1] = true;
        }
 
        if(isvalid(i+1,j,a,b) && visited[i+1][j] == false && mat[i+1][j] != '#'){
            abc.push({i+1,j});
            ans[i+1][j] = {i,j};
            visited[i+1][j] = true;
            
        }
 
        if(isvalid(i,j+1,a,b) && visited[i][j+1] == false && mat[i][j+1] != '#'){
            abc.push({i,j+1});
            ans[i][j+1] = {i,j};
            visited[i][j+1] = true;
            
            
        }
        
        if(isvalid(i-1,j,a,b) && visited[i-1][j] == false && mat[i-1][j] != '#'){
            abc.push({i-1,j});
            ans[i-1][j] = {i,j};
            visited[i-1][j] = true;
            
        }   
    }

    int i = di;
    int j = dj;
    if(ans[i][j].first == -1 && ans[i][j].second == -1){
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