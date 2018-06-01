// Copyright 2018 Razvan Rado... hai sa fim seriosi
// Copyright 2018 Darius Neatu

#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
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
	vector<int> adj[kNmax];
	vector<int> adjt[kNmax];
    vector<int> visited;
    vector<int> topsort;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
        visited = vector<int>(n + 1, 0);

		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adjt[y].push_back(x);
		}
		fin.close();
	}
    // ai observat ca "kosaraju" suna ca ceva ce zice Naruto inainte sa faca
    // un jutsu din ala nebun?
    void kosaraju(vector<vector<int> >& sol) {

        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        for (int i = n; i >= 1; i--) {
            if (visited[topsort[i]]) {
                vector<int> current_ctc;
                dfs_t(topsort[i], current_ctc);
                sol.push_back(current_ctc);
            }
        }
    }

    void dfs(int node) {
        visited[node] = 1;

        for (auto &vecin : adj[node]) {
            if (!visited[vecin]) {
                dfs(vecin);
            }
        }

        // adaug nodul la sortarea topologica
        topsort.push_back(node);
    }

    void dfs_t(int node, vector<int>& current_ctc) {
        visited[node] = 0;
        current_ctc.push_back(node);

        for (auto &vecin : adjt[node]) {
            if (visited[vecin]) {
                dfs_t(vecin, current_ctc);
            }
        }
    }

	vector<vector<int>> get_result() {
		/*
		TODO: Gasiti componentele tare conexe ale grafului orientat cu
		n noduri, stocat in adj. Rezultatul se va returna sub forma
		unui vector, ale carui elemente sunt componentele tare conexe
		detectate. Nodurile si componentele tare conexe pot fi puse in orice
		ordine in vector.

		Atentie: graful transpus este stocat in adjt.
		*/
		vector<vector<int>> sol;
        kosaraju(sol);
		return sol;
	}

	void print_output(vector<vector<int>> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (const auto& ctc : result) {
			for (int nod : ctc) {
				fout << nod << ' ';
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
