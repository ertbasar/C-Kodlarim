/*
Burada birkaç farklı pointer kullanımından bahsedeceğiz. Çok kullanılmayan, biraz alışılmışın dışında olan pointerlardan.
1- Gösterici dizileri: Elemanları göstericilerden oluşan dizilerdir -> <tür>*<dizi ismi>[dizi uzunluğu] Burada malloc kullanımı
gereklidir yoksa gösterici hatası alabiliriz.
2- Göstericileri gösteren göstericiler: <gösterici türü> ** <gösterici ismi> şeklindedir. Burada da malloc kullanımı gereklidir
ve katman sayısı kadar yapılması gereklidir.
3- Fonksiyon Göstericileri: Nasıl bir dizinin ismi bellekteki başlangıç adresini gösteriyorsa bir fonksiyonun ismi de onun
bellekteki başlangıç adresini gösterir. Fonksiyon isimleri aynı türden bir fonksiyon göstericisine atanabilirler.
*/
#include <stdio.h>
#include <stdlib.h>
void fonk(void){
    printf("Selam, boş fonksiyona girdim\n");
}
int topla(int a, int b){
    printf("Selam, toplama fonksiyonuna girdim\n");
    return a + b;
}
int main(void){
    //1 örneği
    int *s[10];
    for (int i = 0; i < 10; i++)
    {
        s[i] = (int*)malloc(sizeof(int)*10);//Dizinin her elemanına 10'ar intlik yer ayırdık.
        //Geçersiz if'i koyulabilir. Bu bilgisayarda hafıza sorunu olmayacağından dynamic-memory-allocation.c dosyasından sonraki süreçte bu if bloğunu koymaya gerek görmüyorum.
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", s[i]);//Dizinin her elemanının başlangıç adresi yazdırıldı
    }
    for (int i = 0; i < 10; i++)//Belleğin geri sisteme verilmesi
    {
        free(s[i]);
    }
    //2 örneği
    char **p;
    p = (char**)malloc(sizeof(char*));//Göstericiyi gösteren bir nesne
    *p = (char*)malloc(sizeof(char));//Karakter türünden bir gösterici
    **p = 'a';//Karakter türünden bir nesne
    printf("%c\n",**p);
    free(*p);
    free(p);
    //3 örneği
    void(*a)(void);//a, geri dönüş değeri ve parametresi void olan fonksiyonların adreslerini tutabilir.
    a = fonk;//Dikkat edilirse () kullanılmadı
    a();//fonk isimli fonksiyonun adresine geçildi ve çalıştırıldı
    //3 ikinci örnek, farklı fonksiyon tipini tutmak istedim
    int(*b)(int, int);
    b = topla;
    printf("%d", b(2,3));
    printf("\n");
    return 0;
}