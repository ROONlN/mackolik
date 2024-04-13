/*                      SAKARYA ÜNİVERSİTESİ
				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
					BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
					  PROGRAMLAMAYA GİRİŞİ DERSİ


ÖDEV NUMARASI: PROJE
ÖĞRENCİ ADI-SOYADI: HÜSEYİN AYDIN
ÖĞRENCİ NUMARASI: G231210046
DERS GRUBU: (İÖ) B GRUBU


*/

#include <iostream>
#include <locale.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>                     //Kütüphaneler
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Futbolcu {
protected:
	string tcNo;
	string ad;
	string soyad;
	string lisansNo;
	string mevki;                          //Futbolcu sınıfı oluşturup bu sınıfa ait nesneler oluşturuyoruz
	string ucret;
	string dTarihi;
	vector <string> oyuncuIsimler;
	vector <string> futbolcular;
public:
	ofstream fDosya;
	ifstream f1Dosya;

	string getTcNo() {
		return tcNo;
	}
	string getAd() {
		return ad;
	}
	string getSoyad() {
		return soyad;
	}                                        //public olmayan bilgileri class dışında da kullanabilmek için get fonksiyonları kullanıyoruz
	string getLisansNo() {
		return lisansNo;
	}
	string getMevki() {
		return mevki;
	}
	string getUcret() {
		return ucret;
	}
	string getDtarih() {
		return dTarihi;
	}

	void oyuncuEkle() {
		fDosya.open("Futbolcu.txt", ios::app);
		cout << "Futbolcunun TC numarasını giriniz: " << endl;
		cin >> tcNo;
		futbolcular.push_back(tcNo);
		cout << "Futbolcunun adını giriniz: " << endl;
		cin >> ad;
		oyuncuIsimler.push_back(ad);
		cout << "Futbolcunun soyadını giriniz: " << endl;
		cin >> soyad;
		cout << "Futbolcunun lisans numarasını giriniz: " << endl;                      //Oyuncu eklemek için fonksiyon kullanıyoruz
		cin >> lisansNo;
		cout << "Futbolcunun mevkisini giriniz: " << endl;
		cin >> mevki;
		cout << "Futbolcunun ücretini giriniz: " << endl;
		cin >> ucret;
		cout << "Futbolcunun doğum tarihini giriniz: " << endl;
		cin >> dTarihi;
		cout << endl;
		fDosya << tcNo << setw(20) << ad << setw(20) << soyad << setw(20) << lisansNo << setw(20) << mevki << setw(20) << ucret << setw(20) << dTarihi << endl;
		fDosya.close();
	}

	void oyuncuSil() {
		ofstream gecici("Gecici.txt");
		string tcNoKontrol;
		cout << "Silmek istediğiniz futbolcunun TC numarasını giriniz: " << endl;
		cin >> tcNoKontrol;
		f1Dosya.open("Futbolcu.txt", ios::in);

		while (f1Dosya >> tcNo >> ad >> soyad >> lisansNo >> mevki >> ucret >> dTarihi) {
			if (tcNoKontrol == tcNo) {
				cout << tcNo << " TC numaralı oyuncu silindi...!!!" << endl;
				cout << endl;
			}                                                                                //Oyuncu silmek için fonksiyon kullanıyoruz
			else {
				gecici << tcNo << setw(20) << ad << setw(20) << soyad << setw(20) << lisansNo << setw(20) << mevki << setw(20) << ucret << setw(20) << dTarihi << endl;
			}
		}
		f1Dosya.close();
		gecici.close();

		remove("Futbolcu.txt");
		rename("Gecici.txt", "Futbolcu.txt");
	}

	void oyuncuGuncelle() {
		ofstream gecici;
		gecici.open("Gecici.txt", ios::app);
		string tcNoDegistir;
		cout << "Bilgisini değiştirmek istediğiniz futbolcunun TC numarasını giriniz: " << endl;
		cin >> tcNoDegistir;
		f1Dosya.open("Futbolcu.txt", ios::in);

		while (f1Dosya >> tcNo >> ad >> soyad >> lisansNo >> mevki >> ucret >> dTarihi) {
			string tcNo, ad, soyad, lisansNo, mevki, ucret, dTarihi;
			if (tcNoDegistir == tcNo) {
				cout << "Futbolcunun TC numarasını giriniz: " << endl;
				cin >> tcNo;
				cout << "Futbolcunun adını giriniz: " << endl;
				cin >> ad;
				cout << "Futbolcunun soyadını giriniz: " << endl;
				cin >> soyad;
				cout << "Futbolcunun lisans numarasını giriniz: " << endl;
				cin >> lisansNo;
				cout << "Futbolcunun mevkisini giriniz: " << endl;                              //Oyuncu güncellemek için fonksiyon kullanıyoruz
				cin >> mevki;
				cout << "Futbolcunun ücretini giriniz: " << endl;
				cin >> ucret;
				cout << "Futbolcunun doğum tarihini giriniz: " << endl;
				cin >> dTarihi;
				cout << endl;

				gecici << tcNo << setw(20) << ad << setw(20) << soyad << setw(20) << lisansNo << setw(20) << mevki << setw(20) << ucret << setw(20) << dTarihi << endl;
			}
			else {
				gecici << tcNo << setw(20) << ad << setw(20) << soyad << setw(20) << lisansNo << setw(20) << mevki << setw(20) << ucret << setw(20) << dTarihi << endl;
			}
		}
		f1Dosya.close();
		gecici.close();

		remove("Futbolcu.txt");
		rename("Gecici.txt", "Futbolcu.txt");
	}

	void oyuncuListele() {

		f1Dosya.open("Futbolcu.txt", ios::in);
		while (f1Dosya >> tcNo >> ad >> soyad >> lisansNo >> mevki >> ucret >> dTarihi) {
			cout << "Oyuncunun TC numarası: " << tcNo << endl;
			cout << "Oyuncunun adı: " << ad << endl;
			cout << "Oyuncunun soyadı: " << soyad << endl;
			cout << "Oyuncunun lisans numarası: " << lisansNo << endl;                      // //Oyuncuları listelemek için fonksiyon kullanıyoruz
			cout << "Oyuncunun mevkisi: " << mevki << endl;
			cout << "Oyuncunun ücreti: " << ucret << endl;
			cout << "Oyuncunun doğum tarihi: " << dTarihi << endl;
			cout << endl;
		}
		f1Dosya.close();
	}
};

