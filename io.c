//
// Created by matko on 15. 4. 2022.
//
#include "io.h"
#include "ctype.h"
static int too_long = 0;
int read_word(char *s, int max, FILE *f){
    int c;
    int counter = 0;

    while(isspace(c= fgetc(f)));
    if(c == EOF){
        return EOF;
    }

    while(!isspace(c) && counter < max-1)
    {
        if(c == EOF){
            return EOF;
        }
        s[counter]=c;
        counter++;
        c= fgetc(f);
    }

    if(counter ==max-1){
        while(!isspace(c=fgetc(f)) || c == EOF){
            if(c == EOF){
                return EOF;
            }
            counter++;
        }
    }
    return counter;
}
