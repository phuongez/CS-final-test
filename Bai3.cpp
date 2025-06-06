#include <iostream>
#include <string>
using namespace std;

string encodeString(const string& s) {
    string result = "";
    int i = 0;

    while (i < s.length()) {
        char currentChar = s[i];
        int count = 0;


        while (i < s.length() && s[i] == currentChar) {
            count++;
            i++;
        }


        result += currentChar;
        result += to_string(count);
    }

    return result;
}

int main() {

    cout << encodeString("aabbbaaac") << endl;  
    cout << encodeString("ab") << endl;   
    cout << encodeString("aaddacc") << endl;    

    return 0;
}
