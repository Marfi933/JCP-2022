#include <iostream>
#include <limits.h>
using namespace std;

template <class P, class D, unsigned n=10>
class PFronta {
private:
	P *priorita;
	D *data;
	unsigned velikost;
	int count=0;
public:
	PFronta() {
		this->velikost = n;
		this->data = new D[velikost];
		this->priorita = new P[velikost];
	}
	bool vlozit(const P&p, const D&d) {
		if (count == velikost-1) {
			return false;
		}
		else {
			priorita[count] = p;
			data[count] = d;
			count++;
			return true;
		}
	}
	bool odebrat(D& del) {
		if (count == 0) {
			return false;
		}
		else {
			P max_pr = priorita[0];
			int index = 0, j = 0;
			for (int k = 0; k < count; k++){
				if (max_pr < priorita[k]) {
					max_pr = priorita[k];
					index = k; //variable index stores index of max priority
				}
			}
			del = data[index];
			for (int k = index; k < count; k++) {
				priorita[k] = priorita[k+1];
				data[k] = data[k+1];
			}
			count--;
			return true;
		}
	}
};

struct Jmeno
{
	char jmeno[10];
	Jmeno() {};
	Jmeno(const char* a) {
		strcpy_s(jmeno, a);
	}
};


int main() {
	PFronta<unsigned, Jmeno> p;
	Jmeno jmeno;
	p.vlozit(5, Jmeno("Pavel"));
	p.vlozit(3, Jmeno("Jana"));
	p.vlozit(1, Jmeno("Eva"));
	p.vlozit(5, Jmeno("Irena"));
	p.vlozit(4, Jmeno("Pavla"));
	p.vlozit(1, Jmeno("Petr"));
	p.vlozit(3, Jmeno("Hana"));
	p.vlozit(7, Jmeno("Jan"));
	p.vlozit(5, Jmeno("Roman"));
	for (int i = 0; i < 9; i++) {
		p.odebrat(jmeno);
		cout << jmeno.jmeno << " ";
	}
	return 0;

}