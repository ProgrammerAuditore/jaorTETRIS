// -----------------------------------------
// archivo :func_video.c
// objetivo:funciones para manejo de video
// lenguaje:gnu c
// autor   :jaor
// www.jaorsoftware.com
// -----------------------------------------

// incluimos el archivo de cabecera
#include "func_video.h"

// Variables para el Dibujo de Marcos
wchar_t *gStrEsquinaSuperiorIzquierda = L"\u250C";
wchar_t *gStrEsquinaSuperiorDerecha   = L"\u2510";
wchar_t *gStrEsquinaInferiorIzquierda = L"\u2514";
wchar_t *gStrEsquinaInferiorDerecha   = L"\u2518";

wchar_t *gStrLineaHorizontalSuperior  = L"\u2500";
wchar_t *gStrLineaHorizontalInferior  = L"\u2500";
wchar_t *gStrLineaVerticalIzquierda   = L"\u2502";
wchar_t *gStrLineaVerticalDerecha     = L"\u2502";

wchar_t *gStrConectorIzquierdo        = L"\u251C";
wchar_t *gStrConectorDerecho          = L"\u2524";
wchar_t *gStrConectorSuperior         = L"\u252C";
wchar_t *gStrConectorInferior         = L"\u2534";

wchar_t *gStrLineaHorizontal          = L"\u2500";
wchar_t *gStrLineaVertical            = L"\u2502";




// Funcion     ; sbLimpiaPantalla
// Objetivo    : Limpia la Pantalla de la Terminal
void sbLimpiaPantalla()
{
   // Utiliza Secuencias de Escapa
   printf("%c[2J",INT_ESCAPE);

}

// Función     : sbCursor
// Objetivo    : Activa o Desactiva el Cursor
void sbCursor(bool bCursorOn) // true lo activa, false lo desactiva
{
   if(bCursorOn)
   {
      printf("\x1B[?25h");
   }
   else
   {
      printf("\x1B[?25l");
   }
}

// Funcion     ; sbGotoXY
// Objetivo    : Coloca el Cursor en la posición indicada
void sbGotoXY(int intRenglon,   // Renglon en el que se colocará el Cursor 1-80
              int intColumna)   // Columna en la que se colocará el Cursor 1-24
{
   // Utiliza Secuencias de Escapa
   printf("%c[%d;%df",INT_ESCAPE,intRenglon,intColumna);

}

// Funcion     ; sbColor
// Objetivo    : Establecer Colores de Texto o Fondo
void sbColor(int pIntColor) // El COlor a establecer
{
   // Utiliza Secuencias de Escapa
   printf("%c[%dm",INT_ESCAPE,pIntColor);

}

// Funcion     ; sbParpadear
// Objetivo    : Habilita el Parpadeo del Texto
void sbParpadear()
{
   // Utiliza Secuencias de Escapa
   printf("%c[5m",INT_ESCAPE);

}

// Funcion     ; sbSubrayar
// Objetivo    : Habilita el Texto Subrayado
void sbSubrayar()
{
   // Utiliza Secuencias de Escapa
   printf("%c[4m",INT_ESCAPE);

}

// Funcion     ; sbInverso
// Objetivo    : Invierto los Colores usados; el Texto a Fondo y el Fondo a Text
void sbInverso()
{
    // Utiliza Secuencias de Escapa
    printf("%c[7m",INT_ESCAPE);
}

// Funcion     ; sbAclarar
// Objetivo    : Aclara el Color Usado
void sbAclarar()
{
   // Utiliza Secuencia Aclarar
   printf("%c[1m",INT_ESCAPE);
}

// Funcion     ; sbNormal
// Objetivo    : Establece el Texto en Normal
void sbNormal()
{
   // Establece el Texto Normal
   printf("%c[0m",INT_ESCAPE);
}



// Funcion     ; sbCursorUp
// Objetivo    : Sube el Cursor los Renglones Indicados
void sbCursorUp(int intRenglones)  // Renglones a Subir
{
   // Utiliza Secuencias de Escapa
   printf("%c[%dA",INT_ESCAPE,intRenglones);
}

// Funcion     ; sbCursorDown
// Objetivo    : Baja el Cursor los Renglones Indicados
void sbCursorDown(int intRenglones)  // Renglones a Subir
{
   // Utiliza Secuencias de Escapa
   printf("%c[%dB",INT_ESCAPE,intRenglones);
}


