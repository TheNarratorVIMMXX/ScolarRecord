// =====================================================================================================================================

// DOCUMENTACIÓN:

// Helpers

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas e Internas
#include <stdexcept>                                                                                         // Excepciones
#include <algorithm>                                                                                         // Algoritmos de STL
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares

// =====================================================================================================================================
// -------------------------------------------------------------- Helpers ----------------------------------------------------------------

void validateStringField(const std::string& stringField, const std::string& fieldName) {
    
    /*
       - Función: Validar Campos de Texto
       - Argumentos: 
            - stringField (const std::string&): El Campo de Texto a Validar
            - fieldName (const std::string&): El Nombre del Campo a Validar (para Mensajes de Error)
       - Retorno: Ninguno
       - Objetivo: Validar que el Campo de Texto represente una Entidad Válida
    */

    std::string stripString = strip(stringField);

    if(stripString.empty()) throw std::invalid_argument(fieldName + " cannot be empty");

    auto fieldBegin = stripString.begin(), fieldEnd = stripString.end();
    
    if (std::any_of(fieldBegin, fieldEnd, [](unsigned char chr){return std::isdigit(chr);})) {
        throw std::invalid_argument(fieldName + " cannot contain numbers");
    }
    else if (std::any_of(fieldBegin, fieldEnd, [](unsigned char chr){return std::ispunct(chr);})) {
        throw std::invalid_argument(fieldName + " cannot contain punctuation");
    }
}

void validateNumericField(const std::string& numericField, const std::string& fieldName) {

    /*
       - Función: Validar Campos Numéricos
       - Argumentos: 
            - numericField (const std::string&): El Campo Numérico a Validar
            - fieldName (const std::string&): El Nombre del Campo a Validar (para Mensajes de Error)
       - Retorno: Ninguno
       - Objetivo: Validar que el Campo Numérico represente un Número Válido
    */

    auto fieldBegin = numericField.begin(), fieldEnd = numericField.end();

    if(strip(numericField).empty()) throw std::invalid_argument(fieldName + " cannot be empty");
    
    if (!std::all_of(fieldBegin, fieldEnd, [](unsigned char chr){return std::isdigit(chr) || chr == '.';})) {
        throw std::invalid_argument(fieldName + " must be a valid number");
    }

    if (std::count(fieldBegin, fieldEnd, '.') > 1) {
        throw std::invalid_argument(fieldName + " cannot contain more than one decimal point");
    }
}

// =====================================================================================================================================