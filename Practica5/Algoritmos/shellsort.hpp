using namespace std;

template<class tipo_vector>
unsigned long int shellsort(vector<tipo_vector> &v, unsigned modo){
	unsigned long int cp=0;//contabilizamos el numero de pasos (comparaciones), que realiza el algoritmo antes de terminar de ordenar la lista.

	if (modo==0){//Mostramos la secuencia de DNI por pantalla.
        cin.ignore();
        cout << "Secuencia antes de ejecutar shellsort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i].DNI_ << endl;
        cout << endl;
    }

    double alpha=0;

    if(modo==0){//Introducimos el Alpha para este algoritmo. por defecto si no introducimos nada tomo alpha = 0,5
		while(alpha >= 1 || alpha <= 0){
			cout << "Introduzca un alpha entre 0 y 1: ";
			cin >> alpha;
			cin.ignore();
		}
	}
	else
		alpha = 0.5;

	int delta = v.size();
	tipo_vector tp;
//conseguimos el delta dependiendo del tamaño de la lista, para usarlo con el alpha y determinar en cuantas "columnas" vamos a dividir la lista para comenzar a realizar la ordenacion con este algoritmo
//el delta se actualiza cuando las primeras n columnas que dividimos estan ordenadas y sigue ejecutandose hasta ordenar completamente la lista.
	while(delta > 1){
		delta = delta * alpha;
		
		for(unsigned i = delta; i<v.size(); i++){
			tipo_vector x = v[i];
			unsigned j = i;
			cp++;
			while((j >= delta) && (x.DNI_ < v[j-delta].DNI_)){

				if (modo==0){
					cout << "Con alpha: " << alpha << " el delta ahora vale: " << delta << endl;
					cout << "Como el valor de la posicion " << i+1 << ": " << v[i].DNI_ << " es menor que el de la posicion " << (j-delta)+1 << ": " << v[j-delta].DNI_ << " intercambiamos y decrementamos delta." << endl;
					cin.ignore();
				}

				v[j] = v[j-delta];
				j = j - delta;
				cp++;
			}
			v[j] = x;

			if (modo==0){
                cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i].DNI_ << endl;

                cout << endl << "=============================";
                cin.ignore();
            }
		}
		
	}

	if (modo==0){
        cout << endl << "Secuencia tras el ejecutar shellsort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i].DNI_ << endl;
        cout << endl << "=============================" << endl;
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

	return cp; //Devolvemos el numero de comparaciones.
}