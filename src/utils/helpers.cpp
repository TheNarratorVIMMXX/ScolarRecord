// =====================================================================================================================================

// DOCUMENTACIÓN:

// Helpers

// Ultima Modificacion: 15/05/26
// Fecha Original de Realización: 22/06/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas e Internas
#include <cstdlib>                                                                                           // Librería Estándar de C
#include <algorithm>                                                                                         // Algoritmos de STL
#include <cctype>                                                                                            // Funciones de Caracteres
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares
#include "../utils/constants.hpp"                                                                            // Constantes

// =====================================================================================================================================
// -------------------------------------------------------------- Sistema Operativo ----------------------------------------------

/// Detectar el Sistema Operativo
#ifdef _WIN32                                                                                                // Windows
    #include <windows.h>                                                                                     // Librería de Windows
    #define IS_WINDOWS true                                                                                  // Definir Constante para Windows
#else                                                                                                        // POSIX (Linux, macOS)
    #include <unistd.h>                                                                                      // Librería de POSIX
    #include <term.h>                                                                                        // Librería de Terminal POSIX
    #define IS_WINDOWS false                                                                                 // Definir Constante para POSIX
#endif                                                                                                       // Fin de Detección del OS

// =====================================================================================================================================
// -------------------------------------------------------------- Helpers ----------------------------------------------------------------

void clearScreen(){

    /*
       - Función: Limpiar Pantalla
       - Argumentos: Ninguno 
       - Retorno: Ninguno
       - Objetivo: Limpiar la Pantalla de la Consola
    */

    /// Limpiar Pantalla
    #ifdef _WIN32                                                                                            // Windows
        system("cls");                                                                                       // Limpiar Pantalla en Windows
    #else                                                                                                    // POSIX (Linux, macOS)
        if (system("clear") != 0) cout << "\033[2J\033[1;1H";                                                // Limpiar Pantalla en POSIX
    #endif                                                                                                   // Fin de la Detección del OS

}

void pauseExecution() {
    
    /*
       - Función: Pausar Ejecución
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Pausar la Ejecución hasta que el Usuario presione Enter
    */

    /// Pausar Ejecución
    #ifdef _WIN32
        std::cout << "Pulsa cualquier tecla para continuar..." << "\n";                                          
        std::getchar();
    #else
        system("bash -c \"read -n1 -s -p 'Pulsa cualquier tecla para continuar...'\"");
        cout << "\n";
    #endif

}

std::string strip(const std::string& text){

    /*
       - Función: Eliminar Espacios en Blanco
       - Argumentos: 
            - text (const string&): El String del cual eliminar espacios.
       - Retorno: 
            - string: El String sin espacios al inicio y al final.
       - Objetivo: Eliminar los Espacios en Blanco al Inicio y al Final de un String
    */

    /// Obtener el Iterador que representa la Posición del Primer Carácter No Espacio
    auto start = std::find_if_not(
        text.begin(),
        text.end(),
        [](unsigned char chr){return isspace(chr);}
    );

    /// Obtener el Iterador que representa la Posición del Último Carácter No Espacio
    auto end = std::find_if_not(
        text.rbegin(),
        text.rend(),
        [](unsigned char chr){return std::isspace(chr);}
    ).base();
    
    /// Retornar nuevo string si el Primer Carácter Encontrado es Menor que el Último Carácter Encontrado
    return (start < end) ? std::string(start, end) : "";
}

// =====================================================================================================================================