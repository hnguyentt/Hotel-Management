#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include "LOAIPHONG.h"
using namespace std;
class PHONG
{
private:
	string maPhong;
	string maLoaiPhong;
	string maLau;
	LOAIPHONG loaiPhong;
	//1: Available, 0: Not available, 2: Vacant clean
	int status;
public:
	PHONG();
	~PHONG();
	string GetMP();
	string GetMaLau();
	string GetMaLP();
	int GetStatus();
	LOAIPHONG GetLoaiPhong();

	void SetMP(string);
	void SetMaLP(string);
	void SetMaLau(string);
	void SetStatus(int);
	void SetLoaiPhong(LOAIPHONG);

	void Nhap();
	void Xuat();
	bool KiemTraLoaiPhong(string);
};

