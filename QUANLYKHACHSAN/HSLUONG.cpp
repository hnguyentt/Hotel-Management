#include "HSLUONG.h"
#include "TABLE.h"



HSLUONG::HSLUONG()
{
}


HSLUONG::~HSLUONG()
{
}
string HSLUONG::GetMCV() {
	return maCV;
}
float HSLUONG::GetHSLCoBan() {
	return hsLuongCoBan;
}
float HSLUONG::GetHSLNgoaiGio() {
	return hsLuongNgoaiGio;
}

void HSLUONG::SetMCV(string mcv) {
	maCV = mcv;
}
void HSLUONG::SetHSLCoBan(float n) {
	hsLuongCoBan = n;
}
void HSLUONG::SetHSLNgoaiGio(float n) {
	hsLuongNgoaiGio = n;
}

void HSLUONG::Nhap() {
	cout << "\nEnter position code: ";
	cin >> maCV;
	cout << "\nEnter salary per hour: ";
	cin >> hsLuongCoBan;
	cout << "\nEnter salary per extra hour:";
	cin >> hsLuongNgoaiGio;
}
void HSLUONG::Xuat() {
	TABLE t('-', '|', '+');
	t.add("Position code");
	t.add("Salary/hour");
	t.add("Salary/extra hour");
	t.endOfRow();

	t.add(maCV);
	t.add(to_string(hsLuongCoBan));
	t.add(to_string(hsLuongNgoaiGio));
	t.endOfRow();
	
	cout << t;
}