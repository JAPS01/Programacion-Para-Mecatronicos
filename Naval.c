#include<stdio.h>
#include<conio.h>
#include<stdlib.h>  
#include<windows.h>
#include<time.h>
#include <ctype.h>


int x = 15;
int y = 15;
int i;
int j;
int op;
int fil[3];
int pos;
int l = 0;
char dis[2];
int pt;
char salir;
int killplayer;
int killenemy;
int disparo_repetido = 0;
int confirm[7];
int shot[2];
char camb;
int k = 0;
int lok;
int repetido = 0;
int confi[7];



 void gotoxy(int x,int y)
 {  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }

char mapa[11][11] = // aqui colocamos a las naves enemigas para luego comprovar si dimos al blanco
    {
        {' ','1','2','3','4','5','6','7','8','9',66},
        {'1',32,32,32,32,32,32,32,32,32,32},
        {'2',32,32,32,32,32,32,32,32,32,32},
        {'3',32,32,32,32,32,32,32,32,32,32},
        {'4',32,32,32,32,32,32,32,32,32,32},
        {'5',32,32,32,32,32,32,32,32,32,32},
        {'6',32,32,32,32,32,32,32,32,32,32},
        {'7',32,32,32,32,32,32,32,32,32,32},
        {'8',32,32,32,32,32,32,32,32,32,32},
        {'9',32,32,32,32,32,32,32,32,32,32},
        {65,32,32,32,32,32,32,32,32,32,32}
    
    };

char jugador[11][11] =
    {
        {' ','1','2','3','4','5','6','7','8','9',66},
        {'1',32,32,32,32,32,32,32,32,32,32},
        {'2',32,32,32,32,32,32,32,32,32,32},
        {'3',32,32,32,32,32,32,32,32,32,32},
        {'4',32,32,32,32,32,32,32,32,32,32},
        {'5',32,32,32,32,32,32,32,32,32,32},
        {'6',32,32,32,32,32,32,32,32,32,32},
        {'7',32,32,32,32,32,32,32,32,32,32},
        {'8',32,32,32,32,32,32,32,32,32,32},
        {'9',32,32,32,32,32,32,32,32,32,32},
        {65,32,32,32,32,32,32,32,32,32,32}
    };

char enemigo[12][11] = 
    {
        {' ','1','2','3','4','5','6','7','8','9',66},
        {'1',32,32,32,32,32,32,32,32,32,32},
        {'2',32,32,32,32,32,32,32,32,32,32},
        {'3',32,32,32,32,32,32,32,32,32,32},
        {'4',32,32,32,32,32,32,32,32,32,32},
        {'5',32,32,32,32,32,32,32,32,32,32},
        {'6',32,32,32,32,32,32,32,32,32,32},
        {'7',32,32,32,32,32,32,32,32,32,32},
        {'8',32,32,32,32,32,32,32,32,32,32},
        {'9',32,32,32,32,32,32,32,32,32,32},
        {65,32,32,32,32,32,32,32,32,32,32}
    };

void mapenemy()
    {
            enemigo[2][2] = 32;
            enemigo[3][2] = 32;

            enemigo[5][5] = 32;
            enemigo[5][6] = 32;
            enemigo[5][7] = 32;
            
            enemigo[7][4] = 32;
            enemigo[8][4] = 32;

            enemigo[1][5] = 32;
            enemigo[1][6] = 32;

            enemigo[3][9] = 32;
            enemigo[4][9] = 32;
            enemigo[5][9] = 32;
            
            enemigo[7][7] = 32;
            enemigo[7][8] = 32;

            enemigo[4][2] = 32;
            enemigo[4][3] = 32;

            enemigo[6][2] = 32;
            enemigo[7][2] = 32;
            enemigo[8][2] = 32;
            
            enemigo[2][6] = 32;
            enemigo[3][6] = 32;

        srand(time(NULL));      //aqui damos una ubicacion Ramdon al enemigo
        pos = (rand() % 3);
        if (pos == 0)
        {
            enemigo[2][2] = 178;
            enemigo[3][2] = 178;

            enemigo[5][5] = 178;
            enemigo[5][6] = 178;
            enemigo[5][7] = 178;
            
            enemigo[7][4] = 178;
            enemigo[8][4] = 178;
        }
        if (pos == 1)
        {
            enemigo[1][5] = 178;
            enemigo[1][6] = 178;

            enemigo[3][9] = 178;
            enemigo[4][9] = 178;
            enemigo[5][9] = 178;
            
            enemigo[7][7] = 178;
            enemigo[7][8] = 178;
        }
        if ((pos == 2) || (pos == 3))
        {
            enemigo[4][2] = 178;
            enemigo[4][3] = 178;

            enemigo[6][2] = 178;
            enemigo[7][2] = 178;
            enemigo[8][2] = 178;
            
            enemigo[2][6] = 178;
            enemigo[3][6] = 178;
        }
    }

