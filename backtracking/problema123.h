using namespace std;
#include <iostream>
#pragma once

//Se citeşte un număr natural nenul n.Să se afişeze, în ordine lexicografică, permutările mulţimii{ 1,2,..,n }

unsigned m[100], nr;

void tipar1() {
	cout << endl;
	for (int i = 0; i < nr; i++) {
		cout << m[i] << ' ';
	}
}

int valid1(int k) {
	for (int i = 0; i < k; i++) {
		if (m[i] == m[k]) {
			return 0;
		}
	}
	return 1;
}

int solutie1(int k) {
	if (k == nr - 1) {
		return 1;
	}
	return 0;
}


void back1(int k) {
	unsigned val;
	for (val = 1; val <= nr; val++) {
		m[k] = val;
		if (valid1(k)) {
			if (solutie1(k)) {
				tipar1();
			}
			else {
				back1(k + 1);
			}
		}
	}
}


void sol123() {
	cout << "nr=";
	cin >> nr;
	back1(0);
}