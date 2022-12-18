using namespace std;
#include <iostream>
#pragma once

//Se citeşte un număr natural nenul n.Să se afişeze, în ordine invers lexicografică, permutările mulţimii{ 1,2,..,n }.

unsigned a[100], n;

void tipar(){
	cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (a[i] == a[k]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k == (n - 1)) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 1; val <= n; val++) {
		a[k] = val;
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

void sol124() {
	cout << "n=";
	cin >> n;
	back(0);
}