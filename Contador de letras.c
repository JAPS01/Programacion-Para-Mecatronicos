#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
int i, j; // estas variables son para los for
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z; // donde se almacenan la cantidad de veces que se introduce una letra
char letras[1000]; //  aqui se almacenan las letras



void limpiar_variables() // se limpian todas las variables 
{
    i = 0;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    E = 0;
    F = 0;
    G = 0; 
    H = 0; 
    I = 0; 
    J  = 0; 
    K = 0; 
    L = 0; 
    M  = 0; 
    N = 0; 
    O  = 0; 
    P = 0;
    Q  = 0; 
    R = 0; 
    S = 0; 
    T = 0; 
    U = 0; 
    V = 0; 
    W  = 0; 
    X = 0; 
    Y = 0; 
    Z = 0;
    int f;
    for (f = 0; f < 100; f++)
    {
        letras[f] = 0;
    }
}

void contador() // se cuentan todas las letras hasta que el arreglo este en 0
{
    while (letras[i] != 0) // Este es el Parse  
    {
        switch (tolower(letras[i])) // Se convierten en minusculas las letras para ahorrar tener que volver a poner los casos para las mayusculas y las tome todas como minusculas  
        {
        case 'a':
            A++;
            break;
        case 'b':
            B++;
            break;
        case 'c':
            C++;
            break;
        case 'd':
            D++;
            break;
        case 'e':
            E++;
            break;
        case 'f':
            F++;
            break;
        case 'g':
            G++;
            break;
        case 'h':
            H++;
            break;
        case 'i':
            I++;
            break;
        case 'j':
            J++;
            break;
        case 'k':
            L++;
            break;
        case 'l':
            L++;
            break;
        case 'm':
            M++;
            break;
        case 'n':
            N++;
            break;
        case 'o':
            O++;
            break;
        case 'p':
            P++;
            break;
        case 'q':
            Q++;
            break;
        case 'r':
            R++;
            break;
        case 's':
            S++;
            break;
        case 't':
            T++;
            break;
        case 'u':
            U++;
            break;
        case 'v':
            V++;
            break;
        case 'w':
            W++;
            break;
        case 'x':
            X++;
            break;
        case 'y':
            Y++;
            break;
        case 'z':
            Z++;
            break;
        }
        i++;
    }
}

void imprimir_letras_existentes() // se verifica cada caso y luego se imprimen solo los valores de las letras que tenemos en el arreglo
{
    if (A != 0)
    {
        printf("A: %i", A);
    }
    printf(" ");
    if (B != 0)
    {
        printf("B: %i", B);
    }
    printf(" ");
    if (C != 0)
    {
        printf("C: %i", C);
    }
    printf(" ");
    if (D != 0)
    {
        printf("D: %i", D);
    }
    printf(" ");
    if (E != 0)
    {
        printf("E: %i", E);
    }
    printf(" ");
    if (F != 0)
    {
        printf("F: %i", F);
    }
    printf(" ");
    if (G != 0)
    {
        printf("G: %i", G);
    }
    printf(" ");
    if (H != 0)
    {
        printf("H: %i", H);
    }
    printf(" ");
    if (I != 0)
    {
        printf("I: %i", I);
    }
    printf(" ");
    if (J != 0)
    {
        printf("J: %i", J);
    }
    printf(" ");
    if (K != 0)
    {
        printf("K: %i", K);
    }
    printf(" ");
    if (L != 0)
    {
        printf("L: %i", L);
    }
    printf(" ");
    if (M != 0)
    {
        printf("M: %i", M);
    }
    printf(" ");
    if (N != 0)
    {
        printf("N: %i", N);
    }
    printf(" ");
    if (O != 0)
    {
        printf("O: %i", O);
    }
    printf(" ");
    if (P != 0)
    {
        printf("P: %i", P);
    }
    printf(" ");
    if (Q != 0)
    {
        printf("Q: %i", Q);
    }
    printf(" ");
    if (R != 0)
    {
        printf("R: %i", R);
    }
    printf(" ");
    if (S != 0)
    {
        printf("S: %i", S);
    }
    printf(" ");
    if (T != 0)
    {
        printf("T: %i", T);
    }
    printf(" ");
    if (U != 0)
    {
        printf("U: %i", U);
    }
    printf(" ");
    if (V != 0)
    {
        printf("V: %i", V);
    }
    printf(" ");
    if (W != 0)
    {
        printf("W: %i", W);
    }
    printf(" ");
    if (X != 0)
    {
        printf("X: %i", X);
    }
    printf(" ");
    if (Y != 0)
    {
        printf("Y: %i", Y);
    }
    printf(" ");
    if (Z != 0)
    {
        printf("Z: %i", Z);
    }
}

int main()
{
    while (1)
    {
        fflush(stdin);
        limpiar_variables();
        printf("\nIntroduzca la palabra\n");
        gets(letras);
        contador();
        imprimir_letras_existentes();
        printf("\n");
        system("PAUSE");
        system("cls");
    }
}
