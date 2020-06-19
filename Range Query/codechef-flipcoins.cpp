/* https://www.codechef.com/problems/FLIPCOIN */
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

ll rangeupdate(int i,int ss,int se,int rs,int re,ll tree[],ll tupdate[]){
    // cout << ss << ' ' << se << '\n';
    if(ss >= rs && se <= re){
        int n = se - ss + 1;
        int up = n - tree[i];
        tree[i] = up;
        tupdate[i]++;
        tupdate[i] = tupdate[i] % 2;
        return tree[i];
    }
    int mid = ss + (se-ss)/2;
    ll ans1,ans2;

    if(tupdate[i] == 1){
        tupdate[i*2]++;
        tupdate[i*2] = tupdate[i*2] % 2;
        tupdate[i*2 + 1]++;
        tupdate[i*2 + 1] = tupdate[i*2 + 1] % 2;
        tree[i*2] = (mid - ss) + 1 - tree[i*2]; 
        tree[i*2+1] = (se - mid) - tree[i*2 + 1];
    }
    tupdate[i] = 0;

    ans1 = ans2 = 0;
    if(isoverlap(ss,mid,rs,re)){
        ans1 = rangeupdate(i*2,ss,mid,rs,re,tree,tupdate);
    }else
        ans1 = tree[i*2];
    if(isoverlap(mid+1,se,rs,re)){
        ans2 = rangeupdate((i*2)+1,mid+1,se,rs,re,tree,tupdate);
    }else   
        ans2 = tree[i*2 + 1];
    
    tree[i] = ans1 + ans2;
    return tree[i];
}

ll getans(int i,int ss,int se,int a,int b,ll tree[],ll tupdate[]){
    // cout << ss << ' ' << se << '\n';
    if(ss >= a && se <= b){
        return tree[i];
    }
    int mid = ss + (se-ss)/2;
    
    if(tupdate[i] == 1){
        tupdate[i*2]++;
        tupdate[i*2] = tupdate[i*2] % 2;
        tupdate[i*2 + 1]++;
        tupdate[i*2 + 1] = tupdate[i*2 + 1] % 2;
        tree[i*2] = (mid - ss) + 1 - tree[i*2]; 
        tree[i*2+1] = (se - mid) - tree[i*2 + 1];
    }
    tupdate[i] = 0;

    ll ans1,ans2;
    ans1 = ans2 = 0;
    if(isoverlap(ss,mid,a,b)){
        ans1 = getans(i*2,ss,mid,a,b,tree,tupdate);
    }
    
    if(isoverlap(mid+1,se,a,b)){
        ans2 = getans(i*2+1,mid+1,se,a,b,tree,tupdate);
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
    ll tree[4*n];
    ll tupdate[4*n];
    fill(tree,tree+(4*n),0);
    fill(tupdate,tupdate+(4*n),0);
    while(q--){
        char c;
        cin >> c;
        if(c == '0'){
            int a,b;
            cin >> a >> b;
            a++;
            b++;
            rangeupdate(1,1,n,a,b,tree,tupdate);
            continue;
        }
        int a,b;
        cin >> a >> b;
        a++;
        b++;
        cout << getans(1,1,n,a,b,tree,tupdate) << '\n';
    }
    return 0;
}
