using namespace std;

template<class tipo_vector>
unsigned long int cocktail(vector<tipo_vector> &v, unsigned modo){

	tipo_vector tp;
	int i,j;
	int inicio = 1;
	int fin = v.size()-1;
	int cam = v.size();
    unsigned long int cp = 0;
    bool intercambio;

    if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar cocktail: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i].DNI_ << endl;
    }

//Recorremos el vector en ambas direcciones ordenando siempre el elemento mayor y menor, cogemos el ultimo elemento de la derecha y lo comparamos con el anterior, si es menor sube, sino, volvemos a comparar 
//el antepenultimo con el siguiente y asi hasta llegar al inicio donde el menor elemento ya estará colocado en su ubicacion final, ahora realizamos el mismo proceso para la derecha, hasta llegar al final
//y colocaremos el elemento mayor en su lugar y repetiremos el proceso desde el inicio para ir colocando siempre un elemento tanto al inicio como al final hasta tener la lista totalmente ordenada.

        intercambio=false;
        
        while(inicio < fin){
   	        for (j=fin; j>=inicio; j--){
                cp++;

                if (modo==0){
                    cout << endl << "Realizo la comparación de las posiciones " << j << " y " << j+1 << endl;
                    cout << j << ". " << v[j-1].DNI_ << endl;
                    cout << j+1 << ". " << v[j].DNI_ << endl;
                }

		        if (v[j].DNI_ < v[j-1].DNI_){

                    if (modo==0)
                    cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " es menor que el de la posicion " << j << ": " << v[j-1].DNI_ << ", " << v[j].DNI_ << " 'sube'." << endl;

			        tp = v[j-1];   
			        v[j-1] = v[j];   
			        v[j] = tp;
		    	    cam = j;
                    intercambio=true;
		       }   
   	        
    		
            else if (modo==0)
                cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " NO es menor que el de la posicion " << j << ": " << v[j-1].DNI_ << ", " << v[j].DNI_ << " no sube." << endl;
   	        }
   	        
            inicio = cam + 1;
            
            for (j=inicio ; j<=fin; j++){
                cp++;
                if (modo==0){
                    cout << endl << "Realizo la comparación de las posiciones " << j << " y " << j+1 << endl;
                    cout << j << ". " << v[j-1].DNI_ << endl;
                    cout << j+1 << ". " << v[j].DNI_ << endl;
                }
    		    if (v[j].DNI_ < v[j-1].DNI_){

                 if (modo==0)
                    cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " es menor que el de la posicion " << j << ": " << v[j-1].DNI_ << ", " << v[j].DNI_ << " 'sube'." << endl;

				tp = v[j-1];   
    			v[j-1] = v[j];   
    			v[j] = tp;
    			cam = j;
                intercambio=true;
    		    }
            else if (modo==0)
                cout << "Como el valor de la posicion " << j+1 << ": " << v[j].DNI_ << " NO es menor que el de la posicion " << j << ": " << v[j-1].DNI_ << ", " << v[j].DNI_ << " no sube." << endl;
            }




            if (modo==0){
                cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i].DNI_ << endl;

                cout << endl << "=============================";
                cin.ignore();
            }
    	
           fin = cam -1; 
        }    
        
            
        

    if (modo==0){
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

    return cp;
}