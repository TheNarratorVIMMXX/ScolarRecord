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
#include <algorithm>                                                                                         // Algoritmos de STL
#include <stdexcept>                                                                                         // Excepciones
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares
#include "../ui/design.hpp"                                                                                  // Diseño de Interfaz
#include "../utils/validators.hpp"                                                                           // Validadores
#include "../utils/constants.hpp"                                                                            // Constantes
#include "../core/operators.hpp"                                                                             // Operadores Sobrecargados

// =====================================================================================================================================
// ------------------------------------------------------------ Registro --------------------------------------------------------------

std::set<int> Student::ids_usados;

namespace StudentRegister {

    void showError(const std::string& message) {
        waitMilliseconds(900);
        clearScreen();
        Design::bannerBegin();
        std::cerr << message;
        Design::bannerEnd();
        waitSeconds(3);
        clearScreen();
    }

    void showNameContext(const CompleteName& completeName) {
        Design::nameOutput(completeName.NAME);
        Design::paternalSurnameOutput(completeName.PATERNAL_SURNAME);
        Design::maternalSurnameOutput(completeName.MATERNAL_SURNAME);
    }

    void showBirthDateContext(const BirthDate& birthDate) {
        Design::dayOutput(birthDate.DAY);
        Design::monthOutput(birthDate.MONTH);
        Design::yearOutput(birthDate.YEAR);
    }

    void showPlaceContext(const Place& place) {
        Design::cityOutput(place.CITY);
        Design::stateOutput(place.STATE);
        Design::countryOutput(place.COUNTRY);
    }

    void instructions() {

        bool valid;
        std::string answer;

        do {
            valid = true;

            Design::confirmation();
            std::cout << "  ***                                                Desea ir a Instrucciones?                                                   *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                          1. SI                                                             *** \n";
            std::cout << "  ***                                                          2. NO                                                             *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                      DESCISION: ";
            std::getline(std::cin, answer);
            Design::bannerEnd();
            waitMilliseconds(900);
            clearScreen();

            if (answer.empty()) {
                showError("  ***                                         ERROR. Ingrese el Dato en la Confirmacion                                          *** \n");
                valid = false;
            } else if (answer.size() > 2) {
                showError("  ***                                            ERROR. Eliga una Opcion Disponible                                              *** \n");
                valid = false;
            } else if (!isdigit(answer[0]) && answer != ConfirmationOption::Yes && answer != ConfirmationOption::No) {
                waitMilliseconds(900);
                clearScreen();
                Design::typeError();
                valid = false;
            } else { 
                int option;

                if (std::any_of(answer.begin(), answer.end(), [](char chr){ return isdigit(chr); })) option = std::stoi(answer);
                else option = (answer == ConfirmationOption::Yes) ? 1 : 2;
 
                if (option == 1) Design::instructions();
                else if (option != 2) {
                    showError("  ***                                             ERROR. Eliga una Opcion Disponible                                             *** \n");
                    valid = false;
                }
                
            }

        } while (!valid);

    }

