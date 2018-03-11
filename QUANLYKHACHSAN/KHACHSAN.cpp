#include "KHACHSAN.h"
#include"TABLE.h"
#include<fstream>


KHACHSAN::KHACHSAN()
{
}


KHACHSAN::~KHACHSAN()
{
}
vector<LOAIPHONG> KHACHSAN::GetDSLoaiPhong() {
	return dsLoaiPhong;
}
vector<LOAIDICHVU> KHACHSAN::GetDSLoaiDichVu() {
	return dsLoaiDichVu;
}
vector<PHONG> KHACHSAN::GetDSPhong() {
	return dsPhong;
}
vector<KHACHHANG> KHACHSAN::GetDSKhachHang() {
	return dsKhachHang;
}
vector<NHANVIEN> KHACHSAN::GetDSNhanVien() {
	return dsNhanVien;
}
vector<KHACHHANG> KHACHSAN::GetDSBill() {
	return dsBill;
}
vector<HSLUONG> KHACHSAN::GetdsHSL() {
	return dsHSL;
}

void KHACHSAN::SetDSBill(vector<KHACHHANG> dsbill) {
	for (int i = 0; i < dsbill.size(); i++) {
		dsBill[i].SetMKH(dsbill[i].GetMKH());
		dsBill[i].SetTenKH(dsbill[i].GetTKH());
		dsBill[i].SetMP(dsbill[i].GetMP());
		dsBill[i].SetPhong(dsbill[i].GetPhong());
		dsBill[i].SetCheckin(dsbill[i].GetCheckin());
		dsBill[i].SetCheckout(dsbill[i].GetCheckout());
		dsBill[i].SetSoNgay(dsbill[i].GetSoNgay());
		dsBill[i].SetTienPhong(dsbill[i].GetTienPhong());
		dsBill[i].SetTienDV(dsbill[i].GetTienDV());
		dsBill[i].SetTongTien(dsbill[i].GetTongTien());
		dsBill[i].SetdsDV(dsbill[i].GetDSDichVu());
		dsBill.push_back(dsBill[i]);
	}
}
void KHACHSAN::SetDSLoaiPhong(vector<LOAIPHONG> dsLP) {
	for (int i = 0; i < dsLP.size(); i++) {
		dsLoaiPhong.push_back(dsLoaiPhong[i]);
	}
}
void KHACHSAN::SetDSLoaiDichVu(vector<LOAIDICHVU> dsloaidv) {
	for (int i = 0; i < dsloaidv.size(); i++) {
		dsLoaiDichVu.push_back(dsloaidv[i]);
	}
}
void KHACHSAN::SetDSPhong(vector<PHONG> a) {
	for (int i = 0; i < a.size(); i++) 
	{
		dsPhong.push_back(a[i]);
	}
}
void KHACHSAN::SetDSKhachHang(vector<KHACHHANG> a) {
	for (int i = 0; i < a.size(); i++) {
		dsKhachHang.push_back(a[i]);
	}
}
void KHACHSAN::SetDSNhanVien(vector<NHANVIEN> a) {
	for (int i = 0; i < a.size(); i++) {
		dsNhanVien[i].SetMaNV(a[i].GetMaNV());
		dsNhanVien[i].SetPwd(a[i].GetPw());
		dsNhanVien[i].SetTenNV(a[i].GetTen());
		dsNhanVien[i].SetmaCV(a[i].GetMaCV());
		dsNhanVien[i].SetCV(a[i].GetCV());
		dsNhanVien[i].SetGioLamViec(a[i].GetGioLamViec());
		dsNhanVien[i].SetLuong(a[i].GetLuong());
	}
}
void KHACHSAN::SetDSHSL(vector<HSLUONG> dshsl) {
	for (int i = 0; i < dsHSL.size(); i++) {
		dsHSL[i].SetMCV(dshsl[i].GetMCV());
		dsHSL[i].SetHSLCoBan(dshsl[i].GetHSLCoBan());
		dsHSL[i].SetHSLNgoaiGio(dshsl[i].GetHSLNgoaiGio());
	}
}

int KHACHSAN::DemNhanVien(string mCV) {
	int soNhanVien = 0;
	for (int i = 0; i < dsNhanVien.size(); i++) {
		if (mCV == dsNhanVien[i].GetMaCV()) {
			soNhanVien++;
		}
	}
	return soNhanVien;
}

