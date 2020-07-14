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
typedef vector<int> vi;
typedef pair<int,int> pi;
#define NMAX 200001
ll value[NMAX];
vector<int> edge[NMAX];
int subtree[NMAX];
pair<int,int> maxsubtree[NMAX];
int indexintree[NMAX];
int indexintreearr[NMAX];
vi segarr[NMAX];
int parent[NMAX];
vi segtree[NMAX];
vi byupdate[NMAX];
bool isoverlap(int a,int b,int x,int y){
    if(x >= a and x <= b){
        return true;
    }
    if(a >= x and a <= y ){
        return true;
    }
    return false;
}
 
int updateby(int i,int ss,int se,int rs,int re,ll value,vi& tree,vi& dupdate){
    
    int mid = ss + (se - ss)/2;
    if(ss >= rs && se <= re){
        dupdate[i] = max(0,dupdate[i]) + value;
        tree[i] =  tree[i] + (se - ss + 1)*value;
        return tree[i];
    }
     
    if(dupdate[i] > -1){
        tree[i*2] = tree[i*2]  + ((mid + 1 - ss) * dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + ((se - mid) * dupdate[i]);
        dupdate[i*2] = max(0,dupdate[i*2]) + dupdate[i];
        dupdate[i*2+1] = max(0,dupdate[i*2+1]) + dupdate[i];
        dupdate[i] = -1;
    }
 
    int ans1,ans2;
    if(isoverlap(rs,re,ss,mid)){
        ans1 = updateby(i*2,ss,mid,rs,re,value,tree,dupdate);
    }else{
        ans1 = tree[i*2];
    }
    if(isoverlap(rs,re,mid+1,se)){
        ans2 = updateby((i*2)+1,mid+1,se,rs,re,value,tree,dupdate);
    }else{
        ans2 = tree[(i*2)+1];
    }
    
    tree[i] = ans1 + ans2;
    return ans1 + ans2;
}
 
 
 
int rangequery(int i,int ss,int se,int rs,int re,vi& tree,vi& dupdate){
    int mid = ss + (se - ss)/2;
    if(ss >= rs && se <= re){
        
        return tree[i];
    }

 
    if(dupdate[i] > -1){
        tree[i*2] = tree[i*2]  + ((mid + 1 - ss) * dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + ((se - mid) * dupdate[i]);
        dupdate[i*2] = max(0,dupdate[i*2]) + dupdate[i];
        dupdate[i*2+1] = max(0,dupdate[i*2+1]) + dupdate[i];
        dupdate[i] = -1;
    }
 
    int ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(rs,re,ss,mid)){
        ans1 = rangequery(i*2,ss,mid,rs,re,tree,dupdate);
    }
    if(isoverlap(rs,re,mid+1,se)){
        ans2 = rangequery((i*2)+1,mid+1,se,rs,re,tree,dupdate);
    }
    return ans1 + ans2;
}
 
int dfs(int s,vector<bool>& visited,vector<int> edge[]){
    visited[s] = true;
    int y = 1;
    for(int x : edge[s]){
        if(visited[x] == false){
            parent[x] = s;
            int temp = dfs(x,visited,edge);
            y += temp;
            if(maxsubtree[s].first == 0){
                maxsubtree[s] = {x,temp};
            }else{
                if(temp > maxsubtree[s].second){
                    maxsubtree[s] = {x,temp};
                }
            }
        }
    }
    subtree[s] = y;
    return y;
}
 
int i = 0;
void dfs2(int s,vector<bool>& visited,vector<int> edge[]){
    visited[s] = true;
    segarr[i].push_back(s);
    indexintreearr[s] = segarr[i].size() - 1;
    indexintree[s] = i;
    if(maxsubtree[s].first != 0)
        dfs2(maxsubtree[s].first,visited,edge);
    for(int x : edge[s])
    {
        if(visited[x] == false)
        {
            i++;
            dfs2(x,visited,edge);
        }
    }
}
// Finding LCA
vector<pair<int,int>> info;
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
 
int main(int size,char** args)
{
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
    fill(parent,parent+NMAX,-1);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    //DFS
    /* LCA */
    bool visit[n] = {false};
    dfs(0,0,edge,visit);
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
    /*LCA END*/
 
    vector<bool> visited(n,false);
    dfs(0,visited,edge); 
    fill(visited.begin(),visited.end(),false);
    dfs2(0,visited,edge);
    for(int i=0;i<n;i++){
        int size = segarr[i].size();
        if(size == 0)
            continue;
        segtree[i].resize(size*4);
        byupdate[i].resize(size*4);
        fill(segtree[i].begin(),segtree[i].end(),0);
        fill(byupdate[i].begin(),byupdate[i].end(),-1);
    }
 
    
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int start = min(lastindex[b],lastindex[a]);
        int end = max(lastindex[b],lastindex[a]);
        int x = rangequery(1,1,n2,start,end,tree).first;
        int xarr = indexintree[x];
        while(true){
            int id = indexintree[a];
            int id2 = indexintreearr[a];
            if(xarr == id){
                updateby(1,1,segarr[id].size(),indexintreearr[x]+1,id2+1,1,segtree[id],byupdate[id]);
                break;
            }else{
                updateby(1,1,segarr[id].size(),1,id2+1,1,segtree[id],byupdate[id]);
            }
            a = parent[segarr[id][0]];
        }
 
        while(true){
 
            int id = indexintree[b];
            int id2 = indexintreearr[b];
            if(xarr == id){
                
                updateby(1,1,segarr[id].size(),indexintreearr[x]+1,id2+1,1,segtree[id],byupdate[id]);
                break;
            }else{
                updateby(1,1,segarr[id].size(),1,id2+1,1,segtree[id],byupdate[id]);
            }
            b = parent[segarr[id][0]];
        }
        updateby(1,1,segarr[xarr].size(),indexintreearr[x]+1,indexintreearr[x]+1,-1,segtree[xarr],byupdate[xarr]);
    }
 
    for(int i=0;i<n;i++){
        int id = indexintree[i];
        int id2 = indexintreearr[i];
        cout << rangequery(1,1,segarr[id].size(),id2+1,id2+1,segtree[id],byupdate[id]) << " ";
    }
    return 0;
}