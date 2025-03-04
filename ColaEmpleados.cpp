//De la Paz Mendoza Ian ALexandro. 25A.
//Colas dinamicas.

#include <iostream>
#include <string>
const int Tam=50;

class alumno {
private: //Atributos deben de ir aqui
    std::string nombre;
    std::string carrera;
    int aprovadas;
    float promedio;
public:
    alumno() { nombre = " "; carrera = " "; aprovadas = 0; promedio = 0.0; } //constructor

    void setNombre(int nom) { nombre = nom; }
    void setCarrera(std::string carr) {carrera = carr; }
    void setAprovadas(int apro) { aprovadas = apro; }
    void setpromedio(float prom) { promedio = prom; }


    // sobrecarga de operadores.
    friend std::ostream& operator<<(std::ostream& os, const alumno& emp);

    friend std::istream& operator>>(std::istream& is, alumno& emp);



    bool operator==(const alumno& otro) const {
        return promedio == otro.promedio;
    }

    bool operator > (const alumno& otro) const {
        return promedio > otro.promedio;
    }

    bool operator < (const alumno& otro) const{
        return promedio < otro.promedio;
    }

    bool operator != (const alumno& otro) const{
        return promedio != otro.promedio;
    }

    alumno operator + (const alumno& otro) const {
        alumno temp;
        temp.promedio = this ->promedio + otro.promedio;
        return temp;
    }


};



class ColaEmpleado {
    private:
        alumno datos[Tam];
        int frente, final;
    public:
        ColaEmpleado() : frente(0), final(-1) {}
    
        bool vacia() const { return final < frente; }
        bool llena() const { return final == Tam - 1; }
    
        void insertar(const alumno& emp) {
            if (llena()) {
                std::cout << "\nError: Pila llena." << std::endl;
            } else {
                datos[++final] = emp;
            }
        }
    
        void eliminar() {
            if (vacia()) {
                std::cout << "\nError: Pila vacía." << std::endl;
            } else {
                frente++;
            }
        }
    
        alumno recuperar() const {
            if (vacia()) {
                std::cout << "\nError: Pila vacía." << std::endl;
                return alumno();
            } else {
                return datos[frente];
            }
        }

        void mostrar () const {
            if (vacia()){
                std::cout << "\nCola vacia." << std::endl;

            }
            else{
                for (int i = frente; i <= final; i++){
                    std::cout << datos[i] << std::endl;
                }
            }
        }
    };
    

std::ostream& operator<<(std::ostream& os, const alumno& emp){
    os << "\nNombre del alumno: " << emp.nombre << std::endl;
    os << "Nombre de la materia: " << emp.carrera << std::endl;
    os << "Materias aprovadas: " << emp.aprovadas << std::endl;
    os << "Promedio: " << emp.promedio << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, alumno& emp) {
    std::cout << "Introduce el nombre del alumno: ";
    is >> emp.nombre;

    std::cout << "Introduce el nombre de la materia: ";
    is >> emp.carrera;

    std::cout << "Introduce las materias aprovadas: ";
    is >> emp.aprovadas;

    std::cout << "Introduce el promedio: ";
    is >> emp.promedio;

    return is;
}

int main()//Mipila
{
    ColaEmpleado Micola;
    alumno JefePlanta, JefePersonal, emp;
    int op=0, num;
    while (op != 5) {
        std::cout << "\n \nBienvenido\nElige una opcion:\n1: Registrar alumnos.\n2: Mostrar todos los alumnos.\n3: Eliminar el ultimo alumno.\n4: Mostrar el ultimo alumno.\n5: Salir.\n\n";
        std::cin >> op;
        switch (op){
            case 1:
            std::cout << "Cuantos alumnos quieres registrar? ";
            std::cin >> num;
                for (int i = 0; i < num; i++) {
                    std::cout << "\nIntroduce los datos del alumno " << i + 1 << ":\n";
                    std::cin >> emp;
                    Micola.insertar(emp); 
                }
                break;
            case 2:
                std::cout << "\n Alumnos registrados:";
                Micola.mostrar();
                break;
            case 3:
            std::cout << "\n Alumno eliminado.\n";
            Micola.eliminar();
                break;
            case 4:
                std::cout << "\nEl ultimo alumno registrado:" << Micola.recuperar() << std::endl;
                break;
            case 5:
                std::cout << "\nGracias\n";
                return 0;
            default:
                std::cout << "\nIntroduce una opcion correcta. \n";
                break;
        }
    }
}
