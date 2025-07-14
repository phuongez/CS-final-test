#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


vector<int> get_difference(const vector<int>& seq) {
    vector<int> diff;
    for (size_t i = 1; i < seq.size(); ++i)
        diff.push_back(seq[i] - seq[i - 1]);
    return diff;
}


int detect_polynomial_degree(const vector<int>& seq) {
    vector<int> current = seq;
    int degree = 0;
    while (current.size() > 1) {
        vector<int> next = get_difference(current);
        bool all_equal = true;
        for (size_t i = 1; i < next.size(); ++i) {
            if (next[i] != next[0]) {
                all_equal = false;
                break;
            }
        }
        degree++;
        if (all_equal) return degree;
        current = next;
    }
    return -1; 
}


bool try_exponential_plus_constant(const vector<int>& f, double& a, double& b) {
    int n1 = 0, n2 = 1;
    double x1 = pow(2, n1), x2 = pow(2, n2);
    double y1 = f[n1], y2 = f[n2];

    a = (y2 - y1) / (x2 - x1);
    b = y1 - a * x1;

    for (int n = 0; n < (int)f.size(); ++n) {
        double expected = a * pow(2, n) + b;
        if (abs(expected - f[n]) > 1e-6)
            return false;
    }
    return true;
}

int main() {
    vector<int> f = {1, 4, 10, 22, 46, 94, 190, 382};

    // 1. Thử kiểm tra dạng a*2^n + b
    double a, b;
    if (try_exponential_plus_constant(f, a, b)) {
        cout << fixed << setprecision(3);
        cout << "Công thức tìm được: f(n) = " << a << " * 2^n";
        if (b >= 0) cout << " + " << b;
        else cout << " - " << abs(b);
        cout << endl;
        return 0;
    }

    // 2. Kiểm tra đa thức bằng bảng sai phân
    int degree = detect_polynomial_degree(f);
    if (degree != -1) {
        cout << "f(n) là đa thức bậc " << degree  << endl;
    } else {
        cout << "Không tìm được công thức đơn giản từ sai phân hoặc mũ." << endl;
    }

    return 0;
}

