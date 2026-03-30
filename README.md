# 📋 Sistema de Registro Escolar

Un sistema de registro escolar por consola desarrollado en C++ con soporte multiplataforma. Permite registrar alumnos con validación robusta de datos, generación automática de IDs únicos y una interfaz visual con arte ASCII.

## 👨‍🎓 Información del Desarrollador

- **Desarrollador:** Magallanes López Carlos Gabriel
- **Correo electrónico:** cgmagallanes23@gmail.com
- **Versión:** 1.3
- **Fecha:** 22 de junio de 2025

---

## 🎯 Descripción del Proyecto

Sistema de Registro Escolar es una aplicación de terminal que permite simular el registro de alumnos de una institución educativa. El sistema captura y valida datos personales y académicos, generando automáticamente un ID único de 8 dígitos para cada alumno registrado.

### Características Principales
- **Registro de Alumnos**: Captura completa de datos personales y académicos
- **Validación Robusta**: Verificación en múltiples capas para cada campo
- **IDs Únicos**: Generación automática y aleatoria de identificadores de 8 dígitos
- **Interfaz ASCII**: Banners y menús visuales en consola
- **Confirmación de Datos**: Pantalla de revisión antes de guardar cada registro
- **Multiplataforma**: Compatible con Windows, Linux y macOS

---

## 🗂️ Estructuras de Datos

El sistema utiliza las siguientes estructuras principales:

### `Nombre`
Almacena el nombre completo dividido en tres campos: nombre, apellido paterno y apellido materno.

### `Fecha`
Almacena una fecha con día, mes y año.

### `Lugar`
Almacena ciudad y estado de nacimiento.

### `Alumnos` (Clase Principal)
Contiene toda la información del alumno:

| Campo | Tipo | Descripción |
|-------|------|-------------|
| `nombre` | `Nombre` | Nombre completo del alumno |
| `nacimiento` | `Fecha` | Fecha de nacimiento |
| `lugar_nacimiento` | `Lugar` | Ciudad y estado de origen |
| `grado` | `int` | Grado escolar (mínimo 1) |
| `grupo` | `char` | Grupo (letra A-Z) |
| `calif` | `double` | Promedio final (0.0 - 10.0) |
| `id_alumno` | `int` | ID único de 8 dígitos (generado automáticamente) |
| `sexo` | `char` | Sexo del alumno |

---

## 🔧 Implementación Técnica

### Soporte Multiplataforma

```cpp
// Limpieza de pantalla
#ifdef _WIN32
    system("cls");     // Windows
#else
    system("clear");   // Linux / macOS
#endif

// Pausa interactiva
#ifdef _WIN32
    getch();           // Windows
#else
    system("bash -c \"read -n1 -s -p '...'\"");  // POSIX
#endif
```

### Generación de IDs Únicos
El sistema utiliza el algoritmo de distribución uniforme de C++ para garantizar IDs irrepetibles:
```cpp
std::random_device random;
std::uniform_int_distribution<int> dist(10000000, 99999999);
// Se verifica contra un std::set de IDs ya usados
```

---

## ✅ Reglas de Validación

### Nombre Completo
- No puede estar vacío
- Solo acepta letras y espacios
- Aplica a nombre, apellido paterno y apellido materno

### Grado
- Debe ser un número entero
- Valor mínimo permitido: 1

### Grupo
- Un solo carácter alfabético (A-Z)
- No acepta números ni caracteres especiales

### Promedio / Calificación
- Rango válido: 0.0 a 10.0
- Acepta decimales con punto (`.`)
- No puede estar vacío

### Fecha de Nacimiento
- Solo dígitos
- Máximo 2 caracteres para el día

### ID del Alumno
- Generado automáticamente por el sistema
- 8 dígitos únicos garantizados

---

## 🐛 Mensajes de Error

