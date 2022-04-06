#include <iostream>

using namespace std;

void only_characters(string& s)
{
	int i;
	for (i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i]))
		{
			s.erase(i, 1);
			i--;
		}
	}
}

void add_spaces(string& s) {
	int i;
	for (i = 0; i <= s.length()-1; i++)
	{
		if (isupper(s[i]) && i != 0)
		{
			s.insert(i, " ");
			i++;
		}
	}
}

void add_new_line(string& s, int n) {
	int i;
	int j = 0; //Number of words on line
	for (i = 0; i <= s.length() - 1; i++)
	{
		if (j == n)
		{
			s.insert(i, "\n");
			j = 0;
		}
		else if (s[i] == ' ') {
			j++;
		}
	}
}

void remove_characters(string& s) {
	int n;
	cout << "Enter number: ";
	cin >> n;
	cout << endl;
	only_characters(s);
	add_spaces(s);
	add_new_line(s, n);
}

int main() {
	string Jmena("::Marie---JanJana..PetrJosefPavel**JaroslavMartinMiroslavEva   "
		"AnnaHanaKarel   LenkaMilanMichal&&AlenaPetra#####LucieJaroslava"
		"Ludmila@@@HelenaDavid@#$%LadislavJitkaMartinaJakub^^^^^^^^VeronikaJarmilaStanislav"
		"Michaela!!!!!IvanaRomanMonika    TerezaZuzanaRadekVlastaMarcelaMarek____"
		"DagmarDanaDanielMartaIrenaMiroslavaBarboraPavlaMiloslavOlga"
		"AndreaIvetaFilipBlanka*&^%<>MiladaIvanZdenkaLibor-----RenataRudolf"
		"VlastimilNikolaGabrielaAdamRadka....SimonaMilenaMiloslavaIva~~~~Daniela~~~"
		"PatrikBohumilDenisaRobert    RomanaAnetaIlona  DominikStanislavaEmilie"
		"RadimRichardKamila++++IvoRostislavVladislavBohuslavAlois==**/VitKamil"
		"JozefVendula%%%%BohumilaViktorEmilMichael%%44%%%LadislavaMagdalenaEduardDominika"
		"MarcelSabinaJulie689AntonieAlicePeter+1000DaliborKristinaOtakarKarla"
		"HedvikaAlexandra'''''SilvieErikaNelaVratislavNikol???LeonaJolanaMargita"
		"Bohuslava&&&RadovanJosefaTerezieMarianLindaIgor((1))");
	remove_characters(Jmena);
	cout << Jmena << endl;
	return 0;
}