    CompleteName readCompleteName(int studentNumber) {

        while (true) {

            std::string name, paternalSurname, maternalSurname;
            bool valid;

            Design::initialRegister(studentNumber);

            do {
                valid = true;

                std::cout << "  ***       Ingrese el Nombre del Alumno: ";
                std::getline(std::cin, name);
                Design::bannerEnd();

                if (name.empty()) {
                    showError("  ***                                            ERROR. Este Dato no puede estar Vacio                                           *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    valid = false;
                } else {
                    try { validateStringField(name, "Name"); }
                    catch (const std::exception&) {
                        showError("  ***                     ERROR. Siga el formato indicado para el Nombre. Si tiene dudas vaya a Instrucciones                    *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        valid = false;
                    }
                }

            } while (!valid);

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Apellido Paterno del Alumno: ";
                std::getline(std::cin, paternalSurname);
                Design::bannerEnd();

                if (paternalSurname.empty()) {
                    showError("  ***                                           ERROR. Este Dato no puede estar Vacio                                           *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    Design::nameOutput(name);
                    valid = false;
                } else {
                    try { validateStringField(paternalSurname, "Paternal Surname"); }
                    catch (const std::exception&) {
                        showError("  ***               ERROR. Siga el formato indicado para el Apellido Paterno. Si tiene dudas vaya a Instrucciones                *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        Design::nameOutput(name);
                        valid = false;
                    }
                }

            } while (!valid);

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Apellido Materno del Alumno: ";
                std::getline(std::cin, maternalSurname);
                Design::bannerEnd();

                if (maternalSurname.empty()) {
                    showError("  ***                                            ERROR. Este Dato no puede estar Vacio                                           *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    Design::nameOutput(name);
                    Design::paternalSurnameOutput(paternalSurname);
                    valid = false;
                } else {
                    try { validateStringField(maternalSurname, "Maternal Surname"); }
                    catch (const std::exception&) {
                        showError("  ***               ERROR. Siga el formato indicado para el Apellido Materno. Si tiene dudas vaya a Instrucciones                *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        Design::nameOutput(name);
                        Design::paternalSurnameOutput(paternalSurname);
                        valid = false;
                    }
                }

            } while (!valid);

            try {
                return CompleteName(name, paternalSurname, maternalSurname);
            } catch (const std::exception&) {
                showError("  ***                 ERROR. El Nombre Completo ingresado no es valid. Verifique los datos e intentelo de nuevo                  *** \n");
                instructions();
                Design::initialRegister(studentNumber);
            }

        }

    }

    BirthDate readBirthDate(int studentNumber, const CompleteName& completeName) {

        int day, month, year;
        std::string day_str, month_str, year_str;
        bool valid;

        while (true) {

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Dia de Nacimiento del Alumno: ";
                std::getline(std::cin, day_str);
                Design::bannerEnd();

                if (day_str.empty()) {
                    showError("  ***                                 ERROR. El Dia de Nacimiento del Alumno no puede estar Vacio                                *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    valid = false;
                } else if (day_str.size() > 2) {
                    showError("  ***                                           ERROR. Eliga un Dia disponible (1 - 31)                                          *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    valid = false;
                } else if (!std::all_of(day_str.begin(), day_str.end(), ::isdigit)) {
                    waitMilliseconds(900);
                    clearScreen();
                    Design::typeError();
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    valid = false;
                } 
                else {
                    day = std::stoi(day_str);
                    if (day < 1 || day > 31) {
                        showError("  ***                                        ERROR. El valor del Dia debe estar entre 1 y 31                                     *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        valid = false;
                    }
                }

            } while (!valid);

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Numero de Mes de Nacimiento del Alumno: ";
                std::getline(std::cin, month_str);
                Design::bannerEnd();

                if (month_str.empty()) {
                    showError("  ***                                ERROR. El Mes de Nacimiento del Alumno no puede estar Vacio                                 *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    Design::dayOutput(day);
                    valid = false;
                } else if (month_str.size() > 2) {
                    showError("  ***                                              ERROR. Eliga un Mes disponible (1 - 12)                                       *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    Design::dayOutput(day);
                    valid = false;
                } else if (!std::all_of(month_str.begin(), month_str.end(), ::isdigit)) {
                    waitMilliseconds(900);
                    clearScreen();
                    Design::typeError();
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    Design::dayOutput(day);
                    valid = false;
                } else {
                    month = std::stoi(month_str);
                    if (month < 1 || month > 12) {
                        showError("  ***                                       ERROR. El valor del Mes debe estar entre 1 y 12                                      *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        Design::dayOutput(day);
                        valid = false;
                    } 
                }

            } while (!valid);

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Anno de Nacimiento del Alumno: ";
                std::getline(std::cin, year_str);
                Design::bannerEnd();

                if (year_str.empty()) {
                    showError("  ***                                ERROR. El Anno de Nacimiento del Alumno no puede estar Vacio                                *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    Design::dayOutput(day);
                    Design::monthOutput(month);
                    valid = false;
                } else if (year_str.size() > 4) {
                    showError("  ***                                                ERROR. Eliga un Anno valido                                                 *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    Design::dayOutput(day);
                    Design::monthOutput(month);
                    valid = false;
                } else if (!std::all_of(year_str.begin(), year_str.end(), ::isdigit)) {
                    waitMilliseconds(900);
                    clearScreen();
                    Design::typeError();
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    Design::dayOutput(day);
                    Design::monthOutput(month);
                    valid = false;
                } else {
                    year = std::stoi(year_str);
                    if (year < 1930 || year >= ACTUAL_YEAR) {
                        showError("  ***                                              ERROR. Eliga un Anno no actual                                               *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        Design::dayOutput(day);
                        Design::monthOutput(month);
                        valid = false;
                    }
                }

            } while (!valid);

            try {
                return BirthDate(day, month, year);
            } catch (const std::exception&) {
                showError("  ***                 ERROR. La fecha ingresada no es valida. Verifique el dia, mes y anno e intentelo de nuevo                  *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                Design::dayOutput(day);
                Design::monthOutput(month);
                Design::yearOutput(year);
            }

        }

    }

    Place readPlace(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate) {

        std::string city, state, country;
        bool valid;

        while (true) {

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese la Ciudad de Nacimiento del Alumno: ";
                std::getline(std::cin, city);
                Design::bannerEnd();

                if (city.empty()) {
                    showError("  ***                                            ERROR. Este Dato no puede estar Vacio                                           *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    valid = false;
                } 
                else {
                    try {validateStringField(city, "City");}
                    catch (const std::exception&) {
                        showError("  ***                     ERROR. Siga el formato indicado para la Ciudad. Si tiene dudas vaya a Instrucciones                    *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        showBirthDateContext(birthDate);
                        valid = false;
                    }
                }

            } while (!valid);


            do {

                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Estado de Nacimiento del Alumno: ";
                std::getline(std::cin, state);
                Design::bannerEnd();

                if (state.empty()) {
                    showError("  ***                                               ERROR. Este Dato no puede estar Vacio                                        *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    Design::cityOutput(city);
                    valid = false;
                } else {
                    try { validateStringField(state, "State"); }
                    catch (const std::exception&) {
                        showError("  ***                     ERROR. Siga el formato indicado para el Estado. Si tiene dudas vaya a Instrucciones                    *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        showBirthDateContext(birthDate);
                        Design::cityOutput(city);
                        valid = false;
                    }
                }

            } while (!valid);

            do {
                valid = true;

                std::cout << "  ***                                                                                                                            *** \n";
                std::cout << "  ***       Ingrese el Pais de Nacimiento del Alumno: ";
                std::getline(std::cin, country);
                Design::bannerEnd();

                if (country.empty()) {
                    showError("  ***                                               ERROR. Este Dato no puede estar Vacio                                        *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    Design::cityOutput(city); 
                    Design::stateOutput(state);
                    valid = false;
                } 
                else {
                    try {validateStringField(country, "Country");}
                    catch (const std::exception&) {
                        showError("  ***                      ERROR. Siga el formato indicado para el Pais. Si tiene dudas vaya a Instrucciones                     *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        showBirthDateContext(birthDate);
                        Design::cityOutput(city);
                        Design::stateOutput(state);
                        valid = false;
                    }
                }

            } while (!valid);

            try {return Place(city, state, country);} 
            catch (const std::exception&) {
                showError("  ***                ERROR. El Lugar de Nacimiento ingresado no es valido. Verifique los datos e intentelo de nuevo                *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                showBirthDateContext(birthDate); 
            }

        }

    }

    Sex readSex(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place) {

        bool valid;
        char sex;
        std::string sex_str;

        do {
            valid = true;

            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       Ingrese el Sexo del Alumno (M - Masculino / F - Femenino): ";
            std::getline(std::cin, sex_str);
            Design::bannerEnd();

            if (sex_str.empty()) {
                showError("  ***                                            ERROR. El Sexo no puede estar Vacio                                             *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                valid = false;
            } else if (sex_str.size() > 1) {
                showError("  ***                                     ERROR. Solo se permite ingresar una letra (M / F)                                      *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                valid = false;
            } else {
                sex = std::toupper(sex_str[0]);
                if (sex != 'M' && sex != 'F') {
                    showError("  ***                                     ERROR. Solo se permite ingresar una letra (M / F)                                      *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    showPlaceContext(place);
                    valid = false;
                }
            }

        } while (!valid);

        return static_cast<Sex>(sex);

    }

    EducativeGrade readGrade(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place, Sex sex){
 
        bool valid;
        int grade;
        std::string grade_str;

        do {
            valid = true;

            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       Ingrese el Grado del Alumno: ";
            std::getline(std::cin, grade_str);
            Design::bannerEnd();

            if (grade_str.empty()) {
                showError("  ***                                            ERROR. El Grado no puede estar Vacio                                            *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                Design::sexOutput(sex);
                valid = false;
            } else if (!std::all_of(grade_str.begin(), grade_str.end(), ::isdigit)) {
                waitMilliseconds(900);
                clearScreen();
                Design::typeError();
                instructions();
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                Design::sexOutput(sex);
                valid = false;
            } else {
                grade = std::stoi(grade_str);
                if (grade < 1 || grade > 8) {
                    showError("  ***                                           ERROR. El Grado debe estar entre 1 y 8                                           *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    showPlaceContext(place);
                    Design::sexOutput(sex);
                    valid = false;
                }
            }

        } while (!valid);

        return static_cast<EducativeGrade>(grade);

    }

    Group readGroup(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place, Sex sex, EducativeGrade grade) {

        bool valid;
        char group;
        std::string group_str;
        
        do {
            valid = true;

            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       Ingrese el Grupo del Alumno: ";
            std::getline(std::cin, group_str);
            Design::bannerEnd();

            if (group_str.empty()) {
                showError("  ***                                            ERROR. El Grupo no puede estar Vacio                                            *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                Design::sexOutput(sex);
                Design::gradeOutput(grade);
                valid = false;
            } else if (group_str.size() > 1) {
                showError("  ***                                     ERROR. Solo se permite ingresar una letra (A - Z)                                      *** \n");
                instructions();
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                Design::sexOutput(sex);
                Design::gradeOutput(grade);
                valid = false;
            } else {
                try { validateStringField(group_str, "Group"); } catch (const std::exception&) {
                    showError("  ***                                     ERROR. Solo se permite ingresar una letra (A - Z)                                      *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    showPlaceContext(place);
                    Design::sexOutput(sex);
                    Design::gradeOutput(grade);
                    valid = false;
                }
                if (valid) {
                    group = group_str[0];
                    if (ALPHABET.find(group) == std::string_view::npos) {
                        showError("  ***                                     ERROR. Solo se permite ingresar una letra (A - Z)                                      *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        showBirthDateContext(birthDate);
                        showPlaceContext(place);
                        Design::sexOutput(sex);
                        Design::gradeOutput(grade);
                        valid = false;
                    }
                }
            }
        } while (!valid);

        return static_cast<Group>(group);

    }

    double readCalification(int studentNumber, const CompleteName& completeName, const BirthDate& birthDate, const Place& place, Sex sex, EducativeGrade grade, Group group) {

        bool valid;
        double calif;
        std::string calif_str;

        do {
            valid = true;

            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       Ingrese el Promedio Final en el curso del Alumno: ";
            std::getline(std::cin, calif_str);
            Design::bannerEnd();

            if (calif_str.empty()) {
                showError("  ***                                          ERROR. La Calificacion no puede estar Vacia                                       *** \n");
                instructions();
                Design::initialRegister(studentNumber);
                showNameContext(completeName);
                showBirthDateContext(birthDate);
                showPlaceContext(place);
                Design::sexOutput(sex);
                Design::gradeOutput(grade);
                Design::groupOutput(group);
                valid = false;
            } else {

                try{validateNumericField(calif_str, "Calification");}catch(const std::exception&){
                    showError("  ***                                         ERROR. Ingrese un Numero Entero o Decimal                                          *** \n");
                    instructions();
                    Design::initialRegister(studentNumber);
                    showNameContext(completeName);
                    showBirthDateContext(birthDate);
                    showPlaceContext(place);
                    Design::sexOutput(sex);
                    Design::gradeOutput(grade);
                    Design::groupOutput(group);
                    valid = false;
                } 
                if (valid) {
                    calif = std::stod(calif_str);
                    try{validateDecimalCalification(calif);} catch(const std::exception&){
                        showError("  ***                                        ERROR. El Rango de Calificacion es de 0 - 10                                        *** \n");
                        instructions();
                        Design::initialRegister(studentNumber);
                        showNameContext(completeName);
                        showBirthDateContext(birthDate);
                        showPlaceContext(place);
                        Design::sexOutput(sex);
                        Design::gradeOutput(grade);
                        Design::groupOutput(group);
                        valid = false;
                    }
                }
            }

        } while (!valid);

        clearScreen();

        return calif;

    }

    void showID() {
        Design::bannerBegin();
        std::cout << "  ***                                                                                                                            *** \n";
        std::cout << "  ***           EL ID DEL ALUMNO SE GENERARA ALEATORIAMENTE POR COMPUTADORA, TENDRA 8 DIGITOS Y SERA UNA CLAVE UNICA             *** \n";
        Design::bannerEnd();
        waitSeconds(5);
        clearScreen();
    }

    bool confirmData(int studentNumber, const Student& student) {

        bool valid;
        int option;
        std::string answer;

        do {
            valid = true;

            Design::confirmation();
            std::cout << "  ***                                                           ALUMNO " << studentNumber << "                                                         *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       NOMBRE:     " << student.COMPLETE_NAME << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       NACIMIENTO: " << student.BIRTHDATE <<"\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       LUGAR:      " << student.BIRTHPLACE << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       SEXO:       " << static_cast<char>(student.SEX) << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       GRADO:      " << static_cast<int>(student.educativeGrade) << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       GRUPO:      " << static_cast<char>(student.group) << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       PROMEDIO:   " << student.calification << "\n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***       ID:         " << student.id_student << "\n";
            Design::bannerEnd();
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                         REGISTRAR?                                                         *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                           1. SI                                                            *** \n";
            std::cout << "  ***                                                           2. NO                                                            *** \n";
            std::cout << "  ***                                                                                                                            *** \n";
            std::cout << "  ***                                                        DECISION: ";
            std::getline(std::cin, answer);
            Design::bannerEnd();
            if (answer.empty()) {
                showError("  ***                                         ERROR. Ingrese el Dato en la Confirmacion                                          *** \n");
                valid = false;
            } else if (answer.size() > 1) {
                showError("  ***                                            ERROR. Eliga una Opcion Disponible                                              *** \n");
                valid = false;
            } else if (!isdigit(answer[0]) && answer != ConfirmationOption::Yes && answer != ConfirmationOption::No) {
                waitMilliseconds(900);
                clearScreen();
                Design::typeError();
                valid = false;
            } else { 

                if (std::any_of(answer.begin(), answer.end(), [](char chr){ return isdigit(chr); })) option = std::stoi(answer);
                else option = (answer == ConfirmationOption::Yes) ? 1 : 2;

                if (option != 1 && option != 2) {
                    showError("...");
                    valid = false;
                }
                
            }

        } while (!valid);

        clearScreen();

        return option == 1;

    }
 
    Student readStudentData(int studentNumber) {

        bool confirm = false;
        while (true){

            CompleteName completeName = readCompleteName(studentNumber);
            BirthDate birthDate = readBirthDate(studentNumber, completeName);
            Place birthPlace = readPlace(studentNumber, completeName, birthDate);
            Sex sex = readSex(studentNumber, completeName, birthDate, birthPlace);
            EducativeGrade grade = readGrade(studentNumber, completeName, birthDate, birthPlace, sex);
            Group group = readGroup(studentNumber, completeName, birthDate, birthPlace, sex, grade);
            double calification = readCalification(studentNumber, completeName, birthDate, birthPlace, sex, grade, group);
            showID();

            try {

                Student student(completeName, birthDate, birthPlace, group, sex, grade, calification);
                confirm = confirmData(studentNumber, student);
                if (confirm) {
                    waitMilliseconds(900);
                    clearScreen();
                    return student;
                }

            } catch (const std::exception&) {
                showError("  ***                        ERROR. No se pudo registrar al Alumno. Verifique los datos e intentelo de nuevo                       *** \n");
                instructions();
            }
            
        }
        }

}

// =====================================================================================================================================