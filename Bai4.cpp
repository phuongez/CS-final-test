#include <iostream>
using namespace std;

const int MAX = 1000; 

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0) return false;
    return true;
}

void superPrimeNumber(int n) {
    int basePrimes[] = {2, 3, 5, 7};
    int result[MAX];    
    int resultSize = 0;

    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < 4; ++i) {
        if (basePrimes[i] <= n) {
            queue[rear++] = basePrimes[i];
            result[resultSize++] = basePrimes[i];
        }
    }

    while (front < rear) {
        int current = queue[front++];
        for (int digit = 0; digit <= 9; ++digit) {
            int next = current * 10 + digit;
            if (next <= n && isPrime(next)) {
                queue[rear++] = next;
                result[resultSize++] = next;
            }
        }
    }

    for (int i = 0; i < resultSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 30;
    superPrimeNumber(n);
    return 0;
}
