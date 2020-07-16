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
#define BLOCK 50
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
struct query{
	int l;
	int r;
	int i;
};
bool operator<(query a,query b){
    return a.r < b.r;
}
vi edge[200000];
int value[200001];
int entryindex[200000];
int exitindex[200000];
int i = 0;
vi tour;
void dfs(int s,vi& visited,vi edge[])
{
    visited[s] = 1;
    entryindex[s] = i;
    tour.push_back(value[s]);
    for(int x : edge[s])
    {
        if(visited[x] == false)
        {
            i++;
            dfs(x,visited,edge);
        }
    }
    exitindex[s] = i;
}


int buildtree(int i,int ses,int see,vector<int>& data,vector<int>& tree)
{
    if(ses == see){
        tree[i] = data[ses];
        return tree[i];
    }
    int mid = ses + (see - ses)/2;
    int value1,value2;
    value1 = buildtree(i*2,ses,mid,data,tree);
    value2 = buildtree(i*2+1,mid+1,see,data,tree);
    tree[i] = value1 + value2;
    return tree[i];
}
 
int updatetree(int i,int ses,int see,int in,int value,vector<int>& tree)
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
    int value1 = updatetree(i*2,ses,mid,in,value,tree);
    int value2 = updatetree((i*2)+1,mid+1,see,in,value,tree);
    tree[i] = value1 + value2;
    return tree[i];
}
 
 
int rangequery(int i,int ses,int see,int ras,int rae,vector<int>& tree)
{
    if(ses >= ras and see <= rae){
        return tree[i];
    }
    int mid = ses + (see - ses)/2;
    int value1 ,value2;
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
    int n;
    cin >> n;
    map<int,int> pos;
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vi visited(n,0);
    dfs(0,visited,edge);
    for(int i=0;i<tour.size();i++){
        if(pos.find(tour[i]) == pos.end()){
            pos.insert({tour[i],i});
        }
    }
    int q;
    q = n;
    query arr[n];
    for(int i=0;i<n;i++){
        arr[i].l = entryindex[i];
        arr[i].r = exitindex[i];
        arr[i].i = i;
    }
 
    sort(arr,arr+n);
    int ans[q];
    vi tree(4*n);
    fill(tree.begin(),tree.end(),0);
    int start = 0;
    for(int i=0;i<n;i++){
        int l = arr[i].l;
        int r = arr[i].r;
        int id = arr[i].i;
        if(r < start){
            ans[id] = rangequery(1,1,n,l+1,r+1,tree);
        }else{
            for(int j=start;j<=r;j++){
                int id2 = pos[tour[j]];
                if(id2 == j){
                    updatetree(1,1,n,j+1,1,tree);
                }else{
                    updatetree(1,1,n,id2+1,0,tree);
                    updatetree(1,1,n,j+1,1,tree);
                    pos[tour[j]] = j;
                }
            }
            ans[id] = rangequery(1,1,n,l+1,r+1,tree);
            start = r + 1;
        }
    }   

    for(int i=0;i<q;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}