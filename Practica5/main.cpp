//Compilar usando g++ -std=c++11 main.cpp DNI.cpp

#include "common.hpp"
#include "DNI.hpp"
#include "Algoritmos/cocktailsort.hpp"
#include "Algoritmos/seleccion.hpp"
#include "Algoritmos/quicksort.hpp"
#include "Algoritmos/mergesort.hpp"
#include "Algoritmos/shellsort.hpp"
#include "Algoritmos/insercion.hpp"
#include "Algoritmos/burbuja.hpp"

#define cantidad_algoritmos 6

using namespace std;


//Metodo para llevar a cabo el control de errores a la hora de elegir el modo y el algoritmo de ejecución en el programa.
void error(void){
	cin.ignore();
	cout << endl << "La opcion introducida no es valida. Presione enter e introduzca otra.";
	cin.ignore();
	
}


void calcular_cp(vector<float> &com, vector<vector<float>> &v, float sm, unsigned int num_alg){
	
	insercion<float>(com,1);

	v[num_alg][0] = com.front(); //Primer elemento en el vector para el minimo
	v[num_alg][1] = (sm/com.size()); //La media.
	v[num_alg][2] = com.back(); //Ultimo elemento en el vector para el maximo
}

//Metodo que recibe el vector y crea los DNI llamando a set_random()
void randomizar(vector<DNI> &v){
	
	for (int i=0;i<v.size();i++)
	
		v[i].set_random();
}


