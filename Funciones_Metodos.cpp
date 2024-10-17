#include "Clases_Funciones.h"
#include <iostream>
#include <string>
#include <random>
#include <stdexcept>  // Para convertir string --> int

using namespace std;

int Surtidor::proximoCodigoSurtidor = 1000;

int Surtidor::asignarCodigoSurtidor(){
    return proximoCodigoSurtidor++;
}

Surtidor::Surtidor(){}  // Constructor por defecto de la clase Surtidor, usado para crear el arreglo de surtidores

Surtidor::Surtidor(int _codigo) : modelo(0), codigoSurtidor(_codigo), estado(true){} // Constructor de un surtidor, habilitado para dispensar combustible, se asigna código identificador

Surtidor::~Surtidor(){}  // Destructor de un objeto de la clase Surtidor

EstacionServicio::EstacionServicio() : nombre(""), cantidadSurtidores(0){  // Constructor de un objeto de la clase EstacionServicio

    for (int i = 0; i < 4; i++){ tanqueCentral[i] = 0; }

    for (int i = 0; i < 2; i++){  // Asigna por defecto un valor de ubicación geográfica a una E/S
        ubicacionGeografica[i] = "0";
    }
}

EstacionServicio::~EstacionServicio(){  // Destructor de un objeto de la clase EstacionServicio
    //delete[] surtidores;  // Libera del heap el espacio ocupado por el arreglo de surtidores
}

RedNacional::RedNacional(){}  // Constructor de un objeto de la clase RedNacional

RedNacional::~RedNacional(){}  // Destructor de un objeto de la clase RedNacional

void Surtidor::setModelo(){  // Asigna el modelo de un surtidor de forma aletoria en un rango [300, 310]
    int modeloMin = 300, modeloMax = 310, modeloAleatorio;

    random_device num;
    mt19937 gen(num());
    uniform_int_distribution<> distrib(modeloMin, modeloMax);
    modeloAleatorio = distrib(gen);
    modelo = modeloAleatorio;
}

int Surtidor::getModelo(){  // Consulta / obtiene el modelo de un surtidor
    return modelo;
}

int Surtidor::getCodigoSurtidor(){  // Consulta / obtiene el código identificador de un surtidor
    return codigoSurtidor;
}

void Surtidor::setEstado(){  // Permite activar o desactivar el estado de un surtidor
    char _estado;
    cout << "Ingrese uno (1) para activar el surtidor o cero (0) para desactivarlo: "; cin >> _estado;
    while (_estado != '0' && _estado != '1'){  // Verifica que se ingrese una opcion de estado valido
        cout << "Error: no ingreso una opcion de estado valido para el surtidor. Ingrese uno (1) para activar el surtidor o cero (0) para desactivarlo: "; cin >> _estado;
    }
    estado = _estado;
}

bool Surtidor::getEstado(){  // Consulta / obtiene el estado de un surtidor
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
    int codigo = Surtidor::asignarCodigoSurtidor();
    surtidores[cantidadSurtidores] = Surtidor(codigo);
    surtidores[cantidadSurtidores].setModelo();
    cantidadSurtidores++;
}

Surtidor EstacionServicio::getSurtidor(int pos){  // Permite obtener un surtidor en específico del arreglo de surtidores de una E/S
    return surtidores[pos];
}

// ---------------------------------------------------------------------- FUNCIONES -------------------------------------------------------------------------------------

bool verificarCantidadSurtidores(EstacionServicio &estacion){  // Función amiga que verifica que la cantidad de surtidores que contiene una E/S sea válida

    return estacion.getCantidadSurtidores() < 12;

    /*if (estacion.cantidadSurtidores > 11){
        return false;
    } else { return true; }*/
    // Retorna true si se pueden agregar más surtidores o false en caso contrario
}

char option(){  // Retorna una opción para navegar en el menú más externo
    char toDo = 'F';

    do{
        cout << "Ingresa la letra correspondiente segun lo que deseas hacer: " << endl << endl
             << "    (A) Gestionar red nacional" << endl
             << "    (B) Gestionar estaciones de servicio" << endl
             << "    (C) Verificar fugas" << endl
             << "    (D) Simular una venta" << endl
             << "    (E) Salir del sistema    " << endl << endl
             << "Tu opcion: "; cin >> toDo;

        toDo = toupper(toDo);

        if (toDo != 'A' && toDo != 'B' && toDo != 'C' && toDo != 'D' && toDo != 'E'){
            cout << "Ingresaste una opcion invalida. Intenta de nuevo" << endl << endl;
        }

    }while(toDo != 'A' && toDo != 'B' && toDo != 'C' && toDo != 'D' && toDo != 'E');

    return toDo;
}

char opcionGestionarRed(){  // Retorna una opción para navegar sobre el menú para gestionar la red
    char toDo = 'F';

    do{
        cout << "\nGESTIONANDO RED NACIONAL..." << endl << endl;
        cout << "Ingresa la letra correspondiente segun lo que deseas hacer: " << endl << endl
             << "    (A) Agregar estacion de servicio" << endl
             << "    (B) Eliminar estacion de servicio" << endl
             << "    (C) Calcular monto total de ventas" << endl
             << "    (D) Fijar precios del combustible" << endl
             << "    (E) Salir de la gestion de la red" << endl << endl
             << "Tu opcion: "; cin >> toDo;

        toDo = toupper(toDo);

        if (toDo != 'A' && toDo != 'B' && toDo != 'C' && toDo != 'D' && toDo != 'E'){
            cout << "\nIngresaste una opcion invalida. Intenta de nuevo" << endl;
        }

    }while(toDo != 'A' && toDo != 'B' && toDo != 'C' && toDo != 'D' && toDo != 'E');

    return toDo;
}