void remap()
    {
        mapa[dis[0]][dis[1]] = 197;
        mapa[0][0] = 32;
        mapa[0][10] = 66;
        mapa[10][0] = 65;


        for (i = 1; i < 10; i++)
        {
            mapa[i][0] = 48+i;
        }
        for (int q = 1; q < 10; q++)
        {
            mapa[0][q] = 48+q;
        }
        
    }

void gamer()
    {
        gotoxy(55,4);
        printf("Mapa del Jugador");
       for (i = 0; i < 11; i++)
        {
            
            for (j = 0; j < 11; j++)
            {
                gotoxy(50+i,j+5);
                printf("%c", jugador[i][j]); //aqui va enemigo en lugar de mapa
            }
            printf("\n");
        }
    }

void remapgame()
    {
        jugador[shot[0]][shot[1]] = 197;
        jugador[0][0] = 32;
        jugador[0][10] = 66;
        jugador[10][0] = 65;

        for (i = 1; i < 10; i++)
        {
            jugador[i][0] = 48+i;
        }
        for (int q = 1; q < 10; q++)
        {
            jugador[0][q] = 48+q;
        }
        
    }

void enemy()
    {
        gotoxy(55,4);
        printf("Mapa Enemigo");
        for (i = 0; i < 11; i++)
        {
            
            for (j = 0; j < 11; j++)
            {
                gotoxy(50+i,j+5);
                printf("%c", mapa[i][j]); //aqui va enemigo en lugar de mapa
            }
            printf("\n");
        }
    }