class Takim : public Futbolcu {
private:
	string takimNo;
	string takimAd;
	string adres;
	string telNo;                                                   //Takım bilgilerini oluşturacağımız için bir sınıf oluşturuyor ve nesneler tnımlıyoruz
	string baskan;
	vector <string> takimlar;
	int oyuncuSayisi;
public:
	ofstream tDosya;
	ifstream t1Dosya;

	void takimEkle() {
		tDosya.open("Takim.txt", ios::app);
		cout << "Takımın numarasını giriniz: " << endl;
		cin >> takimNo;
		cout << "Takımın adını giriniz: " << endl;
		cin >> takimAd;
		takimlar.push_back(takimAd);
		cout << "Takımın adresini giriniz: " << endl;
		cin >> adres;
		cout << "Takımın telefon numarasını giriniz: " << endl;                         ////Takım eklemek için fonksiyon kullanıyoruz
		cin >> telNo;
		cout << "Takımın başkanını giriniz: " << endl;
		cin >> baskan;
		cout << endl;
		oyuncuSayisi = futbolcular.size();
		tDosya << takimNo << setw(20) << takimAd << setw(20) << adres << setw(20) << oyuncuSayisi << setw(20) << baskan << setw(20) << telNo << endl;
		for (int i = 0; i < futbolcular.size(); ++i)
		{
			tDosya << futbolcular[i] << endl;
		}
		tDosya.close();
	}

