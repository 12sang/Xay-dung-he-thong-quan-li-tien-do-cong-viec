#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NHAN_VIEN 100

typedef struct {
    int id;
    char ten[50];
    char viTri[50];
} NhanVien;

NhanVien danhSachNhanVien[MAX_NHAN_VIEN];
int soLuongNhanVien = 0;

// --- Các ch?c nang qu?n lý nhân viên ---
void themNhanVien() {
    if (soLuongNhanVien >= MAX_NHAN_VIEN) {
        printf(">> Danh sách nhân viên dã d?y!\n");
        return;
    }
    NhanVien nv;
    nv.id = soLuongNhanVien + 1;
    printf("Nh?p tên nhân viên: ");
    scanf(" %49[^\n]", nv.ten);
    printf("Nh?p v? trí: ");
    scanf(" %49[^\n]", nv.viTri);
    danhSachNhanVien[soLuongNhanVien++] = nv;
    printf(">> Ðã thêm nhân viên: %s, V? trí: %s\n", nv.ten, nv.viTri);
}
void luu(char *ten_file){
FILE *f;
f=fopen(ten_file,"a");
 if (!f) {
        printf(">> Không th? m? file d? ghi!\n");
        return;
    }
   for (int i= 0; i < soLuongNhanVien; i++) {
   fprintf(f,"%s\n",danhSachNhanVien[i].ten);
    fprintf(f,"%s\n",danhSachNhanVien[i].viTri);
       fprintf(f,"%d\n",danhSachNhanVien[i].id);}
       fclose(f);
}

void hienThiNhanVien() {
    printf("\n--- Danh sách nhân viên ---\n");
    if (soLuongNhanVien == 0) {
        printf("Chua có nhân viên nào.\n");
        return;
    }
    for (int i = 0; i < soLuongNhanVien; i++) {
        printf("ID: %d, Tên: %s, V? trí: %s\n", danhSachNhanVien[i].id, danhSachNhanVien[i].ten, danhSachNhanVien[i].viTri);
    }
}

void xoaNhanVien() {
    int id;
    printf("Nh?p ID nhân viên c?n xóa: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < soLuongNhanVien; i++) {
        if (danhSachNhanVien[i].id == id) {
            found = 1;
            for (int j = i; j < soLuongNhanVien - 1; j++) {
                danhSachNhanVien[j] = danhSachNhanVien[j + 1];
            }
            soLuongNhanVien--;
            printf(">> Ðã xóa nhân viên ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Không tìm th?y nhân viên v?i ID %d\n", id);
}

void quanLyNhanVien() {
    int choice;
    char ten_file[100];
    
    do {
        printf("\n--- QU?N LÝ NHÂN VIÊN ---\n");
        printf("1. Thêm nhân viên\n");
        printf("2. Hi?n th? danh sách nhân viên\n");
        printf("3. Xóa nhân viên\n");
        printf("4. Luu vào danh sách \n");
        printf("0. Quay l?i menu chính\n");
        printf("Ch?n ch?c nang: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            themNhanVien();
            break;
        case 2:
            hienThiNhanVien();
            break;
        case 3:
            xoaNhanVien();
            break;
            case 4: 
            getchar();
            fgets(ten_file,sizeof(ten_file),stdin);
            ten_file[strcspn(ten_file,"\n")]='\0';
            luu(ten_file);
            break;
        case 0:
            printf("Quay l?i menu chính...\n");
            break;
        default:
            printf("L?a ch?n không h?p l?, vui lòng th? l?i.\n");
        }
    } while (choice != 0);
}

