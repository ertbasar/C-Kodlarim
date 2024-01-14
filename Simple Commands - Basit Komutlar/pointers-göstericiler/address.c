/*
Yazılımsal olarak bir adresin iki adet bileşeni vardır, bunlar sayısal bir değer ve türdür. Adres yalnız başına bir anlam
taşımaz. Adres sabitleri, tamsayı türlerindeki sabitler üzerinde bilinçli tür dönüşümü yapılara elde edilirler.
(<tür>*)<tamsayı sabiti> olarak tanımlanabilir. Burada belleği iyi bilmek önemli bir kod yazarsam sorun çıkabilir.
Bu kısmı sadece notlarımı almak için kullandım. Aşağıda basit bir örnek yazayım bari :)
*/
#include <stdio.h>
int main(void){
    int a = 5;
    printf("%p", &a);//adresi yazdırdım
    printf("\n");
    return 0;
}