void KHACHSAN::XuatDSLoaiDichVu() {
	TABLE T('-', '|', '*');
	T.add("Code");
	T.add("Name");
	T.add("Purchase price");
	T.add("Unit Price");
	T.endOfRow();

	for (int i = 0; i < dsLoaiDichVu.size(); i++) {
		T.add(dsLoaiDichVu[i].GetMDV());
		T.add(dsLoaiDichVu[i].GetTenDV());
		T.add(to_string(dsLoaiDichVu[i].GetGiaMua()));
		T.add(to_string(dsLoaiDichVu[i].GetGiaBan()));
		T.endOfRow();
		T.setAlignment(2, TABLE::Alignment::RIGHT);
		T.setAlignment(3, TABLE::Alignment::RIGHT);
	}
	cout << T;
}
void KHACHSAN::XuatDSLoaiPhong() {
	TABLE T('-', '|', '*');
	T.add("Room Type Code");
	T.add("Room Type Name");
	T.add("Number of beds");
	T.add("Accompanied services");
	T.add("Unit Price");
	T.endOfRow();
	for (int i = 0; i < dsLoaiPhong.size();i++) {
		T.add(dsLoaiPhong[i].GetMaLP());
		T.add(dsLoaiPhong[i].GetTenLP());
		T.add(to_string(dsLoaiPhong[i].GetSoGiuong()));
		T.add(dsLoaiPhong[i].GetDVKem());
		T.add(to_string(dsLoaiPhong[i].GetDonGia()));
		T.endOfRow();
		T.setAlignment(2, TABLE::Alignment::RIGHT);
		T.setAlignment(4, TABLE::Alignment::RIGHT);
	}
	cout << T;
}
void KHACHSAN::XuatDSPhong() {
	TABLE T('-', '|', '*');
	T.add("Room code");
	T.add("Room type code");
	T.add("Room type name");
	T.add("N of beds");
	T.add("Services");
	T.add("Unit price");
	T.add("Room status");
	T.endOfRow();

	for (int i = 0; i < dsPhong.size(); i++) {
		T.add(dsPhong[i].GetMP());
		T.add(dsPhong[i].GetMaLP());
		T.add(dsPhong[i].GetLoaiPhong().GetTenLP());
		T.add(to_string(dsPhong[i].GetLoaiPhong().GetSoGiuong()));
		T.add(dsPhong[i].GetLoaiPhong().GetDVKem());
		T.add(to_string(dsPhong[i].GetLoaiPhong().GetDonGia()));
		T.add(to_string(dsPhong[i].GetStatus()));
		T.endOfRow();
		T.setAlignment(5, TABLE::Alignment::RIGHT);
	}
	cout << T;
}
void KHACHSAN::XuatDSKhachHang(vector<KHACHHANG> DS) {
	if (DS.size() == 0) {
		cout << "\nNo customer is available\n";
	}
	else {
		TABLE t('-', '|', '*');

		t.add("Customer code");
		t.add("Customer's name");
		t.add("Room code");
		t.add("Checkin");
		t.endOfRow();

		for (int i = 0; i < DS.size(); i++) {
			t.add(DS[i].GetMKH());
			t.add(DS[i].GetTKH());
			t.add(DS[i].GetMP());
			t.add(DS[i].GetCheckin().Xuat());
			t.endOfRow();
		}
		cout << t;
	}
}
void KHACHSAN::XuatBill() {
	if (dsBill.size() == 0) {
		cout << "No bill has been been exported";
	}
	else {
		for (int i = 0; i < dsBill.size(); i++) {
			cout << "BILL " << i+1 << "\n\n";
			dsBill[i].XuatThongTinTinhTien();
			cout << "###################\n\n\n";
		}
	}
}
void KHACHSAN::XuatDSNhanVien() {
	TABLE T('-', '|', '*');
	T.add("Employee Code");
	T.add("Password");
	T.add("Name");
	T.add("Position");
	T.add("Working hours");
	T.add("Salary");
	T.endOfRow();

	for (int i = 0; i < dsNhanVien.size(); i++) {
		T.add(dsNhanVien[i].GetMaNV());
		T.add(dsNhanVien[i].GetPw());
		T.add(dsNhanVien[i].GetTen());
		T.add(dsNhanVien[i].GetCV());
		T.add(to_string(dsNhanVien[i].GetGioLamViec()));
		T.add(to_string(dsNhanVien[i].GetLuong()));
		T.endOfRow();
		T.setAlignment(4, TABLE::Alignment::RIGHT);
		T.setAlignment(5, TABLE::Alignment::RIGHT);
	}
	cout << T;
}
void KHACHSAN::XuatDSHSL() {
	TABLE t('-', '|', '*');

	t.add("Position code");
	t.add("Salary/hour");
	t.add("Salary/extra hour");
	t.endOfRow();

	for (int i = 0; i < dsHSL.size(); i++) {
		t.add(dsHSL[i].GetMCV());
		t.add(to_string(dsHSL[i].GetHSLCoBan()));
		t.add(to_string(dsHSL[i].GetHSLNgoaiGio()));
		t.endOfRow();
		t.setAlignment(1, TABLE::Alignment::RIGHT);
		t.setAlignment(2, TABLE::Alignment::RIGHT);
	}
	cout << t;
}


