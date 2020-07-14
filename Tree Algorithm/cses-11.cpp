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
typedef vector<ll> vl;
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
vl segtree[NMAX];
long long int buildtree(int i,int ses,int see,vector<int>& data,vector<long long int>& tree)
{
    if(ses == see){
        tree[i] = value[data[ses-1]];
        return tree[i];
    }
    int mid = ses + (see - ses)/2;
    long long int value1,value2;
    value1 = buildtree(i*2,ses,mid,data,tree);
    value2 = buildtree(i*2+1,mid+1,see,data,tree);
    tree[i] = value1 + value2;
    return tree[i];
}

long long int updatetree(int i,int ses,int see,int in,int value,vector<long long int>& tree)
{
    if(ses==see and ses==in){
        tree[i] = value;
        return tree[i];
    }
    if((in < ses or in > see)){
        return tree[i];
    }
    if(ses == see)
        tree[i];
    
    int mid = ses + (see-ses)/2;
    long long int value1 = updatetree(i*2,ses,mid,in,value,tree);
    long long int value2 = updatetree((i*2)+1,mid+1,see,in,value,tree);
    tree[i] = value1 + value2;
    return tree[i];
}


long long int rangequery(int i,int ses,int see,int ras,int rae,vector<long long int>& tree)
{
    if(ses >= ras and see <= rae){
        return tree[i];
    }
    int mid = ses + (see - ses)/2;
    long long int value1 ,value2;
    value1 = 0;
    value2 = 0;
    if((ras >= ses and ras <= mid) or (ses >= ras and ses <= rae))
    {
        value1 = rangequery(i*2,ses,mid,ras,rae,tree);
    }

    if((ras >= mid+1 and ras <= see) or (mid+1 >= ras and mid+1 <= rae))
    {
        value2 = rangequery(i*2+1,mid+1,see,ras,rae,tree);
    }
    return value2 + value1;

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
    for(int i=0;i<n;i++)
        cin >> value[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    //DFS
    vector<bool> visited(n,false);
    dfs(0,visited,edge); 
    fill(visited.begin(),visited.end(),false);
    dfs2(0,visited,edge);
    for(int i=0;i<n;i++){
        int size = segarr[i].size();
        if(size == 0)
            continue;
        segtree[i].resize(size*4);
        fill(segtree[i].begin(),segtree[i].end(),0);
        buildtree(1,1,size,segarr[i],segtree[i]);
    }

    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int b,c;
            cin >> b >> c;
            b--;
            value[b] = c;
            int in = indexintree[b];
            int in2 = indexintreearr[b];
            int size = segarr[in].size();
            updatetree(1,1,size,in2+1,c,segtree[in]);
            continue;
        }
        int b;
        cin >> b;
        b--;
        
        long long int sum = 0;
        while(true){
            if(b == -1)
                break;
            int id = indexintree[b];
            int id2 = indexintreearr[b];
            sum = sum + rangequery(1,1,segarr[id].size(),1,id2+1,segtree[id]);
            b = parent[segarr[id][0]];
        }
        cout << sum << endl;
    }
    
    return 0;
}