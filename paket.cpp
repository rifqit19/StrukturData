#include <iostream>
#include <stdlib.h>

//library conio.h dan windows.h tidak bisa untuk OS mac karena MinGW merupakan Minimalist GNU for Windows dah hanya berjalan di Windows.
// #include<conio.h>
// #include<windows.h>


void gotoxy(int x, int y)
{

    
    /* library windows.h tidak bekerja pada operating system mac
    
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("\033[%d;%dH", y, x);*/

    // alternatif pengganti gotoxy dari lib windows.h dengan ANSI code
    printf("%c[%d;%df", 0x1B, y, x);

}

using namespace std;

struct paket
{
    int top;
    string jenis_brg[30];
    int berat[5];
    string kota[30];

};

paket kirim;


void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}



void inisialisasi()
{
    kirim.top=-1;
}

int IsEmpty()
{
    if(kirim.top==-1)
    {
        return 1;

    }else
    {
        return 0;
    }
}

int IsFull()
{
    if (kirim.top==9)
    {
        return 1;

    }else
     {
        return 0;

     }

}

void push(string jns_brg, int berat, string kota)
{
    kirim.top++;
    kirim.jenis_brg[kirim.top]=jns_brg;
    kirim.berat[kirim.top]=berat;
    kirim.kota[kirim.top]=kota;
}

void pop()
{
    kirim.top=kirim.top-1;
    if(kirim.top<0)
    {
        kirim.top=-1;
    }
}

int main ()
{
    int pilih, i, berat;
    string jenis,kota;
    inisialisasi();
    do{

        // bersihlayar();
        // gotoxy(1,1);
        cout<<"MENU UTAMA"<<endl;
        // gotoxy(1,2);
        cout<<"1. Tambah Data"<<endl;
        // gotoxy(1,3);
        cout<<"2. Hapus Data Terakhir"<<endl;
        // gotoxy(1,4);
        cout<<"3. Tampil Data"<<endl;
        // gotoxy(1,5);
        cout<<"4. Clear Data"<<endl;
        // gotoxy(1,6);
        cout<<"9. Keluar"<<endl;

        // gotoxy(1,8);
        cout<<"Pilihan Anda [1-9] : ";

        cout<<endl;
        cout<<"Pilih : ";
        cin>>pilih;

        switch(pilih)
        {
            case 1:
            {
                if(IsFull()==1)
                {
                    cout<<"Tumpukanan penuh !";
                }
                else
                {
                    
                    // gotoxy(20,15);
                    cout<<"Inputkan Jenis Barang    :";
                    cin>>jenis;
                    // gotoxy(20,16);
                    cout<<"Inputkan Berat           :";
                    cin>>berat;
                    // gotoxy(20,17);
                    cout<<"Inputkan Kota Tujuan     :";
                    cin>>kota;
                    push(jenis, berat, kota);
                }
                cout<<endl;
                getchar();
                break;
            }
            case 2:
            {
                if(IsEmpty()==1)
                {
                    cout<<"Tumpukanan Kosong !";
                }
                else
                {
                    // gotoxy(40,12);
                    cout<<"Data yang anda Hapus Adalah :"<<endl;
                    // gotoxy(40,13);
                    cout<<kirim.jenis_brg[kirim.top]<<" ";
                    // gotoxy(40,14);
                    cout<<kirim.berat[kirim.top]<<" Kg ";
                    // gotoxy(40,15);
                    cout<<kirim.kota[kirim.top]<<endl<<endl;
                    pop();
                }
                cout<<endl;
                getchar();
                break;
            }
            case 3:
            {
                if(IsEmpty()==1)
                {
                    cout<<"Tumpukanan Kosong !"<<endl;
                }
                else
                {
                    // gotoxy(40,10);
                    cout<<"Daftar Kiriman Paket"<<endl;
                    for(i=0; i<=kirim.top; i++)
                    {
                        cout<<i+1<<". ";
                        cout<<kirim.jenis_brg[i]<<" ";
                        cout<<kirim.berat[i]<<" ";
                        cout<<kirim.kota[i]<<" ";
                        cout<<endl;

                    }
                }
                cout<<endl;
                getchar();
                break;
            }
            case 4:
            {
                inisialisasi();
                cout<<"Tumpukanan Kosong !"<<endl;
                cout<<endl;
                getchar();
                break;
            }
        }
    } while (pilih!=9);
    getchar();
}
