
/**
 * @file registro_escolar.h
 * @brief Declara tres Estructuras (Alumno, Profesores y Directivos) y funciona como Gestor de Registro
 * @author Magallanes López Carlos Gabriel
 * @version 1.3
 * @date 22-06-2025
 */


/// @brief Protección contra Inclusiones Múltiples del Archivo de Cabecera

#ifndef REGISTRO_ESCOLAR
#define REGISTRO_ESCOLAR


/// @brief Incluye las Librerías Más Usadas en el Proyecto
#include "librerias_comunes.h"


#ifdef _WIN32
    #include <conio.h>
#else
    #include <cstdlib>
#endif



void pause()
{
    #ifdef _WIN32
        std::cout << "Pulsa cualquier tecla para continuar..." << "\n";
        getch();
    #else
        std::system("bash -c \"read -n1 -s -p 'Pulsa cualquier tecla para continuar...'\"");
        std::cout << "\n";
    #endif
}

void clean()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}



struct Nombre
{
    std::string nom,ap_p,ap_m;
    Nombre(): nom(" "), ap_p(" "), ap_m(" ") {};
    Nombre(const std::string& Nombre,const std::string Apellido_P,const std::string& Apellido_M): nom(Nombre),ap_p(Apellido_P),ap_m(Apellido_M) {};
};

std::ostream& operator << (std::ostream& os, const Nombre noms)
{
    os << noms.nom << " " << noms.ap_p << " " << noms.ap_m;
    return os;
}

struct Fecha
{
    int dia,mes,annio;
    Fecha(): dia(0), mes(0), annio(0) {};
    Fecha(int d, int m, int a): dia(d), mes(m), annio(a) {};
};

std::ostream& operator << (std::ostream& os, const Fecha& fecha)
{
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.annio;
    return os;
}

struct Lugar
{
    std::string ciudad, estado;
    Lugar(): ciudad(""), estado("") {};
    Lugar(const std::string& Ciudad, const std::string& Estado): ciudad(Ciudad), estado(Estado) {};
};

std::ostream& operator << (std::ostream& os, const Lugar& lugar)
{
    os << lugar.ciudad << ", " << lugar.estado << ",    MEXICO";
    return os;
}



