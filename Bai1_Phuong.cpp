#include <iostream>
using namespace std;

int tongUoc(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i)
                sum += i;
            else
                sum += i + n / i;
        }
    }
    return sum;
}

int main() {
    int T;
    cin >> T;

    int* arr = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < T; i++) {
        cout << tongUoc(arr[i]) << endl;
    }

    delete[] arr;
    return 0;
}
