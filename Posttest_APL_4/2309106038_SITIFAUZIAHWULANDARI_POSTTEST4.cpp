#include <iostream>
#include <cstdlib>
using namespace std;

#define maksimal 15

// struct untuk menyimpan informasi skincare
struct Skincare
{
    string namaProduk;
    string jenisProduk;
};

// Array of struct untuk menyimpan data produk skincare
Skincare dataSkincare[maksimal];
int awal = 0;
string loop;

bool login()
{
    string username, password;
    int minLogin = 0;

    do
    {
        cout << "Masukkan username: ";
        getline(cin, username);
        cout << "Masukkan password: ";
        cin >> password;
        cin.ignore();

        if (username == "siti fauziah wulandari" && password == "2309106038")
        {
            cout << "Selamat Datang!" << endl;
            return true;
        }
        else
        {
            cout << "Login gagal! Coba lagi." << endl;
            minLogin++;
        }
    } while (minLogin < 3);

    cout << "Anda telah mencoba sebanyak 3 kali. Program berhenti." << endl;
    return false;
}

void tampilkan()
{
    system("cls");
    if (awal > 0)
    {
        cout << "Data tersimpan" << endl;
        for (int a = 0; a < awal; a++)
        {
            cout << a + 1 << ". Nama: " << dataSkincare[a].namaProduk << " Jenis: " << dataSkincare[a].jenisProduk << endl;
        }
    }
    else
    {
        cout << "Data kosong" << endl;
    }
}

void tambah()
{
    do
    {
        if (awal < maksimal)
        {
            cin.ignore(); // Bersihkan buffer
            cout << "Masukkan nama produk: ";
            getline(cin, dataSkincare[awal].namaProduk);
            cout << "Masukkan jenis produk: ";
            getline(cin, dataSkincare[awal].jenisProduk);
            awal++;
            cout << "Ulangi lagi (y/t): ";
            cin >> loop;
            // Error handling untuk memastikan input adalah 'y' atau 't'
            while (loop != "y" && loop != "t")
            {
                cout << "Masukan tidak valid. Ulangi lagi (y/t): ";
                cin >> loop;
            }
        }
        else
        {
            cout << "Data sudah penuh" << endl;
            cout << "Ketik t untuk kembali: ";
            cin >> loop;
            // Error handling untuk memastikan input adalah 't'
            while (loop != "t")
            {
                cout << "Masukan tidak valid. Ketik t untuk kembali: ";
                cin >> loop;
            }
        }
    } while (loop == "y");
}

void ubah()
{
    if (awal == 0)
    {
        cout << "Tidak ada data skincare yang tersedia." << endl;
        cout << "Kembali ke menu utama..." << endl;
        return;
    }
    int x;
    tampilkan();
    cout << "Ubah data ke: ";
    cin >> x;

    // Error handling untuk memastikan input adalah angka dan dalam rentang yang benar
    while (cin.fail() || x < 1 || x > awal)
    {
        cin.clear();
        cout << "Input tidak valid. Masukkan angka antara 1 dan " << awal << ": ";
        cin >> x;
    }

    cin.ignore(); // Bersihkan buffer
    cout << "Ubah nama produk: ";
    getline(cin, dataSkincare[x - 1].namaProduk);
    cout << "Ubah jenis produk: ";
    getline(cin, dataSkincare[x - 1].jenisProduk);
    cout << "Mau mengubah lagi? (y/t): ";
    cin >> loop;
    // Error handling untuk memastikan input adalah 'y' atau 't'
    while (loop != "y" && loop != "t")
    {
        cout << "Masukan tidak valid. Ulangi lagi (y/t): ";
        cin >> loop;
    }

    if (loop == "y")
        ubah(); // Panggil kembali fungsi ubah jika pengguna ingin mengubah lagi
    else if (loop == "t")
        return; // Kembali ke menu utama jika tidak ingin mengubah lagi
}

void hapus()
{
    // Periksa apakah ada data skincare yang tersedia
    if (awal == 0)
    {
        cout << "Tidak ada data skincare yang tersedia." << endl;
        cout << "Kembali ke menu utama..." << endl;
        return;
    }

    int x;
    tampilkan();
    cout << "Hapus data ke: ";
    cin >> x;

    // Error handling untuk memastikan input adalah angka dan dalam rentang yang benar
    while (cin.fail() || x < 1 || x > awal)
    {
        cin.clear();
        cout << "Input tidak valid. Masukkan angka antara 1 dan " << awal << ": ";
        cin >> x;
    }

    for (int i = x - 1; i < awal - 1; i++)
    {
        dataSkincare[i] = dataSkincare[i + 1];
    }
    awal--;
    cout << "Data berhasil dihapus." << endl;
    cout << "Hapus lagi(y/t): ";
    cin >> loop;
    // Error handling untuk memastikan input adalah 'y' atau 't'
    while (loop != "y" && loop != "t")
    {
        cout << "Masukan tidak valid. Ulangi lagi (y/t): ";
        cin >> loop;
    }

    if (loop == "y")
        hapus(); // Pertimbangkan penggunaan iterasi daripada rekursi
}

int main()
{
    if (!login())
    {
        return 1;
    }

    int pilih;
    do
    {
        system("cls");
        cout << "|-------------Menu-------------|" << endl;
        cout << "1. Tambah produk skincare baru" << endl;
        cout << "2. Ubah produk skincare" << endl;
        cout << "3. Hapus produk skincare" << endl;
        cout << "4. Tampilkan produk skincare" << endl;
        cout << "5. Keluar dari program" << endl;
        cout << "Pilihan anda: ";
        cin >> pilih;

        // Langsung melakukan validasi input dalam kondisi if
        if (pilih < 1 || pilih > 5)
        {
            cout << "Input tidak valid. Masukkan angka antara 1 dan 5." << endl;
            cout << "Ketikkan 'y' untuk kembali ke menu utama atau angka antara 1 dan 5: ";
            cin.clear();
            cin >> loop;

            // Jika pengguna memilih untuk kembali ke menu utama, lanjutkan ke iterasi berikutnya dari loop
            if (loop == "y")
            {
                continue;
            }
        }

        switch (pilih)
        {
        case 1:
            tambah();
            break;
        case 2:
            ubah();
            break;
        case 3:
            hapus();
            break;
        case 4:
            do
            {
                tampilkan();
                cout << "Kembali ke menu utama ketik (y): ";
                cin >> loop;
            } while (loop != "y");
            break;
        case 5:
            cout << "Program Selesai, bye bye...";
            break;
        default:
            cout << "Pilih 1-5" << endl;
            break;
        }
    } while (pilih != 5);

    return 0;
}
