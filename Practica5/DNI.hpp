#include "common.hpp"

#pragma once

using namespace std;

class  DNI{
    
    private:
        
        
    public:
        
        string DNI_;
        DNI(void);//Constructor por defecto
        DNI(string DNI_entrada);//Constructor que reibe un DNI en concreto.
        ~DNI(void);
        string get_DNI(void); //Metodo Getter
        void set_DNI(string DNI_entrada); //Metodo Setter
        void set_random(void); //Metodo Setter para un DNI random.
        bool operator<(DNI& DNI_cp); //Sobrecarga del operador "<"
        bool operator>(DNI& DNI_cp); //Sobrecarga del operador ">"
        bool operator==(DNI& DNI_cp); //Sobrecarga del operador comparacion "=="
        friend ostream& operator<<(ostream& os, const DNI& DNI_salida); //Sobrecarga del operador "<<"
        ostream& imprimir (ostream& os) const;
        operator unsigned long(void);
};