#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main() {
    vector<string> nombres;
    vector<string> ciudades;
    vector<int> dias, meses, anos;

    char opcion;
    do {
        string nombre, ciudad;
        int dia;
		int mes;
		int ano;

        cout << "Ingrese datos personales" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        nombres.push_back(nombre);

        cout << "Ciudad: ";
        cin >> ciudad;
        ciudades.push_back(ciudad);

        cout << "Fecha de nacimiento ";
        cout << "\nIngresa dia de ancimiento: ";
        cin >> dia;
        cout << "Ingresa mes de ancimiento: ";
		cin >> mes;
	    cout << "Ingresa year de ancimiento: ";	
		cin >> ano;
        dias.push_back(dia);
        meses.push_back(mes);
        anos.push_back(ano);

        cout << "¿Desea ingresar los datos de otra persona? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    cout << "\nRegistro completo. Detalles de las personas:" << endl;
    for (size_t i = 0; i < nombres.size(); ++i) {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << "Nombre: " << nombres[i] << endl;
        cout << "Ciudad: " << ciudades[i] << endl;
        cout << "Fecha de nacimiento: " << dias[i] << "/" << meses[i] << "/" << anos[i] << endl;

        
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        int anoActual = 1900 + timePtr->tm_year;
        int mesActual = 1 + timePtr->tm_mon;
        int diaActual = timePtr->tm_mday;

        int edad = anoActual - anos[i];
        if (mesActual < meses[i] || (mesActual == meses[i] && diaActual < dias[i])) {
            edad--;
        }
        cout << "¿Es mayor de edad? " << (edad >= 18 ? "Si" : "No") << endl;
        cout << endl;
    }

    return 0;
}
