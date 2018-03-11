#include "GUI.h"
#include"TABLE.h"

GUI::GUI()
{
	khachsan.DocDSNhanVien();
	khachsan.DocDSHSL();
	khachsan.DocDSLoaiDV();
	khachsan.DocDSLoaiPhong();
	khachsan.DocDSPhong();
	khachsan.DocDSKhachHang();
	khachsan.DocDSBill();
}


GUI::~GUI()
{
}

KHACHSAN GUI::GetKhachSan() {
	return khachsan;
}
void GUI::SetKhachSan(KHACHSAN ks) {
	khachsan.SetDSBill(ks.GetDSBill());
	khachsan.SetDSKhachHang(ks.GetDSKhachHang());
	khachsan.SetDSLoaiDichVu(ks.GetDSLoaiDichVu());
	khachsan.SetDSLoaiPhong(ks.GetDSLoaiPhong());
	khachsan.SetDSNhanVien(ks.GetDSNhanVien());
	khachsan.SetDSPhong(ks.GetDSPhong());
}

void GUI::DrawGUILogin(int&quyen)
{
	login(quyen,mnv);
}





////////////////////////////
void GUI::gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GUI::login(int&quyen,string& maNV)
{
	system("cls");
	maNV = "";
	string password = "";
	char ch, ch2, retry;
	int i = 0, j = 0;
	mainEntrance();
	time();
	gotoxy(55, 13);
	cout << "(LOGIN)";
	gotoxy(20, 17);
	cout << "Enter Code: \n\t\t    Enter Password: ";
	gotoxy(36, 17);

	ch2 = _getch();
	while (ch2 != 13) {                  // gets input until 'Enter' key is pressed

		if (ch2 == '\b') {
			if (maNV.size() > 0) {
				maNV.erase(maNV.begin() + maNV.size() - 1);
				cout << "\b \b";
				j--;
			}
			ch2 = _getch();
		}
		else {
			if (j < 10)
			{
				cout << ch2;
				maNV.push_back(ch2);
				ch2 = _getch();
				j++;
			}
			else {
				ch2 = _getch();
			}
		}
	}

	gotoxy(36, 18);
	ch = _getch();
	while (ch != 13) {                  

		if (ch == '\b') {
			if (password.size() > 0) {
				password.erase(password.begin() + password.size() - 1);
				cout << "\b \b";
				i--;
			}
			ch = _getch();
		}
		else {
			if (i < 10)
			{
				password.push_back(ch);
				cout << "*"; 					  
				ch = _getch();
				i++;
			}
			else {
				ch = _getch();
			}
		}
	}
	bool isSucess = false;
	int k = 0;
	while (!isSucess && k < khachsan.GetDSNhanVien().size()) {
		if (maNV.compare(khachsan.GetDSNhanVien()[k].GetMaNV()) == 0 && password.compare(khachsan.GetDSNhanVien()[k].GetPw()) == 0) {
			isSucess = true;
			if (khachsan.GetDSNhanVien()[k].GetMaCV().compare("GD") == 0) {
				quyen = 1;
			}
			else if (khachsan.GetDSNhanVien()[k].GetMaCV().compare("QL") == 0) {
				quyen = 2;
			}
			else
				quyen = 3;
		}
		k++;
	}
	if (isSucess)
	{
		gotoxy(15, 16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n Congratulations to " << khachsan.GetDSNhanVien()[k-1].GetTen() << ".\n You have successfully logged into the system!";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;
		if (retry == 'r' || retry == 'R')
		{
			system("cls");
			login(quyen,mnv);
		}
		else
		{
			exit(0);
		}
	}
}

void GUI::loading()
{
	gotoxy(24, 28);
	int i;
	for (i = 0; i<5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(200);
	}
	Sleep(1000);
	cout << endl << endl;
	gotoxy(24, 30);
}
void GUI::time()
{
	//  FOR current time and date
	gotoxy(1, 10);
	//time_t now;
	//time (&now);
	//cout << "\n\n\t\t Current Date & Time is: " << ctime(&now);
}

void GUI::mainEntrance()
{
	gotoxy(5, 2);

	cout << "ллллллллллл  ллллллллллл       ллллл        лллллллллл    ллллллллллл     " << endl; gotoxy(5, 3);
	cout << "ллл     ллл  ллл              ллл ллл      ллл            ллл             " << endl; gotoxy(5, 4);
	cout << "ллл     ллл  ллл             ллл   ллл     ллл            ллл             " << endl; gotoxy(5, 5);
	cout << "лллллллллл   ллллллллллл    ллл     ллл    ллл            ллллллллллл     " << endl; gotoxy(5, 6);
	cout << "ллл          ллл           ллллллллллллл   ллл            ллл             " << endl; gotoxy(5, 7);
	cout << "ллл          ллл          ллл         ллл  ллл            ллл             " << endl; gotoxy(5, 8);
	cout << "ллл          ллллллллллл ллл           ллл  лллллллллл    ллллллллллл     " << endl << endl; gotoxy(6, 11);


	cout << "     **************************************************************" << endl;
	gotoxy(6, 13);
	cout << "                       HOTEL MANAGEMENT PROJECT                     " << endl;
	gotoxy(6, 15);
	cout << "     **************************************************************" << endl;
}


///////////////

void GUI::logout()
{
	system("color B0");
	int quyen;
	DrawGUILogin(quyen);
	switch (quyen) {
	case 1: {
		while (true)
		{

			system("cls");
			DrawGUIMainMenu1();
		};
	}; break;
	case 2: {
		while (true)
		{

			system("cls");
			DrawGUIMainMenu2();
		};
	}; break;
	case 3: {
		while (true)
		{

			system("cls");
			DrawGUIMainMenu3();
		};
	}; break;
	}
	system("pause");
}
void GUI::DrawGUIMainMenu1()
{
	system("cls");
	system("color 0D");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________DIRECTOR'S MENU_________________________";
		cout << "\n\n 1: Employee management  ";
		cout << "\n\n 2: Salary management ";
		cout << "\n\n 3: Room management";
		cout << "\n\n 4: Service management";
		cout << "\n\n 5: Account";
		cout << "\n\n 6: Statistics ";
		cout << "\n\n 7: Log out ";
		cout << "\n\n 8: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '8')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;
		TABLE T('-', '|', '+');
		TABLE T1('-', '|', '+');
		TABLE T2('-', '|', '+');
		int GD;
		int QL;
		int TT;
		system("cls");
		switch (choice)
		{
		case '1':
			DrawGUISubMenu11();
			system("pause");
			break;
		case '2':
			DrawGUISubMenu12();
			system("pause");
			break;
		case '3':
			DrawGUISubMenu13();
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			DrawGUISubMenu14();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			cout << "\n\n  _________________________Your account_________________________\n\n";
			for (int i = 0; i < khachsan.GetDSNhanVien().size(); i++) {
				if (mnv == khachsan.GetDSNhanVien()[i].GetMaNV()) {
					khachsan.GetDSNhanVien()[i].Xuat();
				}
			}
			cout << "\n\n\t";
			system("pause");
			break;
		case '6':
			cout << "\n\n  _________________________Statistics_________________________";
			cout << "\n\nEMPLOYEES: " << endl;
			GD = khachsan.DemNhanVien("GD");
			QL = khachsan.DemNhanVien("QL");
			TT = khachsan.DemNhanVien("TT");
			T.add("No. of Directors: ");
			T.add(to_string(GD));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("No. of Managers: ");
			T.add(to_string(QL));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("No. of Receptionists: ");
			T.add(to_string(TT));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("No. of Employees: ");
			T.add(to_string(TT+GD+QL));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);
			
			T.add("Total Salary: ");
			T.add(to_string(khachsan.TinhTongLuong()));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);
			cout << T;

			cout << "\n\nREVENUE: " << endl;
			T1.add("Revenue from room: ");
			T1.add(to_string(khachsan.TinhDoanhThuTheoPhong()));
			T1.endOfRow();
			T1.setAlignment(1, TABLE::Alignment::RIGHT);

			T1.add("Revenue from services: ");
			T1.add(to_string(khachsan.TinhDoanhThuTheoDV()));
			T1.endOfRow();
			T1.setAlignment(1, TABLE::Alignment::RIGHT);

			T1.add("Total revenue: ");
			T1.add(to_string(khachsan.TinhDoanhThuTheoDV()+khachsan.TinhDoanhThuTheoPhong()));
			T1.endOfRow();
			T1.setAlignment(1, TABLE::Alignment::RIGHT);
			cout << T1;
			cout << "\n\nPROFIT: " << endl;
			T2.add("Profit from room: ");
			T2.add(to_string(khachsan.TinhDoanhThuTheoPhong()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);

			T2.add("Profit from services: ");
			T2.add(to_string(khachsan.TinhLoiNhuanTheoDV()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);

			T2.add("Gross profit: ");
			T2.add(to_string(khachsan.TinhLoiNhuanGop()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);

			T2.add("Net profit: ");
			T2.add(to_string(khachsan.TinhLoiNhuanThuan()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);
			cout << T2;
			system("pause");
			break;
		case '7':
			logout();
			break;
		case '8':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu11()
{
	system("cls");
	system("color 0D");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Employee Management_________________________";
		cout << "\n\n 1: View employee list  ";
		cout << "\n\n 2: Insert employee";
		cout << "\n\n 3: Delete an employee ";
		cout << "\n\n 4: Search employee by code ";
		cout << "\n\n 5: Edit employees' information ";
		cout << "\n\n 6: Log out ";
		cout << "\n\n 7: Back ";
		cout << "\n\n 8: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '8')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;
		string code;
		int check;

		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSNhanVien();
			system("pause");
			break;
		case '2':
			khachsan.ThemNhanVien();
			system("pause");
			break;
		case '3':
			cin.ignore();
			cout << "Enter employee code to be deleted: ";
			cin >> code;
			cin.ignore();
			if (mnv == code) {
				cout << "Your code is " << mnv << ". Are you sure to delete yourself? (1-yes, 0-no): ";
				cin >> check;
				if (check == 1) {
					khachsan.XoaNhanVien(mnv);
					logout();
				}
				else {
					cout << "Enter employee code to be deleted: ";
					cin >> code;
					cin.ignore();
					khachsan.XoaNhanVien(code);
				}
			}
			else {
				khachsan.XoaNhanVien(code);
			}
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			khachsan.TimNhanVienTheoMa();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			khachsan.SuaThongTinNhanVien();
			system("pause");
			break;
		case '6':
			logout();
			break;
		case '7':
			DrawGUIMainMenu1();
			break;
		case '8':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu12()
{
	system("cls");
	system("color 0D");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Salary Management_________________________";
		cout << "\n\n 1: View salary unit  ";
		cout << "\n\n 2: Edit salary unit  ";
		cout << "\n\n 3: Calculate salary ";
		cout << "\n\n 4: View salary list";
		cout << "\n\n 5: Arrange in discending order of salary";
		cout << "\n\n 6: Arrange in ascending order of salary";
		cout << "\n\n 7: Back ";
		cout << "\n\n 8: Log out ";
		cout << "\n\n 9: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '9')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;
		float temp;
		vector<NHANVIEN> dsnv;
		TABLE T('-', '|', '*');
		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSHSL();
			system("pause");
			break;
		case '2':
			khachsan.SuaHSL();
			system("pause");
			break;
		case '3':
			dsnv.resize(khachsan.GetDSNhanVien().size());
			for (int i = 0; i < khachsan.GetDSNhanVien().size(); i++) {
				dsnv[i].SetMaNV(khachsan.GetDSNhanVien()[i].GetMaNV());
				dsnv[i].SetPwd(khachsan.GetDSNhanVien()[i].GetPw());
				dsnv[i].SetTenNV(khachsan.GetDSNhanVien()[i].GetTen());
				dsnv[i].SetmaCV(khachsan.GetDSNhanVien()[i].GetMaCV());
				dsnv[i].SetCV(khachsan.GetDSNhanVien()[i].GetCV());
				dsnv[i].SetLuong(dsnv[i].TinhLuong(khachsan.GetdsHSL(),temp));
				dsnv[i].SetGioLamViec(temp);
			}
			khachsan.SetDSNhanVien(dsnv);
			khachsan.GhiDSNhanVien();
			khachsan.XuatDSNhanVien();
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			khachsan.XuatDSNhanVien();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			dsnv = khachsan.SapXepLuongGiamDan();
			T.add("Employee Code");
			T.add("Password");
			T.add("Name");
			T.add("Position");
			T.add("Working hours");
			T.add("Salary");
			T.endOfRow();

			for (int i = 0; i < dsnv.size(); i++) {
				T.add(dsnv[i].GetMaNV());
				T.add(dsnv[i].GetPw());
				T.add(dsnv[i].GetTen());
				T.add(dsnv[i].GetCV());
				T.add(to_string(dsnv[i].GetGioLamViec()));
				T.add(to_string(dsnv[i].GetLuong()));
				T.endOfRow();
				T.setAlignment(4, TABLE::Alignment::RIGHT);
				T.setAlignment(5, TABLE::Alignment::RIGHT);
			}
			cout << T;
			cout << "\n\n\t";
			system("pause");
			break;
		case '6':
			dsnv = khachsan.SapXepLuongTangDan();
			T.add("Employee Code");
			T.add("Password");
			T.add("Name");
			T.add("Position");
			T.add("Working hours");
			T.add("Salary");
			T.endOfRow();

			for (int i = 0; i < dsnv.size(); i++) {
				T.add(dsnv[i].GetMaNV());
				T.add(dsnv[i].GetPw());
				T.add(dsnv[i].GetTen());
				T.add(dsnv[i].GetCV());
				T.add(to_string(dsnv[i].GetGioLamViec()));
				T.add(to_string(dsnv[i].GetLuong()));
				T.endOfRow();
				T.setAlignment(4, TABLE::Alignment::RIGHT);
				T.setAlignment(5, TABLE::Alignment::RIGHT);
			}
			cout << T;
			cout << "\n\n\t";
			system("pause");
			break;
		case '8':
			logout();
			break;
		case '7':
			DrawGUIMainMenu1();
			break;
		case '9':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu13()
{
	system("cls");
	system("color 0D");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Room Management_________________________";
		cout << "\n\n 1: View Room Type List  ";
		cout << "\n\n 2: Edit Room Price ";
		cout << "\n\n 3: Insert Room Type ";
		cout << "\n\n 4: View Room list ";
		cout << "\n\n 5: Insert Room ";
		cout << "\n\n 6: Edit Room's Information ";
		cout << "\n\n 7: Delete Room ";
		cout << "\n\n 8: Back ";
		cout << "\n\n 9: Log out ";
		cout << "\n\n 0: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '0' && choice <= '9')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;

		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSLoaiPhong();
			system("pause");
			break;
		case '2':
			khachsan.SuaGiaPhong();
			cout << "New Room Price:" << endl;
			khachsan.XuatDSLoaiPhong();
			system("pause");
			break;
		case '3':
			khachsan.ThemLoaiPhong();
			system("pause");
			break;
		case '4':
			khachsan.XuatDSPhong();
			system("pause");
			break;
		case '5':
			khachsan.ThemPhong();
			system("pause");
			break;
		case '6':
			khachsan.SuaPhong();
			system("pause");
			break;
		case '7':
			khachsan.XoaPhong();
			system("pause");
			break;
		case '9':
			logout();
			break;
		case '8':
			DrawGUIMainMenu1();
			break;
		case '0':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu14()
{
	system("cls");
	system("color 0D");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Service Management_________________________";
		cout << "\n\n 1: View Service list  ";
		cout << "\n\n 2: Edit Service price ";
		cout << "\n\n 3: Insert Services ";
		cout << "\n\n 4: Delete Services ";
		cout << "\n\n 5: Back ";
		cout << "\n\n 6: Log out ";
		cout << "\n\n 7: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '7')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;

		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSLoaiDichVu();
			cout << "\n\n\t";
			system("pause");
			break;
		case '2':
			khachsan.SuaDSLoaiDV();
			system("pause");
			break;
		case '3':
			khachsan.ThemLoaiDichVu();
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			khachsan.XoaLoaiDichVu();
			system("pause");
			break;
		case '5':
			DrawGUIMainMenu1();
			break;
		case '6':
			logout();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUIMainMenu2()
{
	system("cls");
	system("color 9F");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________MANAGERS' MENU_________________________";
		cout << "\n\n 1: Employee management  ";
		cout << "\n\n 2: Room management";
		cout << "\n\n 3: Service management";
		cout << "\n\n 4: Account";
		cout << "\n\n 5: Statistics ";
		cout << "\n\n 6: Log out ";
		cout << "\n\n 7: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();
		TABLE T('-', '|', '-');
		TABLE T1('-', '|', '-');
		TABLE T2('-', '|', '-');
		if (choice >= '1' && choice <= '7')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;
		int QL;
		int GD;
		int TT;
		system("cls");
		switch (choice)
		{
		case '1':
			DrawGUISubMenu21();
			system("pause");
			break;
		case '2':
			DrawGUISubMenu22();
			system("pause");
			break;
		case '3':
			DrawGUISubMenu23();
			system("pause");
			break;
		case '4':
			for (int i = 0; i < khachsan.GetDSNhanVien().size(); i++) {
				if (mnv == khachsan.GetDSNhanVien()[i].GetMaNV()) {
					khachsan.GetDSNhanVien()[i].Xuat();
				}
			}
			system("pause");
			break;
		case '5':
			cout << "\n\n  _________________________Statistics_________________________";
			cout << "\n\nEMPLOYEES: " << endl;
			GD = khachsan.DemNhanVien("GD");
			QL = khachsan.DemNhanVien("QL");
			TT = khachsan.DemNhanVien("TT");
			T.add("No. of Directors: ");
			T.add(to_string(GD));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("No. of Managers: ");
			T.add(to_string(QL));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("No. of Receptionists: ");
			T.add(to_string(TT));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("No. of Employees: ");
			T.add(to_string(TT + GD + QL));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);

			T.add("Total Salary: ");
			T.add(to_string(khachsan.TinhTongLuong()));
			T.endOfRow();
			T.setAlignment(1, TABLE::Alignment::RIGHT);
			cout << T;

			cout << "\n\nREVENUE: " << endl;
			T1.add("Revenue from room: ");
			T1.add(to_string(khachsan.TinhDoanhThuTheoPhong()));
			T1.endOfRow();
			T1.setAlignment(1, TABLE::Alignment::RIGHT);

			T1.add("Revenue from services: ");
			T1.add(to_string(khachsan.TinhDoanhThuTheoDV()));
			T1.endOfRow();
			T1.setAlignment(1, TABLE::Alignment::RIGHT);

			T1.add("Total revenue: ");
			T1.add(to_string(khachsan.TinhDoanhThuTheoDV() + khachsan.TinhDoanhThuTheoPhong()));
			T1.endOfRow();
			T1.setAlignment(1, TABLE::Alignment::RIGHT);
			cout << T1;
			cout << "\n\nPROFIT: " << endl;
			T2.add("Profit from room: ");
			T2.add(to_string(khachsan.TinhDoanhThuTheoPhong()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);

			T2.add("Profit from services: ");
			T2.add(to_string(khachsan.TinhLoiNhuanTheoDV()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);

			T2.add("Gross profit: ");
			T2.add(to_string(khachsan.TinhLoiNhuanGop()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);

			T2.add("Net profit: ");
			T2.add(to_string(khachsan.TinhLoiNhuanThuan()));
			T2.endOfRow();
			T2.setAlignment(1, TABLE::Alignment::RIGHT);
			cout << T2;
			system("pause");
			break;
		case '6':
			logout();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu21()
{
	system("cls");
	system("color 9F");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Employee Management_________________________";
		cout << "\n\n 1: View employee list  ";
		cout << "\n\n 2: Insert employee";
		cout << "\n\n 3: Delete an employee ";
		cout << "\n\n 4: Search employee by code ";
		cout << "\n\n 5: Edit employees' information ";
		cout << "\n\n 6: Log out ";
		cout << "\n\n 7: Back ";
		cout << "\n\n 8: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '8')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;
		string code;
		int check;
		NHANVIEN nhanvien;
		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSNhanVien();
			system("pause");
			break;
		case '2':
			khachsan.ThemNhanVien();
			system("pause");
			break;
		case '3':
			cout << "Enter employee code to be deleted: ";
			cin >> code;
			if (mnv == code) {
				cout << "Your code is " << mnv << ". Are you sure to delete yourself? (1-yes, 0-no): ";
				cin >> check;
				if (check == 1) {
					khachsan.XoaNhanVien(mnv);
					logout();
				}
				else {
					DrawGUIMainMenu2();
				}
			}
			else {
				nhanvien.SetMaNV(code);
				for (int i = 0; i < khachsan.GetDSNhanVien().size(); i++) {
					if (code == khachsan.GetDSNhanVien()[i].GetMaNV()) {
						nhanvien.SetmaCV(khachsan.GetDSNhanVien()[i].GetMaCV());
					}
				}
				if (nhanvien.KiemTraGD()) {
					cout << "\nYou can't delete your Director.\n";
				}
				else {
					khachsan.XoaNhanVien(code);
				}
			}
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			khachsan.TimNhanVienTheoMa();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			khachsan.SuaThongTinNhanVien();
			system("pause");
			break;
		case '6':
			logout();
			break;
		case '7':
			DrawGUIMainMenu2();
			break;
		case '8':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu22()
{
	system("cls");
	system("color 9F");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Room Management_________________________";
		cout << "\n\n 1: View Room Type List  ";
		cout << "\n\n 2: Edit Room Price ";
		cout << "\n\n 3: Insert Room Type ";
		cout << "\n\n 4: View Room list ";
		cout << "\n\n 5: Insert Room ";
		cout << "\n\n 6: Edit Room's Information ";
		cout << "\n\n 7: Delete Room ";
		cout << "\n\n 8: Back ";
		cout << "\n\n 9: Log out ";
		cout << "\n\n 0: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '0' && choice <= '9')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;

		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSLoaiPhong();
			system("pause");
			break;
		case '2':
			khachsan.SuaGiaPhong();
			cout << "New Room Price:" << endl;
			khachsan.XuatDSLoaiPhong();
			system("pause");
			break;
		case '3':
			khachsan.ThemLoaiPhong();
			system("pause");
			break;
		case '4':
			khachsan.XuatDSPhong();
			system("pause");
			break;
		case '5':
			khachsan.ThemPhong();
			system("pause");
			break;
		case '6':
			khachsan.SuaPhong();
			system("pause");
			break;
		case '7':
			khachsan.XoaPhong();
			system("pause");
			break;
		case '9':
			logout();
			break;
		case '8':
			DrawGUIMainMenu2();
			break;
		case '0':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu23()
{
	system("cls");
	system("color 9F");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Service Management_________________________";
		cout << "\n\n 1: View Service list  ";
		cout << "\n\n 2: Edit Service list ";
		cout << "\n\n 3: Insert Services ";
		cout << "\n\n 4: Delete Services ";
		cout << "\n\n 5: Back ";
		cout << "\n\n 6: Log out ";
		cout << "\n\n 7: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '7')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;

		system("cls");
		switch (choice)
		{
		case '1':
			khachsan.XuatDSLoaiDichVu();
			cout << "\n\n\t";
			system("pause");
			break;
		case '2':
			khachsan.SuaDSLoaiDV();
			cout << "\n\n\t";
			system("pause");
			break;
		case '3':
			khachsan.ThemLoaiDichVu();
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			khachsan.XoaLoaiDichVu();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			DrawGUIMainMenu2();
			break;
		case '6':
			logout();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUIMainMenu3()
{
	system("cls");
	system("color F0");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________EMPLOYEES' MENU_________________________";
		cout << "\n\n 1: Customer management  ";
		cout << "\n\n 2: Account ";
		cout << "\n\n 3: Log out ";
		cout << "\n\n 4: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '4')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;

		system("cls");
		switch (choice)
		{
		case '1':
			DrawGUISubMenu31();
			system("pause");
			break;
		case '2':
			for (int i = 0; i < khachsan.GetDSNhanVien().size(); i++) {
				if (mnv == khachsan.GetDSNhanVien()[i].GetMaNV()) {
					khachsan.GetDSNhanVien()[i].Xuat();
				}
			}
			cout << "\n\n\t";
			system("pause");
			break;
		case '3':
			logout();
			break;
		case '4':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
void GUI::DrawGUISubMenu31()
{
	system("cls");
	system("color F0");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________Customer Management_________________________";
		cout << "\n\n 1: View Customer List  ";
		cout << "\n\n 2: Update Room Status ";
		cout << "\n\n 3: Insert customer ";
		cout << "\n\n 4: Edit customer";
		cout << "\n\n 5: Delete customer";
		cout << "\n\n 6: Export a bill";
		cout << "\n\n 7: Bill List";
		cout << "\n\n 8: Back";
		cout << "\n\n 9: Log out ";
		cout << "\n\n 0: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '0' && choice <= '9')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48;

		system("cls");
		switch (choice)
		{
		case '1':
			cout << "\n\n  _________________________Customer List_________________________\n\n";
			khachsan.XuatDSKhachHang(khachsan.GetDSKhachHang());
			system("pause");
			break;
		case '2':
			khachsan.CapNhatStatusPhong();
			cout << "\n\n\t";
			system("pause");
			break;
		case '3':
			cout << "ROOM STATUS (0-Not Available; 1-Available; 2-Vacant clean)\n\n";
			khachsan.XuatDSPhong();
			cout << "\n\n------------***------------\n\n";
			khachsan.ThemKhachHang();
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			khachsan.SuaKhachHang();
			system("pause");
			break;
		case '5':
			khachsan.XoaKhachHang();
			cout << "\n\n\t";
			system("pause");
			break;
		case '6':
			khachsan.ThemBill();
			cout << "\n\n\t";
			system("pause");
			break;
		case '7':
			cout << "\n\n  _________________________Bill List_________________________\n\n";
			khachsan.XuatBill();
			cout << "\n\n\t";
			system("pause");
			break;
		case '8':
			DrawGUIMainMenu3();
			cout << "\n\n\t";
			system("pause");
			break;
		case '9':
			logout();
			break;
		case '0':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}