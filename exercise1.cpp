#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printArray(array<int, 20>arr) {
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    array<int, 20> numbers = {
        31, 35, 27, 43, 21,             
        51, 73, 55, 89, 67, 95, 53, 67, 71, 89,
        1, 15, 7, 19, 9              
    };

    int option = 0;

    do {
        cout << "\n================ MENÚ DE OPCIONES ================\n";
        cout << "1. Imprimir todos los elementos del grupo\n";
        cout << "2. Imprimir elementos mayores a 20 y menores que 50\n";
        cout << "3. Ordenar e imprimir todos los elementos\n";
        cout << "4. Imprimir elementos en indices impares menores de 10\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cout << "-----------------------------------------------------\n";

        switch (option) {
            case 1:
                cout << "Todos los elementos del grupo:\n";
                printArray(numbers);
                break;

            case 2:
                cout << "Elementos mayores a 20 y menores que 50:\n";
                for (auto x : numbers) {
                    if (x > 20 && x < 50) {
                        cout << x << " ";
                    }
                }
                cout << endl;
                break;

            case 3:
                sort(numbers.begin(), numbers.end());
                cout << "Arreglo ordenado ascendentemente:\n";
                printArray(numbers);
                break;

            case 4:
                cout << "Elementos en índices impares menores a 20 (índices 1, 3, 5, ....., 19):\n";
                for (int i = 0; i < 20; ++i) {
                    if (i % 2 != 0) {
                        cout << "Indice [" << i << "]: " << numbers[i] << "\n";
                    }
                }
                break;

            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }

    } while (option != 5);

    return 0;
}                                          