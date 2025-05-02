#include <iostream>
using namespace std;

class KeuanganAndi {
private:
    int uangSaku;
    int bulan;
    int pengeluaran[12];
    int tabungan[12];

public:
    KeuanganAndi(int saku, int jmlBulan) {
        uangSaku = saku;
        bulan = jmlBulan;
    }

    void inputData() {
        for (int i = 0; i < bulan; i++) {
            cout << "Pengeluaran bulan ke-" << (i + 1) << ": ";
            cin >> pengeluaran[i];
            tabungan[i] = uangSaku - pengeluaran[i];
        }
    }

    void tampilkanData() {
        cout << "\n============= Rincian Bulanan =============" << endl;
        for (int i = 0; i < bulan; i++) {
            cout << "Bulan " << (i + 1) << endl;
            cout << " | Pengeluaran: " << pengeluaran[i] << endl;
            cout << " | Tabungan: " << tabungan[i] << endl;
        }
        cout << "===========================================\n";
    }

    int hitungTotalPengeluaran() {
        int total = 0;
        for (int i = 0; i < bulan; i++) {
            total += pengeluaran[i];
        }
        return total;
    }

    int hitungTabunganRekursif(int i) {
        if (i >= bulan) return 0;
        return tabungan[i] + hitungTabunganRekursif(i + 1);
    }
};

int main() {
    int uangSaku, jumlahBulan;

    cout << "Masukkan uang saku bulanan Andi: ";
    cin >> uangSaku;

    cout << "Masukkan jumlah bulan: ";
    cin >> jumlahBulan;

    KeuanganAndi andi(uangSaku, jumlahBulan);
    andi.inputData();
    andi.tampilkanData();

    int totalPengeluaran = andi.hitungTotalPengeluaran();
    int totalTabungan = andi.hitungTabunganRekursif(0);

    cout << "\nTotal Pengeluaran Andi selama " << jumlahBulan << " bulan adalah " << totalPengeluaran << endl;
    cout << "Total Tabungan Andi selama " << jumlahBulan << " bulan adalah "<< totalTabungan << endl;

    return 0;
}
