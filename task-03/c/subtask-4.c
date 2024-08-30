#include <stdio.h>
#include <stdlib.h>

int read_number_from_file(const char *filename) {
    int num;
    FILE *inputfile = fopen(filename, "r");
    if (inputfile == NULL) {
        printf("Could not open %s\n", filename);
        exit(1);
    }
    fscanf(inputfile, "%d", &num);
    fclose(inputfile);
    return num;
}

void write_number_to_file(const char *filename, int content) {
    FILE *infile = fopen(filename, "w");
    if (infile == NULL) {
        printf("Could not open %s\n", filename);
        exit(1);
    }
    fprintf(infile, "%d", content);
    fclose(infile);
}

void generate_pattern(int n, char *pattern) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            pattern[index++] = ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            pattern[index++] = '*';
        }
        pattern[index++] = '\n';
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            pattern[index++] = ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            pattern[index++] = '*';
        }
        pattern[index++] = '\n';
    }
    pattern[index] = '\0';
}

void write_pattern_to_file(const char *filename, const char *pattern) {
    FILE *outfile = fopen(filename, "w");
    if (outfile == NULL) {
        printf("Could not open %s\n", filename);
        exit(1);
    }
    fputs(pattern, outfile);
    fclose(outfile);
}

int main() {
    int n;
    char pattern[1024];
    
    printf("Enter the number: ");
    scanf("%d", &n);

    write_number_to_file("input2.txt", n);
    n = read_number_from_file("input2.txt");
    generate_pattern(n, pattern);
    write_pattern_to_file("output2.txt", pattern);

    return 0;
}
