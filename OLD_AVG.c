#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 20
#define DATILEN 9

void stampa(int[][MAXLEN]);
float media_pond(int p[][MAXLEN]);

int main (int arcg, char * argv) {

    //printf("MAXLEN %d\n",DATILEN);

    /*
    ---- DATI ----
    inglese
    continuo
    diritto
    programmazione
    aspetti
    architettura
    sysop
    algoritmi
    basi
    critto
    reti
    pwm
    PSS
    AGR
    SSR

    ---- IPOTESI ----
    biometria
    CF
    MDD
    SSW
    SI(L)
    Aspetti organizzativi
    */
        
    // SCENARIO REALISTICO:

    int p[MAXLEN][MAXLEN] = {
        {   
            23, 19, 25, 30, 30, 20, 23, 29, 23, 23, 23, 24, 28, 29,
            27, 24, 21, 24, 24, 24
        },
        {
            12, 6, 12, 6, 6, 12, 12, 12, 6, 12, 6, 6, 6, 6, 
            6, 6, 6, 6, 6, 3
        }
    };


    // SCENARIO MIGLIORE:

    // int p[MAXLEN][MAXLEN] = {
    //     {   
    //         23, 19, 25, 30, 30, 20, 23, 29, 23, 23, 23, 24,
    //         30, 30, 23, 30, 30, 30, 30, 30
    //     },
    //     {
    //         12, 6, 12, 6, 6, 12, 12, 12, 6, 12, 
    //         6, 6, 6, 6, 6, 6, 6, 6, 6, 3
    //     }
    // };

    // SCENARIO BUONO:

    // int p[MAXLEN][MAXLEN] = {
    //     {   
    //         23, 19, 25, 30, 30, 20, 23, 29, 23, 23, 23, 24,
    //         28, 28, 23, 27, 27, 25, 24, 27
    //     },
    //     {
    //         12, 6, 12, 6, 6, 12, 12, 12, 6, 12, 
    //         6, 6, 6, 6, 6, 6, 6, 6, 6, 3
    //     }
    // };

    stampa(p);

    float media;
    media = media_pond(p);

    printf("\nMEDIA PONDERATA: %.5f\n",media);

    float voto_finale;

    voto_finale = (media * 11.0 ) / 3.0;

    printf("\nPUNTEGGIO INGRESSO: %.5f\n\n",voto_finale);
    
}

void stampa(int p[][MAXLEN]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<MAXLEN;j++){
            printf("%d.%d)",i,j);
            if(j<10){printf(" ");}
            printf(" %d\n",p[i][j]);
        }
        printf("\n");
    }
}

float media_pond(int p[][MAXLEN]) {
    int sp=0,sc=0;
    float m=0.0;
    for(int j=0;j<MAXLEN;j++){
        sp=sp + p[0][j] * p[1][j];
        sc=sc + p[1][j];
    }

    printf("\nsp: %d, sc: %d\n",sp,sc);
    m=(float)sp/(float)sc;
    printf("m: %f\n",m);
    return m;
}
