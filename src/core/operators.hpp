// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de Structs para Almacenar Datos de los Alumnos

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include <ostream>                                                                                           // Para Sobrecarga de Operadores de Salida
#include "../core/structs.hpp"                                                                               // Structs para Almacenar Datos

// =====================================================================================================================================
// ------------------------------------------------------------ Structs --------------------------------------------------------------
 
/**
 * @brief Sobrecarga de Operador << para imprimir el Nombre Completo.
 */
inline std::ostream& operator << (std::ostream& os, const CompleteName& name){
    os << name.NAME << " " << name.PATERNAL_SURNAME << " " << name.MATERNAL_SURNAME;
    return os;
}

/**
 * @brief Sobrecarga de Operador << para imprimir la Fecha de Nacimiento.
 */
inline std::ostream& operator << (std::ostream& os, const BirthDate&  birthDate){
    os << birthDate.DAY << "/" << birthDate.MONTH << "/" << birthDate.YEAR;
    return os;
}

/**
 * @brief Sobrecarga de Operador << para imprimir el Lugar de Nacimiento.
 */
inline std::ostream& operator << (std::ostream& os, const Place& place){
    os << place.CITY << ", " << place.STATE << ", " << place.COUNTRY;
    return os;
}

/**
 * @brief Sobrecarga de Operador << para imprimir los datos de un Alumno.
 */
inline std::ostream& operator << (std::ostream& os, const Student& Student){
    os << "Nombre Completo: " << Student.COMPLETE_NAME << "\n"
       << "Fecha de Nacimiento: " << Student.BIRTHDATE << "\n"
       << "Lugar de Nacimiento: " << Student.BIRTHPLACE << "\n"
       << "Grado: " << static_cast<int>(Student.educativeGrade) << "\n"
       << "Grupo: " << static_cast<char>(Student.group) << "\n"
       << "Sexo: " << static_cast<char>(Student.SEX) << "\n"
       << "Calificación: " << Student.calification << "\n"
       << "ID: " << Student.id_student << "\n";
    return os;
}


// =====================================================================================================================================