#include <bits/stdc++.h>
#include <regex>

using namespace std;

void printMatches(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str. end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        currentMatch++;
    }
    cout << endl;
}

int main(){
    string str = "Cat rat mat fat pat";
    regex reg("([crmfp]at)");
    printMatches(str, reg);

    regex reg1("([C-Fc-f]at)");
    printMatches(str, reg1);

    regex reg2("([^Cr]at)");
    printMatches(str, reg2);

    return 0;
}

