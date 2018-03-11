#include "KHACHHANG.h"
#include"TABLE.h"
#include"KHACHSAN.h"


KHACHHANG::KHACHHANG()
{

}


KHACHHANG::~KHACHHANG()
{
}
int KHACHHANG::TinhSoNgay(NgayThangNam checkin,NgayThangNam checkout) {
	return checkout.RDN(checkout.GetNgay(),checkout.GetThang(),checkout.GetNam()) - checkin.RDN(checkin.GetNgay(), checkin.GetThang(), checkin.GetNam());
}
string KHACHHANG::GetMKH() {
	return maKH;
}
string KHACHHANG::GetTKH() {
	return TenKH;
}
NgayThangNam KHACHHANG::GetCheckin() {
	return checkin;
}
NgayThangNam KHACHHANG::GetCheckout() {
	return checkout;
}
vector<DICHVU> KHACHHANG::GetDSDichVu() {
	return dsDV;
}
PHONG KHACHHANG::GetPhong() {
	return phong;
}
float KHACHHANG::GetTienDV() {
	return tienDV;
}
void KHACHHANG::SetTienDV(float n) {
	tienDV = n;
}
void KHACHHANG::SetPhong(PHONG p) {
	phong.SetMP(p.GetMP());
	phong.SetMaLau(p.GetMaLau());
	phong.SetMaLP(p.GetMaLP());
	phong.SetLoaiPhong(p.GetLoaiPhong());
}
void KHACHHANG::SetMKH(string MKH) {
	maKH = MKH;
}
void KHACHHANG::SetTenKH(string TKH) {
	TenKH = TKH;
}
void KHACHHANG::SetCheckin(NgayThangNam date) {
	checkin.SetNgay(date.GetNgay());
	checkin.SetThang(date.GetThang());
	checkin.SetNam(date.GetNam());
}
void KHACHHANG::SetCheckout(NgayThangNam date) {
	checkout.SetNgay(date.GetNgay());
	checkout.SetThang(date.GetThang());
	checkout.SetNam(date.GetNam());
}
void KHACHHANG::SetdsDV(vector<DICHVU> DSDV) {
	for (int i = 0; i < DSDV.size(); i++) {
		dsDV.push_back(DSDV[i]);
	}
}
int KHACHHANG::GetSoNgay() {
	return soNgay;
}
void KHACHHANG::SetSoNgay(int N) {
	soNgay = N;
}
string KHACHHANG::GetMP() {
	return maPhong;
}
float KHACHHANG::GetTienPhong() {
	return tienPhong;
}
void KHACHHANG::SetTienPhong(float n) {
	tienPhong = n;
}
void KHACHHANG::SetMP(string mp) {
	maPhong = mp;
}
float KHACHHANG::GetTongTien() {
	return tongTien;
}
void KHACHHANG::SetTongTien(float n) {
	tongTien = n;
}
void KHACHHANG::NhapThongTinDen() {
	KHACHSAN khachsan;
	khachsan.DocDSPhong();
	cout << "Enter customer's name: ";
	getline(cin, TenKH);
	cin.ignore();
	cout << "Enter checkin date: " << endl;
	checkin.Nhap();
	cout << endl << "Enter room code: ";
	cin >> maPhong;
	cin.ignore();
	while (!khachsan.KiemTraPhong(maPhong)) {
		cout << "\nRoom code is not valid. Please try again: ";
		cin >> maPhong;
		cin.ignore();
	}
}
void KHACHHANG::XuatThongTinDen() {
	TABLE t('-', '|', '*');

	t.add("Customer code");
	t.add("Customer's name");
	t.add("Room code");
	t.add("Checkin");
	t.endOfRow();

	t.add(maKH);
	t.add(TenKH);
	t.add(maPhong);
	t.add(checkin.Xuat());
	t.endOfRow();

	cout << t;
}
float KHACHHANG::TinhTienDV() {
	tienDV = 0;
	if (dsDV.size() > 0) {
		for (int i = 0; i < dsDV.size(); i++) {
			tienDV = tienDV + dsDV[i].GetThanhTien();
		}
	}
	return tienDV;
}
void KHACHHANG::NhapThongTinTinhTien() {
	cout << "\nEnter checkout date: " << endl;
	checkout.Nhap();
	soNgay = TinhSoNgay(checkin, checkout);
	cout << "\nBelow is service list: " << endl;
	KHACHSAN khachsan;
	cout << "\n_________________________SERVICES_________________________:\n";
	cout << "\n\nService list:\n";
	khachsan.DocDSLoaiDV();
	khachsan.DocDSLoaiPhong();
	khachsan.DocDSPhong();
	khachsan.XuatDSLoaiDichVu();
	cout << "Enter number of services that customer used: ";
	cin >> soDV;
	DICHVU dv;
	if (soDV > 0) {
		for (int i = 0; i < soDV; i++) {
			dv.Nhap();
			dsDV.push_back(dv);
		}
		cout << "\nServices consumed by customer: " << endl;
	}
	XuatDSDV();
	for (int i = 0; i < khachsan.GetDSPhong().size(); i++) {
		if (maPhong == khachsan.GetDSPhong()[i].GetMP())
		{
			SetPhong(khachsan.GetDSPhong()[i]);

		}
	}
	tienPhong = phong.GetLoaiPhong().GetDonGia()*soNgay;
	tienDV = TinhTienDV();
	tongTien = tienPhong + tienDV;
}

