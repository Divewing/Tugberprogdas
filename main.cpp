#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <windows.h>

//Kelompok 4 : Zakat
//Insan M - 10111140
//Nadiar A S - 10111121

using namespace std;

// --------------   record ------------------- //

typedef struct{
	char nama[31];
	int rt,rw;
	char kampung[31];
	char kec[31];
	char jk;
	char pekerjaan[31];
}biodata;

typedef struct{
	int pil;
	int emas;
	int perak;
	int statmas;
	int statper;
	float uangmas;
	float uangper;
	float bzktmas;
	float bzktper;
}zakatemas;

typedef struct {
	int statprof;
    int income;
    int tunggakan;
    float zakat;
} zakatprof;

// -------------- array ----------------------//

int arr_id[10];
int arr_cnd[5];

// --------------   fungsi ------------------- //


void ukuranwindow(int lebar, int tinggi){
    _COORD kordinat;
    kordinat.X = lebar;
    kordinat.Y = tinggi;

    _SMALL_RECT rect;
    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = tinggi - 1;
    rect.Right = lebar - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, kordinat);
    SetConsoleWindowInfo(Handle, TRUE, &rect);
    }


biodata inptbio(){
	biodata inpt;
	cout << " Nama\t\t: ";
	 fflush(stdin);cin.get(inpt.nama,30);
	cout << " RT\t\t: ";
	 cin >> inpt.rt;
	cout << " RW\t\t: ";
	 cin >> inpt.rw;
	cout << " Kampung\t: ";
	 fflush(stdin);cin.get(inpt.kampung,30);
	cout << " Kecamatan\t: ";
	 fflush(stdin);cin.get(inpt.kec,30);
	do{
	cout << " Jenis Kelamin\n (L/P)\t\t: ";
	 cin >> inpt.jk;
	 if((toupper(inpt.jk) != 'L')&&(toupper(inpt.jk) != 'P')){
	 	cout << " Data yang anda inputkan tidak benar!! ";
	 }
	}while((toupper(inpt.jk) != 'L')&&(toupper(inpt.jk) != 'P'));
	cout << " Pekerjaan\t: ";
	 fflush(stdin);cin.get(inpt.pekerjaan,30);
	return inpt;
};

zakatemas hitmas(){
	const float kadar = 0.025;
	const int hrg_emas = 47000;
	const int hrg_perak = 1100;
	zakatemas f_hit;
	cout << " [1] Zakat Emas\t [2] Zakat Perak" <<endl;
	cout << " --------------------------------- " <<endl;
	cout << " Pilih: ";
	cin >> f_hit.pil;
	if(f_hit.pil == 1){
		f_hit.statmas = 1;
		cout << " Berat emas yang dimiliki (gr): ";
		cin >> f_hit.emas;
		f_hit.bzktmas = kadar * f_hit.emas;
		f_hit.uangmas = hrg_emas * f_hit.bzktmas;
		cout <<endl;

		return f_hit;
	} else if(f_hit.pil == 2 ){
		f_hit.statper = 1;
		cout << " Berat perak yang dimiliki (gr): ";
		cin >> f_hit.perak;
		f_hit.bzktper = kadar * f_hit.perak;
		f_hit.uangper = hrg_perak * f_hit.bzktper;
		cout <<endl;

		return f_hit;
	}

};


zakatprof hitprof(){
	zakatprof prof;
    char ans;
    float total;

    prof.statprof = 1;
    cout << " Total penghasilan bulan ini, Rp. "; cin >> prof.income;
    cout << "\n Apakah mempunyai tunggakan? [y/N] "; cin >> ans;
    //cout << "Jawab " << ans << endl;

    if ((ans == 'y') || (ans == 'Y')) {
        cout << " Tunggakan bulan ini, Rp. "; cin >> prof.tunggakan;
    } else{
        prof.tunggakan = 0;
    }

    // total =  upah bersih perbulan
    total = prof.income - prof.tunggakan;
    // Jika penghasilan per bulan 0 atau min, zakat = 0
    if (total <= 0){
        prof.zakat = 0.0;
    } else {
        prof.zakat = total * 0.25;
    }

	return prof;
};

zakatemas resetmas(){

		zakatemas f_hit;

		f_hit.pil = 0;
		f_hit.statmas = 0;
		f_hit.emas = 0;
		f_hit.bzktmas = 0;
		f_hit.uangmas = 0;
		f_hit.statper = 0;
		f_hit.perak = 0;
		f_hit.bzktper = 0;
		f_hit.uangper = 0;

		return f_hit;
};


zakatprof resetprof(){
	zakatprof prof;

    prof.statprof = 0;
    prof.income = 0;
    prof.tunggakan = 0;
    prof.zakat = 0.0;


	return prof;
};


int kat(){
	int ketemu = 0,cat;
	char pil;
	do{
		cout << " [1]. Nama"<<endl;
		cout << " [2]. Kampung"<<endl;
		cout << " [3]. Kecamatan"<<endl;
		cout << " [4]. Pekerjaan"<<endl;
		cout << " ---------------------------"<<endl;
		cout << " Cari berdasarkan : ";
		cin >> pil;
		switch(pil){
			case '1' :
				ketemu = 1;
				cat = 1;
				break;
			case '2' :
				ketemu = 1;
				cat = 2;
				break;
			case '3' :
				ketemu = 1;
				cat = 3;
				break;
			case '4' :
				ketemu = 1;
				cat = 4;
				break;
			default :
				cout << endl;
				cout << " Pilihan yang Anda masukan tidak terdaftar"<<endl;
				cout << " Tekan tombol sembarang untuk memilih kembali.. "<<endl;
				getch();
				cout << endl;
				break;
		}
	}while(ketemu!=1);

	return cat;
}

// --------------  prosedur ------------------- //

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tempoutdaf(biodata tempbio){

	cout << " Nama\t\t: "<<tempbio.nama<<endl;
	cout << " RT/RW\t\t: "<<tempbio.rt << "/"<<tempbio.rw<<endl;
	cout << " Kampung\t: "<<tempbio.kampung<<endl;
	cout << " Kecamatan\t: "<<tempbio.kec<<endl;
	cout << " Jenis Kelamin\t: "<<tempbio.jk<<endl;
	cout << " Pekerjaan\t: "<<tempbio.pekerjaan<<endl;

};


void tempubahdaf(biodata *tempbio){
	int pil;
	cout << "\n [1] Semua\t   [2] Nama"<<endl;
	cout << " [3] RT\t\t   [4] RW"<<endl;
	cout << " [5] Kampung\t   [6] Kecamatan"<<endl;
	cout << " [7] Jenis Kelamin [8] Pekerjaan"<<endl;
	cout << " -----------------------------------" << endl;
	cout << " Masukan No. yang akan disunting : ";
	cin >> pil;
	cout << endl;
	switch(pil){
		case 1:
			*tempbio = inptbio();
			break;
		case 2:
			cout << " Nama\t\t: ";
	 		fflush(stdin);cin.get(tempbio->nama,30);
	 		break;
	 	case 3:
	 		cout << " RT\t\t: ";
			cin >> tempbio->rt;
	 		break;
	 	case 4:
	 		cout << " RW\t\t: ";
	 		cin >> tempbio->rw;
	 		break;
	 	case 5:
	 		cout << " Kampung\t: ";
	 		fflush(stdin);cin.get(tempbio->kampung,30);
	 		break;
	 	case 6:
	 		cout << " Kecamatan\t: ";
	 		fflush(stdin);cin.get(tempbio->kec,30);
	 		break;
	 	case 7:
	 		cout << " Jenis Kelamin\n(L/P)\t\t: ";
	 		cin >> tempbio->jk;
	 		break;
	 	case 8:
	 		cout << " Pekerjaan\t: ";
	 		fflush(stdin);cin.get(tempbio->pekerjaan,30);
	 		break;
	 	default:
	 		cout << " Anda memasukan pilihan yang tidak tepat, mohon periksa lagi ";
	 		break;
	}
	cout << endl;
};


void tempoutmas(zakatemas tempmas){
	if(tempmas.pil == 1){
		cout << " Berat Emas yang dimiliki  : "<< tempmas.emas<<" gr"<<endl;
		cout << endl;
		cout << " --------------------------------------------------------" << endl;
		cout << " Berat Emas yang perlu dibayar  : "<< tempmas.bzktmas<<" gr"<<endl;
		cout << " Atau"<<endl;
		cout << " Besarnya uang yang perlu dibayar : Rp. "<<tempmas.uangmas << endl;
		cout << " --------------------------------------------------------" << endl;
		cout << endl;

	} else if(tempmas.pil == 2 ){
		cout << " Berat Perak yang dimiliki  : "<< tempmas.perak<<" gr"<<endl;
		cout << endl;
		cout << " --------------------------------------------------------" << endl;
		cout << " Berat Perak yang perlu dibayar  : "<< tempmas.bzktper<<" gr"<<endl;
		cout << " Atau"<<endl;
		cout << " Besarnya uang yang perlu dibayar : Rp. "<<tempmas.uangper << endl;
		cout << " --------------------------------------------------------" << endl;
		cout << endl;

	}


};


void tempoutprof(zakatprof tempprof){

    cout << "\n\n Zakat profesi bulan ini" << endl;
    cout << " --------------------------------------------------------" << endl;
    cout << " Total penghasilan bulan ini, Rp. " << tempprof.income << endl;
    cout << " Tunggakan bulan ini, Rp. " << tempprof.tunggakan << endl;
    cout << " --------------------------------------------------------" << endl;
    cout << " Total zakat penghasilan bulan ini Rp. " << tempprof.zakat << ",-" << endl;

};



// --------------   linked list ------------------- //

typedef struct node *alamatnode;
typedef struct node{
	int id;
	int bayar;
	biodata personal;
	zakatemas zktemas;
	zakatprof zktprof;
	alamatnode next;
}elemen;

