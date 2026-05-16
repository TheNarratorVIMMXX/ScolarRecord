// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de Constantes Globales

// Ultima Modificacion: 16/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include <string>                                                                                            // Librería de Cadenas
#include <limits>                                                                                            // Límites Numéricos
#include <iostream>                                                                                          // Librería de Entrada y Salida
#include <chrono>                                                                                           // Funciones de Tiempo

// =====================================================================================================================================
// -------------------------------------------------------------- Constantes ----------------------------------------------------------------

/**
 * @brief Límite Máximo para Entradas Numéricas 
 */
inline constexpr std::streamsize MAX_LIMIT = std::numeric_limits<std::streamsize>::max();

/**
 * @brief Sexo del Alumno
 */
enum class Sex {Male = 'M', Female = 'F'};

/**
 * @brief Enumeración para el Abecedario en Mayúscula para Validar el Grupo del Alumno
 */
enum class Group {
    A = 'A', 
    B = 'B', 
    C = 'C', 
    D = 'D', 
    E = 'E', 
    F = 'F', 
    G = 'G', 
    H = 'H', 
    I = 'I', 
    J = 'J', 
    K = 'K', 
    L = 'L', 
    M = 'M', 
    N = 'N', 
    O = 'O', 
    P = 'P', 
    Q = 'Q', 
    R = 'R', 
    S = 'S', 
    T = 'T', 
    U = 'U', 
    V = 'V', 
    W = 'W', 
    X = 'X', 
    Y = 'Y', 
    Z = 'Z'
};

/**
 * @brief Enumeración para los Grados Educativos
 */
enum class EducativeGrade {
    First = 1,
    Second = 2,
    Third = 3,
    Fourth = 4,
    Fifth = 5,
    Sixth = 6,
    Seven = 7,
    Eight = 8
};

/**
 * @brief Opciones de Confirmación para el Usuario
 */
namespace ConfirmationOption {
    constexpr std::string_view Yes = "SI";
    constexpr std::string_view No = "NO";
}

/**
 * @brief Constante para la Fecha Actual.
 */
inline const auto TODAY = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());

/**
 * @brief Constante para el Año Actual.
 */
inline const int ACTUAL_YEAR = static_cast<int>(
    std::chrono::year_month_day(
        std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())
    ).year());

/**
 * @brief Constante para el Abecedario.
 */
inline constexpr std::string_view ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// =====================================================================================================================================
