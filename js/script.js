/*****************************************************************************************************************************************************************************/
/*                                                                                                                                                                           */
/*                                                                  Scripts para el Proyecto ScolarRecord                                                                    */
/*                                                                                                                                                                           */
/*****************************************************************************************************************************************************************************/
/*                                                                                                                                                                           */
/* Autor: Magallanes López Carlos Gabriel                                                                                                                                    */
/* Versión del Proyecto: 1.0                                                                                                                                                 */
/* Correo: cgmagallanes23@gmail.com                                                                                                                                          */
/* Ultima Modificación: 09/05/2026                                                                                                                                           */
/*                                                                                                                                                                           */
/*****************************************************************************************************************************************************************************/

// i18n - Traducciones
const translations = {
    es: {
        titlebarName: "Code::Blocks 20.03 — ScolarRecord",
        tabHero: "main.cpp",
        tabAbout: "README.md",
        tabStructure: "structs.hpp",
        tabFlow: "register.cpp",
        tabValidation: "validators.cpp",
        tabConcepts: "concepts.txt",
        tabStatus: "STATUS",
        sidebarTitle: "Workspace",
        heroLabel: "main.cpp — entry point",
        heroBadge: "⚠ PROYECTO ABANDONADO — v1.0",
        heroDesc: "Sistema de registro escolar por consola desarrollado en C++23. Valida, captura y almacena datos de alumnos con generación automática de IDs únicos y una interfaz visual con arte ASCII.",
        metaLang: "C++23",
        metaIDE: "Code::Blocks",
        metaPlatform: "Multiplataforma",
        metaAuthor: "Carlos Gabriel Magallanes",
        aboutLabel: "README.md — descripción",
        aboutH2: "Proyecto",
        aboutP1: "ScolarRecord es una aplicación de terminal que simula el registro de alumnos de una institución educativa. Cada alumno requiere nombre completo, fecha y lugar de nacimiento, sexo, grado, grupo y promedio final.",
        aboutP2: "El sistema valida cada campo de forma independiente en múltiples capas, mostrando el contexto de datos ya ingresados solo cuando ocurre un error. Al finalizar, genera automáticamente un ID único de 8 dígitos por alumno.",
        feat1Title: "Validación Robusta",
        feat1Desc: "Verificación en múltiples capas por campo, con manejo de excepciones.",
        feat2Title: "IDs Únicos",
        feat2Desc: "Generación aleatoria con std::random_device garantizando unicidad.",
        feat3Title: "Arte ASCII",
        feat3Desc: "Banners y menús visuales construidos completamente en consola.",
        feat4Title: "Multiplataforma",
        feat4Desc: "Compatible con Windows, Linux y macOS via compilación condicional.",
        structureLabel: "structs.hpp — estructuras de datos",
        structureH2: "Estructuras",
        structureP: "El proyecto está organizado en namespaces y structs que separan responsabilidades. Cada struct valida sus propios datos en el constructor.",
        flowLabel: "register.cpp — flujo de captura",
        flowH2: "Flujo del Programa",
        flowP: "Cada campo se captura en su propio bucle de validación. Si hay error, se muestra el contexto de los datos ya ingresados. Si la construcción del struct falla, se reinician todos sus campos.",
        flow1: "Ingresa cantidad de alumnos",
        flow2: "Nombre → Apellido Paterno → Apellido Materno",
        flow3: "Día → Mes → Año de Nacimiento",
        flow4: "Ciudad → Estado → País",
        flow5: "Sexo → Grado → Grupo → Promedio",
        flow6: "Generación automática de ID",
        flow7: "Pantalla de confirmación → Guardar",
        validationLabel: "validators.cpp — reglas de validación",
        validationH2: "Validaciones",
        thField: "Campo",
        thRule: "Regla",
        val1Field: "Nombre / Apellidos",
        val1Rule: "Solo letras y espacios, no vacío",
        val2Field: "Día",
        val2Rule: "Solo dígitos, máx 2 chars, rango 1–31",
        val3Field: "Mes",
        val3Rule: "Solo dígitos, máx 2 chars, rango 1–12",
        val4Field: "Año",
        val4Rule: "Solo dígitos, máx 4 chars, desde 1930",
        val5Field: "Fecha completa",
        val5Rule: "Validada con std::chrono, no puede ser futura",
        val6Field: "Ciudad / Estado / País",
        val6Rule: "Solo letras y espacios, no vacío",
        val7Field: "Sexo",
        val7Rule: "Un carácter: M o F",
        val8Field: "Grado",
        val8Rule: "Entero entre 1 y 8",
        val9Field: "Grupo",
        val9Rule: "Una sola letra A–Z",
        val10Field: "Promedio",
        val10Rule: "Decimal entre 0.0 y 10.0",
        conceptsLabel: "concepts.txt — compilación y conceptos",
        conceptsH2: "Compilación",
        conceptsH2b: "Conceptos Demostrados",
        statusLabel: "STATUS — estado del proyecto",
        statusH2: "Estado: Abandonado",
        bannerTitle: "⚠ PROYECTO INCOMPLETO Y ABANDONADO",
        bannerP: "Este proyecto fue desarrollado como ejercicio de aprendizaje. Durante el desarrollo se adquirió conocimiento sobre bases de datos relacionales, lo que hace que almacenar registros en memoria a través de una interfaz de consola sea poco práctico para un sistema real. Una solución con SQL o SQLite resolvería de forma más adecuada los problemas de persistencia, búsqueda y escalabilidad que este proyecto intentaba abordar manualmente.",
        statusP: "El código queda disponible como referencia de aprendizaje en C++23.",
        statusH2b: "Pendiente (no se implementará)",
        pend1: "Pantalla de instrucciones",
        pend2: "Guardar en archivo (.csv)",
        pend3: "Búsqueda y edición",
        pend4: "Menú de navegación",
        pend5: "Exportación de reportes",
        footerRight: "ScolarRecord v1.0 · C++23 · Code::Blocks",
        langBtn: "🌐 English"
    },
    en: {
        titlebarName: "Code::Blocks 20.03 — ScolarRecord",
        tabHero: "main.cpp",
        tabAbout: "README.md",
        tabStructure: "structs.hpp",
        tabFlow: "register.cpp",
        tabValidation: "validators.cpp",
        tabConcepts: "concepts.txt",
        tabStatus: "STATUS",
        sidebarTitle: "Workspace",
        heroLabel: "main.cpp — entry point",
        heroBadge: "⚠ ABANDONED PROJECT — v1.0",
        heroDesc: "Console-based school registration system developed in C++23. Validates, captures and stores student data with automatic generation of unique IDs and a visual ASCII art interface.",
        metaLang: "C++23",
        metaIDE: "Code::Blocks",
        metaPlatform: "Multiplatform",
        metaAuthor: "Carlos Gabriel Magallanes",
        aboutLabel: "README.md — description",
        aboutH2: "Project",
        aboutP1: "ScolarRecord is a terminal application that simulates the registration of students at an educational institution. Each student requires full name, date and place of birth, gender, grade, group and final average.",
        aboutP2: "The system validates each field independently across multiple layers, showing the context of already entered data only when an error occurs. At the end, it automatically generates a unique 8-digit ID per student.",
        feat1Title: "Robust Validation",
        feat1Desc: "Multi-layer verification per field, with exception handling.",
        feat2Title: "Unique IDs",
        feat2Desc: "Random generation with std::random_device guaranteeing uniqueness.",
        feat3Title: "ASCII Art",
        feat3Desc: "Banners and visual menus built entirely in the console.",
        feat4Title: "Multiplatform",
        feat4Desc: "Compatible with Windows, Linux and macOS via conditional compilation.",
        structureLabel: "structs.hpp — data structures",
        structureH2: "Structures",
        structureP: "The project is organized into namespaces and structs that separate responsibilities. Each struct validates its own data in the constructor.",
        flowLabel: "register.cpp — capture flow",
        flowH2: "Program Flow",
        flowP: "Each field is captured in its own validation loop. If there is an error, the context of already entered data is shown. If the struct construction fails, all its fields are reset.",
        flow1: "Enter number of students",
        flow2: "First Name → Paternal Surname → Maternal Surname",
        flow3: "Day → Month → Year of Birth",
        flow4: "City → State → Country",
        flow5: "Gender → Grade → Group → Average",
        flow6: "Automatic ID generation",
        flow7: "Confirmation screen → Save",
        validationLabel: "validators.cpp — validation rules",
        validationH2: "Validations",
        thField: "Field",
        thRule: "Rule",
        val1Field: "Name / Surnames",
        val1Rule: "Letters and spaces only, not empty",
        val2Field: "Day",
        val2Rule: "Digits only, max 2 chars, range 1–31",
        val3Field: "Month",
        val3Rule: "Digits only, max 2 chars, range 1–12",
        val4Field: "Year",
        val4Rule: "Digits only, max 4 chars, from 1930",
        val5Field: "Full date",
        val5Rule: "Validated with std::chrono, cannot be in the future",
        val6Field: "City / State / Country",
        val6Rule: "Letters and spaces only, not empty",
        val7Field: "Gender",
        val7Rule: "One character: M or F",
        val8Field: "Grade",
        val8Rule: "Integer between 1 and 8",
        val9Field: "Group",
        val9Rule: "Single letter A–Z",
        val10Field: "Average",
        val10Rule: "Decimal between 0.0 and 10.0",
        conceptsLabel: "concepts.txt — compilation & concepts",
        conceptsH2: "Compilation",
        conceptsH2b: "Concepts Demonstrated",
        statusLabel: "STATUS — project status",
        statusH2: "Status: Abandoned",
        bannerTitle: "⚠ INCOMPLETE AND ABANDONED PROJECT",
        bannerP: "This project was developed as a learning exercise. During development, knowledge about relational databases was acquired, which makes storing records in memory through a console interface impractical for a real system. A solution with SQL or SQLite would more adequately solve the persistence, search and scalability problems this project was trying to address manually.",
        statusP: "The code remains available as a C++23 learning reference.",
        statusH2b: "Pending (will not be implemented)",
        pend1: "Instructions screen",
        pend2: "Save to file (.csv)",
        pend3: "Search and edit",
        pend4: "Navigation menu",
        pend5: "Report export",
        footerRight: "ScolarRecord v1.0 · C++23 · Code::Blocks",
        langBtn: "🌐 Español"
    }
};

