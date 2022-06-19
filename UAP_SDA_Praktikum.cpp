#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct node {
   int data;
   struct node *next;
};

struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

void Insert() {
    int val, urut = 1;
    string menu[6] = {"Ayam geprek", "Kwetiau", "Es teh", "Es jeruk", "Jus melon", "Jus Semangka"};
   
    cout << "==================" << endl;
    cout << "|      MENU      |" << endl;
    cout << "==================" << endl;
    cout << "|1. Ayam geprek  |" << endl;
    cout << "|2. Kwetiau      |" << endl;
    cout << "|3. Es teh       |" << endl;
    cout << "|4. Es jeruk     |" << endl;
    cout << "|5. Jus melon    |" << endl;
    cout << "|6. Jus semangka |" << endl;
    cout << "==================" << endl;
    cout << "Masukan pilihan menu : ";
    cin >> val;

    if (rear == NULL) {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = val;
        front = rear;
    } else {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "|          NO. ANTRIAN          |" << endl;
    cout << "|               " << urut << "               |" << endl;
    cout << "---------------------------------" << endl;
    cout << "|         PILIHAN MENU          |" << endl;
    cout << "|         " << menu[(val-1)] << "               |" << endl;
    cout << "---------------------------------" << endl;
    cout << "|       Silahkan Mengantri      |" << endl;
    cout << "---------------------------------" << endl;
    urut++;
}

void Delete() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Antrian menu yang dihapus adalah : "<<front->data<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Antrian menu yang dihapus adalah : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}

void Display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Antrian kosong"<<endl;
      return;
   }
   cout<<"Antrian menu : ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}

int main() {
   int ch;

   do {
        system("CLS");
        cout << "-----------------------------" << endl;
        cout << "|     Selamat Datang di     |" << endl;
        cout << "|        RM. Bersama        |" << endl;
        cout << "-----------------------------" << endl;
        cout << "| 1) Ambil Antrian          |" << endl;
        cout << "| 2) Keluarkan Antrian      |" << endl;
        cout << "| 3) Tampilkan Semua Antrian|" << endl;
        cout << "| 4) Exit                   |" << endl;
        cout << "-----------------------------" << endl;
        cout << "Masukan pilihan : ";
        cin  >> ch;

        switch (ch) {
            case 1: 
                system("CLS");
                Insert();
			    getche();
                break;
            case 2: 
                Delete();
                getche();
                break;
            case 3: 
                Display();
                getche();
                break;
            case 4: 
                cout<<"Exit"<<endl;
                getche();
                break;
            default: 
                cout<<"Invalid choice"<<endl;
        }
    } while(ch!=4);

    return 0;
}