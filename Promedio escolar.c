#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int i, x, j, k, l, notas[2][200], total, count[9], promedio;


void cantidad_de_materias()
{
    count[0] +=count[x];
}
void suma_notas()
{
    total += (notas[0][j]);   
}

void promedio_de_calificacion()
{
    promedio = total/count[0];
    printf("Tu promedio es %d", promedio);
}

void main()
{
    for (x = 1; x < 5; x++)
    {
        for (k = 1; k < 3; k++)
        {
            printf("A%co escolar %d\n", 164, x);
            printf("Cantidad de materias en el cuatrimetre %d\n", k);
            scanf("%d", &count[x]);
            cantidad_de_materias();

            for (j = 0; j < count[x]; j++)
            {   
                printf("introduce la calificacion %d\n", j+1);
                scanf("%d", &notas[0][j]);
                suma_notas();
            }
            system("cls");

        }


    }
    promedio_de_calificacion();
    getch();
}
