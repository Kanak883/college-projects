


#include <stdio.h>
#include <stdlib.h>

#define max_textLength 256
#define FILE_NAME "simple_file.txt"

void createFile();
void readFile();
void appendFile();


int main() {
    int choice;

    while (1) {
        printf("\nSimple File Editor\n");
        printf("1. Create and Write to File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendFile();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

void createFile() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }

    char text[max_textLength];
    printf("Enter text to write to the file: ");
    fgets(text, max_textLength, stdin);
    fprintf(file, "%s", text); 

    fclose(file);
    printf("Text written to file successfully!\n");
}

void readFile() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char text[max_textLength];
    printf("\nFile Contents:\n");
    while (fgets(text, max_textLength, file) != NULL) {
        printf("%s", text); 
    }

    fclose(file);
}

void appendFile() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char text[max_textLength];
    printf("Enter text to append to the file: ");
    fgets(text, max_textLength, stdin);
    fprintf(file, "%s", text);

    fclose(file);
    printf("Text appended to file successfully!\n");
}
