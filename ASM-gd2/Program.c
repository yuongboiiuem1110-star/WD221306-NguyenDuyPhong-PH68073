// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool laSoChinhPhuong(int n) {
    if (n < 0) return false;
    int can = sqrt(n);
    return can * can == n;
}
void kiemTraSoNguyen() {
    float soNhap;
    int kiemTra = 1;
    int flag = 1;

    while (kiemTra) {
        printf(" Moi ban nhap so: \n");
        scanf("%f", &soNhap);
        if (soNhap - (int)soNhap == 0) {
            if (laSoNguyenTo(soNhap)) {
                printf(" %2f la so nguyen to. \n ", soNhap);
            }
            else if (laSoChinhPhuong(soNhap)) {
                printf(" %2f la so chinh phuong. \n", soNhap);
            }
            else {
                printf("So vua nhap la so nguyen.\n");
            }
        }
        else {
            printf("So vua nhap khong phai la so nguyen.\n");
        }
        do {
            printf(" Ban co muon tiep tuc khong?\n");
            printf("1. Co\n");
            printf("2. Khong [0]\n");
            scanf("%d", &flag);

            switch (flag) {
            case 1: kiemTraSoNguyen();
                break;
            case 0: flag = 0;
                break;
            default:
                printf("Ban nhap loi[Vui long chon 1 hoac 0] \n");
                break;
            }
        } while (flag);
        break;
    }
}
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}
void UocChungBoiChung() {
    int choice = 1;
    int a, b;
    while (choice) {
        printf("\n=====Menu=====\n");
        printf("1. Tim Uoc chung lon nhat(UCLN)\n");
        printf("2. Tim Boi chung nho nhat(BCNN)\n");
        printf("3. Quay ve Menu chinh(Chon phim 0)\n");
        printf("Moi ban chon: \n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Moi nhap so a: \n");
            scanf("%d", &a);
            printf("Moi nhap so b: \n");
            scanf("%d", &b);
            printf("Uoc chung lon nhat cua %d vaf %d la: %d\n", a, b, UCLN(a, b));
            break;
        case 2:
            printf("Moi nhap so a: \n");
            scanf("%d", &a);
            printf("Moi nhap so b: \n");
            scanf("%d", &b);
            printf("Boi chung nho nhat cua %d va %d la: %d\n", a, b, BCNN(a, b));
            break;
        case 0:
            break;
        default: printf("Ban nhap loi, vui long chon lai!\n");
            break;
        }
    }
}
float tienHat(int gioVao, int gioRa) {
    int soGio;
    float tienThanhToan;
    soGio = gioRa - gioVao;
    if (soGio <= 3) {
        if (gioVao >= 14 && gioVao <= 17) {
            return tienThanhToan = soGio * 150000 * 0.9;
        }
        return  tienThanhToan = soGio * 150000;
    }
    else {
        if (gioVao >= 14 && gioVao <= 17) {
            return tienThanhToan = (3 * 150000 + (soGio - 3) * 150000 * 0.7) * 0.9;
        }
        return tienThanhToan = 3 * 150000 + (soGio - 3) * 150000 * 0.7;
    }
}
void TinhTienKaraoke() {
    int gioVao, gioRa;
    int flag = 1, choice = 1, flag1 = 1;
    while (choice) {
        printf("Moi ban nhap gio vao [12-23]: \n");
        scanf("%d", &gioVao);
        while (flag) {
            if (gioVao < 12 || gioVao > 23) {
                printf("Nhap khong hop le! Quan chi mo cua tu 12 - 23h. XIn vui long nhap lai gio vao: \n");
                break;
            }
            else {
                printf("Moi ban nhap gio ra [12-23]: \n");
                scanf("%d", &gioRa);
                for (int i = 1; i > 0; i++) {
                    if (gioRa < 13 || gioRa > 24) {
                        printf("Nhap khong hop le! Quan chi mo cua tu 12 - 23h. \n");
                        break;
                    }
                    else if (gioRa <= gioVao) {
                        printf("Nhap khong hop le! Gio ra > gio vao. \n");
                        break;
                    }
                    else {
                        printf("So gio hat: %d\n", gioRa - gioVao);
                        printf("Tien thanh toan: %.2f VND\n", tienHat(gioVao, gioRa));
                        do {
                            printf("Ban co muon tiep tuc tinh tien hat khong? \n");
                            printf("Co.[1] \n");
                            printf("Khong.[0] \n");
                            scanf("%d", &flag1);

                            switch (flag1) {
                            case 1: TinhTienKaraoke();
                                break;
                            case 0:
                                flag1 = 0; flag = 0;
                                choice = 0; i = 0;
                                break;
                            default: printf("Ban nhap loi![Vui long chon 1 hoac 0] \n");
                                break;
                            }
                        } while (flag1);

                    }
                }
                break;
            }
            break;
        }
    }
}
void TinhTienDien() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
void DoiTien() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
void TinhLaiNganHang() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
void VayTienMuaXe() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
void SapXepThongTinSV() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
void GameFPOLYLOTT() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
void TinhPhanSo() {
    int flag;
    do {
        printf("Ban co muon su dung tiep khong ? \n");
        printf("Co [1] \n");
        printf("Khong [0] \n");
        scanf("%d", &flag);
        switch (flag) {
        default:
            printf("Nhap loi [ Vui long chon 1 de tiep tuc hoac 0 de thoat ]\n");
            break;
        }
    } while (flag);
}
int main()
{
    int choice;
    do {
        printf("\n---------- MENU ----------\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Uoc chung || Boi chung\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. tinh phan so\n");
        printf("0. Thoat chuong trinh\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: kiemTraSoNguyen();
            break;
        case 2: UocChungBoiChung();
            break;
        case 3: TinhTienKaraoke();
            break;
        case 4: TinhTienDien();
            break;
        case 5: DoiTien();
            break;
        case 6: TinhLaiNganHang();
            break;
        case 7: VayTienMuaXe();
            break;
        case 8: SapXepThongTinSV();
            break;
        case 9: GameFPOLYLOTT();
            break;
        case 10: TinhPhanSo();
            break;
        case 0: printf("Thoat chuong trinh.\n");
            break;
        default: printf("Lua chon khong hop le. Xin long chon lai [1-10] hoac 0 de thoat chuong trinh.\n");
            break;
        }
    } while (choice != 0);

    return 0;

}

// Debug/Run chuong trinh: bam "F5" hoac "Debug > Start Debugging" tren menu

// Danh cho nguoi moi bat dau:
//   1. Mo "View" > "Solution Explorer"
//          de them/quan ly cac files
//   2. Mo "View" > "Output"
//          de kiem tra "build output" va "cac thong bao khac"
//   3. Mo "View" > "Error List"
//          de xem loi
//   4. Chon Project > "Add" > "New Item"
//          de tao moi file code,
//      hoac Project > "Add" > "Existing Item"
//          de them file da ton tai vao project nay.
//   5. Sau nay, de mo lai project nay,
//          chon "File > Open > Project" va chon file *.sln
//      Co the xem thu muc project, noi luu file *.sln bang cach
//          trong cua so "Solution Explorer"
//          bam chuot phai vao "Solution"
//          chon "Open Folder in File Explorer"

// GV: AnhTT184