void disparos()
    {   
        pt = 0;
        for (i = 0; i < 7; i++) // le damos valores a las posiciones para luegro comprovar si el disparo esta repetido o no
        {
            confirm[i] = i;
        }
        do
            {

                // turno del jugador
                gotoxy(55,4);
                printf("Turno del jugador");
                Sleep(2000);
                system("cls");
                pt = 0;
                enemy();
                gotoxy(49,16);
                printf("[");
                gotoxy(51,16);
                printf("]");
                gotoxy(52,16);
                printf("[");
                gotoxy(54,16);
                printf("]");
                gotoxy(50,16);
                dis[0] = getche();
                gotoxy(53,16);
                dis[1] = getche();

                // concatenamos los numeros
                dis[0] -= 48;
                dis[1] -= 48;


                remap();
                enemy();

                if (pos == 0) // posicion del mapa 1
                {
                    if ((disparo_repetido == 0) && (confirm[0] == 0))
                    {
                        if ((dis[0] == 2) && (dis[1] == 2)) // primera posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[0] = 1;
                            // mapa[dis[0]][dis[1]] = 157;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[1] == 1))
                    {
                        if ((dis[0] == 3) && (dis[1] == 2)) // segunda posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[1] = 2;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[2] == 2))
                    {
                        if ((dis[0] == 5) && (dis[1] == 5)) // primera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[2] = 3;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[3] == 3))
                    {
                        if ((dis[0] == 5) && (dis[1] == 6)) // segunda posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[3] = 4;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[4] == 4))
                    {
                        if ((dis[0] == 5) && (dis[1] == 7)) // tercera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[4];
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[5] == 5))
                    {
                        if ((dis[0] == 7) && (dis[1] == 4)) // primera posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[5] = 6;
                            system("cls");
                        }
                    }
                    if ((disparo_repetido == 0) && (confirm[6] == 6))
                    {
                        if ((dis[0] == 8) && (dis[1] == 4)) // segunda posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confirm[6] = 7;
                            system("cls");
                        }
                    }
                }

                if (pos == 1) // posicion del mapa 2
                {
                    if ((disparo_repetido == 0) && (confirm[0] == 0))
                    {
                        if ((dis[0] == 1) && (dis[1] == 5)) // primera posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[0] = 1;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[1] == 1))
                    {
                        if ((dis[0] == 1) && (dis[1] == 6)) // segunda posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[1] = 2;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[2] == 2))
                    {
                        if ((dis[0] == 3) && (dis[1] == 9)) // primera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[2] = 3;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[3] == 3))
                    {
                        if ((dis[0] == 4) && (dis[1] == 9)) // segunda posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[3] = 4;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[4] == 4))
                    {
                        if ((dis[0] == 5) && (dis[1] == 9)) // tercera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[4];
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[5] == 5))
                    {
                        if ((dis[0] == 7) && (dis[1] == 7)) // primera posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[5] = 6;
                            system("cls");
                        }
                    }
                    if ((disparo_repetido == 0) && (confirm[6] == 6))
                    {
                        if ((dis[0] == 7) && (dis[1] == 8)) // segunda posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[6] = 7;
                            system("cls");
                        }
                    }
                }
                
                if ((pos == 2) || (pos == 3)) // posicion del mapa 2
                {
                    if ((disparo_repetido == 0) && (confirm[0] == 0))
                    {
                        if ((dis[0] == 4) && (dis[1] == 2)) // primera posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[0] = 1;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[1] == 1))
                    {
                        if ((dis[0] == 4) && (dis[1] == 3)) // segunda posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[1] = 2;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[2] == 2))
                    {
                        if ((dis[0] == 6) && (dis[1] == 2)) // primera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[2] = 3;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[3] == 3))
                    {
                        if ((dis[0] == 7) && (dis[1] == 2)) // segunda posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[3] = 4;
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[4] == 4))
                    {
                        if ((dis[0] == 8) && (dis[1] == 2)) // tercera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[4];
                            system("cls");
                        }
                    }

                    if ((disparo_repetido == 0) && (confirm[5] == 5))
                    {
                        if ((dis[0] == 2) && (dis[1] == 6)) // primera posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[5] = 6;
                            system("cls");
                        }
                    }
                    if ((disparo_repetido == 0) && (confirm[6] == 6))
                    {
                        if ((dis[0] == 3) && (dis[1] == 6)) // segunda posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[6] = 7;
                            system("cls");
                        }
                    }
                    else
                    {
                        gotoxy(50,17);
                        printf("Ya disparaste en esta posicion");
                        Sleep(1500);
                        system("cls");
                    }
                }

                Sleep(1000);
                system("cls");
                // turno de la maquina 
                gotoxy(55,4);
                printf("Turno del enemigo");
                Sleep(2000);
                system("cls");
                gamer();
                Sleep(1500);
                srand(time(NULL));      //aqui dispara de forma aleatoria la maquina
                shot[0] = ((rand() % 8) + 1);
                shot[1] = ((rand() % 8) + 1);
                gotoxy(49,16);
                printf("[");
                gotoxy(51,16);
                printf("]");
                gotoxy(52,16);
                printf("[");
                gotoxy(54,16);
                printf("]");
                Sleep(1500);
                gotoxy(50,16);
                printf("%i", shot[0]);
                Sleep(1500);
                gotoxy(53,16);
                printf("%i", shot[1]);
                remapgame();
                gamer();
                Sleep(2500);
                // cambiar para el enemigo

                if (lok == 0) // posicion del mapa 1
                {
                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 3) && (shot[1] == 3)) // primera posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killplayer += 1;
                            confi[0] = 1;
                            // mapa[dis[0]][dis[1]] = 157;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[1] == 1))
                    {
                        if ((shot[0] == 4) && (shot[1] == 3)) // segunda posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confi[1] = 2;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[2] == 2))
                    {
                        if ((shot[0] == 4) && (shot[1] == 7)) // primera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confi[2] = 3;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[3] == 3))
                    {
                        if ((shot[0] == 5) && (shot[1] == 7)) // segunda posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confi[3] = 4;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 6) && (shot[1] == 7)) // tercera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confi[4];
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 8) && (shot[1] == 8)) // primera posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confi[5] = 6;
                            system("cls");
                        }
                    }
                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 9) && (shot[1] == 8)) // segunda posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            killenemy += 1;
                            confi[6] = 7;
                            system("cls");
                        }
                    }
                }

                if (lok == 1) // posicion del mapa 2
                {
                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 7) && (shot[1] == 3)) // primera posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[0] = 1;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[1] == 1))
                    {
                        if ((shot[0] == 8) && (shot[1] == 3)) // segunda posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[1] = 2;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[2] == 2))
                    {
                        if ((shot[0] == 2) && (shot[1] == 6)) // primera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[2] = 3;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[3] == 3))
                    {
                        if ((shot[0] == 2) && (shot[1] == 7)) // segunda posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[3] = 4;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[4] == 4))
                    {
                        if ((shot[0] == 2) && (shot[1] == 8)) // tercera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[4];
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[5] == 5))
                    {
                        if ((shot[0] == 4) && (shot[1] == 8)) // primera posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[5] = 6;
                            system("cls");
                        }
                    }
                    if ((repetido == 0) && (confi[6] == 6))
                    {
                        if ((shot[0] == 4) && (shot[1] == 9)) // segunda posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confi[6] = 7;
                            system("cls");
                        }
                    }
                }
                
                if (lok == 2) // posicion del mapa 2
                {
                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 5) && (shot[1] == 2)) // primera posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[0] = 1;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 6) && (shot[1] == 2)) // segunda posicion nave 1
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[1] = 2;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 6) && (shot[1] == 5)) // primera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[2] = 3;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 7) && (shot[1] == 5)) // segunda posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[3] = 4;
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 8) && (shot[1] == 5)) // tercera posicion nave 2
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[4];
                            system("cls");
                        }
                    }

                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 8) && (shot[1] == 7)) // primera posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[5] = 6;
                            system("cls");
                        }
                    }
                    if ((repetido == 0) && (confi[0] == 0))
                    {
                        if ((shot[0] == 8) && (shot[1] == 8)) // segunda posicion nave 3
                        {
                            gotoxy(50,17);
                            printf("le diste");
                            Sleep(1500);
                            pt = 1;
                            ++killenemy;
                            confirm[6] = 7;
                            system("cls");
                        }
                    }
                }

                
                if (killenemy == 7)
                {
                    l = 1;
                }

                if (killplayer == 7)
                {
                    l = 1;
                }
                // if (pt == 0)
                // {
                //     gotoxy(50,17);
                //     printf("No le diste");
                //     Sleep(1500);
                // }

                    system("cls");
            } while (l != 1);

    }

