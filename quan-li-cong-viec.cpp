#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONG_VIEC 100

typedef struct {
    int id;
    char ten[50];
    char moTa[100];
    int trangThai; // 0: Chua hoàn thành, 1: Ðã hoàn thành
} CongViec;

CongViec danhSachCongViec[MAX_CONG_VIEC];
int soLuongCongViec = 0;

// --- Các ch?c nang qu?n lý công vi?c ---
void themCongViec() {
    if (soLuongCongViec >= MAX_CONG_VIEC) {
        printf(">> Danh sách công vi?c dã d?y!\n");
        return;
    }
    CongViec cv;
    cv.id = soLuongCongViec + 1;
    printf("Nh?p tên công vi?c: ");
    scanf(" %49[^\n]", cv.ten);
    printf("Nh?p mô t? công vi?c: ");
    scanf(" %99[^\n]", cv.moTa);
    cv.trangThai = 0; // M?c d?nh chua hoàn thành
    danhSachCongViec[soLuongCongViec++] = cv;
    printf(">> Ðã thêm công vi?c: %s\n", cv.ten);
}

void hienThiCongViec() {
    printf("\n--- Danh sách công vi?c ---\n");
    if (soLuongCongViec == 0) {
        printf("Chua có công vi?c nào.\n");
        return;
    }
    for (int i = 0; i < soLuongCongViec; i++) {
        printf("ID: %d, Tên: %s, Mô t?: %s, Tr?ng thái: %s\n",
               danhSachCongViec[i].id,
               danhSachCongViec[i].ten,
               danhSachCongViec[i].moTa,
               danhSachCongViec[i].trangThai == 0 ? "Chua hoàn thành" : "Ðã hoàn thành");
    }
}

void capNhatTrangThaiCongViec() {
    int id, trangThai;
    printf("Nh?p ID công vi?c c?n c?p nh?t tr?ng thái: ");
    scanf("%d", &id);
    printf("Nh?p tr?ng thái (0: Chua hoàn thành, 1: Ðã hoàn thành): ");
    scanf("%d", &trangThai);
    int found = 0;
    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == id) {
            danhSachCongViec[i].trangThai = (trangThai == 1) ? 1 : 0;
            found = 1;
            printf(">> Ðã c?p nh?t tr?ng thái công vi?c ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Không tìm th?y công vi?c v?i ID %d\n", id);
}

void xoaCongViec() {
    int id;
    printf("Nh?p ID công vi?c c?n xóa: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == id) {
            found = 1;
            for (int j = i; j < soLuongCongViec - 1; j++) {
                danhSachCongViec[j] = danhSachCongViec[j + 1];
            }
            soLuongCongViec--;
            printf(">> Ðã xóa công vi?c ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Không tìm th?y công vi?c v?i ID %d\n", id);
}
void save_work(){
	FILE *f;
	f=fopen("cv.txt","w");
	if (f == NULL) {
    printf(">> Loi: Khong the mo file de ghi!\n");
    return;
}
	for (int i = 0; i < soLuongCongViec; i++){
		fprintf(f,"%d\n",danhSachCongViec[i].id);
		fprintf(f,"%s\n",danhSachCongViec[i].ten);
		fprintf(f,"%s\n",danhSachCongViec[i].moTa);
		fprintf(f,"%d\n",danhSachCongViec[i].trangThai);
	}
	fclose(f);
}


void quanLyCongViec() {
    int choice;
    do {
        printf("\n--- QU?N LÝ CÔNG VI?C ---\n");
        printf("1. Thêm công vi?c\n");
        printf("2. Hi?n th? danh sách công vi?c\n");
        printf("3. C?p nh?t tr?ng thái công vi?c\n");
        printf("4. Xóa công vi?c\n");
        printf("5. Luu cong viec vao file\n");
        printf("0. Quay l?i menu chính\n");
        printf("Ch?n ch?c nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                themCongViec();
                break;
            case 2:
                hienThiCongViec();
                break;
            case 3:
                capNhatTrangThaiCongViec();
                break;
            case 4:
                xoaCongViec();
                break;
            case 5:
              save_work();
              break;
            case 0:
                printf("Quay l?i menu chính...\n");
                break;
            default:
                printf("L?a ch?n không h?p l?, vui lòng th? l?i.\n");
        }
    } while (choice != 0);
}
