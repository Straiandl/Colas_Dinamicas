//De la Paz Mendoza Ian ALexandro. 25A.
//Clases y objetos.

#include <iostream>
#include <string>
const int Tam=50;

class empleado {
private: //Atributos deben de ir aqui
    int ClaveEmpleado;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string ReportaA;
public:
    empleado() { ClaveEmpleado = 0; nombre = " "; domicilio = " "; sueldo = 0; ReportaA = " "; } //constructor

    void setClaveE(int clave) { ClaveEmpleado = clave; }
    void setnombre(std::string nom) { nombre = nom; }
    void setdomicilio(std::string dom) { domicilio = dom; }
    void setsueldo(float s) { sueldo = s; }
    void setReporta(std::string reporta) { ReportaA = reporta; }

    float getsueldo(){
        return sueldo;
    }


    // sobrecarga de operadores.
    friend std::ostream& operator<<(std::ostream& os, const empleado& emp);

    friend std::istream& operator>>(std::istream& is, empleado& emp);



    bool operator==(const empleado& otro) const {
        return sueldo == otro.sueldo;
    }

    bool operator > (const empleado& otro) const {
        return sueldo > otro.sueldo;
    }

    bool operator < (const empleado& otro) const{
        return sueldo < otro.sueldo;
    }

    bool operator != (const empleado& otro) const{
        return sueldo != otro.sueldo;
    }

    empleado operator + (const empleado& otro) const {
        empleado temp;
        temp.sueldo = this ->sueldo + otro.sueldo;
        return temp;
    }


};

class PilaEmpleado {
    private:
        empleado datos[Tam]; // Arreglo de objetos empleado
        int ult; // Índice del último elemento
    public:
        PilaEmpleado() : ult(-1) {}
    
        bool vacia() const { return ult == -1; }
        bool llena() const { return ult == Tam - 1; }
    
        void insertar(const empleado& emp) {
            if (llena()) {
                std::cout << "\nError: Pila llena." << std::endl;
            } else {
                datos[++ult] = emp; // Inserta el empleado en la pila
            }
        }
    
        void eliminar() {
            if (vacia()) {
                std::cout << "\nError: Pila vacía." << std::endl;
            } else {
                --ult; // Elimina el último elemento
            }
        }
    
        empleado recuperar() const {
            if (vacia()) {
                std::cout << "\nError: Pila vacía." << std::endl;
                return empleado(); // Retorna un empleado vacío
            } else {
                return datos[ult]; // Retorna el último elemento
            }
        }
    
        int ultimo() const {
            return ult;
        }
    };
    

std::ostream& operator<<(std::ostream& os, const empleado& emp){
    os << "\nClave de empleado: " << emp.ClaveEmpleado << std::endl;
    os << "Nombre: " << emp.nombre << std::endl;
    os << "Domicilio: " << emp.domicilio << std::endl;
    os << "Sueldo: " << emp.sueldo << std::endl;
    os << "Reporta a: " << emp.ReportaA << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, empleado& emp) {
    std::cout << "Introduce la clave de empleado: ";
    is >> emp.ClaveEmpleado;

    std::cout << "Introduce el nombre: ";
    is >> emp.nombre;

    std::cout << "Introduce el domicilio: ";
    is >> emp.domicilio;

    std::cout << "Introduce el sueldo: ";
    is >> emp.sueldo;

    std::cout << "reporte: ";
    is >> emp.ReportaA;

    return is;
}

int main()
{
    PilaEmpleado Mipila;
    empleado JefePlanta, JefePersonal, emp;
    int op=0, num;
    while (op != 10) {
        std::cout << "\n Bienvenido \n elige una opcion: \n 1: Registrar empleados. \n 2: Mostrar los empleados. \n 3: Eliminar el ultimo empleado. \n 4: Mostrar el ultimo empleado. \n 5. Presiona 5 para salir. \n \n";
        std::cin >> op;
        switch (op){
            case 1:
            std::cout << "Cuantos empleados quieres registrar? ";
            std::cin >> num;
                for (int i = 0; i < num; i++) {
                    std::cout << "\nIntroduce los datos del empleado " << i + 1 << ":\n";
                    std::cin >> emp;
                    Mipila.insertar(emp); 
                }
                break;
            case 2:
                std::cout << "\n Empleados registrados:";
                while (!Mipila.vacia()) {
                    std::cout << Mipila.recuperar() << std::endl;
                    Mipila.eliminar(); 
                }
                break;
            case 3:
            std::cout << "\n Empleado eliminado.\n";
            Mipila.eliminar();
                break;
            case 4:
                std::cout << "\nEl ultimo empleado registrado:" << Mipila.recuperar() << std::endl;
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