void posjuga()
    {
                lok = 1;
                jugador[7][3] = 178;
                jugador[8][3] = 178;

                jugador[2][6] = 178;
                jugador[2][7] = 178;
                jugador[2][8] = 178;
                
                jugador[4][8] = 178;
                jugador[4][9] = 178;
            gotoxy(55,5);
            printf("Mapa del Jugador");
        for (i = 0; i < 11; i++)
            {
                
                for (j = 0; j < 11; j++)
                {
                    gotoxy(50+i,j+6);
                    printf("%c", jugador[i][j]); //aqui va enemigo en lugar de mapa
                }
                printf("\n");
            }

            gotoxy(50,3);
            printf("Quiere cambiar la posicion del jugador (S)i/(N)o");
            gotoxy(50,4);
            camb = getche();

        do
        {

            camb += k;
            
        for (i = 0; i < 11; i++)
            {
                
                for (j = 0; j < 11; j++)
                {
                    gotoxy(50+i,j+6);
                    printf("%c", jugador[i][j]); //aqui va enemigo en lugar de mapa
                }
                printf("\n");
            }

            if (camb == 115)
            {
                // restablecemos a origen 
                jugador[7][3] = 32;
                jugador[8][3] = 32;

                jugador[2][6] = 32;
                jugador[2][7] = 32;
                jugador[2][8] = 32;
                
                jugador[4][8] = 32;
                jugador[4][9] = 32;


                jugador[5][2] = 32;
                jugador[6][2] = 32;

                jugador[6][5] = 32;
                jugador[7][5] = 32;
                jugador[8][5] = 32;
                
                jugador[8][8] = 32;
                jugador[7][8] = 32;

                // posicion seleccionada
                jugador[3][3] = 178;
                jugador[4][3] = 178;

                jugador[4][7] = 178;
                jugador[5][7] = 178;
                jugador[6][7] = 178;
                
                jugador[8][8] = 178;
                jugador[9][8] = 178;
                lok = 0;
                ++k;
            }

            if (camb == 116)
            {

                // restablecemos a origen
                jugador[5][2] = 32;
                jugador[6][2] = 32;

                jugador[6][5] = 32;
                jugador[7][5] = 32;
                jugador[8][5] = 32;
                
                jugador[8][8] = 32;
                jugador[7][8] = 32;

                jugador[3][3] = 32;
                jugador[4][3] = 32;

                jugador[4][7] = 32;
                jugador[5][7] = 32;
                jugador[6][7] = 32;
                
                jugador[8][8] = 32;
                jugador[9][8] = 32;

                // posicion seleccionada
                jugador[7][3] = 178;
                jugador[8][3] = 178;

                jugador[2][6] = 178;
                jugador[2][7] = 178;
                jugador[2][8] = 178;
                
                jugador[4][8] = 178;
                jugador[4][9] = 178;
                lok = 1;
                ++k;
            }
            

            if (camb == 117)
            {
                
                // restablecemos a origen
                jugador[3][3] = 32;
                jugador[4][3] = 32;

                jugador[4][7] = 32;
                jugador[5][7] = 32;
                jugador[6][7] = 32;
                
                jugador[8][8] = 32;
                jugador[9][8] = 32;

                jugador[7][3] = 32;
                jugador[8][3] = 32;

                jugador[2][6] = 32;
                jugador[2][7] = 32;
                jugador[2][8] = 32;
                
                jugador[4][8] = 32;
                jugador[4][9] = 32;

                // posicion selecionada 
                jugador[5][2] = 178;
                jugador[6][2] = 178;

                jugador[6][5] = 178;
                jugador[7][5] = 178;
                jugador[8][5] = 178;
                
                jugador[8][8] = 178;
                jugador[7][8] = 178;
                lok = 2;
                ++k;
            }
            gotoxy(55,5);
            printf("Mapa del Jugador");
        for (i = 0; i < 11; i++)
            {
                
                for (j = 0; j < 11; j++)
                {
                    gotoxy(50+i,j+6);
                    printf("%c", jugador[i][j]); //aqui va enemigo en lugar de mapa
                }
                printf("\n");
            }
            if (tolower(camb) != 110)
            {
                gotoxy(50,18);
                printf("Cambiar otra vez (S)i/(N)o");
                gotoxy(50,19);
                camb = getche();
            }
            if (k == 3)
            {
                k = 0;
            }

        } while(tolower(camb) != 110);
        Sleep(1500);
        system("cls");
    }

