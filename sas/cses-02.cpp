#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    #ifdef OFFLINE 
	    freopen("input.txt","r",stdin);
    #endif
    int n,m,k;
    cin >> n >> m >> k;
    int arr[n];
    int brr[m];
    for(int i=0;i<n;i++)
	  cin >>arr[i];
    for(int i=0;i<m;i++)
	  cin >>brr[i];
    sort(arr,arr+n);
    sort(brr,brr+m);
    int i = 0;
    int j = 0;
    int total = 0;
    while(i < n && j < m){
  	if(arr[i] <= brr[j]+k && arr[i] >= brr[j]-k){
  	    total++;
  	    i++;
  	    j++;
  	}else if(arr[i] > brr[j] + k){
  	    j++;
  	}else{
  	    i++;
  	}
      }
      cout <<total <<'\n';
    return 0;
}