namespace Disennio
{
    void BannerBegin()
    {
        std::cout << "  ********************************************************************************************************************************** \n";
        std::cout << "  ********************************************************************************************************************************** \n";
        std::cout << "  ***                                                                                                                            *** \n";
    }
    void BannerEnd()
    {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ********************************************************************************************************************************** \n";
        std::cout << "  ********************************************************************************************************************************** \n";
    }
    void Portada()
    {
        for (int i = 0; i<3; i++)
        {
            Disennio::BannerBegin();
            std::cout << "  ***                    *****   ****  ****** ******     *****  ******     *****   **** ******** ****  *******                   *** \n";
            std::cout << "  ***                    **  ** **  ** **  ** **  **     **  ** **  **     **  ** **  **   **   **  ** **   **                   *** \n";
            std::cout << "  ***                    **  ** **  ** **     **         **  ** **         **  ** **  **   **   **  ** **                        *** \n";
            std::cout << "  ***                    *****  ****** ****** *****      **  ** *****      **  ** ******   **   **  ** *******                   *** \n";
            std::cout << "  ***                    **  ** **  **     ** **         **  ** **         **  ** **  **   **   **  **      **                   *** \n";
            std::cout << "  ***                    **  ** **  ** **  ** **  **     **  ** **  **     **  ** **  **   **   **  ** **   **                   *** \n";
            std::cout << "  ***                    *****  **  ** ****** ******     *****  ******     *****  **  **   **    ****  *******                   *** \n";
            Disennio::BannerEnd();
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "  Cargando";
            for (int j = 0; j < 5; j++)
            {
                std::cout << ".";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            clean();
        }
    }
    void TypeError()
    {

        Disennio::BannerBegin();
        std::cerr << "  ***                                        ERROR. Por Favor, Ingrese un Numero Entero                                          *** \n";
        Disennio::BannerEnd();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        clean();

    }
    void Cantidad_A(std::string& num_alumnos, int& n_Alumnos)
    {

        do
        {

            Disennio::BannerBegin();
            std::cout << "  ***                                ****    ****   **   ** ******** ******  *****    ****   *****                               *** \n";
            std::cout << "  ***                               **  **  **  **  ***  **    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                               **  **  **  **  **** **    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                               **      ******  ** ****    **      **    **  **  ******  **  **                              *** \n";
            std::cout << "  ***                               **  **  **  **  **  ***    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                               **  **  **  **  **   **    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                                ****   **  **  **   **    **    ******  *****   **  **  *****                               *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            Disennio::BannerBegin();
            std::cout << "  ***                                    Introduzca la cantidad de alumnos a registrar: ";
            std::getline(std::cin , num_alumnos);
            Disennio::BannerEnd();
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            clean();
            if(!std::all_of(num_alumnos.begin(), num_alumnos.end(), ::isdigit))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                TypeError();
            }
            else    break;

        }while(true);
        n_Alumnos = std::stoi(num_alumnos);

    }
    void Registro(int& i)
    {

        Disennio::BannerBegin();
        std::cout << "  ***                                    *****  ******  ****  **** ******* ****** *****   ****                                   *** \n";
        std::cout << "  ***                                    **  ** **  ** **  **  **  **   **   **   **  ** **  **                                  *** \n";
        std::cout << "  ***                                    **  ** **     **  **  **  **        **   **  ** **  **                                  *** \n";
        std::cout << "  ***                                    *****  *****  **      **  *******   **   *****  **  **                                  *** \n";
        std::cout << "  ***                                    ****   **     ** ***  **       **   **   ****   **  **                                  *** \n";
        std::cout << "  ***                                    ** **  **  ** **  **  **  **   **   **   ** **  **  **                                  *** \n";
        std::cout << "  ***                                    **  ** ******  ****  **** *******   **   **  **  ****                                   *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        Disennio::BannerBegin();
        std::cout << "  ***                                                           ALUMNO "<<i+1<<"                                                         *** \n";
        std::cout << "  ***                                                                                                                            *** \n";

    }
    void DatoNombre (Nombre nombre)
    {

        Disennio::BannerBegin();
        std::cout << "  ***       Ingrese el Nombre del Alumno: " << nombre.nom << "\n";
        Disennio::BannerEnd();

    }
    void DatoApellido_P (Nombre nombre)
    {

        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Apellido Paterno del Alumno: " << nombre.ap_p << "\n";
        Disennio::BannerEnd();

    }
    void DatoApellido_M (Nombre nombre)
    {

        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Apellido Materno del Alumno: " << nombre.ap_m << "\n";
        Disennio::BannerEnd();

    }
    void DatoGrado (int grado)
    {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Grado del Alumno: " << grado << "\n";
        Disennio::BannerEnd();
    }
    void DatoGrupo (char grupo)
    {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Grupo del Alumno: " << grupo << "\n";
        Disennio::BannerEnd();
    }
    void Confirmacion()
    {
        Disennio::BannerBegin();
        std::cout << "  ***                       ****   ****  **   ** ****** *** *****  **   **  ****   ****  ****  ****  **   **                     *** \n";
        std::cout << "  ***                      **  ** **  ** ***  ** **  ** **  **  ** *** *** **  ** **  **  **  **  ** ***  **                     *** \n";
        std::cout << "  ***                      **  ** **  ** **** ** **     **  **  ** ******* **  ** **  **  **  **  ** **** **                     *** \n";
        std::cout << "  ***                      **     **  ** ** **** ****   **  *****  ** * ** ****** **      **  **  ** ** ****                     *** \n";
        std::cout << "  ***                      **  ** **  ** **  *** **     **  ****   **   ** **  ** **  **  **  **  ** **  ***                     *** \n";
        std::cout << "  ***                      **  ** **  ** **   ** **     **  ** **  **   ** **  ** **  **  **  **  ** **   **                     *** \n";
        std::cout << "  ***                       ****   ****  **   ** **    **** **  ** **   ** **  **  ****  ****  ****  **   **                     *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        Disennio::BannerBegin();

    }
    void Instrucciones()
    {
        Disennio::BannerBegin();
        std::cout << "  ***                  **** **    ** ****** ****** *****  **  **  ****   ****  ****  ****  **   ** ****** ******                 *** \n";
        std::cout << "  ***                   **  ***   ** **  **   **   **  ** **  ** **  ** **  **  **  **  ** ***  ** **  ** **  **                 *** \n";
        std::cout << "  ***                   **  ****  ** **       **   **  ** **  ** **  ** **  **  **  **  ** **** ** **     **                     *** \n";
        std::cout << "  ***                   **  ** ** ** ******   **   *****  **  ** **     **      **  **  ** ** **** *****  ******                 *** \n";
        std::cout << "  ***                   **  **  ****     **   **   ****   **  ** **  ** **  **  **  **  ** **  *** **         **                 *** \n";
        std::cout << "  ***                   **  **   *** **  **   **   ** **  **  ** **  ** **  **  **  **  ** **   ** **  ** **  **                 *** \n";
        std::cout << "  ***                  **** **    ** ******   **   **  **  ****   ****   ****  ****  ****  **   ** ****** ******                 *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        Disennio::BannerBegin();
        std::cout << "  ***          PENDIENTE                         *** \n";
        std::cout << "  ***                                  *** \n";
        std::cout << "  ***                                      *** \n";
        std::cout << "  ***                                 *** \n";
        std::cout << "  ***                                  *** \n";
        std::cout << "  ***                                   *** \n";
        std::cout << "  ***                                 *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        pause();
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
        clean();

    }

}