void juego()
    {
        pt = 0;

        posjuga();
        mapenemy();
        disparos();

        if (killenemy == 7)
        {
            gotoxy(50,5);
            printf("   _____                                 _          ");
            gotoxy(50,6);
            printf("  %c ____|                               | |         ", 92);
            gotoxy(50,7);
            printf(" | |  __    __ _   _ __     __ _   ___  | |_    ___ ");
            gotoxy(50,8);
            printf(" | | |_ |  / _` | | '_ %c   / _` | / __| | __|  / _ %c", 92, 92);
            gotoxy(50,9);
            printf(" | |__| | | (_| | | | | | | (_| | %c__ %c | |_  |  __/", 92, 92);
            gotoxy(50,10);
            printf("  %c_____|  %c__,_| |_| |_|  %c__,_| |___/  %c__|  %c___|", 92, 92, 92 , 92, 92);
            Sleep(2500);
        }

        if (killplayer == 7)
        {
            gotoxy(50,5);
            printf(".______    _______ .______       _______   __       _______..___________. _______ ");
            gotoxy(50,6);
            printf("|   _  %c  |   ____||   _  %c     |       %c |  |     /       ||           ||   ____|", 92, 92, 92);
            gotoxy(50,7);
            printf("|  |_)  | |  |__   |  |_)  |    |  .--.  ||  |    |   (----``---|  |----`|  |__   ");
            gotoxy(50,8);
            printf("|   ___/  |   __|  |      /     |  |  |  ||  |     %c   %c        |  |     |   __|  ", 92, 92);
            gotoxy(50,9);
            printf("|  |      |  |____ |  |%c  %c----.|  '--'  ||  | .----)   |       |  |     |  |____ ", 92, 92);
            gotoxy(50,10);
            printf("| _|      |_______|| _| `._____||_______/ |__| |_______/        |__|     |_______|");
            Sleep(2500);
        }
    }

