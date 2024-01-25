/*
Bu örnekte bir banka sistemi örneği yapmaya çalışacağım. Başlangıçta bankada hiç kullanıcı olmayacak, biz ekleyeceğiz. Bu eklediğimiz kullanıcı, tc ve şifre, ad soyad
ve bankaya yatırılan para özelliklerine sahip olacak. Sonrasında da ATM'den para ekleme veya çekme özelliklerine sahip olacak.
Bu uygulama ayrca modüler yapıda tasarlanacak ve header dosyasında gerekli önişlemciler bulunacak. Ayrıca her zaman doğru giriş yapılmasa da genelde doğru giriş
yapıldığını varsaydım. Hatalarla çok uğraşmadım.
*/ 
#include "header.h"

int main() {
    MUSTERI mus;
    initUsers(&mus);
    int islem = 0;
    int tc, indis;
    char sifre[50];
    while(1){
        islem = 0;
        system("clear");
        printf("Merhabalar, bankamıza hoşgeldiniz, lütfen yapmak istediğiniz işlemi seçiniz:\n");
        printf("1 -> Giriş \n2 -> Kayıt\n");
        scanf("%d", &islem);
        if(islem == 1){//Giriş yapılacak
            system("clear");
            printf("Giriş yapmak istediğinizi belirttiniz.\nLütfen TC'nizi giriniz:");
            scanf("%d",&tc);
            printf("Lütfen şifrenizi giriniz: ");
            scanf("%s", sifre);
            system("clear");
            indis = findUser(&mus, tc, sifre);//Yanlış girişler veya hangi indise sahip olan kullanıcı olduğu
            if(indis == -1){
                printf("Kullanıcı bulunamadı, ana ekrana yönlendiriliyorsunuz.");
            }
            printf("Bankamıza hosgeldiniz sayın %s\n", mus.adSoyad[indis]);
            modSelect(&mus, indis);
    }
    else if(islem == 2){//Bankaya yeni bir kayıt yapılacak
        registerUser(&mus);
    }
    else{
        printf("Lütfen doğru bir giriş yapınız! Ana ekrana yönlendiriliyorsunuz");
    }
    }
    return 0;
}