#include <iostream>
#include <iomanip>
using namespace std;

class sks {
	public :
		void input ();
		void proses ();
		int rekursif (int j, int i);
		void output ();
	private :
		string a[20];
		string nama, prodi;
		int b [20];
		int hsks = 150000;
		int bykA, i, nim;
		float total, total_biaya, jml_sks, diskon;
};

void sks::input() {
	cout<<"======================================"<<endl;
	cout<<"|           Pembayaran SKS           |"<<endl;
	cout<<"======================================"<<endl;
	cout<<" Nama  : "; cin>>nama;
	cout<<" NIM   : "; cin>>nim;
	cout<<" Prodi : "; cin>>prodi;
	cout<<" Jumlah Matkul di Ambil : "; cin>>bykA;
	cout<<"======================================"<<endl;
	for(i=0; i<bykA; i++) {
		cout<<"Mata Kuliah "<<i+1<< "          : "; cin.ignore();
		getline(cin, a[i]);
		cout<<"Satuan Kredit Semester : "; cin>>b[i];
		cout<<"======================================"<<endl;
	}
} 

int sks::rekursif(int j, int i) {
	if(i < 0) {
		return i;
	}
	else {
		jml_sks += b[i];
		total   += hsks * b[i];
		return rekursif (j, (i-1));
	}
}

void sks::proses() {
	int j = 1;
	i--;
	rekursif (j, i);
	diskon      = total * 0.25;
	total_biaya = total - diskon;
}

void sks::output() {
	cout<<"======================================"<<endl;
	cout<<"| Nama  : "<<nama<<"                    |"<<endl;
	cout<<"| NIM   : "<<nim<<"                 |"<<endl;
	cout<<"| Prodi : "<<prodi<<"                |"<<endl;
	cout<<"======================================"<<endl;	
	cout<<"|    Mata Kuliah   |       SKS       |"<<endl;
    cout<<"======================================"<<endl;
	for(i=0; i<bykA; i++) {
		cout<<" ";
		cout<<setiosflags(ios::left)<<setw(26)<<a[i]<<" ";
		cout<<setiosflags(ios::left)<<setw(2)<<b[i]<<endl;
	}
	cout<<"======================================"<<endl;
	cout<<"| Jumlah SKS       : "<<jml_sks<<"               |"<<endl;
	cout<<"| Total Pembayaran : "<<total_biaya<<"          |"<<endl;
	cout<<"======================================"<<endl;
}

int main() {
	sks a;
	a.input();
	a.proses();
	a.output();
}