class Alumnos
{
    private:

        Nombre nombre;
        Fecha nacimiento;
        Lugar lugar_nacimiento;
        char grupo,sexo;
        int id_alumno,grado, indice,instrucc;
        double calif;
        bool valido;
        static std::set<int> ids_usados;

    public:

        Alumnos(): nacimiento(0,0,0), nombre("A","A","A"), lugar_nacimiento("",""), grupo('\0'),sexo('\0'), id_alumno(0), grado(0),indice(0),instrucc(0), calif(0.0), valido(true) {};

        Alumnos (const Nombre& Nombre,const Fecha& Nacimiento, const Lugar& Sitio, char Grupo,char Sexo, int ID, int Grado,int i,int Instrucc, double Calificacion):
        nacimiento(Nacimiento), nombre(Nombre), lugar_nacimiento(Sitio), grupo(Grupo),sexo(Sexo), id_alumno(ID), grado(Grado),indice(i),instrucc(Instrucc) ,calif(Calificacion)  , valido(true)
        {
            setNombre(nombre);
            setGrado(grado);
            setGrupo(grupo);
            setID(id_alumno);
            setCalificacion(calif);
            leerDatosAlumno(i);
        };


        /// GETTERS
        const Fecha& getNacimiento() const {return nacimiento;}
        const Nombre& getNombre() const {return nombre;}
        const Lugar& getLugar() const {return lugar_nacimiento;}
        char getGrupo() const {return grupo;}
        char getSexo() const {return sexo;}
        int getID() const {return id_alumno;}
        int getGrado() const {return grado;}
        int getIndice() const {return indice;}
        int getInstrucciones() const {return instrucc;}
        double getCalificacion() const {return calif;}
        bool getValido() const {return valido;}


        ///SETTERS
        void setIndice(int i) {indice = i;}

        void setInstrucciones(int instrucc, const std::string& ver_str, bool& valido)
        {
            char ver_c = ver_str[0];
            if (!(isdigit(ver_c)))
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                Disennio::TypeError();
                valido = false;
            }
            else
            {
                instrucc = ver_c - '0';
                valido = true;
            }


