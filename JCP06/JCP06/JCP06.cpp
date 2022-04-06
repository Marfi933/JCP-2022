#include <iostream>
#include <limits.h>
using namespace std;

void cpy_arr(int* dest, int* source, int n) {
	for (int i = 0; i < n; i++) {
		dest[i] = (int) source[i];
	}
}

class Mnozina {
private:
	int size;
	int index = 0;
	int *arr;
public:
	
	//Konstruktor
	Mnozina(int n) {
		size = n;
		this->arr = new int [n];
	}
	
	//Destruktor
	/*~Mnozina() {
		delete[]arr;
	}*/

	// vypise jen cisla, ktera obsahuje pole
	void print() { 
		for (int i = 0; i < index; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int find(int n) {
		for (int i = 0; i < index; i++) {
			if (arr[i] == n) {
				return i;
			}
		}
		return -1; // mimo pole
	}

	int get_index() {
		return index;
	}

	Mnozina& operator << (int n) {
		if (index == size) {
			int *new_arr = new int [size*2];
			cpy_arr(new_arr, arr, size);
			new_arr[index] = n;
			delete[] arr;
			arr = new int [size*2];
			cpy_arr(arr, new_arr, size+1);
			delete[]new_arr;
			size *= 2;
		}
		else {
			arr[index] = n;
		}
		index++;
		return *this;
	}

	Mnozina& operator -= (int n) {
		int j = find(n);
		if (j != -1) {
			for (int i = j; i < index; i++) {
				arr[i] = arr[i + 1];
			}
			index--;
			arr[index] = NULL;	
		}
		return *this;
	}

	Mnozina& operator += (Mnozina m) {
		int j,i,n;
		for (i = 0; i < m.size; i++) {
			n = m.arr[i];
			j = find(n);
			if (j == -1) {
				*this << n;
			}
		}
		return *this;
	}

	int & operator +() {
		return index;
	}

	int& operator *() {
		return size;
	}

	signed int operator [] (unsigned i) const
	{
		if (i < size) return arr[i];
		return INT_MIN;
	}

	Mnozina& operator -= (Mnozina m) {
		for (int i = 0; i < m.index; i++) {
			int n = m.arr[i], j = find(n);
			if (j != -1) {
				*this -= n;
				print();
			}
		}
		return *this;
	}
};


int main() {
	Mnozina m(10);
	Mnozina m2(10);
	int arr[10] = { 1, 5, 3, 10, 0, 7, 2, 8, 11, 4 };
	int arr2[10] = { 1,3,12, -5, 14, 13, 0, 10, 7, 15 };
	for (int i = 0; i < 10; i++) {
		m << arr[i];
		m2 << arr2[i];
	}
	cout << +m <<" " << *m << endl;	
	m -= 10;
	m -= 0;
	m += m2;
	m.print();
	m -= m2;
	m.print();
	cout << m[5] << " " << m[30];
	return 0;
}