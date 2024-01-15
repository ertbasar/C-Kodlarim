/*
Normal değişkenlerde olduğu gibi göstericilerde de belirleyiciler bulunmaktadır. Zaten genel olarak kullanımları benzer olsa da
kullanımı karmaşık olan sadece const belirleyicisi var diyebiliriz çünkü kullanım yeri işleri biraz değiştirebilir.
1- Gösterdikleri yer sabit göstericiler: conts <tür>*<gösterici ismi> ile göstericinin gösterdiği değer ilk başta verildikten 
sonra bir daha  değiştirilemez, ancak gösterici değiştirilebilir. Genelde fonksiyon parametresi olarak karşımıza çıkarlar.
Yani p = s; yapılabilir ancak p[n] = 'a' gibi bir atama yapılamaz.
2- Kendisi sabit olan göstericiler: <tür>* const <gösterici ismi> şeklinde göstericinin gösterdiği değiştirilebilir ancak
gösterdiği yer değiştirilemez. Yani *p veya p[n] değiştirilebilir ancak p = y; gibi bir atama yapılamaz. Burada malloc kullanımı
yapmak nereyi göstereceğini belirtme adına kullanılmalıdır.
3- Hem kendisi hem de gösterdiği yer sabit olan göstericiler: const <tür>* const <gösterici ismi> şeklinde tam bir koruma
sağlamak amacıyla ilkdeğer verilerek kullanılırlar. Genelde parametre değişkeni olarak karşımıza çıkar.
Not: Ayrıca göstericilere de ilkdeğer verilebilir. Örnek olarak char s[20]; char* t = s; 
int *p = (int*)0x1FC0; gibi. Verilen değer göstericinin içerisine yazılır, gösterdiği yere değil.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    //1'e örnek
    const char* deneme1;
    char deneme_1[] = "Deneme";
    deneme1 = deneme_1;
    //deneme1[2] = 'c';//hata verir
    //2'ye örnek
    char* const deneme2 = malloc(sizeof(char));// yer ayırmak gerekti, bunu ileride dinamik bellek yönetiminde inceleyeceğiz.
    *deneme2 = 'p';
    free(deneme2);//ayırdığımız yeri geri verdik
    //deneme2 = deneme_1;//hata verir
    const char* const deneme3 = "p";
    //deneme3 = deneme_1;//hata verir
    //*deneme3 = 'p';//hata verir
    return 0;
}