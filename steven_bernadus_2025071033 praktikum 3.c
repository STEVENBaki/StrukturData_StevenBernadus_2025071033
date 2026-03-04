#include <stdio.h>
#include <stdlib.h>

// Definisi struct node
struct Node {
    int data;
    struct Node *next;
};

// Fungsi menampilkan isi list
void tampilkanList(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List kosong\n");
        return;
    }

    printf("Isi Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Tambah node di awal
void tambahAwal(struct Node **head, int nilai) {
    struct Node *nodeBaru = malloc(sizeof(struct Node));
    nodeBaru->data = nilai;
    nodeBaru->next = *head;
    *head = nodeBaru;
}

// Tambah node di akhir
void tambahAkhir(struct Node **head, int nilai) {
    struct Node *nodeBaru = malloc(sizeof(struct Node));
    nodeBaru->data = nilai;
    nodeBaru->next = NULL;

    if (*head == NULL) {
        *head = nodeBaru;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

// Hapus node berdasarkan nilai
void hapusNode(struct Node **head, int nilai) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Jika node yang dihapus adalah head
    if (temp != NULL && temp->data == nilai) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Cari node yang ingin dihapus
    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    // Jika nilai tidak ditemukan
    if (temp == NULL) {
        printf("Nilai tidak ditemukan\n");
        return;
    }

    // Hapus node
    prev->next = temp->next;
    free(temp);
}

// Program utama
int main() {
    struct Node *head = NULL;

    // Membuat minimal 5 node
    tambahAkhir(&head, 10);
    tambahAkhir(&head, 20);
    tambahAkhir(&head, 30);
    tambahAkhir(&head, 40);
    tambahAkhir(&head, 50);

    tampilkanList(head);

    // Tambah di awal
    tambahAwal(&head, 5);
    printf("Setelah tambah di awal:\n");
    tampilkanList(head);

    // Tambah di akhir
    tambahAkhir(&head, 60);
    printf("Setelah tambah di akhir:\n");
    tampilkanList(head);

    // Hapus node berdasarkan nilai
    hapusNode(&head, 30);
    printf("Setelah hapus nilai 30:\n");
    tampilkanList(head);

    return 0;
}
