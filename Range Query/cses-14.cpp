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


ll updateby(int i,int ss,int se,int rs,int re,ll value,ll tree[],ll tupdate[],ll dupdate[]){
    
    int mid = ss + (se - ss)/2;
    if(ss >= rs && se <= re){
        dupdate[i] = max(0,dupdate[i]) + value;
        tree[i] =  tree[i] + (se - ss + 1)*value;
        return tree[i];
    }
    
    if(tupdate[i] > -1){
        tree[i*2] =  (mid + 1 - ss) * tupdate[i];
        tree[i*2+1] = (se - mid) * tupdate[i];
        tupdate[i*2] = tupdate[i*2+1] = tupdate[i];
        dupdate[i*2 + 1] = 0;
        dupdate[i*2] = 0;
        tupdate[i] = -1;
    }

    if(dupdate[i] > -1){
        tree[i*2] = tree[i*2]  + ((mid + 1 - ss) * dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + ((se - mid) * dupdate[i]);
        dupdate[i*2] = max(0,dupdate[i*2]) + dupdate[i];
        dupdate[i*2+1] = max(0,dupdate[i*2+1]) + dupdate[i];
        dupdate[i] = -1;
    }

    ll ans1,ans2;
    if(isoverlap(rs,re,ss,mid)){
        ans1 = updateby(i*2,ss,mid,rs,re,value,tree,tupdate,dupdate);
    }else{
        ans1 = tree[i*2];
    }
    if(isoverlap(rs,re,mid+1,se)){
        ans2 = updateby((i*2)+1,mid+1,se,rs,re,value,tree,tupdate,dupdate);
    }else{
        ans2 = tree[(i*2)+1];
    }
    
    tree[i] = ans1 + ans2;
    return ans1 + ans2;
}

ll updateto(int i,int ss,int se,int rs,int re,ll value,ll tree[],ll tupdate[],ll dupdate[]){
    
    int mid = ss + (se - ss)/2;
    if(ss >= rs && se <= re){
        tupdate[i] = value;
        dupdate[i] = 0;
        tree[i] =  (se - ss + 1)*value;
        return tree[i];
    }
    

    ll ans1,ans2;
 
    if(tupdate[i] > -1){
        tree[i*2] =  (mid + 1 - ss) * tupdate[i];
        tree[i*2+1] = (se - mid) * tupdate[i];
        tupdate[i*2] = tupdate[i*2+1] = tupdate[i];
        dupdate[i*2 + 1] = 0;
        dupdate[i*2] = 0;
        tupdate[i] = -1;
    }

    if(dupdate[i] > -1){
        tree[i*2] = tree[i*2]  + ((mid + 1 - ss) * dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + ((se - mid) * dupdate[i]);
        dupdate[i*2] = max(0,dupdate[i*2]) + dupdate[i];
        dupdate[i*2+1] = max(0,dupdate[i*2+1]) + dupdate[i];
        dupdate[i] = -1;
    }

    if(isoverlap(rs,re,ss,mid)){
        ans1 = updateto(i*2,ss,mid,rs,re,value,tree,tupdate,dupdate);
    }else{
        ans1 = tree[i*2];
    }
    if(isoverlap(rs,re,mid+1,se)){
        ans2 = updateto((i*2)+1,mid+1,se,rs,re,value,tree,tupdate,dupdate);
    }else{
        ans2 = tree[(i*2)+1];
    }
    
    tree[i] = ans1 + ans2;
    return ans1 + ans2;
}
 
ll rangequery(int i,int ss,int se,int rs,int re,ll tree[],ll tupdate[],ll dupdate[]){
    
    int mid = ss + (se - ss)/2;
    if(ss >= rs && se <= re){
        
        return tree[i];
    }

    if(tupdate[i] > -1){
        tree[i*2] =  (mid + 1 - ss) * tupdate[i];
        tree[i*2+1] = (se - mid) * tupdate[i];
        tupdate[i*2] = tupdate[i*2+1] = tupdate[i];
        dupdate[i*2 + 1] = 0;
        dupdate[i*2] = 0;
        tupdate[i] = -1;
    }

    if(dupdate[i] > -1){
        tree[i*2] = tree[i*2]  + ((mid + 1 - ss) * dupdate[i]);
        tree[i*2+1] = tree[i*2+1] + ((se - mid) * dupdate[i]);
        dupdate[i*2] = max(0,dupdate[i*2]) + dupdate[i];
        dupdate[i*2+1] = max(0,dupdate[i*2+1]) + dupdate[i];
        dupdate[i] = -1;
    }
 
    ll ans1,ans2;
    ans1 = ans2 = 0;
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
    fill(tupdate,tupdate+(4*n),-1);
    fill(dupdate,dupdate+(4*n),-1);
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
            int x;
            cin >> x;
            updateby(1,1,n,a,b,x,tree,tupdate,dupdate);
            //incrase by 
            // for(int i=1;i<=15;i++)
            //     cout << tree[i] << ' ';
            // cout << '\n';
            continue;
        }


        if(i == 2){
            int a,b;
            cin >> a >> b;
            int x ;
            cin >> x;
            updateto(1,1,n,a,b,x,tree,tupdate,dupdate);
            // incrase to 
            continue;
        }
 
        int a,b;
        cin >> a >> b;
        // range query 
        cout << rangequery(1,1,n,a,b,tree,tupdate,dupdate) << '\n';
    }
    return 0;
}