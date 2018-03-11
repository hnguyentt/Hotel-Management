#pragma once
#include"PHONG.h"
#include"LOAIPHONG.h"
#include"LOAIDICHVU.h"
#include"KHACHHANG.h"
#include "NHANVIEN.h"


class KHACHSAN
{
private:
	vector<LOAIPHONG> dsLoaiPhong;
	vector<LOAIDICHVU> dsLoaiDichVu;
	vector<PHONG> dsPhong;
	vector<KHACHHANG> dsKhachHang;
	vector<KHACHHANG> dsBill;
	vector<NHANVIEN> dsNhanVien;
	vector<HSLUONG> dsHSL;

public:
	KHACHSAN();
	~KHACHSAN();
	vector<LOAIPHONG> GetDSLoaiPhong();
	vector<LOAIDICHVU> GetDSLoaiDichVu();
	vector<PHONG> GetDSPhong();
	vector<NHANVIEN> GetDSNhanVien();
	vector<KHACHHANG> GetDSKhachHang();
	vector<KHACHHANG> GetDSBill();
	vector<HSLUONG> GetdsHSL();

	void SetDSLoaiPhong(vector<LOAIPHONG>);
	void SetDSLoaiDichVu(vector<LOAIDICHVU>);
	void SetDSPhong(vector<PHONG>);
	void SetDSKhachHang(vector<KHACHHANG>);
	void SetDSNhanVien(vector<NHANVIEN>);
	void SetDSBill(vector<KHACHHANG>);
	void SetDSHSL(vector<HSLUONG>);

	int DemNhanVien(string);
	
	void XuatDSLoaiDichVu();
	void XuatDSLoaiPhong();
	void XuatDSPhong();
	void XuatDSKhachHang(vector<KHACHHANG>);
	void XuatBill();
	void XuatDSNhanVien();
	void XuatDSHSL();

	vector<LOAIPHONG> DocDSLoaiPhong();
	vector<LOAIDICHVU> DocDSLoaiDV();
	vector<PHONG> DocDSPhong();
	vector<KHACHHANG> DocDSKhachHang();
	vector<NHANVIEN> DocDSNhanVien();
	vector<HSLUONG> DocDSHSL();
	vector<KHACHHANG> DocDSBill();

	void GhiDSLoaiPhong();
	void GhiDSLoaiDV();
	void GhiDSPhong();
	void GhiDSNhanVien();
	void GhiDSHSL();
	void GhiDSKhachHang();
	void GhiDSBill();

	void ThemNhanVien();
	void ThemLoaiPhong();
	void ThemLoaiDichVu();
	void ThemPhong();
	void ThemKhachHang();
	void ThemBill();

	void XoaNhanVien(string);
	void XoaLoaiPhong();
	void XoaLoaiDichVu();
	void XoaPhong();
	void XoaKhachHang();

	void TimNhanVienTheoMa();
	void TimKhachHangTheoMa();
	vector<KHACHHANG> TimDSKhachChuaBill();

	bool KiemTraPhongDangDung(string);
	bool KiemTraTinhBill(string);
	bool KiemTraKhachHang(string);
	bool KiemTraLoaiPhong(string);
	bool KiemTraLoaiDV(string);
	bool KiemTraPhong(string);
	bool KiemTraNhanVien(string);

	void SuaThongTinNhanVien();
	void SuaHSL();
	void SuaGiaPhong();
	void SuaPhong();
	void SuaDSLoaiDV();
	void CapNhatStatusPhong();
	void SuaKhachHang();

	float TinhTongLuong();
	float TinhDoanhThuTheoPhong();
	float TinhDoanhThuTheoDV();
	float TinhLoiNhuanTheoDV();
	float TinhLoiNhuanGop();
	float TinhLoiNhuanThuan();
	float TinhLoiNhanRong();

	vector<NHANVIEN> SapXepLuongGiamDan();
	vector<NHANVIEN> SapXepLuongTangDan();
	void HoanViNhanVien(NHANVIEN&, NHANVIEN&);
};

