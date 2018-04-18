using namespace std;

template<class tipo_vector>
unsigned long int seleccion(vector<tipo_vector> &v, unsigned modo){

	tipo_vector tp;
	unsigned min;//
	unsigned long int cp = 0;//Almacenamos los pasos del algoritmo (comparaciones).

	if (modo==0){//mostramos la secuencia de DNI
        cin.ignore();
        cout << "Secuencia antes de ejecutar seleccion: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i].DNI_ << endl;
    }
//Almacenamos la posicion del valor minimo conocido y la vamos comparando con todas las demas, en el momento en el que encontremos una menor, esa sera la nueva minima y seguiremos comparando con las restantes,
//al llegar al final, la que haya sido minima final, cambiará su posicion con la del minimo inicial y se repetirá el proceso con los restantes.
	for (int i = 0; i < v.size()-1; i++){ 
		min = i;
		for (int j = i+1; j < v.size(); j++){
			cp++;
			
			if (modo==0){
                cout << endl << "Realizo la comparación de las posiciones " << min+1 << " y " << j+1 << endl;
                cout << min+1 << ". " << v[min].DNI_ << endl;
                cout << j+1 << ". " << v[j].DNI_ << endl;
            }

			if (v[j].DNI_ < v[min].DNI_){

				if (modo==0){
					cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " es menor que el de la posicion " << min+1 << ": " << v[min+1].DNI_ << ", ahora la posicion " << j+1 << ": " << v[j].DNI_ << " es el valor minimo." << endl;
				}

				min = j;
			}
		}

		tp = v[min];
		v[min] = v[i];
		v[i] = tp;

		if (modo==0){
			cout << "Intercambio las posiciones " << min+1 << ": " << v[min].DNI_ << " y " << i+1 << ": " << v[i].DNI_ << ". " << endl;
			cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i].DNI_ << endl;

                cout << endl << "=============================";
                cin.ignore();
		}
	}

	if (modo==0){
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }
    
	return cp;
}