int main (void){
	
	srand(time(NULL));

	unsigned opc = 2;
	int ct_pruebas = 300;
	unsigned alg_ejecutar = 100;
	int tam_secuencia, num_rep;

	while (opc != 0 && opc != 1){
		cout << "================ " << "ORDENACION" << " =================" << endl;
		cout << "Seleccione el modo con el que desea trabajar: " << endl;
		cout << "0. Modo demostración" << endl;
		cout << "1. Modo estadisticas" << endl;
		cout << "Introduzca una opcion: ";
		cin >> opc;//Conseguimos y guardamos el Modo de trabajo seleccionado.
		if (opc != 0 && opc != 1)
			error();
	}

	if (opc==0){
		while (!(alg_ejecutar>=0 && alg_ejecutar<=(cantidad_algoritmos-1))){ 
			write(1,"\033[H\033[2J",7);
			cout << "============= " << "MODO DEMOSTRACIÓN" << " =============" << endl;
			cout << "Introduzca el tamaño de la secuencia: ";
			cin >> ct_pruebas; //Conseguimos y guardamos el tamaño del banco de pruebas que vamos a usar.
			cout << "Seleccione el algoritmo que quiere probar: " << endl;
			cout << "0. Algoritmo Cocktail" << endl;
			cout << "1. Algoritmo MergeSort" << endl;
			cout << "2. Algoritmo QuickSort" << endl;
			cout << "3. Algoritmo Seleccion" << endl;
			cout << "4. Algoritmo ShellSort" << endl;
			cout << "5. Algoritmo Burbuja" << endl;
			cout << "Introduzca una opcion: ";
			cin >> alg_ejecutar;//Conseguimos y guardamos el algoritmo que vamos a usar.
			if (!(alg_ejecutar>=0 && alg_ejecutar<=(cantidad_algoritmos-1)))
				error();
		}
		vector<DNI> vector_DNI(ct_pruebas); //Creamos el vector que contendrá los DNI y que será del tamaño del banco de pruebas.
		
		switch (alg_ejecutar){
			case 0:{//Algoritmo Cocktail, randomizamos el vector creando todos los DNI y llamamos al algoritmo en cuestión.
			
				cout << "=========== " << "DEMOSTRACIÓN COCKTAIL" << " ============" << endl;
				randomizar(vector_DNI);

				cocktail<DNI>(vector_DNI,0);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
				break;
			}
			
			case 1:{//Algoritmo MergeSort, randomizamos el vector creando todos los DNI y llamamos al algoritmo en cuestión.
				
				cout << "========== " << "DEMOSTRACIÓN MERGESORT" << " ===========" << endl;
				
				randomizar(vector_DNI);
						
						for(int j = 0; j < 9; j++){
							cout << vector_DNI[4].DNI_[j];
						}
							cout << endl;
					
					
						mergesort<DNI>(vector_DNI,0);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.

				break;
			}
			case 2:{//Algoritmo QuickSort, randomizamos el vector creando todos los DNI y llamamos al algoritmo en cuestión.
				
				cout << "========== " << "DEMOSTRACIÓN QUICKSORT" << " ===========" << endl;
				randomizar(vector_DNI);

				quicksort<DNI>(vector_DNI,0);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
				break;
			}
			case 3:{//Algoritmo Seleccion, randomizamos el vector creando todos los DNI y llamamos al algoritmo en cuestión.
			
				cout << "========== " << "DEMOSTRACIÓN SELECCION" << " ===========" << endl;
				randomizar(vector_DNI);

				seleccion<DNI>(vector_DNI,0);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
				break;
			}
			case 4:{//Algoritmo ShellSort, randomizamos el vector creando todos los DNI y llamamos al algoritmo en cuestión.
				
				cout << "========== " << "DEMOSTRACIÓN SHELLSORT" << " ===========" << endl;
				randomizar(vector_DNI);

				shellsort<DNI>(vector_DNI,0);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
				break;
			}
			case 5:{//Algoritmo Burbuja, randomizamos el vector creando todos los DNI y llamamos al algoritmo en cuestión.
				
				cout << "========== " << "DEMOSTRACIÓN BURBUJA" << " ===========" << endl;
				randomizar(vector_DNI);

				burbuja<DNI>(vector_DNI,0);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
				break;
			}

		}
	}
	else{
		
		cout << "============= " << "MODO ESTADÍSTICA" << " =============" << endl;
		cout << "Introduzca el tamaño de la secuencia a analizar: ";
		cin >> tam_secuencia; //Conseguimos el tamaño del banco de pruebas y lo guardamos.
		cout << "Introduzca la cantidad de veces que quiera que se repitan las pruebas: ";
		cin >> num_rep;//Conseguimos el numero de repeticiones que tendrán los algoritmos y lo guardamos.
		cout << endl << "                               NUMERO DE COMPARACIONES" << endl;
		cout << "                            Minimo -  Promedio  -   Maximo" << endl;

		vector<DNI> vector_DNI(tam_secuencia);//Creamos el banco de pruebas.
		vector<vector<float>> resultados(cantidad_algoritmos, vector<float>(3));//creamos el vector para almacenar los resultados, minimo, medio y maximo.
		vector<float> comp(num_rep);//creamos el vector de comparaciones.
		float suma = 0;//Creamos el sumados para cuantificarlas.

		for (int i=0; i<cantidad_algoritmos; i++){
			switch (i){
				case 0:{//Metodo del CockTail,
					//Cada vez que llamamos al metodo con el diferente numero de repeticiones que vayamos a hacer guardamos el numero de pasos(comparaciones) que realiza en un vector que luego será sumado y utilizado
					//para conocer los resultados finales del estudio de cada algoritmo.
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_DNI.size();k++)
							vector_DNI[k].set_random();
						comp[j] = cocktail<DNI>(vector_DNI,1);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
						suma += comp[j];
					}

					calcular_cp(comp, resultados, suma, 0);

					cout << "Método del Cocktail: " << setw(12) << resultados[0][0] << setw(12) << resultados[0][1] << setw(12) << resultados[0][2] << endl;//Mostramos por pantalla los resultados para este algoritmo.
					suma=0;//Volvemos a poner a cero las sumas de las comparaciones.
					break;
				}

				case 1:{//Metodo del MergeSort
					//Cada vez que llamamos al metodo con el diferente numero de repeticiones que vayamos a hacer guardamos el numero de pasos(comparaciones) que realiza en un vector que luego será sumado y utilizado
					//para conocer los resultados finales del estudio de cada algoritmo.
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_DNI.size();k++)
							vector_DNI[k].set_random();
						comp[j] = mergesort<DNI>(vector_DNI,1);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 1);

					cout << "Método de mergesort:  " << setw(12) << resultados[1][0] << setw(12) << resultados[1][1] << setw(12) << resultados[1][2] << endl;//Mostramos por pantalla los resultados para este algoritmo.
					suma=0;//Volvemos a poner a cero las sumas de las comparaciones.
					break;
				}

				case 2:{//Metodo del QuickSort
					//Cada vez que llamamos al metodo con el diferente numero de repeticiones que vayamos a hacer guardamos el numero de pasos(comparaciones) que realiza en un vector que luego será sumado y utilizado
					//para conocer los resultados finales del estudio de cada algoritmo.
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_DNI.size();k++)
							vector_DNI[k].set_random();
						comp[j] = quicksort<DNI>(vector_DNI,1);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
						suma += comp[j];

					}
					
					calcular_cp(comp, resultados, suma, 2);

					cout << "Método de quicksort:  " << setw(12) << resultados[2][0] << setw(12) << resultados[2][1] << setw(12) << resultados[2][2] << endl;//Mostramos por pantalla los resultados para este algoritmo.
					suma=0;//Volvemos a poner a cero las sumas de las comparaciones.
					break;
				}

				case 3:{//Metodo de Seleccion
					//Cada vez que llamamos al metodo con el diferente numero de repeticiones que vayamos a hacer guardamos el numero de pasos(comparaciones) que realiza en un vector que luego será sumado y utilizado
					//para conocer los resultados finales del estudio de cada algoritmo.
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_DNI.size();k++)
							vector_DNI[k].set_random();
						comp[j] = seleccion<DNI>(vector_DNI,1);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 3);

					cout << "Método de seleccion:  " << setw(12) << resultados[3][0] << setw(12) << resultados[3][1] << setw(12) << resultados[3][2] << endl;//Mostramos por pantalla los resultados para este algoritmo.
					suma=0;//Volvemos a poner a cero las sumas de las comparaciones.
					break;
				}

				case 4:{//Metodo del ShellSort
					//Cada vez que llamamos al metodo con el diferente numero de repeticiones que vayamos a hacer guardamos el numero de pasos(comparaciones) que realiza en un vector que luego será sumado y utilizado
					//para conocer los resultados finales del estudio de cada algoritmo.
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_DNI.size();k++)
							vector_DNI[k].set_random();
						comp[j] = shellsort<DNI>(vector_DNI,1);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 4);

					cout << "Método de shellsort:  " << setw(12) << resultados[4][0] << setw(12) << resultados[4][1] << setw(12) << resultados[4][2] << endl;//Mostramos por pantalla los resultados para este algoritmo.
					suma=0;//Volvemos a poner a cero las sumas de las comparaciones.
					break;
				}
				case 5:{//Metodo Burbuja.
					//Cada vez que llamamos al metodo con el diferente numero de repeticiones que vayamos a hacer guardamos el numero de pasos(comparaciones) que realiza en un vector que luego será sumado y utilizado
					//para conocer los resultados finales del estudio de cada algoritmo.
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_DNI.size();k++)
							vector_DNI[k].set_random();
						comp[j] = burbuja<DNI>(vector_DNI,1);//Llamamos al algoritmo pasandole por parametros el vector de DNIs y el modo de ejecucion elegido.
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 5);

					cout << "Método de burbuja:  " << setw(12) << resultados[5][0] << setw(12) << resultados[5][1] << setw(12) << resultados[5][2] << endl;//Mostramos por pantalla los resultados para este algoritmo.
					suma=0;//Volvemos a poner a cero las sumas de las comparaciones.
					break;
				}
			}
		}
	}
}