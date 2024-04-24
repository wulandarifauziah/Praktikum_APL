#include <iostream>
#include <cstdlib>
using namespace std;

#define maksimal 15

// struct untuk menyimpan informasi skincare
struct Skincare
{
    string namaProduk;
    string jenisProduk;
    int harga;
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
            cout << a + 1 << ". Nama: " << dataSkincare[a].namaProduk << " Jenis: " << dataSkincare[a].jenisProduk << " Harga: " << dataSkincare[a].harga << endl;
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
            cout << "Masukkan harga produk: ";
            cin >> dataSkincare[awal].harga;
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

void ubah(Skincare *produk)
{
    cin.ignore(); // Bersihkan buffer
    cout << "Ubah nama produk: ";
    getline(cin, produk->namaProduk);
    cout << "Ubah jenis produk: ";
    getline(cin, produk->jenisProduk);
    cout << "Ubah harga produk: ";
    cin >> produk->harga;
}

void hapus(Skincare *produk)
{
    for (int i = 0; i < awal; i++)
    {
        if (&dataSkincare[i] == produk)
        {
            for (int j = i; j < awal - 1; j++)
            {
                dataSkincare[j] = dataSkincare[j + 1];
            }
            awal--;
            cout << "Data berhasil dihapus." << endl;
            break;
        }
    }
}

void insertionSortAscending(Skincare arr[], int n)
{
    int i, j;
    Skincare key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Pindahkan elemen dari arr[0..i-1] yang lebih besar dari key ke satu posisi ke depan dari posisi mereka sekarang */
        while (j >= 0 && arr[j].harga > key.harga)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortAscending(Skincare arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].namaProduk > arr[j + 1].namaProduk)
            {
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                Skincare temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSortDescending(Skincare arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].namaProduk > arr[maxIndex].namaProduk)
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            Skincare temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int binarySearchAscending(Skincare arr[], int l, int r, string x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        // Cek jika elemen berada di tengah
        if (arr[mid].namaProduk == x)
            return mid;

        // Jika elemen yang dicari lebih besar, abaikan setengah kiri
        if (arr[mid].namaProduk < x)
            l = mid + 1;

        // Jika elemen yang dicari lebih kecil, abaikan setengah kanan
        else
            r = mid - 1;
    }

    // Jika elemen tidak ditemukan
    return -1;
}

int binarySearchDescending(Skincare arr[], int l, int r, string x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        // Cek jika elemen berada di tengah
        if (arr[mid].namaProduk == x)
            return mid;

        // Jika elemen yang dicari lebih kecil, abaikan setengah kiri
        if (arr[mid].namaProduk < x)
            r = mid - 1;

        // Jika elemen yang dicari lebih besar, abaikan setengah kanan
        else
            l = mid + 1;
    }

    // Jika elemen tidak ditemukan
    return -1;
}

void searchAscending(Skincare arr[], int n, string key)
{
    int result = binarySearchAscending(arr, 0, n - 1, key);
    if (result == -1)
        cout << "Produk tidak ditemukan." << endl;
    else
        cout << "Produk ditemukan pada indeks " << result + 1 << endl;
}

void searchDescending(Skincare arr[], int n, string key)
{
    int i;
    bool found = false;
    for (i = n - 1; i >= 0; i--)
    {
        if (arr[i].namaProduk == key)
        {
            cout << "Produk ditemukan pada indeks " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Produk tidak ditemukan." << endl;
}

void tampilkanNamaProduk(Skincare arr[], int n)
{
    cout << "Nama-nama produk skincare yang tersedia:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << arr[i].namaProduk << endl;
    }
    cout << endl;
}

int main()
{
    if (!login())
    {
        return 1;
    }

    string searchKey;

    int pilih;
    do
    {
        system("cls");
        cout << "|-------------Menu-------------|" << endl;
        cout << "1. Tambah produk skincare baru" << endl;
        cout << "2. Ubah produk skincare" << endl;
        cout << "3. Hapus produk skincare" << endl;
        cout << "4. Tampilkan produk skincare" << endl;
        cout << "5. Cari produk skincare" << endl;
        cout << "6. Keluar dari program" << endl;
        cout << "Pilihan anda: ";
        cin >> pilih;

        // Langsung melakukan validasi input dalam kondisi if
        if (pilih < 1 || pilih > 6)
        {
            cout << "Input tidak valid. Masukkan angka antara 1 dan 6." << endl;
            cout << "Ketikkan 'y' untuk kembali ke menu utama atau angka antara 1 dan 6: ";
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
            if (awal == 0)
            {
                cout << "Tidak ada data skincare yang tersedia." << endl;
                cout << "Kembali ke menu utama..." << endl;
                break;
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

            ubah(&dataSkincare[x - 1]);
            cout << "Data berhasil diubah." << endl;
            break;
        case 3:
            if (awal == 0)
            {
                cout << "Tidak ada data skincare yang tersedia." << endl;
                cout << "Kembali ke menu utama..." << endl;
                break;
            }
            int y;
            tampilkan();
            cout << "Hapus data ke: ";
            cin >> y; // Error handling untuk memastikan input adalah angka dan dalam rentang yang benar
            while (cin.fail() || y < 1 || y > awal)
            {
                cin.clear();
                cout << "Input tidak valid. Masukkan angka antara 1 dan " << awal << ": ";
                cin >> y;
            }

            hapus(&dataSkincare[y - 1]);
            break;
        case 4:
            do
            {
                system("cls");
                cout << "|---------Tampilkan Produk---------|" << endl;
                cout << "1. Tampilkan produk skincare (Ascending)" << endl;
                cout << "2. Tampilkan produk skincare (Descending)" << endl;
                cout << "3. Tampilkan produk skincare (Ascending Harga)" << endl;
                cout << "Pilihan anda: ";
                int subPilih;
                cin >> subPilih;
                switch (subPilih)
                {
                case 1:
                    bubbleSortAscending(dataSkincare, awal);
                    tampilkan();
                    break;
                case 2:
                    selectionSortDescending(dataSkincare, awal);
                    tampilkan();
                    break;
                case 3:
                    insertionSortAscending(dataSkincare, awal);
                    tampilkan();
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
                }
                cout << "Kembali ke menu utama ketik (y): ";
                cin >> loop;
            } while (loop != "y");
            break;
        case 5:
            tampilkanNamaProduk(dataSkincare, awal);
            cout << "Masukkan nama produk yang ingin dicari: ";
            cin.ignore();
            getline(cin, searchKey);
            do
            {
                system("cls");
                cout << "|-------------Cari Produk-------------|" << endl;
                cout << "1. Cari pada data yang terurut secara ascending" << endl;
                cout << "2. Cari pada data yang terurut secara descending" << endl;
                cout << "Pilihan anda: ";
                int searchChoice;
                cin >> searchChoice;
                switch (searchChoice)
                {
                case 1:
                    searchAscending(dataSkincare, awal, searchKey);
                    break;
                case 2:
                    searchDescending(dataSkincare, awal, searchKey);
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
                }
                cout << "Kembali ke menu utama ketik (y): ";
                cin >> loop;
            } while (loop != "y");
            break;
        case 6:
            cout << "Program Selesai, bye bye...";
            break;
        default:
            cout << "Pilih 1-6" << endl;
            break;
        }
    } while (pilih != 6);

    return 0;
}