vector<LOAIPHONG> KHACHSAN::DocDSLoaiPhong() {
	LOAIPHONG loaiPhong;
	string luu;
	ifstream f("../DATA/LoaiPhong.txt");
	if (!f.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (f.good()) {
		getline(f, luu,',');
		if (luu == "") {
			break;
		}
		loaiPhong.SetMaLP(luu);
		getline(f, luu, ',');
		loaiPhong.SetTenLP(luu);
		getline(f, luu, ',');
		loaiPhong.SetSoGiuong(stoi(luu));
		getline(f, luu, ',');
		loaiPhong.SetDVKem(luu);
		getline(f, luu, '\n');
		loaiPhong.SetDonGia(stof(luu));
		dsLoaiPhong.push_back(loaiPhong);
	}
	f.close();
	return dsLoaiPhong;
}
void KHACHSAN::ThemLoaiPhong() {
	LOAIPHONG loaiPhong;
	string temp;
	cout << "Current Room Type List: " << endl;
	XuatDSLoaiPhong();
	int n;
	cout << "Enter number of Room Types to be added: ";
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			cout << "Enter Room type code: ";
			cin >> temp;
			cin.ignore();
			while (KiemTraLoaiPhong(temp)) {
				cout << "\nThis room type already exist. Please enter another one:";
				cin >> temp;
				cin.ignore();
			}
			loaiPhong.SetMaLP(temp);
			loaiPhong.Nhap();
			dsLoaiPhong.push_back(loaiPhong);
		}
		GhiDSLoaiPhong();
		cout << "\nNew Room Type List: " << endl;
		XuatDSLoaiPhong();
	}
}
bool KHACHSAN::KiemTraLoaiPhong(string code) {
	bool check = false;
	for (int i = 0; i < dsLoaiPhong.size(); i++) {
		if (code == dsLoaiPhong[i].GetMaLP()) {
			check = true;
		}
	}
	return check;
}
void KHACHSAN::XoaLoaiPhong() {
	string code;
	cin.ignore();
	cout << "\nEnter room type code to be deleted: ";
	getline(cin, code);
	bool check = false;
	for (int i = 0; dsLoaiPhong.size(); i++) {
		if (dsLoaiPhong[i].GetMaLP() == code) {
			dsLoaiPhong.erase(dsLoaiPhong.begin() + i);
			check = true;
		}
	}
	if (!check) {
		cout << "\nNo Room type with the entered code";
	}
	else {
		GhiDSLoaiPhong();
		cout << "\nRoom type " << code << " has been deleted." << endl;
	}
}
void KHACHSAN::SuaGiaPhong() {
	float temp;
	cout << "Current Room Price table: " << endl;
	XuatDSLoaiPhong();
	for (int i = 0; i < dsLoaiPhong.size(); i++) {
		cout << "Enter Price for " << dsLoaiPhong[i].GetTenLP() << ": ";
		cin >> temp;
		dsLoaiPhong[i].SetDonGia(temp);
	}
	GhiDSLoaiPhong();

}
void KHACHSAN::GhiDSLoaiPhong() {
	remove("../DATA/LoaiPhong.txt");
	fstream f;
	f.open("../DATA/LoaiPhong.txt", ios::app);
	for (int i = 0; i < dsLoaiPhong.size(); i++) {
		f << dsLoaiPhong[i].GetMaLP() << ",";
		f << dsLoaiPhong[i].GetTenLP() << ",";
		f << dsLoaiPhong[i].GetSoGiuong() << ",";
		f << dsLoaiPhong[i].GetDVKem() << ",";
		f << dsLoaiPhong[i].GetDonGia() << "\n";
	}
	f.close();
}

vector<LOAIDICHVU> KHACHSAN::DocDSLoaiDV() {
	LOAIDICHVU loaidv;
	string luu;
	ifstream f("../DATA/BangGiaDichVu.txt");
	if (!f.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (f.good()) {
		getline(f, luu,',');
		if (luu == "") {
			break;
		}
		loaidv.SetMDV(luu);
		getline(f, luu, ',');
		loaidv.SetTenDV(luu);
		getline(f, luu, ',');
		loaidv.SetGiaMua(stof(luu));
		getline(f, luu, '\n');
		loaidv.SetGiaBan(stof(luu));
		dsLoaiDichVu.push_back(loaidv);
	}
	f.close();
	return dsLoaiDichVu;
}
void KHACHSAN::ThemLoaiDichVu() {
	LOAIDICHVU loaidv;
	string temp;
	cout << "Current service type list: " << endl;
	XuatDSLoaiDichVu();
	int n;
	cout << "Enter number of service type to be added: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "\nEnter service code: ";
		cin >> temp;
		cin.ignore();
		while (KiemTraLoaiDV(temp)) {
			cout << "\nThis code belongs to another existed service type. Please try another one: ";
			cin>>temp;
			cin.ignore();
		}
		loaidv.SetMDV(temp);
		loaidv.Nhap();
		dsLoaiDichVu.push_back(loaidv);
	}
	GhiDSLoaiDV();
	cout << "\nNew service type list: " << endl;
	XuatDSLoaiDichVu();
}
bool KHACHSAN::KiemTraLoaiDV(string code) {
	bool check = false;
	for (int i = 0; i < dsLoaiDichVu.size(); i++) {
		if (code == dsLoaiDichVu[i].GetMDV()) {
			check = true;
		}
	}
	return check;
}
void KHACHSAN::XoaLoaiDichVu() {
	string code;
	bool check = false;
	cin.ignore();
	cout << "\nEnter Service code to be deleted: ";
	cin >> code;
	for (int i = 0; i < dsLoaiDichVu.size(); i++) {
		if (dsLoaiDichVu[i].GetMDV() == code) {
			dsLoaiDichVu.erase(dsLoaiDichVu.begin() + i);
			check = true;
		}
	}
	if (!check) {
		cout << "\nNo Room type has the entered code\n";
	}
	else {
		GhiDSLoaiDV();
		cout << "\nService " << code << " has been deleted." << endl;
	}
}
void KHACHSAN::SuaDSLoaiDV() {
	string code;
	float temp;
	bool check = false;
	cout << "Enter service code to be editted: ";
	cin >> code;
	cin.ignore();
	for (int i = 0; i < dsLoaiDichVu.size(); i++) {
		if (code == dsLoaiDichVu[i].GetMDV()) {
			cout << "Enter new purchase price for " << dsLoaiDichVu[i].GetTenDV() << ": ";
			cin >> temp;
			dsLoaiDichVu[i].SetGiaMua(temp);
			cout << "\nEnter new unit price for " << dsLoaiDichVu[i].GetTenDV() << ": ";
			cin >> temp;
			dsLoaiDichVu[i].SetGiaBan(temp);
			check = true;
		}
	}
	if (!check) {
		cout << "No service has the entered code.\n";
	}
	else {
		GhiDSLoaiDV();
		cout << "\nService " << code << " has been updated.\n";
	}
}
void KHACHSAN::GhiDSLoaiDV() {
	remove("../DATA/BangGiaDichVu.txt");
	fstream f;
	f.open("../DATA/BangGiaDichVu.txt", ios::app);
	for (int i = 0; i < dsLoaiDichVu.size(); i++) {
		f << dsLoaiDichVu[i].GetMDV() << ",";
		f << dsLoaiDichVu[i].GetTenDV() << ",";
		f << dsLoaiDichVu[i].GetGiaMua() << ",";
		f << dsLoaiDichVu[i].GetGiaBan() << "\n";
	}
	f.close();
}

