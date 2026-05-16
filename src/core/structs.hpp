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
#include <random>                                                                                            // Números Aleatorios
#include <set>                                                                                               // Conjuntos
#include <algorithm>                                                                                         // Algoritmos de STL
#include <cctype>                                                                                            // Funciones de Caracteres
#include <stdexcept>                                                                                         // Excepciones Estándar
#include <format>                                                                                            // Formateo de Cadenas
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares
#include "../utils/validators.hpp"                                                                           // Funciones de Validación
#include "../utils/constants.hpp"                                                                            // Constantes Globales

// =====================================================================================================================================
// ------------------------------------------------------------ Structs --------------------------------------------------------------
 
/**
 * @brief Representa el Nombre Completo de un Alumno.
 */
struct CompleteName{
    
    const std::string NAME;                                                                                  ///< Nombre del Alumno                                                 
    const std::string PATERNAL_SURNAME;                                                                      ///< Apellido Paterno
    const std::string MATERNAL_SURNAME;                                                                      ///< Apellido Materno                                                                             
    
    CompleteName(
    
        const std::string& name,
        const std::string& paternalSurname,
        const std::string& maternalSurname
    
    ): NAME(name), PATERNAL_SURNAME(paternalSurname), MATERNAL_SURNAME(maternalSurname) {
        
        validateStringField(name, "Name");
        validateStringField(paternalSurname, "Paternal Surname");
        validateStringField(maternalSurname, "Maternal Surname");
    
    };

};

/**
 * @brief Representa una Fecha de Nacimiento.
 */
struct BirthDate{
    
    const int DAY;                                                                                           ///< Día de Nacimiento
    const int MONTH;                                                                                         ///< Mes de Nacimiento
    const int YEAR;                                                                                          ///< Año de Nacimiento
    
    BirthDate(int day, int month, int year): DAY(day), MONTH(month), YEAR(year) {
        
        if (day <= 0 || month <= 0 || year <= 0 || year < 1930) {
            throw std::invalid_argument("Date components must be positive integers.");
        }
        
        std::chrono::year_month_day date{std::chrono::year{year} / std::chrono::month{static_cast<unsigned>(month)} / std::chrono::day{static_cast<unsigned>(day)}};
        if (!date.ok()) {
            throw std::invalid_argument(std::format("Invalid date: {:%d/%m/%Y}", date));
        }
        
        if (std::chrono::sys_days{date} >= TODAY) {
            throw std::out_of_range(std::format("Date cannot be in the future and cannot be today: {:%d/%m/%Y}", date));
        }
    };

};

/**
 * @brief Representa un Lugar de Nacimiento.
 */
struct Place{
    
    const std::string CITY;                                                                                  ///< Ciudad de Nacimiento
    const std::string STATE;                                                                                 ///< Estado de Nacimiento
    const std::string COUNTRY;                                                                               ///< País de Nacimiento

    Place(
        
        const std::string& city, 
        const std::string& state, 
        const std::string& country
    
    ): CITY(city), STATE(state), COUNTRY(country) {

        validateStringField(city, "City");
        validateStringField(state, "State");
        validateStringField(country, "Country");

    };

};

/**
 * @brief Representa a un Alumno. Actúa como Data Class.
 */
struct Student {

    const CompleteName COMPLETE_NAME;
    const BirthDate BIRTHDATE;
    const Place BIRTHPLACE;
    Group group;
    const Sex SEX;
    int id_student;
    EducativeGrade educativeGrade;
    double calification;
 
    Student(
        const CompleteName& nombre,
        const BirthDate& nacimiento,
        const Place& lugar_nacimiento,
        Group grupo,
        Sex sexo,
        EducativeGrade educativeGrade,
        double calif
    ) : COMPLETE_NAME(nombre), BIRTHDATE(nacimiento), BIRTHPLACE(lugar_nacimiento), group(grupo), SEX(sexo), id_student(0), educativeGrade(educativeGrade), calification(calif) {
    
        
        validateDecimalCalification(calif);

        /// Definir Variables
        std::random_device random;
        std::uniform_int_distribution<int> dist(10000000, 99999999);
        int nuevo_id;
        
        /// Obtener ID único para el Alumno, hasta que no se repita con los IDs ya usados
        do {nuevo_id = dist(random);} while (ids_usados.count(nuevo_id));
        
        /// Registrar el ID generado como usado para evitar futuras repeticiones
        ids_usados.insert(nuevo_id);;
        
        /// Asignar el ID generado al Alumno
        id_student = nuevo_id;
    }

    /// @brief  Conjunto de IDs ya usados para garantizar la unicidad de los mismos
    static std::set<int> ids_usados;

};

// =====================================================================================================================================