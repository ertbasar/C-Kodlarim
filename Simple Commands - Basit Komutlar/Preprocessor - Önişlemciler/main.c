/*
Burada ve oluşturduğum header dosyasında önişlemciler üzerinde çalıştım. Önişlemciler genel olarak kaynak program
üzerinde bir takım düzenleme ve değişiklikler yapan önmodüllerdir. Burada include ve define gibi komutlar kullanılabilir.
Ayrıca iç içe kullanıma olanak sağladığından ana modülün daha sade görünmesine yardımcı olur
*/
#include "header.h"
int main(void){
    for(int i = 0; i < MAX; i++)
        printf("%d \n", i);
    return 0;
}