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
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
int startindex[200000];
int endindex[200000];
int arr[200000];
int n;
vector<int> value;
void dfs(int s,vector<int> edge[],bool visited[]){
    startindex[s] = value.size();
    value.push_back(arr[s]);
    visited[s] = true;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs(x,edge,visited);
        }
    }
    endindex[s] = value.size() - 1;
}

bool isoverlap(int a,int b,int x,int y){
    if(x >= a and x <= b){
        return true;
    }
    if(a >= x and a <= y ){
        return true;
    }
    return false;
}
 

void construct(int i,int ss,int se,ll tree[]){
    if(ss == se){
        tree[i] = value[ss];
        return;
    }
    int mid = ss + (se - ss)/2;
    construct(i*2,ss,mid,tree);
    construct(i*2+1,mid+1,se,tree);
    tree[i] = tree[i*2] + tree[i*2+1];
}

void update(int i,int ss,int se,int index,int val,ll tree[]){
    if(ss == se && se == index){
        value[index] = val;
        tree[i] = val;
        return;
    }
    int mid = ss + (se - ss)/2;
    if(index > mid){
        update(i*2+1,mid+1,se,index,val,tree);
    }else{
        update(i*2,ss,mid,index,val,tree);
    }
    tree[i] = tree[i*2] + tree[i*2+1];
}

ll rangequery(int i,int ss,int se,int rs,int re,ll tree[]){
    if(ss >= rs && se <= re){
        return tree[i];
    }
    int mid = ss + (se - ss)/2;
    ll ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(rs,re,ss,mid)){
        ans1 = rangequery(i*2,ss,mid,rs,re,tree);
    }

    if(isoverlap(rs,re,mid+1,se)){
        ans2 = rangequery(i*2+1,mid+1,se,rs,re,tree);
    }
    return ans1 + ans2;
}

int main(int size,char** args)
{
    value.resize(1);
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
    int q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    vector<int> edge[n];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    bool visited[n] = {false};
    dfs(0,edge,visited);
    long long int tree[4*n];
    fill(tree,tree+(4*n),0);
    construct(1,1,n,tree);

    
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int node,value;
            cin >> node >> value;
            node--;
            int index = startindex[node];
            update(1,1,n,index,value,tree);
            continue;
        }
        int node;
        cin >> node;
        node--;
        int rs = startindex[node];
        int re = endindex[node];
        cout << rangequery(1,1,n,rs,re,tree) << '\n';
    }

    return 0;
}