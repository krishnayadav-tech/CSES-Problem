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

int construct(int i,int ss,int se,int arr[],int tree[]){
    if(ss==se){
        tree[i] = arr[ss];
        return 0;
    }
    int mid = ss + (se-ss)/2;
    construct(i*2,ss,mid,arr,tree);
    construct((i*2)+1,mid+1,se,arr,tree);
    return 0;
}


int update(int i,int ss,int se,int index,int arr[],int tree[]){
    
    if(ss==se && ss==index){
        tree[i] = -1;
        arr[index] = -1;
        return tree[i];
    }
    int mid = ss + (se-ss)/2;
    int ans;
    if(index <= mid){
        ans = update(i*2,ss,mid,index,arr,tree);
        tree[i] = tree[i] + ans;
    }
    else{
        ans = update((i*2)+1,mid+1,se,index,arr,tree);
    }
    return ans;
}

int getans(int i,int ss,int se,int index,int arr[],int tree[]){
    if(ss == se && ss==index){
        return ss;
    }
    int mid = ss + (se-ss)/2;
    if(index >= (mid+1 + tree[i])){
        return getans((i*2)+1,mid+1,se,index-tree[i],arr,tree);
    }else{
        return getans(i*2,ss,mid,index,arr,tree);
    }
}


void printtree(int tree[])
{
    for(int i=1;i<=9;i++){
        cout << tree[i] << ' ';
    }
    cout << '\n';
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
    int arr[n+1];
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    int tree[4*n];
    fill(tree,tree+(4*n),0);
    construct(1,1,n,arr,tree);
    //  printtree(tree);
    int n2 = n;
    while(n2--){
        int x;
        cin >> x;
        int index = getans(1,1,n,x,arr,tree);
        cout << arr[index] << ' ';
        update(1,1,n,index,arr,tree);
        // printtree(tree);
    }
    cout << '\n';
    return 0;
}