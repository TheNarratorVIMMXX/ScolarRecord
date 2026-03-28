
/**
 * @file librerias_comunes.h
 * @brief Archivo que agrupa las Librerías Más Usadas en el proyecto
 *
 * Este archivo incluye todas las Librerías Estándar para evitar su
 * repetición en cada Archivo Fuente.
 *
 * Está organizado por Bloques Temáticos para facilitar su Búsqueda,
 * Mantenimiento y Lectura.
 *
 * Modo de Uso:
 *
 * ```cpp
 * #include "librerias_comunes.h"
 * ```
 *
 * Todo esto con el objetivo de Incluir todas las Librerías Necesarias
 * y que estén Disponibles.
 */

/// @brief Protección contra Inclusiones Múltiples del Archivo de Cabecera
#ifndef LIBRERIAS_COMUNES
#define LIBRERIAS_COMUNES


/// ============= Entrada y Salida Estándar =============

/// @brief Librería para Entrada y Salida Básica
#include <iostream>

/// @brief Librería para Manejo de Cadenas de Texto
#include <string>



/// ================= Funciones de Duración y Tiempo =================

/// @brief Librería para Funciones de Duración y Tiempo
#include <chrono>

/// @brief Librería para el Manejo y Creación de Hilos de Ejecución
#include <thread>



/// ================ Contenedores y Estructuras ================

/// @brief Librería para Manejo de Vectores Dinámicos
#include <vector>

/// @brief Librería para Contenedores Ordenados no Duplicados
#include <set>



/// ================ Funciones y Utilidades Extras ================

/// @brief Librería para Características de Tipos de Datos
#include <limits>

/// @brief Librería para Uso de Algoritmos
#include <algorithm>

/// @brief Librería para Funciones de Caracteres
#include <cctype>

/// @brief Librería de Aleatoriedad
#include <random>


#endif  // LIBRERIAS_COMUNES
