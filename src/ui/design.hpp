// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de UI 

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include "../core/structs.hpp"                                                                               // Structs

// =====================================================================================================================================
// -------------------------------------------------------------- UI----------------------------------------------------------------

/**
 * @brief Diseño de UI.
 */
namespace Design{

    /**
     * @brief Inicio del Banner.
     */
    void bannerBegin();

    /**
     * @brief Fin del Banner.
     */
    void bannerEnd();
    
    /**
     * @brief Portada.
     */
    void cover();

    /**
     * @brief Error de Tipo de Dato.
     */
    void typeError();
    
    /**
     * @brief Input del Número de Estudiantes a Registrar.
     * @param studentsNum (int&): Número de Estudiantes a Registrar.
     */
    void studentsInput(int& studentsNum);

    /**
     * @brief inicio del Registro.
     * @param studentnum (int&): Número de Estudiante al que se Registrará.
     */
    void initialRegister(int studentNum);
 
    /**
     * @brief Imprimir Nombre 
     * @param completeName (const CompleteName&): Nombre Completo del Estudiante.
     */
    void nameOutput (const std::string& name);
  
    /**
     * @brief Imprimir Apellido Paterno.
     * @param completeName (const CompleteName&): Nombre Completo del Estudiante.
     */
    void paternalSurnameOutput (const std::string& paternalSurname);

    /**
     * @brief Imprimir Apellido Materno.
     * @param completeName (const CompleteName&): Nombre Completo del Estudiante.
     */
    void maternalSurnameOutput (const std::string& maternalSurname);

    /**
     * @brief Imprimir Grado
     * @param grade (int): Grado del Estudiante.
     */
    void gradeOutput (EducativeGrade grade);

    /**
     * @brief Imprimir Grupo.
     * @param group (char): Grupo del Estudiante.
     */
    void groupOutput (Group group);

    /**
     * @brief Confirmación de Registro.
     */
    void confirmation();

    /**
     * @brief Instrucciones.
     */
    void instructions();

    /**
     * @brief Imprimir Día de Nacimiento.
     * @param day (int): Día de Nacimiento del Estudiante.
     */
    void dayOutput(int day);
    
    /**
     * @brief Imprimir Mes de Nacimiento.
     * @param month (int): Mes de Nacimiento del Estudiante.
     */
    void monthOutput(int month);
    
    /**
     * @brief Imprimir Año de Nacimiento.
     * @param year (int): Año de Nacimiento del Estudiante.
     */
    void yearOutput(int year);
    
    /**
     * @brief Imprimir Calificación.
     * @param calification (double): Calificación del Estudiante.
     */
    void calificationOutput(double calification);

    /**
     * @brief Imprimir Ciudad.
     * @param city (std::string): Ciudad del Estudiante.
     */
    void cityOutput(const std::string& city);
    
    /**
     * @brief Imprimir Estado.
     * @param state (std::string): Estado del Estudiante.
     */
    void stateOutput(const std::string& state);

    /**
     * @brief Imprimir País.
     * @param country (std::string): País del Estudiante.
     */
    void countryOutput(const std::string& country); 

    /**
     * @brief Imprimir Sexo
     */
    void sexOutput(Sex sex);

}

// =====================================================================================================================================