| Error | Causa |
|-------|-------|
| `ERROR. Por Favor, Ingrese un Numero Entero` | Entrada no numérica donde se esperaba un entero |
| `ERROR. Este Dato no puede estar Vacio` | Campo requerido enviado en blanco |
| `ERROR. Siga el formato indicado para el Nombre Completo` | Caracteres inválidos en el nombre |
| `ERROR. El Menor Grado permitido a Ingresar es 1` | Grado menor a 1 |
| `ERROR. Solo se permite ingresar una letra (A-Z)` | Grupo con más de un carácter o no alfabético |
| `ERROR. El Rango de Calificacion es de 0 - 10` | Promedio fuera del rango permitido |
| `ERROR. Eliga una Opcion Disponible` | Opción de menú inválida |

---

## 🔄 Flujo del Programa

```
INICIO
    ↓
Ingresar cantidad de alumnos a registrar
    ↓
┌──────────────────────────────────────┐
│         BUCLE POR CADA ALUMNO        │
│                                      │
│  1. Nombre                           │
│  2. Apellido Paterno                 │
│  3. Apellido Materno                 │
│  4. Día de Nacimiento                │
│  5. Grado                            │
│  6. Grupo                            │
│  7. Promedio Final                   │
│  8. ID (generado automáticamente)    │
│                                      │
│  → Pantalla de Confirmación          │
│     1. SI → Guardar y continuar      │
│     2. NO → Repetir registro         │
└──────────────────────────────────────┘
    ↓
FIN
```

---

## 📚 Conceptos de Programación Demostrados

🎓 **Programación Orientada a Objetos**
- Clases con atributos privados
- Getters y Setters con validación
- Sobrecarga del operador `<<`
- Miembros estáticos (`ids_usados`)

🎓 **Estructuras en C++**
- `struct` con constructores y constructores por defecto
- Composición de estructuras dentro de clases

🎓 **Manejo de Entrada/Salida**
- Lectura con `std::getline`
- Validación carácter por carácter
- Limpieza de buffer con `cin.clear()`

🎓 **Namespaces**
- Organización del código de interfaz en `namespace Disennio`

🎓 **Números Aleatorios**
- `std::random_device` y `std::uniform_int_distribution`
- Control de unicidad con `std::set`

🎓 **Desarrollo Multiplataforma**
- Compilación condicional con `#ifdef _WIN32`
- Compatibilidad POSIX y Windows

🎓 **STL (Standard Template Library)**
- `std::vector` para colecciones dinámicas
- `std::set` para IDs únicos
- `std::string` y sus métodos

---

## 🔧 Compilación y Ejecución

### Requisitos
- **Compilador**: C++11 o posterior (GCC, Clang, MSVC)
- **Sistema Operativo**: Windows 10/11, Linux o macOS

### Comandos de Compilación

#### Windows (MinGW)
```bash
g++ -std=c++11 main.cpp -o registro.exe
registro.exe
```

#### Linux / macOS
```bash
g++ -std=c++11 main.cpp -o registro
./registro
```

#### Con opciones adicionales
```bash
# Con optimización
g++ -std=c++11 -O2 main.cpp -o registro

# Con advertencias habilitadas
g++ -std=c++11 -Wall -Wextra main.cpp -o registro
```

---

## 🔮 Mejoras Futuras

Por el momento no se tiene planeado a futuro seguir desarrollando este proyecto, pero si en algún momento se cambia de idea algunas de las mejoras futuras que se implementarían son: 

- [ ] Registro de Profesores (`struct Profesores`)
- [ ] Registro de Directivos (`struct Directivos`)
- [ ] Menú principal con navegación completa
- [ ] Guardado de registros en archivo (.txt / .csv)
- [ ] Búsqueda y edición de alumnos registrados
- [ ] Exportación de reportes
- [ ] Soporte completo para fecha de nacimiento (mes y año)
- [ ] Pantalla de instrucciones completa

---

## 📧 Contacto

- **Autor:** Carlos Gabriel Magallanes López
- **Correo electrónico:** cgmagallanes23@gmail.com

---

⭐ **Sistema de registro escolar en C++ que demuestra POO, validación de datos y desarrollo multiplataforma**
