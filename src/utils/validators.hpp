// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de Funciones para Validar los Datos de Entrada

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include <string>                                                                                            // Librería de Cadenas
#include <stdexcept>                                                                                         // Excepciones

// =====================================================================================================================================
// -------------------------------------------------------------- Validadores ----------------------------------------------------------------

/**
 * @brief Valida un Campo de Texto.
 * @param stringField (const std::string&): Campo de Texto a Validar.
 * @param fieldName (const std::string&): Nombre del Campo a Validar (para Mensajes de Error).
 * @throws std::invalid_argument Si el Campo está Vacío o Contiene Caracteres No Permitidos.
 */
void validateStringField(const std::string& stringField, const std::string& fieldName);

/**
 * @brief Valida un Campo Numérico.
 * @param numericField (const std::string&): Campo Numérico a Validar.
 * @param fieldName (const std::string&): Nombre del Campo a Validar (para Mensajes de Error).
 * @throws std::invalid_argument Si el Campo está Vacío o Contiene Caracteres No Permitidos.
 */
void validateNumericField(const std::string& numericField, const std::string& fieldName);

/**
 * @brief Valida que una Calificación Decimal esté dentro del Rango Permitido (0.0 - 10.0).
 * @param calif (double): Calificación a Validar.
 */
inline void validateDecimalCalification(double calif) {
    if (calif < 0.0 || calif > 10.0) throw std::out_of_range("Calificacion must be between 0.0 and 10.0");
}

// =====================================================================================================================================