typedef struct{
	elemen *awal;
}list;

void buatlist(list *L){
	(*L).awal = NULL;
}

int  lastid(list L){
	int id;
	if(L.awal != NULL){
		elemen *bantu = L.awal;
		while(bantu != NULL){
			id = bantu->id;
			bantu = bantu->next;
		}
		return id + 1;
	}else{
		return id = 1;
	}


};

void simpdata(int id, const char nama[],int rt, int rw,const char kampung[],const char kec[],char jk,const char pekerjaan[], list *L){
	elemen *node;
	node = (elemen *) malloc (sizeof (elemen));
	if((*L).awal == NULL){
		node->id = id;
		strcpy(node->personal.nama,nama);
		node->personal.rt = rt;
		node->personal.rw = rw;
		strcpy(node->personal.kampung,kampung);
		strcpy(node->personal.kec,kec);
		node->personal.jk = jk;
		strcpy(node->personal.pekerjaan,pekerjaan);
		node -> next = L->awal;
		L->awal = node;
		node = NULL;
	}else{
		node->id = id;
		strcpy(node->personal.nama,nama);
		node->personal.rt = rt;
		node->personal.rw = rw;
		strcpy(node->personal.kampung,kampung);
		strcpy(node->personal.kec,kec);
		node->personal.jk = jk;
		strcpy(node->personal.pekerjaan,pekerjaan);
		node -> next = NULL;

		elemen *buntut = L->awal;
		while(buntut->next != NULL){
			buntut = buntut->next;
		}
		buntut->next = node;
		node = NULL;
	}


};


void simpanbio(int id, biodata tempbio, list *L){
	elemen *node;
	node = (elemen *) malloc (sizeof (elemen));
	if((*L).awal == NULL){
		node->id = id;
		strcpy(node->personal.nama,tempbio.nama);
		node->personal.rt = tempbio.rt;
		node->personal.rw = tempbio.rw;
		strcpy(node->personal.kampung,tempbio.kampung);
		strcpy(node->personal.kec,tempbio.kec);
		node->personal.jk = tempbio.jk;
		strcpy(node->personal.pekerjaan,tempbio.pekerjaan);

		node->zktprof.statprof = 0;
		node->zktprof.income = 0;
    	node->zktprof.tunggakan = 0;
    	node->zktprof.zakat = 0;

		node->zktemas.statmas = 0;
		node->zktemas.emas = 0;
		node->zktemas.bzktmas = 0;
		node->zktemas.uangmas = 0;

		node->zktemas.statper = 0;
		node->zktemas.perak = 0;
		node->zktemas.bzktper = 0;
		node->zktemas.uangper = 0;

		node -> next = L->awal;
		L->awal = node;
		node = NULL;
	}else{
		node->id = id;
		strcpy(node->personal.nama,tempbio.nama);
		node->personal.rt = tempbio.rt;
		node->personal.rw = tempbio.rw;
		strcpy(node->personal.kampung,tempbio.kampung);
		strcpy(node->personal.kec,tempbio.kec);
		node->personal.jk = tempbio.jk;
		strcpy(node->personal.pekerjaan,tempbio.pekerjaan);

		node->zktprof.statprof = 0;
		node->zktprof.income = 0;
    	node->zktprof.tunggakan = 0;
    	node->zktprof.zakat = 0;

		node->zktemas.statmas = 0;
		node->zktemas.emas = 0;
		node->zktemas.bzktmas = 0;
		node->zktemas.uangmas = 0;

		node->zktemas.statper = 0;
		node->zktemas.perak = 0;
		node->zktemas.bzktper = 0;
		node->zktemas.uangper = 0;

		node -> next = NULL;

		elemen *buntut = L->awal;
		while(buntut->next != NULL){
			buntut = buntut->next;
		}
		buntut->next = node;
		node = NULL;
	}


};

void cari(list L, int arr_id[15],char menu_sub){
	if(L.awal != NULL){

		char inpt[31],band[31];
		int ketemu = 1,lkw,ctr=0,cat,j;

        /*
		if(menu_sub == '1'){
			j=6;
		}else if(menu_sub == '3'){
			j=22;
		}else if(menu_sub == '4'){
			j=16;
		}else if(menu_sub == '5'){
			j = 15;
		}
        */
        j = 6;
		cat = kat();

		cout << " \n Masukan kata kunci pencarian : ";
		fflush(stdin);cin.get(inpt,30);

		lkw = strlen(inpt);
		elemen *bantu = L.awal;
        system("cls");
        cout <<"\n                                                     Hasil Pencarian" << endl;
        cout <<"\n +------+---------------------------+-------+----------------------+----------------------+----+-------------------+" << endl;
        cout <<" | ID   | Nama                      | RT/RW | Kampung              | Kecamatan            | JK | Pekerjaan         |" << endl;
        cout <<" +------+---------------------------+-------+----------------------+----------------------+----+-------------------+" << endl;
		while(bantu != NULL){
				if(cat == 1){
					strcpy(band,bantu->personal.nama);
				}else if(cat == 2){
					strcpy(band,bantu->personal.kampung);
				}else if(cat == 3){
					strcpy(band,bantu->personal.kec);
				}else if(cat == 4){
					strcpy(band,bantu->personal.pekerjaan);
				}

			if(strnicmp(band,inpt,lkw) == 0){
				arr_id[ctr] = bantu->id;
				/*cout <<"Id\t\t\t: "<< bantu->id<<endl;
				cout <<"Nama\t\t: "<<  bantu->personal.nama <<endl;
				cout <<"RT/RW\t\t: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
				cout <<"Kampung\t\t: "<<bantu->personal.kampung<<endl;
				cout <<"Kecamatan\t: "<<bantu->personal.kec<<endl;
				cout <<"Jenis Kelamin\n(L/P)\t\t: "<<bantu->personal.jk<<endl;
				cout <<"Pekerjaan\t: "<<bantu->personal.pekerjaan<<endl;

				cout <<endl;
				*/
                gotoxy(1,j); cout <<"| " << bantu->id;
                gotoxy(8,j); cout <<"| " << bantu->personal.nama;
                gotoxy(36,j); cout <<"| " << bantu->personal.rt <<"/"<< bantu->personal.rw;
                gotoxy(44,j); cout <<"| " << bantu->personal.kampung;
                gotoxy(67,j); cout <<"| " << bantu->personal.kec;
                gotoxy(90,j); cout <<"| " << bantu->personal.jk;
                gotoxy(95,j); cout <<"| " << bantu->personal.pekerjaan;
                gotoxy(115,j); cout <<"|";
				ketemu = 0;
				bantu = bantu->next;
				j = j+1;
				ctr = ctr + 1;



			}else{
				bantu = bantu->next;
			}
		};
		cout <<"\n +------+---------------------------+-------+----------------------+----------------------+----+-------------------+" << endl;
        cout << endl;
		if((bantu == NULL)&&(ketemu == 1)){
			cout << " Data tidak ditemukan.. "<<endl;
			arr_id[0]=0;
		}

	}else{
		cout<<" Belum ada data, data masih kosong.. ";
	}


};

void ubahdatalist(list *L,int arr_id[15]){
	int id,ctr,ketemu = 1;
	char konf, pil;


	do{
	  cout << endl;
	  cout << "\n Masukan ID pendaftar yang datanya akan di ubah: ";
	  cin >> id;
	  ctr=0;
	  while(arr_id[ctr] != 0){
		  if(arr_id[ctr]==id){
			  ketemu = 0;
		  }
		  ctr = ctr + 1;
	  }
	  if (ketemu == 1) {
	  	cout << " ID yang Anda masukan tidak terdaftar dalam tabel hasil pencarian ";
	  }
	}while(ketemu!=0);

	elemen *bantu = L->awal;
	while(bantu->id != id){
		bantu = bantu->next;
	}
	do{
	cout << " \n\n [1] Semua\t   [2] Nama"<<endl;
	cout << " [3] RT\t\t   [4] RW"<<endl;
	cout << " [5] Kampung\t   [6] Kecamatan"<<endl;
	cout << " [7] Jenis Kelamin [8] Pekerjaan"<<endl;
	cout << " -----------------------------------" << endl;
	cout << " Masukan No. yang akan diubah: ";
	cin >> pil;
	cout << endl;
	switch(pil){
		case '1':
			bantu->personal = inptbio();
			break;
		case '2':
			cout << " Nama\t: ";
	 		fflush(stdin);cin.get(bantu->personal.nama,30);
	 		break;
	 	case '3':
	 		cout << " RT\t: ";
			cin >> bantu->personal.rt;
	 		break;
	 	case '4':
	 		cout << " RW\t: ";
	 		cin >> bantu->personal.rw;
	 		break;
	 	case '5':
	 		cout << " Kampung\t: ";
	 		fflush(stdin);cin.get(bantu->personal.kampung,30);
	 		break;
	 	case '6':
	 		cout << " Kecamatan\t: ";
	 		fflush(stdin);cin.get(bantu->personal.kec,30);
	 		break;
	 	case '7':
	 		cout << " Jenis Kelamin\n(L/P)\t\t: ";
	 		cin >> bantu->personal.jk;
	 		break;
	 	case '8':
	 		cout << " Pekerjaan\t: ";
	 		fflush(stdin);cin.get(bantu->personal.pekerjaan,30);
	 		break;
	 	default:
	 		cout << " Anda memasukan pilihan yang calah, mohon periksa lagi.. ";
	 		getch();
	 		break;
	}
        /*
	    cout << endl;
		cout <<" ID\t\t: "<< bantu->id<<endl;
		cout <<" Nama\t\t: "<<  bantu->personal.nama <<endl;
		cout <<" RT/RW\t\t: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
		cout <<" Kampung\t: "<<bantu->personal.kampung<<endl;
		cout <<" Kecamatan\t: "<<bantu->personal.kec<<endl;
		cout <<" Jenis Kelamin\t: "<<bantu->personal.jk<<endl;
		cout <<" Pekerjaan\t: "<<bantu->personal.pekerjaan<<endl;
        */
        if ((pil == '1') || (pil == '2') || (pil == '3') || (pil == '4') || (pil == '5') || (pil == '6') || (pil == '7') || (pil == '8')){
            cout << " \n Apakah data di atas sudah benar? [y/N]: ";
            cin >> konf;
        }
	}while((konf != 'Y')&&(konf!='y'));
};


