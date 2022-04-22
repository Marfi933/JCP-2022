#include <iostream>
#include <fstream>
using namespace std;


void fix_string(char*& s, int n) {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			s[i] = toupper(s[i]);
		}
		else {
			s[i] = tolower(s[i]);
		}
	}
	s[n] = '\0';
}

int main() {
	ifstream s("Jmena", ios::binary);
	ofstream file("JmenaC", ios::binary);
	char c;
	if (s.is_open() && file.is_open()) {
		int size;
		while (!s.eof()) {
			s.read((char*)&c, sizeof(c));
			if (s.eof()) break;
			size = (int)c;
			char* str = new char[size + 1];
			s.read(str, size);
			fix_string(str, size);
			file.write(str, size);
			}
		s.close();
		file.close();
	}
	ifstream s2("JmenaC", ios::binary);
	ofstream file2("Jmena.txt", ios::binary);
	
	if (s2.is_open() && file2.is_open()) {
		char new_line = '\n';
		char space = ' ';
		int n = 0;
		unsigned int count_names = 0;
		while (!s2.eof()) {
			if (s2.eof()) break;
			s2.read((char*)&c, sizeof(c));
			if (n == 10 && !islower(c)) { // if we found the number of names and we know that we are at the end of the name
				n = 0;
				file2.put(new_line); 
				n++; // increment here, cause current letter is upper
				count_names++;
			}
			else if (isupper(c) && n == 0) { // avoid spaces on the beginning of line
				n++;
				count_names++;
			}
			else if (isupper(c)) {
				n++;
				count_names++;
				file2.put(space); // before every name we put space
			}
			file2.put(c); // add char to file
		}
		cout << "Pocet jmen: " << count_names << endl;
		s2.close();
		file2.close();
	}
	return 0;
}