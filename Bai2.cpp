#include <iostream>
#include <string>
using namespace std;

//  Kí tự tiếp theo
char nextChar(char c) {
    return (c == 'z') ? 'a' : (c + 1);
}

// Hàm sinh chuỗi và trả về ký tự thứ k
char getKthCharacter(char startChar, int k) {
    string word(1, startChar); // bắt đầu với startChar
    while ((int)word.length() < k) {
        string next = "";
        for (char c : word) {
            next += nextChar(c);
        }
        word += next;
    }
    return word[k - 1];
}

int main() {
    char startChar;
    int k;

    cout << "Nhập ký tự bắt đầu (a-z): ";
    cin >> startChar;

    cout << "Nhập giá trị k: ";
    cin >> k;

    char result = getKthCharacter(startChar, k);
    cout << "Ký tự thứ " << k << " trong chuỗi là: " << result << endl;

    return 0;
}
