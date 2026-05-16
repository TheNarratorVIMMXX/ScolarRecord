// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de Funciones Auxiliares (Helpers)

// Ultima Modificacion: 15/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include <iostream>                                                                                          // Librería de Entrada y Salida
#include <chrono>                                                                                            // Tiempo y de Duración
#include <thread>                                                                                            // Hilos de Ejecución
#include <string>                                                                                            // Librería de Cadenas

// =====================================================================================================================================
// ------------------------------------------------------------ Helpers --------------------------------------------------------------
 
/**
 * @brief Función que Espera una Cantidad de Segundos Específica.
 * @param seconds (int): La Cantidad de Segundos a Esperar.
 */
inline void waitSeconds(int seconds){std::this_thread::sleep_for(std::chrono::seconds(seconds));}

/**
 * @brief Función que Espera una Cantidad de Milisegundos Específica.
 * @param milliseconds (int): La Cantidad de Milisegundos a Esperar.
 */
inline void waitMilliseconds(int milliseconds){std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));} 

/**
 * @brief Limpiar la Pantalla 
 */
void clearScreen();

/**
 * @brief Pausar la Ejecución 
 */
void pauseExecution();

/**
 * @brief Eliminar Espacios en Blanco de un String al Inicio y al Final.
 * @param text (const string&): El String del cual eliminar espacios.
 * @return string: El String sin espacios al inicio y al final.
 */
std::string strip(const std::string& text);

// =====================================================================================================================================