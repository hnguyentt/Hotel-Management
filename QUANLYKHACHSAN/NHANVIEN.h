#pragma once
#include<iostream>
#include<string>
#include"HSLUONG.h"
#include<vector>
#include<fstream>

using namespace std;

class NHANVIEN
{
protected:
	string maNV = "";
	string password = "";
	string tenNV = "";
	string maCV = "";
	string chucVu = "";
	float luong = 0;
	float gioLamViec = 0;
public:
	NHANVIEN();
	~NHANVIEN();

	void SetMaNV(string);
	void SetPwd(string);
	void SetTenNV(string);
	void SetmaCV(string);
	void SetGioLamViec(float);
	void SetLuong(float);
	void SetCV(string);
	string GetCV();
	string GetMaNV();
	string GetPw();
	string GetTen();
	string GetMaCV();
	float GetGioLamViec();
	float GetLuong();

	void Nhap();
	void Xuat();
	float TinhLuong(vector<HSLUONG>,float&);
	bool KiemTraGD();
};


