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
int sts = 0;
int n;
int tree[4001][4001];
int tree2[4001][4001];
bool isoverlap(int a,int b,int x,int y){
    if(x >= a and x <= b){
        return true;
    }
    if(a >= x and a <= y ){
        return true;
    }
    return false;
}
 
int construct(int i,int ss,int se,int arr[],int tree[]){
    sts++;
    if(ss==se){
        tree[i] = arr[ss];
        return tree[i];
    }
    int mid = ss + (se-ss)/2;
    int ans1 = construct(i*2,ss,mid,arr,tree);
    int ans2 = construct((i*2)+1,mid+1,se,arr,tree);
    tree[i] = ans1 + ans2;
    return tree[i];
}
 
void construct2(int i,int ss,int se,int tree[][4001],int tree2[][4001]){
    if(ss==se){
        for(int j=1;j<=sts;j++){
            tree2[i][j] = tree[ss][j];
        }
        return;
    }
    int mid = ss + (se-ss)/2;
    construct2(i*2,ss,mid,tree,tree2);
    construct2((i*2)+1,mid+1,se,tree,tree2);
    for(int j=1;j<=2*n;j++){
        tree2[i][j] = tree2[i*2][j] + tree2[i*2+1][j];
    }
}
 
set<int> updateindex;
int update(int i,int ss,int se,int index,int value,int arr[],int tree[]){
    
    if(ss==se && ss==index){
        updateindex.insert(i);
        tree[i] = value;
        arr[index] = value;
        return tree[i];
    }
 
    if(index < ss or index > se){
        return tree[i];
    }
    if(ss == se){
        return tree[i];
    }
 
    int mid = ss + (se-ss)/2;
    int ans1 = update(i*2,ss,mid,index,value,arr,tree);
    int ans2 = update((i*2)+1,mid+1,se,index,value,arr,tree);
    tree[i] = ans1 + ans2;
    updateindex.insert(i);
    return tree[i];
}
 
 
void update2(int i,int ss,int se,int index,int tree[][4001],int tree2[][4001]){
    if(ss==se && ss==index){
        for(int x : updateindex){
            tree2[i][x] = tree[ss][x];
        }
        return;
    }
 
    if(index < ss or index > se){
        return;
    }
    if(ss == se){
        return;
    }
 
    int mid = ss + (se-ss)/2;
    update2(i*2,ss,mid,index,tree,tree2);
    update2(i*2+1,mid+1,se,index,tree,tree2);
    for(int j : updateindex){
        tree2[i][j] = tree2[i*2][j] + tree2[i*2+1][j];
    }
}
 
int getans(int i,int ss,int se,int rs,int re,int tree[]){
    if(ss >= rs && se <= re){
        return tree[i];
    }
 
    int mid = ss + (se-ss)/2;
    int ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(ss,mid,rs,re)){
        ans1 = getans(i*2,ss,mid,rs,re,tree);
    }
    if(isoverlap(mid+1,se,rs,re)){
        ans2 = getans((i*2)+1,mid+1,se,rs,re,tree);
    }
    return (ans1 + ans2);
}
 
int getans2(int i,int ss,int se,int a,int b,int c,int d,int tree[][4001],int tree2[][4001]){
    if(ss >= a && se <= c){
        int ans = getans(1,1,n,b,d,tree2[i]);
        return ans;
    }
 
    int mid = ss + (se-ss)/2;
    int ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(ss,mid,a,c)){
        ans1 = getans2(i*2,ss,mid,a,b,c,d,tree,tree2);
    }
    if(isoverlap(mid+1,se,a,c)){
        ans2 = getans2((i*2)+1,mid+1,se,a,b,c,d,tree,tree2);
    }
    return (ans1 + ans2);
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
    int q;
    cin >> n >> q;
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            char c;
            cin >> c;
            if(c == '*')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
 
    for(int i=1;i<=n;i++){
        construct(1,1,n,arr[i],tree[i]);
    }
    construct2(1,1,n,tree,tree2);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int a,b;
            cin >> a >> b;
            int value;
            if(arr[a][b] == 0){
                value = 1;
            }else{
                value = 0;
            }
            updateindex.clear();
            update(1,1,n,b,value,arr[a],tree[a]);
            update2(1,1,n,a,tree,tree2);
            continue;
        }
 
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << getans2(1,1,n,a,b,c,d,tree,tree2) << '\n';
    }
    return 0;
}