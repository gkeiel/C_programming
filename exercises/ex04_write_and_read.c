#include <stdio.h>
#include <stdlib.h>

// write and read FILE .txt with functions analogous to scanf and printf
int main()
{
    FILE *file;
    char phrase1[30];
    char phrase2[30];
    
    // read from keyboard
    printf("Enter a name to be saved: ");
    fgets(phrase1, 50, stdin);
    
    // write in document
    file = fopen("write_and_read.txt","a");
    fprintf(file, "%s", phrase1);
    fclose(file);
    
    // read from document and print on screen
    file = fopen("write_and_read.txt","r");
    while( fgets(phrase2, 50, file) != NULL){
        // print on screen
        printf("%s ", phrase2);
    }
    fclose(file);
    return 0;
}