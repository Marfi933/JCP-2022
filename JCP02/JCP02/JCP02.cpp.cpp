#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//�e�en� 1
	char c = 48;
	int i, j;
	cout << setw(5);
	for (i = 0; i < 16; i++) {
		cout << hex << c << ' ';
		c++;
		if (c == '9' + 1) {
			c += 7;
		}
	}
	cout << endl;
	cout << setw(3);
	for (int j = 0; j < 17 * 2; j++) {
		cout << '-';
	}
	c = 32;
	cout << '-' << endl;
	for (int i = 0; i < 14; i++) {
		cout << hex << (int)(unsigned char)c << '|';
		for (int j = 0; j < 16; j++) {
			if (j == 15 && i == 5) { // znak delete -> �patn� se vykresluje
				cout << setw(3) << hex << c;
				c++;
			}
			else {
				cout << setw(2) << hex << c;
				c++;
			}

		}
		cout << setw(2) << '|';
		cout << endl;
	}
	cout << setw(3);
	for (int j = 0; j < 17 * 2; j++) {
		cout << '-';
	}
	cout << '-' << endl;

	//vytiskne 5 pr�zdn�ch ��dk�
	for (i = 0; i < 5; i++) {
		cout << endl;
	}

	//�e�en� 2
	cout << setw(6);
	c = '0';
	for (i = 0; i < 10; i++) {
		cout << c << ' ';
		c++;
	}
	cout << endl;
	cout << setw(4);
	for (int j = 0; j < 11 * 2; j++) {
		cout << '-';
	}
	cout << '-' << '\n';
	c = 30;
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 10; j++) {
			if (i != 7 && j == 0) {
				cout << dec << setw(3) << (unsigned int)(unsigned char)c << '|';
			}
			else if (i >= 7 && j == 0) {
				cout << dec << (unsigned int)(unsigned char)c << '|';
			}
			if ((i == 9 && j == 7) || (i == 22 && j == 7)) { // znaky, ktere se spatne vykreslily{
				cout << dec << setw(3) << c;
			}
			else {
				cout << dec << setw(2) << c;
			}
			c++;
		}
		cout << setw(2) << '|';
		cout << endl;
	}
	cout << setw(4);
	for (int j = 0; j < 11 * 2; j++) {
		cout << '-';
	}
	cout << '-' << endl;
}


