#include <fstream>
#include <vector>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, m;
	vector<int> dist;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 0, d; i < n; i++) {
			fin >> d;
			dist.push_back(d);
		}
		fin.close();
	}

	int get_result() {
        int stopsCnt = 0;
        int fullTank = m;

        for (int i = 0; i < n - 1; i++) {
            if (i != 0) {
                m = m - (dist[i] - dist[i - 1]);
            } else {
                m -= dist[i];
            }

            if (dist[i + 1] - dist[i] > m) {
                stopsCnt++;
                m = fullTank;
            }

        }

		return stopsCnt;
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
