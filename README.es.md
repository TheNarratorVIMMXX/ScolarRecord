[![en](https://img.shields.io/badge/lang-en-blue.svg)](README.md)

# 📋 Sistema de Registro Escolar

![C++](https://img.shields.io/badge/C%2B%2B-23-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Plataforma-Multiplataforma-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Type](https://img.shields.io/badge/Tipo-App_de_Consola-8B008B?style=for-the-badge)
![Version](https://img.shields.io/badge/Versión-1.0-orange?style=for-the-badge)
![License](https://img.shields.io/badge/Licencia-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Estado-Abandonado-red?style=for-the-badge)

Sistema de registro escolar por consola desarrollado en C++23 con soporte multiplataforma. Permite registrar alumnos con validación robusta de datos, generación automática de IDs únicos y una interfaz visual con arte ASCII.

---

## ⚠️ Estado del Proyecto: Abandonado

Este proyecto fue desarrollado como ejercicio de aprendizaje y actualmente se encuentra **incompleto y abandonado**.

La razón principal es que, durante el desarrollo, se adquirió conocimiento sobre la existencia de bases de datos relacionales, lo que hace que el enfoque de almacenar registros en memoria a través de una interfaz de consola sea poco práctico para un sistema de registro real. Una solución con base de datos (SQL, SQLite, PostgreSQL, etc.) resolvería de forma más adecuada los problemas de persistencia, búsqueda, edición y escalabilidad que este proyecto intentaba abordar manualmente.

El código queda disponible como referencia de aprendizaje en C++.

---

## 🎬 Vista Previa

<div align="center">
  <img src="assets/preview.gif" alt="Sistema de Registro Escolar Vista Previa"/>
</div>

---

## 👨‍💻 Información del Desarrollador

| Campo | Detalle |
|-------|---------|
| **Desarrollador** | Magallanes López Carlos Gabriel |
| **Correo** | cgmagallanes23@gmail.com |
| **Versión** | 1.0 |
| **Fecha de inicio** | 22 de junio de 2025 |

---

## 🎯 Descripción

ScolarRecord es una aplicación de terminal que simula el registro de alumnos de una institución educativa. Captura y valida datos personales y académicos, generando automáticamente un ID único de 8 dígitos por alumno.

---

## 🗂️ Estructura del Proyecto

```
ScolarRecord/
├── main.cpp                  # Punto de entrada
├── core/
│   ├── structs.hpp           # Definición de estructuras de datos
│   ├── register.hpp          # Declaración del namespace StudentRegister
│   ├── register.cpp          # Lógica de captura y validación de datos
│   └── operators.hpp         # Sobrecarga de operadores de salida (<<)
├── ui/
│   ├── design.hpp            # Declaración del namespace Design
│   └── design.cpp            # Implementación de la interfaz ASCII
└── utils/
    ├── constants.hpp         # Constantes y enumeraciones globales
    ├── helpers.hpp           # Declaración de funciones auxiliares
    ├── helpers.cpp           # Implementación de funciones auxiliares
    ├── validators.hpp        # Declaración de validadores
    └── validators.cpp        # Implementación de validadores
```

---

## 🧱 Estructuras de Datos

### `CompleteName`
Nombre completo dividido en tres campos: nombre, apellido paterno y apellido materno. Los tres campos se validan en el constructor.

### `BirthDate`
Fecha de nacimiento con día, mes y año. Valida que la fecha sea real y no futura usando `std::chrono`.

### `Place`
Ciudad, estado y país de nacimiento. Cada campo se valida individualmente.

### `Student` (Clase Principal)
Estructura principal que agrupa todos los datos del alumno:

| Campo | Tipo | Descripción |
|-------|------|-------------|
| `COMPLETE_NAME` | `CompleteName` | Nombre completo |
| `BIRTHDATE` | `BirthDate` | Fecha de nacimiento |
| `BIRTHPLACE` | `Place` | Lugar de nacimiento |
| `SEX` | `Sex` | Sexo (`M` / `F`) |
| `educativeGrade` | `EducativeGrade` | Grado escolar (1–8) |
| `group` | `Group` | Grupo (letra A–Z) |
| `calification` | `double` | Promedio final (0.0–10.0) |
| `id_student` | `int` | ID único de 8 dígitos (generado automáticamente) |

---

## 🔄 Flujo del Programa

```
INICIO
    ↓
Mostrar portada (animación ASCII)
    ↓
Ingresar cantidad de alumnos a registrar
    ↓
┌──────────────────────────────────────────────────┐
│              BUCLE POR CADA ALUMNO               │
│                                                  │
│  1.  Nombre                                      │
│  2.  Apellido Paterno                            │
│  3.  Apellido Materno                            │
│  4.  Día de Nacimiento                           │
│  5.  Mes de Nacimiento                           │
│  6.  Año de Nacimiento                           │
│  7.  Ciudad de Nacimiento                        │
│  8.  Estado de Nacimiento                        │
│  9.  País de Nacimiento                          │
│  10. Sexo (M / F)                                │
│  11. Grado (1–8)                                 │
│  12. Grupo (A–Z)                                 │
│  13. Promedio Final                              │
│  14. ID (generado automáticamente)               │
│                                                  │
│  → Pantalla de confirmación                      │
│     1 / SI → Guardar y continuar                 │
│     2 / NO → Repetir registro                    │
└──────────────────────────────────────────────────┘
    ↓
FIN
```

Cada campo se valida de forma independiente. Si hay un error, se muestra el mensaje correspondiente con el contexto de los datos ya ingresados y se pide reingresar solo el campo incorrecto. Si la creación de la estructura falla, se reinician todos sus campos.

---

## ✅ Reglas de Validación

| Campo | Regla |
|-------|-------|
| Nombre / Apellidos | Solo letras y espacios, no puede estar vacío |
| Día | Solo dígitos, máximo 2 caracteres, rango 1–31 |
| Mes | Solo dígitos, máximo 2 caracteres, rango 1–12 |
| Año | Solo dígitos, máximo 4 caracteres, desde 1930 hasta el año actual |
| Fecha completa | Validada con `std::chrono::year_month_day`, no puede ser futura |
| Ciudad / Estado / País | Solo letras y espacios, no puede estar vacío |
| Sexo | Un solo carácter: `M` o `F` (no distingue mayúsculas) |
| Grado | Número entero entre 1 y 8 |
| Grupo | Una sola letra A–Z |
| Promedio | Número decimal entre 0.0 y 10.0 |

---

## 🔧 Implementación Técnica

### Soporte Multiplataforma

| Plataforma | Versión Mínima |
|------------|---------------|
| **Windows** | Windows 10 |
| **Linux** | Ubuntu 18.04+ |
| **macOS** | macOS 10.14+ |

La limpieza de pantalla y la pausa interactiva se implementan con compilación condicional:

```cpp
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
```

### Generación de IDs Únicos

```cpp
std::random_device random;
std::uniform_int_distribution<int> dist(10000000, 99999999);
// Se verifica contra un std::set<int> de IDs ya usados
do { nuevo_id = dist(random); } while (ids_usados.count(nuevo_id));
ids_usados.insert(nuevo_id);
```

---

## 📚 Conceptos Demostrados

- **Structs con constructores y validación** en C++
- **Namespaces** para organización del código (`Design`, `StudentRegister`)
- **Manejo de excepciones** con `try/catch` para flujo de validación
- **Sobrecarga de operadores** (`<<`) para impresión de estructuras
- **STL:** `std::vector`, `std::set`, `std::string`, `std::chrono`
- **Números aleatorios** con `std::random_device` y `std::uniform_int_distribution`
- **Enumeraciones** (`enum class`) para tipos con dominio acotado
- **Compilación condicional** para soporte multiplataforma
- **Separación de responsabilidades** en múltiples archivos y namespaces

---

## 🔧 Compilación y Ejecución

### Requisitos

| Componente | Requisito |
|------------|-----------|
| **Compilador** | GCC con soporte C++23 (GCC 13+) |
| **SO** | Windows 10/11, Linux o macOS |

### Comando de Compilación

```bash
g++ -std=c++23 -o ScolarRecord main.cpp core/register.cpp ui/design.cpp utils/helpers.cpp utils/validators.cpp
```

### Con Opciones Adicionales
```bash
# Con optimización
g++ -std=c++23 -O2 -o ScolarRecord main.cpp core/register.cpp ui/design.cpp utils/helpers.cpp utils/validators.cpp

# Con advertencias habilitadas
g++ -std=c++23 -Wall -Wextra -o ScolarRecord main.cpp core/register.cpp ui/design.cpp utils/helpers.cpp utils/validators.cpp
```

### Ejecución

```bash
# Windows
ScolarRecord.exe

# Linux / macOS
./ScolarRecord
```

---

## 🔮 Funcionalidades Pendientes

Dado que el proyecto está abandonado estas mejoras **no serán implementadas**, pero se listan como referencia de lo que faltaba:

- [ ] Pantalla de instrucciones completa
- [ ] Guardado de registros en archivo (.txt / .csv)
- [ ] Búsqueda y edición de alumnos ya registrados
- [ ] Menú principal con navegación
- [ ] Exportación de reportes
- [ ] Registro de Profesores (`struct Profesores`)
- [ ] Registro de Directivos (`struct Directivos`)

---

## 📧 Contacto

**Magallanes López Carlos Gabriel** — cgmagallanes23@gmail.com
