#include <stdio.h>
#include <stdlib.h>
int main(){
    long int n, k;
    scanf("%d %d", &n, &k);

    long int i = 1, aux, j=1;
    long int valor[1000000];
    scanf("%d", &valor[0]);
    long int acu = 0;
    while(i<k){
        if(i<n){
            scanf("%ld", &valor[i]);
            acu =0;
            j=1;
            while(j<=i){
                acu += j*valor[i-j];
                j++;
            }
            if(acu < valor[i]){
                valor[i] = acu;
            }
        }
        else{
            acu =0;
            j=1;
            while(j<=i){
                acu += j*valor[i-j];
                j++;
            }
            valor[i] = acu;

        }
        i++;
    }
    printf("%ld", valor[k-1]);

}
