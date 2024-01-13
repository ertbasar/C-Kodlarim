/*
Basit getchar putchar komutları yaparak ısınıyorum. 
Burada getch kullanmak biraz sıkıntılı çünkü klavyeden alırken bazı sorunlarla 
karşılaşabiliyorum. Bunun nedeni conio kütüphanesinin macte olmaması ve benzeri
olan kütüphaneyle de tam olarak istediklerimi yapamamış olmam. Bu yüzden farklı
bir dosyada da bunu deneyeceğim
*/
#include <stdio.h>

int main() {
    char alinan, denenen, denenen2, denenen3;

    // Basit alma ve yazdırma
    alinan = getchar();
    putchar(alinan);

    // 'a' ise yazdır
    while (getchar() != '\n'); // newline karakterini temizle
    if ((denenen = getchar()) == 'a')
        putchar(denenen);

    // 'q' gelene kadar yazdırma
    while (getchar() != '\n'); // newline temizle
    while ((denenen2 = getchar()) != 'q') {
        putchar(denenen2);
        while (getchar() != '\n'); // newline temizle
    }

    // 'E' gelene kadar yazdırma (for döngüsü)
    while (getchar() != '\n'); // newline temizle
    for (denenen3 = getchar(); denenen3 != 'E' && denenen3 != EOF; denenen3 = getchar()) {
        putchar(denenen3);
        while (getchar() != '\n'); // newline temizle
    }

    return 0;
}
