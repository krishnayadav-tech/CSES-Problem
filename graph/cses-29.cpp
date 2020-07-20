#include <bits/stdc++.h>
using namespace std;

struct Edges{
public:
    int start = 0;
    vector<int> abc;
    void push_back(int a){
        abc.push_back(a);
    }
private:
};

void dfs(int node,vector<Edges>& edge,stack<int>& abc){
    int start = edge[node].start;
    while(start < edge[node].abc.size()){
        edge[node].start++;
        int mine = min(node,edge[node].abc[start]);
        int maxe = max(node,edge[node].abc[start]);
        dfs(edge[node].abc[start],edge,abc);
        start = edge[node].start;
    }
    abc.push(48 + (node & 1));
}

int main()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << "10" << endl;
        return 0;
    }

    int node_s = pow(2,n-1);
    int node_v = node_s;
    vector<Edges> edge(node_v);
    bitset<32> number_temp;
    for(int i=0;i<n-1;i++){
        number_temp.set(i);
    }
    int another_temp = number_temp.to_ulong();
    for(int i=0;i<node_v;i++){
        edge[i].push_back((i << 1) & another_temp);
        edge[i].push_back(((i << 1) | 1) & another_temp);
    }
    stack<int> abc;
    dfs(0,edge,abc);
    string ans;
    for(int i=0;i<n-1;i++){
        ans.push_back('0');
    }
    abc.pop();
    while(abc.size()){
        ans.push_back((char)abc.top());
        abc.pop();
    }
    cout << ans << endl;
    return 0;
}