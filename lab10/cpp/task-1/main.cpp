#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> sources;
	vector<int> adj[kNmax];

	void read_input() {
		cin >> n >> m;

        for (int i = 0; i < n; i++) {
            sources.push_back(i);
        }

		for (int i = 1, x, y, z; i <= m; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}

	vector<int> get_result() {
		vector<int> d(n + 1, -1);
        d[source] = 0;

        list<int> queue;
        vector<int>::iterator i;
        int minDist = 1;
        queue.push_back(source);
        bool modifFlag;

        while (!queue.empty()) {
            int tempS = queue.front();
            queue.pop_front();


            for (i = adj[tempS].begin(); i != adj[tempS].end(); i++) {
                if (d[*i] == -1) {
                    d[*i] = minDist + d[tempS];
                    queue.push_back(*i);
                }
            }
        }

		return d;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << (i == n ? '\n' : ' ');
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
