#include <iostream>
#ifndef CLASES_FUNCIONES_H
#define CLASES_FUNCIONES_H
using namespace std;
#include <string>
int* precios;
const int numPrecios = 9; // 9 ya que son tres por casa región:)

void asignarPreciosN() {
    precios = new int[numPrecios];
    string zonas[] = {"norte", "centro", "sur"};
    string tipos[] = {"regular", "premium", "Eco Extra"};

    for (int i = 0; i < 3; i++) { // se recorren las zonas
        for (int j = 0; j < 3; j++) { // se recorre los tipos de combustibles
            cout << "precio del combustible " << tipos[j] << " " << zonas[i] << ": ";
            cin >> precios[i * 3 + j];
        }
    }

    cout << "Precios guardados con exito!" << endl;
}

void mostrarPrecios() {
    string zonas[] = {"norte", "centro", "sur"};
    string tipos[] = {"regular", "premium", "Eco Extra"};

    for (int i = 0; i < 3; i++) { // Recorremos las zonas
        for (int j = 0; j < 3; j++) { // Recorremos los tipos de combustibles
            cout << "precio del combustible " << tipos[j] << " " << zonas[i] << ": " << precios[i * 3 + j] << endl;
        }
    }
}
void menu(){
    int p;
    int c = 1;
    while(c!=0){
        cout<< "ingrese lo que va a realizar:"<<endl<<"1.asignar precios."<<endl;
        cout<<"2. salir"<<endl;
        cin>>p;
        if (p==1){
            asignarPreciosN();
        }
        if(p==2){
            delete[]precios;
            cout<<"hasta pronto!!!";
            c=0;
        }
        else{
            cout<<"opcion invalida"<<endl;
        }
    }
}


class Surtidor{
private:
    int codigoIdentificador;  // En serie en un rango [1000, 9999], único para cada surtidor
    int modelo;  // Aleatorio, en un rango [300, 310], suponiendo que existen 11 modelos de máquinas surtidoras

public:

    Surtidor();
    ~Surtidor();

};

class EstacionServicio{
private:
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

int main (){
    menu();
}





#endif // CLASES_FUNCIONES_H
