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
    regex reg(".{3}-(.{8})");
    printMatches(str, reg);

    string str2 = "My number is 904-703-9009";
//    regex reg2("(.{3}-.{8})"); // showing the telephone no
    regex reg2("(.{3})-(.*)-(.*)");
//    printMatches(str2, reg2);
    smatch match;
    if(regex_search(str2, match, reg2)){
        for(int i = 1; i < match.size(); i++){
            cout << match.str(i) << endl;
        }
    }
    return 0;
}
