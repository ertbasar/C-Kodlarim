/* 
0x16d7d3008, 0x16ceab008, 0x16d3d3008 address.c kodu çalıştırılınca çıktıda gelen adresler. Bu çalışmada kullanılabilir 
diye düşünüyorum, göreceğiz.
Göstericiler, adres bilgilerini saklamak ve adreslerle ilgili işlemler yapmak için kullanılan nesnelerdir. İçerilerinde adres
değerleri bulunur ve bildirimleri <tür> * <gösterici ismi> şeklinde olur örneğin char *s gibi. Bu bildirimden derleyici s'in
bir gösterici olduğunu ve gösterdiği yerin char olarak yorumlanacağını gösterir.
char *s = (char*)0x16ceab008; *s = 'a'; ile belirtilen yere de a karakterini yerleştirir. (Bellege erisilebilen uygulamalarda)
* operatörü aynı zamanda dizi isimleriyle birlikte de kullanılabilir, aynı zamanda adres sabitleriyle de kullanılabilir (
char*)0x16ceab008 = 'a' gibi. * içerik operatörü & adres operatörü denebilir. Pointerlar fonksiyonlarda da call by refernece 
kullanımında da fazlasıyla kullanılırlar. void sample(int *p) ile tanım yapılıp, sample(&x) ile de çağrılması yapılabilir. 
Burada diziler de gönderilip fonksiyonda kullanılabilir.
*/
#include <stdio.h>
#include <stdlib.h>
int print_dizi_return_last(int*, int);
int main(void){
    //basit bir pointer kullanımı
    int *a;
    int deneme = 5;
    a = &deneme;//denemenin adresini a'ya attık ki * kullanınca o adresi göstersin
    *a = 15;
    printf("%d\n", deneme);
    //fonksiyona array göndermeyle alakalı basit bir örnek
    int array[9] = {1,2,3,4,5,6,7,8,9};
    print_dizi_return_last(array, sizeof(array)/sizeof(array[0]));
    return 0;
}
int print_dizi_return_last(int *dizi, int boyut){
    for(int i = 0; i < boyut;i++){
        printf("%d\n", dizi[i]);
    }
    return dizi[boyut-1];
}






