#include <iostream>
using namespace std;
#define MAX(a,b) (a>b?a:b)
int main()
{
    string a;
    cin >> a;
    int maxe = 1;
    int j = 1;
    for(unsigned int i=1;i<a.size();i++){
        if(a[i] == a[i-1]){
            j++;
            maxe = max(j,maxe);
        }else{
            j = 1;
        }
    }
    cout << maxe << '\n';
    return 0;
}