	void takimSil() {
		ofstream gecici("Gecici.txt");
		string takimNoDegistir;
		cout << "Silmek istediğiniz takımın numarasını giriniz: " << endl;
		cin >> takimNoDegistir;
		t1Dosya.open("Takim.txt", ios::in);

		while (t1Dosya >> takimNo >> takimAd >> adres >> oyuncuSayisi >> baskan >> telNo) {
			if (takimNoDegistir == takimNo) {
				cout << takimNo << " numaralı takım silindi...!!!" << endl;                            //Takım silmek için fonksiyon kullanıyoruz
				cout << endl;
			}
			else {
				gecici << takimNo << setw(20) << takimAd << setw(20) << adres << setw(20) << oyuncuSayisi << setw(20) << baskan << setw(20) << telNo << endl;
				for (int i = 0; i < futbolcular.size(); ++i) {
					t1Dosya >> futbolcular[i];
					gecici << futbolcular[i] << endl;
				}
			}
		}
		t1Dosya.close();
		gecici.close();

		remove("Takim.txt");
		rename("Gecici.txt", "Takim.txt");
	}

	void futbolcuEkle() {
		string takimNoKontrol;
		cout << "Oyuncu eklemek istediğiniz takımın numarasını giriniz: " << endl;
		cin >> takimNoKontrol;
		if (takimNoKontrol == takimNo) {
			string tcKontrol;
			cout << "Takıma eklemek istediğiniz futbolcunun TC numarasını giriniz: " << endl;               //Takıma oyuncu eklemek için fonksiyon kullanıyoruz
			cin >> tcKontrol;
			if (tcKontrol == getTcNo()) {
				futbolcular.push_back(tcKontrol);
				cout << "Oyuncu takıma eklendi" << endl;
				cout << endl;
			}
		}
	}

	void futbolcuSil() {
		string takimNoKontrol;
		cout << "Oyuncu silmek istediğiniz takımın numarasını giriniz: " << endl;
		cin >> takimNoKontrol;
		if (takimNoKontrol == takimNo) {
			string tcKontrol;
			cout << "Takımdan silmek istediğiniz oyuncunun TC numarasını giriniz: " << endl;
			cin >> tcKontrol;
			auto ara = find(futbolcular.begin(), futbolcular.end(), tcKontrol);
			if (ara != futbolcular.end()) {
				futbolcular.erase(remove(futbolcular.begin(), futbolcular.end(), tcKontrol), futbolcular.end());     //Takımdan oyuncu silmek için fonksiyon kullanıyoruz
				cout << "Oyuncu silindi...!!!" << endl;
				cout << endl;
			}
			else {
				cout << "Oyuncu bulunamadı...!!!" << endl;
				cout << endl;
			}
		}
	}

	void futbolcuListele() {
		ifstream f3Dosya("Futbolcu.txt");
		string takimNoKontrol;
		cout << "Oyuncu listesini istediğiniz takımın numarasını giriniz: " << endl;
		cin >> takimNoKontrol;
		string satir;
		if (takimNoKontrol == takimNo) {
			for (int i = 0; i < futbolcular.size(); ++i)
			{
				string yaz(futbolcular[i]);                                        //Takımdaki oyuncuları listelemek için fonksiyon kullanıyoruz
				while (getline(f3Dosya, satir)) {
					if (satir.find(yaz) != string::npos) {
						cout << satir << endl;
						cout << endl;
					}
				}
			}
			f3Dosya.close();
		}
	}

