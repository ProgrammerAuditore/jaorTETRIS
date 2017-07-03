// -----------------------------------------------------------------------------------------
// archivo :func_video.h
// objetivo:archivo de cabecera para archivo func_video.h con funciones para manejo de video
// lenguaje:gnu c
// autor   :jaor
// www.jaorsoftware.com
// -----------------------------------------------------------------------------------------

// Se Incluyen librerias
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>

// Constantes
#define INT_ESCAPE         0x1B   // Valor de la Secuencia ESCAPE
#define STR_VACIA          ""     // Cadena Vacia
#define INT_TEXTO_NEGRO    30     // Constante para el Color de Texto Negro
#define INT_TEXTO_ROJO     31     // Constante para el Color de Texto Rojo
#define INT_TEXTO_VERDE    32     // Constante para el Color de Texto Verde
#define INT_TEXTO_AMARILLO 33     // Constante para el Color de Texto Amarillo
#define INT_TEXTO_AZUL     34     // Constante para el Color de Texto Azul
#define INT_TEXTO_MAGENTA  35     // Constante para el Color de Texto Magenta
#define INT_TEXTO_CIAN     36     // Constante para el Color de Texto Cian
#define INT_TEXTO_BLANCO   37     // Constante para el Color de Texto Blanco

#define INT_FONDO_NEGRO    40     // Constante para el Color de Fondo Negro
#define INT_FONDO_ROJO     41     // Constante para el Color de Fondo Rojo
#define INT_FONDO_VERDE    42     // Constante para el Color de Fondo Verde
#define INT_FONDO_AMARILLO 43     // Constante para el Color de Fondo Amarillo
#define INT_FONDO_AZUL     44     // Constante para el Color de Fondo Azul
#define INT_FONDO_MAGENTA  45     // Constante para el Color de Fondo Magenta
#define INT_FONDO_CIAN     46     // Constante para el Color de Fondo Cian
#define INT_FONDO_BLANCO   47     // Constante para el Color de Fondo Blanco

// Caracteres Extendidos Unicode Para Dibujar los Marcos
#define BOX_DRAWINGS_LIGHT_HORIZONTAL         L"\u2500"
#define BOX_DRAWINGS_LIGHT_VERTICAL           L"\u2502"
#define BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT     L"\u250C"
#define BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT      L"\u2510"
#define BOX_DRAWINGS_LIGHT_UP_AND_RIGHT       L"\u2514"
#define BOX_DRAWINGS_LIGHT_UP_AND_LEFT        L"\u2518"
#define BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT L"\u251C"
#define BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT  L"\u2524"

// Funcion     ; sbLimpiaPantalla
// Objetivo    : Limpia la Pantalla de la Terminal
void sbLimpiaPantalla();

// Función     : sbCursor
// Objetivo    : Activa o Desactiva el Cursor
void sbCursor(bool bCursorOn); // true lo activa, false lo desactiva


// Funcion     ; sbGotoXY
// Objetivo    : Coloca el Cursor en la posición indicada
void sbGotoXY(int intRenglon,   // Columna en la que se colocará el Cursor 1-80
              int intColumna);  // Renglon en el que se colocará el Cursor 1-24

// Funcion     ; sbCursorUp
// Objetivo    : Sube el Cursor los Renglones Indicados
void sbCursorUp(int intRenglones);  // Renglones a Subir

// Funcion     ; sbCursorDown
// Objetivo    : Baja el Cursor los Renglones Indicados
void sbCursorDown(int intRenglones);  // Renglones a Subir


// Funcion     ; sbCursorRight
// Objetivo    : Avanza el Cursor las Columnas Indicadas
void sbCursorRight(int intColumnas);  // Columnas a Avanzar

// Funcion     ; sbCursorLeft
// Objetivo    : Retrocede el Cursor las Columnas Indicadas
void sbCursorLeft(int intColumnas);  // Columnas a Retroceder

// Funcion     ; sbCursorSave
// Objetivo    : Guarda la Posición del Cursor
void sbCursorSave();

// Funcion     ; sbCursorRestore
// Objetivo    : Restablece la Posición del Cursor
void sbCursorRestore();


// Funcion     ; sbColor
// Objetivo    : Establecer un Color para el Despliegue de Texto en la Terminal
void sbColor(int pIntColor); // El COlor a establecer

// Funcion     ; sbParpadear
// Objetivo    : Habilita el Parpadeo del Texto
void sbParpadear();

// Funcion     ; sbSubrayar
// Objetivo    : Habilita el Texto Subrayado
void sbSubrayar();

// Funcion     ; sbInverso
// Objetivo    : Invierto los Colores usados; el Texto a Fondo y el Fondo a Text
void sbInverso();

// Funcion     ; sbAclararColor
// Objetivo    : Aclara el Color Usado
void sbAclarar();

// Funcion     ; sbNormal
// Objetivo    : Deja el Texto en Normal
void sbNormal();

// Funcion     ; sbDibujaLineaHorizontal
// Objetivo    : Dibuja una Linea Horizontal en un Renglon Específico
void SbDibujaLineaHorizontal(int  intRenglon,      // Renglon donde se dibuja la Línea
                             int  intColInicial,   // Columna Inicial
                             int  intColFinal);    // Columna Final


// Funcion     ; sbDibujaLineaVertical
// Objetivo    : Dibuja una Linea Vertical en una Columna específica
void SbDibujaLineaVertical(int  intColumna,        // Columna donde se dibuja la linea vertical
                           int  intRenInicial,     // Renglon Inicial
                           int  intRenFinal);      // Renglón Final

// Funcion     ; sbDibujaMarco
// Objetivo    : Dibuja un Marco en la Pantalla
void sbDibujaMarco(int  intRen1,      // Renglon de la Esquina Superior Izquierda
                   int  intCol1,      // Columna de la Esquina Superior Izquierda
                   int  intRen2,      // Renglón de la Columna inferior derecha
                   int  intCol2,      // Columna de la esquina inferior derecha
                   char *pStrTitulo); // Título que llevará el Marco; opcional si viene vació

// Funcion     ; sbDibujaVentana
// Objetivo    : Dibuja una Ventana en la Pantalla
void sbDibujaVentana(int  intRen1,      // Renglon de la Esquina Superior Izquierda
                     int  intCol1,      // Columna de la Esquina Superior Izquierda
                     int  intRen2,      // Renglón de la Columna inferior derecha
                     int  intCol2,      // Columna de la esquina inferior derecha
                     char *pStrTitulo); // Título que llevará la Ventana



// Funcion     ; sbLimpiaArea
// Objetivo    : Limpia una Área en la Pantalla con Espacios en Blanco
void sbLimpiaArea(int  intRen1,      // Renglon de la Esquina Superior Izquierda
                  int  intCol1,      // Columna de la Esquina Superior Izquierda
                  int  intRen2,      // Renglón de la Columna inferior derecha
                  int  intCol2);     // Columna de la esquina inferior derecha