void tampilall(list L){
	if(L.awal != NULL){
        system("cls");
        int j=6;
		elemen *bantu = L.awal;
        cout <<"\n                                            Data Semua Pembayar Zakat" << endl;
        cout <<"\n +------+---------------------------+-------+----------------------+----------------------+----+-------------------+" << endl;
        cout <<" | ID   | Nama                      | RT/RW | Kampung              | Kecamatan            | JK | Pekerjaan         |" << endl;
        cout <<" +------+---------------------------+-------+----------------------+----------------------+----+-------------------+" << endl;
		while(bantu != NULL){
                /*
				cout <<"Id\t\t\t: "<< bantu->id<<endl;
				cout <<"Nama\t\t: "<<  bantu->personal.nama <<endl;
				cout <<"RT/RW\t\t: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
				cout <<"Kampung\t\t: "<<bantu->personal.kampung<<endl;
				cout <<"Kecamatan\t: "<<bantu->personal.kec<<endl;
				cout <<"Jenis Kelamin\t: "<<bantu->personal.jk<<endl;
				cout <<"Pekerjaan\t: "<<bantu->personal.pekerjaan<<endl;
				cout <<endl;
				*/
                gotoxy(1,j); cout <<"| " << bantu->id;
                gotoxy(8,j); cout <<"| " << bantu->personal.nama;
                gotoxy(36,j); cout <<"| " << bantu->personal.rt <<"/"<< bantu->personal.rw;
                gotoxy(44,j); cout <<"| " << bantu->personal.kampung;
                gotoxy(67,j); cout <<"| " << bantu->personal.kec;
                gotoxy(90,j); cout <<"| " << bantu->personal.jk;
                gotoxy(95,j); cout <<"| " << bantu->personal.pekerjaan;
                gotoxy(115,j); cout <<"|";

				bantu = bantu->next;
				j = j+1;

		};
		bantu = NULL;
        cout <<"\n +------+---------------------------+-------+----------------------+----------------------+----+-------------------+" << endl;
        cout << endl;
	}else{
		cout<<" Belum ada data, data masih kosong.. "<<endl;
	}


};


void svall(list L){
	if(L.awal != NULL){

		time_t sekarang = time(0);
		char nama[30];
		char txt[5] = {'.','t','x','t'};
		char namafile[35];
		char* waktu = ctime(&sekarang);

		cout <<" File akan disimpan di tempat file program berada."<<endl;
		cout <<" Jika ingin menyimpan dilokasi lain masukan nama file dan lokasinya"<<endl;
		cout <<" Contoh : D:\\namafile"<<endl;
		cout <<endl;
		cout <<" Nama file : ";
		fflush(stdin);cin.get(nama,30);
		strcpy(namafile, strcat(nama, txt));
		ofstream byrfile;
  		byrfile.open (namafile);
  		byrfile <<" =============================================================="<<endl;
  		byrfile <<"                 Biodata Pembayar Zakat"<<endl;
  		byrfile <<" =============================================================="<<endl;
  		byrfile <<endl;
  		byrfile << " File ini di simpan pada : "<<waktu<<endl;

  		if(byrfile.is_open()){
  			elemen *bantu = L.awal;
			while(bantu != NULL){
				byrfile <<" =============================================================="<<endl;
				byrfile <<" ID\t\t			: "<< bantu->id<<endl;
				byrfile <<" --------------------------------------------------------------"<<endl;
				byrfile <<" Nama\t\t		: "<<  bantu->personal.nama <<endl;
				byrfile <<" RT/RW\t\t		: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
				byrfile <<" Kampung\t\t	: "<<bantu->personal.kampung<<endl;
				byrfile <<" Kecamatan\t		: "<<bantu->personal.kec<<endl;
				byrfile <<" Jenis Kelamin\t	: "<<bantu->personal.jk<<endl;
				byrfile <<" Pekerjaan\t		: "<<bantu->personal.pekerjaan<<endl;
				byrfile <<" =============================================================="<<endl;
				byrfile <<endl;
				bantu = bantu->next;
			};
			bantu = NULL;

		}else{
			cout << " File tidak bisa dibuka! "<<endl;
		}

	byrfile.close();
	}else{
		cout<<" Tabel Masih Kososng.. "<<endl;
	}


};


void kondisi_zakat(int id_pem,int arr_cnd[5], list L){

	elemen *bantu = L.awal;
	while(bantu->id != id_pem){
		bantu = bantu->next;
	}
		arr_cnd[1] = bantu->bayar;
		arr_cnd[2] = bantu->zktprof.statprof;
		arr_cnd[3] = bantu->zktemas.statmas;
		arr_cnd[4] = bantu->zktemas.statper;

};



void simpanzkt(char pil_zkt, int id_pem, zakatemas tempmas,zakatprof tempprof, list *L){

	elemen *bantu = L->awal;
	while(bantu->id != id_pem){
		bantu = bantu->next;
	}
		bantu->bayar = 1;
	if(pil_zkt == '1'){

		bantu->zktprof.statprof = tempprof.statprof;
		bantu->zktprof.income = tempprof.income;
    	bantu->zktprof.tunggakan = tempprof.tunggakan;
    	bantu->zktprof.zakat = tempprof.zakat;
	} else if(pil_zkt == '2'){

		if(tempmas.pil==1){

			bantu->zktemas.statmas = tempmas.statmas;
			bantu->zktemas.emas = tempmas.emas;
			bantu->zktemas.bzktmas = tempmas.bzktmas;
			bantu->zktemas.uangmas = tempmas.uangmas;
		}else if(tempmas.pil==2){

			bantu->zktemas.statper = tempmas.statper;
			bantu->zktemas.perak = tempmas.perak;
			bantu->zktemas.bzktper = tempmas.bzktper;
			bantu->zktemas.uangper = tempmas.uangper;
		}

	}


};

void input_value_table_zakat(int id_pem,int statprof,int income,int tunggakan,float zakat,int statmas,int emas,float bzktmas,float uangmas ,int statper,int perak ,float bzktper,float uangper, list *L){

	elemen *bantu = L->awal;
	while(bantu->id != id_pem){
		bantu = bantu->next;
	}
		if((statprof==0)&&(statmas==0)&&(statper==0)){
			bantu->bayar = 0;
		}else{
			bantu->bayar = 1;
		}

		bantu->zktprof.statprof = statprof;
		bantu->zktprof.income = income;
    	bantu->zktprof.tunggakan = tunggakan;
    	bantu->zktprof.zakat = zakat;

		bantu->zktemas.statmas = statmas;
		bantu->zktemas.emas = emas;
		bantu->zktemas.bzktmas = bzktmas;
		bantu->zktemas.uangmas = uangmas;

		bantu->zktemas.statper = statper;
		bantu->zktemas.perak = perak;
		bantu->zktemas.bzktper = bzktper;
		bantu->zktemas.uangper = uangper;




};

void caribay(list L,int arr_id[15]){
	if(L.awal != NULL){

		char inpt[31],band[31];
		int ketemu = 1,lkw,j,ctr=0,cat;
		j = 19;
		cat = kat();
		arr_id[ctr] = 0;
		cout << "\n Masukan kata kunci pencarian : ";
		fflush(stdin);cin.get(inpt,30);
		lkw = strlen(inpt);
		elemen *bantu = L.awal;
		while(bantu != NULL){

			if(cat == 1){
					strcpy(band,bantu->personal.nama);
				}else if(cat == 2){
					strcpy(band,bantu->personal.kampung);
				}else if(cat == 3){
					strcpy(band,bantu->personal.kec);
				}else if(cat == 4){
					strcpy(band,bantu->personal.pekerjaan);
				}

		if((strnicmp(band,inpt,lkw) == 0)&&(ketemu==1)){
            cout << "\n\n +-----+-----------------------+----------------------+---------------------------+--------------------+--------------------+" << endl;
            cout << " |     |                       |                      | Zakat Penghasilan (Rp)    | Zakat Emas         | Zakat Perak        |" << endl;
            cout << " | ID  | Nama                  | Pekerjaan            +-------------+-------------+------+-------------+------+-------------+" << endl;
            cout << " |     |                       |                      | Penghasilan | Zakat       | gr   | Rp          | gr   | Rp          |" << endl;
            cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+" << endl;
		}
			if(strnicmp(band,inpt,lkw) == 0){

				arr_id[ctr] = bantu->id;

                gotoxy(1,j); cout <<"| " << bantu->id;
                gotoxy(7,j); cout <<"| " << bantu->personal.nama;
                gotoxy(31,j); cout <<"| " << bantu->personal.pekerjaan;

				if((bantu->zktprof.statprof == 1) || (bantu->zktprof.statprof == 0)){
                        gotoxy(54,j); cout <<"| " << bantu->zktprof.income;
                        gotoxy(68,j); cout <<"| " << bantu->zktprof.zakat;

				}
				if((bantu->zktemas.statmas == 1) || (bantu->zktemas.statmas == 0)){
                        gotoxy(82,j); cout <<"| " << bantu->zktemas.bzktmas;
                        gotoxy(89,j); cout <<"| " << bantu->zktemas.uangmas;

				}
				if((bantu->zktemas.statper == 0) || (bantu->zktemas.statper == 1)){
                        gotoxy(103,j); cout <<"| " << bantu->zktemas.bzktper;
                        gotoxy(110,j); cout <<"| " << bantu->zktemas.uangper;
                        gotoxy(124,j); cout <<"|";

				}
				cout <<endl;
				ketemu = 0;
				bantu = bantu->next;
				j = j+1;
				ctr = ctr + 1;
			}else{
				bantu = bantu->next;
				j+1;
			}

		};
		if ((bantu == NULL) && (ketemu == 0)){
            cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+\n" << endl;
		}
		if((bantu == NULL)&&(ketemu == 1)){
			cout << " Data tidak ditemukan.. "<<endl;
		}
		bantu = NULL;
	}else{
		cout<<" Belum ada data, data masih kosong.."<<endl;
	}


};


