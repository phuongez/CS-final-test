#include <iostream>
#include <vector>
using namespace std;

void findCombinations(const vector<int>& a, int k, vector<int>& current, int index) {
    if (k == 0) {
        cout << "[ ";
        for (int num : current)
            cout << num << " ";
        cout << "]" << endl;
        return;
    }

    for (int i = index; i < a.size(); ++i) {
        if (a[i] <= k) {
            current.push_back(a[i]);
            findCombinations(a, k - a[i], current, i);
            current.pop_back();
        }
    }
}

int main() {
    vector<int> a = {1, 2, 6, 8, 35, 9};
    int k = 10;
    vector<int> current;

    cout << "Tổ hợp các phần tử có tổng bằng " << k << " là:\n";
    findCombinations(a, k, current, 0);

    return 0;
}
