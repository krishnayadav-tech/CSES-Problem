#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,bool visited[],vector<int> adj[],bool rect[]){
    visited[node] = true;
    rect[node] = true;
    bool cycle = false;
    for(int i : adj[node]){
        if(!visited[i] && cycle == false){
            cycle = dfs(i,visited,adj,rect);
        }else if(visited[i] && rect[i] == true){
            return true;
        }
    }
    rect[node] = false;
    return cycle;
}

void print(priority_queue <int, vector<int>, greater<int>> abc){
    while(abc.size() > 0){
        cout << abc.top() <<  ' ';
        abc.pop();
    }
    cout << '\n';
}
vector<int> topologicalsort(int n,vector<int> edge[],vector<int> zero,int indegree[]){
    vector<int> ans;
    priority_queue <int, vector<int>, greater<int>> abc;
    for(int i=0;i<zero.size();i++){
        abc.push(zero[i]);
    }
    while(abc.size() > 0){
        int temp = abc.top();
        abc.pop();
        ans.push_back(temp);
        indegree[temp] = -1;
        for(int x : edge[temp]){
            indegree[x] = indegree[x] - 1;
            if(indegree[x] == 0){
                abc.push(x);
            }
        }
    }
    return ans;
}
int main()
{
    // freopen("input.txt","r",stdin);
    int n,e;
    cin  >> n >>  e;
    vector<int> edge[n];
    int indegree[n] = {0};
    for(int i=0;i<e;i++){
        int from,to;
        cin >> from >> to;
        edge[from-1].push_back(to-1);
        indegree[to-1]++;
    }
    
    bool rec[n] = {0};
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(dfs(i,visited,edge,rec)){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    
    
    //find 0'th degree node
    vector<int> zerothnode;
    for(int i=0;i<n;i++){
        // sort(edge[i].begin(),edge[i].end());
        if(indegree[i] == 0){
            zerothnode.push_back(i);
        }
    }
    
    
    vector<int> topo = topologicalsort(n,edge,zerothnode,indegree);
    for(int x : topo){
        cout << x+1 <<  ' ';
    }
    cout << '\n';
    

    return 0;
}