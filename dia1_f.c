#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);

    int * num = malloc(n*sizeof(int));
    int * indice = malloc(q*sizeof(int));
    int * resp = malloc(q*sizeof(int));

    for(int i = 0;i<n; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 0; i<q; i++){
        scanf("%d", &indice[i]);
    }

    

    


}