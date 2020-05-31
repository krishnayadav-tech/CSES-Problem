// A C++ Program to detect cycle in a graph 
#include<bits/stdc++.h> 

using namespace std; 
stack<int> abc2;
bool dfs(int s,vector<int> edge[],bool visited[],bool rec[]){

    rec[s] = true;
    visited[s] = true;
    abc2.push(s);
    for(int x : edge[s]){
        if(visited[x] == false){
            if(dfs(x,edge,visited,rec)){
                return true;
            }
        }else{
            if(rec[x] == true){
                abc2.push(x);
                return true;
            }
        }
    }
    abc2.pop();
    rec[s] = false;
    return false;
}
void print(){
    vector<int> ans2;
    int s = abc2.top();
    ans2.push_back(s);
    abc2.pop();
    while(abc2.size()){
        ans2.push_back(abc2.top());
        if(abc2.top() == s ){
            break;
        }
        abc2.pop();
    }
    cout <<  ans2.size() << '\n';
    for(int i=0;i<ans2.size();i++){
        cout << ans2[ans2.size() -1 - i] + 1<< ' ';
    }
    cout << '\n';
}

int main() 
{ 
    // freopen("input.txt","r",stdin);
    int n,e;
    cin >> n >> e;
	vector<int> edge[n];
	for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        if(a == b){
            continue;
        }
        a--;b--;
        edge[a].push_back(b);
    }

    bool visited[n] = {false};
    bool rec[n] = {false};
    for(int i=0;i<n;i++){
        while(abc2.size())
            abc2.pop();
        if(dfs(i,edge,visited,rec)){
            print();
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
	return 0; 
} 
