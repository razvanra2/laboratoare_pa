#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
using namespace std;

const int kNmax = 50005;
#define oo (1 << 30)

#define NO_PARENT (-1)


class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	int source;
	vector<pair<int, int> > adj[kNmax];

    priority_queue<pair<int, int>, vector<pair<int, int>>,
               std::greater<pair<int, int>>>pq;

    vector<int> d;
    vector<int> p;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m >> source;
        d.resize(n + 1);
        p.resize(n + 1);

		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back({y, w});
		}
		fin.close();
	}

	vector<int> get_result() {
        for (int i = 1; i <= n; ++i) {
            d[i] = oo;
            p[i] = NO_PARENT;
        }

        p[source] = 0;
        d[source] = 0;

        pq.push({d[source], source});
        while (!pq.empty()) {
            auto entry = pq.top();
            pq.pop();
            int cost = entry.first;
            int node = entry.second;
            if (cost <= d[node]) {
                for (auto &edge : adj[node]) {
                    int neighbour = edge.first;
                    int cost_edge = edge.second;

                    if (d[node] + cost_edge < d[neighbour]) {
                        d[neighbour] = d[node] + cost_edge;
                        p[neighbour] = node;
                        pq.push({d[neighbour], neighbour});
                     }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (d[i] == oo) {
            d[i] = -1;
            }
        }

        return d;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << " ";
		}
		fout << "\n";
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
