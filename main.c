// Inclusión de Librerías
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>


// Prototipo de Función que dibuja el Tablero
void sbTableroDibuja();

// Prototipo Letra Siguiente
int fnIntLetraSiguiente();

// Prototipo Inicializa Semilla Aleatoria
void sbAleatorioInicializa();

// Definición de Función Principal
int main()
{
    // Limpia la Pantalla
    sbLimpiaPantalla();

    // Dibuja el Tablero
    sbTableroDibuja();

    // Presiona cualquier tecla para finalizar
    getch();

    // Inicializa Aleatoria
    sbAleatorioInicializa();

    // Imprime la Letra siguiente
    printf("\n Letra: %c \n",fnIntCaracterSiguiente());

    // Espera n segundos
    sleep(5);

    // Imprime otra letra
    printf("\n Letra: %c \n",fnIntCaracterSiguiente());

    // Retorna 0
    return 0;

}

// Función para obtener letra siguiente
int fnIntCaracterSiguiente()
{
    // Retorna la siguiente letra aleatoria
    return (rand()%(90-48+1))+48;

}

// Inicializa Semilla Aleatoria
void sbAleatorioInicializa()
{
    // Iniciliza
    srand((unsigned int)time(0));

}


// Función para dibujar el Tablero
void sbTableroDibuja()
{
    // Desactiva el Cursor
    sbCursor(0); // 0 = False

    // Dibuja el Marco
    sbDibujaMarco(5,15,20,65,"JaorTetris Ver 2.16");

}
