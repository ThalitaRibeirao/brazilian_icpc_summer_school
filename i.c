#include <stdio.h>
#include <stdlib.h>

int main(){
    int  t, i;
    long long  a, b, k, interval, pos;

    scanf("%d", &t);


    for(i = 0; i < t; i++){
        scanf("%lld %lld %lld", &a, &b, &k);
        interval = a - b;
        pos = (k/2) * interval;

        if(k%2 == 1){
            pos += a;
        }
        printf("%lld\n", pos);
    }


    return 0;
}