#include<stdio.h> //biblioteca para el programa

int main(int argc, char const *argv[]) //main
{
    int monedas[] = {25, 10, 5, 1}; //definimos las monedas empezando por la mayor, para 
    int n = 4; //4 por el número de tipo de monedas
    int cantidad, i, num; //variables no definidas

    printf("\t**Problema del cambio (con algoritmo voras**)\n");
    printf("\nIngresa la cantidad de cambio a dar: ");
    scanf("%d", &cantidad); //Cantidad

    printf("La cantidad %d con la menor monedas posibles son: \n",cantidad);

        for (i = 0; i < n; i++)
        {
            num = cantidad / monedas[i]; //cantidad de monedas de ese tipo
            cantidad = cantidad % monedas[i]; //cantidad de monedas por cubrir
            if (num > 0)
            {
                printf(" %d monedas de $%d\n ",num, monedas[i]);
            }
            
        }

    return 0;
}