vector<PHONG> KHACHSAN::DocDSPhong() {
	PHONG phong;
	string luu;
	ifstream f("../DATA/Phong.txt");
	if (!f.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (f.good()) {
		getline(f, luu,',');
		if (luu == "") {
			break;
		}
		phong.SetMP(luu);
		getline(f, luu, ',');
		phong.SetMaLP(luu);
		for (int i = 0; i < dsLoaiPhong.size(); i++) {
			if (luu == dsLoaiPhong[i].GetMaLP()) {
				phong.SetLoaiPhong(dsLoaiPhong[i]);
			}
		}
		getline(f, luu, '\n');
		phong.SetStatus(stoi(luu));
		dsPhong.push_back(phong);
	}
	f.close();
	return dsPhong;
}
void KHACHSAN::ThemPhong() {
	PHONG phong;
	string temp;
	cout << "Current Room list: " << endl;
	XuatDSPhong();
	int n;
	cout << "\nEnter N. of rooms to be added: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter Room code: ";
		cin >> temp;
		cin.ignore();
		while (KiemTraPhong(temp)) {
			cout << "\nThis code already exists. Please add another one: ";
			cin >> temp;
			cin.ignore();
		}
		phong.SetMP(temp);
		phong.Nhap();
		dsPhong.push_back(phong);
		phong.Xuat();
	}
	GhiDSPhong();
}
bool KHACHSAN::KiemTraPhong(string code) {
	bool check = false;
	for (int i = 0; i < dsPhong.size(); i++) {
		if (code == dsPhong[i].GetMP()) {
			check = true;
		}
	}
	return check;
}
bool KHACHSAN::KiemTraPhongDangDung(string code) {
	bool check = false;
	vector<KHACHHANG> dsKhachChuaBill = TimDSKhachChuaBill();
	for (int i = 0; i < dsKhachChuaBill.size(); i++) {
		if (code == dsKhachChuaBill[i].GetMP()) {
			check = true;
		}
	}
	return check;
}
void KHACHSAN::XoaPhong() {
	string code;
	bool check = false;
	cin.ignore();
	cout << "\nEnter Room code to be deleted: ";
	getline(cin, code);
	if (KiemTraPhongDangDung(code)) {
		cout << "\nYou can not delete this room because a current customer is living in.\n";
	}
	else {
		for (int i = 0; i < dsPhong.size(); i++) {
			if (dsPhong[i].GetMP() == code) {
				dsPhong.erase(dsPhong.begin() + i);
				check = true;
			}
		}
		if (!check) {
			cout << "\nNo Room with the entered code\n";
		}
		else {
			GhiDSPhong();
			cout << "\n Room " << code << " has been deleted." << endl;
		}
	}
}
void KHACHSAN::SuaPhong() {
	string temp;
	string mp;
	bool check = false;
	cout << "Current Room list:" << endl;
	XuatDSPhong();
	cout << "Enter Room code to be editted: ";
	cin >> mp;
	cin.ignore();
	for (int i = 0; i < dsPhong.size(); i++) {
		if (mp == dsPhong[i].GetMP()) {
			cout << "Enter new room type code: ";
			getline(cin, temp);
			while (!KiemTraLoaiPhong(temp)) {
				cout << "\nRoom type code is invalid. Please try again: ";
				getline(cin, temp);
			}
			dsPhong[i].SetMaLP(temp);
			cout << "Enter Room status (0-Not available, 1-Available, 2-Vacant clean: ";
			getline(cin, temp);
			dsPhong[i].SetStatus(stoi(temp));
			for (int j = 0; j < dsLoaiPhong.size(); j++) {
				if (dsPhong[i].GetMaLP() == dsLoaiPhong[j].GetMaLP()) {
					dsPhong[i].SetLoaiPhong(dsLoaiPhong[j]);
				}
			}
			check = true;
		}
	}
	if (!check) {
		cout << "\nNo room has the entered code.\n";
	}
	else {
		GhiDSPhong();
		cout << "\nThe room " << mp << " has been editted.\n";
	}
}
void KHACHSAN::CapNhatStatusPhong() {
	string temp;
	string mp;
	bool check = false;
	cout << "Enter Room code to be editted: ";
	cin >> mp;
	for (int i = 0; i < dsPhong.size(); i++) {
		if (mp == dsPhong[i].GetMP()) {
			check = true;
			cout << "Enter Room status: ";
			getline(cin, temp);
			dsPhong[i].SetStatus(stoi(temp));
			for (int j = 0; j < dsLoaiPhong.size(); j++) {
				if (dsPhong[i].GetMaLP() == dsLoaiPhong[j].GetMaLP()) {
					dsPhong[i].SetLoaiPhong(dsLoaiPhong[j]);
				}
			}
		}
	}
	if (!check) {
		cout << "No room has the entered code.\n";
	}
	else {
		GhiDSPhong();
		cout << "\nCurrent status of Room: 0-not available, 1-available, 2-vacant cleaning\n";
		XuatDSPhong();
	}
}
void KHACHSAN::GhiDSPhong() {
	remove("../DATA/Phong.txt");
	fstream f;
	f.open("../DATA/Phong.txt", ios::app);
	for (int i = 0; i < dsPhong.size(); i++) {
		f << dsPhong[i].GetMP() << ",";
		f << dsPhong[i].GetLoaiPhong().GetMaLP() << ",";
		f << dsPhong[i].GetStatus() << "\n";
	}
	f.close();
}

