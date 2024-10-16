#include "Clases_Funciones.h"
#include <iostream>
#include <string>
#include <random>
#include <stdexcept>  // Para convertir string --> int

using namespace std;

EstacionServicio::EstacionServicio() : nombre(""), cantidadSurtidores(0){  // Constructor de un objeto de la clase EstacionServicio
    for (int i = 0; i < 4; i++){ tanqueCentral[i] = 0; }

    for (int i = 0; i < 2; i++){  // Asigna por defecto un valor de ubicación geográfica a una E/S
        ubicacionGeografica[i] = "0";
    }
}

EstacionServicio::~EstacionServicio(){  // Destructor de un objeto de la clase EstacionServicio
    //delete[] surtidores;  // Libera del heap el espacio ocupado por el arreglo de surtidores
}

Surtidor::Surtidor(){}  // Constructor por defecto de una instancia de la clase Surtidor

Surtidor::Surtidor(int _codigo) : codigoIdentificador(_codigo), estado(true){}  // Constructor de un surtidor, donde por defecto está habilitado para dispensar combustible

Surtidor::~Surtidor(){}  // Destructor de un objeto de la clase Surtidor

RedNacional::RedNacional(){}  // Constructor de un objeto de la clase RedNacional

RedNacional::~RedNacional(){}  // Destructor de un objeto de la clase RedNacional

int Surtidor::getCodigoIdentificador(){  // Consulta / obtiene el código identificador de un surtidor
    return codigoIdentificador;
}

void Surtidor::setEstado(){  // Permite activar o desactivar el estado de un surtidor
    char _estado;
    cout << "Ingrese uno (1) para activar el surtidor o cero (0) para desactivarlo: "; cin >> _estado;
    while (_estado != '0' && _estado != '1'){  // Verifica que se ingrese una opcion de estado valido
        cout << "Error: no ingreso una opcion de estado valido para el surtidor. Ingrese uno (1) para activar el surtidor o cero (0) para desactivarlo: "; cin >> _estado;
    }
    estado = _estado;
}

bool Surtidor::getEstado(){
    return estado;
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

int EstacionServicio::getCantidadSurtidores(){  // Consulta / obtiene la cantidad de surtidores de una estación de servicio
    return cantidadSurtidores;
}

void EstacionServicio::crearSurtidor(){  // Permite crear un surtidor para una estación de servicio determinada
    Surtidor surtidor;
    int codigo = asignarCodigoSurtidor(surtidor);
    surtidores[cantidadSurtidores] = surtidor;
    cantidadSurtidores++;
}

int RedNacional::asignarCodigoSurtidor(){  // Al momento de crear un surtidor, le asigna un código único y le suma uno al código identificador
    codigoSurtidor += 1;
    return codigoSurtidor;
}

// ---------------------------------------------------------------------- FUNCIONES -------------------------------------------------------------------------------------

bool verificarCantidadSurtidores(const EstacionServicio &estacion){  // Función amiga que verifica que la cantidad de surtidores que contiene una E/S sea válida
    if (estacion.cantidadSurtidores > 11){
        return false;
    } else { return true; }
    // Retorna true si se pueden agregar más surtidores o false en caso contrario
}

int asignarCodigoSurtidor(const RedNacional& estacion, const Surtidor& estacion){  // Al momento de crear un surtidor, la función amiga le asigna un código único al mismo
    surtidor.codigoIdentificador
}







