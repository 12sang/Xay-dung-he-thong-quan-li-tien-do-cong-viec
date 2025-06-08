#include <stdio.h>
#include <stdlib.h>
#include"quan-li-nhan-vien.cpp"
#include"quan-li-cong-viec.cpp"
#include"tai-du-lieu-tu-tep.cpp"
// pjno2: Xây dựng ứng dụng cho hệ thống quản lí tiến độ công việc cho công ty

// Hàm hiển thị menu
void hienThiMenu() {
    printf("\n================ HỆ THỐNG QUẢN LÝ TIẾN ĐỘ CÔNG VIỆC ================\n");
    printf("1. Quản lý nhân viên\n");
    printf("2. Quản lý công việc\n");
    printf("3. Phân công công việc\n");
    printf("4. Cập nhật tiến độ công việc\n");
    printf("5. Xem báo cáo tiến độ\n");
    printf("6. Tìm kiếm công việc\n");
    printf("7. Tải dữ liệu từ tệp\n");
    printf("0. Thoát chương trình\n");
    printf("====================================================================\n");
    printf("Nhập lựa chọn của bạn: ");
}

// Hàm xử lý lựa chọn
void xuLyLuaChon(int luaChon) {
    switch(luaChon) {
        case 1:
            printf(">> Chức năng Quản lý nhân viên đang được xử lý...\n");
            quanLyNhanVien();
            break;
        case 2:
            printf(">> Chức năng Quản lý công việc đang được xử lý...\n");
            quanLyCongViec();
            break;
        case 3:
            printf(">> Chức năng Phân công công việc đang được xử lý...\n");
            break;
        case 4:
            printf(">> Cập nhật tiến độ công việc đang được xử lý...\n");
            break;
        case 5:
            printf(">> Xem báo cáo tiến độ...\n");
            break;
        case 6:
            printf(">> Tìm kiếm công việc...\n");
            break;
        case 7:
            printf(">> Tải dữ liệu từ tệp...\n");
            xuat_file();
            break;
        case 0:
            printf(">> Đang thoát chương trình...\n");
            break;
        default:
            printf(">> Lựa chọn không hợp lệ! Vui lòng thử lại.\n");
    }
}

int main(){
 int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        xuLyLuaChon(luaChon);
    } while (luaChon != 0);
    return 0;
}
