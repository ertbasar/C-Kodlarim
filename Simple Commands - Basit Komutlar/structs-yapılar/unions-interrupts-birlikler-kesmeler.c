/*
Bu kısımda da biraz birliklerden bahsedeceğim. Kendisinin ve değişkenlerinin tanımı yapılarla aynıdır sadece struct yerine union kelimesi kullanılır.
Birlikler aslında yapılara benzese de bellek organizasyonları arasında çok temel bir fark vardır. Birlik elemanlarının hepsi aynı adresten başlayacak olarak 
yerleşirler ve en uzun elemanı kadar yer ayrılmış olur. Farklı zamanlarda kullanılacak bazı değişkenler için ayrı ayrı yer ayırmamak için veya bir bütün veya bütünün
parçaları üzerinde işlem yaparak bütün oluşturmak için. Bu kullanımlarda dikkat edilmelidir aksi taktirde veri kaybı yaşanabilir.
*/
/*
Kesmeler: mikroişlemcinin o anda çalıştırdığı koda ara vererek başka bir kodun icra edilmesi durumudur. 3 gruba ayrılır: 
Yazılım kesmeleri: Programcının INT makine komutuyla dahil ettiği kesmelerdir, işlevleri fonksiyon çağırmayla aynıdır
Donanım kesmeleri: Dışsal bir birim tarafından mikroişlemcinin INT ucunun aktive edilmesiyle çağrılırlar
İçsel kesmeler: Mikroişlemcinin bir makine kodunu icra ederken problemle karşılaştığında kendisinin çağırdığı kesmelerdir.
*/

#include <stdio.h>
#include <stdlib.h>
//birlik tanımı yapıldı
union DENEME{
    int tamsayi;
    int dizi[10];
    char harf;
};
union DENEME2{
    int tamsayi;
    int dizi[5];
    char harf;
};
int main(){
    union DENEME xyz;
    printf("%lu\n", sizeof(xyz));//40 bitlik bi alan ayırır
    union DENEME2 xyz2;
    printf("%lu\n", sizeof(xyz2));//20 bitlik bi alan ayırır
    return 0;
}