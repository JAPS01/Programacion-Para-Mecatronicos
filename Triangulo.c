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

    else if ((lg[2] > lg[1]) && (lg[2] > lg[0]))
    {
        lg[3] = (lg[1] + lg[0]);
        if (lg[2] < lg[3])
        {
            true = 1;
        }
    }
} 

void parse()  // determinamos si cumple los requisitos para ser un triangulo y verificamos de que tipo es
{    
    if ((lg[0] == lg[1]) && (lg[0] == lg [2]))
    {
        printf("Es un equilatero");
    }
    else
    {
        if (true==1)
        {
            if ((lg[0] == lg[1]) || (lg[0] == lg[2]) || (lg[2] == lg[1]))
            {
                printf(" Es un isosceles");
            }
            if ((lg[0] != lg[1]) && (lg[0] != lg[2]) && (lg[2] != lg[1]))
            {
                printf("Es un escaleno");
            }
        }
        else
        {
            printf("No cumple con la condicion de que:\n%cpara formar un tri%cngulo se requiere que: el lado mayor sea menor que la suma de los otros dos lados%c", 40, 160, 41);
        }
    }
}

int main()
{
    do
    {
        fflush(stdin);
        limpiar_variables();
        printf("introduzca la primera longitud\n");
        scanf("\n%i", &lg[0]);
        printf("introduzca la segunda longitud\n");
        scanf("\n%i", &lg[1]);
        printf("introduzca la tercera longitud\n");
        scanf("\n%i", &lg[2]);
        indentificar_mayor();
        parse();
        printf("\nQuiere salir? S/N");
        salir = getche();
        system("PAUSE");
        system("cls");
    } while (salir != 's');
}
