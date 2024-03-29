#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

int editBook()
{
    wifstream xvtk("book.txt"); 
    wstring A[999][8], x;

    int run = 0; 
    
    while (getline(xvtk, x)) 
    {
        wstring isbn = L"", title = L"", subject = L"",
               author = L"", publisher = L"", date = L"", pages = L"", copies = L"";

        int kt = 0;
        for (size_t i = 0; i < x.size(); ++i)
        {
            if (x[i] == ' ')
            {
                if (kt == 0)
                {
                    kt = 1;
                    continue;
                }
                if (kt == 1)
                {
                    kt = 2;
                    continue;
                }
                if (kt == 2)
                {
                    kt = 3;
                    continue;
                }
                if (kt == 3)
                {
                    kt = 4;
                    continue;
                }
                if (kt == 4)
                {
                    kt = 5;
                    continue;
                }
                if (kt == 5)
                {
                    kt = 6;
                    continue;
                }
                if (kt == 6)
                {
                    kt = 7;
                    continue;
                }
            }

            if (kt == 0)
            {
                isbn += x[i];
            }
            if (kt == 1)
            {
                title += x[i];
            }
            if (kt == 2)
            {
                subject += x[i];
            }
            if (kt == 3)
            {
                author += x[i];
            }
            if (kt == 4)
            {
                publisher += x[i];
            }
            if (kt == 5)
            {
                date += x[i];
            }
            if (kt == 6)
            {
                pages += x[i];
            }
            if (kt == 7)
            {
                copies += x[i];
            }
        }

        A[run][0] = isbn;
        A[run][1] = title;
        A[run][2] = subject;
        A[run][3] = author;
        A[run][4] = publisher;
        A[run][5] = date;
        A[run][6] = pages;
        A[run][7] = copies;
        run++;
    }
   
    xvtk.close();
	wfstream ofs;
	ofs.open("book.txt");
	while (true) {
        int index = -1;
        wstring name;

		system("cls");
        wcout << L"Nhập tên sách: ";
        wcin >> name;

        // Searching for the book
        for (size_t i = 0; i < run; i++) {
            if (A[i][0] == name || A[i][1] == name) {
                index = i;
                break; // Exit the loop once the book is found
            }
        }

        if (index != -1) {
            // Display book information
        	wcout << setw(8) << left << A[index][0] << "|" << setw(45) << left << A[index][1] << "|" << setw(25) << left << A[index][2] << "|"
                << setw(25) << left << A[index][3] << "|" << setw(25) << left << A[index][4] << "|" << setw(6) << left << A[index][5] << "|"
                << setw(5) << left << A[index][6] << "|" << setw(7) << left << A[index][7] << "|" << "\n";
            wcout<<L"\n----------Menu Chỉnh Sửa----------"<<endl;
            wcout<<L"1.Id sách.\n2.Tên sách.\n3.Chủ đề.\n4.Tác giả.\n5.Nhà xuất bản.\n6.Năm xuất bản.\n7.Số trang.\n8.Số bản sao.\n9.Thoát\n";
            int choice;
            wcout<<L"Nhap lua chon: ";wcin>>choice;
            switch (choice){
            	case 1:{
            		wstring id;
            		wcout<<L"Nhập id mới: ";wcin>>id;
            		A[index][0] = id;
            		ofs<<A[index][0];
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\n";
					wcout<<L"Bạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 2:{
            		wstring name;
            		wcout<<L"Nhập tên mới: ";wcin>>name;
            		A[index][1] = name;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 3:{
            		wstring subject;
            		wcout<<L"Nhập chủ đề mới: ";wcin>>subject;
            		A[index][2] = subject;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					}
            		else break;
            		//break;
            	}
            	case 4:{
            		wstring author;
            		wcout<<L"Nhập tên tác giả mới: ";wcin>>author;
            		A[index][3] = author;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 5:{
            		wstring publisher;
            		wcout<<"Nhập NXB mới: ";wcin>>publisher;
            		A[index][4] = publisher;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 6:{
            		wstring date;
            		wcout<<L"Nhập năm xb mới: ";wcin>>date;
            		A[index][5] = date;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 7:{
            		wstring pages;
            		wcout<<"Nhập số trang mới: ";wcin>>pages;
            		A[index][6] = pages;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 8:{
            		wstring copies;
            		wcout<<"Nhập số bản sao  mới: ";
            		A[index][7] = copies;wcin>>copies;
            		wcout<<A[index][0]<<"|"<<A[index][1]<<"|"<<A[index][2]<<"|"<<A[index][3]<<"|"<<A[index][4]<<"|"<<A[index][5]<<"|"<<A[index][6]<<"|"<<A[index][7]<<endl;
            		wcout<<L"Sửa thành công.\nBạn có muốn chỉnh sửa tiếp không(Y/N): ";
            		wstring lc;
            		wcin>>lc;
            		if (lc == L"Y"){
            			system("cls");
            			continue;
					} 
            		else break;
            		//break;
            	}
            	case 9:{
					break;
				}
            	default:
            		break;
			}
			return 0;
        } else {
            wcout << L"Không tìm thấy sách.\n";
            wstring yc;

            wcout << L"Bạn có muốn tìm sách khác không (Y/N): ";
            wcin >> yc;

            if (yc != L"Y")
                return 0; // Return 0 to indicate successful program termination
        }
	}
	ofs.close();
	return 0;
}
int main_edit()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

	editBook();
	return 0;
}
