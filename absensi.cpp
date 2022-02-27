#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstring>

using namespace std ;

class mahasiswa {
    public :
    char nama [50];
    char kehadiran ;
    int hadir =0;
    int nrp;
    float persen ;
};
mahasiswa mhs [30];
void dataMasuk (int  i){

    ofstream datamhs ("data.dat");// membuat database 
    cout << "input data mahasiswa : "<< i+1 <<endl;
    cout << "input nrp : "; cin >> mhs[i].nrp ;
    cout << "input nama mahasiswa : "; cin >> mhs[i].nama;

    datamhs.write ((char*)&mhs , sizeof (mhs)); //menyimpan data
    datamhs.close ();//menutup data 
}

void rekapData (int banyakMhs ){
    int i ,j ;
    int banding ;
    ifstream filerekap ("data.dat ");
    filerekap ((char*)&mhs ,sizeof(mhs));
    cout << "nrp \t\t\t nama \t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10";
    for (i =0 < banyakMhs ; i++){
        cout <<mhs[i].nrp <<"\t" << mhs[i].nama <<"\t\t\t";
        for (j=0 ;j<10 ;j++){
            cout << mhs[i].kehadiran [j] << "\t";
            banding = _strcmpi(mhs[i].kehadiran[j] << "H" );
            if (banding == 0){
                mhs[i],hadir +=1;

            }
        }
        mhs[i].persen = mhs[i].hadir  *100/10;
        cout << mhs[i].persen;
        cout << endl ;

    }
    filerekap.close ();//menutup data 
}s

void datapresensi (int j ,int minggu ){
    ifstream bukadata ("data.dat");
    bukadata.read ((char*)&mhs ,sizeof (mhs ));
    cout << mhs[j].nrp <<"\t "<< mhs[j].nama <<"\t" ;
    cout << "\t kehadiran H/A/I/S : ";
    fflush (stdin ); //menghapus buffer 

    ofstream simpandata ("data.dat ");
    simpandata.write ((char *)&mhs ,sizeof(mhs ));

    bukadata.close();
    simpandat.close();
}

int main (){
    int i ,n= 3;
    int x ; int minggu =0;
    
    int pilihan ;
    char lagi ;
    cout << "pilih opsi : "<<endl;
    cout << "1.masukan data mahasiswa " << endl ;
    cout << "2. presensi mahasiswa ";
    cout  << "3.rekap data ";
    cin >> pilihan;
    system ("cls");
    switch (pilihan ){
        case 1 : {
            for (i=0;i< n; i++ ){
                dataMasuk(i);
                system("cls");

            }
        }break ;
        case 2 : {
            do {
                cout << "absensi minggu "<< minggu +1 << endl ;
                for (x=0;x< n;x++ ){
                    datapresensi (x, minggu );

                }
                cout << "absensi minggu berikutnya [y/n] : ";
                cin >> lagi ;
                minggu ++ ;

             }while (lagi =='y'  || lagi =='Y');

        }break ;
        case  3 : {
            rekapData(n);
        }break ;
        default : cout << "pilihan salah " << endl ;

    }
    _getch();
}