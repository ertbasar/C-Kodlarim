/*
makrolar typedef'e benzerler. Burada parantezlere fazlasıyla dikkat edilmesi gerekir ve sonraki satırda devam edilmek istendiğinde \ kullanımlalıdır.
*/
#define CARP(a,b) ((a)*(b))
#define MAX(a,b) ((a)>(b)*(a):(b))
#include <stdio.h>
int main(void){
    printf("%d\n", CARP(5,3));
    return 0;
}