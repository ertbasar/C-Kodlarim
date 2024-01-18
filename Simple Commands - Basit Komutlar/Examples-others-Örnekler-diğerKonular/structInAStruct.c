/*
Yapı içinde direkt olarak kendi türünden bir yapı olmasa da başka bir yapı değişkenini gösterme adına işaretçisi bulunabilir. Linked list vs yapılarda da işe yarar.
*/

struct INSAN{
    int yas;
    char isim[50];
    struct INSAN *sonraki_denek;
};
int main(void){
    struct INSAN denek1;
    printf("%lu\n", sizeof(denek1));
    return 0;
}