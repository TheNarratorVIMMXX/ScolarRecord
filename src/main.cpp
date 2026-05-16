// =====================================================================================================================================

// DOCUMENTACIÓN:

// Registro de Alumnos

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#include <vector>                                                                                          // Librería de Vectores
#include "ui/design.hpp"                                                                                   // Diseño de la Interfaz
#include "core/structs.hpp"                                                                                // Structs
#include "core/register.hpp"                                                                               // Registro de Alumnos
#include "utils/helpers.hpp"                                                                               // Funciones Auxiliares

// =====================================================================================================================================
// -------------------------------------------------------------- Main ----------------------------------------------------------------

int main ()
{
    int studentsNum, studentNumber;
    std::vector<Student> studentBD;

    clearScreen();

    Design::cover();
    Design::studentsInput(studentsNum);

    for (studentNumber = 1; studentNumber <= studentsNum;){
      auto student = StudentRegister::readStudentData(studentNumber);
      studentBD.push_back(student);
      waitMilliseconds(900);
      clearScreen();
      studentNumber++;
    }

    return 0;
}

// =====================================================================================================================================