/*
Burada Cpp'deki map'in bir uyarlamasını geerçekleştirmeye çalışacağım. mapler key-value olarak verilerin saklandığı yapılardır. bir key'den sadece bir tane bulunabilir
Yazacağımız birkaç önemli fonksiyonu aşağıdakilerdir.
-/ insert(): Bir anahtar-değer çiftini std::map içine ekler.
-/ erase(): Belirli bir anahtarın ilişkilendirilmiş değeriyle birlikte std::map içinden çıkarır.
-/ find(): Belirli bir anahtarın std::map içinde olup olmadığını kontrol eder. Varsa adresini geri döner yoksa NULL döndüreceğim
-/ empty(): std::map'in boş olup olmadığını kontrol eder.
Bunların dışında init, clear ve print gibi birkaç fonksiyonu da bu uygulamada işime yarayacağından yazacağım. Daha fazlası yazılabilir elbette ancak şimdilik uğraşmaya gerek duymuyorum.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Yapı içerisindeki veriyi farklı bir yapı içerisinde kullanma kararı aldım, bunun sayesinde yapı dizisi gibi kullanıp verileri bu şekilde tutacağım
typedef struct _VERI{
    int key;
    char value[50];
}VERI;
//yapının tanımı, boyutunu ve elemanları tutmam benim düşündüğüm mimaride yeterli
typedef struct _MAP{
    int size;
    VERI* data;
}MAP;
//map'i başlatıp yer ayırmaya başladık
void init(MAP* a){
    a->size = 0;
    a->data = (VERI*)malloc(sizeof(VERI)*a->size);
}
//Boş olup olmadığını döner
int empty(MAP* a){
    if(a->size == 0)
        return 1;
    return 0;
}
//map'e çift eklemek için bir fonksiyon
void insert(MAP* a, int key, char value[50]){
    if(empty(a)){//Eğer boşsa direkt geçir
        a->size++;
        a->data = (VERI*)realloc(a->data, sizeof(VERI)*a->size);
        a->data[0].key = key;
        strcpy(a->data[0].value, value);
        return;
    }
    for(int i = 0; i < a->size; i++){//Elemana sahip mi kontrolü
        if(a->data[i].key == key){
            printf("Bu anahtara sahip bir çift zaten bulunmakta..\n");
            return;
        }
    }
    //Tüm kontrollerden geçtiğine göre artık bellekte yer ayırıp yeni çifti ekleyebiliriz.
    a->size++;
    a->data = (VERI*)realloc(a->data, sizeof(VERI)*a->size);
    a->data[a->size-1].key = key;
    strcpy(a->data[a->size-1].value, value);
    return;
}
//map'ten çift çıkarmak için bir fonksiyon
void erase(MAP *a, int key){
    for(int i = 0; i < a->size; i++){//Elemana sahip mi kontrolü
        if(a->data[i].key == key){
            printf("Bu anahtara sahip bir çift bulundu ve silindi..\n");
            for(int x = i; x < a->size-1; x++){//bulunduğu yerden ilerisini geriye doğru kaydırmak lazım
                a->data[i].key = a->data[i+1].key;
                strcpy(a->data[i].value, a->data[i+1].value);
            }
            a->size--;
            a->data = (VERI*)realloc(a->data, sizeof(VERI)*a->size);
            return;
        }
    }
    printf("Böyle bir anahtara sahip çifi yok\n");
    return;
}
int* find(MAP* a, int key){
    for(int i = 0; i < a->size; i++){//Elemana sahip mi kontrolü
        if(a->data[i].key == key){
            return &a->data[i].key;
        }
    }
    return NULL;
}
void print(MAP* a){
    if(a->size == 0){
        printf("Boş bir map..\n");
    }
    for(int i = 0; i < a->size; i++){
        printf("Anahtar:%d Değer:%s\n", a->data[i].key, a->data[i].value);
    }
    return;
}
int main(void){
    MAP harita;
    init(&harita); //mapi başlattık

    //birkaç veri eklemesi
    insert(&harita, 1, "Bir");
    insert(&harita, 2, "İki");
    insert(&harita, 3, "Üç");

    //yazdırdık
    printf("Map:\n");
    print(&harita);

    //iki çifti silme komutu
    erase(&harita, 2);
    erase(&harita, 5);//bu anahtar olmadığından geri dönüş yapmalı

    //son halini yazdıralım ki doğru çalışmış mı görelim
    printf("Güncellenmiş Map:\n");
    print(&harita);

    //belirli bir anahtar var mı bakalım
    int arananAnahtar = 1;
    int* bulunanAnahtar = find(&harita, arananAnahtar);
    
    if (bulunanAnahtar != NULL) {
        printf("Anahtar %d bulundu.\n", *bulunanAnahtar);
    } else {
        printf("Anahtar %d bulunamadı.\n", arananAnahtar);
    }
    //2. örnekte bulmamayı bekliyoruz
    arananAnahtar = 4;
    bulunanAnahtar = find(&harita, arananAnahtar);
    
    if (bulunanAnahtar != NULL) {
        printf("Anahtar %d bulundu.\n", *bulunanAnahtar);
    } else {
        printf("Anahtar %d bulunamadı.\n", arananAnahtar);
    }
    
    //belleği geri verdim. clear yazmadığımdan direkt free'yi kullandım
    free(harita.data);
    return 0;
}