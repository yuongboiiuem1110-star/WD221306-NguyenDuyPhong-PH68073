// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int flag = 1;
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
    int flag = 1;
    while (flag) {
        printf("Moi ban nhap so: \n");
        scanf("%f", &soNhap);
        if (soNhap - (int)soNhap == 0) {
            if (laSoNguyenTo(soNhap)) {
                printf("%2f la so nguyen to. \n", soNhap);
            }
            else if (laSoChinhPhuong(soNhap)) {
                printf("%2f la so chinh phuong. \n", soNhap);
            }
            else {
                printf("So vua nhap la so nguyen. \n");
            }
        }
        else {
            printf("So vua nhap khong phai la so nguyen. \n");
        }
        menuPhu(1);
        flag = 0;
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
    int flag = 1, flag1 = 1;
    int flag2 = 1;
    while (flag2) {
        printf("\nMoi nhap so a: \n");
        scanf("%d", &a);
        if (a - (int)a != 0) {
            printf("So a khong phai la so nguyen. Vui long nhap lai!\n");
            printf("--------------------------------\n");
        }
        else {
            while (flag) {
                printf("\nMoi nhap so b: \n");
                scanf("%d", &b);
                while (flag1) {
                    if (b - (int)b != 0) {
                        printf("So b khong phai la so nguyen. Vui long nhap lai!\n");
                        printf("--------------------------------\n");
                        break;
                    }
                    else {
                        printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, UCLN(a, b));
                        printf("Boi chung nho nhat cua %d va %d la: %d\n", a, b, BCNN(a, b));
                        menuPhu(2);
                        flag = 0; flag1 = 0; flag2 = 0;
                    }
                }
            }
        }
    }
}
float tienHat(int gioVao, int gioRa) {
    int soGio;
    int flag = 1;
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
void tinhTienQuanKaraoke() {
    int gioVao, gioRa;
    int choice = 1;
    int flag = 1;
    while (choice) {
        printf("\nMoi ban nhap gio vao [12-23]: \n");
        scanf("%d", &gioVao);
        while (flag) {
            if (gioVao < 12 || gioVao > 23) {
                printf("Nhap khong hop le! Quan chi hoat dong tu 12 - 23h. Vui long nhap lai gio vao: \n");
                printf("--------------------------------\n");
                break;
            }
            else {
                printf("\nMoi ban nhap gio ra [12-23]: \n");
                scanf("%d", &gioRa);
                for (int i = 1; i > 0; i++) {
                    if (gioRa > 24) {
                        printf("Nhap khong hop le! Quan chi hoat dong tu 12 - 23h. \n");
                        printf("--------------------------------\n");
                        break;
                    }
                    else if (gioRa <= gioVao) {
                        printf("Nhap khong hop le! Gio ra > gio vao[Gio vao ban dang nhap la: %d h] \n", gioVao);
                        printf("--------------------------------\n");
                        break;
                    }
                    else {
                        printf("So gio hat: %d\n", gioRa - gioVao);
                        printf("Tien thanh toan: %.2f VND\n", tienHat(gioVao, gioRa));
                        menuPhu(3);
                        flag = 0;
                        choice = 0;
                        break;
                    }
                }

            }

        }

    }
}
void TinhTienDien() {
    double kWh;
    int flag = 1;
    float tienDien;
    while (flag) {
        printf("\nMoi ban nhap so kWh tieu thu trong thang: \n");
        scanf("%lf", &kWh);
        if (kWh <= 0) {
            printf("So kWh khong hop le. Vui long nhap lai: \n");
            printf("--------------------------------\n");
        }
        else {
            if (kWh <= 50) {
                tienDien = kWh * 1678;

            }
            else if (kWh <= 100) {
                tienDien = 50 * 1678 + (kWh - 50) * 1734;

            }
            else if (kWh <= 200) {
                tienDien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;

            }
            else if (kWh <= 300) {
                tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536;

            }
            else if (kWh <= 400) {
                tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834;
            }
            else {
                tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927;
            }
            printf("Gia dien cua 50 so dau:     1678 VND\n");
            printf("Gia dien tu so 51 den 100:  1734 VND\n");
            printf("Gia dien tu so 101 den 200: 2014 VND\n");
            printf("Gia dien tu so 201 den 300: 2536 VND\n");
            printf("Gia dien tu so 301 den 400: 2834 VND\n");
            printf("Gia dien tu so 401 tro di:  2927 VND\n");
            printf("So tien dien phai tra trong thang la: %.0f VND\n", tienDien);
            menuPhu(4);
            flag = 0;
        }
    }
}
void ChucNangDoiTien() {
    int flag = 1;
    int soTien;
    int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int soLuong[9] = { 0 };
    while (flag) {
        printf("\nNhap so tien can doi: \n");
        scanf("%d", &soTien);
        if (soTien <= 0) {
            printf("So tien khong hop le. Vui long nhap lai!\n");
            printf("--------------------------------\n");
        }
        else {
            int soTienConLai = soTien;
            for (int j = 0; j < 9; j++) {
                if (menhGia[j] == 500 && soTien < 1000) {
                    continue;
                }
                if (menhGia[j] == 200 && soTien < 400) {
                    continue;
                }
                if (menhGia[j] == 100 && soTien < 200) {
                    continue;
                }
                if (menhGia[j] == 50 && soTien < 100) {
                    continue;
                }
                if (menhGia[j] == 20 && soTien < 40) {
                    continue;
                }
                if (menhGia[j] == 10 && soTien < 20) {
                    continue;
                }
                if (menhGia[j] == 5 && soTien < 10) {
                    continue;
                }
                if (menhGia[j] == 2 && soTien < 4) {
                    continue;
                }
                soLuong[j] = soTienConLai / menhGia[j];
                soTienConLai %= menhGia[j];
            }
            printf("Cac menh gia tien[500, 200, 100, 50, 20, 10, 5, 2, 1] \n");
            printf("----------------------------------------------------- \n");
            printf("Ket qua doi tien:\n");
            for (int i = 0; i < 9; i++) {
                if (soLuong[i] > 0) {
                    printf("%d to %d VND\n", soLuong[i], menhGia[i]);
                }
            }
            menuPhu(5);
            flag = 0;
        }
    }
}
void TinhLaiSuatVayNganHang() {
    int flag = 1;
    float soTienVay, tienLai, tongTienPhaiTra, gocHangThang, GocConLai, laiSuat = 0.05;
    while (flag) {
        printf("Lai suat co dinh 5%%/thang va ky han 12 thang \n");
        printf("-------------------------------------------- \n");
        printf("\nNhap so tien muon vay: \n");
        scanf("%f", &soTienVay);
        if (soTienVay <= 0) {
            printf("So tien vay khong hop le. Vui long nhap lai: \n");
            printf("-------------------------------------------\n");
        }
        else {
            gocHangThang = soTienVay / 12;
            printf("Bang tra gop 12 thang: \n");

            for (int thang = 1; thang <= 12; thang++) {
                tienLai = soTienVay * laiSuat;
                tongTienPhaiTra = gocHangThang + tienLai;
                soTienVay -= gocHangThang;
                printf("Thang %d: Tien goc hang thang: %.0f VND, Tien lai: %.0f VND, Tong tien phai tra: %.0f VND, So tien con lai: %.0f\n", thang, gocHangThang, tienLai, tongTienPhaiTra, soTienVay);
            }
            menuPhu(6);
            flag = 0;
        }
    }
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
    srand(time(NULL));
    int soNgauNhien = rand() % 15 + 1;
    int input;
    while (flag) {
        printf("\nNhap 1 so co 2 chu so[01-15]: \n");
        scanf("%d", &input);
        if (input < 0 || input > 15) {
            printf("So nhap khong dung! Vui long nhap lai[01-15] \n");
            printf("--------------------------------\n");
        }
        else {
            printf("So ngau nhien: %02d\n", soNgauNhien);
            int hangChucRanDom = soNgauNhien / 10;
            int hangDonViRanDom = soNgauNhien % 10;
            int hangChucInput = input / 10;
            int hangDonViInput = input % 10;
            int count = 0;
            if (hangChucRanDom == hangChucInput) count++;
            if (hangDonViRanDom == hangChucInput) count++;
            if (count == 2) printf("Chuc mung ban da trung giai nhat! \n");
            else if (count == 1) printf("Chuc mung ban da trung giai nhi! \n");
            else printf("Chuc ban may man lan sau! \n");
            menuPhu(9);
            flag = 0;
        }
    }
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
int menuPhu(int cacChucNang) {
    int flag = 1;
    int flag1 = 1;
    while (flag1) {
        printf("Ban co muon tiep tuc khong ? \n");
        printf("Co [chon 1] \n");
        printf("Khong [chon 0] \n");
        scanf("%d", &flag);
        switch (flag1) {
        case 1:
            if (cacChucNang == 1) {
                kiemTraSoNguyen();
                break;
            }
            else if (cacChucNang == 2) {
                UocChungBoiChung();
                break;
            }
            else if (cacChucNang == 3) {
                tinhTienQuanKaraoke();
                break;
            }
            else if (cacChucNang == 4) {
                TinhTienDien();
                break;
            }
            else if (cacChucNang == 5) {
                ChucNangDoiTien();
                break;
            }
            else if (cacChucNang == 6) {
                TinhLaiSuatVayNganHang();
                break;
            }
            else if (cacChucNang == 7) {
                VayTienMuaXe();
                break;
            }
            else if (cacChucNang == 8) {
                SapXepThongTinSV();
                break;
            }
            else if (cacChucNang == 9) {
                GameFPOLYLOTT();
                break;
            }
            else if (cacChucNang == 10) {
                TinhPhanSo();
                break;
            }
            break;
        case 0:
            printf("Tro ve menu chinh. \n");
            break;
        default:
            printf("Lua chon khong hop le! Xin vui long chon lai 1 de tiep tuc hoac 0 de thoat. \n");
            continue;
        }
        flag1 = 0;
    }
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
        case 3: tinhTienQuanKaraoke();
            break;
        case 4: TinhTienDien();
            break;
        case 5: ChucNangDoiTien();
            break;
        case 6: TinhLaiSuatVayNganHang();
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