void tutorial()
    {
        char jugexp[12][11] = 
        {
            {' ','1','2','3','4','5','6','7','8','9',66},
            {'1',32,178,32,32,32,32,32,32,32,32},
            {'2',32,178,32,32,32,32,32,32,32,32},
            {'3',32,32,32,32,32,32,32,32,32,32},
            {'4',32,32,32,32,32,32,32,32,32,32},
            {'5',32,32,32,178,178,178,32,32,32,32},
            {'6',32,32,32,32,32,32,32,32,32,32},
            {'7',32,32,32,32,32,32,32,32,32,32},
            {'8',32,32,32,32,178,32,32,32,32,32},
            {'9',32,32,32,32,178,32,32,32,32,32},
            {65,32,32,32,32,32,32,32,32,32,32}
        };
            char enmexp[12][11] = 
        {
            {' ','1','2','3','4','5','6','7','8','9',66},
            {'1',32,32,32,32,32,32,32,32,32,32},
            {'2',32,32,32,32,32,32,32,32,32,32},
            {'3',32,32,32,32,32,32,32,32,32,32},
            {'4',32,32,32,32,32,32,32,32,32,32},
            {'5',32,32,32,32,32,32,32,32,32,32},
            {'6',32,32,32,32,32,32,32,32,32,32},
            {'7',32,32,32,32,32,32,32,32,32,32},
            {'8',32,32,32,32,32,32,32,32,32,32},
            {'9',32,32,32,32,32,32,32,32,32,32},
            {65,32,32,32,32,32,32,32,32,32,32}
        };
        gotoxy(66,3);
        printf("TUTORIAL");
        gotoxy(50,4);
        printf("El primer valor que se introduzca sera ");
        gotoxy(50,5);
        printf("el de las fila y el segundo las columna");
        Sleep(5000);
        system("cls");

        gotoxy(66,3);
        printf("TUTORIAL");
        gotoxy(50,4);
        printf("mapa enemigo");
        for (i = 0; i < 11; i++)
        {
            
            for (j = 0; j < 11; j++)
            {
                gotoxy(50+i,j+5);printf("%c", enmexp[i][j]);
            }
            printf("\n");
        }
        Sleep(1250);
        
        gotoxy(50,17);
        printf("El mapa enemigo no nos muestra sus posiciones.");
        gotoxy(50,18);
        printf("(Por eso no se muestran las naves).");
        Sleep(2000);
        gotoxy(50,19);
        printf("cada posicion tiene su indentificador.");
        gotoxy(50,20);
        printf("(Ver Mapa)");
        Sleep(8000);
        gotoxy(50,21);
        printf("Para disparar se mostrara un texto como el siguiente:");
        gotoxy(50,22);
        printf("Lugar a disparar:");
        gotoxy(50,23);
        printf("Luego de esto debe de poner la ubicacion.");
        Sleep(5000);
        gotoxy(50,24);
        printf("A");
        Sleep(650);
        gotoxy(51,24);
        printf("5");
        Sleep(625);
        gotoxy(50,25);
        printf("El mapa enemigo se actualizara colocando");
        gotoxy(50,26);
        printf("el disparo en la posicion indicada.");
        Sleep(5000);
        system("cls");

        gotoxy(20,4);
        printf("Mapa antes de disparar.");
        for (i = 0; i < 11; i++)
        {
            
            for (j = 0; j < 11; j++)
            {
                gotoxy(20+i,j+5);printf("%c", enmexp[i][j]);
            }
            printf("\n");
        }
            enmexp[10][5] = 206;
            gotoxy(50,4);
            printf("Mapa despues de disparar.");
        for (i = 0; i < 11; i++)
        {
            
            for (j = 0; j < 11; j++)
            {
                gotoxy(50+i,j+5);printf("%c", enmexp[i][j]);
            }
            printf("\n");
        }
        Sleep(5000);
        system("cls");

        gotoxy(63,3);
        printf("TUTORIAL");
        gotoxy(50,4);
        printf("mapa del jugador");
            for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 11; j++)
            {
                gotoxy(50+i,j+5);printf("%c", jugexp[i][j]);
            }
            printf("\n");
        }
        gotoxy(50,17);
        printf("El mapa del jugador muestra sus naves.");
        gotoxy(50,18);
        printf("El jugador puede cambiar la posicion de sus naves.");
        gotoxy(50,19);
        Sleep(3000);
        printf("cuando inicia el juego se le pregunta.");
        gotoxy(50,20);
        Sleep(1000);
        printf("%cDesea cambiar la posicion%c (S)i/(N)o", 168, 63);
        Sleep(1500);
        gotoxy(50,21);
        printf("S");
        Sleep(1000);
        gotoxy(50,22);
        printf("mapa del jugador");
        //se quitan los barcos 
        jugexp[1][2] = 32;
        jugexp[2][2] = 32;
        jugexp[5][5] = 32;
        jugexp[5][6] = 32;
        jugexp[5][4] = 32;
        jugexp[8][5] = 32;
        jugexp[9][5] = 32;

        // cambiamos la posicion de los barcos 
        jugexp[5][5] = 178;
        jugexp[6][5] = 178;
        jugexp[2][3] = 178;
        jugexp[3][3] = 178;
        jugexp[4][3] = 178;
        jugexp[5][1] = 178;
        jugexp[5][2] = 178;

        for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 11; j++)
            {
                gotoxy(50+i,j+23);printf("%c", jugexp[i][j]);
            }
            printf("\n");
        }
        Sleep(5000);
        system("cls");
        gotoxy(50,5);
        printf("El jugador puede cambiar las veces que quira la posicion.");
        gotoxy(50,6);
        Sleep(1000);
        printf("Luego de aceptar la posicion el juego empieza");
        Sleep(5000);
        system("cls");
        return inicio();
    }

