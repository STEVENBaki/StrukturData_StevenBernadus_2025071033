#include<stdio.h>
int main(){
    // Bagian Pertama 1 - LOOPING DASAR
    printf("Bagian 1 Looping Dasar\n"); // judul program
    printf("\nMenamplikan Angka 1 sampai 10\n");
    for(int i = 1; i <=10; i++){ //pengulangan 1 sampai 10
    printf("%d ", i);
    }

    printf("\n\nMenamplikan Angka 1 sampai 50\n"); //pengulangan 1 sampai 50
    for(int i = 1; i <=50; i++){
            if(i % 2 == 0){
    printf("%d ", i);}
    }
    //Bagian Kedua 2 - PERHITUNGAN JUMLAH
    printf("\n\nBagian 2 Perhitungan Jumlah\n");
    int N,jumlah = 0;
    printf("Masukan Nilai N: ");
    scanf("%d", &N);
    for(int i = 1; i <=N;i++){ //pengulangan 1 sampai N
    jumlah += i; // tambahkan i ke variabel jumlah
    }
    printf("Jumlah Bilangan dari 1 sampai %d adalah : %d\n\n", N, jumlah);

    // Bagian ketiga 3 – Array dan Rata-rata


    printf("\nBagian 3 Array dan Rata-rata\n");

    int nilai[5];   // Array untuk menyimpan 5 nilai
    int total = 0;  // Variabel untuk menyimpan total nilai
    float rata;     // Variabel untuk menyimpan rata-rata

    // Input 5 nilai dari user
    for(int i = 0; i < 5; i++) {
        printf("Masukkan nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);   // Simpan ke array
        total += nilai[i];        // Tambahkan ke total
    }

    // Hitung rata-rata
    rata = total / 5.0;   // 5.0 agar hasil berupa desimal

    // Tampilkan hasil
    printf("Total nilai: %d\n", total);
    printf("Rata-rata nilai: %.2f\n", rata);

    return 0;   // Program selesai
}