	void futbolcuGuncelle() {
		string takimNoKontrol;
		cout << "Oyuncu bilgilerini değişmek istediğiniz takımın numarasını giriniz: " << endl;
		cin >> takimNoKontrol;
		if (takimNoKontrol == takimNo) {
			ofstream gecici;
			gecici.open("Gecici.txt", ios::app);
			string tcNoDegistir;
			cout << "Bilgisini değiştirmek istediğiniz futbolcunun TC numarasını giriniz: " << endl;
			cin >> tcNoDegistir;
			f1Dosya.open("Futbolcu.txt", ios::in);
			while (f1Dosya >> tcNo >> ad >> soyad >> lisansNo >> mevki >> ucret >> dTarihi) {
				string tcNo, ad, soyad, lisansNo, mevki, ucret, dTarihi;
				if (tcNoDegistir == tcNo) {
					cout << "Futbolcunun TC numarasını giriniz: " << endl;
					cin >> tcNo;                                                                        //Takımdaki oyuncuları güncellemek için fonksiyon kullanıyoruz
					auto ara = find(futbolcular.begin(), futbolcular.end(), tcNoDegistir);
					if (ara != futbolcular.end()) {
						*ara == tcNo;
						cout << endl;
					}
					cout << "Futbolcunun adını giriniz: " << endl;
					cin >> ad;
					cout << "Futbolcunun soyadını giriniz: " << endl;
					cin >> soyad;
					cout << "Futbolcunun lisans numarasını giriniz: " << endl;
					cin >> lisansNo;
					cout << "Futbolcunun mevkisini giriniz: " << endl;
					cin >> mevki;
					cout << "Futbolcunun ücretini giriniz: " << endl;
					cin >> ucret;
					cout << "Futbolcunun doğum tarihini giriniz: " << endl;
					cin >> dTarihi;
					cout << endl;

					gecici << tcNo << setw(20) << ad << setw(20) << soyad << setw(20) << lisansNo << setw(20) << mevki << setw(20) << ucret << setw(20) << dTarihi << endl;
				}
				else {
					gecici << tcNo << setw(20) << ad << setw(20) << soyad << setw(20) << lisansNo << setw(20) << mevki << setw(20) << ucret << setw(20) << dTarihi << endl;
				}
			}
			f1Dosya.close();
			gecici.close();

			remove("Futbolcu.txt");
			rename("Gecici.txt", "Futbolcu.txt");
		}
	}

	void takimListele() {
		t1Dosya.open("Takim.txt", ios::in);
		while (t1Dosya >> takimNo >> takimAd >> adres >> oyuncuSayisi >> baskan >> telNo) {
			cout << "Takım numarası: " << takimNo << endl;
			cout << "Takım adı: " << takimAd << endl;
			cout << "Adres: " << adres << endl;                                                       //Takımları listelemek için fonksiyon kullanıyoruz
			cout << "Oyuncu sayısı: " << oyuncuSayisi << endl;
			cout << "Takım başkanı: " << baskan << endl;
			cout << "Takım telefon numarası: " << telNo << endl;
			cout << endl;
		}
		t1Dosya.close();
	}

	void maclar() {
		vector <int> puanlar(takimlar.size(), 0);

		for (int i = 0; i < takimlar.size(); ++i)
		{
			for (int y = 1; y < takimlar.size(); ++y)
			{
				cout << takimlar[i] << " VS " << takimlar[y] << endl;
				int takim1gol = rand() % 10;
				int takim2gol = rand() % 10;
				int random = rand() % oyuncuIsimler.size();
				cout << "Maç sonucu: " << takim1gol << " - " << takim2gol << endl;
				cout << "Goller" << endl;
				for (int i = 1; i < takim1gol; i++)
				{
					cout << takimlar[i] << ": " << endl;
					cout << rand() % 91 << oyuncuIsimler[random] << endl;
				}
				for (int i = 1; i < takim1gol; i++)                                            //Takımlara maçları oynatıyor, golleri ve puanları hesaplıyoruz
				{
					cout << takimlar[y] << ": " << endl;
					cout << rand() % 91 << oyuncuIsimler[random] << endl;
				}

				if (takim1gol < takim2gol) {
					puanlar[y] = puanlar[y] + 3;
				}
				else if (takim1gol > takim2gol) {
					puanlar[i] = puanlar[i] + 3;
				}
				else {
					puanlar[y] = puanlar[y] + 1;
					puanlar[i] = puanlar[i] + 1;
				}
			}
		}

		for (int a = 0; a < takimlar.size(); ++a)
		{
			cout << "PUAN DURUMU" << endl;
			cout << endl;
			cout << takimlar[a] << " = " << puanlar[a] << endl;
			cout << endl;
		}
	}

};


