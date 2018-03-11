#pragma once
#include"LOAIDICHVU.h"
#include<fstream>
using namespace std;
class DICHVU
{
private:
	string maDV;
	string tenDV;
	int soLuong;
	float giaMua;
	float donGia;
	float thanhTien;
public:
	DICHVU();
	~DICHVU();
	string GetMDV();
	string GetTDV();
	int GetSL();
	float GetGiaMua();
	float GetDonGia();
	float GetThanhTien();
	void SetMDV(string);
	void SetTDV(string);
	void SetSL(int);
	void SetDonGia(float);
	void SetThanhTien(float);
	void SetGiaMua(float);
	
	void Nhap();
	void Xuat();
	bool IsMaDV(string);
};

