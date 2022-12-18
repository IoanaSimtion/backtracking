using namespace std;
#include <iostream>
#pragma once

//Se citește un număr natural n (n<16). Afișați în ordine lexicografică toate permutările mulțimii {1,2,…,n} 
//în care elementele pare sunt puncte fixe (nu își schimbă poziția).

unsigned v[50], n;

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (v[i] % 2 == 0 && i % 2 == 0) {
			return 0;
		}
		if (v[i] % 2 == 1 && i % 2 == 1) {
			return 0;
		}
		if (v[i] % 2 == 0 && v[i] - i > 1) {
			return 0;
		}
	}

	for (int i = 0; i < k; i++) {
		if (v[i] == v[k]) {
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

void sol3150() {
	cout << "n=";
	cin >> n;
	back(0);
}