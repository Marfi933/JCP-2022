#include <iostream>
#include <vector>

using namespace std;

class osoba {
	public:
	string jmeno, prijmeni;
	osoba(string jmeno, string prijmeni) : jmeno(jmeno), prijmeni(prijmeni) {
	}
};

bool pridat(vector<osoba> &v, const char *jmeno, const char * prijmeni) {
	for (auto& osoba : v) {
		if (jmeno == osoba.jmeno && prijmeni == osoba.prijmeni) {
			return false;
		}
	}
	osoba o(jmeno, prijmeni);
	v.push_back(o);
	return true;
}

bool odebrat(vector<osoba>& v, const char* jmeno, const char* prijmeni) {
	int index = 0;
	for (auto& osoba : v) {
		if (jmeno == osoba.jmeno && prijmeni == osoba.prijmeni) {
			v.erase(v.begin() + index);
			return true;
		}
		index++;
	}
	return false;
}


int main() {
	vector<osoba> osoby;
	pridat(osoby, "Petr", "Nemec");
	pridat(osoby, "Adam", "Boyko");
	pridat(osoby, "Pepa", "Nemec");
	pridat(osoby, "Daniel", "Coufal");
	pridat(osoby, "Ondra", "Nemec");
	pridat(osoby, "Petr", "Nemec");
	pridat(osoby, "Andrea", "Nova");
	pridat(osoby, "Petr", "Nemec");
	pridat(osoby, "Alice", "Novakova");
	odebrat(osoby, "Petr", "Nemec");
	odebrat(osoby, "Andrea", "Nova");
	odebrat(osoby, "Andrea", "Nova");	
	for (auto& o : osoby) {
		cout << o.jmeno << " " << o.prijmeni << endl;
	}
	return 0;
}