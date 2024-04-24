
void searchAscending(Skincare arr[], int n, string key) {
    int result = binarySearchAscending(arr, 0, n - 1, key);
    if (result == -1)
        cout << "Produk tidak ditemukan." << endl;
    else
        cout << "Produk ditemukan pada indeks " << result + 1 << endl;
}