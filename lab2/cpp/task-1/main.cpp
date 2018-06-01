#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Object {
	int weight;
	int price;

	Object(int _weight, int _price) : weight(_weight), price(_price) {}
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, w;
	vector<Object> objs;

	void read_input() {
		ifstream fin("in");
		fin >> n >> w;
		for (int i = 0, weight, price; i < n; i++) {
			fin >> weight >> price;
			objs.push_back(Object(weight, price));
		}
		fin.close();
	}

	static bool rule(Object a, Object b) {
		return (((double)a.price / (double)a.weight) > ((double)b.price / (double)b.weight));
	}

	double get_result() {
		sort(objs.begin(), objs.end(), rule);
		double weightAdded = 0.0;
		double stolenValue = 0.0;

		int cnt = 0;

		while(w - objs[cnt].weight > 0) {
			w -= objs[cnt].weight;
			stolenValue += objs[cnt].price;
			cnt++;
		}

		if (w > 0) {
			stolenValue += (((double) w / (double)objs[cnt].weight) * objs[cnt].price);
		}


		return stolenValue;
	}

	void print_output(double result) {
		ofstream fout("out");
		fout << setprecision(4) << fixed << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
