#include <bits/stdc++.h>
#include <regex>

using namespace std;

void printMatches(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        currentMatch++;
    }
    cout << endl;
}

//            Problem
//    match email address
//    list
//    1. 1-20 uppercase and lowercase letter, number, plus ._%+-
//    2. an @ symbol
//    3. 2-20 lowercase and uppercase letter, number, plus .-
//    4. a period
//    5. 2-3 lowercase and uppercase letter

int main(){


    string str = "abc@ru.ac.bd, db@aol.com, m@.com, @apple.com, db@.com";
    regex reg("[a-zA-z][\\w._%+-]{1,19}@[\\w.-]{2,20}.[\\w]{2,3}");
    printMatches(str, reg);

    return 0;
}
