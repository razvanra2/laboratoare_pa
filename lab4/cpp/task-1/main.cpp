#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int kMod = 1e9 + 7;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

    Task() {
        flag = false;
    }
 private:
	int n;
	vector<int> v;
    bool flag;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
            if (e % 2 == 1) {
                flag = true;
            }
			v.push_back(e);
		}
		fin.close();
	}

    // https://we.tl/EEf7HTp4P5 ;) da, e putere
    int putere(int nr, int pwr) {
        int result = nr % kMod;
        for (int i = 1; i < pwr; i++) {
            result = ((result % kMod) * (nr % kMod)) % kMod;
        }
        return result;
    }

	int get_result2() {
        if (flag == true) {
            if (n == 1) {
                return 0;
            } else {
                return (putere(2, n - 1) - 1);
            }
        }
        if (n == 1) {
            return 1;
        }
        return (putere(2,n) - 1);
	}
    int get_result() {
        // even =  numarul de subsiruri cu numere pare
        // odd = numarul de subsiruri cu numere impare
        int even = 0, odd = 0;
        // cazul de baza
        if (v[1] % 2 == 0) {
            even = 1;
        } else {
            odd = 1;
        }
        for (int i = 2; i <= n; i++) {
            if (v[i] % 2 == 0) {
                even = ((even % kMod) * 2) % kMod;
                even = ((even % kMod) + 1) % kMod;
                odd = ((odd % kMod) * 2) % kMod;
            } else {
                even = (even % kMod) + (odd % kMod);
                odd = ((even % kMod) + 1) % kMod;
            }
        }
        return even % kMod;
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
