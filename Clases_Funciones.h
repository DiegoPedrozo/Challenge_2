#ifndef CLASES_FUNCIONES_H
#define CLASES_FUNCIONES_H

#include <string>
using namespace std;

class Surtidor{

    int codigoIdentificador;  // En serie en un rango [1000, 9999], único para cada surtidor
    int modelo;  // Aleatorio, en un rango [300, 310], suponiendo que existen 11 modelos de máquinas surtidoras

public:

    Surtidor();
    ~Surtidor();

};

class EstacionServicio{

    Surtidor surtidor;
    int nombre;
    int codigoIdentificador;
    string gerente;  // ¿Servirá de algo usarlo?
    string region;
    int ubicacionGeografica[2];  // Almacena en la primer entrada la latitud y en la segunda la longitud
    int tanqueCentral[3];  // [0] = cantidad de regular, [1] = cantidad de premium, [2] = cantidad de EcoExtra


public:

    EstacionServicio();
    ~EstacionServicio();

};

class RedNacional{

    EstacionServicio estacionServicio;

public:

    RedNacional();

};





#endif // CLASES_FUNCIONES_H
