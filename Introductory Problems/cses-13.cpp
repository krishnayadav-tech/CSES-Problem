#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set<string> ans;
void permutation(int i,string& abc,int s)
{
    if(i == s){
        ans.insert(abc);
        return;
    }
    for(int j=i;j<abc.size();j++){
        swap(abc[i],abc[j]);
        permutation(i+1,abc,s);
        swap(abc[i],abc[j]);
    }
}
int main()
{
    string a;
    cin >> a;
    sort(a.begin(),a.end());
    string cur = "";
    permutation(0,a,a.size()-1);
    cout << ans.size() << '\n';
    for(auto x : ans){
        cout <<  x << '\n';
    }
    return 0;
}