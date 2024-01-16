/*
C'de bellek yönetim çok önemlidir. Şu an işlemleri 16GB RAM'e sahip bir bilgisayardan yapsam da bu ileride çok daha düşük bir
belleğe sahip bir cihazla çalışmayacağım anlamına gelmemekte. Bundan ötürü de bu konuyu özellikle Cpp'ye geçmeden önce C'yi 
tekrar ederken irdelemek istedim. Burada kullanılan dört adet farklı fonksiyon olarak, bunlar malloc, calloc, realloc ve free.
malloc ve calloc ile bölgeleri tahsis edeceğiz, gerekmesi durumunda realloc ile daha büyük bir alanı tahsis edeceğiz ve free ile
de bu ayırdığımız alanı belleğe sisteme geri iade edeceğiz. Ayrıca stdlib kütüphanesini kullanmak gerekli.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //temel bir malloc komutu
    int *a; 
    a = (int*)malloc(sizeof(int)*10);// ile aslına bakarsak 10 elemanlı bir array oluşturduk da denebilir. Bilinçli tür dönüşümü kullanarak taşınabilirliği arttırmaya çalıştık.
    if(a == NULL){
        printf("Yetersiz Bellek");//Eğer bellekte yer ayıramazsa NULL döner ve bunu kontrol etmek önemlidir.
    }
    else{
        for (int i = 0; i < 10; i++)
        {
            a[i] = i+1;
        }
        for (int i = 0; i < 10; i++)
        {
            printf("%d\n", a[i]);
        }
    }
    //a işaretçisi bittikten sonra NULL pointer mı var?
    int *deneme;
    deneme = a;
    while(*deneme != 0 && deneme != NULL){//Eğer sadece NULL kullanırsam sonsuz döngüye giriyor bu çalıştığım bilgisayarda NULL olarak tutulmamasından dolayı diye tahmin ediyorum. 
        printf("Adres:%p ve Değer:%d\n", deneme, *deneme);
        deneme++;
    }
    //Araya NULL koyarak da denememe rağmen istediğim sonucu alamadım. Bu şu anda kullandığım bilgisayarla alakalı olarak düşünmekteyim, zaten yapay zekaya sorunca da istediğim gibi bir cevap alamadım.
    //Şimdi de kullanıcıdan bir değer alarak o sayıya bir calloc yapalım ki boyutunu belirleyebildiğimiz bir dizi gibi gözüksün. calloc da zaten malloc çağırır sadece önceden veri varsa bunları sıfırlar.
    int sayi;
    printf("Lutfen oluşturmak istediğiniz arrayin büyüklüğünü giriniz:");
    scanf("%d", &sayi);
    int *array;
    array = (int*)calloc(sayi,sizeof(int));//calloc içinde ne kadar sayıda ne istediğimizi belirtiriz
    if(array == NULL)
        printf("Bellek tahsis hatası");
    for (int i = 0; i < sayi; i++)
    {
        array[i+2] = i+1;//arrayin başladığı adresten iki sonra ile başlar ve burda array bitse de devamını getirmekte sorun yaşamaz
        printf("Calloc deger: %d\n", array[i]);
    }
    printf("%d",array[7]);//yukarıda sayi = 6 desek ve sonrasında burayı gözlemlersek yukarıda belirttiğimiz nedenden dolayı 6 değerini hatasız bir şekilde alırız.
    //Şimdi de az önceki arrayi realloc edelim
    array = realloc(array, sizeof(int) * (sayi + 2));
    //Yukarıdaki kullanım pek doğru değil, çünkü eğer yeni bir yer tahsis edilemezse eski blok değişmez ve programın sağlıklı bir şekilde çalışmasını kontrol etmek için orijinal bloğu serbest bırakmak gerekir. Geçici bir işaretçi oluşturup o şekilde ayarlamak daha iyi olur. Ancak yeni yer tahsis edilemediğinde işe devam edilmesi isteniyorsa yukarıdaki satır yeterlidir.
    int *temp = realloc(array, sizeof(int) * (sayi + 2));
    if(temp == NULL){//hatalı durumda yapılacaklar
        printf("Bellek tahsis hatası");
        free(array);
    }
    else{
        array = temp;//tahsis edildiğindeki davranış
    }
    free(a);//en başta ayırdığım belleği sisteme geri veriyorum
    free(array);
    return 0;
}