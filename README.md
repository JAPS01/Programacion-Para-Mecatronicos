# Programacion-Para-Mecatronicos
En este Repositorio se encontraran los programas para los estudiantes de programacion para mecatronicos del ITLA
``` c
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

int true;
int lg[4];
int i;
int mayor;
char salir;

void limpiar_variables()  // se limpian las variables 
{
    mayor = 0;
    
    for (i = 0; i < 4; i++)
    {
        lg[i] = 0;
    }
    true = 0;
    
}
void indentificar_mayor() // verificamos cual es el mayor y tambien determinamos si es un triangulo
{

    if ((lg[0] > lg[1]) && (lg[0] > lg[2])) 
    {
        lg[3] = (lg[1] + lg[2]);
        if (lg[0] < lg[3])
        {
            true = 1;
        }
    }

    else if ((lg[1] > lg[0]) && (lg[1] > lg[2]))
    {
        lg[3] = (lg[0] + lg[2]);
        if (lg[1] < lg[3])
        {
            true = 1;
        }
    }

```
