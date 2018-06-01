#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(compute_sqrt());
	}

private:
	double n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

	double compute_sqrt() {
		if (n == 0) {
			return 0;
		} else {
			if (n > 0 && n < 1) {
				float left = 0;
				float right = 1;

				while (left <= right) {
					float mid = (left + right) / 2;

					if (fabs(n - mid * mid) <= 0.001) {
						return mid;
					} else {
						if (n - mid * mid < 0.001) {
							right = mid;
						} else {
							left = mid;
						}
					}
				}
			} else {
				float left = 1;
				float right = n / 2 + 1;

				while (left <= right) {
					float mid = (left + right) / 2;
					if (fabs(n - mid * mid) <= 0.001) {
						return mid;
					} else {
						if (n - mid * mid > 0.001) {
							left = mid;
						} else {
							right = mid;
						}
					}
				}
			}
		}
		/*
		TODO: Calculati sqrt(n) cu o precizie de 0.001
		Precizie de 10^-x = |rezultatul vostru - rezultatul corect| <= 10^-x
		*/
		return 0.0;
	}

	void print_output(double result) {
		ofstream fout("out");
		fout << setprecision(4) << fixed << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
