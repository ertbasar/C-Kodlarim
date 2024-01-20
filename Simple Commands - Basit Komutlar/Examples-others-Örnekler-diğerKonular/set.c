/*
Cpp'deki STL kütüphanesinde bulunan set'in bir uyarlamasını yazmaya çalışacağım. set, sıralı ve tekrar etmeyen elemanlardan oluşan bir küme olarak tanımlanabilir.
Genel olarak temel olan ve benim yazacağım fonksiyonları şunlardır.
-/ insert(): Bir elemanı kümeye ekler.
-/ erase(): Belirli bir elemanı kümeden çıkarır.
-/ find(): Belirli bir elemanın kümede olup olmadığını kontrol eder. Varsa olan elemanın adresini döner yoksa da end()'i gönderir ama burda yapmıcam.
-/ size(): Kümedeki eleman sayısını döndürür.
-/ empty(): Kümenin boş olup olmadığını kontrol eder.
Bunların dışında ben de init ve print fonksiyonları yazacağım
*/

#include <stdio.h>
#include <stdlib.h>
//normal set elemanları
typedef struct _SET{
    int *data;
    int size;
}SET;
//set için başlangıç yapıldı, yer ayrımı ve boyutun başta 0'a eşitlenmesi
void init(SET* a){
    a->size = 0;
    a->data = (int*)malloc(sizeof(int)*a->size);//sonradan realloc olarak kullanmak için malloc kullandım ancak 0 integerlik yer ayırdım
}
//kümenin içine eleman eklemek için fonksiyon
void insert(SET *a, int number){
    for(int kopya = 0; kopya <  a->size ; kopya++){//Kopya mı onun kontrolü
        if(a->data[kopya] == number){
            printf("Bu eleman zaten kümede bulunmakta\n");
            return;
        }
    }
    if(a->size == 0 || number<a->data[0]){//Eğer ilk veya en küçük elemansa direkt başa yerleştirelim
        a->size++;
        a->data = (int*)realloc(a->data, sizeof(int)*a->size); 
        for (int i = a->size - 1; i > 0; i--) {
            a->data[i] = a->data[i - 1];
        }
        a->data[0] = number;
        return;
    }
    if(number>a->data[a->size-1]){//Eğer direkt en büyük olarak geliyorsa yerleştirelim
        a->size++;
        a->data = (int*)realloc(a->data, sizeof(int)*a->size);
        a->data[a->size-1]=number;
        return;
    }
    //Tüm kontrollerden geçtiyse bellekte yer ayrıp ona göre yerine atamasını yapabiliriz
    int yer = 0;
    while (yer < a->size && number > a->data[yer]) {
        yer++;
    }
    //yerleşeceği yerden itibaren tüm elemanları birer kaydır
    a->size++;
    a->data = (int *)realloc(a->data, sizeof(int) * a->size);
    for (int kaydir = a->size - 1; kaydir > yer; kaydir--) {
        a->data[kaydir] = a->data[kaydir - 1];
    }
    a->data[yer] = number;
    return;
}
//kümenin içindeki elemanı çıkartmak için fonksiyon
void erase(SET *a, int number){
    int i = 0;
    while(i<a->size){
        if(a->data[i]==number){//sayıyı bulmaya çalışıyoruz
            for(int x = i; x < a->size-1; x++){//sayının olduğu yeri bulduktan sonra sonraki elemanları birer geriye alıyoruz
                a->data[x] = a->data[x+1];
            }
            a->size--;
            a->data = (int*)realloc(a->data, sizeof(int)*a->size);//size daraltılması
            return;
        }
        i++;
    }
    printf("Kümede böyle bir sayı yok\n");
}
//küme içinde verilen elemanın bulunup bulunmadığını döndürür, varsa adresini döner
int* find(SET *a, int number){
    for(int i = 0; i < a->size; i++){//yerini arıyoruz
        if(a->data[i]==number)
            return &a->data[i];//varsa adresini döndük
    }
    return NULL;//yoksa NULL döndürdüm
}
//kümenin boyutunu döndürür
int size(SET *a){
    return a->size;
}
//küme boşsa 1 yoksa 0 döndürür
int empty(SET *a){
    if(a->size==0)
        return 1;
    return 0;
}
void print(SET *a){
    for(int i = 0; i < a->size; i++){
        printf("%d\n", a->data[i]);
    }
}
int main(void){
    SET deneme;
    init(&deneme);

    // Eleman eklemeleri
    insert(&deneme, 7);
    insert(&deneme, 4);
    insert(&deneme, 12);
    insert(&deneme, 23);
    insert(&deneme, 9);
    insert(&deneme, 15);
    // Kümeyi yazdırma
    printf("Küme elemanları:\n");
    print(&deneme);

    // Eleman silme
    erase(&deneme, 4);

    // Silme sonrası küme
    printf("\nKüme elemanları (4 silindikten sonra):\n");
    print(&deneme);

    // Eleman kümede var mı
    int search_number = 12;
    int* found = find(&deneme, search_number);
    if (found != NULL) {
        printf("\n%d kümede bulunuyor. Adres: %p\n", search_number, (void*)found);
    } else {
        printf("\n%d kümede bulunmuyor.\n", search_number);
    }
    //2. bir kontrol
    search_number = 355;
    int* found2 = find(&deneme, search_number);
    if (found2 != NULL) {
        printf("\n%d kümede bulunuyor. Adres: %p\n", search_number, (void*)found2);
    } else {
        printf("\n%d kümede bulunmuyor.\n", search_number);
    }

    // Kümenin boyutu ve boş olup olmadığı
    printf("\nKüme boyutu: %d\n", size(&deneme));
    if (empty(&deneme)) {
        printf("Küme boş.\n");
    } else {
        printf("Küme dolu.\n");
    }

    return 0;
}