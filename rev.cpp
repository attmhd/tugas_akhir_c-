#include<iostream>
#include<vector>
using namespace std;

//struct mahasiswa
struct mahasiswa
{
    vector<string>nama, nim;
    
    vector<float>ipk;

};

//variabel
string nama, nim;
char continues;
int length,i, n, id,j, pil, input;
float ipk, uts, tgs, uas, present, ttl_nilai;
enum choices{selesai = 0, create_data_mhs,tampilkan_data_mhs, update, hapus};
mahasiswa mhs;

//modular

int choices(){
    system("clear");
    cout << "           SiMahasiswa         " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Entri Data Mahasiswa" << endl;
    cout << "2. Tampilkan Data Mahasiswa" << endl;
    cout << "3. Update Data Mahasiswa" << endl;
    cout << "4. Hapus Data Mahasiswa" << endl;
    cout << "0. Selesai" << endl;
    cout << "Masukkan pilihan anda 0 - 6    : "; cin  >> input;

    return input;
}

void entriData(){
    system("clear");
    cout << "Masukkan jumlah data yang akan diinput : ";
    cin >> n;

            
    for(i = 0;i < n; i ++){
        cout << "Masukkan Nama Mahasiswa ke- " << i + 1 << " : ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM Mahasiswa : " ;
        cin >> nim;
                
        cout << "Masukkan Nilai Tugas : ";
        cin >> tgs;
        cout << "Masukkan Nilai Kehadiran : ";
        cin >> present;
        cout << "Masukkan Nilai UTS : ";
        cin >> uts;
        cout << "Masukkan Nilai UAS : ";
        cin >> uas;

        ttl_nilai = 0.2 * tgs + 0.1 * present + 0.3 * uts + 0.4 * uas;
        if((ttl_nilai <= 100)and(ttl_nilai >= 90)){
            ipk = 4;
        }
        else if((ttl_nilai >= 85)and(ttl_nilai < 90)){
            ipk = 3.75;
        }
        else if((ttl_nilai >= 80)and(ttl_nilai < 85)){
            ipk = 3.5;
        }
        else if((ttl_nilai >= 75)and(ttl_nilai < 85)){
            ipk = 3.25;
        }
        else if((ttl_nilai >= 70)and(ttl_nilai <75)){
            ipk = 3;
        }
        else if((ttl_nilai >= 65)and(ttl_nilai <70)){
            ipk = 2.75;
        }
        else if((ttl_nilai >= 55)and(ttl_nilai <65)){
            ipk = 2.5;
        }
        else if((ttl_nilai >= 40)and(ttl_nilai <55)){
            ipk = 2;
        }
        else if((ttl_nilai >= 30)and(ttl_nilai <40)){
            ipk = 1;
        }
        else if((ttl_nilai >= 0)and(ttl_nilai <30)){
            ipk = 0;
        };
                                
                
        mhs.nama.push_back(nama);
        mhs.nim.push_back(nim);
        mhs.ipk.push_back(ipk);

        cout << "Input data selesai ....." << endl;
    };

    system("sleep 5s");
}

void tampilData(){
    system("clear");
    cout << "       ID      |       NAMA        |       NIM     |       IPK     " << endl;
    cout << "====================================================================" << endl;
            
    for(i = 0; i < length; i++){
        cout << i + 1 << "      |       " << mhs.nama[i] << "       |       " << mhs.nim[i] << "        |       "  << mhs.ipk[i] << endl;
    };
    system("sleep 10s");
}

void deleteData(){
    system("clear");
    cout << "Masukkan id yang akan di hapus : " ;
    cin >> id;
    j = id - 1;

    if(j < length){
        mhs.nama.erase(mhs.nama.begin()+j);
        mhs.nim.erase(mhs.nim.begin()+j);
        mhs.ipk.erase(mhs.ipk.begin()+j);

        cout << "ID ke- " << id << " berhasil dihapus..." << endl;

    }
    else{
        cout << "ID yang anda masukkan out of context";
    };
    system("sleep 5s");
}

void updateData(){
    system("clear");
    cout << "Masukkan id yang akan di update : ";
    cin >> id;
    j = id - 1;
            
    if(j < length){
        cout << "Pilih data yang akan di update : " << endl;
        cout << "1. Nama" << endl;
        cout << "2. NIM" << endl;
        cout << "3. IPK" << endl;
        cout << "Masukkan pilihan : "; cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "Masukkan nama Mahasiswa : "; 
            getline(cin >> ws, mhs.nama[j]);
            break;
        case 2:
            cout << "Masukkan NIM Mahasiswa :   ";
            cin >> mhs.nim[j];
            break;
        case 3:
            cout << "Masukkan NIM Mahasiswa :   ";
            cin >> mhs.nim[j];
            break;
        default:
            cout << "Pilihan out of context..." << endl;
            break;
        }
                
    }
    else{
        cout << "ID yang anda masukkan out of context" << endl;
    };
    system("sleep 3s");

}



int main(){

    do{
        choices();

        length = mhs.nama.size();

        //pengkondisian
        switch (input)
        {
        case create_data_mhs:
            entriData();
            break;
        case tampilkan_data_mhs:
            tampilData();
            break;
        case update:
            updateData();            
            break;
        case hapus:
            deleteData();
            break;
        default:
            // cout << "Pilihan out of context..." << endl;
            break;
        }    
    }while (input != selesai);
    

}