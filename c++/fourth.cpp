#include <bits/stdc++.h>
#include <regex>

using namespace std;

//void printMatches(string str, regex reg){
//    sregex_iterator currentMatch(str.begin(), str.end(), reg);
//    sregex_iterator lastMatch;
//
//    while(currentMatch != lastMatch){
//        smatch match = *currentMatch;
//        cout << match.str() << endl;
//        currentMatch++;
//    }
//    cout << endl;
//}

int main(){
    string str = "Cat rat mat fat pat";
    regex reg("([Cr]at)");
    string owlfood = regex_replace(str, reg, "Owl");
    cout << owlfood << endl;

    return 0;
}
