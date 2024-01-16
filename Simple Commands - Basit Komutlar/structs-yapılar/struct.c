/*
-Yapılar objelere benzer ancak tüm objeleri public olarak düşünülebilir. Değişkenlere vs direkt erişilebilir. Genel bildirim şekillerine bakacak olursak:
struct [yapı ismi(denelde büyük harflerle)]{<tür> <isim>; <tür> <isim>;....}([değişken listesi] değişkenler burada da tanımlanabilir, global olurlar); şeklindedir. 
Yapı değişkenleri ise: struct <yapı ismi> <yapı değişkeninin ismi> şeklindedir. Bir yapı değişkeninin taanımlandığını gören derleyici, bellekte ilgili yapının
tüm elemanlarını içeri alacak uzunlukta sürekli yer tahsis eder. Tahsis edilen boyutu da sizeof ile de öğrenebiliriz. sizeof ile %lu kullanımı daha iyi olurmuş.
-Bunun dışında tabii ki yapı göstericileri de vardır. struct <yapı ismi> *<yapı göstericisinin ismi> şeklinde tanımlanırlar. erişimde -> kullanılabilir
-Ayrıca iç içe yapılara değinmeden de olmaz. Bunun yapılması için içerdeki yapının ya daha yukarıda ya da dıştaki yapının içinde tanımlanmalıdır.
-Yapı değişkenleri arasında işlemler gerçekleştirilebilir. Bunun için tamamen aynı türden 2 yapı gereklidir.
-Yapılar fonksiyonlara parametre olarak da gönderilebilirler, burada call by referance olarak göndermek özellikle büyük yapılarda çok daha verimlidir.
*/
/*
Hizalama kavramı: Yapı değişkenleri daha hızlı erişmek için çift adreslerden başlayacak şekilde yerleştirilirler (char dışında). Eğer yapının toplam uzunluğu tek
bir değerse bir boşluk bırakılarak çift olması sağlanır.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//yapı tanımlanması
struct DATE{
    int gun, ay, yil;
};
//iç içe yapının tanımlanmış olduğu daha gelişmiş bir yapı örneği
struct INSAN{
    char isim[30];
    int yas;
    int ugurlu_sayilari[3];//diziler ve göstericiler de yapı elemanı olabilirler
    int *deneme;//ilkdeğer verilmemiş göstericiler bellekte herhangi güvenli bir bölgeyi göstermez
    struct DATE dogum;
};
void dispDate(struct DATE *a){
    printf("Dogum gunu:%d/%d/%d\n", a->gun, a->ay, a->yil);
}

int main(void){
    //yapı örneği
    struct INSAN ertugrul;
    strcpy(ertugrul.isim,"Ertugrul");//Stringe sonradan atama yapmak için bu fonksiyonu kullanmamız gerekir.
    ertugrul.deneme = (int *)malloc(sizeof(int) * 5);//deneme işaretçisine yer ayırdık, sonrasında bazı işlemler yapabiliriz ve yazdırabiliriz.
    ertugrul.ugurlu_sayilari[0]=23;//gibi bir atama da yapabiliriz
    ertugrul.dogum.gun = 30;
    ertugrul.dogum.ay = 5;
    ertugrul.dogum.yil = 1999;
    dispDate(&(ertugrul.dogum));//adres göndermek daha iyi olur demiştik, o şekilde gönderdim
    printf("%lu\n",sizeof(ertugrul));
    free(ertugrul.deneme);
    //yapı göstericisi örneği
    struct INSAN *alparslan;
    struct INSAN deneme2;
    alparslan = &deneme2;
    (*alparslan).yas = 45;//yapı göstericisinin elemanlarına bu sekilde erisilebilir
    printf("Alparslanın yasi:%d\n", deneme2.yas);
    alparslan->yas = 53;//ancak bu sekilde erismek görsel olarak daha güzeldir
    printf("Alparslanın gercek yasi aslında:%d\n", deneme2.yas);
    return 0;
}