int main()
{
	setlocale(LC_ALL, "Turkish");
/*
	remove("Takim.txt");
	remove("Gecici.txt");
	remove("Futbolcu.txt");
*/
	Takim n1;
	int secim;
	do {
		cout << "Lütfen işlem yapmak istediğiniz numarayı giriniz: " << endl;
		cout << "1-)Takım işlemleri" << endl;
		cout << "2-)Futbolcu işlemleri" << endl;
		cout << "3-)Maçları ve puan durumunu göster " << endl;
		cout << "4-)Çıkış yap" << endl;
		cin >> secim;
		if (secim == 1) {

			int secim2;
			do {
				cout << "Lütfen işlem yapmak istediğiniz numarayı giriniz: " << endl;
				cout << "1-)Takım oluştur" << endl;
				cout << "2-)Takım sil" << endl;
				cout << "3-)Takıma futbolcu ekle" << endl;
				cout << "4-)Takımdan futbolcu sil" << endl;
				cout << "5-)Takımdaki futbolcuları listele" << endl;
				cout << "6-)Takımdaki bir futblcuyu güncelle" << endl;
				cout << "7-)Takımları listele" << endl;
				cout << "8-)Çıkış yap" << endl;
				cin >> secim2;
				cout << endl;
				switch (secim2)
				{
				case 1:
					n1.takimEkle();
					break;
				case 2:
					n1.takimSil();
					break;
				case 3:
					n1.futbolcuEkle();
					break;
				case 4:
					n1.futbolcuSil();
					break;
				case 5:
					n1.futbolcuListele();
					break;
				case 6:
					n1.futbolcuGuncelle();
					break;
				case 7:
					n1.takimListele();
					break;
				case 8:
					cout << "Çıkış yapılıyor" << endl;
					cout << endl;
					break;
				default:
					cout << "Hatalı tuşlama yaptınız...!!!" << endl;
					cout << endl;
					break;
				}
			} while (secim2 != 8);
		}
		else if (secim == 2) {
			Futbolcu oyuncu;
			int secim3;
			do {
				cout << "Lütfen işlem yapmak istediğiniz numarayı giriniz: " << endl;
				cout << "1-)Oyuncu ekle" << endl;
				cout << "2-)Oyuncu sil" << endl;
				cout << "3-)Oyuncu güncelle " << endl;
				cout << "4-)Oyuncuları listele" << endl;
				cout << "5-)Çıkış yap" << endl;
				cin >> secim3;
				cout << endl;
				switch (secim3)
				{
				case 1:
					oyuncu.oyuncuEkle();
					break;
				case 2:
					oyuncu.oyuncuSil();
					break;
				case 3:
					oyuncu.oyuncuGuncelle();
					break;
				case 4:
					oyuncu.oyuncuListele();
					break;
				case 5:
					cout << "Çıkış yapılıyor" << endl;
					cout << endl;
					break;
				default:
					cout << "Hatalı tuşlama yaptınız...!!!" << endl;
					cout << endl;
					break;
				}
			} while (secim3 != 5);
		}
		else if (secim == 3) {
			n1.maclar();
			cout << endl;
		}
		else if (secim == 4) {
			cout << "Çıkış yapılıyor" << endl;
			cout << endl;
		}
		else {
			cout << "Hatalı tuşlama yaptınız...!!!" << endl;
			cout << endl;
		}
	} while (secim != 4);
}