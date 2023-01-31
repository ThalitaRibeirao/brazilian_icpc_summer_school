#include <stdio.h>
#include <stdlib.h>

int main(){
    int d, f;
    scanf("%d %d", &f, &d);
    int *diaP = malloc((f+100)*sizeof(int));
    int *diaC = malloc((f+100)*sizeof(int));
    int *pode = malloc((d+100)*(sizeof(int)));

    if(f>d){
        printf("N\n");
        return 0;
    }
    for(int i = 0; i<d; i++){
        pode[i] = 0;
    }

    for(int i = 0; i<f; i++){
        scanf("%d", &diaP[i]);
    }

    for(int i = 0; i<f; i++){
        scanf("%d", &diaC[i]);
    }

    for(int i = 0; i<f; i++){
        if(pode[(diaP[i]+diaC[i])%d]++!=0){
            printf("N\n");
            return 0;
        } 
    }
    printf("S\n");
}
