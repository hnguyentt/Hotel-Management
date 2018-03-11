#pragma once
#include<iostream>
using namespace std;
class NgayThangNam
{
private:
	int ngay=0;
	int thang=0;
	int nam=0;
public:
	NgayThangNam();
	~NgayThangNam();
	int GetNgay();
	int GetThang();
	int GetNam();
	void SetNgay(int);
	void SetThang(int);
	void SetNam(int);
	bool XetNamNhuan();
	int RDN(int, int, int);
	void Nhap();
	string Xuat();
};

