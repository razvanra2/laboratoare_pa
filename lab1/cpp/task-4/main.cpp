#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(fast_pow(base, exponent, mod));
	}

private:
	int base, exponent, mod;

	void read_input() {
		ifstream fin("in");
		fin >> base >> exponent >> mod;
		fin.close();
	}

	int fast_pow(int base, int exponent, int mod) {
		int aux = 1;

		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
			return base % mod;
		}

		if (base == 0) {
			return 0;
		}

		if (base == 1) {
			return 1;
		}
		if (exponent % 2 == 0 ) {
			aux = fast_pow(base, exponent / 2, mod) % mod;
			return (1LL * aux * aux) % mod;
		} else {  // exponent % 2  == 1
			aux = fast_pow(base, exponent - 1, mod);
			return (1LL * base * aux ) % mod;
		}

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
