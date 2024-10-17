#include <iostream>
#include "Clases_Funciones.h"

using namespace std;

int main(){

    cout << "| ------------------------------ BIENVENIDO A TERMAX ------------------------------- |" << endl << endl;
    RedNacional redNacional;
    bool out = false;

    while (out == false){
        char toDo = option();  // Retorna opciones para navegar en el menú más externo

        switch (toDo){
            case 'A':{  // Gestionar red nacional
                char toDoA = opcionGestionarRed();
                switch (toDoA){
                    case 'A':{  // Agregar estacion de servicio
                        break;
                    }
                    case 'B':{  // Eliminar estacion de servicio
                        break;
                    }
                    case 'C':{  // Calcular monto total de ventas
                        break;
                    }
                    case 'D':{  // Fijar precios combustible
                        break;
                    }
                    case 'E':{  // Salir de la gestion de la red
                        cout << "\n...FIN DE GESTION DE LA RED\n\n";
                        break;
                    }
                }
                break;
            }
            case 'B':{  // Gestionar estaciones de servicio
                break;
            }
            case 'C':{  // Verificar fugas
                break;
            }
            case 'D':{  // Simular una venta
                break;
            }
            case 'E':{  // Salir del sistema
                out = true;
                break;
            }
            default:
                break;
        }
    }
    cout << "\n| ----------------------------------- HASTA LUEGO ---------------------------------- |" << endl << endl;


    //string* ubicacion = estacion1.getUbicacionGeografica();

    /*estacion1.setTanqueCentral();
    int* tanque = estacion1.getTanqueCentral(); */ // Usa esto para obtener una representación del tanque central de la E/S

    return 0;
}