void caripembayar(list L,int arr_id[15],char menu_sub){
	if(L.awal != NULL){

	char inpt[31],band[31];
		int ketemu = 1,lkw,j,ctr=0,cat;

	arr_id[ctr] = 0;

		if(menu_sub == '3'){
			j = 18;
		}else if(menu_sub == '4'){
			j = 19;
		}
		cat = kat();

		cout << "\n Masukan kata kunci pencarian : ";
		fflush(stdin);cin.get(inpt,30);
		lkw = strlen(inpt);
		elemen *bantu = L.awal;
		while(bantu != NULL){

			if(cat == 1){
					strcpy(band,bantu->personal.nama);
				}else if(cat == 2){
					strcpy(band,bantu->personal.kampung);
				}else if(cat == 3){
					strcpy(band,bantu->personal.kec);
				}else if(cat == 4){
					strcpy(band,bantu->personal.pekerjaan);
				}

		if((strnicmp(band,inpt,lkw) == 0)&&(ketemu==1)){
            cout << "\n\n +-----+-----------------------+----------------------+---------------------------+--------------------+--------------------+" << endl;
            cout << " |     |                       |                      | Zakat Penghasilan (Rp)    | Zakat Emas         | Zakat Perak        |" << endl;
            cout << " | ID  | Nama                  | Pekerjaan            +-------------+-------------+------+-------------+------+-------------+" << endl;
            cout << " |     |                       |                      | Penghasilan | Zakat       | gr   | Rp          | gr   | Rp          |" << endl;
            cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+" << endl;
		}

			if((strnicmp(band,inpt,lkw) == 0)&&(bantu->bayar==1)){

				arr_id[ctr] = bantu->id;

                gotoxy(1,j); cout <<"| " << bantu->id;
                gotoxy(7,j); cout <<"| " << bantu->personal.nama;
                gotoxy(31,j); cout <<"| " << bantu->personal.pekerjaan;
				/*
				cout <<"ID\t\t\t : "<< bantu->id<<endl;
                cout <<"Nama\t\t: "<<  bantu->personal.nama <<endl;
                cout <<"RT/RW\t\t: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
                cout <<"Kampung\t\t: "<<bantu->personal.kampung<<endl;
                cout <<"Kecamatan\t: "<<bantu->personal.kec<<endl;
                cout <<"Jenis Kelamin\t: "<<bantu->personal.jk<<endl;
                cout <<"Pekerjaan\t: "<<bantu->personal.pekerjaan<<endl;
                */
				if((bantu->zktprof.statprof == 1) || (bantu->zktprof.statprof == 0)){
                        gotoxy(54,j); cout <<"| " << bantu->zktprof.income;
                        gotoxy(68,j); cout <<"| " << bantu->zktprof.zakat;
						/*
						cout << "Zakat profesi bulan ini" << endl;
    					cout << "--------------------------------------------------------" << endl;
    					cout << "Total penghasilan bulan ini, Rp. " << bantu->zktprof.income << endl;
    					cout << "Tunggakan bulan ini, Rp. " << bantu->zktprof.tunggakan << endl;
    					cout << "--------------------------------------------------------" << endl;
    					cout << "Total zakat penghasilan bulan ini Rp. " << bantu->zktprof.zakat << ",-" << endl;
    					*/
				}
				if((bantu->zktemas.statmas == 1) || (bantu->zktemas.statmas == 0)){
                        gotoxy(82,j); cout <<"| " << bantu->zktemas.bzktmas;
                        gotoxy(89,j); cout <<"| " << bantu->zktemas.uangmas;
						/*
						cout << endl;
						cout << "Berat Emas yang dimiliki  : "<< bantu->zktemas.emas<<" gr"<<endl;
						cout << "--------------------------------------------------------" << endl;
						cout << "Berat Emas yang perlu dibayar  : "<< bantu->zktemas.bzktmas<<" gr"<<endl;
						cout << "Atau"<<endl;
						cout << "Besarnya uang yang perlu dibayar : Rp. "<<	bantu->zktemas.uangmas  << endl;
						cout << "--------------------------------------------------------" << endl;
						cout << endl;
						*/
				}
				if((bantu->zktemas.statper == 0) || (bantu->zktemas.statper == 1)){
                        gotoxy(103,j); cout <<"| " << bantu->zktemas.bzktper;
                        gotoxy(110,j); cout <<"| " << bantu->zktemas.uangper;
                        gotoxy(124,j); cout <<"|";
						/*
						cout << endl;
						cout << "Berat Perak yang dimiliki  : "<< bantu->zktemas.perak<<" gr"<<endl;
						cout << "--------------------------------------------------------" << endl;
						cout << "Berat Perak yang perlu dibayar  : "<< bantu->zktemas.bzktper<<" gr"<<endl;
						cout << "Atau"<<endl;
						cout << "Besarnya uang yang perlu dibayar : Rp. "<<	bantu->zktemas.uangper  << endl;
						cout << "--------------------------------------------------------" << endl;
						cout << endl;
						*/
				}
				cout <<endl;
				ketemu = 0;
				bantu = bantu->next;
				j = j+1;
				ctr = ctr + 1;
			}else{
				bantu = bantu->next;
				j+1;
			}

		};
		if ((bantu == NULL) && (ketemu == 0)){
            cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+\n" << endl;
		}
		if((bantu == NULL)&&(ketemu == 1)){
			cout << " Data tidak ditemukan.. "<<endl;
		}
		bantu = NULL;
	}else{
		cout<<" Belum ada data, data masih kosong.. "<<endl;
	}


};

void tampilpembayar(list L){
    system("cls");
        cout << "\n                                                 Daftar Pembayar Zakat" << endl;
        int j=9;
	if(L.awal != NULL){
		elemen *bantu = L.awal;
        cout << "\n\n +-----+-----------------------+----------------------+---------------------------+--------------------+--------------------+" << endl;
        cout << " |     |                       |                      | Zakat Penghasilan (Rp)    | Zakat Emas         | Zakat Perak        |" << endl;
        cout << " | ID  | Nama                  | Pekerjaan            +-------------+-------------+------+-------------+------+-------------+" << endl;
        cout << " |     |                       |                      | Penghasilan | Zakat       | gr   | Rp          | gr   | Rp          |" << endl;
        cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+" << endl;
		while(bantu != NULL){
			//if(bantu->bayar == 1){
                /*
				cout <<"ID\t\t\t : "<< bantu->id<<endl;
                cout <<"Nama\t\t: "<<  bantu->personal.nama <<endl;
                cout <<"RT/RW\t\t: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
                cout <<"Kampung\t\t: "<<bantu->personal.kampung<<endl;
                cout <<"Kecamatan\t: "<<bantu->personal.kec<<endl;
                cout <<"Jenis Kelamin\t: "<<bantu->personal.jk<<endl;
                cout <<"Pekerjaan\t: "<<bantu->personal.pekerjaan<<endl;
                */
                gotoxy(1,j); cout <<"| " << bantu->id;
                gotoxy(7,j); cout <<"| " << bantu->personal.nama;
                gotoxy(31,j); cout <<"| " << bantu->personal.pekerjaan;

				//if(bantu->zktprof.statprof == 1){
                    /*
                    cout << "Zakat profesi bulan ini" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Total penghasilan bulan ini, Rp. " << bantu->zktprof.income << endl;
                    cout << "Tunggakan bulan ini, Rp. " << bantu->zktprof.tunggakan << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Total zakat penghasilan bulan ini Rp. " << bantu->zktprof.zakat << ",-" << endl;
                    */
                    gotoxy(54,j); cout <<"| " << bantu->zktprof.income;
                    gotoxy(68,j); cout <<"| " << bantu->zktprof.zakat;
				//}

				//if(bantu->zktemas.statmas == 1){
                    /*
					cout << endl;
                    cout << "Berat Emas yang dimiliki  : "<< bantu->zktemas.emas<<" gr"<<endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Berat Emas yang perlu dibayar  : "<< bantu->zktemas.bzktmas<<" gr"<<endl;
                    cout << "Atau"<<endl;
                    cout << "Besarnya uang yang perlu dibayar : Rp. "<<	bantu->zktemas.uangmas  << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << endl;
                    */
                    gotoxy(82,j); cout <<"| " << bantu->zktemas.bzktmas;
                    gotoxy(89,j); cout <<"| " << bantu->zktemas.uangmas;
				//}
				//if(bantu->zktemas.statper == 1){
                    /*
                    cout << endl;
                    cout << "Berat Perak yang dimiliki  : "<< bantu->zktemas.perak<<" gr"<<endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Berat Perak yang perlu dibayar  : "<< bantu->zktemas.bzktper<<" gr"<<endl;
                    cout << "Atau"<<endl;
                    cout << "Besarnya uang yang perlu dibayar : Rp. "<<	bantu->zktemas.uangper  << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << endl;
                    */
                    gotoxy(103,j); cout <<"| " << bantu->zktemas.bzktper;
                    gotoxy(110,j); cout <<"| " << bantu->zktemas.uangper;
                    gotoxy(124,j); cout <<"|";
                //}
            //}

            cout <<endl;
            bantu = bantu->next;
            j = j+1;
		};
		cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+" << endl;
		bantu = NULL;
	}else{
		cout<<" Belum ada data, data masih kosong.. ";
	}


};



