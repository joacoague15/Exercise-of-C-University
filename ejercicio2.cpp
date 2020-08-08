#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void agregarZonaBebidas (int zona);

int main()
{
	FILE *f;

  //Rubros
  int heladeria = 0, pizzeria = 0, bebidas = 0, parrilla = 0;

  //Ingreso de Datos
    int respuestaZona, respuesta;
    cout << "Ingreso de datos? (1 para si/0 para no): " << endl;
    cin >> respuesta;

    //Vectores para guardar datos de los comercios

		vector <int> zonasBebidas;
    vector <int> zonasHeladeria;
		vector <int> zonasParrilla;
  	vector <int> zonasPizzeria;

		vector <string> nombresBebidas;
    vector <string> nombresHeladeria;
		vector <string> nombresParrilla;
    vector <string> nombresPizzeria;

		//Para saber si estan todos los rubros por zona

  while (respuesta != 0) {
    char nombreComercio[100];
    int rubro;

    cout << "Nombre de comercio:" << endl;
    cin >> nombreComercio;

    cout << "Seleccionar numero de rubro: 1- heladeria, 2- pizzeria, 3- bebidas, 4- parrilla (si excede los 10 en la zona, no se ingresa el dato):" << endl;
    cin >> rubro;

    cout << "Especifique la zona (1 - 6)"<< endl;
    cin >> respuestaZona;

    if (rubro == 1 && heladeria < 10) {
     	nombresHeladeria.push_back(nombreComercio);
			zonasHeladeria.push_back(respuestaZona);
      heladeria++;
    }
    else if (rubro == 2 && pizzeria < 10) {
     	nombresPizzeria.push_back(nombreComercio);
			zonasPizzeria.push_back(respuestaZona);
      pizzeria++;
    }
    else if (rubro == 3 && bebidas < 10) {
    	nombresBebidas.push_back(nombreComercio);
			zonasParrilla.push_back(respuestaZona);
      bebidas++;
			//agregarZonaBebidas(respuestaZona);
    }
    else if (rubro == 4 && parrilla < 10) {
      nombresParrilla.push_back(nombreComercio);
			zonasBebidas.push_back(respuestaZona);
      parrilla++;
    }
    else {
      cout << "El rubro especificado no existe" << endl;
    }
    cout << "Ingreso de datos? (1 para si/0 para no): " << endl;
    cin >> respuesta;
  }

	ofstream Bebidas;
	Bebidas.open("Bebidas.dat",ios::app);
	if (bebidas > 0) {
		for (int i = 0; i < nombresBebidas.size(); i++) {
			Bebidas << "Nombre de comercio: " << nombresBebidas[i] << endl;
			Bebidas << "Zona de comercio: " << zonasBebidas[i] << endl;
	}
			agregarZonaBebidas (respuestaZona);
}
	else {
			Bebidas << "No hay datos disponibles" << endl;
	}

	Bebidas.close();

	ofstream Heladeria;
	Heladeria.open("Heladeria.dat",ios::app);

	if (heladeria > 0) {
  for (int i = 0; i < nombresHeladeria.size(); i++) {
		Heladeria << "Nombre de comercio: "<< nombresHeladeria[i] << endl;
		Heladeria << "Zona de comercio: "<< zonasHeladeria[i] << endl;
  }
}
else {
	Heladeria << "No hay datos disponibles" << endl;
}

	Heladeria.close();

	ofstream Parrilla;
	Parrilla.open("Parrilla.dat",ios::app);

	if (parrilla > 0) {
  for (int i = 0; i < nombresParrilla.size(); i++) {
		Parrilla << "Nombre de comercio: "<< nombresParrilla[i] <<endl;
		Parrilla << "Zona de comercio: " << zonasParrilla[i] <<endl;
	}
}
else {
	Parrilla << "No hay datos disponibles" << endl;
}

	Parrilla.close();

  ofstream Pizzeria;
	Pizzeria.open("Pizzeria.dat",ios::app);

	if (pizzeria > 0) {
  for (int i = 0; i < nombresPizzeria.size(); i++) {
		Pizzeria << "Nombre de comercio: "<< nombresPizzeria[i] << endl;
		Pizzeria << "Zona de comercio: "<< zonasPizzeria[i] << endl;
	}
}
else {
	Pizzeria << "No hay datos disponibles" << endl;
}
	Pizzeria.close();

    return 0;
  }
