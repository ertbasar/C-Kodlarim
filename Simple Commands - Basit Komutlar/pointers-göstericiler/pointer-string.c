/*
Stringler de fazlasıyla yaygın kullanımı olan degiskenlerdir. Char dizileri olarak düşünülebilirler.
En basit tanımlanması char deneme[] = "selam"; olarak yapılabilir. C derleyicileri derleme aşamasında herhangi bir stringle
karşılaştıklarında önce bellekte bir yere yerleştirir sonrasında da NULL karakterini koyar. Sonra da string yerine o koyduğu
yerin başlangıç adresini koyar. Benzer bir durum char *p; p = "Deneme"; ile de olur.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    //burada yukarıdaki özetteki işlemleri gerçekleştireceğim
    char deneme[] = "selam";
    char *p;
    p = "Deneme";//işaretçi olduğundan * kullanımı yok. 
    printf("%s\n%s\n",deneme, p);
    printf("İşaretçinin ilk elemanı:%c\n",*p);//p'nin ilk elemanını yazdırır.
    return 0;
}