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
#define BLOCK 51
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
bool comp(query a , query b)
{
	if(a.l / BLOCK != b.l/BLOCK)
	return a.l/BLOCK < b.l/BLOCK;
	
	return a.r < b.r;
}

unordered_map<int,int> fre;
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
    for(int i=0;i<n;i++)
        cin >> value[i];
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
    
    int q;
    q = n;
    query arr[n];
    for(int i=0;i<n;i++){
        arr[i].l = entryindex[i];
        arr[i].r = exitindex[i];
        arr[i].i = i;
    }

    sort(arr,arr+n,comp);
    int ans[q];
    int rl,rr;
    rl = rr = arr[0].l;
    int count = 0;
    fre[tour[rl]]++;
    count = 1;
    for(int i=0;i<q;i++){
        
        int l,r,id; 
        l = arr[i].l;
        r = arr[i].r;
        id = arr[i].i;
        while(l < rl){
            rl--;
            fre[tour[rl]]++;
            if(fre[tour[rl]] == 1){
                count++;
            }
        }
        while(l > rl){
            fre[tour[rl]]--;
            if(fre[tour[rl]] == 0){
                count--;
            }
            rl++;
        }
 
        while(r > rr){
            rr++;
            fre[tour[rr]]++;
            if(fre[tour[rr]] == 1){
                count++;
            }
        }
 
        while(r < rr){
            fre[tour[rr]]--;
            if(fre[tour[rr]] == 0){
                count--;
            }
            rr--;
        }
 
        ans[id] = count;
    }
 
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}