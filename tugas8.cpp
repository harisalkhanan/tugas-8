#include <iostream>
#include <string>

using namespace std;

struct Zodiak {
    string nama;
    int hariMulai, bulanMulai;
    int hariAkhir, bulanAkhir;
};

Zodiak daftarZodiak[12] = {
    {"Capricorn", 22, 12, 19, 1},
    {"Aquarius", 20, 1, 18, 2},
    {"Pisces", 19, 2, 20, 3},
    {"Aries", 21, 3, 19, 4},
    {"Taurus", 20, 4, 20, 5},
    {"Gemini", 21, 5, 20, 6},
    {"Cancer", 21, 6, 22, 7},
    {"Leo", 23, 7, 22, 8},
    {"Virgo", 23, 8, 22, 9},
    {"Libra", 23, 9, 22, 10},
    {"Scorpio", 23, 10, 21, 11},
    {"Sagittarius", 22, 11, 21, 12}
};

// Fungsi memeriksa tanggal berada di antara dua rentang
bool cekTanggal(int hari, int bulan, Zodiak zodiak) {
    if ((bulan == zodiak.bulanMulai && hari >= zodiak.hariMulai) || 
        (bulan == zodiak.bulanAkhir && hari <= zodiak.hariAkhir)) {
        return true;
    } else if (bulan > zodiak.bulanMulai && bulan < zodiak.bulanAkhir) {
        return true;
    }
    return false;
}

int main() {
    int hari, bulan, tahun;

    cout << "Masukkan hari lahir kamu: ";
    cin >> hari;
    cout << "Masukkan bulan lahir kamu: ";
    cin >> bulan;
    cout << "Masukkan tahun lahir kamu: ";
    cin >> tahun;

    bool zodiakDitemukan = false;
    string zodiak;

    for (int i = 0; i < 12; i++) {
        if (cekTanggal(hari, bulan, daftarZodiak[i])) {
            zodiak = daftarZodiak[i].nama;
            zodiakDitemukan = true;
            break;
        }
    }

    if (zodiakDitemukan) {
        cout << "Tanggal Lahir kamu: " << hari << "-" << bulan << "-" << tahun << endl;
        cout << "Zodiak kamu adalah: " << zodiak << endl;
    } else {
        cout << "tidak valid." << endl;
    }

    return 0;
}
