/*
Cpp'deki list yapısının bir benzerini yazmaya çalışacağım. Bu listelerde her eleman kendinden önce ve sonraki 
elemanları işaret eden iki adet bağlantıya sahiptir. Bu elemanlara aslına bakarsak node da denebilir. İlk önce
bu nodeları tasarlayacağız sonrasında da bunların üzerinden bazı verileri değiştireceğiz. 
-/ push_back(): Listenin sonuna eleman ekler.
-/ push_front(): Listenin başına eleman ekler.
-/ pop_back(): Listenin sonundaki elemanı kaldırır.
-/ pop_front(): Listenin başındaki elemanı kaldırır.
-/ size(): Listenin içindeki eleman sayısını döndürür.
-/ empty(): Listenin boş olup olmadığını kontrol eder.
-/ clear(): Listenin içindeki tüm elemanları kaldırır.
Burada genel node tanımı yapıldıktan sonra liste başlangıcı ayarlanacak, sonrasında da önceki sonrakilere erişimlerle alakalı işlemler yapılacak. Burdan sonra da 
önden ve sondan eklemeler, çıkarımlarla alakalı işlemler yapılacak. Son olarak da print fonksiyonunu ekleyeceğim ve bu çalışmayı sonlandıracağım
*/
/*
Bilgisayarda NULL pointer işlemleri pek istediğim gibi gitmediğinden genel olarak bir şeyi kontrol ederken == NULL gibi şeyleri daha seyrek bir şekilde kullanmaya çalıştım. 
Bu yüzden bazı yerler daha pratik şekilde yazılabilirdi.
*/

#include <stdio.h>
#include <stdlib.h>
//Bir düğümün tanımı, kendi değeri ve önceki ile sonraki düğümlerin adreslerini tutar
typedef struct _NODE{
    int data;
    struct _NODE *next;
    struct _NODE *before;
}NODE;
//Bir listenin başını ve sonunu bilmemiz yeterlidir. 
typedef struct _LIST{
    NODE *head;
    NODE *tail;
}LIST;
//Yeni bir liste oluşturma (bu kodda kullanmadım)
NODE* init(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));//Node miktarınca 
    newNode->data = data;
    newNode->next=NULL;
    newNode->before=NULL;
    return newNode;
}
//Listeye yeni bir eleman ekleme (arkasına)
void push_back(LIST* a, int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));//Yeni bir node oluşturuldu
    newNode->data = data;//Bu node'a veri atandı
    newNode->next = NULL;
    if(a->head == NULL){//Eğer node şimdiye kadar boş ise ona göre atamalar yapıldı
        a->head = newNode;//Kuyruk da baş da yeni oluşturduğumuz nodelar oldular
        a->tail = newNode;
        return;
    }
    else{//dolu node için atamalar yapıldı
        newNode->before=a->tail;//eski kuyruk, yeni node'un before'u oldu
        a->tail->next=newNode;//yeni kuyruk eski kuyrugun next'ine eklendi
        a->tail = newNode;//yeni kuyruk kuyruğa atandı
        return;
    }
}
//Listeye yeni bir eleman ekleme (önüne), yukarıdaki işlemlerin benzeri öne eklemek için yapıldı
void push_front(LIST* a, int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->before = NULL;
    if(a->head == NULL){
        a->head = newNode;
        a->tail = newNode;
        return;
    }
    else{
        newNode->next = a->head;
        newNode->before = NULL;
        a->head = newNode;
        return;
    }
}
//Arkadan eleman çıkarma
void pop_back(LIST *a){
    if(a->head==NULL){
        printf("Zaten boş bir liste\n");
        return;
    }
    else{
        if(a->head==a->tail){//eğer tek elemanlıysa ona göre NULL atamaları yapıldı
            a->head = NULL;
            a->tail = NULL;
        }
        else{
            a->tail = a->tail->before;//kuyruk bi önceki node'a alındı
            a->tail->next=NULL;//yeni kuyruğun gösterdiği yer temizlendi
        }
    } 
}
//Önden eleman çıkarma, yukarıdakinin benzeri
void pop_front(LIST *a){
    if(a->head==NULL){
        printf("Zaten boş bir liste\n");
        return;
    }
    else{
        if(a->head == a->tail){
            a->head = NULL;
            a->tail = NULL;
        }
        else{
            a->head = a->head->next;
            a->head->before = NULL;
        }
    } 
}
//Listenin boyutunu hesaplama
int size(LIST* a){
    int boyut = 0;
    NODE *newNode = a->head;//sayımı yapacağımız node tanımlandı
    if(a->head == NULL)
        return 0;
    else{
        while(newNode!=a->tail->next){//tail'in next'ini gösterene kadar boyut değişkeni bir arttırıldı
            boyut++;
            newNode=newNode->next;
        }
    }
    return boyut;
}
//Listenin elemanlarını baştan sona yazdırma
void print(LIST* a){
    NODE* newNode = a->head;
    if(a->head == NULL)
        printf("Boş bir liste..\n");
    else{
        while(newNode!=NULL){//tail'in next'ini gösterene kadar yazırıldı
            printf("%d\n", newNode->data);
            newNode=newNode->next;
        }
    }
    return ;
}
//Liste boş mu onu döner
int empty(LIST* a){
    if(a->head==NULL)
        return 1;
    else
        return 0;
}
//Listeyi boşaltan komut
void clear(LIST *a){
    NODE *newNode = a->head;//işlemlerin yapılacağı node tanımlandı
    while(newNode!=NULL){//Burada sırayla elemanların içleri ve gösterdikleri boşaltıldı veya NULL atandı
        NODE* temp = newNode->next;
        newNode->data = 0;
        free(newNode->next);
        newNode = temp;
    }
    a->head = NULL;//son olarak a'nın işaretçi elemanları NULL yapıldı
    a->tail = NULL;
    return;
}

int main(void){
    LIST liste;
    liste.head = NULL;
    liste.tail = NULL;
    printf("Liste: ");
    print(&liste);
    //Eleman ekleme 
    push_back(&liste, 1);
    push_back(&liste, 2);
    push_back(&liste, 3);
    push_back(&liste, 4);

    printf("Liste: ");
    print(&liste);

    //Önden ve arkadan eleman çıkarma 
    pop_front(&liste);
    pop_back(&liste);

    printf("Liste (önden ve arkadan eleman çıkarıldı): ");
    print(&liste);

    //Listede kaç eleman olduğunu kontrol
    printf("Liste boyutu: %d\n", size(&liste));

    //Liste boş mu
    if (empty(&liste)) {
        printf("Liste boş.\n");
    } else {
        printf("Liste boş değil.\n");
    }
    // Liste temizleme
    clear(&liste);

    printf("Liste temizlendi. Liste: ");
    print(&liste); //Boş olmalı
    return 0;
}