using namespace std;

template<class tipo_vector>
unsigned long int burbuja(vector<tipo_vector> &v, unsigned modo){

	tipo_vector tp;
	int i,j;
    unsigned long int cp = 0;
    bool intercambio;

//realizamos comparaciones directas entre dos DNI, vamos de derecha a izquierda comprobando si el qeu tenemos guardado es menor que el anterior o no, si es menor, se intercambia, y seguimos, si es mayor
//cambiamos el guardado al menor y seguimos comparando hasta llegar al inicio.

    if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar burbuja: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i].DNI_ << endl;
    }

	for (i=0; i<v.size(); i++){
        intercambio=false;
   		for (j= v.size()-1 ; j>i; j--){
            cp++;

            if (modo==0){
                cout << endl << "Realizo la comparación de las posiciones " << j << " y " << j+1 << endl;
                cout << j << ". " << v[j-1].DNI_ << endl;
                cout << j+1 << ". " << v[j].DNI_ << endl;
            }

    		if (v[j].DNI_ < v[j-1].DNI_){

                 if (modo==0)
                    cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " es menor que el de la posicion " << j << ": " << v[j-1].DNI_ << ", " << v[j].DNI_ << " 'sube'." << endl;

				tp = v[j];   
    			v[j] = v[j-1];   
    			v[j-1] = tp;
                intercambio=true;
    		}
            else if (modo==0)
                cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " NO es menor que el de la posicion " << j << ": " << v[j-1].DNI_ << ", " << v[j].DNI_ << " no sube." << endl;

            if (modo==0){
                cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i].DNI_ << endl;

                cout << endl << "=============================";
                cin.ignore();
            }
    	}
        if(!intercambio){
            if (modo==0)
                cout << "No ha ocurrido ningún cambio. Se termina la ejecución." << endl;
            break;
        }
    }

    if (modo==0){
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

    return cp;
}