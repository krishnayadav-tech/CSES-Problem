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
ll construct(int i,int ss,int se,int arr[],ll tree[]){
    if(ss==se){
        tree[i] = arr[ss];
        return 0;
    }
    int mid = ss + (se-ss)/2;
    ll ans1 = construct(i*2,ss,mid,arr,tree);
    ll ans2 = construct((i*2)+1,mid+1,se,arr,tree);
    return 0;
}

ll rangeupdate(int i,int ss,int se,int rs,int re,int value,int arr[],ll tree[]){
    if(ss >= rs && se <= re){
        tree[i] = tree[i] + value;
        return 0;
    }
    int mid = ss + (se-ss)/2;
    ll ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(ss,mid,rs,re)){
        ans1 = rangeupdate(i*2,ss,mid,rs,re,value,arr,tree);
    }
    if(isoverlap(mid+1,se,rs,re)){
        ans2 = rangeupdate((i*2)+1,mid+1,se,rs,re,value,arr,tree);
    }
    return 0;
}

ll getans(int i,int ss,int se,int index,int arr[],ll tree[]){
    if(ss == se && ss == index){
        return tree[i];
    }
    int mid = ss + (se-ss)/2;
    if(tree[i] != 0){
        tree[i*2] = tree[i*2] + tree[i];
        tree[(i*2)+1] = tree[(i*2)+1] + tree[i];
        tree[i] = 0;
    }
    ll ans;
    if(index <= mid){
        ans = getans(i*2,ss,mid,index,arr,tree);
    }else{
        ans = getans((i*2)+1,mid+1,se,index,arr,tree);
    }
    return ans;
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
    ll tree[4*n];
    fill(tree,tree+(4*n),0);
    construct(1,1,n,arr,tree);
    while(q--){
        char c;
        cin >> c;
        if(c == '1'){
            int a,b,c;
            cin >> a >> b >> c;
            rangeupdate(1,1,n,a,b,c,arr,tree);
            continue;
        }
        int a;
        cin >> a;
        cout << getans(1,1,n,a,arr,tree) << '\n';
    }
    return 0;
}