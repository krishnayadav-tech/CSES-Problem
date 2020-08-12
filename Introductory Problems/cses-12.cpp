#include <iostream>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int arr[26] = {0};
    for(int i=0;i<a.size();i++){
        arr[a[i]-'A']++;
    }
    int oddc = 0;
    for(int i=0;i<26;i++){
        if(arr[i] % 2 != 0){
            oddc++;
        }
    }
    if(a.size() % 2 == 0 and oddc > 0){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }else if(a.size() % 2 == 1 and oddc > 1){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    char odde;
    if(a.size() % 2 != 0){
        for(int i=0;i<26;i++){
            if(arr[i] % 2 != 0){
                odde = i + 'A';
            }
        }
    }
    int i,j;
    i = 0;
    j = a.size() - 1;
    char arr2[a.size()];
    if(a.size() % 2 == 0){
        for(int k=0;k<26;k++){
            int x = arr[k];
            bool turn = true;
            while(x){
                if(turn)
                {
                    arr2[i] = k + 'A';
                    i++;
                }
                else
                {
                    arr2[j] = k + 'A';
                    j--;
                }
                turn = !turn;
                x--;
            }
        }
    }else{
        for(int k=0;k<26;k++){
            int x = arr[k];
            if(x % 2 != 0){
                x = x - 1;
            }
            bool turn = true;
            while(x){
                if(turn)
                {
                    arr2[i] = k + 'A';
                    i++;
                }
                else
                {
                    arr2[j] = k + 'A';
                    j--;
                }
                x--;
                turn = !turn;
            }
        }
        arr2[a.size()/2] = odde;
    }
    for(int i=0;i<a.size();i++){
        cout << arr2[i];
    }
    cout << '\n';
    return 0;
}