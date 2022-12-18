using namespace std;
#include <iostream>
#pragma once

//Se citesc două numere a și b. Să se afișeze, în ordine lexicografică, permutările mulțimii {a, a + 1, ..., b}.

unsigned a, b, v[100];

void tipar() {
	cout << endl;
	for (int i = 0; i <= b - a; i++) {
		cout << v[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (v[i] == v[k]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k == (b - a)) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = a; val <= b; val++) {
		v[k] = val;
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

void sol3909() {
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	back(0);
}