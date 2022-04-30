#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Fruits {
	string name;
	float mass = 0.0;
	float price = 0.0;
	Fruits(string nam, float mas, float pr) : name(nam), mass(mas), price(pr) {};
}; 

struct smaller {
	bool operator () (const string& c1, const string& c2) const // predicate to map
	{
		const char* a = c1.c_str();
		const char* b = c2.c_str();
		return(_stricmp(a, b) < 0); // str c1 < str c2
	}
};

struct equals {
	bool operator()(const string& c1, const string& c2) const { // if c1 == c2, doesn't matter the size of char (uppercase, lowercase)
		const char* a = c1.c_str();
		const char* b = c2.c_str();
		return(_stricmp(a, b) == 0); // str c1 == str c2
	}
};

void split_data(char * &s, vector <Fruits>& fruits) {
	string name, mass, price;
	int count = 1;
	bool after = false;
	for (auto i = 0; i < strlen(s); i++) { 
		if (isalpha(s[i])) { // if char is letter push to string name
			name.push_back(s[i]);
		}
		else if ((isalnum(s[i]) || s[i] == '.') && count == 1) { // if char is number or . push to string mass
			mass.push_back(s[i]);
			after = true; // after is variable for check if we have number in string mass
		}
		else if (after && s[i] == ' ') { // if char is space and after () is true push to string price
			after = false;
			count++; // increment count for check if we the next char after number or . is space 
		}
		else if ((isalnum(s[i]) || s[i] == '.') && count == 2) {
			price.push_back(s[i]); // if char is number or . push to string price
		}
	}
	fruits.push_back(Fruits(name, stof(mass), stof(price)));
}

void get_fruits(vector <Fruits>& fruits, const char* filename) {
	ifstream file(filename, ios::binary);
	char* s;
	s = new char[1000];
	if (file.is_open()) {
		while (file.getline(s, 1000)) {
			split_data(s, fruits);
		}
	}
}

void fix_string(string &s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

void calculate_mass_and_avg(multimap<string, pair<float, float>, smaller>& fruit_map) {
	multimap<string, pair<float, float>, smaller> res;
	for (auto fruit : fruit_map) {
		float price = 0.0;
		float mass = 0.0;
		unsigned int count = 0;
		for (auto i = fruit_map.find(fruit.first); i != fruit_map.end(); i++) { // find all fruits with the same name
			if ((equals ()(i->first, fruit.first)) && (res.find(fruit.first) == res.end())) { // if the name is in the result map than skip
				price += i->second.second * i->second.first;
				mass += i->second.first;
				count++;
			}
			else {
				break;
			}
		}
		if (res.find(fruit.first) == res.end()) { 
			string name = fruit.first;
			fix_string(name); // change name to lower case
			res.emplace(name, make_pair(mass, price / mass));
		}
	}
	fruit_map = res;
}

float roundoff(float value)
{
	float pow_10 = pow(10.0, 1);
	return round(value * pow_10) / pow_10;
}


void insert_to_file(const char *filename, multimap<string, pair<float, float>, smaller>& fruit_map) {
	ofstream file(filename, ios::binary);
	if (file.is_open()) {
		while (fruit_map.size() != 0) {
			auto it = fruit_map.begin();
			file << it->first << "     " << roundoff(it->second.first) << "      " << roundoff(it->second.second) << endl;
			fruit_map.erase(it);
		}
	}
}


int main()
{
	vector <Fruits> fruits;
	multimap<string, pair<float, float>, smaller> fruit_map;
	get_fruits(fruits, "Ovoce.txt");
		for (auto i : fruits) {
		fruit_map.emplace(i.name, make_pair(i.mass, i.price));
	}
	calculate_mass_and_avg(fruit_map);
	for (auto i : fruit_map) {
		cout << i.first << " " << i.second.first << " " << i.second.second << endl;
	}
    insert_to_file("OvoceCelkem.txt", fruit_map);
	return 0;
}
