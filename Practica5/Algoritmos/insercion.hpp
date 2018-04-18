using namespace std;

template<class tipo_vector>
unsigned long int insercion(vector<tipo_vector> &v, unsigned modo){
	
	tipo_vector tp;
	int i,j;
	unsigned long int cp = 0;

	

	for (i=1; i<v.size(); i++){
		
		tp = v[i];
		j = i - 1;

		
		cp++;
		while ((v[j] > tp) && (j >= 0)){
			cp++;
			

       		v[j+1] = v[j];

       		

    	    j--;    	    
    	}

    	

    	v[j+1] = tp;

    	

    		
		}
	


	return cp;
}