#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h> /* Uses system ELF definition structs and constants */


int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <elf_file>\n", argv[0]);
        return 1;
    }

FILE *file = fopen(argv[1], "rb");
if(!file){
perror("Failed to open file");
return 1;
}

    return 0;
}