void tampil_aml_zkt(list L){
    system("cls");
        cout << "\n                                                 Daftar Pembayar Zakat" << endl;
        int j=9;
	if(L.awal != NULL){
		elemen *bantu = L.awal;
        cout << "\n\n +-----+-----------------------+----------------------+---------------------------+--------------------+--------------------+" << endl;
        cout << " |     |                       |                      | Zakat Penghasilan (Rp)    | Zakat Emas         | Zakat Perak        |" << endl;
        cout << " | ID  | Nama                  | Pekerjaan            +-------------+-------------+------+-------------+------+-------------+" << endl;
        cout << " |     |                       |                      | Penghasilan | Zakat       | gr   | Rp          | gr   | Rp          |" << endl;
        cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+" << endl;
		while(bantu != NULL){


			//if(bantu->bayar == 1){
                /*
				cout <<"ID\t\t\t : "<< bantu->id<<endl;
                cout <<"Nama\t\t: "<<  bantu->personal.nama <<endl;
                cout <<"RT/RW\t\t: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
                cout <<"Kampung\t\t: "<<bantu->personal.kampung<<endl;
                cout <<"Kecamatan\t: "<<bantu->personal.kec<<endl;
                cout <<"Jenis Kelamin\t: "<<bantu->personal.jk<<endl;
                cout <<"Pekerjaan\t: "<<bantu->personal.pekerjaan<<endl;
                */
                gotoxy(1,j); cout <<"| " << bantu->id;
                gotoxy(7,j); cout <<"| " << bantu->personal.nama;
                gotoxy(31,j); cout <<"| " << bantu->personal.pekerjaan;

				//if(bantu->zktprof.statprof == 1){
                    /*
                    cout << "Zakat profesi bulan ini" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Total penghasilan bulan ini, Rp. " << bantu->zktprof.income << endl;
                    cout << "Tunggakan bulan ini, Rp. " << bantu->zktprof.tunggakan << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Total zakat penghasilan bulan ini Rp. " << bantu->zktprof.zakat << ",-" << endl;
                    */
                    gotoxy(54,j); cout <<"| " << bantu->zktprof.income;
                    gotoxy(68,j); cout <<"| " << bantu->zktprof.zakat;
				//}

				//if(bantu->zktemas.statmas == 1){
                    /*
					cout << endl;
                    cout << "Berat Emas yang dimiliki  : "<< bantu->zktemas.emas<<" gr"<<endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Berat Emas yang perlu dibayar  : "<< bantu->zktemas.bzktmas<<" gr"<<endl;
                    cout << "Atau"<<endl;
                    cout << "Besarnya uang yang perlu dibayar : Rp. "<<	bantu->zktemas.uangmas  << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << endl;
                    */
                    gotoxy(82,j); cout <<"| " << bantu->zktemas.bzktmas;
                    gotoxy(89,j); cout <<"| " << bantu->zktemas.uangmas;
				//}
				//if(bantu->zktemas.statper == 1){
                    /*
                    cout << endl;
                    cout << "Berat Perak yang dimiliki  : "<< bantu->zktemas.perak<<" gr"<<endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Berat Perak yang perlu dibayar  : "<< bantu->zktemas.bzktper<<" gr"<<endl;
                    cout << "Atau"<<endl;
                    cout << "Besarnya uang yang perlu dibayar : Rp. "<<	bantu->zktemas.uangper  << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << endl;
                    */
                    gotoxy(103,j); cout <<"| " << bantu->zktemas.bzktper;
                    gotoxy(110,j); cout <<"| " << bantu->zktemas.uangper;
                    gotoxy(124,j); cout <<"|";
                //}
            //}

            cout <<endl;
            bantu = bantu->next;
            j = j+1;
		};
		cout << " +-----+-----------------------+----------------------+-------------+-------------+------+-------------+------+-------------+" << endl;
		bantu = NULL;
	}else{
		cout<<" Belum ada data, data masih kosong.. ";
	}


};



void cari_pemb_aml(list L,int arr_id[15]){
	if(L.awal != NULL){
		char inpt[31],band[31];
		int ketemu = 1,lkw,ctr=0,cat;
		cat = kat();
		arr_id[ctr] = 0;
		cout << "\n Masukan kata kunci pencarian : ";
		fflush(stdin);cin.get(inpt,30);
		lkw = strlen(inpt);
		elemen *bantu = L.awal;
		while(bantu != NULL){

			if(cat == 1){
					strcpy(band,bantu->personal.nama);
				}else if(cat == 2){
					strcpy(band,bantu->personal.kampung);
				}else if(cat == 3){
					strcpy(band,bantu->personal.kec);
				}else if(cat == 4){
					strcpy(band,bantu->personal.pekerjaan);
				}



			if(strnicmp(band,inpt,lkw) == 0){

				arr_id[ctr] = bantu->id;

                	cout <<endl;
				cout <<" =============================================================="<<endl;
				cout <<" ID				: "<<bantu->id<<endl;
				cout <<" --------------------------------------------------------------"<<endl;
				cout <<" Nama				: "<<bantu->personal.nama <<endl;
				cout <<" RT/RW				: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
				cout <<" Kampung			: "<<bantu->personal.kampung<<endl;
				cout <<" Kecamatan			: "<<bantu->personal.kec<<endl;
				cout <<" Jenis Kelamin			: "<<bantu->personal.jk<<endl;
				cout <<" Pekerjaan			: "<<bantu->personal.pekerjaan<<endl;
				cout <<endl;
				if(bantu->zktprof.statprof == 1){
							cout << " Zakat profesi bulan ini" << endl;
    				cout << " --------------------------------------------------------" << endl;
    				cout << " Total penghasilan bulan ini, Rp. " << bantu->zktprof.income << endl;
    				cout << " Tunggakan bulan ini, Rp. " << bantu->zktprof.tunggakan << endl;
    				cout << " --------------------------------------------------------" << endl;
    				cout << " Total zakat penghasilan bulan ini Rp. " << bantu->zktprof.zakat << ",-" << endl;
				}

				if(bantu->zktemas.statmas == 1){
					cout << endl;
					cout << " Berat Emas yang dimiliki 			: "<< bantu->zktemas.emas<<" gr"<<endl;
					cout << " --------------------------------------------------------" << endl;
					cout << " Berat Emas yang perlu dibayar  	: "<< bantu->zktemas.bzktmas<<" gr"<<endl;
					cout << " Atau"<<endl;
					cout << " Besarnya uang yang perlu dibayar 	: Rp. "<<	bantu->zktemas.uangmas  << endl;
					cout << " --------------------------------------------------------" << endl;
				}
				if(bantu->zktemas.statper == 1){
						cout << endl;
					cout << " Berat Perak yang dimiliki 		: "<< bantu->zktemas.perak<<" gr"<<endl;
					cout << " --------------------------------------------------------" << endl;
					cout << " Berat Perak yang perlu dibayar  	: "<< bantu->zktemas.bzktper<<" gr"<<endl;
					cout << " Atau"<<endl;
					cout << " Besarnya uang yang perlu dibayar 	: Rp. "<<	bantu->zktemas.uangper  << endl;
					cout << " --------------------------------------------------------" << endl;
					cout << endl;
				}

				cout <<" =============================================================="<<endl;
				cout <<endl;
				ketemu = 0;
				bantu = bantu->next;

				ctr = ctr + 1;
			}else{
				bantu = bantu->next;

			}

		};

		if((bantu == NULL)&&(ketemu == 1)){
			cout << "\n Data tidak ditemukan..."<<endl;
		}
		bantu = NULL;
	}else{
		cout<<" List Masih Kososng"<<endl;
	}


};


void svallbayar(list L){
	if(L.awal != NULL){
		time_t sekarang = time(0);
		char nama[30];
		char txt[5] = {'.','t','x','t'};
		char namafile[35];
		char* waktu = ctime(&sekarang);
		cout <<" File akan disimpan di tempat file program berada."<<endl;
		cout <<" Jika ingin menyimpan dilokasi lain masukan nama file dan lokasinya"<<endl;
		cout <<" Contoh : D:\\namafile"<<endl;
		cout <<endl;
		cout <<" Nama file : ";
		fflush(stdin);cin.get(nama,30);
		strcpy(namafile, strcat(nama, txt));

		ofstream byrfile;
  		byrfile.open (namafile);
  		byrfile <<" =============================================================="<<endl;
  		byrfile <<"                Data Zakat Yang di Bayar"<<endl;
  		byrfile <<" =============================================================="<<endl;
  		byrfile <<endl;
  		byrfile << " File ini di simpan pada : "<<waktu<<endl;
  		elemen *bantu = L.awal;
  		if(byrfile.is_open()){

			while(bantu != NULL){
				byrfile <<endl;
				byrfile <<" =============================================================="<<endl;
				byrfile <<" ID\t\t\t 		: "<<bantu->id<<endl;
				byrfile <<" --------------------------------------------------------------"<<endl;
				byrfile <<" Nama\t\t		: "<<bantu->personal.nama <<endl;
				byrfile <<" RT/RW\t\t		: "<<bantu->personal.rt <<"/"<<bantu->personal.rw << endl;
				byrfile <<" Kampung\t\t    : "<<bantu->personal.kampung<<endl;
				byrfile <<" Kecamatan\t		: "<<bantu->personal.kec<<endl;
				byrfile <<" Jenis Kelamin\t	: "<<bantu->personal.jk<<endl;
				byrfile <<" Pekerjaan\t		: "<<bantu->personal.pekerjaan<<endl;

				if(bantu->zktprof.statprof == 1){
							byrfile << " Zakat profesi bulan ini" << endl;
    				byrfile << " --------------------------------------------------------" << endl;
    				byrfile << " Total penghasilan bulan ini, Rp. " << bantu->zktprof.income << endl;
    				byrfile << " Tunggakan bulan ini, Rp. " << bantu->zktprof.tunggakan << endl;
    				byrfile << " --------------------------------------------------------" << endl;
    				byrfile << " Total zakat penghasilan bulan ini Rp. " << bantu->zktprof.zakat << ",-" << endl;
				}

				if(bantu->zktemas.statmas == 1){
					byrfile << endl;
					byrfile << " Berat Emas yang dimiliki 			: "<< bantu->zktemas.emas<<" gr"<<endl;
					byrfile << " --------------------------------------------------------" << endl;
					byrfile << " Berat Emas yang perlu dibayar  	: "<< bantu->zktemas.bzktmas<<" gr"<<endl;
					byrfile << " Atau"<<endl;
					byrfile << " Besarnya uang yang perlu dibayar 	: Rp. "<<	bantu->zktemas.uangmas  << endl;
					byrfile << " --------------------------------------------------------" << endl;
				}
				if(bantu->zktemas.statper == 1){
						byrfile << endl;
					byrfile << " Berat Perak yang dimiliki 			: "<< bantu->zktemas.perak<<" gr"<<endl;
					byrfile << " --------------------------------------------------------" << endl;
					byrfile << " Berat Perak yang perlu dibayar  	: "<< bantu->zktemas.bzktper<<" gr"<<endl;
					byrfile << " Atau"<<endl;
					byrfile << " Besarnya uang yang perlu dibayar 	: Rp. "<<	bantu->zktemas.uangper  << endl;
					byrfile << " --------------------------------------------------------" << endl;
					byrfile << endl;
				}

				byrfile <<" =============================================================="<<endl;

				byrfile <<endl;
				bantu = bantu->next;
			};

		}else{
			cout << " File tidak bisa dibuka"<<endl;
		}
		bantu = NULL;
	byrfile.close();
	cout << endl;
	}else{
		cout<<" List Masih Kososng! "<<endl;
	}


};



