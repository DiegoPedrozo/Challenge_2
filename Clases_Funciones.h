#ifndef CLASES_FUNCIONES_H
#define CLASES_FUNCIONES_H

#include <string>
using namespace std;

class Surtidor{

    int codigoIdentificador;  // En serie en un rango [1000, 9999], único para cada surtidor
    int modelo;  // Aleatorio, en un rango [300, 310], suponiendo que existen 11 modelos de máquinas surtidoras
    bool estado;

public:

    void setEstado();  // Modifica el estado de un surtidor de una E/S
    bool getEstado();  // Consulta / obtiene el estado de un surtidor

    Surtidor();
    ~Surtidor();

};

class EstacionServicio{

    Surtidor surtidor;
    //string gerente;  // ¿Servirá de algo usarlo?
    string nombre;
    string ubicacionGeografica[2];  // Almacena en la primer entrada la latitud y en la segunda la longitud de una E/S
    string region;  // Se usa para determinar el precio del combustible según la ubicacion geográfica de la E/S
    int codigoIdentificador;  // En serie, en un rango [100, 999], único para cada E/S
    int tanqueCentral[3];  // [0] = cantidad de regular, [1] = cantidad de premium, [2] = cantidad de EcoExtra

public:

    EstacionServicio();
    ~EstacionServicio();

    void setNombre();  // Permite asignarle un nombre a una E/S
    string getNombre() const;  // Permite obtener el nombre de una E/S, útil a la hora de imprimir una factura

    void setUbicacionGeografica();  // Asigna a una E/S su ubicación geográfica
    string* getUbicacionGeografica();  // --> Revisar si es mejor que la ubicación geográfica sea un atributo de la red nacional

    void setRegion();  // Usa el valor de la latitud de la ubicacion geografica para determinar la zona a la que va a pertenecer la E/S
    string getRegion() const;  // Consulta / obtiene la región de una estación de servicio

    void setCodigoIdentificador();  // Le asigna a cada E/S un código único

    void setTanqueCentral();  // Para asignarle una cantidad de combustible al tanque central
    int* getTanqueCentral();  // Devuelve un puntero al arreglo que almacena la cantidad de combustible del tanque central
};

class RedNacional{

    EstacionServicio estacionServicio;
    int precios[9];  // Contiene los precios del combustible de las estaciones de servicio de la red nacional

public:

    RedNacional();
    ~RedNacional();

};

#endif // CLASES_FUNCIONES_H
