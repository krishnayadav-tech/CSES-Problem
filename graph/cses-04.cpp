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
int main()
{
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<int> edge[n];
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bool visited[n] = {false};
    //bfs
    int arr[n];
    fill(arr,arr+n,-1);
    queue<int> abc;
    abc.push(0);
    visited[0] = true;
    while(abc.size() > 0)
    {
        int temp = abc.front();
        abc.pop();
        if(temp == n-1){
            break;
        }
        for(int x : edge[temp]){
            if(!visited[x]){
                abc.push(x);
                arr[x] = temp;
                visited[x] = true;
            }
        }
    }
    if(arr[n-1] == -1){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    stack<int> ans;
    int i = n-1;
    while(true){
        
        ans.push(i);
        if(i == 0){
            break;
        }
        i = arr[i];
    }
    
    cout << ans.size() << '\n';
    while(ans.size() > 0){
        cout << ans.top() + 1 << ' ';
        ans.pop();
    }
    cout << '\n';
    return 0;
}