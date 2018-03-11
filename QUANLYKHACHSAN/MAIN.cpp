#include "GUI.h"
#include "NHANVIEN.h"
#include"KHACHSAN.h"
#include"TABLE.h"

void main()
{
	system("color B0");
	int quyen;
	GUI gui;
	gui.DrawGUILogin(quyen);

	switch (quyen) {
	case 1: {
		while (true)
		{

			system("cls");
			gui.DrawGUIMainMenu1();
		}; 
	}; break;
	case 2: {
		while (true)
		{

			system("cls");
			gui.DrawGUIMainMenu2();
		};
	}; break;
	case 3: {
		while (true)
		{

			system("cls");
			gui.DrawGUIMainMenu3();
		};
	}; break;
	}
	system("pause");
}