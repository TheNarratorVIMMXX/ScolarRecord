// =====================================================================================================================================

// DOCUMENTACIÓN:

// Clases

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas e Internas
#pragma once                                                                                                 // Evitar Múltiples INclusiones
#include "../core/structs.hpp"                                                                               // Structs

// =====================================================================================================================================
// ------------------------------------------------------------ Namespace --------------------------------------------------------------

namespace StudentRegister {

    /**
     * @brief Muestra un mensaje de error con pausa y limpieza de pantalla.
     * @param message (const std::string&) Mensaje a mostrar en el banner de error.
     */
    void showError(const std::string& message);

    /**
     * @brief Muestra el contexto del nombre completo del Alumno.
     * @param completeName (const CompleteName&) Nombre Completo del Alumno.
     */
    void showNameContext(const CompleteName& completeName);
    
    /**
     * @brief Muestra el contexto de la fecha de nacimiento del Alumno.
     * @param birthDate (const BirthDate&) Fecha de Nacimiento del Alumno.
     */
    void showBirthDateContext(const BirthDate& birthDate);

    /**
     * @brief Muestra el contexto del lugar de nacimiento del Alumno.
     * @param place (const Place&) Lugar de Nacimiento del Alumno.
     */
    void showPlaceContext(const Place& place);

    /**
     * @brief Pregunta si el usuario desea ver las instrucciones y las muestra si así lo indica.
     */
    void instructions();

    /**
     * @brief Lee y valida el Nombre Completo del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @return Nombre Completo validado como CompleteName.
     */
    CompleteName readCompleteName(int studentNumber);

    /**
     * @brief Lee y valida la Fecha de Nacimiento completa del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param completeName  (const CompleteName&) Nombre Completo ya capturado.
     * @return Fecha de Nacimiento validada como BirthDate.
     */
    BirthDate readBirthDate(int studentNumber, const CompleteName& completeName);
    
    /**
     * @brief Lee y valida el Lugar de Nacimiento del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param completeName  (const CompleteName&) Nombre Completo ya capturado.
     * @param birthDate (const BirthDate&) Fecha de Nacimiento ya capturada.
     * @return Lugar de Nacimiento validado como Place.
     */
    Place readPlace(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate);

    /**
     * @brief Lee y valida el Sexo del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param completeName  (const CompleteName&) Nombre Completo ya capturado.
     * @param birthDate (const BirthDate&) Fecha de Nacimiento ya capturada.
     * @param place (const Place&) Lugar de Nacimiento ya capturado.
     * @return Sexo validado como Sex.
     */
    Sex readSex(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place);

    /**
     * @brief Lee y valida el Grado del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param completeName  (const CompleteName&) Nombre Completo ya capturado.
     * @param birthDate (const BirthDate&) Fecha de Nacimiento ya capturada.
     * @param place (const Place&) Lugar de Nacimiento ya capturado.
     * @param sex (Sex) Sexo del Alumno.
     * @return Grado validado.
     */
    EducativeGrade readGrade(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place, Sex sex);
    
    /**
     * @brief Lee y valida el Grupo del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param completeName  (const CompleteName&) Nombre Completo ya capturado.
     * @param birthDate (const BirthDate&) Fecha de Nacimiento ya capturada.
     * @param place (const Place&) Lugar de Nacimiento ya capturado.
     * @param sex (Sex) Sexo del Alumno.
     * @param grade (EducativeGrade) Grado del Alumno.
     * @return Grupo validado.
     */
    Group readGroup(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place, Sex sex, EducativeGrade grade);

    /**
     * @brief Lee y valida el Promedio Final del Alumno.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param completeName  (const CompleteName&) Nombre Completo ya capturado.
     * @param birthDate (const BirthDate&) Fecha de Nacimiento ya capturada.
     * @param place (const Place&) Lugar de Nacimiento ya capturado.
     * @param sex (Sex) Sexo del Alumno.
     * @param grade (EducativeGrade) Grado del Alumno.
     * @param group (Group) Grupo del Alumno.
     * @return Calificacion validada.
     */
    double readCalification(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place, Sex sex, EducativeGrade grade, Group group);
    
    /**
     * @brief Mensaje de ID generado y mostrado al usuario.
     */
    void showID();

    /**
     * @brief Muestra los datos del Alumno ya construido y solicita confirmación de registro.
     * @param studentNumber (int) Número de Alumno en el registro actual.
     * @param student (const Student&) Instancia de Student ya construida con todos los datos.
     * @return true si el usuario confirma el registro, false si no.
     */
    bool confirmData(int studentNumber, const Student& student);
    
    /**
     * @brief Orquesta la lectura completa de datos y retorna el Student registrado.
     * @param studentNumber Número de Alumno en el registro actual.
     * @return Student construido y confirmado.
     */
   Student readStudentData(int studentNumber);

}

// =====================================================================================================================================