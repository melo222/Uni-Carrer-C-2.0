#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAXLEN 100

typedef struct {
    char cod[5];
    char nome[100];
    short cfu;
    short voto;
} Exam;


void scrivi_su_file_testo(const char *filename, Exam *dati, size_t size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Errore apertura file");
        exit(EXIT_FAILURE);
    }

    if (dati != NULL){ 
        for (size_t i = 0; i < size; i++) {
            fprintf(file, "%s|%s|%d|%d\n", dati[i].cod, dati[i].nome, dati[i].cfu, dati[i].voto);
        }
    }

    fclose(file);
}

void leggi_da_file_testo(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Errore apertura file");
        exit(EXIT_FAILURE);
    }

    Exam dato;
    char buffer[256];
    int max_len_exam = 42;
    
    int diff = 0;
    while (fgets(buffer, sizeof(buffer), file)) {

        sscanf(buffer, "%4[^|]|%99[^|]|%d|%d", dato.cod, dato.nome, &dato.cfu, &dato.voto);
        
        diff = max_len_exam - strlen(dato.nome);
        if (diff > 1){
            memset(dato.nome + strlen(dato.nome),' ',diff);
            memset(dato.nome + max_len_exam, '\0', 1);
        }

        printf("COD: %s\t NOME: %s CFU: %d\t VOTO: %d\n",dato.cod,dato.nome,dato.cfu,dato.voto);
    }    

    fclose(file);
}

void media(const char *filename, int verbose){
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Errore apertura file");
        exit(EXIT_FAILURE);
    }

    Exam dato;
    char buffer[200];
    int sum_votes=0,sum_cfu=0;
    float media=0.0;

    while (fgets(buffer, sizeof(buffer), file)) {

        sscanf(buffer, "%4[^|]|%99[^|]|%d|%d", dato.cod, dato.nome, &dato.cfu, &dato.voto);
       
        // if(verbose){
        //     printf("COD: %s\t CFU: %d\t\t Voto: %d\n", dato.cod, dato.cfu, dato.voto);
        // }

        sum_votes += dato.voto * dato.cfu;
        sum_cfu += dato.cfu;
    }

    if (verbose) {
        printf("Sum_CFU: %d\t Sum_Votes: %d\n",sum_cfu,sum_votes);
    }

    media = (float)sum_votes / (float)sum_cfu;
    printf("Media: %f\n",media);

    fclose(file);
}

int main(int argc, char const *argv[]){
    
    Exam dati[22];

    char *directory = "./Cartella_Carriere/";
    char *file_name = NULL;

    int opt;

    //flags
    int n=0,o=0,m=0,v=0,d=0;

    while ((opt = getopt(argc, (char * const *)argv, "n:o:mvd:")) != -1) {
        switch (opt) {
            case 'n':
            n=1;
                file_name = optarg;
                printf("%s",*directory+file_name);
                scrivi_su_file_testo(file_name, NULL, 3);
                printf("\nInserire i dati nel file in questo modo:\n");
                printf("CODE|NAME_EXAM|CFU|VOTE\n");
                break;
            case 'o':
            o=1;
                file_name = optarg;
                break;
            case 'd':
            d=1;
                // da implementare il file di conf/cache per la directory e anche 
                // per ad esempio l'ultima carriera aperta o in uso diciamo
                break;
            case 'm': // media
            m=1;
                break;
            case 'v': // verbose
            v=1;
                printf("verbose activate\n");
                break;
            default:
                printf("Uso: %s -n <nome file> | -o <nome file>\n", argv[0]);
                return 1;
        }
    }
    // Controllo errori per combinazioni non valide
    if (d && (n || o || m || v)) {
        printf("Errore: -d deve essere usato da solo.\n");
        return 1;
    }
    // if (v && !m) {
    //     printf("Errore: -v può essere usato solo con -m.\n");
    //     return 1;
    // }
    if (v && o) {
        leggi_da_file_testo(file_name);
    }

    if(m){
        media(file_name,v);
    }
    
    if(d){
        printf("modifica richiesta alla directory contenente le carriere, verrà applicata la modifica dopo l'esecuzioni delle azioni richieste in questa istanza.");
        // qua trasferiamo la cartella da un'altra parte.
    }
    if(!(d || n || o || m || v)){        
        printf("Uso: %s\n-----USAGE-----\n-n <new nome file> || -o <nome file> [options] {-m media, -v verbose}\n", argv[0]);
    }

    return 0;
}
