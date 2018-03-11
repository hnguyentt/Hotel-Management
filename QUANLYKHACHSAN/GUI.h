#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>                  
#include <ctime>		           	 
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>   
#include "KHACHSAN.h"

//#include "ROOM.h"

using namespace std;

static COORD coord = { 0, 0 };

class GUI
{
private:
	KHACHSAN khachsan;
	string mnv;
public:
	GUI();
	~GUI();

	KHACHSAN GetKhachSan();
	void SetKhachSan(KHACHSAN);

	void DrawGUILogin(int&);
	void DrawGUIMainMenu1();
	void DrawGUIMainMenu2();
	void DrawGUIMainMenu3();
	void DrawGUISubMenu11();
	void DrawGUISubMenu12();
	void DrawGUISubMenu13();
	void DrawGUISubMenu14();
	void DrawGUISubMenu21();
	void DrawGUISubMenu22();
	void DrawGUISubMenu23();
	void DrawGUISubMenu31();

	void gotoxy(int x, int y);
	void time();
	void loading();
	void mainEntrance();
	void login(int&,string&);
	void logout();

};


