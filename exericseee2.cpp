#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

void printArray(const array<string, 10>& countries) {
    for (const auto& x : countries) {
        cout << x << " ";
    }
    cout << "\n";
}

int main () 
{
    array<string, 10> countries = {
        "Perú", "Colombia", "Argentina", "Brasil", "Chile"
    };

    int options = 0;

    do {
        cout << "\n================ ELIJA LA OPCIÓN DE SU AGRADO ================\n";
        cout << "1. Insertar los elementos restantes (con at() y [])\n";
        cout << "2. Imprimir paises que inician con C o P\n";
        cout << "3. Imprimir el primer y ultimo elemento\n";
        cout << "4. Ordenar e imprimir todos los elementos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> options;
        cout << "-----------------------------------------------------\n";

        switch (options) {
            case 1:
                countries[5] = "Ecuador";
                countries[6] = "Bolivia";
                countries[7] = "Paraguay";
                countries.at(8) = "Venezuela";
                countries.at(9) = "Uruguay";
                
                cout << "Elementos restantes insertados correctamente.\n";
                cout << "Arreglo actualizado: ";
                printArray(countries);
                break;

            case 2:
                cout << "Paises que inician con 'C' o 'P':\n";
                for (const auto& pais : countries) {
                    if (!pais.empty() && (pais[0] == 'C' || pais[0] == 'P')) {
                        cout << pais << " ";
                    }
                }
                cout << "\n";
                break;

            case 3:
                cout << "Primer elemento: " << countries.front() << "\n";
                cout << "Ultimo elemento: " << countries.back() << "\n";
                break;

            case 4:
                sort(countries.begin(), countries.end());
                cout << "Arreglo ordenado ascendentemente:\n";
                printArray(countries);
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