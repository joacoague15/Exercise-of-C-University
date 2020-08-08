#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
vector<string> nombresOrdenados;
string nombre3 = "Zaira";
string nombre1 = "Helena";
string nombre2 = "Alberto";

nombresOrdenados.push_back(nombre3);
nombresOrdenados.push_back(nombre1);
nombresOrdenados.push_back(nombre2);

  sort(nombresOrdenados.begin(), nombresOrdenados.end());

  for (int i=0; i < nombresOrdenados.size(); i++) {
    cout << nombresOrdenados.at(i) << endl;
  }
}
