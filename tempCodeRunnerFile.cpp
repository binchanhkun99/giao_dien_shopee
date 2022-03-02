#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct KhachHang {
    int id;
    char ten[30];
    char gioiTinh[5];
    char diaChi[25];
    int soNgayThue;
    int soNgayTra;
    int tuoi;
    int SCMND;
    char tinhTrang[25];
    float tongTien;
};

typedef KhachHang KH;

void printLine(int n);
void nhapThongTinKH(KH &kh, int id);
void nhapKH(KH a[], int id, int n);
void capNhatThongTinKH(KH &kh);
void capNhatKH(KH a[], int id, int n);
int xoaTheoID(KH a[], int id, int n);
void timKiemTheoTen(KH a[], char ten[], int n);
void tinhTongTien(KH &kh);
int idLonNhat(KH a[], int n);
void sapXepTheoTen(KH a[], int n);
void showKhachHang(KH a[], int n);
int docFile(KH a[], char fileName[]);
void ghiFile(KH a[], int n, char fileName[]);
void pressAnyKey();

int main() {
    int key;
    char fileName[] = "khachhang.txt";
    KH arrayKH[MAX];
    int soluongKH = 0;
    int idCount = 0;
    soluongKH = docFile(arrayKH, fileName);
    idCount = idLonNhat (arrayKH, soluongKH);

    while(true) {
        cout << "CHUONG TRINH QUAN LY KHSCH HANG ";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them thong tin khach hang.                               **\n";
        cout << "**  2. Cap nhat thong tin khach hang boi ID.          **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem khach hang theo ten.                  **\n";
        cout << "**  6. Sap xep khach hang theo ten.                   **\n";
        cout << "**  7. Hien thi danh sach khach hang.                 **\n";
        cout << "**  8. Ghi danh sach khach hang vao file.             **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them KHACH HANG.";
                idCount++;
                nhapKH(arrayKH, idCount, soluongKH);
                printf("\nThem khach hang thanh cong!");
                soluongKH++;
                pressAnyKey();
                break;
            case 2:
                if(soluongKH > 0) {
                    int id;
                    cout << "\n2. Cap nhat thong tin khach hang. ";
                    cout << "\n Nhap ID: "; cin >> id;
                    capNhatKH(arrayKH, id, soluongKH);
                }else{
                    cout << "\nSanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongKH > 0) {
                    int id;
                    cout << "\n3. Xoa khach hang.";
                    cout << "\n Nhap ID: "; cin >> id;
                    if (xoaTheoID(arrayKH, id, soluongKH) == 1) {
                        printf("\nkhach hang co id = %d da bi xoa.", &id);
                        soluongKH--;
                    }
                }else{
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongKH > 0) {
                    cout << "\n4. Tim kiem khach hang theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(arrayKH, strTen, soluongKH);
                }else{
                    cout << "\nSanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 5:
                if(soluongKH > 0) {
                    cout << "\n5. Sap xep Khach hang theo ten.";
                    sapXepTheoTen(arrayKH, soluongKH);
                    showKhachHang(arrayKH, soluongKH);
                }else{
                    cout << "\nSanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongKH > 0){
                    cout << "\n7. Hien thi danh sach khach hang.";
                    showKhachHang(arrayKH, soluongKH);
                }else{
                    cout << "\nSanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 8:
                if(soluongKH > 0){
                    cout << "\n8. Ghi danh sach khach hang vao file.";
                    ghiFile(arrayKH, soluongKH, fileName);
                }else{
                    cout << "\nSanh sach khach hang trong!";
                }
                printf("\nGhi danh sach khach hang vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
 
void tinhTongTien(KH &kh) {
    kh.tongTien = (kh.soNgayTra - kh.soNgayThue) * 100;    
}

 
void nhapThongTinSV(KH &kh, int id) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(kh.ten);
    cout << " Nhap gioi tinh: "; gets(kh.gioiTinh);
    cout << " Nhap tuoi: "; cin >> kh.tuoi;
    cout << " Nhap so CMND: "; cin >> kh.SCMND;
    cout << " Nhap ngay thue: "; cin >> kh.soNgayThue;
    cout << " Nhap ngay tra: "; cin >> kh.soNgayTra;
    cout << "\n Nhap tinh trang: "; fflush(stdin); gets(kh.tinhTrang);
    kh.id = id;
    tinhTongTien(kh);
}

void nhapKH(KH a[], int id, int n) {
    printLine(40);
    printf("\n Nhap khach hang thu %d:", n + 1);
    nhapThongTinKH(a[n], id);
    printLine(40);
}

void capNhatThongTinKH(KH &kh) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(kh.ten);
    cout << " Nhap gioi tinh: ";fflush(stdin); gets(kh.gioiTinh);
    cout << "\n Nhap dia chi: "; fflush(stdin); gets(kh.diaChi);
    cout << " Nhap tuoi: "; cin >> kh.tuoi;
    cout << " Nhap so CMND: "; cin >> kh.SCMND;
    cout << " Nhap ngay thue: "; cin >> kh.soNgayThue;
    cout << " Nhap ngay tra: "; cin >> kh.soNgayTra;
    cout << "\n Nhap tinh trang: "; fflush(stdin); gets(kh.tinhTrang);
    tinhTongTien(kh);
    
}

void capNhatKH(KH a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin khach hang co ID = " << id;
            capNhatThongTinKH(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Khach hang co ID = %d khong ton tai.", id);
    }
}

int xoaTheoID(KH a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa KH co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Khach hang co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}

void timKiemTheoTen(KH a[], char ten[], int n) {
    KH arrayFound[MAX];
    char tenKH[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenKH, a[i].ten);
        if(strstr(strupr(tenKH), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showKhachHang(arrayFound, found);
}

void showKhachHang(KH a[], int n) {
    printLine(100);
    cout <<"\nSTT\tID\tHo va ten\tDia chi\tGioi tinh\tNgay thue\tngay tra\tTuoi\tCMT\tTinh trang\ttong tien";
    for(int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].diaChi);
        printf("\t\t%s", a[i].gioiTinh);
        printf("\t\t%d", a[i].soNgayThue);
        printf("\t\t%d", a[i].soNgayTra);
        printf("\t\t%d", a[i].tuoi);
        printf("\t\t%d", a[i].SCMND);
        printf("\t%s", a[i].tinhTrang);
        printf("\t%.2f", a[i].tongTien);
    }
    printLine(100);
}

void sapXepTheoTen(KH a[], int n) {
    KH tmp;
    char tenKH1[30];
    char tenKH2[30];
    for(int i = 0;i < n; i++) {
    	strcpy(tenKH1, a[i].ten);
        for(int j = i+1; j < n; j++) {
        	strcpy(tenKH2, a[j].ten);
            if(strcmp(strupr(tenKH1), strupr(tenKH2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int idLonNhat (KH a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for(int i = 0;i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}

int docFile(KH a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    while (fscanf(fp, "%5d%30s%5s%5s%5d%5d%10d%10d%10s%2f\n", &a[i].id, &a[i].ten, 
            &a[i].gioiTinh, &a[i].diaChi, &a[i].soNgayThue, &a[i].soNgayTra, &a[i].tuoi, &a[i].SCMND,
			&a[i].tinhTrang,
            &a[i].tongTien) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong khach hang co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    return i;
}

void ghiFile(KH a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5s%5d%5d%10d%10d%10s%2f\n", &a[i].id, &a[i].ten, 
            &a[i].gioiTinh, &a[i].diaChi, &a[i].soNgayThue, &a[i].soNgayTra, &a[i].tuoi, &a[i].SCMND,
			&a[i].tinhTrang,
            &a[i].tongTien);
    }
    fclose (fp);
}

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}