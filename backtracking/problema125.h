using namespace std;
#include <iostream>
#pragma once

//Se citeşte un număr natural nenul n, apoi n numere naturale distincte. 
//Să se afişeze, în ordine lexicografică, permutările mulţimii formate din cele n numere citite

unsigned v[50], n, multime[50];
int p = 0;
int permutari[50][50];


//todo functie ce verifica daca vectorul a este mai mare decat vectorul b

bool comparareVectori(int a[50], int b[50], int d) {

	int i = 0;
	while (a[i] == b[i] && i < d) {
		i++;
	}

	if (a[i] > b[i]) {

		return true;
	}
	else {
		return false;
	}
}

void afisareMatrice(int m[50][50], int p, int n) {
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
}

void interschimbareLinii(int m[50][50], int linie1, int linie2, int n) {
	for (int i = 0; i < n; i++) {
		int aux = m[linie1][i];
		m[linie1][i] = m[linie2][i];
		m[linie2][i] = aux;
	}
}

void sortMatrice(int m[50][50], int p, int n) {
	
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < p - 1; i++) {
			if (comparareVectori(m[i],m[i+1], p)>0) {
				//cout << "da" << endl << endl;
				interschimbareLinii(m, i, i + 1, n);
				flag = 0;
			}
		}
	} while (flag == 0);

}

void matrice() {
	for (int i = 0; i < n; i++) {
		permutari[p][i] = v[i];
	}
	p++;
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (v[k] == v[i]) {
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
	for (int i = 0; i < n; i++) {
		val = multime[i];
		v[k] = val;
		if (valid(k)) {
			if (solutie(k)) {
				matrice();
			}
			else {
				back(k + 1);
			}
		}
	}

	
}


void sol125() {
	cout << "n=";
	cin >> n;
	cout << "Elementele multimii: ";
	for (int i = 0; i < n; i++) {
		cin >> multime[i];
	}
	back(0);
	sortMatrice(permutari, p,n);
	afisareMatrice(permutari, p, n);

	/*cout << comparareVectori(permutari[0], permutari[2], n);
	cout << endl << endl;
	interschimbareLinii(permutari, 3, 5, n);
	afisareMatrice(permutari, p, n);*/
}