// Funcion     ; sbCursorRight
// Objetivo    : Avanza el Cursor las Columnas Indicadas
void sbCursorRight(int intColumnas)  // Columnas a Retroceder
{
   // Utiliza Secuencias de Escapa
   printf("%c[%dC",INT_ESCAPE,intColumnas);
}

// Funcion     ; sbCursorLeft
// Objetivo    : Retrocede el Cursor las Columnas Indicadas
void sbCursorLeft(int intColumnas)  // Columnas a Retroceder
{
   // Utiliza Secuencias de Escapa
   printf("%c[%dD",INT_ESCAPE,intColumnas);
}

// Funcion     ; sbCursorSave
// Objetivo    : Salva la posición actual del Cursor
void sbCursorSave()
{
   // Utiliza Secuencias de Escape
   printf("%c[s",INT_ESCAPE);
}

// Funcion     ; sbCursorRestore
// Objetivo    : Restablece la posición actual del Cursor
void sbCursorRestore()
{
   // Utiliza Secuencias de Escape
   printf("%c[u",INT_ESCAPE);
}



// Funcion     ; sbDibujaLineaHorizontal
// Objetivo    : Dibuja una Linea Horizontal en un Renglon Especifico
void SbDibujaLineaHorizontal(int  intRenglon,      // Renglon donde se dibuja la Linea Horizontal
                             int  intColInicial,   // Columna Inicial
                             int  intColFinal)     // Columna Final
{
   // Variable para Conteo
   int intPos;

   // Se ubica en el Renglon Origen y Columna Inicial
   sbGotoXY(intRenglon,intColInicial);

   // Ciclo para dibujar la linea horizontal
   for (intPos=intColInicial;intPos<=intColFinal;intPos++)
       //printf("%c",'-');
       printf("%ls",gStrLineaHorizontal);

}

// Funcion     ; sbDibujaLineaVertical
// Objetivo    : Dibuja una Linea Vertical en una Columna Especifica
void SbDibujaLineaVertical(int  intColumna,      // Columna donde se dibuja la Linea Vertical
                           int  intRenInicial,   // Renglón Inicial
                           int  intRenFinal)     // Renglón Final
{
   // Variable para Conteo
   int intPos;

   // Ciclo para dibujar la linea vertical
   for (intPos=intRenInicial;intPos<=intRenFinal;intPos++)
   {
       // Se ubica en el Siguiente Renglon
       sbGotoXY(intPos,intColumna);
       //printf("%c",'|');
       printf("%ls",gStrLineaVertical);
   }

}

