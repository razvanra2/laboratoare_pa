#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(get_result(n, x, y));
	}

private:
	int n, x, y;

	void read_input() {
		ifstream fin("in");
		fin >> n >> x >> y;
		fin.close();
	}

	int get_result(int n, int x, int y) {
		if (n == 0) {
			return 1;
		}

		if ( x <= n / 2) {
			if (y <= n / 2) {
				return get_result(n - 1, x, y);
			} else { // y > n / 2
				return pow(2, n) + get_result(n - 1, x, y - pow(2, n / 2));
			}
		} else { // x > n / 2
			if ( y <= n / 2) {
				return 2 * pow(2, n) + get_result(n - 1, x - pow(2, n / 2), y);
			} else { // y > n / 2
				return 3 * pow(2, n) + get_result(n - 1, x - pow(2, n / 2) , y - pow(2, n / 2));
			}
		}

		return 0;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
