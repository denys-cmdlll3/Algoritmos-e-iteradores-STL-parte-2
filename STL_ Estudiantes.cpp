#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string name;
    int year_birth;
    float GPA, budget;

public:
    Student(string name = "NN", int year_birth = 0,float GPA = 0, float budget = 0) {
        this->name = name;
        this->year_birth = year_birth;
        this->GPA = GPA;
        this->budget = budget;
    }

    float indice() const {
        return abs(GPA - 3) * budget;
    }

    float clave(int criterio) const {
        if (criterio == 1) return year_birth;
        if (criterio == 2) return GPA;
        if (criterio == 3) return budget;
        return indice();
    }

    friend istream& operator>>(istream& in, Student& s) {
        in >> s.name >> s.year_birth >> s.GPA >> s.budget;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.name << " " << s.year_birth << " " << s.GPA << " " << s.budget;
        return out;
    }
};

class Menu {
private:
    vector<Student> estudiantes;

    void insertar() {
        int opcion, indice;
        Student s;

        cout << "1. Al final\n";
        cout << "2. En una posicion\n";
        cin >> opcion;

        if (opcion == 2) {
            cout << "Ingrese posicion (0-" << estudiantes.size() << "): ";
            cin >> indice;

            if (indice < 0 || indice > estudiantes.size()) {
                cout << "Posicion invalida\n";
                return;
            }
        }
        else if (opcion == 1) {
            indice = estudiantes.size();
        }
        else {
            cout << "Opcion invalida\n";
            return;
        }

        cout << "1. Datos por defecto\n";
        cout << "2. Ingresar datos\n";
        cin >> opcion;

        if (opcion == 2) {
            cout << "Nombre, anio, GPA y presupuesto: ";
            cin >> s;
        }
        else if (opcion != 1) {
            cout << "Opcion invalida\n";
            return;
        }

        estudiantes.insert(estudiantes.begin() + indice, s);
    }

    void eliminar() {
        if (estudiantes.empty()) {
            cout << "Vector vacio\n";
            return;
        }

        int opcion, indice;

        cout << "1. Eliminar ultimo\n";
        cout << "2. Eliminar por posicion\n";
        cin >> opcion;

        if (opcion == 1) {
            indice = estudiantes.size() - 1;
        }
        else if (opcion == 2) {
            cout << "Ingrese posicion (0-" << estudiantes.size() - 1 << "): ";
            cin >> indice;

            if (indice < 0 || indice >= estudiantes.size()) {
                cout << "Posicion invalida\n";
                return;
            }
        }
        else {
            cout << "Opcion invalida\n";
            return;
        }

        estudiantes.erase(estudiantes.begin() + indice);
    }

    void actualizar() {
        if (estudiantes.empty()) {
            cout << "Vector vacio\n";
            return;
        }

        int indice;

        cout << "Ingrese posicion (0-" << estudiantes.size() - 1 << "): ";
        cin >> indice;

        if (indice < 0 || indice >= estudiantes.size()) {
            cout << "Posicion invalida\n";
            return;
        }

        cout << "Ingrese nuevos datos: ";
        cin >> estudiantes[indice];
    }

    void ordenar() {
        if (estudiantes.empty()) {
            cout << "Vector vacio\n";
            return;
        }

        int criterio;

        cout << "1. Anio de nacimiento\n";
        cout << "2. GPA\n";
        cout << "3. Presupuesto\n";
        cout << "4. Indice universitario\n";
        cin >> criterio;

        if (criterio < 1 || criterio > 4) {
            cout << "Criterio invalido\n";
            return;
        }

        sort(estudiantes.begin(), estudiantes.end(),
            [criterio](const Student& a, const Student& b) {
                return a.clave(criterio) < b.clave(criterio);
            });

        cout << "Estudiantes ordenados correctamente\n";
    }

    void imprimir() {
        if (estudiantes.empty()) {
            cout << "Vector vacio\n";
            return;
        }

        for (int i = 0; i < estudiantes.size(); i++) {
            cout << i << ": " << estudiantes[i] << endl;
        }
    }

public:
    void ejecutar() {
        int opcion;

        do {
            cout << "\n--- MENU ---\n";
            cout << "1. Insertar\n";
            cout << "2. Eliminar\n";
            cout << "3. Actualizar\n";
            cout << "4. Ordenar\n";
            cout << "5. Imprimir\n";
            cout << "0. Salir\n";
            cout << "Opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1: insertar(); break;
                case 2: eliminar(); break;
                case 3: actualizar(); break;
                case 4: ordenar(); break;
                case 5: imprimir(); break;
                case 0: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida\n";
            }

        } while (opcion != 0);
    }
};

int main() {
    Menu menu;
    menu.ejecutar();

    return 0;
}
