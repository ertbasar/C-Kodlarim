/*
Tür tanımlamaları typedef <tür ismi> <tanımlanann yeni tür ismi> olarak yapılır. tür ismi standart türlerle beraber yapı, birlik veya işaretçiler olabilir.
Tanımlandıkları yerlere göre kullanımı değişebilir ancak genellikle global olarak kullanılırlar. Dizi ve göstericilerin bulunduğu karmaşık veri yapılarında 
kullanılarak yazım ve anlayış kolaylığı sağlarlar.
*/
/*
Sayımlama sabitleri yani enum bir anahtar sözcüktür. Derleyici küme parantezleri arasındaki sembolik sabitlere sıfırdan başlayarak sırasıyla artan sırada bir 
tamsayı karşılık getirir. Arada sayılar verilirse onlardan sonra benzer şekilde devam eder. enum bildirimi aynı zamanda bir tür de belirtir, yani üzerinden bir 
nesne de yaratabilirsiniz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* CHPTR;//tür tanımlaması yapıldı
enum DAYS {pztesi = 1, sl, crs, prs, cm, cmtesi, pzr};//enum tanımı
int main(void){
    CHPTR deneme;
    deneme = (char*)malloc(sizeof(char)*10);//alan ayrıldı, zorunda değiliz 
    strcpy(deneme, "Cuma");//deneme'ye Cuma atanması için strcpy kullanılabilir
    printf("Cuma haftanın %d. günüdür\n", cm);
    deneme = "Bu şekilde de atama yapılabilir";//Ayrılmış alan burda serbest bırakıldı çünkü sabit bir karakter dizisi atandı. Bu yüzden aşağıdaki free fonksiyonunda hata alırız
    printf("%s", deneme);
    //free(deneme);
    return 0;
}