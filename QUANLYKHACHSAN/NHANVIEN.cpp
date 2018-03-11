#include "NHANVIEN.h"
#include "TABLE.h"
#include "KHACHSAN.h"


NHANVIEN::NHANVIEN()
{
}


NHANVIEN::~NHANVIEN()
{
}
void NHANVIEN::Nhap() {
	cout << "Enter employee's password: ";
	getline(cin, password);
	cout << "Enter employee's name: ";
	getline(cin, tenNV);
	cout << "Enter position code: ";
	getline(cin, maCV);
	while (maCV != "GD"&&maCV != "QL"&&maCV != "TT") {
		cout << "\nPosition code is not valid. Please re-enter the position code:";
		getline(cin, maCV);
	}
	if (maCV == "GD") {
		chucVu = "Director";
	}
	else if (maCV == "QL") {
		chucVu = "Manager";
	}
	else {
		chucVu = "Receptionist";
	}
	gioLamViec = 0;
	luong = 0;
}
void NHANVIEN::Xuat() {
	
	TABLE T('-', '|', '*');
	T.add("Code");
	T.add("Password");
	T.add("Name");
	T.add("Position");
	T.add("Working hours");
	T.add("Salary");
	T.endOfRow();

	T.add(maNV);
	T.add(password);
	T.add(tenNV);
	T.add(chucVu);
	T.add(to_string(gioLamViec));
	T.add(to_string(luong));
	T.endOfRow();
	T.setAlignment(4, TABLE::Alignment::RIGHT);
	T.setAlignment(5, TABLE::Alignment::RIGHT);
	
	cout << T;
}
float NHANVIEN::TinhLuong(vector<HSLUONG> dsHSL, float& wh) {
	cout << "Enter number of working hours of " << tenNV << ": ";
	cin >> wh;
	for (int i = 0; i < dsHSL.size(); i++) {
		if (maCV == dsHSL[i].GetMCV()) {
			if (wh > 160) {
				luong = 160 * dsHSL[i].GetHSLCoBan() + (wh - 160)*dsHSL[i].GetHSLNgoaiGio();
			}
			else {
				luong = wh*dsHSL[i].GetHSLCoBan();
			}
		}
	}
	return luong;
}

bool NHANVIEN::KiemTraGD() {
	bool check = false;
	if (maCV == "GD") {
		check = true;
	}
	return check;
}

string NHANVIEN::GetMaNV() {
	return maNV;
}
string NHANVIEN::GetPw() {
	return password;
}
string NHANVIEN::GetTen() {
	return tenNV;
}
string NHANVIEN::GetMaCV() {
	return maCV;
}
float NHANVIEN::GetGioLamViec() {
	return gioLamViec;
}
void NHANVIEN::SetMaNV(string manv) {
	maNV = manv;
}
void NHANVIEN::SetPwd(string pwd) {
	password = pwd;
}
void NHANVIEN::SetTenNV(string ten) {
	tenNV = ten;
}
void NHANVIEN::SetmaCV(string macv) {
	maCV = macv;
}
void NHANVIEN::SetGioLamViec(float wh) {
	gioLamViec = wh;
}
void NHANVIEN::SetLuong(float l) {
	luong = l;
}
float NHANVIEN::GetLuong() {
	return luong;
}
void NHANVIEN::SetCV(string a) {
	chucVu = a;
}
string NHANVIEN::GetCV() {
	return chucVu;
}