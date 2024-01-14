/*
Bu dosyada belirleyicilerle alakalı birkaç satır kod yazacağım.
Belirleyiciler genel olarak değişkenlerin ne kadar süreyle ve nerede tutulacağını ve değeriyle 
alakalı biglileri tanımlamak için kullanılır. Kısaca tanımlamaları yapmak gerekirse:
-auto: nesnenin faaliyet alanı bitince kaybolur
-register: bellekte değil de CPU yazmaçlarında tutulacağını belirtir
-static: programın çalışma süresince bellekten kaybolmazlar, autonun zıttıdır
-extern: nesnenin başka bir modül içerisinde olduğunu belirtmek için kullanılır

-const: ilk değer atandıktan sonra değişkenin değerinin değiştirilemeyeceğini belirtir
-volatile: değişkenlerin optimizasyon amacıyla yazmaçta bekletilmemesi gerektiğinde kullanılır
*/
#include <stdio.h>
#include <stdlib.h>
int main(void){
auto const int a = 5; // Yerelde işi bitince belleğe geri salınacak ve de değeri değiştirilemez
extern char b;// başka bir dosyadan alınacak gibi olur, bu yüzden derlerken hata vermez. Bunun bir örneğini önişlemcilerde yapacaağız
register float c = 1024;// CPU yazmaçlarında tutulacak
static int d = 23;// programın çalışma süresince bellekte tutulacak, global değişkene benzer ama farkı yerelde tanınmasıdır
int *deneme1, *deneme2;
//şimdi  bir örnek yapalım, bu örnekte parantez bloğu açıp yenip değişkenler tanımlayalım ve adreslerini 
//bir yerde tutup sonrasında oradaki verileri yazdıralım. 1. Örnek
{
    auto int *x;// değişkenlerin tanımlanması, yer ayrılması ve de değerlerin verilmesi. Yer ayrılması burada zorunlu. Yoksa aşağıda vereceğim ikinci örnek gibi yazılması gerekir
    static int *y;
    x = malloc(sizeof(int));
    y = malloc(sizeof(int));
    *x = 5;
    *y = 15;
    printf("%p \n", x);// değişkenlerin adreslerinin yazdırılması ve sonrasında önceden belirlenmiş pointerlara atanması
    printf("%p \n", y);
    deneme1 = x;
    deneme2 = y;
}
printf("%d\n", *deneme1);//dışarda da aynı verilere erişilip erişilmediğinin incelendiği kısım. ikisi de tanımladığım şekilde geldi ancak auto olanda başka bir işlemde aynı şekilde veri gelmeyebilir, oraya başka bir veri yazılmış olabilirdi
printf("%d\n", *deneme2);
//2. Örnek
{
    static int y_value = 10;
    deneme2 = &y_value; // Önceden tanımlanan pointer'a yeni bir bellek adresi atayabilirsiniz
}
    // Blok dışında da kullanılabilir
printf("%d", *deneme2);
//çalıştırılınca görüldüğü üzere static olduğu zaman belirli bir adresteki veri eğer değiştirlmediyse ve static ise aynı değerde devam eder. ancak auto ise veya değiştirildiyse buradaki değişkenin değeri bu bloğun dışında aynı şekilde görülmeyebilir.
printf("\n\n");
return 0;

}