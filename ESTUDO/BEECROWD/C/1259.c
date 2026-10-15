#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ParImpar(int N, int numeros[], int *Qtdpar, int *Qtdimpar, int par[], int impar[]){
int i = 0;

    for ( i = 0; i < N; i++)
    {
        if ((numeros[i]  % 2) == 0)
            {
                par[*Qtdpar] = numeros[i];
                (*Qtdpar)++;
            }

    if ((numeros[i] % 2) != 0 )
        {
            impar[*Qtdimpar] = numeros[i];
            (*Qtdimpar)++;
        }
    }
}
void OrdenaPar( int qtdpar, int par[] ){
int i, j, aux;

for ( i = 0; i < qtdpar; i++)
    {
        for( j = 0; j < qtdpar - 1 - i; j++)
            {
                if ( par[j] > par[j+1])
                    {
                        aux = par[j];
                        par[j] = par[j+1];
                        par[j+1] = aux;
                    }
                }
    }
}

void OrdenaImpar( int qtdimpar, int impar[] ){
int i, j, aux;

for ( i = 0; i < qtdimpar; i++)
    {
        for(j = 0; j < qtdimpar - 1 - i; j++ )
            {
                if ( impar[j] < impar[j+1]) // 9, 1, 7, 11, 13
                    {
                        aux = impar[j];
                        impar[j] = impar[j+1];
                        impar[j+1] = aux;
                    }
                }
        }
}

void imprimir(int qtdpar, int qtdimpar, int par[], int impar[]){

for ( int i = 0; i < qtdpar; i++)
    {
    printf("%d\n", par[i]);
    }


    for ( int i = 0; i < qtdimpar; i++)
    {
    printf("%d\n", impar[i]);
    }


}

int main(){

int N, i;
int qtdpar = 0; int qtdimpar = 0;
int *Qtdpar, *Qtdimpar;

Qtdpar = &qtdpar;
Qtdimpar = &qtdimpar;

srand(time(NULL));

scanf("%d", &N);

int numeros[N], par[N], impar[N];

for (i = 0; i < N; i++) {
    numeros[i] = rand() % 100;
}


ParImpar(N, numeros, &qtdpar, &qtdimpar, par, impar);
OrdenaPar( qtdpar, par);
OrdenaImpar(qtdimpar, impar);
imprimir(qtdpar, qtdimpar, par, impar);
return 0;

}