            if (instrucc == 1)
            {
                Disennio::Instrucciones();
            }

        }
        void setNacimiento(const Fecha& nacimiento)
        {
            ;
        }
        void setNombre (const Nombre& nombre)
        {
            if(nombre.nom.empty() )
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                Disennio::BannerBegin();
                std::cout << "  ***                                                                                                                            *** \n";
                std::cerr << "  ***                                            ERROR. Este Dato no puede estar Vacio                                           *** \n";
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                clean();
                Instrucciones();
                Disennio::Registro(indice);
                valido = false;
                return;

            }

            else
            {
                int err = 0, letra = 0, space = 0;

                for (char c : nombre.nom)
                {
                    if (isalpha(c))      letra++;
                    else if (isspace(c)) space++;
                    else                 err++;


                }
                if (letra < 1 || err > 0  )
                {
                        std::this_thread::sleep_for(std::chrono::milliseconds(900));
                        clean();
                        Disennio::BannerBegin();
                        std::cerr << "  ***                 ERROR. Siga el formato indicado para el Nombre Completo. Si tiene dudas vaya a Instrucciones               *** \n";
                        Disennio::BannerEnd();
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        clean();
                        Instrucciones();
                        Disennio::Registro(indice);
                        valido = false;
                        return;
                }

            }
         this->nombre.nom = nombre.nom;
         valido = true;
        }
        void setApellido_P (const Nombre& nombre)
        {
            if(nombre.ap_p.empty() )
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                Disennio::BannerBegin();
                std::cout << "  ***                                                                                                                            *** \n";
                std::cerr << "  ***                                            ERROR. Este Dato no puede estar Vacio                                           *** \n";
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                clean();
                Instrucciones();
                Disennio::Registro(indice);
                Disennio::DatoNombre(nombre);
                valido = false;
                return;

            }

            else
            {
                int err = 0, letra = 0, space = 0;

                for (char c : nombre.ap_p)
                {
                    if (isalpha(c))      letra++;
                    else if (isspace(c)) space++;
                    else                 err++;


                }
                if (letra < 1 || err > 0  )
                {
                        std::this_thread::sleep_for(std::chrono::milliseconds(900));
                        clean();
                        Disennio::BannerBegin();
                        std::cerr << "  ***                 ERROR. Siga el formato indicado para el Nombre Completo. Si tiene dudas vaya a Instrucciones               *** \n";
                        Disennio::BannerEnd();
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        clean();
                        Instrucciones();
                        Disennio::Registro(indice);
                        Disennio::DatoNombre(nombre);
                        valido = false;
                        return;
                }

            }
         this->nombre.ap_p = nombre.ap_p;
         valido = true;
        }
        void setApellido_M (const Nombre& nombre)
        {
            if(nombre.ap_m.empty() )
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                Disennio::BannerBegin();
                std::cerr << "  ***                                            ERROR. Este Dato no puede estar Vacio                                           *** \n";
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                clean();
                Instrucciones();
                Disennio::Registro(indice);
                Disennio::DatoNombre(nombre);
                Disennio::DatoApellido_P(nombre);
                valido = false;
                return;

            }

            else
            {
                int err = 0, letra = 0, space = 0;

                for (char c : nombre.ap_m)
                {
                    if (isalpha(c))      letra++;
                    else if (isspace(c)) space++;
                    else                 err++;


                }
                if (letra < 1 || err > 0  )
                {
                        std::this_thread::sleep_for(std::chrono::milliseconds(900));
                        clean();
                        Disennio::BannerBegin();
                        std::cerr << "  ***                 ERROR. Siga el formato indicado para el Nombre Completo. Si tiene dudas vaya a Instrucciones               *** \n";
                        Disennio::BannerEnd();
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        clean();
                        Instrucciones();
                        Disennio::Registro(indice);
                        Disennio::DatoNombre(nombre);
                        Disennio::DatoApellido_P(nombre);
                        valido = false;
                        return;
                }

            }
         this->nombre.ap_m = nombre.ap_m;
         valido = true;
        }
        void setGrado (int grado)
        {
             if(grado < 1)
             {

                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                Disennio::BannerBegin();
                std::cerr << "  ***                                     ERROR. El Menor Grado permitido a Ingresar es 1                                        *** \n";
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                clean();
                Instrucciones();
                Disennio::Registro(indice);
                Disennio::DatoNombre(nombre);
                Disennio::DatoApellido_P(nombre);
                Disennio::DatoApellido_M(nombre);
                valido = false;
            }
            else
            {
                this->grado = grado;
                valido = true;
            }

        }
        void setGrupo (char grupo)
        {
            if(!isalpha(grupo))
            {
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                     ERROR. Solo se permite ingresar una letra (A -Z)                                       *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    Disennio::DatoGrado(grado);
                    valido = false;
            }

            else
            {

                this->grupo = grupo;
                valido = true;
            }

        }
        void setCalificacion (double calif)
        {

            if(calif < 0 || calif > 10)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                Disennio::BannerBegin();
                std::cerr << "  ***                                        ERROR. El Rango de Calificacion es de 0 - 10                                        *** \n";
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                clean();
                Instrucciones();
                Disennio::Registro(indice);
                Disennio::DatoNombre(nombre);
                Disennio::DatoApellido_P(nombre);
                Disennio::DatoApellido_M(nombre);
                Disennio::DatoGrado(grado);
                Disennio::DatoGrupo(grupo);
                valido = false;
            }

            else
            {

                this->calif = calif;
                valido = true;

            }

        }
        void setID (int id_alumno)
        {


                std::random_device random;
                std::uniform_int_distribution<int> dist (10000000, 99999999);
                int nuevo_id;
                do {nuevo_id = dist(random); }while(ids_usados.count(nuevo_id));
                id_alumno = nuevo_id;
                ids_usados.insert(nuevo_id);
                this->id_alumno = id_alumno;
                valido = true;


        }


        /// METODOS

        ///Lectura de Datos
         void leerDatosAlumno(int i)
        {
            indice = i;
            Disennio::Registro(indice);

            do
            {
                Disennio::BannerBegin();
                std::cout << "  ***       Ingrese el Nombre del Alumno: ";
                std::getline(std::cin, nombre.nom);
                Disennio::BannerEnd();
                setNombre(nombre);

             }while(!this->valido);


             do
             {
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Apellido Paterno del Alumno: ";
                std::getline(std::cin, nombre.ap_p);
                Disennio::BannerEnd();
                setApellido_P(nombre);
              }while(!this->valido);


              do
              {
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Apellido Materno del Alumno: ";
                std::getline(std::cin, nombre.ap_m);
                Disennio::BannerEnd();
                setApellido_M(nombre);;
              }while(!this->valido);

              do
              {
                std::string dia_str;
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Dia de Nacimiento del Alumno: ";
                std::getline(std::cin, dia_str);
                Disennio::BannerEnd();
                if(dia_str.empty())
                {

                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    Disennio::BannerBegin();
                    std::cerr << "  ***                               ERROR. El Dia de Nacimiento del Alumno no puede estar Vacio                                  *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    valido = false;
                    continue;

                }
                else if (dia_str.size() > 2)
                {

                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                             ERROR. Eliga un Dia disponible                                                 *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    valido = false;
                    continue;
                }
                else  if (!std::all_of(dia_str.begin(), dia_str.end(), ::isdigit))
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::TypeError();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    valido = false;
                    continue;
                }
                else
                {
                    nacimiento.dia = std::stoi(dia_str);
                    setNacimiento(nacimiento);

                }

              }while(!this->valido);

              do
              {
                std::string grado_str;
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Grado del Alumno: ";
                std::getline(std::cin , grado_str);
                Disennio::BannerEnd();

                if(grado_str.empty())
                {

                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                            ERROR. El Grado no puede estar Vacio                                            *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    valido = false;
                    continue;

                }
                else  if (!std::all_of(grado_str.begin(), grado_str.end(), ::isdigit))
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::TypeError();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    valido = false;
                    continue;
                }
                else
                {
                        grado = std::stoi(grado_str);
                        setGrado(grado);
                }

            }while(!this->valido);


            do
            {
                std::string grupo_str;
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Grupo del Alumno: ";
                std::getline(std::cin , grupo_str);
                Disennio::BannerEnd();
                if(grupo_str.empty())
                {

                    Disennio::BannerBegin();
                    std::cerr << "  ***                                            ERROR. El Grupo no puede estar Vacio                                            *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    Disennio::DatoGrado(grado);
                    valido = false;

                }
               else if(grupo_str.size() > 1)
                {
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                     ERROR. Solo se permite ingresar una letra (A - Z)                                      *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    Disennio::DatoGrado(grado);
                    valido = false;
                }
                else
                {
                    grupo = grupo_str[0];
                    setGrupo(grupo);
                }

            }while(!this->valido);

             do
            {
                std::string calif_str;
                int punto = 0,nums = 0,err = 0;
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Promedio Final en el curso del Alumno: ";
                std::getline(std::cin , calif_str);
                Disennio::BannerEnd();
                for(int j = 0; j < calif_str.size(); j++ )
                {
                    char c = calif_str[j];
                    if(isdigit(c))      nums++;
                    else if(c == '.')   punto++;
                    else                err++;

                }
                if (err > 0 || punto > 1 || nums == 0)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                                ERROR. Ingrese un Numero                                                    *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    Disennio::DatoGrado(grado);
                    Disennio::DatoGrupo(grupo);
                    valido = false;
                }


                else if(calif_str.empty())
                {

                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                          ERROR. La Calificacion no puede estar Vacia                                       *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    Instrucciones();
                    Disennio::Registro(indice);
                    Disennio::DatoNombre(nombre);
                    Disennio::DatoApellido_P(nombre);
                    Disennio::DatoApellido_M(nombre);
                    Disennio::DatoGrado(grado);
                    Disennio::DatoGrupo(grupo);
                    valido = false;

                }
                else
                {
                    calif=std::stod(calif_str);
                    setCalificacion(calif);
                }
            }while(!this->valido);

             do
            {
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***           EL ID DEL ALUMNO SE GENERARA ALEATORIAMENTE POR COMPUTADORA, TENDRA 8 DIGITOS Y SERA UNA CLAVE UNICA             *** \n";
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::seconds(5));
                setID(id_alumno);
            }while(!this->valido);

        }

        /// Confirmacion
        int ConfirmarDatos(int& confirm)
        {
            std::string confirm_str;

            Disennio::Confirmacion();
            std::cout << "  ***                                                           ALUMNO "<<indice+1<<"                                                         *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       NOMBRE:   " << nombre.nom << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       GRADO:    " << grado << "                                                                                                          *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       GRUPO:    " << grupo << "                                                                                                          *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       PROMEDIO: " << calif << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       ID:       " << id_alumno << "                                                                                                   *** \n";
            Disennio::BannerEnd();
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                         REGISTRAR?                                                         *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                           1. SI                                                            *** \n";
            std::cout << "  ***                                                           2. NO                                                            *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                        DECISION: ";
            std::getline(std::cin, confirm_str);
            Disennio::BannerEnd();

            if(confirm_str.empty())
            {

                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                         ERROR. Ingrese el Dato en la Confirmacion                                          *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    valido = false;
            }
            else if (confirm_str.size() > 1)
            {
                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                            ERROR. Eliga una Opcion Disponible                                              *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    valido = false;
            }
            else if (!std::all_of(confirm_str.begin(), confirm_str.end(),::isdigit))
            {
                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::TypeError();
                    valido = false;
            }
            else
            {
                confirm = std::stoi(confirm_str);
                return confirm;
            }


        }

        /// Correccion
        void Instrucciones()
        {
            std::string ver_str;
            do
            {
                Disennio::Confirmacion();
                std::cout << "  ***                                                Desea ir a Instrucciones?                                                   *** \n";
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***                                                          1. SI                                                             *** \n";
                std::cout << "  ***                                                          2. NO                                                             *** \n";
                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***                                                      DESCISION: ";
                std::getline(std::cin, ver_str);
                Disennio::BannerEnd();
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                clean();
                if(ver_str.empty())
                {

                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                         ERROR. Ingrese el Dato en la Confirmacion                                          *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    valido = false;
                }
                else if (ver_str.size() > 1)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(900));
                    clean();
                    Disennio::BannerBegin();
                    std::cerr << "  ***                                            ERROR. Eliga una Opcion Disponible                                              *** \n";
                    Disennio::BannerEnd();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    clean();
                    valido = false;
                }
                else
                {
                    setInstrucciones(instrucc,ver_str,valido);
                }

            }while(!this->valido);
        }

        friend std::ostream& operator << (std::ostream& os, const Alumnos& alumno);


};


std::set<int> Alumnos::ids_usados;


std::ostream& operator << (std::ostream& os, const Alumnos& alumno)
{
    os <<" - " << alumno.nombre.nom << ", " << alumno.grado << alumno.grupo << ", " << alumno.calif << ", ID: " << alumno.id_alumno;
    return os;
}

int main ()
{
    std::string num_alumnos,num_maestros, num_directivos;
    int n_Alumnos,confirm;
    std::vector<Alumnos> Registro_A, Registro_M,Registro_D;
    system("color 0E");

     /// Disennio::Portada();
     /// Disennio::Menu();
      Disennio::Cantidad_A(num_alumnos,n_Alumnos);

    for ( int i = 0; i < n_Alumnos;)
    {
        Alumnos alumno;
        alumno.leerDatosAlumno(i);
        clean();
        alumno.ConfirmarDatos(confirm);
      if(confirm == 2)
      {
          clean();
          std::this_thread::sleep_for(std::chrono::milliseconds(900));
          continue;
      }
      else
      {

      Registro_A.push_back(alumno);
      std::this_thread::sleep_for(std::chrono::milliseconds(900));
      clean();
      i++;
    }}

    return 0;
}

#endif // REGISTRO_ESCOLAR
