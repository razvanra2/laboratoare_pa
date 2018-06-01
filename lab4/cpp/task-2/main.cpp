#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int kMod = 1e9 + 7;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	string expr;
	std::unordered_map<int, int> dp_true, dp_false;

	void read_input() {
		ifstream fin("in");
		fin >> n >> expr;
		expr = " " + expr; // adaugare caracter fictiv - indexare de la 1
		fin.close();
	}

		int trueValue(int i, int j, string operands, string operators) {
        int result = 0;
        // pe diagonala, frumos
		if (i == j) {
			return (operands[i] == 'T');
		} else {
    		for (int k = i; k < j; k++) {
    			if (operators[k] == '&') {
                    // stg si dreapta true
    				result = (((trueValue(i, k, operands, operators) * trueValue(k + 1, j, operands, operators)) % kMod) + result) % kMod;
    			}
                if (operators[k] == '|') {
                    // stg true si dreapta false, invers si amble true
    				result = (((trueValue(i, k, operands, operators) * falseValue(k + 1, j, operands, operators)) % kMod +
    					(falseValue(i, k, operands, operators) * trueValue(k + 1, j, operands, operators)) % kMod +
    					(trueValue(i, k, operands, operators) * trueValue(k + 1, j, operands, operators)) % kMod) + result) % kMod;
    			}
                if (operators[k] == '^') {
                    // F si T sau T si F
                    result = (((trueValue(i, k, operands, operators) * falseValue(k + 1, j, operands, operators)) % kMod +
                    (falseValue(i, k, operands, operators) * trueValue(k + 1, j, operands, operators)) % kMod) + result) % kMod;
                }
    		}

    		dp_true[i * n + j] = result;
        }
		return result;
	}

    int falseValue(int i, int j, string operands, string operators) {
        int result = 0;
            if (i == j) {
                return (operands[i] == 'F');
            } else {
                for (int k = i; k < j; k++) {
                    if (operators[k] == '&') {
                        // T si F, F si T
                        result = (((trueValue(i, k, operands, operators)  * falseValue(k + 1, j, operands, operators)) % kMod +
                            (falseValue(i, k, operands, operators) * trueValue(k + 1, j, operands, operators)) % kMod +
                            (falseValue(i, k, operands, operators) * falseValue(k + 1, j, operands, operators)) % kMod) + result) % kMod;
                    }
                    if (operators[k] == '|') {
                        // F si F
                        result = (((falseValue(i, k, operands, operators) * falseValue(k + 1, j, operands, operators)) % kMod) + result) % kMod;
                    }
                    if (operators[k] == '^') {
                        // F si F sau T si T
                        result = (((trueValue(i, k, operands, operators) * trueValue(k + 1, j, operands, operators)) % kMod +
                        (falseValue(i, k, operands, operators) * falseValue(k + 1, j, operands, operators)) % kMod) + result) % kMod;
                    }
                }

                dp_false[i * n + j] = result;
            }
            return result;
        }


	int get_result() {
        string operands, operators;

		operands = " ";
		operators = " ";

        // separ operatorii si operanzii in doua stringuri diferite,
        // ii pun in ordine asa frumos
        operands += expr[1];
		for (int i = 1; i < n - 1; i++) {
			operators += expr[i + 1];
			operands += expr[i + 2];
			i++;

		}
		int size = (n + 1) / 2;
		return trueValue(1, size, operands, operators);
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << '\n';
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
