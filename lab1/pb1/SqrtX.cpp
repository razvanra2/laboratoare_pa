#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

double sqrtX(double x, double left, double right) {
    if (x == 0) {
        return 0;
    } else {
        if (left <= right) {
            float mid = (left + right) / 2;
            if (abs(x - mid * mid) < 0.001) {
                return mid;
            } else {
                if (mid * mid < x) {
                    return sqrtX(x, mid, right);
                } else {
                    return sqrtX(x, left, mid);
                }
            }
        }
    }

    return -1;
}

int main() {
	freopen("date.in",  "r", stdin);
    freopen("date.out", "w", stdout);

    double nr;
    cin >> nr;
    cout << sqrtX(nr, 0, nr);

    return 0;
}
