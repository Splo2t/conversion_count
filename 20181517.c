#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileLineCount(FILE *pFILE);

int fileWordCount(FILE *pFILE);

int fileCharCount(FILE *pFILE);
char *changeAlp(FILE *myFile, char*name);
int main(int argc, char *argv[]) {

    FILE *f = fopen(argv[1], "r");
    printf("Line Count:%d\n", fileLineCount(f));
    printf("Word Count:%d\n", fileWordCount(f));
    printf("Character Count:%d\n", fileCharCount(f));

    char *fileName = changeAlp(f, argv[1]);
    printf("File Saved in my %s", fileName);
    fclose(f);
    return 0;
}

int fileCharCount(FILE *myFile) {
    rewind(myFile);
    char buffer[1024];
    int count = 0;
    int i = 0;
    while( !feof( myFile ) )
    {
        i = 0;
        fgets( buffer, sizeof(buffer), myFile);
        while(buffer[i] != 0){
            if(buffer[i] == ' '){
                i++;
                continue;
            }
            count++;
            i++;
        }
    }
    return count;
}

int fileWordCount(FILE *myFile) {
    rewind(myFile);
    char buffer[1024];
    int count = 0;
    int i = 0;
    while( !feof( myFile ) )
    {
        i = 0;
        fgets( buffer, sizeof(buffer), myFile);
        while(buffer[i] != 0){
            if(buffer[i] == ' '){
                count++;
            }
            i++;
        }
    }
    return count;
}

int fileLineCount(FILE *myFile) {
    rewind(myFile);
    char buffer[1024];
    int count = 0;
    while( !feof( myFile ) )
    {
        fgets( buffer, sizeof(buffer), myFile);
        count++;
    }
    return count;
}

char *changeAlp(FILE *myFile, char*name){
    rewind(myFile);
    char *fileName = (char*)malloc(sizeof(char)*strlen(name));
    strcpy(fileName,name);
    strcpy(&fileName[strlen(fileName)-3],"rev");
    FILE *writeF = fopen(fileName,"w");

    char buffer[1024];
    int count = 0;
    int i = 0;
    while( !feof( myFile ) )
    {
        i = 0;
        fgets( buffer, sizeof(buffer), myFile);
        while(buffer[i] != 0){
            if(buffer[i] <= 'z' && buffer[i] >= 'a'){
                buffer[i] -= 32;
            }
            else if(buffer[i] <= 'Z' && buffer[i] >= 'A'){
                buffer[i] += 32;
            }
            i++;
        }
        fputs(buffer,writeF);
    }
    fclose(writeF);
    return fileName;
}
