#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(const vector<int>& price, int n, vector<int>& cutChoice) {
    vector<int> dp(n + 1, 0); 
    cutChoice.resize(n + 1, 0); 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (dp[i] < price[j - 1] + dp[i - j]) {
                dp[i] = price[j - 1] + dp[i - j];
                cutChoice[i] = j;
            }
        }
    }

    return dp[n];
}


vector<int> getCutSequence(const vector<int>& cutChoice, int n) {
    vector<int> cuts;
    while (n > 0) {
        int cut = cutChoice[n];
        cuts.push_back(cut);
        n -= cut;
    }
    return cuts;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    vector<int> cutChoice;
    int maxProfit = rodCutting(price, n, cutChoice);

    cout << "Tổng giá trị lớn nhất thu được: " << maxProfit << endl;

    vector<int> cuts = getCutSequence(cutChoice, n);
    cout << "Cách cắt thanh sắt: ";
    for (int cut : cuts) {
        cout << cut << " ";
    }
    cout << endl;

    return 0;
}