// Detección y Aplicación de Idioma
function detectLanguage() {
    const saved = localStorage.getItem('lang');
    if (saved) return saved;
    const browserLang = navigator.language || navigator.userLanguage;
    return browserLang.startsWith('es') ? 'es' : 'en';
}

// Aplicar Traducciones al DOM
function applyLanguage(lang) {
    const t = translations[lang];
    document.querySelectorAll('[data-i18n]').forEach(el => {
        const key = el.getAttribute('data-i18n');
        if (t[key]) el.innerHTML = t[key];
    });
    document.querySelectorAll('[data-i18n-html]').forEach(el => {
        const key = el.getAttribute('data-i18n-html');
        if (t[key]) el.innerHTML = t[key];
    });
    document.documentElement.setAttribute('lang', lang);
    const btn = document.getElementById('langToggleBtn');
    if (btn) btn.textContent = t.langBtn;
    localStorage.setItem('lang', lang);
}

// Crear Botón Flotante de Cambio de Idioma
function createLangButton() {
    const btn = document.createElement('button');
    btn.id = 'langToggleBtn';
    btn.addEventListener('click', () => {
        const current = localStorage.getItem('lang') || detectLanguage();
        const next = current === 'es' ? 'en' : 'es';
        applyLanguage(next);
    });
    document.body.appendChild(btn);
}

