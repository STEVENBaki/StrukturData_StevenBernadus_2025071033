#include <stdio.h>
#include <stdlib.h>

struct Node{
    int nilai;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

// insert diawal
void insertAwal(int nilai){
    struct Node *baru = (struct Node*)malloc(sizeof (struct Node));

    baru->nilai = nilai;
    baru->prev = NULL;
    baru->next = head;

    if(head != NULL){
        head->prev = baru;
    }
    head = baru;
}

//insert diakhir
void insertAkhir(int nilai){
    struct Node *baru = (struct Node*)malloc(sizeof (struct Node));
    struct Node *temp = head;

    baru->nilai = nilai;
    baru->next = NULL;

    if(head == NULL){
        baru->prev = NULL;
        head = baru;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = baru;
    baru->prev = temp;
}

//fungsi hapus di awal
void hapusAwal(){
    if(head == NULL){
        printf("List nilai kosong\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
}

//untuk menampilkan data
void tamplilist(){
    struct Node *temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->nilai);
        temp = temp->next;
    }
    printf("NULL\n");
}
//menu programnya

int main(){
    int pilihan,nilai;
    do{
        printf("\nMENU\n");
        printf("1. Tambah data di Awal\n");
        printf("2. Tambah data di Akhir\n");
        printf("3. Deletion di Awal\n");
        printf("4. Tampilkan Data\n");
        printf("5. Keluar\n");
        printf("pilih: ");
        scanf("%d",&pilihan);

        switch(pilihan){

        case 1:
            printf("Masukan data: ");
            scanf("%d",&nilai);
            insertAwal(nilai);
            break;

        case 2:
            printf("Masukan data: ");
            scanf("%d",&nilai);
            insertAkhir(nilai);
            break;

        case 3:
            hapusAwal();
            break;

        case 4:
            tamplilist();
            break;
        }

    }while(pilihan !=5);
    return 0;
}
