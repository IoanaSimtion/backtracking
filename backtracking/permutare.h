/*Cerinta:
Realizeaza permutari din multimea M={1,2,3,..,n}, n<21
astfel incat primul element sa fie impar iar ultimul sa fie par*/

using namespace std;
#include <iostream>
#pragma once
unsigned s[20], n; 

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << ' ';
	}
}

int valid(int k) {
	if (k == 0 && s[k] % 2 == 0) {
		return 0;
	}//conditii suplimentare

	if (k == n - 1 && s[k] % 2 == 1) {
		return 0;
	}//conditii suplimentare

	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	
	return 1;
}

int solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 1; val <= n; val++) {
		s[k] = val;//{1,2,0}
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}



void afisarePermutari() {

	cout << "n=";
	cin >> n;
	back(0);
}
