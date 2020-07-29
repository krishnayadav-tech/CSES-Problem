#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef OFFLINE 
        freopen("input.txt","r",stdin);
    #endif
    int n,pow;
    cin >> n >> pow;
    set<int> ans;
    map<int,int> ans2;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        ans.insert(temp);
        ans2[temp]++;
    }
    int cap = pow;
    int total = 1;
    int count = 0;
    while(ans.size() > 0){
        if(count == 2)
        {
            cap = pow;
            total++;
            count = 0;
        }
        set<int> :: iterator  temp = ans.upper_bound(cap);
        if(temp == ans.begin()){
            total++;
            cap = pow;
            count = 0;
        }else{
            temp--;
            count++;
            cap = cap - (*temp);
            ans2[*temp]--;
            if(ans2[*temp] == 0)
                ans.erase(*temp);
        }
    }
    if(cap == pow)
        cout << total  - 1 << endl;
    else
        cout << total << '\n';
    return 0;
}