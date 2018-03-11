#include "NgayThangNam.h"
#include<string>

NgayThangNam::NgayThangNam()
{
}


NgayThangNam::~NgayThangNam()
{
}
int NgayThangNam::GetNgay() {
	return ngay;
}
int NgayThangNam::GetThang() {
	return thang;
}
int NgayThangNam::GetNam() {
	return nam;
}
void NgayThangNam::SetNgay(int n) {
	ngay = n;
}
void NgayThangNam::SetThang(int n) {
	thang = n;
}
void NgayThangNam::SetNam(int n) {
	nam = n;
}
bool NgayThangNam::XetNamNhuan() {
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100!=0)) {
		return true;
	}
	else
	{
		return false;
	}
}
void NgayThangNam::Nhap() {
	cout << "Enter day: ";
	cin >> ngay;
	cout << "Enter month: ";
	cin >> thang;
	cout << "Enter year: ";
	cin >> nam;
}
string NgayThangNam::Xuat() {
	string xuat = to_string(ngay) + "/" + to_string(thang)+"/"+to_string(nam);
	return xuat;
}
//Convert date to integer denoting the number of days since an epoch
int NgayThangNam::RDN(int d, int m, int y) {
	if (m < 3) {
		y--;
		m += 12;
	}
	return (365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306);
}