#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ordenamientoIntercambio(vector<int> &v, int &nIntercambios, int &nComparaciones){
  // Recorremos la lista desde el inicio hasta el penúltimo elemento
  for(int i = 0; i < v.size()-1; i++) { 
    // Recorremos la lista desde el siguiente elemento hasta el final 
    for(int j=i+1; j < v.size(); j++){
      // Si el elemento actual (i) es mayor que el elemento (j), intercambiamos
      int aux;
      nComparaciones++;
      if(v[i] > v[j]){
        // Hacemos el intercambio
        aux = v[j];
        v[j] = v[i];
        v[i] = aux;
        nIntercambios++;
      }
    }
  }
}

// Ordenar un vector int usando ordenamiento de burbuja
void ordenamientoBurbuja(vector<int> &v, int &nIntercambios, int &nComparaciones){
  int aux;
  for (int i = 0; i < v.size() - 1; i++) { // Recorre el vector desde el primer elemento hasta el penultimo
    for (int j = 0; j < v.size() - 1 - i; j++) { // Recorre el vector desde el primer elemento hasta el penultimo
      nComparaciones++;
      if (v[j] > v[j + 1]) { // Si el elemento de la posicion j es mayor que el elemento de la posicion j + 1 se intercambian
        aux = v[j]; // Se guarda el valor de la posicion j
        v[j] = v[j + 1]; // Se guarda el valor de la posicion j + 1 en la posicion j
        v[j + 1] = aux; // Se guarda el valor de la posicion j en la posicion j + 1
        nIntercambios++; // Se incrementa el contador de intercambios
      }
    }
  }
}

void merge(vector<int> &v, int inicio, int medio, int fin) {
    // creamos un vector auxiliar
    vector<int> temp(fin - inicio + 1);

    // variables punteros para los intervalos y para el vector auxiliar
	int i = inicio, j = medio+1, k = 0;

    // recorre ambos intervalos y en cada iteracion agrega el menor de los dos elementos en el vector auxiliar
	while(i <= medio && j <= fin) { // mientras no se hayan terminado los intervalos
		if(v[i] <= v[j]) { // si el elemento de v[i] es menor o igual al de v[j]
			temp[k] = v[i]; // agrega el elemento de v[i] en el vector auxiliar
			k += 1; i += 1; // incrementa el puntero de v[i] y el puntero de temp
		} 
		else { // si el elemento de v[i] es mayor al de v[j]
			temp[k] = v[j]; // agrega el elemento de v[j] en el vector auxiliar
			k += 1; j += 1; // incrementa el puntero de v[j] y el puntero de temp
		}
	}

    // agrega los elementos que quedaron en el primer intervalo
	while(i <= medio) { // mientras no se hayan terminado los intervalos
		temp[k] = v[i]; // agrega el elemento de v[i] en el vector auxiliar
		k += 1; i += 1; // incrementa el puntero de v[i] y el puntero de temp
	}

    // agrega los elementos que quedaron en el segundo intervalo
	while(j <= fin) { // mientras no se hayan terminado los intervalos
		temp[k] = v[j]; // agrega el elemento de v[j] en el vector auxiliar
		k += 1; j += 1; // incrementa el puntero de v[j] y el puntero de temp
	}

    // copia el vector auxiliar al intervalo original
	for(i = inicio; i <= fin; i += 1) { // mientras no se hayan terminado los intervalos
		v[i] = temp[i - inicio] ; // agrega el elemento de temp en v[i]
	}
}

// Arr es un arreglo de tipo entero
// start y end son los indices de inicio y fin del intervalo actual de Arr
void mergeSort(vector<int> &v , int inicio, int fin) { // funcion que recibe un vector de tipo entero y un intervalo de inicio y fin
	if(inicio < fin) { // si el intervalo de inicio y fin es mayor a 0
		int medio = (inicio + fin) / 2; // calcula el punto medio del intervalo
		mergeSort(v, inicio, medio); // llama a la funcion mergeSort con el intervalo de inicio y medio
		mergeSort(v, medio+1, fin); // llama a la funcion mergeSort con el intervalo de medio+1 y fin
		merge(v, inicio, medio, fin); // llama a la funcion merge con el intervalo de inicio y fin
	}
}

// ---- Algoritmos de Busqueda ----

int busquedaSecuencial(vector<int> v, int valor) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == valor) { // Si encuentra el valor
      return i; // Retorna la posicion
    }
  }
  return -1; // Si no encuentra el valor
}

int busquedaBinaria(vector<int> v, int valor) {
  int left = 0;
  int right = v.size() - 1;
  int mid;
  while (left <= right) {
    // Calcular el punto medio
    mid = (left + right) / 2; // mid es igual a la mitad de left y right
    // Valida si el dato es igual al dato de en medio
    if (v[mid] == valor) {
      // Retorna la posicion de en medio
      return mid;
    } else {
      // Valida si el dato es menor al dato de en medio
      if (valor < v[mid]) {
        // Cambia el limite derecho
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return -1;
}

void mostrarVector(vector<int> &v){
  for(int i=0; i < v.size(); i++){
    cout << "v[" << i << "] = " << v[i] << endl;
  }
}

int main() {
  
  vector<int> numeros = {10,4,8,12,20,15,54,28,5,4,7,8,2,1,5,9,8,4,2,0,10,25,4,85,72,91,20,0,35,66};

  int nIntercambios=0, nComparaciones=0;
  //Odenamiento intercambio
  cout << "-------Antes-------" << endl;
  mostrarVector(numeros);
  ordenamientoIntercambio(numeros, nIntercambios, nComparaciones);
  cout << "------Despues------" << endl;
  mostrarVector(numeros);
  cout << "-------------------" << endl;
  cout << "Compraciones: " << nComparaciones << endl;
  cout << "Intercambios: " << nIntercambios << endl;

  vector<int> numerosOrd = {0,2,3,4,5,6,7,8,9};

  return 0;
} 