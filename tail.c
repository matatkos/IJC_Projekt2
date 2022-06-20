#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#define MAXCHAR 4095
FILE *file;
void Warning_msg(const char *fmt, ...);
void Error_exit(const char *fmt, ...);
void Read_Files(FILE *fp, long int to_delete);

///////////////////////////////////////
//Hlavny kod
int main(int argc,  char** argv) {
    long int delete_lines = 10;
    int file_found = 0;
    if(argc > 4){
        Error_exit("Too many arguments: %d", argc);
    }
    for (int i = 1; i < argc; ++i) {
        if(strcmp(argv[i],"-n")==0){
            if(++i <= argc){
                char* ptr;
                delete_lines= strtol(argv[i], &ptr,0);
                if(delete_lines < 0){
                    Error_exit("Number cannot be negative. Current number: %d",delete_lines);
                }
            }
        }
    }
    for (int i = 1; i < argc; ++i) {
        file= fopen(argv[i], "r");
        if(file){
            Read_Files(file,delete_lines);
            file_found=1;
        }
    }
    if(file_found == 0){
        file = stdin;
        Read_Files(file, delete_lines);
    }

    return 0;
}


//Warning_msg funkcia z prveho projektu
void Warning_msg(const char *fmt, ...){
    va_list  ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

//Error_exit funkcia z prveho project
void Error_exit(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}

void Read_Files(FILE *fp,long int to_delete){
    long int lines_in_file=1;
    char c;
    while((c=(char)fgetc(fp)) != EOF){
        if(c == '\n'){
            lines_in_file++;
        }
    }

    int ignore_line= 0;
    long int print_from= lines_in_file - to_delete;
    long int counter=0;
    int character_count=0;
    int max_char_error=0;
    char d;
    rewind(fp);

    while((d=(char)fgetc(fp)) != EOF){
        character_count++;
        if(character_count > MAXCHAR){
            max_char_error++;
            if (max_char_error == 1){
                Warning_msg("Line n.%d has too many characters.",counter);
            }
            ignore_line=1;
        }

        if(counter >= print_from){

            if(ignore_line == 0){
                printf("%c",d);
            }
        }

        if(d == '\n'){
            counter++;
            character_count=0;
            ignore_line=0;
        }
    }
}