void KHACHHANG::XuatThongTinTinhTien(){
	TABLE t('-', '|', '*');

	t.add("Name");
	t.add("R.code");
	t.add("RT.code");
	t.add("Unit price");
	t.add("Checkin");
	t.add("Checkout");
	t.add("Day count");
	t.add("Room Price");
	t.add("Service Price");
	t.add("Total");
	t.endOfRow();

	t.add(TenKH);
	t.add(maPhong);
	t.add(phong.GetMaLP());
	t.add(to_string(phong.GetLoaiPhong().GetDonGia()));
	t.add(checkin.Xuat());
	t.add(checkout.Xuat());
	t.add(to_string(soNgay));
	t.add(to_string(tienPhong));
	t.add(to_string(tienDV));
	t.add(to_string(tongTien));
	t.endOfRow();
	t.setAlignment(3, TABLE::Alignment::RIGHT);
	t.setAlignment(7, TABLE::Alignment::RIGHT);
	t.setAlignment(8, TABLE::Alignment::RIGHT);
	t.setAlignment(9, TABLE::Alignment::RIGHT);

	cout << t;
	if (soDV > 0) {
		cout << "\nServices:" << endl;
		XuatDSDV();
	}
}
void KHACHHANG::XuatDSDV() {
	TABLE T('-', '|', '*');
	T.add("Code");
	T.add("Name");
	T.add("Unit price");
	T.add("Quantity");
	T.add("Total");
	T.endOfRow();

	for (int i = 0; i < soDV; i++) {
		T.add(dsDV[i].GetMDV());
		T.add(dsDV[i].GetTDV());
		T.add(to_string(dsDV[i].GetDonGia()));
		T.add(to_string(dsDV[i].GetSL()));
		T.add(to_string(dsDV[i].GetThanhTien()));
		T.endOfRow();
		T.setAlignment(2, TABLE::Alignment::RIGHT);
		T.setAlignment(3, TABLE::Alignment::RIGHT);
		T.setAlignment(4, TABLE::Alignment::RIGHT);
	}
	cout << T;
}
int KHACHHANG::GetSoDV() {
	return soDV;
}
void KHACHHANG::SetSoDV(int n) {
	soDV = n;
}
bool KHACHHANG::KiemTraKhachHang(string code) {
	bool check = false;
	KHACHSAN khachsan;
	vector<KHACHHANG> dsKH = khachsan.DocDSKhachHang();
	for (int i = 0; i < dsKH.size(); i++) {
		if (code == dsKH[i].GetMKH()) {
			check = true;
		}
	}
	return check;
}