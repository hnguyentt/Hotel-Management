#include "PHONG.h"
#include"TABLE.h"
#include"KHACHSAN.h"


PHONG::PHONG()
{
}


PHONG::~PHONG()
{
}

string PHONG::GetMP() {
	return maPhong;
}
string PHONG::GetMaLP() {
	return maLoaiPhong;
}
string PHONG::GetMaLau() {
	return maLau;
}
int PHONG::GetStatus() {
	return status;
}
LOAIPHONG PHONG::GetLoaiPhong() {
	return loaiPhong;
}

void PHONG::SetMP(string MP) {
	maPhong = MP;
}
void PHONG::SetMaLP(string MLP) {
	maLoaiPhong = MLP;
}
void PHONG::SetMaLau(string ML) {
	maLau = ML;
}
void PHONG::SetStatus(int n) {
	status = n;
}
void PHONG::SetLoaiPhong(LOAIPHONG lp) {
	loaiPhong.SetMaLP(lp.GetMaLP());
	loaiPhong.SetTenLP(lp.GetTenLP());
	loaiPhong.SetSoGiuong(lp.GetSoGiuong());
	loaiPhong.SetDVKem(lp.GetDVKem());
	loaiPhong.SetDonGia(lp.GetDonGia());
}
void PHONG::Nhap() {
	cout << "\nEnter Room type code: ";
	cin >> maLoaiPhong;
	cin.ignore();
	while (!KiemTraLoaiPhong(maLoaiPhong)) {
		cout << "\nThe room type code does not exist. Please try again: ";
		cin >> maLoaiPhong;
		cin.ignore();
	}
	cout << "Enter Room status: ";
	cin >> status;
	KHACHSAN khachsan;
	khachsan.SetDSLoaiPhong(khachsan.DocDSLoaiPhong());
	for (int i = 0; i < khachsan.GetDSLoaiPhong().size(); i++) {
		if (maLoaiPhong == khachsan.GetDSLoaiPhong()[i].GetMaLP()) {
			SetLoaiPhong(khachsan.GetDSLoaiPhong()[i]);
		}
	}
}
void PHONG::Xuat() {
	TABLE T('-', '|', '*');
	T.add("Room code");
	T.add("Room type code");
	T.add("Room type name");
	T.add("N of beds");
	T.add("Services");
	T.add("Unit price");
	T.add("Room status");
	T.endOfRow();

	T.add(maPhong);
	T.add(maLoaiPhong);
	T.add(loaiPhong.GetTenLP());
	T.add(to_string(loaiPhong.GetSoGiuong()));
	T.add(loaiPhong.GetDVKem());
	T.add(to_string(loaiPhong.GetDonGia()));
	T.add(to_string(status));
	T.endOfRow();
	T.setAlignment(6, TABLE::Alignment::RIGHT);
	
	cout << T;
}
bool PHONG::KiemTraLoaiPhong(string code) {
	bool check = false;
	KHACHSAN khachsan;
	vector<LOAIPHONG> dsLP = khachsan.DocDSLoaiPhong();
	for (int i = 0; i < dsLP.size(); i++) {
		if (code == dsLP[i].GetMaLP()) {
			check = true;
		}
	}
	return check;
}