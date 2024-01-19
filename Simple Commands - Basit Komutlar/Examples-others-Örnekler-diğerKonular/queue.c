/*
Cpp STL kütüphanesinde bulunan queue'nun (kuyruk) C'ye uyarlamasını yapmaya çalışacağım. Kuyruk, genellikle bir koleksiyonun sonuna eleman eklemek (enqueue) ve 
koleksiyonun başından eleman çıkarmak (dequeue) için kullanılır.
Kuyruğun bizim burada fonksiyonda yazacağımız temel özellikleri şunlardır:
Enqueue (Ekleme): Kuyruğun sonuna yeni bir eleman ekler.
Dequeue (Çıkarma): Kuyruğun başındaki elemanı çıkarır.
Front: Kuyruğun başındaki elemanı gösterir.
Back: Kuyruğun sonundaki elemanı gösterir.
Empty (Boş mu?): Kuyruğun boş olup olmadığını kontrol eder.
Size (Boyut): Kuyruktaki eleman sayısını verir.
Bunların dışında init ve free versiyonlarını da dışarıdan olacak şekilde yapacağım ki bellekte yer ayrımını gerçekleştirelim. Son olarak da yazdırmak adına print fonksiyonu yazacağım.
*/
#include <stdio.h>
#include <stdlib.h>
//Normal queue elemanları
typedef struct _QUEUE{
    int *data;// Array gibi tutmayı tercih ettim
    int capacity;
}QUEUE;
//kapasitesi 0 başlasın diye init edildi
void initQueue(QUEUE *a){
    a->capacity = 0;
}
//Belleğe geri iade ederken
void freeQueue(QUEUE *a){
    free(a->data);
    a->capacity = 0;
}
//boş mu sorusuna cevap verildi
int empty(QUEUE *a){
    if(a->capacity==0)
        return 1;
    else
        return 0;
}
//eleman eklemesi yapmak için
void enqueue(QUEUE *a, int b){
    a->capacity++;//kapasite arttırıldı
    if(a->capacity == 1)//eğer ilk elemansa malloc ile yer tahsis edildi
        a->data = (int*)malloc(sizeof(int));
    else//değilse uygun miktarda bölge tahsis edildi
        a->data = realloc(a->data, sizeof(int)*a->capacity);
    a->data[a->capacity-1] = b;//yeni gelen eleman yerine koyuldu
}
//elemanı baştan çıkarmak için
void dequeue(QUEUE *a){
    if(a->capacity==0)
        printf("Zaten boş bir queue\n");
    else{
        for(int i = 0; i < a->capacity-1; i++)//2. 1.ye 3. 2.ye ... olacak şekilde her bir eleman bir öne kaydırıldı
            a->data[i]=a->data[i+1];
        a->data[a->capacity-1]=0;
        a->capacity--;
        if(a->capacity==0)//eğer artık boşsa geri sisteme verelim
            free(a->data);
        else
            a->data = realloc(a->data, sizeof(int)*a->capacity);//değilse realloc edelim
    }
    
}
//öndeki eleman verildi
int front(QUEUE *a){
    if(!empty(a))
        return a->data[0];
    else
        printf("Zaten boş bir queue\n");
        return -1;
}
//en arkadaki eleman verildi
int back(QUEUE *a){
    if(!empty(a))
        return a->data[a->capacity-1];
    else
        printf("Zaten boş bir queue\n");
        return -1;
}
//size için bir fonksiyon yazıldı
int size(QUEUE *a){
    return a->capacity;
}
//elemanları baştan sona yazmak için yazdım
void print(QUEUE *a){
    for(int i = 0; i < a->capacity; i++)
        printf("%d\n", a->data[i]);
}

int main(void){
    QUEUE x;//queue değişkeni tanımladım
    initQueue(&x);
    printf("Boşsa 1 döner:%d\n", empty(&x));//boş oluğ olmadığını kontrol ettim
    enqueue(&x, 5);
    enqueue(&x, 7);
    enqueue(&x, 345);
    dequeue(&x);
    enqueue(&x, 30);
    printf("Boyut:%d Front:%d Back:%d\n", size(&x), front(&x), back(&x));//queue'deki durumu kontrol ettim
    print(&x);
    enqueue(&x, 23);
    enqueue(&x, 34);
    enqueue(&x, 6);
    dequeue(&x);
    printf("Boyut:%d Front:%d Back:%d\n", size(&x), front(&x), back(&x));
    print(&x);
    freeQueue(&x);//sisteme belleği geri verdim
    return 0;
}