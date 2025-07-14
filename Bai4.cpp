#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int id;
    int start;
    int end;
};

bool compareByEnd(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    vector<Activity> activities = {
        {1, 1, 3},
        {2, 2, 5},
        {3, 4, 7},
        {4, 1, 8},
        {5, 5, 9},
        {6, 8, 10}
    };

    // Sắp xếp theo thời gian kết thúc tăng dần
    sort(activities.begin(), activities.end(), compareByEnd);

    cout << "Các hoạt động được chọn: ";

    int last_end = 0;
    for (const auto& act : activities) {
        if (act.start >= last_end) {
            cout << act.id << " ";
            last_end = act.end;
        }
    }

    cout << endl;
    return 0;
}
