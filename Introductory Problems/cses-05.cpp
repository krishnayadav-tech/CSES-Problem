#include <bits/stdc++.h>
using namespace std;
int node[100000];
priority_queue<long long int> removeedge;
long long int totalsum = 0;
int dfs(int s,int par,vector<pair<int,long long int>> edge[],bool visited[]){
    visited[s] = true;
    int res = 0;
    for(auto x : edge[s]){
        if(visited[x.first] == false){
            res = res + dfs(x.first,s,edge,visited);
        }
    }
    node[s] = res + 1;
    return res + 1;
}

void dfs2(int s,int par,long long int cost,vector<pair<int,long long int>> edge[],bool visited[]){
    visited[s] = true;
    for(auto x : edge[s]){
        if(visited[x.first] == false){
            dfs2(x.first,s,x.second,edge,visited);
        }
    }
    if(s != 0){
        cost = cost * node[s];
        totalsum = totalsum + cost;
        removeedge.push(cost);
    }
}
int solve(int A, vector<vector<int> > &B, int C) {
    totalsum = 0;
    vector<pair<int,long long int>> edge[A];
    for(unsigned int i=0;i<B.size();i++){
        int a,b,c;
        a = B[i][0];
        b = B[i][1];
        c = B[i][2];
        a--;b--;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});   
    }
    bool visited[A] = {false};
    dfs(0,-1,edge,visited);
    fill(visited,visited+A,false);
    dfs2(0,-1,0,edge,visited);
    while(C > 0 and removeedge.size()){
        if(removeedge.top() > 0){
            totalsum = totalsum - removeedge.top();
            removeedge.pop();
            C--;
        }else{
            break;
        }
    }
    totalsum = totalsum % 1000000007;
    if(totalsum < 0){
        return totalsum + 1000000007;
    }
    return totalsum;
}

int main()
{
    int n = 8;
    vector<vector<int>> abc;
    abc.push_back({1,2,8});
    abc.push_back({2,3,7});
    abc.push_back({3,4,11});
    abc.push_back({2,5,10});
    abc.push_back({2,6,10});
    abc.push_back({6,7,4});
    abc.push_back({4,8,6});
    int c = 2;
    cout << solve(n,abc,c) << '\n';
    return 0;
}