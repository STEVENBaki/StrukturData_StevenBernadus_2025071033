#include <stdio.h>

// Function untuk menghitung total nilai
int hitungTotal(int arr[], int ukuran) {
    int total = 0;
    for(int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    return total;
}

// Function untuk menghitung rata-rata
float hitungRataRata(int arr[], int ukuran) {
    int total = hitungTotal(arr, ukuran);
    return (float) total / ukuran;
}

// Function untuk mencari nilai tertinggi
int nilaiTertinggi(int arr[], int ukuran) {
    int max = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int nilai[10];
    int ukuran = 10;

    // Input nilai
    printf("Masukkan 10 nilai:\n");
    for(int i = 0; i < ukuran; i++) {
        printf("Nilai ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // Pemanggilan function
    int total = hitungTotal(nilai, ukuran);
    float rata = hitungRataRata(nilai, ukuran);
    int tertinggi = nilaiTertinggi(nilai, ukuran);

    // Output terstruktur
    printf("\n===== HASIL PERHITUNGAN =====\n");
    printf("Total Nilai      : %d\n", total);
    printf("Rata-rata Nilai  : %.2f\n", rata);
    printf("Nilai Tertinggi  : %d\n", tertinggi);

    return 0;
}
