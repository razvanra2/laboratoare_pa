#include <bits/stdc++.h>

#define kNmax 50010
#define oo (1 << 30)
#define NO_PARENT (-1)

using namespace std;

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

    queue<int> q;

    vector<int> d;

    vector<int> p;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m >> source;
        d.resize(n + 1);

        p.resize(n + 1);
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
		}
		fin.close();
	}

	vector<int> get_result() {
        if (BellmanFord()) {
            vector<int> emptyVector;
            return emptyVector;
        }

        return d;
	}

    bool BellmanFord() {
       vector<int> usedNdsCnt(n + 1, 0);
       d = vector<int>(n + 1, oo);
       p = vector<int>(n + 1, NO_PARENT);

       p[source] = 0;
       d[source] = 0;

       q.push(source);

       while (!q.empty()) {
           int node = q.front();
           q.pop();

           usedNdsCnt[node]++;
           if (usedNdsCnt[node] == n) {
               return true;
           }
           for (auto &edge : adj[node]) {
               if (d[edge.first] >= d[node] + edge.second) {
                   p[edge.first] = node;
                   d[edge.first] = d[node] + edge.second;
                   q.push(edge.first);
               }
           }
       }

       return false;
     }

	void print_output(vector<int> result) {
		ofstream fout("out");
		if (result.size() == 0) {
			fout << "Ciclu negativ!\n";
		} else {
			for (int i = 1; i <= n; i++) {
				fout << result[i] << ' ';
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
