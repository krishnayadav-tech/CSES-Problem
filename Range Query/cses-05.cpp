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
    if(ss==se){
        tree[i] = arr[ss];
        return tree[i];
    }
    int mid = ss + (se-ss)/2;
    int ans1 = construct(i*2,ss,mid,arr,tree);
    int ans2 = construct((i*2)+1,mid+1,se,arr,tree);
    tree[i] = ans1^ans2;
    return tree[i];
}

int update(int i,int ss,int se,int index,int value,int arr[],int tree[]){
    
    if(ss==se && ss==index){
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
    tree[i] = ans1 ^ ans2;
    return tree[i];
}

int getans(int i,int ss,int se,int rs,int re,int arr[],int tree[]){
    if(ss >= rs && se <= re){
        return tree[i];
    }

    int mid = ss + (se-ss)/2;
    int ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(ss,mid,rs,re)){
        ans1 = getans(i*2,ss,mid,rs,re,arr,tree);
    }
    if(isoverlap(mid+1,se,rs,re)){
        ans2 = getans((i*2)+1,mid+1,se,rs,re,arr,tree);
    }
    return (ans1 ^ ans2);
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
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    int tree[4*n];
    fill(tree,tree+(4*n),INF);
    construct(1,1,n,arr,tree);
    
    while(q--){
        int a,b;
        cin  >>  a >> b;
        cout << getans(1,1,n,a,b,arr,tree) << '\n';
    }
    return 0;
}