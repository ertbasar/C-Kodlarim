/*
INSAN yapısı içerisinde bir ADRBILGI isminde yapı göstericisi bildirilmiştir. Programcı ins değişkeni üzerinden ADRBILGI yapısına erişmek istediğinde ins.adrbilgi
içinde rastgele değerler vardır. Bunun için ya yerel bir yapı değişkeni tanımlanmalıdır -> ADRBILGI adres; ins.adrbilgi = &adres; veya dinamik bellek fonk.larla
ins.adrbilgi = (ADRBILGI*)malloc(sizeof(ADRBILGI)); ile, ancak burda da yapının adres elemanı da bir gösterici olduğundan onlara da yer tahsis etmek gereklidir.
Ona da ins.adrbilgi.adres=(char*)malloc(50); yapılır. Bu tahsisatlar yapıldıktan sonra ins ile diğer elemanlara erişimler yapılabilir. Benzer şekilde eğer
ins de bir gösterici olsaydı işlemlere onunla başlamak gerekirdi. Onu da xyz ile yapalım.
Benzer şekilde bir yapının elemanı fonksiyon göstericisi de olabilir.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Aynı zamanda iç içe yapılara da örnek olabilir.
typedef struct _ADRBILGI{
    char* adres;
    char telno[10];
} ADRBILGI;
typedef struct _INSAN{
    char ad_soyad[40];
    ADRBILGI *adrbilgi;
    void (*isimYazdır)(struct _INSAN);//içine bir adet 
} INSAN;
void printName(INSAN a){
    printf("%s", a.ad_soyad);
}
int main(void){
    //normal tanımlamalar
    INSAN ins;
    ins.adrbilgi = (ADRBILGI*)malloc(sizeof(ADRBILGI));//adrbilgi işaretçisi için yer ayrımı
    ins.adrbilgi->adres=(char*)malloc(50);//adrbilgi içindeki adres 
    strcpy(ins.ad_soyad, "Ertugrul\n");
    ins.isimYazdır = &printName;//Fonksiyon işaretçisine adres eşitlemesi
    ins.isimYazdır(ins);
    //işaretçi tanımlamaları
    INSAN *xyz;
    xyz = (INSAN*)malloc(sizeof(INSAN));//Bu sefer xyz'yi bir yere yerleştirerek başlamamız gerekti
    xyz->adrbilgi = (ADRBILGI*)malloc(sizeof(ADRBILGI));
    xyz->adrbilgi->adres= (char*)malloc(sizeof(30));
    strcpy(xyz->ad_soyad, "Alparslan");
    ins.isimYazdır(*xyz);//Bu sefer de xyzdeki ad soyad bilgisini yazdıracağız. fonksiyon ins'e ait olduğundan ve xyz bir işaretçi olduğundan böyle bir kullanım yapmak gerekti. Eğer sadece yazdırma değil de değer değişimlerinin de olduğu bir işlem olsaydı zaten fonksiyona işaretçi olarak alırdık ve gönderimleri de öyle yapardık.
    free(ins.adrbilgi->adres);
    free(ins.adrbilgi);
    free(xyz->adrbilgi->adres);
    free(xyz->adrbilgi);
    free(xyz);
    printf("\n");
    return 0;
}