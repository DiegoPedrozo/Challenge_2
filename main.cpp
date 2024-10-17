#include <iostream>
#include "Clases_Funciones.h"

using namespace std;

int main(){

    RedNacional redNacional;
    EstacionServicio estacion;

    while (verificarCantidadSurtidores(estacion)){
        estacion.crearSurtidor();
    }

    cout << "Los codigos de los surtidores son: ";
    for (int i = 0; i < estacion.getCantidadSurtidores(); i++){
        cout << estacion.getSurtidor(i).getCodigoSurtidor() << " | ";
    }

    //string* ubicacion = estacion1.getUbicacionGeografica();

    /*estacion1.setTanqueCentral();
    int* tanque = estacion1.getTanqueCentral(); */ // Usa esto para obtener una representación del tanque central de la E/S

    return 0;
}
