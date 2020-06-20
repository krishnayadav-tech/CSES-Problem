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
int query;
int queryb[4*200000];
int queryt[4*200000];
bool isoverlap(int a,int b,int x,int y){
    if(x >= a and x <= b){
        return true;
    }
    if(a >= x and a <= y ){
        return true;
    }
    return false;
}
 
void construct(int i,int ss,int se,int arr[],ll tree[]){
    if(ss == se){
        tree[i] = arr[ss];
        return;
    }
    int mid = ss + (se - ss)/2;
    construct(i*2,ss,mid,arr,tree);
    construct((i*2)+1,mid+1,se,arr,tree);
    tree[i] = tree[i*2] + tree[(i*2)+1];
}

ll APSum(ll s,int n,int d){
    return (((2*s) + ((n-1)*d)) * n)/2;
}

ll NthTerm(ll s,int n,int d){
    return s + (n-1)*d;
}


int value = 1;
ll update(int i,int ss,int se,int rs,int re,ll tree[],ll tupdate[],ll dupdate[]){
    
    if(ss >= rs && se <= re){
        
        tupdate[i] = tupdate[i] + value;
        dupdate[i]++;
        tree[i] = tree[i] + APSum(value,(se - ss + 1),1);
        value = value + 1 + (se - ss);
        return tree[i];
    }
    
    
    int mid = ss + (se - ss)/2;
    ll ans1,ans2;
    if(tupdate[i] > 0){
        dupdate[i*2] += dupdate[i];
        dupdate[i*2+1] += dupdate[i];
        tupdate[i*2] = tupdate[i*2] + tupdate[i];
        tupdate[i*2+1] = tupdate[i*2 + 1] + NthTerm(tupdate[i],mid+2-ss,dupdate[i]);
        tree[i*2] = tree[i*2] + APSum(tupdate[i],mid+1-ss,dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + APSum(NthTerm(tupdate[i],mid+2-ss,dupdate[i]),se - mid,dupdate[i]);
        tupdate[i] = 0;
        dupdate[i] = 0;
    }
 
    if(isoverlap(rs,re,ss,mid)){
        ans1 = update(i*2,ss,mid,rs,re,tree,tupdate,dupdate);
    }else{
        ans1 = tree[i*2];
    }
    if(isoverlap(rs,re,mid+1,se)){
        ans2 = update((i*2)+1,mid+1,se,rs,re,tree,tupdate,dupdate);
    }else{
        ans2 = tree[(i*2)+1];
    }
    
    tree[i] = ans1 + ans2;
    return ans1 + ans2;
}
 
ll rangequery(int i,int ss,int se,int rs,int re,ll tree[],ll tupdate[],ll dupdate[]){
    if(ss >= rs && se <= re){
        
        return tree[i];
    }
 
    int mid = ss + (se - ss)/2;
    ll ans1,ans2;
    ans1 = ans2 = 0;
    if(tupdate[i] > 0){
        dupdate[i*2] += dupdate[i];
        dupdate[i*2+1] += dupdate[i];
        tupdate[i*2] = tupdate[i*2] + tupdate[i];
        tupdate[i*2+1] = tupdate[i*2 + 1] + NthTerm(tupdate[i],mid+2-ss,dupdate[i]);
        tree[i*2] = tree[i*2] + APSum(tupdate[i],mid+1-ss,dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + APSum(NthTerm(tupdate[i],mid+2-ss,dupdate[i]),se - mid,dupdate[i]);
        tupdate[i] = 0;
        dupdate[i] = 0;
    }
    if(isoverlap(rs,re,ss,mid)){
        ans1 = rangequery(i*2,ss,mid,rs,re,tree,tupdate,dupdate);
    }
    if(isoverlap(rs,re,mid+1,se)){
        ans2 = rangequery((i*2)+1,mid+1,se,rs,re,tree,tupdate,dupdate);
    }
    return ans1 + ans2;
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
    ll tupdate[4*n];
    ll dupdate[4*n];
    fill(tupdate,tupdate+(4*n),0);
    fill(dupdate,dupdate+(4*n),0);
    fill(tree,tree+(4*n),0);
    construct(1,1,n,arr,tree);
    // for(int i=1;i<=15;i++)
    //     cout << tree[i] << ' ';
    // cout << '\n';
    while(q--){
        int i;
        cin >> i;
        if(i == 1){
            int a,b;
            cin >> a >> b;
            value = 1;
            update(1,1,n,a,b,tree,tupdate,dupdate);
            // for(int i=1;i<=15;i++)
            //     cout << tree[i] << ' ';
            // cout << '\n';
            continue;
        }
 
        int a,b;
        cin >> a >> b;
        cout << rangequery(1,1,n,a,b,tree,tupdate,dupdate) << '\n';
    }
    return 0;
}