void sv_hid(int id,list L){
	if(L.awal != NULL){
		ofstream hidfile;
  		hidfile.open ("datbase.wow");
  		elemen *bantu = L.awal;
  		if(hidfile.is_open()){

			while(bantu != NULL){
				hidfile<<"$"<<bantu->id<<"$"<<bantu->personal.nama<<"$"<<bantu->personal.rt<<"$"<<bantu->personal.rw <<"$"<<bantu->personal.kampung<<"$"<<bantu->personal.kec<<"$"<<bantu->personal.jk<<"$"<<bantu->personal.pekerjaan<<endl;
				if(bantu->bayar ==1){

					hidfile<<"input_value_table_zakat("<<","<<bantu->zktprof.statprof<<","<< bantu->zktprof.income<<","<< bantu->zktprof.tunggakan <<","<< bantu->zktprof.zakat
					<<","<<bantu->zktemas.statmas<<","<<bantu->zktemas.emas<<","<<bantu->zktemas.bzktmas<<","<<bantu->zktemas.uangmas
					<<","<<bantu->zktemas.statper<<","<<bantu->zktemas.perak<<","<<bantu->zktemas.bzktper<<","<<bantu->zktemas.uangper<<");"<< endl;
				}
				//svfile <<endl;
				bantu = bantu->next;
			};
		}else{
			cout << " File tidak bisa dibuka"<<endl;
		}
		bantu = NULL;
		hidfile.close();

	}else{
		cout<<" List Masih Kososng"<<endl;
	}


};


