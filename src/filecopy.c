/*
This program copies the contents of one file to another and prints counts of the non-whitespace characters in the terminal.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for exit()

int main(int argc, char **argv) /* command line arguments */ { 
    /*
    ch variable of (int) type to check for the EOF
    count variable as a flag for the character count
    pointer to FILE readfile (FILE *) for the access of the file stream to read content from the file
    pointer to FILE writefile (FILE *) for the access of the file stream to write content to the file
    */
    int ch;
    unsigned long count = 0;
    FILE *readfile;
    FILE *writefile;

    /*
    checks if the command line arguments are sufficient enough for the reference of arguments as file names
    */
    if(argc != 3) {
        printf("Not enough arguments to read and write the files.\n");
        exit(EXIT_FAILURE);
    }

    /*
    fopen() opens the file which is to be read, initializes the readfile (FILE *) with a pointer to FILE object (FILE *), 
    the readfile handle which is access to the file stream, if successful or NULL if encounters an error
    */
    if((readfile = fopen(argv[1], "r")) == NULL) {
        printf("%s file does not exist.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*
    fopen() opens or creates the file in which the read content will be written, initializes the writefile (FILE *) with a pointer to FILE object
    the readfile handle which is access to the file stream, if successful or NULL if encounters an error
    */
    if((writefile = fopen(argv[2], "w")) == NULL) {
        printf("%s file does not exist.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*
    the loop reads the character using the file stream from the file bit by bit and writes each character to the file through writefile stream until it encounters EOF
    and increments the count of the non whitespace characters
    */
    while((ch = getc(readfile)) != EOF) {
        putc((unsigned char)ch, writefile);
        if(ch != ' ' && ch != '\n' && ch != '\t' && ch != '\v')
            count++;
    }

    /*
    fclose() to close the files identified by 
    readfile, writefile, flushing buffers occupied by the file contents
    */
    fclose(readfile);
    fclose(writefile);

    printf("%s contents copied to %s.\n", argv[1], argv[2]);
    printf("%s has %lu characters.\n", argv[1], count);

    return 0;
}