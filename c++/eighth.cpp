#include <bits/stdc++.h>
using namespace std;

void printMatches(string str, regex reg){
    smatch matches;

    while(regex_search(str, matches, reg)){

        cout << matches.str(1) << endl;
        str = matches.suffix().str();
    }
    cout << endl;
}

int main(){
    string str = "<name>Life On Mars</name>"
        "<name>Freaks and Geeks</name>";
    // regex reg("<name>(.*)</name>"); // search the longest match
    regex reg("<name>(.*?)</name>"); // sarch the shortest match
    // can be written as +?, *?, {n,}?
    printMatches(str, reg);

    // word boundary ->  use \\b...\\b
    string str2 = "ape at the apex";
//    regex reg2("(ape)"); // finds both the ape and 'ape'x
    regex reg2("(\\bape\\b)");
    printMatches(str2, reg2);

    // string boundary
    string str3 = "Match everything up to @";
//    regex reg3("(.*[^@])");
    regex reg3("(^.*[^@])");
    printMatches(str3, reg3);

    string str4 = "@ Get this string";
//    regex reg4("([^@\\s].*)");
    regex reg4("([^@\\s].*$)");
    printMatches(str4, reg4);

    return 0;
}
