int sayi;
    printf("Lutfen oluşturmak istediğiniz arrayin büyüklüğünü giriniz:");
    scanf("%d", &sayi);
    int *array;
    array = (int*)calloc(sizeof(int)*sayi);