#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;
class Surovina {
    char Nazev[20], Mnozstvi[20];
public: 
    Surovina(const char* nazev, const char* mnozstvi) {
        strcpy_s(Nazev, nazev);
        strcpy_s(Mnozstvi, mnozstvi);
      }
      Surovina() { }
      const char* nazev() { return Nazev; };
      const char* mnozstvi() { return Mnozstvi; };
};

class obdelnik {
private:
    float a, b;
public:
    obdelnik(float as, float bs) {
        a = as;
        b = bs;
    }
    float obsah() { return a * b; }
    float obvod() { return 2 * (a + b); }
    void show() {
        for (int row = 1; row <= (int)a; row++) {
            for (int col = 1; col <= (int)b; col++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
    bool is_square() {
        return a == b;
    }
};

class soubor {
    string nazev;
    unsigned int size;
    public:
        soubor(string s, unsigned int siz) {
            nazev = s;
            size = siz;
        }
        void show() {
            cout << "nazev souboru: %s" << nazev << ", velikost souboru: %d" << size <<endl;
        }
        void rename(string s) {
            nazev = s;
        }
};

class figurka {
    int x = 0;
public:
    figurka(int xx) {
        x = xx;
    }
    void posun(int xx) {
        x += xx;
    }

    void pozice() {
        cout << "x: " << x <<endl;
    }
};

class Stack {
int capacity = 10;
int size = 0;
int arr[10];
public:

    Stack() = default;
    void push(int el) {
        if (size == capacity) {
            printf("Capacity is full");
        }
        arr[size] = el;
        size++;
    }
    int pop() {
        int a = arr[size--];
        if (size == 0) {
            printf("Nothing to pop");
        }
        for (int i = 0; i < (sizeof(arr) / 10) - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return a;
        }
    };

class kostka {
    int pocet_stran;
public:
    kostka(int pocet) {
        pocet_stran = pocet;
    }
    int hod() {
        return rand() % pocet_stran+1;
    }
};

int main() {
    Surovina Kulajda[8];
    const char* NM[] =
    { "ocet","1 lzicka","bobkovy list","4 ks",
      "smetana na vareni","1 kelimek","brambory","400 g",
      "cely cerny pepr","5 kulicek","mleko","500 ml",
      "vejce natvrdo","6 ks","cele nove koreni","5 kulicek" };
    int j = 1;
    int k = 0;
    for (int i = 0; i < 8; i++) {
        Kulajda[i] = Surovina(NM[k], NM[j]);
        k += 2;
        j += 2;
    }
    for (int i = 0; i < 8; i++) {
        cout << Kulajda[i].nazev() << ' ' << Kulajda[i].mnozstvi() << endl;
    }
    obdelnik o(10,5);
    o.show();
    cout << o.is_square() << endl;
    kostka ko(6);
    figurka fi(0);
    for (j = 0; j < 10; j++) {
        fi.posun(ko.hod());
        fi.pozice();
    }
    Stack s;
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    cout << s.pop();
}
