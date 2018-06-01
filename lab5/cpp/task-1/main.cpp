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
	int n, k;

	void read_input() {
		ifstream fin("in");
		fin >> n >> k;
		fin.close();
	}

	vector<vector<int> > get_result() {
		vector<vector<int> > all;
        vector<int> solution(k);
        vector<int> domain(n + 1);
        unordered_set<int> visited;

        for (int i = 0; i <= n; i++) {
            domain[i] = i;
        }

        back(0, k, all, solution, domain, visited);

		return all;
	}

    void back(int step, int stop, vector<vector <int> >& all, vector<int>& sol,
    vector<int>& domain, unordered_set<int>& visited) {

        if (step == stop) {
            all.push_back(sol);
            return;
        }


        for (int i = 1; i <= n; i++) {
            if (visited.find(domain[i]) == visited.end()) {
                sol[step] = domain[i];
                visited.insert(domain[i]);

                back(step + 1, stop, all, sol, domain, visited);

                visited.erase(domain[i]);
            }
        }
    }

	void print_output(vector<vector<int> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
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
