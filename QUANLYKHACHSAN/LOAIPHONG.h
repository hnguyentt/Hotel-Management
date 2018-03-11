#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LOAIPHONG
{
protected:
	string maLoaiPhong;
	string tenLoaiPhong;
	int soGiuong;
	string dichVuKem;
	float donGiaPhong;
public:
	LOAIPHONG();
	~LOAIPHONG();
	string GetMaLP();
	string GetTenLP();
	int GetSoGiuong();
	string GetDVKem();
	float GetDonGia();
	void SetMaLP(string);
	void SetTenLP(string);
	void SetSoGiuong(int);
	void SetDVKem(string);
	void SetDonGia(float);

	void Nhap();
	void Xuat();
};

