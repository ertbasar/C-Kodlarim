//Standart kütüphanelerin eklenmesi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Burada kendi yapı ve fonksiyonlarım başlıyor. Sırayla hepsinde neler yaptığımı da anlatacağım.
//İlk önce map yapısını geçireceğim
typedef struct _VERI{
    int key;
    char value[50];
}VERI;
//yapının tanımı, boyutunu ve elemanları tutmam benim düşündüğüm mimaride yeterli
typedef struct _MAP{
    int size;
    VERI data;
}MAP;
//Müşteri bilgilerinin olduğu yapı
typedef struct _MUSTERI
{   MAP* kullanici;
    char** adSoyad;
    int* bakiye;
    int size;
}MUSTERI;
//Müşteri yapısını başlatıp yer ayırmaya başladık, bir dahakinde realloc yapabiliriz
void initUsers(MUSTERI *a){
    a->size = 0; 
    a->adSoyad = NULL;
    a->bakiye = NULL;
    a->kullanici = NULL;
}

//map'e çift eklemek için bir fonksiyon
void addUser(MUSTERI* a, int key, char value[50], char adSoyad[31]){
    for(int i = 0; i < a->size; i++){//Müşterinin bulunu bulunmadığını kontrol ettik
        if(a->kullanici[i].data.key == key){
            printf("Kullanıcı zaten bankamızda bulunmakta");
            return;
        }
    }
    //Eğer kullanıcı yoksa yerler ayrılıyor
    a->size++;
    a->adSoyad = (char**)realloc(a->adSoyad, a->size * sizeof(char*));
    a->adSoyad[a->size - 1] = (char*)malloc(strlen(adSoyad) + 1);
    a->bakiye = (int*)realloc(a->bakiye, sizeof(int)*a->size);
    a->kullanici = (MAP*)realloc(a->kullanici, sizeof(MAP)*a->size);
    //Atamaların yapılması
    a->kullanici[a->size-1].data.key = key;//TC ataması
    strcpy(a->kullanici[a->size-1].data.value, value);//Şifre ataması
    strcpy(a->adSoyad[a->size-1], adSoyad);//Ad soyad ataması
}

//Kullanıcının olup olmadığını arayan fonksiyon
int findUser(MUSTERI* a, int key, char value[50]){
    for(int i = 0; i < a->size; i++){
        if(a->kullanici[i].data.key == key){
            if(strcmp(a->kullanici[i].data.value, value) == 0)
                return i;
            else
                return -1;
        }
    }
    return -1;
}

//Giriş yapmış müşterinin yapacağı işlemlerin gerçekleştirileceği fonksiyon, bu modları da ayrı fonksiyonlar olarak yazabilirdik ancak uğraşmadım
void modSelect(MUSTERI *a, int i){
    int mod;
mod:
    printf("Lütfen yapmak istediğiniz işlemi seçiniz:\n1-> Bakiye Görüntüleme\n2-> Para Yatırma\n3-> Para Çekme\n4-> Çıkış\n");
    scanf("%d", &mod);
    system("clear");
    if(mod == 1){//Bakiye görüntüleme
        printf("Bankadaki bakinyeniz: %dTL\n", a->bakiye[i]);
    }
    else if(mod == 2){//Para yatırma
        int miktar;
        printf("Ne kadar miktarda para yatırmak istiyorsunuz:");
        scanf("%d",&miktar);
        a->bakiye[i] = a->bakiye[i] + miktar;
        system("clear");
        printf("Paranızı bankamıza yatırdığınız için teşekkürler. Bakiyeniz:%d\n", a->bakiye[i]);
    }
    else if(mod==3){//Para çekimi, eğer bakiyeden fazla bir miktar çekilmek istenirse ana menüye döndürür
        int miktar;
        printf("Ne kadar miktarda para çekmek istiyorsunuz:");
        scanf("%d",&miktar);
        if(miktar > a->bakiye[i]){
            system("clear");
            printf("Bu miktar bakiyenizde bulunmamakta. Ana menüye yönlendiriliyorsunuz..\n");
            goto mod;
        }
        a->bakiye[i] = a->bakiye[i] - miktar;
        system("clear");
        printf("Paranızı bankamızda tuttuğunuz için teşekkürler. Kalan bakiyeniz:%d\n", a->bakiye[i]);
    }
    else if(mod == 4)
        return;
    printf("Başka bir işlem yapmak istiyor musunuz?\n1-> Evet \n2-> Hayır\n");
    int soru;
    scanf("%d", &soru);
    system("clear");
    if(soru == 1)
        goto mod;
    return;
}
//Kayıt olacak müşterinin kayıt sürecinin gerçekleştirildiği fonksiyon
void registerUser(MUSTERI *a){
    printf("Bankamıza yeniden hoşgeldiniz, şimdi kaydınızı yapmak için size birkaç soru soracağım.\n");
    printf("Lütfen TC numaranızı giriniz: ");
    int tc;
    scanf("%d", &tc);
    char sifre[50];
    printf("Lütfen şifrenizi giriniz: ");
    scanf("%s", sifre);
    char adSoyad[31];
    printf("Lütfen adınızı ve soyadınızı giriniz: ");
    getchar(); //önceki scanf'ten kalan enter'ı temizleme
    fgets(adSoyad, sizeof(adSoyad), stdin);
    //fgets sonunda oluşan newline karakterini temizle
    adSoyad[strcspn(adSoyad, "\n")] = '\0';
    addUser(a, tc, sifre, adSoyad);
}