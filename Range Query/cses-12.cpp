#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <chrono>
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
typedef vector<int> vi;
struct query{
	int l=0;
	int r=0;
	int i=-1;
};
bool operator<(query a,query b){
    return a.r < b.r;
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
    auto s = chrono::high_resolution_clock::now();
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
    scanf("%d",&n);
    scanf("%d",&q);
    int value[n];
    map<int,int> pos;
    for(int i=0;i<n;i++){
        scanf("%d",&value[i]);
        if(pos.find(value[i]) == pos.end()){
            pos.insert({value[i],i});
        }
    }
    query arr[q];
    for(int i=0;i<q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;
        b--;
        arr[i].i = i;
        arr[i].l = a;
        arr[i].r = b;
    }
    sort(arr,arr+q);
    int ans[q];
    vi tree(4*n);
    fill(tree.begin(),tree.end(),0);
    int start = 0;
    for(int i=0;i<q;i++){
        int l = arr[i].l;
        int r = arr[i].r;
        int id = arr[i].i;
        if(id == -1)
            continue;
        if(r < start){
            ans[id] = rangequery(1,1,n,l+1,r+1,tree);
        }else{
            for(int j=start;j<=r;j++){
                int id2 = pos[value[j]];
                if(id2 == j){
                    updatetree(1,1,n,j+1,1,tree);
                }else{
                    updatetree(1,1,n,id2+1,0,tree);
                    updatetree(1,1,n,j+1,1,tree);
                    pos[value[j]] = j;
                }
            }
            ans[id] = rangequery(1,1,n,l+1,r+1,tree);
            start = r + 1;
        }
    }   
   
 
    for(int i=0;i<q;i++){
        printf("%d ",ans[i]);
    }
    
    auto e = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = e - s;
    // printf("%f",diff.count());
    return 0;
}