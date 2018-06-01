#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

	vector<vector<int> > get_result() {
		vector<vector<int> > all;
        vector<int> domain(n);
        for (int i = 0; i < n; i++) {
            domain[i] = i +1;
        }

        vector<int> solution;
        unordered_set<int> visited;

        back(0, n, all, solution, domain, visited);

		return all;
	}

    void back(int step, int stop, vector< vector <int> >& all, vector<int>& sol,
        vector<int>& domain, unordered_set<int>& visited) {
        if (sol.size() > 0)
            all.push_back(sol);

        if (step == stop) {
            return;
        }



        for (int i = 0; i < n; i++) {
            if (visited.find(domain[i]) == visited.end()) {
                if (sol.size() == 0) {
                    sol.push_back(domain[i]);
                    visited.insert(domain[i]);

                    back(step + 1, stop, all, sol, domain, visited);

                    sol.pop_back();
                    visited.erase(domain[i]);
                } else {
                    if (domain[i] > sol[sol.size() - 1]) {

                        sol.push_back(domain[i]);
                        visited.insert(domain[i]);

                        back(step + 1, stop, all, sol, domain, visited);

                        sol.pop_back();
                        visited.erase(domain[i]);
                    }
                }
            }
        }
    }

	void print_output(vector<vector<int> > result) {
		ofstream fout("out");
		fout << result.size() + 1<< '\n';
		for (int i = 0; i < (int)result.size(); i++) {
			for (int j = 0; j < (int)result[i].size(); j++) {
				fout << result[i][j] <<
					(j + 1 != result[i].size() ? ' ' : '\n');
			}
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
