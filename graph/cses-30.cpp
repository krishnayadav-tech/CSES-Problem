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
#include <chrono>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mod 1000000007
typedef long long int ll;
struct Edges{
    vector<int> abc;
    int start = 0;
    void add(int a){
        abc.push_back(a);
    }
};
class Timer{
public:
    Timer(){
        start_t = chrono::high_resolution_clock::now();
    }

    ~Timer(){
        end_t = chrono::high_resolution_clock::now();
    }

    void exec_time()
    {
        end_t = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_t - start_t;
        cout << fixed <<  diff.count() << endl;
    }

private:
    chrono::high_resolution_clock::time_point start_t;
    chrono::high_resolution_clock::time_point end_t;
    
};
int n;
int indegree[100000] = {0};
int outdegree[100000] = {0};
void dfs(int node,int par,vector<Edges>& edge,stack<int>& abc){
    int start = edge[node].start;
    while(start < edge[node].abc.size()){
        edge[node].start++;
        int mine = min(node,edge[node].abc[start]);
        int maxe = max(node,edge[node].abc[start]);
        dfs(edge[node].abc[start],node,edge,abc);
        start = edge[node].start;
    }
    abc.push(node);
}

void dfs2(int node,vector<Edges>& edge,bool visited[]){
    visited[node] = true;
    for(int x : edge[node].abc){
        if(visited[x] == false){
            dfs2(x,edge,visited);
        }
    }
}
int main(int size,char** args)
{
    // Timer t;
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
    int e;
    cin >> n >> e;
    vector<Edges> edge(n);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].add(b);
        outdegree[a]++;
        indegree[b]++;
    }

    bool alleven = true;
    for(int i=1;i<n-1;i++){
        if(indegree[i] != outdegree[i]){
            alleven = false;
            break;
        }
    }

    if(outdegree[0] - indegree[0] != 1){
        alleven = false;
    }

    if(outdegree[n-1] - indegree[n-1] != -1){
        alleven = false;
    }

    int c = 0;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(visited[i] == false && outdegree[i] != 0){
            dfs2(i,edge,visited);
            c++;
        }
    }
 
    if(alleven == false  or c > 1){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    

    stack<int> abc;
    dfs(0,-1,edge,abc);
    while(abc.size())
    {
        cout << abc.top() + 1 << ' ';
        abc.pop();
    }
    cout << '\n';
    // t.exec_time();
    return 0;
}