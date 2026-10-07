#include <iostream>
#include <string>
using namespace std;

struct NgaySinh
{
    int ngay;
    int thang;
    int nam;
};

struct NhanVien
{
    int maNV;
    string hoTen;
    NgaySinh ngaySinh;
    float luong;
};

void nhap(NhanVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";

        cout << "Ma nhan vien: ";
        cin >> a[i].maNV;
        cin.ignore();

        cout << "Ho ten: ";
        getline(cin, a[i].hoTen);

        cout << "Ngay sinh: ";
        cin >> a[i].ngaySinh.ngay;
        cout << "Thang sinh: ";
        cin >> a[i].ngaySinh.thang;
        cout << "Nam sinh: ";
        cin >> a[i].ngaySinh.nam;

        cout << "Luong (trieu dong): ";
        cin >> a[i].luong;
    }
}

void xuat(NhanVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        cout << "Ma nhan vien: " << a[i].maNV << endl;
        cout << "Ho ten: " << a[i].hoTen << endl;
        cout << "Ngay sinh: "
             << a[i].ngaySinh.ngay << "/"
             << a[i].ngaySinh.thang << "/"
             << a[i].ngaySinh.nam << endl;
        cout << "Luong: " << a[i].luong << " trieu dong" << endl;
    }
}

void sapXep(NhanVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].luong > a[j + 1].luong)
            {
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void timKiem(NhanVien a[], int n, float X)
{
    int left = 0;
    int right = n - 1;
    int viTri = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].luong == X)
        {
            viTri = mid;
            break;
        }
        else if (a[mid].luong < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (viTri == -1)
    {
        cout << "\nKhong tim thay nhan vien co luong bang " << X << endl;
        return;
    }

    int i = viTri;

    while (i >= 0 && a[i].luong == X)
    {
        i--;
    }

    i++;

    cout << "\nCac nhan vien co luong bang " << X << " trieu dong:\n";

    while (i < n && a[i].luong == X)
    {
        cout << "\nMa nhan vien: " << a[i].maNV << endl;
        cout << "Ho ten: " << a[i].hoTen << endl;
        cout << "Ngay sinh: "
             << a[i].ngaySinh.ngay << "/"
             << a[i].ngaySinh.thang << "/"
             << a[i].ngaySinh.nam << endl;
        cout << "Luong: " << a[i].luong << " trieu dong" << endl;

        i++;
    }
}

int main()
{
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    NhanVien a[100];

    nhap(a, n);

    cout << "\n===== DANH SACH NHAN VIEN VUA NHAP =====\n";
    xuat(a, n);

    sapXep(a, n);

    cout << "\n===== DANH SACH SAU KHI SAP XEP =====\n";
    xuat(a, n);

    float X;

    cout << "\nNhap luong X can tim: ";
    cin >> X;

    timKiem(a, n, X);

    return 0;
}
