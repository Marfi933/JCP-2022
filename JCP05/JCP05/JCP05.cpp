#include <iostream>
#include <string.h>

using namespace std;

class Struktura {
public:
	virtual bool pridat(int) = 0;
	virtual bool odebrat(int&) = 0;
};

int Pridat(Struktura& struc, int elem[], int n) {
	int count= 0, i;
	for (i = 0; i < n; i++) {
		if (struc.pridat(elem[i])) {
			count++;
		}
		else {
			return count;
		}
	}
	return count;
}

int OdebratVypsat(Struktura& struc, int n=INT_MAX) {
	int count = 0, i, number = 0;
	for (i = 0; i < n; i++) {
		if (struc.odebrat(number)) {
			count++;
			cout << number << " ";
		}
		else {
			cout << "\n";
			return count;
		}
	}
	cout << "\n";
	return count;
}

void fill_null(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = NULL;
	}
}

class Zasobnik : public Struktura {
private: int capacity;
		 int head = -1;
		 int *arr;
public:
	Zasobnik(int capacity) {
		this->capacity = (capacity);
		this->arr = new int[capacity];
		fill_null(this->arr, capacity); // naplní pole 0
	}
	
	bool pridat(int n) {
		if (head >= capacity-1) {
			return false;
		}
		else {
			head++;
			arr[head] = n;
			return true;
		}
	}

	bool odebrat(int&a) {
		if (head == -1) {
			return false;
		}
		else {
			a = arr[head]; 
			arr[head] = NULL;
			head--;
			return true;
		}
	}
	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};


class Fronta : public Struktura {
private: int capacity;
	   int front = 0;
	   int rear = 0;
	   int* arr;
public:
	Fronta(int capacity) {
		this->capacity = (capacity);
		this->arr = new int[capacity];
		fill_null(this->arr, capacity); // naplní pole 0
	}

	bool pridat(int n) {
		if (capacity == rear) {
			return false;
		}
		else {
			arr[rear] = n;
			rear++;
			return true;
		}
	}

	bool odebrat(int& a) {
		if (front == rear) {
			return false;
		}
		else {
			a = arr[front];
			rear--;
			for (int i = 0; i < capacity; i++) {
				arr[i] = arr[i + 1];
			}
		}
	}
	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};

void test_zasobnik() {
	cout << "-------Zasobnik-----" << endl;
	Zasobnik z(6);
	int arr[6] = { 5,9,1,0,4 };
	int arr2[6] = { 3,6,7,5,2,8 };
	Pridat(z, arr, 5);
	z.print();
	OdebratVypsat(z, 3);
	Pridat(z, arr2, 6);
	z.print();
	OdebratVypsat(z, 6);
}

void test_fronta() {
	cout << "-------Fronta-------" << endl;
	int arr[6] = { 5,9,1,0,4 };
	int arr2[6] = { 3,6,7,5,2,8 };
	Fronta f(6);
	Pridat(f, arr, 5);
	f.print();
	OdebratVypsat(f, 3);
	Pridat(f, arr2, 6);
	f.print();
	OdebratVypsat(f, 6);
}



int main(){
	test_zasobnik();
	test_fronta();
	return 0;
}