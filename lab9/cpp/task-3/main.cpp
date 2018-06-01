#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#define oo (1 << 20)
using namespace std;

const int NMAX = 105;

class Task {
 public:
	void solve() {
		read_input();
		compute();
		print_output();
	}

 private:
	int n;
	int d[NMAX][NMAX], p[NMAX][NMAX];

    void read_input() {
      ifstream fin("in");
      fin >> n;

      for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
          int c;
          fin >> c;

          if (c == 0) {
            c = oo;
          }

          d[x][y] = c;
          p[x][y] = x;
        }
      }
      fin.close();
    }

	void compute() {
        //Roy-Floyd
        for (int k = 1; k <= n; ++k) {
          for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
              if (i != j && d[i][k] + d[k][j] < d[i][j]) {
                d[i][j] = d[i][k] + d[k][j];
                p[i][j] = p[k][j];
              }
            }
          }
        }

        for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
                if (d[i][j] == oo) {
                    d[i][j] = 0; // ;)
                }
			}
		}
	}

	void print_output() {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fout << d[i][j] << ' ';
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
