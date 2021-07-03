#include <bits/stdc++.h>
#include <regex>

using namespace std;

void printMatches(string str, regex reg){
    // store the matches
    smatch matches;
    // writing output in true/false
    cout << boolalpha;
    while(regex_search(str, matches, reg)){
        cout << "Is there a match: " << matches.ready() << endl;
        cout << "Are there no match: " << matches.empty() << endl;
        cout << "Number of matches: " << matches.size() << endl;
        cout << matches.str(1) << endl;
        // edit the new str for next search
        str = matches.suffix().str();
        cout << endl;
    }
}

int main(){
    string str = "The ape was at the apex";
    // writing regular expression
    regex reg("(ape[^ ]?)");
    printMatches(str, reg);

    return 0;
}