void inicio()
    { 
        gotoxy(50,3);
        printf("Batalla Naval");
            gotoxy(30,5);
            printf("                               o o");
            gotoxy(30,6);
            printf("                               o ooo");
            gotoxy(30,7);
            printf("                                 o oo");
            gotoxy(30,8);
            printf("                                    o o      |   #)");
            gotoxy(30,9);
            printf("                                     oo     _|_|_#_");
            gotoxy(30,10);
            printf("                                       o   | U505  |");
            gotoxy(30,11);
            printf("  __                    ___________________|       |_________________");
            gotoxy(30,12);
            printf(" |   -_______-----------                                              %c", 92);
            gotoxy(30,13);
            printf(">|    _____                                                   --->     )");
            gotoxy(30,14);
            printf(" |__ -     ---------_________________________________________________ /");
        
        gotoxy(50,16);
        printf("1.Iniciar");
        gotoxy(50,17);
        printf("2.Tutorial");
        gotoxy(50,18);
        printf("[");
        gotoxy(52,18);
        printf("]");
        gotoxy(51,18);
        op = getche();
        system("cls");
        op -= 48;
        if (op == 1)
        {
            juego();
        }
        if (op == 2)
        {
            tutorial();
        }
    }


int main()
    {
        do
        {
            l = 1;
            if (l == 1) // ponemos al mapa en su estado inicial
            {
                    for (i = 1; i < 11; i++)
                    {
                        for (int q = 1; q < 11; q++)
                            {
                                mapa[i][q] = 32;
                            }
            
                    }

                    for (i = 1; i < 11; i++)
                    {
                        for (int q = 1; q < 11; q++)
                            {
                                jugador[i][q] = 32;
                            }
            
                    }
            }
            l = 0;
            inicio();
            gotoxy(50,18);
            printf("Salir (S)i/(N)o");
            gotoxy(50,19);
            salir = getche();
            system("cls");
        } while (tolower(salir)!='s');
        

    }
