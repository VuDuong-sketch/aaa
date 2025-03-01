#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_LINE_LENGTH 256 
 
void editFile(const char *filename) { 
    FILE *file; 
    char lines[100][MAX_LINE_LENGTH]; // Array to hold lines from the file 
    int lineCount = 0; 
 
    // Step 1: Open the file for reading 
    file = fopen(filename, "r"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        return; 
    } 
 
    // Step 2: Read the contents 
    while (fgets(lines[lineCount], MAX_LINE_LENGTH, file) != NULL) { 
        lineCount++; 
    } 
    fclose(file); // Step 4: Close the file 
 
    // Step 3: Modify the contents (example: append " - edited" to each line) 
    for (int i = 0; i < lineCount; i++) { 
        // Ensure we don't exceed the buffer size 
        if (strlen(lines[i]) + 10 < MAX_LINE_LENGTH) { 
            strcat(lines[i], " - edited\n"); 
        } 
    } 
 
    // Step 5: Open the file for writing 
    file = fopen(filename, "w"); 
    if (file == NULL) { 
        perror("Error opening file for writing"); 
        return; 
    } 
 
    // Step 6: Write the modified contents 
    for (int i = 0; i < lineCount; i++) { 
        fputs(lines[i], file); 
    } 
     
    // Step 7: Close the file again 
    fclose(file); 
} 
 
int main() { 
    const char *filename = "example.txt"; 
    editFile(filename); 
    return 0; 
} 
