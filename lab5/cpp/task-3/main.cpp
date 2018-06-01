// Copyright 2018 Razvan Radoi, first of his name, king of the
// off by one errors, the bugs and the initial commits,
// protector of the code
#include <fstream>
#include <vector>
#include <algorithm>
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

	vector<int> get_result() {
		vector<int> sol(n + 1, 0);
        vector<int> current(n + 1, 0);
		/*
		TODO: Gasiti o solutie pentru problema damelor pe o tabla de dimensiune
		n x n.

		Pentru a plasa o dama pe randul i, coloana j:
			sol[i] = j.
		Randurile si coloanele se indexeaza de la 1 la n.

		De exemplu, configuratia (n = 5)
		X----
		--X--
		----X
		-X---
		---X-
		se va reprezenta prin sol[1..5] = {1, 3, 5, 2, 4}.
		*/

        rege(1, sol, current);
		return sol;
	}

    bool check(int poz, int step, vector<int>& curr) {
        for (int i = 1; i < step; i++) {
            if (curr[i] == poz) {
                return false;
            }

            if (step + poz == i + curr[i] || step - poz == i - curr[i]) {
                return false;
            }
        }
        return true;
    }
    /* cel care decide unde stau reginele nu poate fi decat rege */
    void rege(int step, vector<int>& sol, vector<int>& curr /* ;) */) {
        if (step == n) {
            sol = curr;
            return;
        }
        if (step == 1) {
            curr.push_back(1);
            rege(step + 1, sol, curr);
            curr.pop_back();
        } else {
            
            for (int i  = 1; i <= step; i++) {
                if (check(i, step, curr) == true) {
                    curr.push_back(i);

                    rege(step + 1, sol, curr);

                    curr.pop_back();
                }
            }
        }
    }

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << (i != n ? ' ' : '\n');
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
