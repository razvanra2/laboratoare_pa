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

int firstAppearence(int x, vector<int> numbers, int left, int right) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if(numbers[mid] == x && (mid == 0 || x > numbers[mid - 1] )) {
            return mid;
        } else {
            if (numbers[mid] < x) {
                return firstAppearence(x, numbers, mid, right);
            } else {
                return firstAppearence(x, numbers, left, mid);
            }
        }
    }

    return -1;
}

int lastAppearence(int x, vector<int> numbers, int left, int right) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if(numbers[mid] == x && (mid == numbers.size() - 1 || x < numbers[mid + 1] )) {
            return mid;
        } else {
            if (numbers[mid] < x) {
                return lastAppearence(x, numbers, mid, right);
            } else {
                return lastAppearence(x, numbers, left, mid);
            }
        }
    }

    return -1;
}

int countXinVector(int x, vector<int> numbers) {

    int i = firstAppearence(x, numbers, 0, numbers.size() - 1);

    if (i == -1) {
        return i;
    }

    int j = lastAppearence(x, numbers, i, numbers.size() - 1);

    return j - i + 1;
}

int main() {
	freopen("data.in",  "r", stdin);
    freopen("data.out", "w", stdout);

    vector<int> numbers;
    int aux;

    int x;
    cin >> x;

    while (cin >> aux) {
            numbers.push_back(aux);
    }

    cout << countXinVector(x, numbers);

	return 0;
}
