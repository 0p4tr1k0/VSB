#include <stdio.h>

int mylength(const char *str) {
    if(*str == '\0'){
        return 0;
    } else {
        return 1 + mylength(str + 1);
    }
}

int main(){
    printf("%d\n", mylength(""));
    printf("%d\n", mylength("abc"));
    printf("%d\n", mylength("abc 0 asd"));
    return 0;
}