#include "DICHVU.h"
#include "TABLE.h"
#include"KHACHSAN.h"


DICHVU::DICHVU()
{
}


DICHVU::~DICHVU()
{
}
string DICHVU::GetMDV() {
	return maDV;
}
string DICHVU::GetTDV() {
	return tenDV;
}
int DICHVU::GetSL() {
	return soLuong;
}
float DICHVU::GetGiaMua() {
	return giaMua;
}
float DICHVU::GetDonGia() {
	return donGia;
}
void DICHVU::SetMDV(string mdv) {
	maDV = mdv;
}
void DICHVU::SetTDV(string tdv) {
	tenDV = tdv;
}
void DICHVU::SetSL(int n) {
	soLuong = n;
}
void DICHVU::SetDonGia(float n) {
	donGia = n;
}
float DICHVU::GetThanhTien() {
	return thanhTien;
}
void DICHVU::SetGiaMua(float gm) {
	giaMua = gm;
}
void DICHVU::SetThanhTien(float n) {
	thanhTien = n;
}
void DICHVU::Nhap() {
	cout << "Enter service code: ";
	cin >> maDV;
	cin.ignore();
	while (!IsMaDV(maDV)) {
		cout << "\nThis code is not valid. Please try again: ";
		cin >> maDV;
		cin.ignore();
	}
	cout << "Enter quantity: ";
	cin >> soLuong;
	vector<LOAIDICHVU> dsLoaiDV;
	KHACHSAN khachsan;
	dsLoaiDV = khachsan.DocDSLoaiDV();
	for (int i = 0; i < dsLoaiDV.size(); i++) {
		if (dsLoaiDV[i].GetMDV()==maDV)
		{
			tenDV = dsLoaiDV[i].GetTenDV();
			donGia = dsLoaiDV[i].GetGiaBan();
			giaMua = dsLoaiDV[i].GetGiaMua();
		}
	}
	thanhTien = donGia * soLuong;
}

void DICHVU::Xuat() {
	TABLE T('-', '|', '*');
	T.add("Code");
	T.add("Name");
	T.add("Unit price");
	T.add("Quantity");
	T.add("Total");
	T.endOfRow();

	T.add(maDV);
	T.add(tenDV);
	T.add(to_string(donGia));
	T.add(to_string(soLuong));
	T.add(to_string(thanhTien));
	T.endOfRow();
	T.setAlignment(2, TABLE::Alignment::RIGHT);
	T.setAlignment(3, TABLE::Alignment::RIGHT);
	T.setAlignment(4, TABLE::Alignment::RIGHT);
	
	cout << T;
}
bool DICHVU::IsMaDV(string code) {
	bool check = false;
	KHACHSAN khachsan;
	vector<LOAIDICHVU> dsLoaiDV = khachsan.DocDSLoaiDV();
	for (int i = 0; i < dsLoaiDV.size(); i++) {
		if (code == dsLoaiDV[i].GetMDV()) {
			check = true;
		}
	}
	return check;
}
