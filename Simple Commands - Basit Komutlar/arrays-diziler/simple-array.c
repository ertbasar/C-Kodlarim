/*
Bu dosyada birkaç adet basit dizi işlemi gerçekleştireceğim. Diziler aynı değişken altında belirlenen miktarda değişkenin
saklanmasını sağlarlar. Bir listeye benzedikleri söylenebilir ve farklı birkaç şekilde tanımlamaları yapılabilir.
Diziler aynı zamanda gösterici yani pointer özelliğe de sahiptir ve bu şekilde de erişebiliriz.
*/
#include <stdio.h>

int main(void){
int a[10] = {1,5,3,12,12,34,45,321,43423424,3};
int *b;

//Dizi elemanlarını indislerine göre sırayla yazdırmaca. Dizinin boyutu / dizideki bir elemanın boyutu işlemiyle dizideki karakter sayısı kadar döngüyü ayarladık
for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
    printf("%d\n", a[i]);
}
//Burada da b göstericisine a dizisini atadık ve benzer şekilde yazdırma işlemleri yaptık
printf("Bu sefer işaretçi üzerinden yazdıracağım");
b = a;
for(;b != (a + sizeof(a)/sizeof(a[0])) ; b++){
    printf("%d\n", *b);
}
// Dizi elemanlarının adreslerini yazdırma
printf("Bu dizi elemanlarının adreslerini yazdıracağım\n");
b = a;
for(;b != (a + sizeof(a)/sizeof(a[0])) ; b++){
    printf("%p\n", b);
}
//Çok boyutu dizilerde de benzeri işlemler gerçekleştirilebilir. Burada işlemler biraz daha farklı çünkü c çok boyutlu olduğundan dolayı farklı bir aritmetiğe sahiptir.
printf("Bu sefer çoklu dizinin elemanlarını yazdıracağım\n");
int c[3][2] = {1,2,3,4,5,6};
b = &c[0][0];// tanımlarken direkt c yerine c 0a 0ın adresini vermemiz gerekti. bu çok boyutlu olmasından ötürü. aşağıda da benzer bir kullanım bulunmakta.
for(;b != (&c[0][0] + sizeof(c)/sizeof(c[0][0])) ; b++){
    printf("%d\n", *b);
}

return 0;
}