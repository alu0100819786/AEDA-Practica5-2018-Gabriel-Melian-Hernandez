#include "DNI.hpp"
//Constructor por defecto que crea un DNI con todos sus valores a "0".
DNI::DNI (void):
DNI_("000000000")
{
    for (int i = 0; i < 9; i++) {
        DNI_[i] = 0;
    }
}

//Constructor que recibe un string por parametros y crea un DNI con esos datos recibidos.        
DNI::DNI(string DNI_entrada)
{
    
   for (int i = 0; i < 9; i++) {
        DNI_[i]=DNI_entrada[i];
    }
}

//Destructor de la clase DNI
DNI::~DNI(void){}

//Metodo Getter que devuelve un DNI.
string DNI::get_DNI(void){
    return DNI_;
}

//Metodo Setter que recibe un DNI por parametros y lo guardara si esta dentro de los valores permitidos y si no es así, generará y guardará uno aleatorio.
void DNI::set_DNI(string DNI_entrada){
    
    if(DNI_entrada < "00000000A" || DNI_entrada > "99999999Z"){
        	cout << "El DNI introducido no es válido. Se insertará uno aleatorio" << endl;
		    set_random();
    }
    else {
        DNI_=DNI_entrada;
    }
}

//Metodo Setter random donde genererá un DNI aleatorio.
void DNI::set_random(void){
    
    for(int i=0;i<8;i++){
        
     DNI_[i] = rand() % 10 + 48;    // 10 porque vas de 0-9 y 48 donde empiezan los numeros en ASCII
    }
    
    for(int i=8;i<9;i++){
        DNI_[i] = rand() % 26 + 65; // 26 el tamaño del alfabeto y 65 donde empieza la letra A en ASCII
    }
}

//Sobrecarga del Operador "<"
bool DNI::operator<(DNI& DNI_cp){
    return DNI_ < DNI_cp.get_DNI();
}

//Sobrecarga del Operador ">"
bool DNI::operator>(DNI& DNI_cp){
    return DNI_ > DNI_cp.get_DNI();
}

//Sobrecarga del Operador "=="
bool DNI::operator==(DNI& DNI_cp){
    return DNI_ == DNI_cp.get_DNI();
}

//Sobrecarga del Operador "<<"
ostream& operator<<(ostream& os, const DNI& DNI_salida)
{
    os << DNI_salida.DNI_;
    return os;
}

//Metodo para llevar a cabo la impresion de un DNI
ostream& DNI::imprimir (ostream& os) const {
    char aux[8];
    for (int i = 0; i < 9; i++){
        aux[i] = DNI_[i];
        os << setw(9) << aux;//Set Width(9)
    }
    return os;
}

DNI::operator unsigned long (void)
{
    unsigned long aux = 0;
    for (int i = 0; i < 9; i++) {
        aux += DNI_[i] * (i + 1);
    }

    return aux;
}