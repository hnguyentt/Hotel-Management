#pragma once
#include<iostream>
#include<string>
using namespace std;

class HSLUONG
{
private:
	string maCV;
	float hsLuongCoBan;
	float hsLuongNgoaiGio;

public:
	HSLUONG();
	~HSLUONG();

	string GetMCV();
	float GetHSLCoBan();
	float GetHSLNgoaiGio();

	void SetMCV(string);
	void SetHSLCoBan(float);
	void SetHSLNgoaiGio(float);

	void Nhap();
	void Xuat();
};

