#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void in_file1(){
    FILE *f = fopen("nv.txt", "r");
    if (!f) {
        printf(">> Không thê mo file \n");
        return;
    }
int c=0;
    int id;
    char ten[100];
    char viTri[100];

    printf("\n--- Danh sách nhân viên tu file ---\n");

    while (fscanf(f, "%d\n", &id) == 1) {
    	c++;
        if (!fgets(ten, sizeof(ten), f)) break;
        if (!fgets(viTri, sizeof(viTri), f)) break;
        ten[strcspn(ten, "\n")] = '\0';
        viTri[strcspn(viTri, "\n")] = '\0';

        printf("%d ID: %d, Tên: %s, Vi trí: %s\n",c, id, ten, viTri);
    }
    fclose(f);
}
     void in_file2(){
    	int c=0;
    FILE *f = fopen("nv.txt", "r");
    if (!f) {
        printf(">> Không tim thay file\n");
        return ;
    }
    int id;
    char ten[50];
    char moTa[100];
    int trangThai;
    printf("\n--- Danh sách quan ly cong viec ---\n");
    while (fscanf(f, "%d\n", &id) == 1) {
    	c++;
        if (!fgets(ten, sizeof(ten), f)) break;
        if (!fgets(moTa, sizeof(moTa), f)) break;
        if (fscanf(f, "%d\n", &trangThai) != 1) break;
        ten[strcspn(ten, "\n")] = '\0';
        moTa[strcspn(moTa, "\n")] = '\0';
        printf("%d\n",c);
        printf("ID: %d\n", id);
        printf("Ten: %s\n", ten);
        printf("Tien do: %s\n", moTa);
        printf("Trang thái: %s\n", trangThai == 0 ? "Chua hoàn thành" : "Ðã hoàn thành");
    }
    fclose(f);
    return ;
}

void xuat_file() {
    int choice;
    
    do {
        printf("\n--- IN FILE ---\n");
        printf("1. In file quan li nhan vien \n");
        printf("2. IN file quan li cong viec \n");
        printf("0. Quay l?i menu chính\n");
        printf("Ch?n ch?c nang: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            in_file1();
            break;
        case 2:
           in_file2();
            break;
        case 0:
            printf("Quay lai menu chính...\n");
            break;
        default:
            printf("lua chon ko phu hop.\n");
        }
    } while (choice != 0);
}
