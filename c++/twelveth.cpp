#include <bits/stdc++.h>
using namespace std;

void printMatches(string str, regex reg){
    // used when you're searching a string
    smatch matches;

    // Determines if there is a match and match results are returned in 'matches'
    while(regex_search(str, matches, reg)){

        // get the first match
        cout << matches.str(1) << endl;

        // Eliminate the previous match and create a new string to search
        str = matches.suffix().str();
    }
    cout << endl;
}

int main(){
    // or condition
    string str = "1. Dog 2. Cat 3. Monkey";
    regex reg("\\d\\.\\s(Dog|Cat)");
    printMatches(str, reg);

    return 0;
}
