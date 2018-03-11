#include "LOAIPHONG.h"
#include"TABLE.h"
#include "KHACHSAN.h"



LOAIPHONG::LOAIPHONG()
{
}


LOAIPHONG::~LOAIPHONG()
{
}
string LOAIPHONG::GetMaLP() {
	return maLoaiPhong;
}
string LOAIPHONG::GetTenLP() {
	return tenLoaiPhong;
}
int LOAIPHONG::GetSoGiuong() {
	return soGiuong;
}
string LOAIPHONG::GetDVKem() {
	return dichVuKem;
}
float LOAIPHONG::GetDonGia() {
	return donGiaPhong;
}
void LOAIPHONG::SetMaLP(string mlp) {
	maLoaiPhong = mlp;
}
void LOAIPHONG::SetTenLP(string tlp) {
	tenLoaiPhong = tlp;
}
void LOAIPHONG::SetSoGiuong(int n) {
	soGiuong = n;
}
void LOAIPHONG::SetDVKem(string dvk) {
	dichVuKem = dvk;
}
void LOAIPHONG::SetDonGia(float n) {
	donGiaPhong = n;
}
void LOAIPHONG::Nhap() {
	cout << "Enter Room type name: ";
	getline(cin, tenLoaiPhong);
	cin.ignore();
	cout << "Enter number of beds: ";
	cin >> soGiuong;
	cin.ignore();
	cout << "Enter accompanied services (seperated by '-'): ";
	getline(cin, dichVuKem);
	cin.ignore(1000,'\n');
	cout << "Enter Room's unit price: ";
	cin >> donGiaPhong;
}
void LOAIPHONG::Xuat() {
	TABLE T('-', '|', '*');
	T.add("Room Type Code");
	T.add("Room Type Name");
	T.add("Number of beds");
	T.add("Accompanied services");
	T.add("Unit Price");
	T.endOfRow();

	T.add(maLoaiPhong);
	T.add(tenLoaiPhong);
	T.add(to_string(soGiuong));
	T.add(dichVuKem);
	T.add(to_string(donGiaPhong));
	T.endOfRow();
	T.setAlignment(2, TABLE::Alignment::RIGHT);
	T.setAlignment(4, TABLE::Alignment::RIGHT);
	cout << T;
}