vector<KHACHHANG> KHACHSAN::DocDSKhachHang() {
	KHACHHANG khachhang;
	string luu;
	NgayThangNam checkin;
	ifstream f("../DATA/DSKhachHang.txt");
	if (!f.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (f.good())
	{
		getline(f, luu,',');
		if (luu == "") {
			break;
		}
		khachhang.SetMKH(luu);
		getline(f, luu, ',');
		khachhang.SetTenKH(luu);
		getline(f, luu, ',');
		khachhang.SetMP(luu);
		getline(f, luu, ',');
		checkin.SetNgay(stoi(luu));
		getline(f, luu, ',');
		checkin.SetThang(stoi(luu));
		getline(f, luu, '\n');
		checkin.SetNam(stoi(luu));
		khachhang.SetCheckin(checkin);
		dsKhachHang.push_back(khachhang);
	}
	f.close();
	return dsKhachHang;
}
void KHACHSAN::ThemKhachHang() {
	int n;
	string tam;
	cout << "Enter no. of customers to be added: ";
	cin >> n;
	KHACHHANG khachhang;
	for (int i = 0; i < n; i++) {
		cout << "\nEnter customer code: ";
		cin >> tam;
		cin.ignore();
		while (KiemTraKhachHang(tam)) {
			cout << "\nThis code belongs to an other existed customer. Please try again: ";
			cin >> tam;
			cin.ignore();
		}
		khachhang.SetMKH(tam);
		khachhang.NhapThongTinDen();
		dsKhachHang.push_back(khachhang);
	}
	GhiDSKhachHang();
}
bool KHACHSAN::KiemTraKhachHang(string code) {
	bool check = false;
	for (int i = 0; i < dsKhachHang.size(); i++) {
		if (code == dsKhachHang[i].GetMKH()) {
			check = true;
		}
	}
	return check;
}
void KHACHSAN::SuaKhachHang() {
	string mkh;
	cin.ignore();
	bool check = false;
	cout << "Enter customer code to be editted: ";
	getline(cin, mkh);
	if (dsKhachHang.size() == 0) {
		cout << "No customer is available.\n";
	}
	else {
		for (int i = 0; i < dsKhachHang.size(); i++) {
			if (mkh == dsKhachHang[i].GetMKH()) {
				cout << "Enter customer's new information: " << endl;
				dsKhachHang[i].NhapThongTinDen();
				dsKhachHang[i].XuatThongTinDen();
				GhiDSKhachHang();
				cout << "\nThe customer " << mkh << " has been editted.\n";
				check = true;
			}
		}
	}
	if (!check) {
		cout << "\nNo customer has the entered code.\n";
	}
}
void KHACHSAN::XoaKhachHang() {
	string code;
	if (dsKhachHang.size() == 0) {
		cout << "\nNo customber is availabe to delete.\n";
	}
	else {
		cout << "\nEnter Customer code to be deleted: ";
		cin >> code;
		bool check = false;
		for (int i = 0; i < dsKhachHang.size(); i++) {
			if (dsKhachHang[i].GetMKH() == code) {
				dsKhachHang.erase(dsKhachHang.begin() + i);
				cout << "Customer " << code << " has been delected." << endl;
				check = true;
			}
		}
		if (!check) {
			cout << "\nNo customer with the entered code.\n";
		}
		else {
			GhiDSKhachHang();
		}
	}
}
void KHACHSAN::TimKhachHangTheoMa() {
	if (dsKhachHang.size() == 0) {
		cout << "No customber is availabe";
	}
	else {
		string code;
		bool check = false;
		cin.ignore();
		cout << "Enter an Customer code: ";
		getline(cin, code);
		for (int i = 0; i < dsKhachHang.size(); i++) {
			if (code == dsKhachHang[i].GetMKH()) {
				check = true;
				dsKhachHang[i].XuatThongTinDen();
			}
		}
		if (!check) {
			cout << "No Customer with the entered code." << endl;
		}
	}
}
vector<KHACHHANG> KHACHSAN::TimDSKhachChuaBill() {
	vector<KHACHHANG> dsKhachChuaBill;
	for (int i = 0; i < dsKhachHang.size(); i++) {
		if (!KiemTraTinhBill(dsKhachHang[i].GetMKH())) {
			dsKhachChuaBill.push_back(dsKhachHang[i]);
		}
	}
	return dsKhachChuaBill;
}
void KHACHSAN::GhiDSKhachHang() {
	if (dsKhachHang.size() > 0) {
		remove("../DATA/DSKhachHang.txt");
		fstream f;
		f.open("../DATA/DSKhachHang.txt", ios::app);
		for (int i = 0; i < dsKhachHang.size(); i++) {
			f << dsKhachHang[i].GetMKH() << ",";
			f << dsKhachHang[i].GetTKH() << ",";
			f << dsKhachHang[i].GetMP() << ",";
			f << dsKhachHang[i].GetCheckin().GetNgay() << ",";
			f << dsKhachHang[i].GetCheckin().GetThang() << ",";
			f << dsKhachHang[i].GetCheckin().GetNam() << "\n";
		}
		f.close();
	}
}

vector<KHACHHANG> KHACHSAN::DocDSBill() {
	string luu;
	string luu1;

	ifstream f("../DATA/DSHoaDon.txt");
	if (!f.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (f.good())
	{
		getline(f, luu, ',');
		if (luu == "") {
			break;
		}
		else if (luu == "@") {
			KHACHHANG khachhang;
			NgayThangNam ngay;
			PHONG phong;
			LOAIPHONG loaiphong;
			DICHVU dichvu;
			vector<DICHVU> dsDV;

			getline(f, luu, ',');
			khachhang.SetMKH(luu);
			getline(f, luu, ',');
			khachhang.SetTenKH(luu);
			getline(f, luu, ',');
			khachhang.SetMP(luu);
			getline(f, luu, ',');
			phong.SetMaLP(luu);
			loaiphong.SetMaLP(luu);
			getline(f, luu, ',');
			loaiphong.SetDonGia(stof(luu));
			phong.SetLoaiPhong(loaiphong);
			khachhang.SetPhong(phong);
			getline(f, luu, ',');
			ngay.SetNgay(stoi(luu));
			getline(f, luu, ',');
			ngay.SetThang(stoi(luu));
			getline(f, luu, ',');
			ngay.SetNam(stoi(luu));
			khachhang.SetCheckin(ngay);
			getline(f, luu, ',');
			ngay.SetNgay(stoi(luu));
			getline(f, luu, ',');
			ngay.SetThang(stoi(luu));
			getline(f, luu, ',');
			ngay.SetNam(stoi(luu));
			khachhang.SetCheckout(ngay);
			getline(f, luu, '\n');
			khachhang.SetSoDV(stoi(luu));
			dsDV.resize(stoi(luu));
			if (stoi(luu) > 0) {
				for (int i = 0; i<stoi(luu); i++) {
					getline(f, luu1, ',');
					dichvu.SetMDV(luu1);
					getline(f, luu1, ',');
					dichvu.SetTDV(luu1);
					getline(f, luu1, ',');
					dichvu.SetGiaMua(stof(luu1));
					getline(f, luu1, ',');
					dichvu.SetDonGia(stof(luu1));
					getline(f, luu1, ',');
					dichvu.SetSL(stoi(luu1));
					getline(f, luu1, '\n');
					dichvu.SetThanhTien(stof(luu1));
					dsDV[i] = dichvu;
				}
				khachhang.SetdsDV(dsDV);
				dsDV.clear();
			}
			khachhang.SetSoNgay(khachhang.TinhSoNgay(khachhang.GetCheckin(), khachhang.GetCheckout()));
			khachhang.SetTienPhong(khachhang.GetSoNgay()*khachhang.GetPhong().GetLoaiPhong().GetDonGia());
			khachhang.SetTienDV(khachhang.TinhTienDV());
			khachhang.SetTongTien(khachhang.GetTienPhong() + khachhang.GetTienDV());
			dsBill.push_back(khachhang);
		}
	}
	f.close();
	return dsBill;
}
void KHACHSAN::ThemBill() {
	cout << "List of current customers without bills exported:\n";
	vector<KHACHHANG> dsChuaBill = TimDSKhachChuaBill();
	XuatDSKhachHang(dsChuaBill);
	KHACHHANG Bill;
	string makh;
	bool check = false;
	cout << "\nEnter customer's code: ";
	cin >> makh;
	for (int i = 0; i < dsChuaBill.size(); i++) {
		if (makh == dsChuaBill[i].GetMKH()) {
			Bill = dsChuaBill[i];
			Bill.NhapThongTinTinhTien();
			dsBill.push_back(Bill);
			cout << "\nBill:\n";
			Bill.XuatThongTinTinhTien();
			check = true;
		}
	}
	if (!check) {
		cout << "No customer with the entered code is available for exporting bill./n";
	}
	else {
		GhiDSBill();
	}
}
bool KHACHSAN::KiemTraTinhBill(string mkh) {
	bool check = false;
	if (dsBill.size() == 0) {
		check = false;
	}
	else {
		for (int i = 0; i < dsBill.size(); i++) {
			if (mkh == dsBill[i].GetMKH()) {
				check = true;
			}
		}
	}
	return check;
}
void KHACHSAN::GhiDSBill() {
	if (dsBill.size() > 0) {
		remove("../DATA/DSHoaDon.txt");
		fstream f;
		f.open("../DATA/DSHoaDon.txt", ios::app);
		for (int i = 0; i < dsBill.size(); i++) {
			f << "@" << "," << dsBill[i].GetMKH() << ",";
			f << dsBill[i].GetTKH() << ",";
			f << dsBill[i].GetMP() << ",";
			f << dsBill[i].GetPhong().GetMaLP() << ",";
			f << dsBill[i].GetPhong().GetLoaiPhong().GetDonGia() << ",";
			f << dsBill[i].GetCheckin().GetNgay() << ",";
			f << dsBill[i].GetCheckin().GetThang() << ",";
			f << dsBill[i].GetCheckin().GetNam() << ",";
			f << dsBill[i].GetCheckout().GetNgay() << ",";
			f << dsBill[i].GetCheckout().GetThang() << ",";
			f << dsBill[i].GetCheckout().GetNam() << ",";
			f << dsBill[i].GetSoDV() << "\n";
			if (dsBill[i].GetSoDV() > 0) {
				for (int j = 0; j < dsBill[i].GetSoDV(); j++) {
					f << dsBill[i].GetDSDichVu()[j].GetMDV() << ",";
					f << dsBill[i].GetDSDichVu()[j].GetTDV() << ",";
					f << dsBill[i].GetDSDichVu()[j].GetGiaMua() << ",";
					f << dsBill[i].GetDSDichVu()[j].GetDonGia() << ",";
					f << dsBill[i].GetDSDichVu()[j].GetSL() << ",";
					f << dsBill[i].GetDSDichVu()[j].GetThanhTien() << "\n";
				}
			}
		}
		f.close();
	}
}

vector<NHANVIEN> KHACHSAN::DocDSNhanVien() {
	NHANVIEN nhanVien;
	string luu;
	ifstream dsnv("../DATA/NhanVien.txt");
	if (!dsnv.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (dsnv.good()) {
		getline(dsnv, luu,',');
		if (luu == "") {
			break;
		}
		nhanVien.SetMaNV(luu);
		getline(dsnv, luu, ',');
		nhanVien.SetPwd(luu);
		getline(dsnv, luu, ',');
		nhanVien.SetTenNV(luu);
		getline(dsnv, luu, ',');
		nhanVien.SetmaCV(luu);
		getline(dsnv, luu, ',');
		nhanVien.SetCV(luu);
		getline(dsnv, luu, ',');
		nhanVien.SetGioLamViec(stof(luu));
		getline(dsnv, luu, '\n');
		nhanVien.SetLuong(stof(luu));
		dsNhanVien.push_back(nhanVien);
	}
	dsnv.close();
	return dsNhanVien;
}
void KHACHSAN::ThemNhanVien() {
	string temp;
	cout << "Current Employee list: " << endl;
	XuatDSNhanVien();
	int n;
	NHANVIEN nhanvien;
	cout << "Enter no. of employees to be added: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter employee code: ";
		cin >> temp;
		cin.ignore();
		while (KiemTraNhanVien(temp)) {
			cout << "\nThis person has already existed. Please try another code:";
			cin >> temp;
			cin.ignore();
		}
		nhanvien.SetMaNV(temp);
		nhanvien.Nhap();
		dsNhanVien.push_back(nhanvien);
	}
	GhiDSNhanVien();
}
bool KHACHSAN::KiemTraNhanVien(string code) {
	bool check = false;
	for (int i = 0; i < dsNhanVien.size(); i++) {
		if (code == dsNhanVien[i].GetMaNV()) {
			check = true;
		}
	}
	return check;
}
void KHACHSAN::XoaNhanVien(string code) {
	bool check = false;
	for (int i = 0; i < dsNhanVien.size(); i++) {
		if (code==dsNhanVien[i].GetMaNV()) {
			dsNhanVien.erase(dsNhanVien.begin() + i);
			check = true;
		}
	}
	if (!check) {
		cout << "\nNo employee with the entered code" << endl;
	}
	else {
		GhiDSNhanVien();
		cout << "Employee with the code " << code << " has been deleted.";
	}
}
void KHACHSAN::TimNhanVienTheoMa() {
	string code;
	bool check = false;
	cout << "Enter an employee code: ";
	cin >> code;
	for (int i = 0; i<dsNhanVien.size(); i++) {
		if (code == dsNhanVien[i].GetMaNV()) {
			check = true;
			dsNhanVien[i].Xuat();
		}
	}
	if (!check) {
		cout << "No employee with the entered code." << endl;
	}
}
void KHACHSAN::SuaThongTinNhanVien() {
	string code;
	string temp;
	bool check = false;
	cin.ignore();
	cout << "Enter employee code to be editted: ";
	getline(cin, code);
	for (int i = 0; i < dsNhanVien.size(); i++) {
		if (code == dsNhanVien[i].GetMaNV()) {
			cout << "Enter new employee code: ";
			getline(cin, temp);
			while (temp != code&&KiemTraNhanVien(temp)) {
				cout << "\nThis code belongs to another person. Please try another one: ";
				getline(cin, temp);
			}
			dsNhanVien[i].SetMaNV(temp);
			cout << "Enter new password: ";
			getline(cin, temp);
			dsNhanVien[i].SetPwd(temp);
			cout << "Enter new name: ";
			getline(cin, temp);
			dsNhanVien[i].SetTenNV(temp);
			cout << "Enter new position code: ";
			getline(cin, temp);
			while (temp != "GD"&&temp != "QL"&&temp != "TT") {
				cout << "\nThe position code is not valid. Please re-enter it: ";
				getline(cin, temp);
			}
			dsNhanVien[i].SetmaCV(temp);
			if (temp == "GD") {
				dsNhanVien[i].SetCV("Director");
			}
			else if (temp == "QL") {
				dsNhanVien[i].SetCV("Manager");
			}
			else {
				dsNhanVien[i].SetCV("Receptionist");
			}
			GhiDSNhanVien();
			check = true;
			cout << "New employee's information: " << endl;
			dsNhanVien[i].Xuat();
		}
	}
	if (!check) {
		cout << "No employee with the entered code." << endl;
	}
}
void KHACHSAN::GhiDSNhanVien() {
	remove("../DATA/NhanVien.txt");
	fstream f;
	f.open("../DATA/NhanVien.txt", ios::app);
	for (int i = 0; i < dsNhanVien.size(); i++) {
		f << dsNhanVien[i].GetMaNV() << ",";
		f << dsNhanVien[i].GetPw() << ",";
		f << dsNhanVien[i].GetTen() << ",";
		f << dsNhanVien[i].GetMaCV() << ",";
		f << dsNhanVien[i].GetCV() << ",";
		f << dsNhanVien[i].GetGioLamViec() << ",";
		f << dsNhanVien[i].GetLuong() << "\n";
	}
	f.close();
}

vector<HSLUONG> KHACHSAN::DocDSHSL() {
	HSLUONG hsl;
	string luu;
	ifstream f("../DATA/HeSoLuong.txt");
	if (!f.is_open()) {
		cout << "ERROR: File open" << '\n';
	}
	while (f.good()) {
		getline(f, luu,',');
		if (luu == "") {
			break;
		}
		hsl.SetMCV(luu);
		getline(f, luu, ',');
		hsl.SetHSLCoBan(stof(luu));
		getline(f, luu, '\n');
		hsl.SetHSLNgoaiGio(stof(luu));
		dsHSL.push_back(hsl);
	}
	f.close();
	return dsHSL;
}
void KHACHSAN::SuaHSL() {
	float temp;
	cout << "Current salary unit: " << endl;
	XuatDSHSL();
	cout << "Enter salary/hour of Director: ";
	cin >> temp;
	dsHSL[0].SetHSLCoBan(temp);
	cout << "Enter salary/extra hour of Director: ";
	cin >> temp;
	dsHSL[0].SetHSLNgoaiGio(temp);
	cout << "Enter salary/hour of Manager: ";
	cin >> temp;
	dsHSL[1].SetHSLCoBan(temp);
	cout << "Enter salary/extra hour of Manager: ";
	cin >> temp;
	dsHSL[1].SetHSLNgoaiGio(temp);
	cout << "Enter salary/hour of Receptionist: ";
	cin >> temp;
	dsHSL[2].SetHSLCoBan(temp);
	cout << "Enter salary/extra hour of Receptionist: ";
	cin >> temp;
	dsHSL[2].SetHSLNgoaiGio(temp);
	GhiDSHSL();
	cout << "New Salary unit: " << endl;
	XuatDSHSL();
}
void KHACHSAN::GhiDSHSL() {
	remove("../DATA/HeSoLuong.txt");
	fstream f;
	f.open("../DATA/HeSoLuong.txt", ios::app);
	for (int i = 0; i < dsHSL.size(); i++) {
		f << dsHSL[i].GetMCV() << ",";
		f << dsHSL[i].GetHSLCoBan() << ",";
		f << dsHSL[i].GetHSLNgoaiGio() << "\n";
	}
	f.close();
}

float KHACHSAN::TinhTongLuong() {
	float tongLuong = 0;
	for (int i = 0; i < dsNhanVien.size(); i++) {
		tongLuong = tongLuong + dsNhanVien[i].GetLuong();
	}
	return tongLuong;
}
float KHACHSAN::TinhDoanhThuTheoPhong() {
	float tongTienPhong = 0;
	for (int i = 0; i < dsBill.size(); i++) {
		tongTienPhong = tongTienPhong + dsBill[i].GetTienPhong();
	}
	return tongTienPhong;
}
float KHACHSAN::TinhDoanhThuTheoDV() {
	float doanhThuDV = 0;
	for (int i = 0; i < dsBill.size(); i++) {
		doanhThuDV = doanhThuDV + dsBill[i].GetTienDV();
	}
	return doanhThuDV;
}
float KHACHSAN::TinhLoiNhuanTheoDV() {
	float giaVon = 0;
	for (int i = 0; i < dsBill.size(); i++) {
		if (dsBill[i].GetSoDV() > 0) {
			for (int j = 0; j < dsBill[i].GetSoDV(); j++) {
				giaVon = giaVon + dsBill[i].GetDSDichVu()[j].GetGiaMua()*dsBill[i].GetDSDichVu()[j].GetSL();
			}
		}
	}
	return TinhDoanhThuTheoDV() - giaVon;
}
float KHACHSAN::TinhLoiNhuanGop() {
	return TinhDoanhThuTheoPhong() + TinhLoiNhuanTheoDV();
}
float KHACHSAN::TinhLoiNhuanThuan() {
	return TinhLoiNhuanGop() - TinhTongLuong();
}
float KHACHSAN::TinhLoiNhanRong() {
	return 0.8*TinhLoiNhuanThuan();
}


vector<NHANVIEN> KHACHSAN::SapXepLuongGiamDan() {
	vector<NHANVIEN> kq;
	kq = dsNhanVien;
	for (int i = 0; i < dsNhanVien.size() - 1; i++) {
		for (int j = i+1; j < dsNhanVien.size(); j++) {
			if (kq[i].GetLuong() < kq[j].GetLuong()) {
				HoanViNhanVien(kq[i], kq[j]);
			}
		}
	}
	return kq;
}
vector<NHANVIEN> KHACHSAN::SapXepLuongTangDan() {
	vector<NHANVIEN> kq;
	kq = dsNhanVien;
	for (int i = 0; i < dsNhanVien.size() - 1; i++) {
		for (int j = i + 1; j < dsNhanVien.size(); j++) {
			if (kq[i].GetLuong() > kq[j].GetLuong()) {
				HoanViNhanVien(kq[i], kq[j]);
			}
		}
	}
	return kq;
}
void KHACHSAN::HoanViNhanVien(NHANVIEN& a, NHANVIEN& b) {
	NHANVIEN temp;
	temp = a;
	a = b;
	b = temp;
}