void hapussemua(list *L){
	while(L->awal != NULL){
		if(L->awal != NULL){
			if(L->awal->next == NULL){
				elemen *node = L->awal;
				L->awal = L->awal->next;
				node->next = NULL;
				free(node);
			}else{
				elemen *akhir = L->awal;
				elemen *sebelumakhir;
				while(akhir->next != NULL){
					sebelumakhir = akhir;
					akhir = akhir->next;
				}

				sebelumakhir->next = NULL;
				free(akhir);
			}


		}
	}
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
 	ukuranwindow(126,200);
	int id,id_pem,ctr,ketemu,jmp=0;
	char pil_bay,pilih, menu, menu_sub, menu_konf, pil_zkt,pass[9];
	const char *word = "1234abcd";
	list L;
	buatlist(&L);
	// ----- tempat menyimpan data sementara ----------//

		biodata tempbio;
		zakatemas tempmas;
		zakatprof tempprof;

	// --------------- Pre-Inputed Data ------------//
		simpdata(1,"Insan Muslim",2,5,"Cidulang","Gegerbitung",'L',"Karyawan",&L);
		simpdata(2,"Nadiar A Syariful",3,2,"Cisitu","Cisitu",'L',"Wiraswasta",&L);
		simpdata(3,"Lia Mulia",4,6,"Sekeloa","Sekeloa",'P',"Karyawan",&L);
		simpdata(4,"Mahmud Mualim",1,3,"Pucung","Pluit",'L',"Wiraswasta",&L);
		simpdata(5,"Nani Masaka",3,6,"Sekeloa","Sekeloa",'P',"Ibu rumah tangga",&L);
		simpdata(6,"Yatta Dekita",1,3,"Cijurei","Gegerbitung",'P',"Buruh",&L);
		simpdata(7,"Moch Ridwan",3,4,"Sekeloa","Sekeloa",'L',"Buruh", &L);

		input_value_table_zakat(1,1,800000,0,200000,0,0,0,0,1,20,0.5,550,&L);
		input_value_table_zakat(2,1,920000,0,230000,0,0,0,0,0,0,0,0,&L);
		input_value_table_zakat(3,0,0,0,0,0,0,0,0,0,0,0,0,&L);
		input_value_table_zakat(4,1,950000,100000,212500,0,0,0,0,0,0,0,0,&L);
		input_value_table_zakat(5,0,0,0,0,1,40,1,47000,1,50,1.25,1375,&L);
		input_value_table_zakat(6,1,450000,80000,92500,0,0,0,0,1,30,0.75,825,&L);
		input_value_table_zakat(7,0,0,0,0,0,0,0,0,0,0,0,0,&L);


	do{



		system("cls");
		cout << "\n           Program Zakat" << endl;
		cout << " ===================================" <<endl;
		cout << " Menu" << endl;
		cout << " -----------------------------------" << endl;
		cout << " [1] Pendafataran" << endl;
		cout << " [2] Pembayaran" << endl;
		cout << " [3] Amil zakat" << endl;
		cout << " [4] Keluar" << endl;
		cout << " -----------------------------------" << endl;
		cout << " Masukan Pilihan : ";
		cin >> menu;
		switch(menu){

//  -----------------------  Pendaftaran Zakat --------------------------   //

			case '1' :
				do{
					system("cls");
					cout << "\n -----------------------------------" << endl;
					cout << " Menu > Pendaftaran " << endl;
					cout << " -----------------------------------" << endl;
					cout << " [1] Cari"<<endl;
					cout << " [2] Input"<<endl;
					cout << " [3] Ouput"<<endl;
					cout << " [4] Ubah"<<endl;
					cout << " [5] Simpan"<<endl;
					cout << " [6] Kembali ke menu sebelumnya"<<endl;
					cout << " -----------------------------------" << endl;
					cout << " Masukan Pilihan : ";
					cin >> menu_sub;
					switch(menu_sub){
						case '1':
						    system("cls");
							cout << "\n -----------------------------------" << endl;
							cout << " Menu > Pendaftaran > Cari" << endl;
							cout << " -----------------------------------" << endl;
							cari(L,arr_id,menu_sub);
							cout << " \n" << endl;
							cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '2':
							system("cls");
							cout << "\n -----------------------------------" << endl;
							cout << " Menu > Pendaftaran > Input" << endl;
							cout << " -----------------------------------" << endl;
							id = lastid(L);
							cout << " ID\t\t: " << id <<endl;
							tempbio = inptbio();
							do{
								system("cls");
								cout << "\n -----------------------------------" << endl;
								cout << " Menu > Pendaftaran > Input" << endl;
								cout << " -----------------------------------" << endl;
								id = lastid(L);
								tempoutdaf(tempbio);
								cout << " -----------------------------------" << endl;
								cout << " Apakah data diatas sudah benar? "<<endl;
								cout << " \n [1] Ya " << " [2] Tidak " <<endl;
								cout << " -----------------------------------" << endl;
								cout << " Pilih : ";
								cin >> menu_konf;
								switch(menu_konf){
									case '1' :
										simpanbio(id,tempbio,&L);
										break;
									case '2' :
										tempubahdaf(&tempbio);
										break;
									default :
										cout << " Pilihan tidak terdaftar !!"<<endl;
										cout << " Tekan tombol sembarang untuk memilih kembali.. ";
										break;
								}
							}while(menu_konf!='1');
							cout << " -----------------------------------" << endl;
							cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '3':
							do{
								system("cls");
								cout << "\n -----------------------------------" << endl;
								cout << " Menu > Pendaftaran > Output" << endl;
								cout << " -----------------------------------" << endl;
								cout << " [1] Tampilkan seluruh pendaftar" <<endl;
								cout << " [2] Cari"<<endl;
								cout << " [3] Kembali kemenu sebelumnya"<<endl;
								cout << " -----------------------------------" << endl;
								cout << " Pilih : ";
								cin >> menu_konf;
								cout << endl;
								switch(menu_konf){
									case '1' :

										tampilall(L);
										cout << "\n Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
										getch();
										break;
									case '2' :
										cari(L,arr_id,menu_sub);
										cout << "\n Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
										getch();
										break;
									case '3' :
										break;
									default :
										cout << " Pilihan tidak ada! Mohon periksa"<<endl;
										cout << " Tekan tombol sembarang untuk memilih kembali.. ";
										break;
								}
							}while(menu_konf!='3');
							break;
						case '4':
							system("cls");
							cout << "\n -----------------------------------" << endl;
							cout << "  Menu > Pendaftaran > Ubah" << endl;
							cout << " -----------------------------------" << endl;
							cari(L,arr_id,menu_sub);
							if(arr_id[0]!=0){
								ubahdatalist(&L,arr_id);
							}
							cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '5':
							system("cls");
							cout << "\n -----------------------------------" << endl;
							cout << " Menu > Pendaftaran > Simpan" << endl;
							cout << " -----------------------------------" << endl;

							svall(L);

							cout << "\n\n Data berhasil disimpan"<<endl;
							cout << " -----------------------------------" << endl;
							cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '6':
							break;
						default:
							cout << " Pilihan yang anda masukan tidak terdaftar"<<endl;
							cout << " Tekan tombol sembarang untuk mengulang.. ";
							getch();
							break;
					}

				}while(menu_sub!='6');
				break;

//  -----------------------  Bayar Zakat --------------------------   //

			case '2' :
				do{



					system("cls");
					cout << "\n -----------------------------------" << endl;
					cout << " Menu > Pembayaran " << endl;
					cout << " -----------------------------------" << endl;
					cout << " [1] Bayar "<<endl;
					cout << " [2] Ouput zakat"<<endl;
					cout << " [3] Cari pembayaran"<<endl;
					cout << " [4] Ubah"<<endl;
					cout << " [5] Simpan"<<endl;
					cout << " [6] Kembali ke menu sebelumnya"<<endl;
					cout << " -----------------------------------" << endl;
					cout << " Masukan Pilihan: ";
					cin >> menu_sub;
					switch(menu_sub){
						case '1':

								system("cls");
								cout << "\n -----------------------------------" << endl;
								cout << " Menu > Pembayaran > Bayar" << endl;
								cout << " -----------------------------------" << endl;
								caribay(L,arr_id);
								if(arr_id[0]!=0){
									do{
                                	   ketemu = 1;
	                                   cout << endl;
	                                   cout << " Masukan ID pendaftar yang akan membayar zakat: ";
	                                   cin >> id_pem;
	                                   ctr=0;
	                                   while(arr_id[ctr] != 0){
		                                if(arr_id[ctr]==id_pem){
			                               ketemu = 0;
		                                }
		                                  	ctr = ctr + 1;
	  									}
	  									if(ketemu == 1){
	  										cout << endl;
	  										cout << " Id yang anda masukan tidak terdaftar";
	  										cout << endl;
	  									}
								}while(ketemu!=0);
								cout << " -----------------------------------" << endl;
								kondisi_zakat(id_pem,arr_cnd,L);

									if((arr_cnd[1]==1)&&(arr_cnd[2]==1)&&(arr_cnd[3]==1)&&(arr_cnd[4]==1)){
										cout << endl;
										cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar semua zakat yang ada."<<endl;
										cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
										cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
										getch();
									}else{
											do{
												do{
													system("cls");
													cout << "\n -----------------------------------" << endl;
													cout << " Menu > Pembayaran > Cari > Pilih zakat" << endl;
													cout << " -----------------------------------" << endl;
													cout << " [1] Zakat profesi"<< endl;
													cout << " [2] Zakat Emas/Perak"<< endl;
													cout << " -----------------------------------" << endl;
													cout << " Masukan pilihan anda : ";
													cin >> pil_zkt;
													cout << endl;

														switch(pil_zkt){
														case '1':
															if(arr_cnd[2] == 1){
																cout << endl;
																cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat profesi."<<endl;
																cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																jmp = 1;
															}else{
																tempprof = resetprof();
																tempprof = hitprof();
																tempoutprof(tempprof);
																jmp = 0;
															}
															break;
														case '2':
															if((arr_cnd[3]==1)&&(arr_cnd[4]==1)){
																cout << endl;
																cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat emas dan perak."<<endl;
																cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																jmp = 1;

															}else{
																tempmas = resetmas();
																tempmas = hitmas();
																if((arr_cnd[3]==1)&&(tempmas.pil == 1)){
																	cout << endl;
																	cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat emas."<<endl;
																	cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																	jmp = 1;
																}else if((arr_cnd[4]==1)&&(tempmas.pil == 2)){
																	cout << endl;
																	cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat perak."<<endl;
																	cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																	jmp = 1;
																}else {
																	tempoutmas(tempmas);
																	jmp = 0;
																}

															}
															break;
														default:
															cout << " Pilihan tidak ada!!" << endl;
															cout << " Tekan tombol sembarang untuk memilih kembali.. ";
															getch();
															break;
														}
													}while((pil_zkt!='1')&&(pil_zkt!='2'));
														cout << " -----------------------------------" << endl;
														cout << " [1] Untuk Selesai " << "[2] Untuk Ulangi"<<endl;
														cout << " Pilih : ";
														cin >> pil_bay;
												}while(pil_bay!='1');
													if(jmp==0){
														simpanzkt(pil_zkt,id_pem, tempmas, tempprof, &L);
													}
									}

								}else{
									cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
									getch();
								}

							break;
						case '2':
							tampilpembayar(L);
							cout << "\n\n Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '3':
							system("cls");
							cout << "-----------------------------------" << endl;
							cout << " Menu > Pembayaran > Cari" << endl;
							cout << "-----------------------------------" << endl;
							caripembayar(L,arr_id,menu_sub);
							cout << "\n Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '4':
								system("cls");
								cout << "\n -----------------------------------" << endl;
								cout << " Menu > Pembayaran > Ubah" << endl;
								cout << " -----------------------------------" << endl;
								caripembayar(L,arr_id,menu_sub);
								if(arr_id[0]!=0){
									do{
                                	   ketemu = 1;
	                                   cout << endl;
	                                   cout << " Masukan ID pendaftar yang datanya akan di ubah: ";
	                                   cin >> id_pem;
	                                   ctr=0;
	                                   while(arr_id[ctr] != 0){
		                                if(arr_id[ctr]==id_pem){
			                               ketemu = 0;
		                                }
		                                  ctr = ctr + 1;
	  									}
	  									if(ketemu == 1){
	  									cout << endl;
	  									cout << " Id yang anda masukan tidak terdaftar";
	  									}
								}while(ketemu!=0);
								cout << " -----------------------------------" << endl;
								do{
									do{
									cout << "\n\n Zakat yang akan di ubah" << endl;
									cout << " -----------------------------------" << endl;
									cout << " [1] Zakat profesi"<< endl;
									cout << " [2] Zakat Emas/Perak"<< endl;
									cout << " -----------------------------------" << endl;
									cout << " Masukan pilihan anda: ";
									cin >> pil_zkt;
									cout << endl;

										switch(pil_zkt){
										case '1':
											tempprof = resetprof();
											tempprof = hitprof();
											tempoutprof(tempprof);

											break;
										case '2':
											tempmas = resetmas();
											tempmas = hitmas();
											tempoutmas(tempmas);
											break;
										default:
											cout << " Pilihan tidak ada!!" << endl;
											cout << " Tekan tombol sembarang untuk memilih kembali.. ";
											getch();
											break;
										}
									}while((pil_zkt!='1')&&(pil_zkt!='2'));
									cout << " -----------------------------------" << endl;
									cout << " Apakah data yang anda masukan sudah benar? "<<endl;
									cout << " [1] Ya\t" << "[2] Ulangi"<<endl;
									cout << " Pilih : ";
									cin >> pil_bay;

									simpanzkt(pil_zkt,id_pem, tempmas, tempprof, &L);

								}while(pil_bay!='1');
							}else{
								cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
								getch();
								}
							break;
						case '5':
						system("cls");
							cout << "\n -----------------------------------" << endl;
							cout << " Menu > Pendaftaran > Simpan" << endl;
							cout << " -----------------------------------" << endl;
							id = lastid(L);
							svallbayar(L);
							cout << " Data berhasil disimpan"<<endl;
							cout << " -----------------------------------" << endl;
							cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
							getch();
							break;
						case '6':
							break;
						default:
							cout << " Pilihan yang anda masukan tidak terdaftar"<<endl;
							cout << " Tekan tombol sembarang untuk kembali ke menu awal.. ";
							getch();
							break;
					}

				}while(menu_sub!='6');
				break;

//  -----------------------  Amil Zakat --------------------------   //
			case '3' :
				cout << " Password : ";
				fflush(stdin);cin.get(pass,30);
				if(strcmp(pass,word)==0){
					do{
					system("cls");
						cout << "\n -----------------------------------" << endl;
						cout << " Menu > Amil Zakat " << endl;
						cout << " -----------------------------------" << endl;
						cout << " [1] Input "<<endl;
						cout << " [2] Ouput"<<endl;
						cout << " [3] Cari"<<endl;
						cout << " [4] Ubah"<<endl;
						cout << " [5] Simpan"<<endl;
						cout << " [6] Kembali ke menu sebelumnya"<<endl;
						cout << " -----------------------------------" << endl;
						cout << " Masukan Pilihan: ";
						cin >> menu_sub;
						switch(menu_sub){
							case '1':
								system("cls");
								cout << "-----------------------------------" << endl;
								cout << " Menu > Amil Zakat > Input" << endl;
								cout << "-----------------------------------" << endl;
								cout << " [1] Biodata "<<endl;
								cout << " [2] Zakat"<<endl;
								cout << " [3] Keluar"<<endl;
								cout << "-----------------------------------" << endl;
								cout << " Masukan pilihan : ";
								cin >> pilih;
								if(pilih == '1'){
									system("cls");
									cout << "\n -----------------------------------" << endl;
									cout << " Menu > Amil Zakat > Input > Biodata" << endl;
									cout << " -----------------------------------" << endl;
									id = lastid(L);
									cout << " ID\t\t: " << id <<endl;
									tempbio = inptbio();
									do{
										system("cls");
										cout << "\n -----------------------------------" << endl;
										cout << " Menu > Amil Zakat > Input > Biodata" << endl;
										cout << " -----------------------------------" << endl;
										id = lastid(L);
										tempoutdaf(tempbio);
										cout << " -----------------------------------" << endl;
										cout << " Apakah data diatas sudah benar? "<<endl;
										cout << " \n [1] Ya " << " [2] Tidak " <<endl;
										cout << " -----------------------------------" << endl;
										cout << " Pilih : ";
										cin >> menu_konf;
										switch(menu_konf){
											case '1' :
												simpanbio(id,tempbio,&L);
												break;
											case '2' :
												tempubahdaf(&tempbio);
												break;
											default :
												cout << " Pilihan tidak terdaftar !!"<<endl;
												cout << " Tekan tombol sembarang untuk memilih kembali.. ";
												break;
											}
										}while(menu_konf!='1');
										cout << " -----------------------------------" << endl;
										cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
										getch();
										break;
									}else if(pilih == '2'){

										system("cls");
										cout << "\n -----------------------------------" << endl;
										cout << " Menu > Amil Zakat > Input > Zakat" << endl;
										cout << " -----------------------------------" << endl;
										caribay(L,arr_id);
										if(arr_id[0]!=0){
											do{
											   ketemu = 1;
											   cout << endl;
											   cout << " Masukan ID pendaftar yang akan membayar zakat: ";
											   cin >> id_pem;
											   ctr=0;
											 while(arr_id[ctr] != 0){
											if(arr_id[ctr]==id_pem){
											   ketemu = 0;
											}
											  ctr = ctr + 1;
											}
											if(ketemu == 1){
											cout << " ID yang anda masukan tidak terdaftar";
											}
									}while(ketemu!=0);
									cout << " -----------------------------------" << endl;
									kondisi_zakat(id_pem,arr_cnd,L);

										if((arr_cnd[1]==1)&&(arr_cnd[2]==1)&&(arr_cnd[3]==1)&&(arr_cnd[4]==1)){
											cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar semua zakat yang ada."<<endl;
											cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
											cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
											getch();
										}else{
												do{
													do{
														system("cls");
														cout << "\n -----------------------------------" << endl;
														cout << " Menu > Amil Zakat > Input > Pilih zakat" << endl;
														cout << " -----------------------------------" << endl;
														cout << " [1] Zakat profesi"<< endl;
														cout << " [2] Zakat Emas/Perak"<< endl;
														cout << " -----------------------------------" << endl;
														cout << " Masukan pilihan anda : ";
														cin >> pil_zkt;
														cout << endl;

															switch(pil_zkt){
															case '1':
																if(arr_cnd[2] == 1){
																	cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat profesi."<<endl;
																	cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																	jmp = 1;
																}else{
																	tempprof = resetprof();
																	tempprof = hitprof();
																	tempoutprof(tempprof);
																	jmp = 0;
																}

																break;
															case '2':
																if((arr_cnd[3]==1)&&(arr_cnd[4]==1)){
																	cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat emas dan perak."<<endl;
																	cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																	jmp = 1;

																}else{
																	tempmas = resetmas();
																	tempmas = hitmas();
																	if((arr_cnd[3]==1)&&(tempmas.pil == 1)){
																		cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat emas."<<endl;
																		cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																		jmp = 1;
																	}else if((arr_cnd[4]==1)&&(tempmas.pil == 2)){
																		cout << " Pembayar zakat dengan ID " << id_pem <<" pada periode ini telah membayar zakat perak."<<endl;
																		cout << " Gunakan menu \"Ubah\" untuk mengubah data"<<endl;
																		jmp = 1;
																	}else {
																		tempoutmas(tempmas);
																		jmp = 0;
																	}

																}

																break;
															default:
																cout << " Pilihan tidak ada!!" << endl;
																cout << " Tekan tombol sembarang untuk memilih kembali.. ";
																getch();
																break;
															}
														}while((pil_zkt!='1')&&(pil_zkt!='2'));
															cout << " -----------------------------------" << endl;
															cout << " [1] Untuk Selesai " << "[2] Untuk Ulangi"<<endl;
															cout << " Pilih : ";
															cin >> pil_bay;
													}while(pil_bay!='1');
														if(jmp==0){
															simpanzkt(pil_zkt,id_pem, tempmas, tempprof, &L);
														}
										}

									}else{
										cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya.. ";
										getch();
									}


								}
								break;
							case '2':
								system("cls");
								cout << " -----------------------------------" << endl;
								cout << " Menu > Amil Zakat > Output zakat" << endl;
								cout << " -----------------------------------" << endl;
								cout << " [1] Biodata "<<endl;
								cout << " [2] Zakat"<<endl;
								cout << " [3] Keluar"<<endl;
								cout << " -----------------------------------" << endl;
								cout << " Masukan pilihan : ";
								cin >> pilih;
								if(pilih == '1'){
									tampilall(L);
									cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya"<<endl;
									getch();
								}else if(pilih == '2'){
									tampil_aml_zkt(L);
									cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya"<<endl;
									getch();
								}
								break;
							case '3':
								system("cls");
								cout << " ---------------------------------------" << endl;
								cout << " Menu > Amil Zakat > Cari" << endl;
								cout << " ---------------------------------------" << endl;
								cout << " [1] Biodata "<<endl;
								cout << " [2] Zakat"<<endl;
								cout << " [3] Keluar"<<endl;
								cout << " -----------------------------------" << endl;
								cout << " Masukan pilihan : ";
								cin >> pilih;
								cout << endl;
								if(pilih == '1'){
									system("cls");
									cout << " ---------------------------------------" << endl;
									cout << " Menu > Amil Zakat > Cari > Biodata" << endl;
									cout << " ---------------------------------------" << endl;
									menu_sub = '5';
									cari(L,arr_id,menu_sub);
									menu_sub = '3';
								}else if(pilih == '2'){
									system("cls");
									cout << " ---------------------------------------" << endl;
									cout << " Menu > Amil Zakat > Cari > Zakat" << endl;
									cout << " ---------------------------------------" << endl;
									caripembayar(L,arr_id,menu_sub);

								}
								cout << " -----------------------------------" << endl;
								cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya"<<endl;
								getch();
								break;
							case '4':
									system("cls");
									cout << " -----------------------------------" << endl;
									cout << " Menu > Amil Zakat > Ubah" << endl;
									cout << " -----------------------------------" << endl;
									cari_pemb_aml(L,arr_id);
									if(arr_id[0]!=0){
									cout << " [1] Biodata "<<endl;
									cout << " [2] Zakat"<<endl;
									cout << " [3] Keluar"<<endl;
									cout << " -----------------------------------" << endl;
									cout << " Masukan pilihan : ";
									cin >> pilih;
									if(pilih == '1'){
										ubahdatalist(&L,arr_id);
									}else if(pilih == '2'){
										do{
											ketemu = 1;
											cout << endl;
											cout << " Masukan ID pendaftar yang datanya akan di ubah: ";
											cin >> id_pem;
											ctr=0;
											while(arr_id[ctr] != 0){
												if(arr_id[ctr]==id_pem){
													ketemu = 0;
												 }
												ctr = ctr + 1;
											}
											if(ketemu == 1){
												cout << " ID yang Anda masukan tidak terdaftar";
											}
										}while(ketemu!=0);
									cout << "-----------------------------------" << endl;
									do{
										do{
										cout << "\n\n Zakat yang akan di ubah" << endl;
										cout << " -----------------------------------" << endl;
										cout << " [1] Zakat profesi"<< endl;
										cout << " [2] Zakat Emas/Perak"<< endl;
										cout << " -----------------------------------" << endl;
										cout << " Masukan pilihan anda: ";
										cin >> pil_zkt;
										cout << endl;

											switch(pil_zkt){
											case '1':
												tempprof = resetprof();
												tempprof = hitprof();
												tempoutprof(tempprof);

												break;
											case '2':
												tempmas = resetmas();
												tempmas = hitmas();
												tempoutmas(tempmas);
												break;
											default:
												cout << " Pilihan tidak ada!!" << endl;
												cout << " Tekan tombol sembarang untuk memilih kembali.. ";
												getch();
												break;
											}
										}while((pil_zkt!='1')&&(pil_zkt!='2'));
										cout << " -----------------------------------" << endl;
										cout << " Apakah data yang anda masukan sudah benar? "<<endl;
										cout << " [1] Ya\t" << "[2] Ulangi"<<endl;

										cout << "  Pilih : ";
										cin >> pil_bay;
									}while(pil_bay!='1');
								simpanzkt(pil_zkt,id_pem, tempmas, tempprof, &L);
									}
									}else{
										cout << " -----------------------------------" << endl;
										cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya"<<endl;
										getch();

									};
								break;
							case '5':
								system("cls");
								cout << " -----------------------------------" << endl;
								cout << " Menu > Amil Zakat > Simpan" << endl;
								cout << " -----------------------------------" << endl;
								svallbayar(L);
								cout << " Data berhasil disimpan"<<endl;
								cout << " -----------------------------------" << endl;
								cout << " Tekan tombol sembarang untuk kembali ke menu sebelumnya"<<endl;
								getch();
								break;
							case '6':
								break;
							default:
								cout << " Pilihan yang anda masukan tidak terdaftar"<<endl;
								cout << " Tekan tombol sembarang untuk kembali ke menu awal"<< endl;
								getch();
								break;
						}

					}while(menu_sub!='6');
				}else{
					cout << " Passsword yang anda masukan salah"<<endl;
					cout << " Tekan tombol sembarang untuk kembali ke menu awal"<< endl;
					getch();
				}
				break;
			case '4' :
				id = lastid(L);
				sv_hid(id,L);
				hapussemua(&L);
				break;
			default :
				cout << "\n Pilihan yang anda masukan tidak terdaftar" << endl;
				cout << " Tekan Tombol sembarang untuk kembali ke menu.. ";
				getch();
				break;
		}
	}while(menu != '4');

hapussemua(&L);

	return 0;
}



