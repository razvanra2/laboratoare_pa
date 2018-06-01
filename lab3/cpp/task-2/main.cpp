#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Result {
	int len;
	vector<int> subsequence;
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, m;
	vector<int> v;
	vector<int> w;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;

		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}

		w.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= m; i++) {
			fin >> e;
			w.push_back(e);
		}

		fin.close();
	}

	Result get_result() {
		Result result;
		result.len = 0;
		vector<vector<int> > dp(1000, vector<int>(1000));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (v[i] == w[j]) {  // hop, Germania
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		while (n > 0 && m > 0) {
			if (v[n] == w[m]) {
				result.len++;
				result.subsequence.push_back(v[n]);
				n--;
				m--;
			} else {
				if (dp[n][m - 1] > dp[m - 1][n]) {
					m--;
				} else {
					n--;
				}
			}
		}

		sort(result.subsequence.begin(), result.subsequence.end());
		return result;
	}

	void print_output(Result result) {
		ofstream fout("out");
		fout << result.len << '\n';
		for (int x : result.subsequence) {
			fout << x << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
