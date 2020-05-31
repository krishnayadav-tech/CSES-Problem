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
typedef pair<ll,int> pi;
stack<int> ans2;
ll sumall[2500];
bool dfs(int s,vector<pair<int,ll>> edge[],bool visited[],bool rec[],ll sum,int start){
    rec[s] = true;
    visited[s] = true;
    ans2.push(s);
    for(auto x : edge[s]){
        if(!visited[x.first]){
            sumall[x.first] = sum + x.second;
            if(dfs(x.first,edge,visited,rec,sum+x.second,start)){
                return true;
            }
            sumall[x.first] = sum - x.second;
        }else{
            if(rec[x.first] == true && (sum + x.second - sumall[x.first]) < 0){
                
                ans2.push(x.first);
                return true;
            }
        }
    }

    
    rec[s] = false;
    ans2.pop();
    return false;
}

void print(){
    vector<int> done;
    done.push_back(ans2.top());
    ans2.pop();
    while(ans2.size() > 0){
        done.push_back(ans2.top());
        if(ans2.top() == done[0]){
            break;
        }
        ans2.pop();
    }

    for(int i=done.size()-1;i>=0;i--){
        cout << done[i] + 1<< ' ';
    }
    cout << '\n';

    while(ans2.size()){
        ans2.pop();
    }
}
int main()
{
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> al;
    vector<ll> cost;
    vector<pair<int,ll>> edge[n];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge[a].push_back({b,c});
        al.push_back({a,b});
        cost.push_back(c);
    }
    // belmanford
    bool visited[n] = {false};
    bool rec[n] = {false};

    for(int i=0;i<n;i++){
        fill(visited,visited+n,false);
        fill(rec,rec+n,false);
        fill(sumall,sumall + n, 0);
        if(dfs(i,edge,visited,rec,0,i)){
            cout << "YES" << '\n';
            print();
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}