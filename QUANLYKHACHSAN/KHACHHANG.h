#pragma once
#include"DICHVU.h"
#include"NgayThangNam.h"
#include <vector>
#include"PHONG.h"

class KHACHHANG
{
private:
	string maKH;
	string TenKH;
	NgayThangNam checkin;
	NgayThangNam checkout;
	int soNgay;
	string maPhong;
	PHONG phong;
	int soDV;
	vector<DICHVU> dsDV;
	float tienDV=0;
	float tienPhong = 0;
	float tongTien=0;
public:
	KHACHHANG();
	~KHACHHANG();
	int TinhSoNgay(NgayThangNam, NgayThangNam);
	string GetMKH();
	string GetTKH();
	NgayThangNam GetCheckin();
	NgayThangNam GetCheckout();
	vector<DICHVU> GetDSDichVu();
	int GetSoNgay();
	string GetMP();
	float GetTongTien();
	PHONG GetPhong();
	float GetTienDV();
	float GetTienPhong();
	int GetSoDV();
	void SetSoDV(int);
	void SetTienPhong(float);
	void SetTienDV(float);
	void SetPhong(PHONG);
	void SetTongTien(float);
	void SetMP(string);
	void SetSoNgay(int soNgay);
	void SetMKH(string);
	void SetTenKH(string);
	void SetCheckin(NgayThangNam);
	void SetCheckout(NgayThangNam);
	void SetdsDV(vector<DICHVU>);
	void NhapThongTinDen();
	void XuatThongTinDen();
	void NhapThongTinTinhTien();
	void XuatThongTinTinhTien();
	float TinhTienDV();
	void XuatDSDV();
	bool KiemTraKhachHang(string);
};

