//TLE
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
set<int> tree[4*200000];
bool isoverlap(int a,int b,int x,int y){
    if(x >= a and x <= b){
        return true;
    }
    if(a >= x and a <= y ){
        return true;
    }
    return false;
}
 
void construct(int i,int ss,int se,int arr[],set<int> tree[]){
    if(ss == se){
        tree[i].insert(arr[ss]);
        return;
    }
    int mid = ss + (se - ss)/2;
    construct(i*2,ss,mid,arr,tree);
    construct(i*2+1,mid+1,se,arr,tree);
    for(int x : tree[i*2]){
        tree[i].insert(x);
    }
    for(int x : tree[i*2+1]){
        tree[i].insert(x);
    }
}
 
set<int> rangequery(int i,int ss,int se,int rs,int re,set<int> tree[]){
	if(re < ss or rs > se){
		set<int> ans;
		return ans;
	}
    if(ss >= rs && se <= re){
        return tree[i];
    }
    int mid = ss + (se - ss)/2;
    set<int> ans1,ans2;
    set<int> some;
    if(isoverlap(ss,mid,rs,re)){
        ans1 = rangequery(i*2,ss,mid,rs,re,tree);
    }
 
    if(isoverlap(mid+1,se,rs,re)){
        ans2 = rangequery(i*2+1,mid+1,se,rs,re,tree);
    }
 
    for(int x : ans1){
        some.insert(x);
    }
 
    for(int x : ans2){
        some.insert(x);
    }
    return some;
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
    int n,q;
    cin >> n >> q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    construct(1,1,n,arr,tree);
 
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << rangequery(1,1,n,a,b,tree).size() << '\n';
    }
    return 0;
}