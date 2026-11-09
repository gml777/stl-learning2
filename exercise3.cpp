#include <iostream>
#include <array>
#include <string>
#include <fstream> 

using namespace std;

struct Estudiante {
    string nombre;
    int anioNacimiento;
    float gpa;
};

void imprimirEstudiantes(const array<Estudiante, 10>& estudiantes) {
    int anioActual = 2026; 
    for (const auto& est : estudiantes) {
        if (!est.nombre.empty()) {
            int edad = anioActual - est.anioNacimiento;
            string calificaBeca = (est.gpa >= 3.5) ? "Si" : "No";

            cout << "Nombre: " << est.nombre 
                 << " \t| Edad: " << edad 
                 << " \t| GPA: " << est.gpa 
                 << " \t| Beca: " << calificaBeca << "\n";
        }
    }
    cout << "\n";
}

int main() {
    array<Estudiante, 10> estudiantes = {{
        {"Juan", 2000, 3.4},
        {"Maria", 2005, 2.8}
    }};

    int options = 0;

    do {
        cout << "\n================ MENU DE OPERACIONES ================\n";
        cout << "1. Insertar 3er y 4to elemento (desde teclado)\n";
        cout << "2. Insertar 5to y 6to elemento (desde arrays basicos)\n";
        cout << "3. Insertar elementos restantes (desde datos.txt)\n";
        cout << "4. Imprimir todos los estudiantes (Edad y Beca)\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> options;
        cout << "-----------------------------------------------------\n";

        switch (options) {
            case 1:
                cout << "Ingrese 3er estudiante (Nombre Anio GPA) separados por espacio:\n";
                cin >> estudiantes[2].nombre >> estudiantes[2].anioNacimiento >> estudiantes[2].gpa;
                
                cout << "Ingrese 4to estudiante (Nombre Anio GPA) separados por espacio:\n";
                cin >> estudiantes[3].nombre >> estudiantes[3].anioNacimiento >> estudiantes[3].gpa;
                break;

            case 2: {
                string nombres[] = {"Gaby", "Patty", "Diana"};
                int nacimientos[] = {2002, 2004, 2006};
                float gpas[] = {3.8, 3.0, 2.9};

                estudiantes[4].nombre = nombres[0];
                estudiantes[4].anioNacimiento = nacimientos[0];
                estudiantes[4].gpa = gpas[0];

                estudiantes[5].nombre = nombres[1];
                estudiantes[5].anioNacimiento = nacimientos[1];
                estudiantes[5].gpa = gpas[1];

                cout << "Estudiantes 5 y 6 ingresados desde los arrays internos.\n";
                break;
            }

            case 3: {
                ifstream archivo("datos.txt");
                
                if (archivo.is_open()) {
                    for (int i = 6; i < 10; ++i) {
                        archivo >> estudiantes[i].nombre >> estudiantes[i].anioNacimiento >> estudiantes[i].gpa;
                    }
                    archivo.close();
                    cout << "Datos cargados exitosamente desde datos.txt.\n";
                } else {
                    cout << "ERROR: No se encontro el archivo 'datos.txt'.\n";
                }
                break;
            }

            case 4:
                cout << "Lista de todos los estudiantes registrados:\n";
                imprimirEstudiantes(estudiantes);
                break;

            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }

    } while (options != 5);

    return 0;
}