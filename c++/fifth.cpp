#include <bits/stdc++.h>
#include <iostream>
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

int main(){
    string str = "F.B.I. I.R.S. CIA";
    regex reg("([^ ]\\..\\..\\.)"); // anything without CIA
    printMatches(str, reg);

    string str2 = "This is a\n multiline string\nthat has many lines";
    cout << str2 << endl;
    regex reg2("\n");
    string noLBStr = regex_replace(str2, reg2, " ");
    cout << noLBStr << endl;

//    You can also replace
//    \b : Backspace
//    \f : Form Feed
//    \r : Carriage Retrun
//    \t : Tab
//    \v : Vertical Tab

    // for a single number
    // \d -> [0-9]
    // \D -> [^0-9]
    string str3 = "12345";
    regex reg3("\\d"); // one digit
    printMatches(str3, reg3);

    string str4 = "123 1234 12345 123456 1234567";
    regex reg4("\\d{5,7}"); // stiring with 5 to 7 length long
    printMatches(str4, reg4);

    // \w -> [a-zA-Z0-9]
    // \W -> [^a-zA-Z)-9]
    string str5 = "418-325-7856";
    regex reg5("\\w{3}-\\w{3}-\\w{4}"); // telephone no match
    printMatches(str5, reg5);

    // \s -> [\f\n\r\t\v]
    // \S -> [^\f\n\r\t\v]
    string str6 = "Toshiro Muramatsu";
    regex reg6("\\w{2,20}\\s\\w{2,20}"); // name matching
    printMatches(str6, reg6);

    string str7 = "a as ape bug";
    regex reg7("a[a-z]+"); // starting 'a' with more than two character
    printMatches(str7, reg7);

    return 0;
}
