/*
	Yasir Seyrek
	Github: https://github.com/yasirsey
	Medium: https://medium.com/@yasirsey
*/

#include <stdio.h>
#include <stdlib.h> //malloc() ve free() fonksiyonları için.

//Düğüm Yapımızı Oluşturuyoruz

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL; //İlk Elemanı Tutuyoruz

//Sona Eleman Ekleme Fonksiyonu

void lastinsert(){
    int number;
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); //malloc ile struct node boyutunda alan ayırım type casting yaptık.
    printf("Sona eklenecek sayiyi girin:");
    scanf("%d",&number);
    new_node->data = number;
    new_node->next = NULL;
    if(head == NULL){	//Head NULL ise hiç eleman yok demektir dolayısıyla başa ekliyoruz yeni düğümü.
        head = new_node;
        printf("%d sayisi sona eklendi.\n",number);
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        printf("%d sayisi sona eklendi.\n",number);
    }
}

//Liste Elemanlarını Ekrana Bastırma Fonksiyonu

void print(){
    struct node* temp = head;
    if(head==NULL){
        printf("Liste bos.\n");
    }
    else{
        printf("Sirali liste elemanlari:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

//Başa Eleman Ekleme Fonksiyonu

void firstinsert(){
    int number;
    printf("Lutfen basa eklenecek sayiyi girin:");
    scanf("%d",&number);
    struct node* new_node = (struct node*)(malloc(sizeof(struct node)));
    new_node->data = number;
    new_node->next = head;
    head = new_node;
    printf("%d sayisi basa eklendi.\n",number);
}

//Araya Eleman Ekleme Fonksiyonu (Indexe Göre)

void outinsert(){
    int index,number,counter;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Kacinci siraya girilecek:");
    scanf("%d",&index);
    printf("%d. siraya girilecek sayiyi girin:",index);
    scanf("%d",&number);
    new_node->data = number;
    struct node* temp = head;
    counter = 0;
    while(temp!=NULL){
        if(counter == index-1){
            break;
        }
        temp = temp->next;
        counter++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    printf("%d sayisi %d siraya eklendi.\n",number,index);
}

//Baştan Eleman Silme Fonksiyonu

void firstdelete(){
    if(head==NULL){
        printf("Liste bos.\n");
        return;
    }
    struct node* temp = head;
    head = temp->next;
    free(temp);
    printf("Bastaki sayi silindi.\n");
}

//Sondan Eleman Silme Fonksiyonu

void lastdelete(){
    if(head==NULL){
        printf("Liste bos.\n");
        return;
    }
    struct node* temp = head;
    if(temp->next == NULL){
        head = NULL;
        free(head);
        printf("Sondaki sayi silindi.\n");
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Sondaki sayi silindi.\n");
}

//İndexe Göre Eleman Silme Fonksiyonu

void deletebyindex(){
    struct node* temp = head;
    int index;
    printf("Silinecek indexi giriniz:");
    scanf("%d",&index);
    if(index==0){
        head = temp->next;
        free(temp);
        printf("%d. indexteki eleman silindi.\n",index);
        return;
    }
    for(int i=0;i<index-1;i++){
        temp = temp->next;
    }

    struct node* temp2 = temp->next->next;
    free(temp->next);
    temp->next = temp2;
    printf("%d. indexteki eleman silindi.\n",index);
}

//Girilen Sayıya Göre Eleman Silme Fonksiyonu

void deletebyelement(){
    int number,flag=0;
    printf("Silmek istediginiz sayiyi giriniz:");
    scanf("%d",&number);
    struct node* temp = head;
    if(number==head->data){
        head = temp->next;
        free(temp);
        printf("%d sayisi silindi.\n",number);
        return;
    }
    while(temp->next!=NULL){
        if(temp->next->data==number){
                flag = 1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("Boyle bir sayi yok.");
        return;
    }
    struct node* temp2 = temp->next->next;
    free(temp->next);
    temp->next = temp2;
    printf("%d sayisi silindi.\n",number);
}

//Ters Çevirme Fonksiyonu

void traverse(){
    struct node* temp = head;
    struct node* before = NULL;
    struct node* after = NULL;
    while(temp!=NULL){
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
    head = before;
}

int main()
{

    //Menü Yapısı
    int choice;
    while(1){
        printf("\n**********\n1-Yazdir\n2-Sona Eleman Ekle\n3-Basa Eleman Ekle\n4-Araya Eleman Ekle\n5-Bastan Eleman Sil\n6-Sondan Eleman Sil\n7-Indexe Gore Sil\n8-Elemana Gore Sil\n9-Ters Cevir\n\nLutfen bir secim yapiniz:");
        scanf("%d",&choice);
        switch(choice){
        case (1):
            system("clear"); //Ekran Geçmişini Silmek için kullandım. Linux için clear Windows için CLS yazmanız gerekli.
            print();
            break;
        case (2):
            system("clear");
            lastinsert();
            break;
        case (3):
            system("clear");
            firstinsert();
            break;
        case (4):
            system("clear");
            outinsert();
            break;
        case (5):
            system("clear");
            firstdelete();
            break;
        case (6):
            system("clear");
            lastdelete();
            break;
        case (7):
            system("clear");
            deletebyindex();
            break;
        case (8):
            system("clear");
            deletebyelement();
            break;
        case (9):
            system("clear");
            traverse();
            break;
        }
    }

	return 0;
}
