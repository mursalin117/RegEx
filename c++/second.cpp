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
    string str = "I picked the pickle";
    regex reg("(pick([^ ]+)?)");

    printMatches(str, reg);

    return 0;
}
