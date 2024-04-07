#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create input file and input string
void createInputFile() {
    FILE *file;
    char input[1000];

    // Open input file in write mode
    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Read input string from user
    printf("Enter text to store in input file:\n");
    fgets(input, sizeof(input), stdin);

    // Write input string to file
    fputs(input, file);

    // Close file
    fclose(file);

    // Display path of input file
    printf("Input file (input.txt) created in the current directory.\n");
}

// Function to separate sentences and write to output file
void separateSentences() {
    FILE *inputFile, *outputFile;
    char input[1000];
    char *sentence;
    int count = 0;

    // Open input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Open output file in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(input, sizeof(input), inputFile)) {
        // Tokenize input into sentences
        sentence = strtok(input, ".!?");

        // Write each sentence to output file
        while (sentence != NULL) {
            fprintf(outputFile, "%s\n", sentence);
            count++; // Increment count for each sentence written
            sentence = strtok(NULL, ".!?");
        }
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    // Display information about the number of strings found and written
    printf("Number of strings found and written to output file: %d\n", count);

    // Display path of output file
    printf("Output file (output.txt) created in the current directory.\n");

    // Write this information to the output file
    outputFile = fopen("output.txt", "a"); // Open output file in append mode
    if (outputFile == NULL) {
        printf("Error opening output file for writing additional info!\n");
        exit(1);
    }
    fprintf(outputFile, "Number of strings found and written to output file: %d\n", count);
    fclose(outputFile);
}

// Function to display content of output file in terminal
void displayOutputFile() {
    FILE *outputFile;
    char ch;

    // Open output file in read mode
    outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Read and display file content character by character
    printf("Content of output file (output.txt):\n");
    while ((ch = fgetc(outputFile)) != EOF) {
        putchar(ch);
    }

    // Close file
    fclose(outputFile);
}

int main() {
    // Create input file and input string
    createInputFile();

    // Separate sentences and write to output file
    separateSentences();

    // Display content of output file
    displayOutputFile();

    printf("\nSeparation of sentences completed. Check input.txt and output.txt for results.\n");

    return 0;
}
