#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar un número aleatorio entre 0 y 99
int generarNumeroAleatorio() {
    return rand() % 100;
}

// Función para calcular la aptitud de un individuo
int calcularAptitud(int individuo, int objetivo) {
    return abs(objetivo - individuo);
}

// Función para seleccionar individuos para la reproducción (ruleta)
int seleccionarPadre(const vector<int>& poblacion, int objetivo) {
    int totalAptitud = 0;
    for (size_t i = 0; i < poblacion.size(); ++i) {
        totalAptitud += calcularAptitud(poblacion[i], objetivo);
    }

    int r = rand() % totalAptitud;
    int acumulado = 0;
    for (size_t i = 0; i < poblacion.size(); ++i) {
        acumulado += calcularAptitud(poblacion[i], objetivo);
        if (acumulado >= r) {
            return poblacion[i];
        }
    }
    return poblacion.back();
}

// Función para realizar la reproducción (cruce)
int reproducir(int padre1, int padre2) {
    // Se realiza un cruce simple tomando la mitad de los bits de cada padre
    int mascara = (1 << 16) - 1; // Máscara de 16 bits con todos los bits en 1
    int bitsPadre1 = padre1 & mascara;
    int bitsPadre2 = padre2 & mascara;
    int hijo = (bitsPadre1 >> 8) | (bitsPadre2 << 8); // Cruce en el octavo bit
    return hijo;
}

// Función principal
int main() {
    srand(time(NULL));

    const int objetivo = 42;
    const int tamanoPoblacion = 100;
    const double tasaMutacion = 0.1;

    vector<int> poblacion;

    // Inicializar la población con números aleatorios
    for (int i = 0; i < tamanoPoblacion; ++i) {
        poblacion.push_back(generarNumeroAleatorio());
    }

    int generacion = 0;
    while (true) {
        // Evaluar la aptitud de la población
        int mejorIndividuo = poblacion[0];
        int mejorAptitud = calcularAptitud(mejorIndividuo, objetivo);
        for (size_t i = 0; i < poblacion.size(); ++i) {
            int individuo = poblacion[i];
            int aptitud = calcularAptitud(individuo, objetivo);
            if (aptitud < mejorAptitud) {
                mejorIndividuo = individuo;
                mejorAptitud = aptitud;
            }
        }

        cout << "Generacion " << generacion << ": " << mejorIndividuo << " (Aptitud: " << mejorAptitud << ")" << endl;

        // Comprobar si se ha alcanzado el objetivo
        if (mejorAptitud == 0) {
            cout << "Objetivo alcanzado!" << endl;
            break;
        }

        // Seleccionar individuos para la reproducción y crear una nueva generación
        vector<int> nuevaGeneracion;
        for (int i = 0; i < tamanoPoblacion; ++i) {
            int padre1 = seleccionarPadre(poblacion, objetivo);
            int padre2 = seleccionarPadre(poblacion, objetivo);
            int hijo = reproducir(padre1, padre2);

            // Aplicar una tasa de mutación
            if (rand() / static_cast<double>(RAND_MAX) < tasaMutacion) {
                hijo = generarNumeroAleatorio();
            }

            nuevaGeneracion.push_back(hijo);
        }

        poblacion = nuevaGeneracion;
        generacion++;
    }

    return 0;
}

