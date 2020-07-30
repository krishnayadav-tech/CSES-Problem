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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define isint(a) ((int)a==a)
#define mod 1000000007
#define INF 1e9
using namespace std;
typedef long long int ll;
typedef pair<int,int> pi;
struct Node{
    int data;
    int index;
    Node(int d,int i){
        data = d;
        index = i;
    }
    Node(){}
};
bool operator<(const Node& a,const Node& b){
    return a.data < b.data;
}
bool operator==(Node a,Node b){
    return a.data == b.data;
}
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    Node arr[n];
    Node brr[n];
    set<Node> ans;
    for(int i=0;i<n;i++){
        cin >> arr[i].data;
        brr[i].data = arr[i].data;
        brr[i].index = arr[i].index = i;
    }
    int maxe = 0;
    int j = 0;
    for(int i=0;i<n;i++){
        set<Node> :: iterator it = ans.find({arr[i].data,0});
        if(it != ans.end())
        {
            for(int k=j;k<=it->index;k++)
            {
                ans.erase(arr[k]);
            }
            j = it->index + 1;
        }
        ans.insert({arr[i]});
        maxe = max(maxe,ans.size());
    }
    cout << maxe << '\n';
    return 0;
}