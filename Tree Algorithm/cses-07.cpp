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
vector<pair<int,int>> info;
void dfs(int s,int depth,vector<int> edge[],bool visited[]){
    visited[s] = true;
    info.push_back({s,depth});
    for(int x : edge[s])
    {
        if(visited[x] == false){
            dfs(x,depth+1,edge,visited);
            info.push_back({s,depth});
        }
    }
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
 

void construct(int i,int ss,int se,vector<pair<int,int>>& tree){

    if(ss == se){
        tree[i] = info[ss];
        return;
    }
    int mid = ss + (se - ss)/2;
    construct(i*2,ss,mid,tree);
    construct(i*2+1,mid+1,se,tree);
    if(tree[i*2].second < tree[i*2+1].second){
        tree[i] = tree[i*2];
    }else{
        tree[i] = tree[i*2+1];
    }
}

pair<int,int> rangequery(int i,int ss,int se,int rs,int re,vector<pair<int,int>>& tree){
    if(ss >= rs and se <= re){
        return tree[i];
    }

    int mid = ss + (se - ss)/2;
    pair<int,int> first = {-1,INF};
    pair<int,int> second = {-1,INF};
    if(isoverlap(rs,re,ss,mid)){
        first = rangequery(i*2,ss,mid,rs,re,tree);
    }

    if(isoverlap(rs,re,mid+1,se)){
        second = rangequery(i*2+1,mid+1,se,rs,re,tree);
    }

    if(first.second < second.second){
        return first;
    }else{
        return second;
    }
}

int main(int size,char** args)
{
    info.resize(1);
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
    int n,q;
    cin >> n >> q;
    vector<int> edge[n];
    for(int i=1;i<n;i++){
        int temp;
        cin >> temp;
        temp--;
        edge[i].push_back(temp);
        edge[temp].push_back(i);
    }
    bool visited[n] = {false};
    dfs(0,0,edge,visited);

    int lastindex[n];
    fill(lastindex,lastindex+n,-1);
    for(int i=1;i<info.size();i++){
        if(lastindex[info[i].first] == -1){
            lastindex[info[i].first] = i;
        }
    }
    int n2 = info.size() - 1;
    vector<pair<int,int>> tree(4*n2,{-1,INF});
    construct(1,1,n2,tree);
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int start = min(lastindex[b],lastindex[a]);
        int end = max(lastindex[b],lastindex[a]);
        cout << rangequery(1,1,n2,start,end,tree).first + 1 << '\n';
    }
    return 0;
}