
#include "htab.h"
#include "io.h"
#include <stdio.h>
#include "stdlib.h"


#define MAX_WORD_LEN 127
#define max_hashtable_size 7000

void print(htab_pair_t *pair){
    printf("%s\t%d\n",pair->key,pair->value);

}


int main(int argc, char **argv){
    int max = MAX_WORD_LEN;
    char *s= malloc(sizeof(char)*(max+1));
    FILE *fp = stdin;





    htab_t *table = htab_init(max_hashtable_size);


    while(read_word(s,max,fp)!= EOF){
        htab_pair_t *tmp = htab_lookup_add(table,s);
        if(tmp == NULL){
            fprintf(stderr, "Cannot make item");
            htab_free(table);
            return 1;
        }
        tmp->value++;
        s= malloc(sizeof(char)*(max+1));
    }


    htab_for_each(table, &print);

    htab_free(table);

    fclose(fp);

    return 0;
}