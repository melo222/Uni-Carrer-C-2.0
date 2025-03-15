#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN 256;

struct career{
    int id;
    char name_career [256];
};
typedef struct career career;

void create_career() {
    career tmp;
    char name[256];
    printf("\ninsert a name for the career: ");
    fgets(name, 256, stdin);
    gets(name);

    strcpy(tmp.name_career, name);
}


int main(int argc, char const *argv[]){
    
    char answare = 0;
    while(answare != -1){
        printf("Usage:\n");
        printf("<1> Create istance of career\n");
        printf("<2> View career\n");
        printf("<3> Delete career\n");
        printf("<4> Create Exam\n");
        printf("<5> View Exam\n");
        printf("<6> Delete Exam\n");
        printf("0) print again the menu\n");
        printf("-1) exit\n");
        scanf("%c", answare);
        printf("answare = %c\n", answare);
        switch (answare)
        {
        case 0: continue;
        case 1: 
            create_career();
            break;
        }
    }
    return 0;
}
