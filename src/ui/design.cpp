
// =====================================================================================================================================

// DOCUMENTACIÓN:

// UI

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas e Internas
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares
#include "../utils/constants.hpp"                                                                            // Constantes
#include "../core/structs.hpp"                                                                               // Structs
    
// =====================================================================================================================================
// -------------------------------------------------------------- UI----------------------------------------------------------------

namespace Design{

    void bannerBegin(){
        std::cout << "  ********************************************************************************************************************************** \n";
        std::cout << "  ********************************************************************************************************************************** \n";
        std::cout << "  ***                                                                                                                            *** \n";
    }

    void bannerEnd(){
   
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ********************************************************************************************************************************** \n";
        std::cout << "  ********************************************************************************************************************************** \n";    
    }
    
    void cover(){
        for (int _ = 0; _ < 3; _++){
            bannerBegin();
            std::cout << "  ***                    *****   ****  ****** ******     *****  ******     *****   **** ******** ****  *******                   *** \n";
            std::cout << "  ***                    **  ** **  ** **  ** **  **     **  ** **  **     **  ** **  **   **   **  ** **   **                   *** \n";
            std::cout << "  ***                    **  ** **  ** **     **         **  ** **         **  ** **  **   **   **  ** **                        *** \n";
            std::cout << "  ***                    *****  ****** ****** *****      **  ** *****      **  ** ******   **   **  ** *******                   *** \n";
            std::cout << "  ***                    **  ** **  **     ** **         **  ** **         **  ** **  **   **   **  **      **                   *** \n";
            std::cout << "  ***                    **  ** **  ** **  ** **  **     **  ** **  **     **  ** **  **   **   **  ** **   **                   *** \n";
            std::cout << "  ***                    *****  **  ** ****** ******     *****  ******     *****  **  **   **    ****  *******                   *** \n";
            bannerEnd();
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "  Cargando";
            for (int _ = 0; _ < 5; _++){
                std::cout << ".";
                waitMilliseconds(500);
            }
            waitMilliseconds(800);
            clearScreen();
        }
    }

    void typeError(){
        bannerBegin();
        std::cerr << "  ***                                        ERROR. Por Favor, Ingrese un Numero Entero                                          *** \n";
        bannerEnd();
        waitSeconds(3);
        clearScreen();
    }
    
