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

// Everything
// []      : Match what is in the brackets
// [^ ]    : Match anything not in the brackets
// ()      : Return surrounded submatch
// .       : Match any 1 character or space
// +       : Match 1 or more what proceeds
// ?       : Match 0 or 1
// *       : Match 0 or more
// *?      : Lazy Match the smallest match
// \b      : Word boundary
// ^       : Beginning of string
// $       : End of string
// \n      : Newline
// \d      : Any 1 number
// \D      : Anything but a number
// \w      : Same as [a-zA-Z0-9_]
// \W      : Same as [^a-zA-Z0-9_]
// \s      : Same as [\f\n\r\t\v]
// \S      : Same as [^\f\n\r\t\v]
// {5}     : Match 5 of what proceeds the curly brackets
// {5,7}   : Match values that are between 5 and 7 in length


int main(){
    // back references
    string str = "The cat cat fell out the window";
    regex reg("(\\b\\w+)\\s+\\1");
    printMatches(str, reg);

    // back reference substitution
    string str2 = "<a href='#'><b>The Link</b></a>";
    regex reg2("<b>(.*?)</b>");

    string result;
    regex_replace(back_inserter(result), str2.begin(), str2.end(), reg2, "$1");
    cout << result << endl;

    // back reference substitution
    string str3 = "442-342-8096";
    regex reg3("([\\d]{3})(-[\\d]{3}-[\\d]{4})");

    string result2;
    regex_replace(back_inserter(result2), str3.begin(), str3.end(), reg3, "($1)$2");
    cout << result2 << endl;

    // back reference substitution
    string str4 = "https://www.youtube.com "
        "http://www.google.com";
    regex reg4("(https?://([\\w.]+))");

    string result3;
    regex_replace(back_inserter(result3), str4.begin(), str4.end(), reg4,
    "<a herf='$1'>$2</a>\n");
    cout << result3 << endl;

    return 0;
}
