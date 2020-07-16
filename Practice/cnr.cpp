#include <iostream>
#include <unistd.h>
using namespace std;
int main(int n,char ** args)
{
    string compile;
    string act;
    if(n == 1){
        act = "g++ -std=c++1z main.cpp && ./a.out";
    }else if(n == 2){
        compile = args[1];
        act = "g++ -std=c++1z ";
        act = act + compile;
        act = act + string(" && ./a.out");
    }else{
        compile = args[1];
        act = "g++ -std=c++1z ";
        act = act + compile;
        act = act + string(" && ./a.out");
        bool online = false;
        string oj = args[2];
        if(oj == "oj")
            online = true;
        if(online){
            act = act + string(" -onlinejudge");
        }
    }
    
    char* tocompile = &act[0];
    cout << tocompile << '\n';
    system(tocompile);
    return 0;
}
