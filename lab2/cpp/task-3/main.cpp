#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Homework {
	int deadline;
	int score;

	Homework(int _deadline, int _score) : deadline(_deadline), score(_score) {}
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<Homework> hws;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		for (int i = 0, deadline, score; i < n; i++) {
			fin >> deadline >> score;
			hws.push_back(Homework(deadline, score));
		}
		fin.close();
	}

	static bool rule(Homework a, Homework b) {
		if (a.score > b.score) {
			return true;
		}
		if (a.score < b.score) {
			return false;
		}

		if (a.score == b.score) {
			if (a.deadline < b.deadline) {
				return true;
			}
		}

		return false;
	}

	int get_result() {
		int totalScore = 0;
		int maxDeadline = 0;

		for (int i = 0; i < n; i++) {
			if (hws[i].deadline > maxDeadline) {
				maxDeadline = hws[i].deadline;
			}
		}

		sort(hws.begin(), hws.end(), rule);

		int semester[100] = {0};
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (semester[hws[i].deadline] == 0) {
				semester[hws[i].deadline] = hws[i].score;
			} else {
				for (int j = hws[i].deadline - 1; j > 0; j++) {
					if (semester[j] == 0) {
						semester[j] = hws[i].score;
						break;
					}
				}
			}
		}

		for (int i = 1; i <= maxDeadline; i++) {
			totalScore += semester[i];
		}

		return totalScore;
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
