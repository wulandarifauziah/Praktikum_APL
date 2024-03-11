#include <iostream>
#include <cstdlib>
using namespace std;

#define maksimal 15
string skincare[maksimal], jenisProduk[maksimal], loop;
int awal = 0;

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
            cout << a + 1 << ". Nama: " << skincare[a] << " Jenis: " << jenisProduk[a] << endl;
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
            cin.ignore();
            cout << "Masukkan nama produk: ";
            getline(cin, skincare[awal]);
            cout << "Masukkan jenis produk: ";
            getline(cin, jenisProduk[awal]);
            awal++;
            cout << "Ulangi lagi (y/t): ";
            cin >> loop;
        }
        else
        {
            cout << "Data sudah penuh" << endl;
            cout << "Ketik t untuk kembali: ";
            cin >> loop;
        }
    } while (loop == "y");
}

void ubah()
{
    int x;
    do
    {
        tampilkan();
        cout << "Ubah data ke: ";
        cin >> x;
        if (x >= 1 && x <= awal)
        {
            cin.ignore();
            cout << "Ubah nama produk: ";
            getline(cin, skincare[x - 1]);
            cout << "Ubah jenis produk: ";
            getline(cin, jenisProduk[x - 1]);
            cout << "Mau mengubah lagi? (y/t): ";
            cin >> loop;
        }
        else
        {
            cout << "Index tidak valid. Masukkan index angka " << awal << endl;
            loop = "y";
        }
    } while (loop == "y");
}

void hapus()
{
    int x;
    do
    {
        tampilkan();
        cout << "Hapus data ke: ";
        cin >> x;
        if (x >= 1 && x <= awal)
        {
            for (int i = x - 1; i < awal - 1; i++)
            {
                skincare[i] = skincare[i + 1];
                jenisProduk[i] = jenisProduk[i + 1];
            }
            awal--;
            cout << "hapus lagi(y/t): " << endl;
            cin >> loop;
        }
        else
        {
            cout << "Input tidak valid. ketik y untuk menghapus lagi atau t untuk kembali: ";
            cin >> loop;
        }
    } while (loop == "y");
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
            cout << "";
            break;
        default:
            cout << "Pilih 1-5" << endl;
            break;
        }
    } while (pilih != 5);
    cout << "Program Selesai, byee byee...";
    return 0;
}