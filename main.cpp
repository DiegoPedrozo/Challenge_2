#include <iostream>
#include "Clases_Funciones.h"

using namespace std;

int main(){
    EstacionServicio estacion1;

    estacion1.setUbicacionGeografica();
    string* ubicacion = estacion1.getUbicacionGeografica();

    cout << "Latitud: " << ubicacion[0] << " | " << "Longitud: " << ubicacion[1] << endl << endl;

    /*estacion1.setTanqueCentral();
    int* tanque = estacion1.getTanqueCentral(); */ // Usa esto para obtener una representación del tanque central de la E/S

    return 0;
}
