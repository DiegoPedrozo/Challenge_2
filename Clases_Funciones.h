#ifndef CLASES_FUNCIONES_H
#define CLASES_FUNCIONES_H

#include <string>
using namespace std;

class Surtidor{

    int modelo;  // Aleatorio, en un rango [300, 310], suponiendo que existen 11 modelos de máquinas surtidoras
    int codigoSurtidor;  // En serie, en un rango [1000, 9999], único para cada surtidor
    bool estado;  // Para determinar si un surtidor puede dispensar o no combustible

    static int proximoCodigoSurtidor;  // En serie en un rango [1000, 9999], único para cada surtidor, por eso es estático

public:

    int getCodigoSurtidor();  // Consulta / obtiene el código identificador de un surtidor

    void setEstado();  // Modifica el estado de un surtidor de una E/S
    bool getEstado();  // Consulta / obtiene el estado de un surtidor

    Surtidor();  // Constructor por defecto de una instancia de la clase Surtidor, usado para crear el arreglo de surtidores
    Surtidor(int _codigo);  // Constructor con código como parámetro, cuando se crea un nuevo surtidor
    ~Surtidor();

    static int asignarCodigoSurtidor();  // Al momento de crear un surtidor, la función le asigna un código único al mismo

};

class EstacionServicio{

    //string gerente;  // ¿Servirá de algo usarlo?
    string nombre;
    string ubicacionGeografica[2];  // Almacena en la primer entrada la latitud y en la segunda la longitud de una E/S
    string region;  // Se usa para determinar el precio del combustible según la ubicacion geográfica de la E/S
    int codigoEstacion;  // En serie, en un rango [100, 999], único para cada E/S
    int tanqueCentral[3];  // [0] = cantidad de regular, [1] = cantidad de premium, [2] = cantidad de EcoExtra

    Surtidor surtidores[12];  // Arreglo de surtidores, máximo 12 por E/S
    int cantidadSurtidores;  // Lleva la cuenta de la cantidad de surtidores que tiene una E/S

public:

    EstacionServicio();
    ~EstacionServicio();

    void setNombre();  // Permite asignarle un nombre a una E/S
    string getNombre() const;  // Permite obtener el nombre de una E/S, útil a la hora de imprimir una factura

    void setUbicacionGeografica();  // Asigna a una E/S su ubicación geográfica
    string* getUbicacionGeografica();  // --> Revisar si es mejor que la ubicación geográfica sea un atributo de la red nacional

    void setRegion();  // Usa el valor de la latitud de la ubicacion geografica para determinar la zona a la que va a pertenecer la E/S
    string getRegion() const;  // Consulta / obtiene la región de una estación de servicio

    void setCodigoEstacion();  // Le asigna a cada E/S un código único

    void setTanqueCentral();  // Para asignarle una cantidad de combustible al tanque central
    int* getTanqueCentral();  // Devuelve un puntero al arreglo que almacena la cantidad de combustible del tanque central

    int getCantidadSurtidores();  // Consulta / obtiene la cantidad de surtidores que posee una E/S
    Surtidor getSurtidor(int pos);  // Permite obtener un surtidor en específico del arreglo de surtidores de una E/S

    void crearSurtidor();  // Permite crear un surtidor para una estación de servicio determinada

    friend bool verificarCantidadSurtidores(EstacionServicio &estacion);  // Función amiga que verifica que la cantidad de surtidores que contiene una E/S sea válida

};

class RedNacional{

    EstacionServicio estacionServicio;

    int cantidadEstaciones = 0;
    int precios[9];  // Contiene los precios del combustible de las estaciones de servicio de la red nacional

public:

    RedNacional();
    ~RedNacional();

};

// ---------------------------------------------------------------------- FUNCIONES -------------------------------------------------------------------------------------

bool verificarCantidadSurtidores(const EstacionServicio &estacion);  // Verifica que la cantidad de surtidores que puede contener una E/S sea válida

#endif // CLASES_FUNCIONES_H
