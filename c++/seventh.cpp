#include <bits/stdc++.h>

using namespace std;

//void printMatches2(string str, regex reg){
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

// Everything
// []      : Match what is in the brackets
// [^ ]    : Match anything not in the brackets
// .       : Match any 1 character or space
// +       : Match 1 or more what proceeds
// \n      : Newline
// \d      : Any 1 number
// \D      : Anything but a number
// \w      : Same as [a-zA-Z0-9_]
// \W      : Same as [^a-zA-Z0-9_]
// \s      : Same as [\f\n\r\t\v]
// \S      : Same as [^\f\n\r\t\v]
// {5}     : Match 5 of what proceeds the curly brackets
// {5,7}   : Match values that are between 5 and 7 in length
// ()      : Return only what is between ()


int main(){
    string str1 = "cat cats catcat catcats atc";
    regex reg1("((cat)+s?)");
//    regex reg1("([cat]+s?)");
//    regex reg1("(\\b(cats?)\\b)");
    printMatches(str1, reg1);
//    regex reg2("(^(cat)$)");
//    printMatches2(str1, reg2);

    string str2 = "doctor doctors doctor's";
    regex reg2("((doctor)+['s]*)");
//    regex reg2("((doctor)+['s]{0,2})");
//    regex reg2("([doctor]+['s]*)");
    printMatches(str2, reg2);

    string str3 = "Just some words\n"
                    "and some more\r\n"
                    "and more\n";
    cout << str3 << endl;
    regex reg3("[\r]?\n");
    string line = regex_replace(str3, reg3, " ");
    cout << line << endl;

    return 0;
}
