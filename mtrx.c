#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INP_LEN 300



typedef struct mtrxMatrix {
    int col;
    int row;
    float* data;
} mtrxMatrix;


int mtrxCreate() {
    char inp[INP_LEN];
    int col;
    int row;
    float* data;

    while (1) {
        fgets(inp, INP_LEN, stdin);
        if (strchr(inp, '\n') != NULL) {
            break;
        }
        printf("Input is too long!");
        while (getchar() != '\n');
    }

    // char* colChar = strtok(inp, " ");
    // char* rowChar = strtok(NULL, " ");

    printf("%s", inp);

    for (int i = 0; inp[i] != '\0'; i++) {
        if (!(isdigit(inp[i]) || inp[i]=='\n' || inp[i]=='.' || inp[i]== ' ')) {
            printf("String contains non-digit and non-point characters");
            return 0;
        }
    }

    printf("valid");
    // printf("%s and %s", colChar, rowChar);
    
}




int main() {
    // mtrxMatrix* m = mtrxCreate();
    mtrxCreate();
    return 0;
}