#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}
    Task() {
        ansLen = 0;
    }

 private:
	int n, k;
	string caractere;
	vector<int> freq;
    int ansLen;

	void read_input() {
		ifstream fin("in");
		fin >> n >> k;
		fin >> caractere;
		caractere = " " + caractere; // Adaugare element fictiv -
									 // indexare de la 1.
		freq.push_back(-1); // Adaugare element fictiv - indexare de la 1.
		for (int i = 1, f; i <= n; i++) {
			fin >> f;
            ansLen += f;
			freq.push_back(f);
		}
		fin.close();
	}

	vector<vector<char> > get_result() {
		vector<vector<char> > all;
        vector<char> sol(ansLen);
        vector<int> used(n + 1, 0);

        back(0, ansLen, sol, used, all);

        return all;
	}

    bool check(vector<char> sol, int start, char c) {
        int counter = 0;
        // n-ai idee cate ore am stat pana mi-am dat seamea
        // ca e start - 1 aici
        // ca eu puneam start
        // mi-e rusine cu mine insumi
        // jur
        for (int i = start - 1; i >= 0; i--) {
            if (sol[i] == c) {
                counter++;
            } else {
                break;
            }
        }

        if (counter <= k - 1) {
            return true;
        }

        return false;
    }

    void back(int step, int ansLen, vector<char>& sol, vector<int>& used,
    vector<vector <char> >& all) {

        if (step == ansLen) {
            all.push_back(sol);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i] < freq[i]) {
                if (check(sol, step, caractere[i]) == true) {
                    sol[step] = caractere[i];
                    used[i] = used[i] + 1;

                    back(step + 1, ansLen, sol, used, all);

                    used[i] = used[i] - 1;
                }
            }
        }
    }

	void print_output(vector<vector<char> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < (int)result.size(); i++) {
			for (int j = 0; j < (int)result[i].size(); j++) {
				fout << result[i][j];
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
