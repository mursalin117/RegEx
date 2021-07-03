#include <bits/stdc++.h>
using namespace std;

void printMatches(string str, regex reg){
    smatch match;

    while(regex_search(str, match, reg)){
        cout << match.str(1) << endl;
        str = match.suffix().str();
    }
    cout << endl;
}

int main(){
    string str = "206-711-3001 212-712-3002 209-713-3003";
    regex reg("(([^(.{4})])(.{8}))");
    printMatches(str, reg);

    return 0;
}
