[![es](https://img.shields.io/badge/lang-es-red.svg)](README.es.md)

# 📋 School Registration System

![C++](https://img.shields.io/badge/C%2B%2B-23-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Multiplatform-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Type](https://img.shields.io/badge/Type-Console_App-8B008B?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-1.0-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Abandoned-red?style=for-the-badge)

A console-based school registration system developed in C++23 with multiplatform support. It allows registering students with robust data validation, automatic unique ID generation, and a visual interface with ASCII art.

---

## ⚠️ Project Status: Abandoned

This project was developed as a learning exercise and is currently **incomplete and abandoned**.

The main reason is that during development, knowledge was gained about the existence of relational databases, which makes storing records in memory through a console interface impractical for a real registration system. A database solution (SQL, SQLite, PostgreSQL, etc.) would more adequately solve the persistence, search, editing, and scalability problems this project was trying to address manually.

The code remains available as a C++ learning reference.

---

## 🎬 Preview

<div align="center">
  <img src="assets/preview.gif" alt="School Registration System Preview"/>
</div>

---

## 👨‍💻 Developer Info

| Field | Detail |
|-------|--------|
| **Developer** | Carlos Gabriel Magallanes López |
| **Email** | cgmagallanes23@gmail.com |
| **Version** | 1.0 |
| **Start Date** | June 22, 2025 |

---

## 🎯 Description

ScolarRecord is a terminal application that simulates student registration for an educational institution. It captures and validates personal and academic data, automatically generating a unique 8-digit ID per student.

---

## 🗂️ Project Structure

```
ScolarRecord/
├── main.cpp                  # Entry point
├── core/
│   ├── structs.hpp           # Data structure definitions
│   ├── register.hpp          # StudentRegister namespace declaration
│   ├── register.cpp          # Data capture and validation logic
│   └── operators.hpp         # Output operator overloading (<<)
├── ui/
│   ├── design.hpp            # Design namespace declaration
│   └── design.cpp            # ASCII interface implementation
└── utils/
    ├── constants.hpp         # Global constants and enumerations
    ├── helpers.hpp           # Helper function declarations
    ├── helpers.cpp           # Helper function implementations
    ├── validators.hpp        # Validator declarations
    └── validators.cpp        # Validator implementations
```

---

## 🧱 Data Structures

### `CompleteName`
Full name divided into three fields: first name, paternal surname, and maternal surname. All three fields are validated in the constructor.

### `BirthDate`
Date of birth with day, month, and year. Validates that the date is real and not in the future using `std::chrono`.

### `Place`
City, state, and country of birth. Each field is validated individually.

### `Student` (Main Class)
Main structure grouping all student data:

| Field | Type | Description |
|-------|------|-------------|
| `COMPLETE_NAME` | `CompleteName` | Full name |
| `BIRTHDATE` | `BirthDate` | Date of birth |
| `BIRTHPLACE` | `Place` | Place of birth |
| `SEX` | `Sex` | Gender (`M` / `F`) |
| `educativeGrade` | `EducativeGrade` | School grade (1–8) |
| `group` | `Group` | Group (letter A–Z) |
| `calification` | `double` | Final average (0.0–10.0) |
| `id_student` | `int` | Unique 8-digit ID (auto-generated) |

---

## 🔄 Program Flow

```
START
    ↓
Show cover screen (ASCII animation)
    ↓
Enter number of students to register
    ↓
┌──────────────────────────────────────────────────┐
│              LOOP FOR EACH STUDENT               │
│                                                  │
│  1.  First Name                                  │
│  2.  Paternal Surname                            │
│  3.  Maternal Surname                            │
│  4.  Day of Birth                                │
│  5.  Month of Birth                              │
│  6.  Year of Birth                               │
│  7.  City of Birth                               │
│  8.  State of Birth                              │
│  9.  Country of Birth                            │
│  10. Gender (M / F)                              │
│  11. Grade (1–8)                                 │
│  12. Group (A–Z)                                 │
│  13. Final Average                               │
│  14. ID (auto-generated)                         │
│                                                  │
│  → Confirmation screen                           │
│     1 / YES → Save and continue                  │
│     2 / NO  → Repeat registration                │
└──────────────────────────────────────────────────┘
    ↓
END
```

Each field is validated independently. If there is an error, the corresponding message is shown with the context of already-entered data, and only the incorrect field is requested again. If structure creation fails, all its fields are reset.

---

## ✅ Validation Rules

| Field | Rule |
|-------|------|
| Name / Surnames | Letters and spaces only, cannot be empty |
| Day | Digits only, max 2 characters, range 1–31 |
| Month | Digits only, max 2 characters, range 1–12 |
| Year | Digits only, max 4 characters, from 1930 to current year |
| Full Date | Validated with `std::chrono::year_month_day`, cannot be in the future |
| City / State / Country | Letters and spaces only, cannot be empty |
| Gender | Single character: `M` or `F` (case insensitive) |
| Grade | Integer between 1 and 8 |
| Group | Single letter A–Z |
| Average | Decimal number between 0.0 and 10.0 |

---

## 🔧 Technical Implementation

### Multiplatform Support

| Platform | Minimum Version |
|----------|----------------|
| **Windows** | Windows 10 |
| **Linux** | Ubuntu 18.04+ |
| **macOS** | macOS 10.14+ |

Screen clearing and interactive pause are implemented with conditional compilation:

```cpp
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
```

### Unique ID Generation

```cpp
std::random_device random;
std::uniform_int_distribution<int> dist(10000000, 99999999);
// Verified against a std::set<int> of already used IDs
do { new_id = dist(random); } while (used_ids.count(new_id));
used_ids.insert(new_id);
```

---

## 📚 Concepts Demonstrated

- **Structs with constructors and validation** in C++
- **Namespaces** for code organization (`Design`, `StudentRegister`)
- **Exception handling** with `try/catch` for validation flow
- **Operator overloading** (`<<`) for structure printing
- **STL:** `std::vector`, `std::set`, `std::string`, `std::chrono`
- **Random numbers** with `std::random_device` and `std::uniform_int_distribution`
- **Enumerations** (`enum class`) for bounded-domain types
- **Conditional compilation** for multiplatform support
- **Separation of concerns** across multiple files and namespaces

---

## 🔧 Compilation & Execution

### Requirements

| Component | Requirement |
|-----------|-------------|
| **Compiler** | GCC with C++23 support (GCC 13+) |
| **OS** | Windows 10/11, Linux, or macOS |

### Compilation Command

```bash
g++ -std=c++23 -o ScolarRecord main.cpp core/register.cpp ui/design.cpp utils/helpers.cpp utils/validators.cpp
```

### With Additional Options
```bash
# With optimization
g++ -std=c++23 -O2 -o ScolarRecord main.cpp core/register.cpp ui/design.cpp utils/helpers.cpp utils/validators.cpp

# With warnings enabled
g++ -std=c++23 -Wall -Wextra -o ScolarRecord main.cpp core/register.cpp ui/design.cpp utils/helpers.cpp utils/validators.cpp
```

### Execution

```bash
# Windows
ScolarRecord.exe

# Linux / macOS
./ScolarRecord
```

---

## 🔮 Pending Features

Since the project is abandoned, these improvements **will not be implemented**, but are listed as reference for what was missing:

- [ ] Complete instructions screen
- [ ] Save records to file (.txt / .csv)
- [ ] Search and edit already registered students
- [ ] Main menu with navigation
- [ ] Report export
- [ ] Teacher registration (`struct Teacher`)
- [ ] Administrator registration (`struct Administrator`)

---

## 📧 Contact

**Carlos Gabriel Magallanes López** — cgmagallanes23@gmail.com
