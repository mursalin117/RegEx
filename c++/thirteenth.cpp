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
    string str = "12345 12345-1234 1234 12346-333";
    regex reg("(\\d{5}-\\d{4}|\\d{5}\\s)"); // first 5 digit or, 5-4 digit
    printMatches(str, reg);


    string str2 = "14125551212 4125551212 "
        "(412)5551212 412 555 1212 412-555-1212 "
        "1-412-555-1212";

    regex reg2("((1?)(-| ?)(\\()?(\\d{3})(\\)|-| |\\)-|\\) )?(\\d{3})(-| )?(\\d{4}))");
    printMatches(str2, reg2);
    regex reg3("((\\d?)(-| |\\()?(\\d{3})(\\)|-| )?(\\d{3})( |-)?(\\d{4}))");
    printMatches(str2, reg3);

    return 0;
}
