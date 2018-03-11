#include "LOAIDICHVU.h"
#include"TABLE.h"
#include "KHACHSAN.h"

LOAIDICHVU::LOAIDICHVU()
{
}


LOAIDICHVU::~LOAIDICHVU()
{
}
string LOAIDICHVU::GetMDV() {
	return maDV;
}
string LOAIDICHVU::GetTenDV() {
	return tenDV;
}
float LOAIDICHVU::GetGiaMua() {
	return giaMua;
}
float LOAIDICHVU::GetGiaBan() {
	return giaBan;
}
void LOAIDICHVU::SetMDV(string mdv) {
	maDV = mdv;
}
void LOAIDICHVU::SetTenDV(string tdv) {
	tenDV = tdv;
}
void LOAIDICHVU::SetGiaMua(float n) {
	giaMua = n;
}
void LOAIDICHVU::SetGiaBan(float n) {
	giaBan = n;
}
void LOAIDICHVU::Nhap() {
	cout << "\nEnter service name: ";
	getline(cin, tenDV);
	cin.ignore();
	cout << "Enter purchase price: ";
	cin >> giaMua;
	cout << "Enter price: ";
	cin >> giaBan;
}
void LOAIDICHVU::Xuat() {
	TABLE T('-', '|', '*');
	T.add("Code");
	T.add("Name");
	T.add("Purchase price");
	T.add("Unit Price");
	T.endOfRow();

	T.add(maDV);
	T.add(tenDV);
	T.add(to_string(giaMua));
	T.add(to_string(giaBan));
	T.setAlignment(2, TABLE::Alignment::RIGHT);
	T.setAlignment(3, TABLE::Alignment::RIGHT);
	cout << T;
}
bool LOAIDICHVU::KiemTraLoaiDV(string code) {
	KHACHSAN khachsan;
	vector<LOAIDICHVU> dsLoaiDV = khachsan.DocDSLoaiDV();
	bool check = false;
	for (int i = 0; i < dsLoaiDV.size(); i++) {
		if (code == dsLoaiDV[i].GetMDV()) {
			check = true;
		}
	}
	return check;
}