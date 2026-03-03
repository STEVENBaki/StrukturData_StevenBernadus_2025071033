#include<stdio.h>
#include<stdlib.h>
//definisi struct
struct Node {
int data;
struct Node *next;
};

// fungsi menambah data di awal code
void tambahData(struct Node **head, int nilai){
    struct Node *nodeBaru = malloc(sizeof(struct Node));

    if(nodeBaru == NULL){
        printf("Gagal alokasi memori\n");
        return;
    }


    nodeBaru->data = nilai;
    nodeBaru->next = *head; //harus *head
    *head = nodeBaru;

    printf("Data berhasil ditambahkan\n");
}
// Fungsi Tapil data
void tampilData(struct Node *head){
    if(head == NULL){
        printf("List kosong\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL){
       printf("%d -> ", temp->data);
       temp = temp->next;
    }
    printf("NULL\n");
}
//fungsi Hapus data (berdasarkan nilai)
void hapusData(struct Node **head, int nilai){
    if(*head == NULL){
        printf("List Kosong\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;


    // Jika data ada di head
    if(temp->data == nilai){
       *head = temp->next;
       free(temp);
       printf("Data berhasil dihapus!\n");
       return;
}
// Cari data
while(temp != NULL && temp->data != nilai){
    prev = temp;
    temp = temp->next;
}
if(temp == NULL){
    printf("Data tidak ditemukan\n");
    return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Data berhasil dihapus!\n");
}
int main(){
    struct Node *head = NULL;
    int pilihan, nilai;

    do{
        printf("\n========== MENU ==========\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampil Data\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
        case 1:
            printf("Masukkan Nilai: ");
            scanf("%d", &nilai);
            tambahData(&head, nilai);
            break;

        case 2:
            printf("Masukkan nilai yang akan dihapus: ");
            scanf("%d", &nilai);
            hapusData(&head, nilai);
            break;

        case 3:
            tampilData(head);
            break;

        case 4:
            printf("Program selesai.\n");
            break;

        default:
            printf("Pilihan tidak valid!");
        }
    } while(pilihan != 4);
    return 0;
}