// Efecto Fade In al hacer Scroll
const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.classList.add('visible');
            observer.unobserve(entry.target);
        }
    });
}, { threshold: 0.12 });

// Observar Elementos de la Clase 'fade-in' para Activar Efecto al Entrar en el Viewport
document.querySelectorAll('.fade-in').forEach(el => observer.observe(el));

// Estado Activo de la Pestaña al Hacer Scroll
const sections = document.querySelectorAll('section[id]');
const tabs = document.querySelectorAll('.tab');

// Instanciar Observador de Secciones para Actualizar la Pestaña Activa al Hacer Scroll
const sectionObserver = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            const id = entry.target.getAttribute('id');
            tabs.forEach(tab => {
                tab.classList.toggle('active', tab.getAttribute('href') === `#${id}`);
            });
        }
    });
}, { threshold: 0.4 });

// Observar Secciones para Actualizar Pestaña Activa al Hacer Scroll
sections.forEach(s => sectionObserver.observe(s));

// Generar Números de Línea en cada Sección del IDE
function fillLineNumbers(containerId, count) {
    const container = document.getElementById(containerId);
    if (!container) return;
    for (let i = 1; i <= count; i++) {
        const span = document.createElement('span');
        span.className = 'line-num';
        span.textContent = i;
        container.appendChild(span);
    }
}

// Llamadas a fillLineNumbers para Cada Sección del IDE con su Número de Líneas
fillLineNumbers('ln-hero', 28);
fillLineNumbers('ln-about', 22);
fillLineNumbers('ln-structure', 30);
fillLineNumbers('ln-flow', 18);
fillLineNumbers('ln-validation', 16);
fillLineNumbers('ln-concepts', 20);
fillLineNumbers('ln-status', 14);

// Resaltar Elemento del Árbol de Archivos al Hacer Click
document.querySelectorAll('.tree-item[href]').forEach(item => {
    item.addEventListener('click', function () {
        document.querySelectorAll('.tree-item').forEach(i => i.style.background = '');
        this.style.background = 'var(--cb-select)';
    });
});

// Inicialización
createLangButton();                                                                              // Creación del Botón del Lenguaje
applyLanguage(detectLanguage());                                                                 // Aplicación del Lenguaje

/*****************************************************************************************************************************************************************************/