    void studentsInput(int& studentsNum){
        do{
            bannerBegin();
            std::cout << "  ***                                ****    ****   **   ** ******** ******  *****    ****   *****                               *** \n";
            std::cout << "  ***                               **  **  **  **  ***  **    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                               **  **  **  **  **** **    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                               **      ******  ** ****    **      **    **  **  ******  **  **                              *** \n";
            std::cout << "  ***                               **  **  **  **  **  ***    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                               **  **  **  **  **   **    **      **    **  **  **  **  **  **                              *** \n";
            std::cout << "  ***                                ****   **  **  **   **    **    ******  *****   **  **  *****                               *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            bannerBegin();
            std::cout << "  ***                                    Introduzca la cantidad de alumnos a registrar: ";
            std::cin >> studentsNum;

            bannerEnd();
            waitMilliseconds(900);
            clearScreen();
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(MAX_LIMIT,'\n');
                typeError();
            }
            else {

                std::cin.clear(); 
                std::cin.ignore(MAX_LIMIT,'\n');    
                break;
            }

        }while(true);
    }

    void initialRegister(int studentNum){
        bannerBegin();
        std::cout << "  ***                                    *****  ******  ****  **** ******* ****** *****   ****                                   *** \n";
        std::cout << "  ***                                    **  ** **  ** **  **  **  **   **   **   **  ** **  **                                  *** \n";
        std::cout << "  ***                                    **  ** **     **  **  **  **        **   **  ** **  **                                  *** \n";
        std::cout << "  ***                                    *****  *****  **      **  *******   **   *****  **  **                                  *** \n";
        std::cout << "  ***                                    ****   **     ** ***  **       **   **   ****   **  **                                  *** \n";
        std::cout << "  ***                                    ** **  **  ** **  **  **  **   **   **   ** **  **  **                                  *** \n";
        std::cout << "  ***                                    **  ** ******  ****  **** *******   **   **  **  ****                                   *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        bannerBegin();
        std::cout << "  ***                                                           ALUMNO "<<studentNum<<"                                                         *** \n";
        std::cout << "  ***                                                                                                                            *** \n";

    }
    
    void nameOutput (const std::string& name){
        bannerBegin();
        std::cout << "  ***       Ingrese el Nombre del Alumno: " << name << "\n";
        bannerEnd();
    }
    
    void paternalSurnameOutput (const std::string& paternalSurname){
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Apellido Paterno del Alumno: " << paternalSurname << "\n";
        bannerEnd();
    }

    void maternalSurnameOutput (const std::string& maternalSurname){
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Apellido Materno del Alumno: " << maternalSurname << "\n";
        bannerEnd();
    }

    void gradeOutput (EducativeGrade grade){
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Grado del Alumno: " << static_cast<int>(grade) << "\n";
        bannerEnd();
    }

    void groupOutput (Group group){
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Grupo del Alumno: " << static_cast<char>(group) << "\n";
        bannerEnd();
    }

    void confirmation(){
        bannerBegin();
        std::cout << "  ***                       ****   ****  **   ** ****** *** *****  **   **  ****   ****  ****  ****  **   **                     *** \n";
        std::cout << "  ***                      **  ** **  ** ***  ** **  ** **  **  ** *** *** **  ** **  **  **  **  ** ***  **                     *** \n";
        std::cout << "  ***                      **  ** **  ** **** ** **     **  **  ** ******* **  ** **  **  **  **  ** **** **                     *** \n";
        std::cout << "  ***                      **     **  ** ** **** ****   **  *****  ** * ** ****** **      **  **  ** ** ****                     *** \n";
        std::cout << "  ***                      **  ** **  ** **  *** **     **  ****   **   ** **  ** **  **  **  **  ** **  ***                     *** \n";
        std::cout << "  ***                      **  ** **  ** **   ** **     **  ** **  **   ** **  ** **  **  **  **  ** **   **                     *** \n";
        std::cout << "  ***                       ****   ****  **   ** **    **** **  ** **   ** **  **  ****  ****  ****  **   **                     *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        bannerBegin();
    }

    void instructions(){
        bannerBegin();
        std::cout << "  ***                  **** **    ** ****** ****** *****  **  **  ****   ****  ****  ****  **   ** ****** ******                 *** \n";
        std::cout << "  ***                   **  ***   ** **  **   **   **  ** **  ** **  ** **  **  **  **  ** ***  ** **  ** **  **                 *** \n";
        std::cout << "  ***                   **  ****  ** **       **   **  ** **  ** **  ** **  **  **  **  ** **** ** **     **                     *** \n";
        std::cout << "  ***                   **  ** ** ** ******   **   *****  **  ** **     **      **  **  ** ** **** *****  ******                 *** \n";
        std::cout << "  ***                   **  **  ****     **   **   ****   **  ** **  ** **  **  **  **  ** **  *** **         **                 *** \n";
        std::cout << "  ***                   **  **   *** **  **   **   ** **  **  ** **  ** **  **  **  **  ** **   ** **  ** **  **                 *** \n";
        std::cout << "  ***                  **** **    ** ******   **   **  **  ****   ****   ****  ****  ****  **   ** ****** ******                 *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        bannerBegin();
        std::cout << "  ***                                                          PENDIENTE                                                         *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***                                                                                                                            *** \n";
        pauseExecution();
        waitMilliseconds(900);
        clearScreen();
    }

    void dayOutput(int day) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Dia de Nacimiento del Alumno: " << day << "\n";
        bannerEnd();
    }

    void monthOutput(int month) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Mes de Nacimiento del Alumno: " << month << "\n";
        bannerEnd();
    }

    void yearOutput(int year) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Anno de Nacimiento del Alumno: " << year << "\n";
        bannerEnd();
    }

    void calificationOutput(double calification) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Promedio Final en el curso del Alumno: " << calification << "\n";
        bannerEnd();
    }

    void cityOutput(const std::string& city) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese la Ciudad de Nacimiento del Alumno: " << city << "\n";
        bannerEnd();
    }

    void stateOutput(const std::string& state) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Estado de Nacimiento del Alumno: " << state << "\n";
        bannerEnd();
    }

    void countryOutput(const std::string& country) {
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Pais de Nacimiento del Alumno: " << country << "\n";
        bannerEnd();
    }

    void sexOutput(Sex sex){
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***       Ingrese el Sexo del Alumno: " << static_cast<char>(sex) << "\n";
        bannerEnd();
    }
    
}

// =====================================================================================================================================