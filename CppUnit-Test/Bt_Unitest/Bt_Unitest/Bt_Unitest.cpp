#include <iostream>
#include <string>

using namespace std;

int main() {
    try {
        // Nhập số a
        cout << "Nhap so thu nhat (a): ";
        double a;
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Vui long nhap so hop le!");
        }

        // Nhập số b
        cout << "Nhap so thu hai (b): ";
        double b;
        cin >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Vui long nhap so hop le!");
        }

        // Tính toán
        double tong = a + b;
        double hieu = a - b;
        double tich = a * b;

        // Hiển thị kết quả
        cout << "\nKet qua:\n";
        cout << "Tong: " << a << " + " << b << " = " << tong << endl;
        cout << "Hieu: " << a << " - " << b << " = " << hieu << endl;
        cout << "Tich: " << a << " * " << b << " = " << tich << endl;

        // Kiểm tra chia cho 0
        if (b != 0) {
            double thuong = a / b;
            cout << "Thuong: " << a << " / " << b << " = " << thuong << endl;
        }
        else {
            cout << "Khong the chia cho 0!" << endl;
        }
    }
    catch (const runtime_error& ex) {
        cout << "Loi: " << ex.what() << endl;
    }
    catch (...) {
        cout << "Loi: Co loi khong xac dinh!" << endl;
    }

    // Giữ console để xem kết quả
    cout << "\nNhan phim bat ky de thoat...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}