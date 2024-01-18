#include <stdio.h>
#include <stdlib.h>
struct INSAN{
    int yas;
    char isim[50];
};
int main(void){
    struct INSAN topluluk[10];
    printf("%lu\n", sizeof(topluluk));
    return 0;
}