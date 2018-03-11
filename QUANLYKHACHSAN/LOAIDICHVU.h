#pragma once
#include<iostream>
#include<string>
using namespace std;
class LOAIDICHVU
{
private:
	string maDV;
	string tenDV;
	float giaMua;
	float giaBan;
public:
	LOAIDICHVU();
	~LOAIDICHVU();
	string GetMDV();
	string GetTenDV();
	float GetGiaMua();
	float GetGiaBan();
	void SetMDV(string);
	void SetTenDV(string);
	void SetGiaMua(float);
	void SetGiaBan(float);

	void Nhap();
	void Xuat();
	bool KiemTraLoaiDV(string);
};

