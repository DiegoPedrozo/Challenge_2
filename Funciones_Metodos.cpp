#include "Clases_Funciones.h"
#include <iostream>
#include <string>
#include <random>
#include <stdexcept>  // Para convertir string --> int

using namespace std;

EstacionServicio::EstacionServicio(){  // Constructor de un objeto de la clase EstacionServicio
    nombre = "";
    for (int i = 0; i < 4; i++){ tanqueCentral[i] = 0; }

    for (int i = 0; i < 2; i++){  // Asigna por defecto un valor de ubicación geográfica a una E/S
        ubicacionGeografica[i] = "0";
    }
}

EstacionServicio::~EstacionServicio(){  // Destructor de un objeto de la clase EstacionServicio
    cout << "Estacion de servicio eliminada" << endl;
}

Surtidor::Surtidor(){}  // Constructor de un objeto de la clase Surtidor

Surtidor::~Surtidor(){}  // Destructor de un objeto de la clase Surtidor

RedNacional::RedNacional(){}  // Constructor de un objeto de la clase RedNacional

RedNacional::~RedNacional(){}  // Destructor de un objeto de la clase RedNacional

void Surtidor::setEstado(){  // Permite activar o desactivar el estado de un surtidor
    char _estado;
    cout << "Ingrese uno (1) para activar el surtidor o cero (0) para desactivarlo: "; cin >> _estado;
    while (_estado != '0' && _estado != '1'){  // Verifica que se ingrese una opcion de estado valido
        cout << "Error: no ingreso una opcion de estado valido para el surtidor. Ingrese uno (1) para activar el surtidor o cero (0) para desactivarlo: "; cin >> _estado;
    }
    estado = _estado;
}

void EstacionServicio::setNombre(){  // Permite asignarle un nombre a una E/S
    string _nombre;
    cout << "Ingrese un nombre para la estacion de servicio: "; getline(cin, _nombre);
    nombre = _nombre;
}

string EstacionServicio::getNombre() const{  // Permite obtener el nombre de una E/S, útil a la hora de imprimir una factura
    return nombre;
}

void EstacionServicio::setUbicacionGeografica(){  // Asigna a una E/S su ubicación geográfica
    string coordenadas[2];

    cout << "A continuacion, ingrese la latitud [-12, 12] y luego la longitud [-9, 9] de la estacion de servicio" << endl << endl;
    cout << "    Latitud: "; cin >> coordenadas[0];

    while (stoi(coordenadas[0]) < -12 || stoi(coordenadas[0]) > 12){  // Verifica que el valor de la latitud ingresada sea válido
        cout <<"\nError: desea construir una estacion de servicio fuera del pais. Ingrese un valor para la latitud en el rango [-12, 12]" << endl;
        cout << "    Latitud: "; cin >> coordenadas[0];
    }

    cout << "\n    Longitud: "; cin >> coordenadas[1];
    while (stoi(coordenadas[1]) < -9 || stoi(coordenadas[1]) > 9){  // Verifica que el valor de la longitud ingresada sea válido
        cout <<"\nError: desea construir una estacion de servicio fuera del pais. Ingrese un valor para la latitud en el rango [-9, 9]" << endl;
        cout << "    Longitud: "; cin >> coordenadas[1];
    }

    for (int i = 0; i < 2; i++){
        ubicacionGeografica[i] = coordenadas[i];
    }
}

string* EstacionServicio::getUbicacionGeografica(){  // Consultamos / obtenemos la ubicación geográfica de una E/S
    return ubicacionGeografica;
}

void EstacionServicio::setRegion(){  // Usa el valor de la latitud de la ubicacion geografica para determinar la zona a la que va a pertenecer la E/S
    int latitud = stoi(ubicacionGeografica[0]);  // Guarda el valor de la latitud

    if (4 <= latitud && latitud <= 12){
        region = "Norte";
    } else if (-4 <= latitud && latitud < 4){
        region = "Centro";
    } else {
        region = "Sur";
    }
}

string EstacionServicio::getRegion() const{  // Consulta / obtiene la región de una estación de servicio
    return region;
}

void EstacionServicio::setTanqueCentral(){  // Genera de forma aleatoria la cantidad de cada categoría de combustible en el tanque central
    int cantidadMin = 100, cantidadMax = 200, cantidadAleatoria;

    for (int i = 0; i < 3; i++){
        random_device cantidad;
        mt19937 gen(cantidad());
        uniform_int_distribution<> distrib(cantidadMin, cantidadMax);
        cantidadAleatoria = distrib(gen);
        tanqueCentral[i] = cantidadAleatoria;
    }
}

int* EstacionServicio::getTanqueCentral(){  // Devuelve un puntero al arreglo que almacena la cantidad de combustible del tanque central
    return tanqueCentral;
}







