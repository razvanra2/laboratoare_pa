#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define NEGINF -100000
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, S;
	vector<int> v;

	void read_input() {
		ifstream fin("in");
		fin >> n >> S;
		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}

    static bool rule(int a, int b) {
        return a > b;
    }

	int get_result() {
        vector<int>dp(S + 1, 0);

        for (int j = 1; j <= S; j++) {
            int min = NEGINF;

            for (int i = 1; i <= n; i++) {
                if (j - v[i] >= 0 && dp[j - v[i]] != -1) {
                    min = dp[j - v[i]];
                }
            }

            if(min == NEGINF) {
                dp[j] = -1;
            } else {
                dp[j] = min + 1;
            }
        }

		return dp[S];
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
