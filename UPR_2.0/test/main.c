#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void shortest_starts(const char *ss, FILE* tmpf){
    if (ss == tmpf)
    {
        printf("%s", ss);
    }
    
}


int main(){
    
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    const char* ss = buffer;

    printf("shortest-starts %s", ss);

    FILE* tmpf = tmpfile();
    fputs("womAn\n", tmpf);
    fputs("Lay\n", tmpf);
    fputs("do\n", tmpf);
 
    rewind(tmpf);


    shortest_starts(buffer, tmpf);

    while (fgets(buffer, sizeof buffer, tmpf))
    {
        printf("%s \n", buffer);
    }
    

    





    return 0;
}