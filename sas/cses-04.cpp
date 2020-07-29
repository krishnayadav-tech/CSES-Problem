#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data,index;
    int ans;
};
bool operator<(Node a,Node b){
    return a.ans < b.ans;
}
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int arr[n];
    Node brr[m];
    set<int> ans;
    map<int,int> ans2;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans.insert(arr[i]);
        ans2[arr[i]]++;
    }
    for(int i=0;i<m;i++){
        cin >> brr[i].data;
        brr[i].index = i;
    }
    
    //  sort(brr,brr+m);
    for(int i=0;i<m;i++){
        set<int> :: iterator it = ans.upper_bound(brr[i].data);
        if(it == ans.begin()){
            brr[i].ans = -1;
        }else{
            it--;
            brr[i].ans = *it;
            ans2[*it]--;
            if(ans2[*it] == 0){
                ans.erase(*it);
            }
        }
    }
    int realpic[m];
    for(int i=0;i<m;i++){
        realpic[brr[i].index] = brr[i].ans;
    }
    for(int x : realpic){
        cout << x << '\n';
    }
    return 0;
}