// Funcion     ; sbDibujaMarco
// Objetivo    : Dibuja un Marco en la Pantalla
void sbDibujaMarco(int  intRen1,      // Renglon de la Esquina Superior Izquierda
                   int  intCol1,      // Columna de la Esquina Superior Izquierda
                   int  intRen2,      // Renglón de la Columna inferior derecha
                   int  intCol2,      // Columna de la esquina inferior derecha
                   char *pStrTitulo)  // Título que llevará el Marco; opcional si viene vació
{

   // Variable Auxiliar
   wchar_t *strAuxiliar            = L"\u2500";


   // Variables para Ciclos
   int intPos;

   // Prepara los caracteres extendidos
   setlocale(LC_ALL, "");

   // Dibuja la Esquina Superior
   sbGotoXY(intRen1,intCol1);

   // Despliega la Esquina Superior Izquierda
   //printf("%c",'+');
   printf("%ls",gStrEsquinaSuperiorIzquierda);

   // Ciclo para la Línea Superior
   //for(intPos=intCol1+1;intPos<intCol2;intPos++)
      // Despliega el Caracter
      //printf("%c",'-');
   //   printf("%ls",gStrLineaHorizontalSuperior);

   // Guarda la linea Horizontal
   strAuxiliar = gStrLineaHorizontal;

   // Copia la del Marco a la de la Linea
   gStrLineaHorizontal = gStrLineaHorizontalSuperior;

   // Llama a Linea Horizontal para Dibujar Linea Horizontal Superior
   SbDibujaLineaHorizontal(intRen1,intCol1+1,intCol2-1);

   // Regresa el valor Guardaro
   gStrLineaHorizontal = strAuxiliar;


   // Despliega la Esquina Superior Derecha
   //printf("%c",'+');
   printf("%ls",gStrEsquinaSuperiorDerecha);

   // Ciclo para Imprimir los Costados
   //for(intPos=intRen1+1;intPos<intRen2;intPos++)
   //{

       // Se coloca en el costado izquierdo y dibuja el caracter
   //    sbGotoXY(intPos,intCol1);
       //printf("%c",124);
   //    printf("%ls",gStrLineaVerticalIzquierda);

       // Se coloca en el costado derecho y dibuja el caracter
   //    sbGotoXY(intPos,intCol2);
       //printf("%c",124);
   //    printf("%ls",gStrLineaVerticalDerecha);

   //}

   // Guarda la linea Vertical
   strAuxiliar = gStrLineaVertical;

   // Copia la del Marco a la de la Linea
   gStrLineaVertical = gStrLineaVerticalIzquierda;

   // Llama a Linea Vertical para Dibujar Linea Vertical Izquierda
   SbDibujaLineaVertical(intCol1,intRen1+1,intRen2-1);

   // Regresa el valor Guardado
   gStrLineaVertical = strAuxiliar;

   // Copia la del Marco a la de la Linea
   gStrLineaVertical = gStrLineaVerticalDerecha;

   // Llama a Linea Vertical para Dibujar Linea Vertical Izquierda
   SbDibujaLineaVertical(intCol2,intRen1+1,intRen2-1);

   // Regresa el valor Guardado
   gStrLineaVertical = strAuxiliar;


   // Se coloca en la esquina inferior izquierda
   sbGotoXY(intRen2,intCol1);
   //printf("%c",'+');
   printf("%ls",gStrEsquinaInferiorIzquierda);

   // Ciclo para dibujar la linea inferior
   for(intPos=intCol1+1;intPos<intCol2;intPos++)
      //printf("%c",'-');
      printf("%ls",gStrLineaHorizontalInferior);

   // Dibuja la esquina inferior derecha
   //printf("%c",'+');
   printf("%ls",gStrEsquinaInferiorDerecha);

   // Verifica si imprime el Título
   if (strlen(pStrTitulo)>0)
   {

       // Imprime el Título del Marco
       sbGotoXY(intRen1,intCol1+3);

       // Despliega el titulo
       printf("%s",pStrTitulo);
   }


}

// Funcion     ; sbDibujaVentana
// Objetivo    : Dibuja una Ventana en la Pantalla
void sbDibujaVentana(int  intRen1,      // Renglon de la Esquina Superior Izquierda
                     int  intCol1,      // Columna de la Esquina Superior Izquierda
                     int  intRen2,      // Renglón de la Columna inferior derecha
                     int  intCol2,      // Columna de la esquina inferior derecha
                     char *pStrTitulo)  // Título que llevará el Marco; opcional si viene vació
{
   int intPos;

   // Dibuja el Marco de la Ventana
   sbDibujaMarco(intRen1,intCol1,intRen2,intCol2,"");

   // Dibuja el Conector Izquierdo
   sbGotoXY(intRen1+2,intCol1);
   printf("%ls",gStrConectorIzquierdo);

   // Dibuja el Conector Derecho
   sbGotoXY(intRen1+2,intCol2);
   printf("%ls",gStrConectorDerecho);

   // Dibuja la linea en el tercer renglón con respecto al inicial
   sbGotoXY(intRen1+2,intCol1+1);

   // Ciclo para dibujar la linea debajo del Titulo de la Ventana
   for(intPos=intCol1+1;intPos<intCol2;intPos++)
      //printf("%c",'-');
      printf("%ls",gStrLineaHorizontal);

   //Se ubica para centrar el Título
   sbGotoXY(intRen1+1,(intCol2-intCol1-strlen(pStrTitulo))/2);

   // Despliega el titulo
   printf("%s",pStrTitulo);



}

// Funcion     ; sbLimpiaArea
// Objetivo    : Limpia un Área en la Pantalla con Espacios en Blanco
void sbLimpiaArea(int  intRen1,      // Renglon de la Esquina Superior Izquierda
                  int  intCol1,      // Columna de la Esquina Superior Izquierda
                  int  intRen2,      // Renglón de la Columna inferior derecha
                  int  intCol2)      // Columna de la esquina inferior derecha
{

   // Variables para los Ciclos
   int iRen,iCol;

   // Ciclo
   for (iRen=intRen1;iRen<=intRen2; iRen++)
       for (iCol=intCol1;iCol<=intCol2; iCol++)
       {
           // Se ubica en el Renglon y Columna
           sbGotoXY(iRen,iCol);
           // Imprime el Espacio en Blanco
           printf("%c",32);
       }
}
