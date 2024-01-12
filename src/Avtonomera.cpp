#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PLATES = 160;
const int EXIT = -1;

struct Plate {
    int code;
    string region;
};

typedef Plate Plates_vector[MAX_PLATES];

struct Plates {
    Plates_vector vec;
    int n;
};

void openFile(ifstream& fin, string& filename) {
    cout << "Data file: ";
    cin >> filename;
    fin.open(filename.c_str());

    while (not fin.is_open()) {
        cout << "File not found. try again." << endl;
        cout << "File name: ";
        cin >> filename;
        fin.open(filename.c_str());
    }
}

void readPlate(ifstream& fin, Plate& p) {
    fin >> p.code;
    if (not fin.eof()) {
        fin >> p.region;
    }
}

void insert(Plates& plates, Plate& p) {
    int i = plates.n - 1;
    while (i >= 0 and p.code < plates.vec[i].code) {
        plates.vec[i + 1] = plates.vec[i];
        i--;
    }
    plates.vec[i + 1] = p;
    plates.n++;
}

void readFile(ifstream& fin, Plates& plates) {
    int i = 0;
    Plate p;
    readPlate(fin, p);
    while (not fin.eof()) {
        insert(plates, p);
        i++;
        readPlate(fin, p);
    }
    plates.n = i;
    cout << "Data loaded." << endl;
}

void askCode(int& c) {
    cout << "CODE: ";
    cin >> c;
}

void searchCode(const Plates& plates, int code, bool& found, int& pos) {
    int a = 0;
    int b = plates.n - 1;
    int m = 0;
    found = false;
    while (a <= b and not found) {
        m = (a + b) / 2;
        if (code == plates.vec[m].code) found = true;
        else if (code < plates.vec[m].code) b = m - 1;
        else a = m + 1;
    }
    if (found) pos = m;
    else pos = a;
}

void printRegion(string region) {
    for (char& c : region)
        if (c == '_') cout << ' ';
        else cout << c;
    cout << endl;
}

int main() {
    ifstream fin;
    string filename;
    openFile(fin, filename);

    Plates plates;
    readFile(fin, plates);

    for (int i = 0; i < plates.n; i++) {}

    cout << "[" << EXIT << " TO EXIT]" << endl;

    int code;
    askCode(code);
    while (code != EXIT) {
        bool found;
        int pos;
        searchCode(plates, code, found, pos);

        if (not found) {
            cout << "Registration code not found, please try again." << endl;
        } else {
            string region = plates.vec[pos].region;
            printRegion(region);
        }

        askCode(code);
    }

    return 0;
}