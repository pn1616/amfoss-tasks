#include <stdio.h>
#include <stdlib.h>

void subtask2() {
    char content[1000];
    FILE *infile = fopen("input.txt", "r");
    fgets(content, 1000, infile);
    fclose(infile);

    FILE *outfile = fopen("output.txt", "w");
    fputs(content, outfile);
    fclose(outfile);

    outfile = fopen("output.txt", "r");
    fgets(content, 1000, outfile);
    fclose(outfile);

    printf("%s", content);
}

int main() {
    char inputcontent[1000];
    printf("Content of the file: \n");
    fgets(inputcontent, 1000, stdin);

    FILE *infile = fopen("input.txt", "w");
    fputs(inputcontent, infile);
    fclose(infile);

    printf("printing output.txt...\n");
    subtask2();

    return 0;
}
