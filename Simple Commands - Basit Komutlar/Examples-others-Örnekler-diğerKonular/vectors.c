/*
Cpp STL kütüphanesinde bulunan vektörlerin bir C uyarlamasını yazmaya çalışacağım. Buradaki vektörü bir yapı olarak oluşturacağız ve bilgilerin olduğu ve kapasitesinin
olduğu iki tane değişkeni olacak. Sonrasında bu vektörü tanımlamak ve bellekte yer ayırmakla ilgili birkaç fonksiyona ihtiyacımız olacak. Bundan sonrasında da vektöre
eleman ekleme yaptığımız ve vektörü yazdırdığımız iki farklı fonksiyonu tanımlayacağız. Son olarak da vektöre ayırdığımız belleği sisteme geri vereceğiz.
*/
#include <stdio.h>
#include <stdlib.h>
//vektörün tanımlanması
typedef struct _VECTOR{
    int* data;
    int size;
    int capacity;
}VECTOR;
//vektör için başlangıçta yer ayrımı yapan fonsiyon. Bu örnekte vektör tanımlandığında 0 veriyle ve 4 kapasiteyle başlıyor olarak düşüneceğiz. 
void initVector(VECTOR *a){
    a->size = 0;
    a->capacity = 4;
    a->data = (int*)malloc(sizeof(int)*a->capacity);//eğer size ile capacity eşitse capacitye ekleme yapılır
    if (a->data == NULL) {
        printf("Bellek tahsis hatasi\n");
        exit(EXIT_FAILURE);
    }
}
//vektöre yeni eleman eklenmesi yapılması, gerekirse kapasite arttırımı yapılıyor
void pushVector(VECTOR *a, int input){
    if(a->capacity == a->size){
        a->capacity = a->capacity * 2;
        a->data = (int*)realloc(a->data, sizeof(int)*a->capacity);
        }
    a->data[a->size] = input;
    a->size++;

}
//vektöre tahsis edilen belleğin sisteme geri verilmesi
void freeVector(VECTOR *a){
    free(a->data);
    a->capacity = 0;
    a->size = 0;
}
//vektörün elemanlarını yazdıran fonksiyon
void printVector(VECTOR a){
    for(int i = 0; i < a.size; i++)
        printf("%d\n", a.data[i]);
}
int main(void){
    VECTOR vektor;// vektör değişkeni tanımladık
    initVector(&vektor);// vektör ve işaretçi değişkeni için bellekten alan tahsis ettik, başlangıç değerlerini verdik
    pushVector(&vektor, 5);// vektöre eleman eklemesi yaptık
    pushVector(&vektor, 212);
    pushVector(&vektor, 815);
    pushVector(&vektor, 459);
    pushVector(&vektor, 145);
    pushVector(&vektor, 682);
    printf("%zu şu anki kullanılan bellek miktarı\n",sizeof(vektor.data)*vektor.capacity);
    printf("Elemanlar:\n");
    printVector(vektor);//vektör elemanlarını yazdırdık
    freeVector(&vektor);//vektöre tahsis ettiğimiz alanı geri sisteme verdik
    return 0;
}

