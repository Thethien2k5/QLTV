#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
#include <vector>
#include <algorithm>
#include <iomanip>
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>
//
using namespace std;

int old_book()
{
    while (true)
    {

        vector<vector<wstring>> A;
        wstring x;
        int run = 0;
        wifstream xvtk("book.txt");

        while (getline(xvtk, x))
        {
            // Thêm một dòng mới vào 'A'
            A.push_back(vector<wstring>(8));
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

        system("cls");
        wcout << L"Sách đã có trong thư viện.\nNên chỉ có thể cập nhật thêm số lượng sách\n";
        wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
        wstring yc;
        wcin >> yc;
        if (yc == L"Y")
        {
            wcout << L"Nhập tên sách: ";
            wstring name_book;
            wcin >> name_book;

            bool kt = true;

            for (size_t i = 0; i < A.size(); i++)
            {
                kt = true;
                if (name_book == A[i][1])
                {
                    kt = false;
                    break;
                }
            }

            if (kt)
            {
                kt = true;
                system("cls");
                wcout << L"Không tìm thấy sách trong thư viện\n";
                wcout << L"Ấn kí tự bất kì để nhập lại: ";
                wchar_t c;
                wcin >> c;

                continue;
            }

            wcout << L"Nhập số lượng sách muốn thêm: ";
            int x;
            wcin >> x;

            for (size_t i = 0; i < A.size(); i++)
            {
                if (name_book == A[i][1])
                {
                    A[i][7] = to_wstring(x + stol(A[i][7]));
                    break;
                }
            }

            wofstream user_in; // tạo đối tượng user ghi file
            user_in.open("book.txt");
            for (int j = 0; j < A.size(); j++)
            {
                user_in << A[j][0] << " " << A[j][1] << " " << A[j][2] << " " << A[j][3] << " " << A[j][4] << " " << A[j][5] << " " << A[j][6] << " " << A[j][7] << "\n";
            }
            user_in.close();

            system("cls");
            wcout << L"Đã cập nhật.\n";
            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
}

int new_book()
{
    while (true)
    {

        vector<wstring> A;
        wstring x;
        int run = 0;
        wifstream xvtk("book.txt");

        while (getline(xvtk, x))
        {
            wstring isbn;
            for (size_t i = 0; i < x.size(); ++i)
            {
                if (x[i] == L' ')
                {
                    break;
                }
                isbn += x[i];
            }
            A.push_back(isbn);
        }
        xvtk.close();

        system("cls");
        wcout << L"Sách mới.\nBạn cần ghi đầy đủ thông tin để lưu nó vào thư viện\n";
        wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
        wstring yc;
        wcin >> yc;
        if (yc == L"Y")
        {
            wstring isbn, title, subject, author, publisher, date, pages, copies;

            wcout << L"ID Sách: ";
            wcin >> isbn;

            if (find(A.begin(), A.end(), isbn) != A.end())
            {
                wcout << L"ID đã tồn tại.\nNhấn kí tự bất kì để nhập lại: ";
                wchar_t t;
                wcin >> t;
                continue;
            }

            wcout << L"Tên Sách: ";
            wcin >> title;

            wcout << L"Chủ Đề: ";
            wcin >> subject;

            wcout << L"Tác Giả: ";
            wcin >> author;

            wcout << L"Nhà Xuất bản: ";
            wcin >> publisher;

            wcout << L"Năm Xuất Bản: ";
            wcin >> date;

            wcout << L"Số Trang: ";
            wcin >> pages;

            wcout << L"Số Bản Copy: ";
            wcin >> copies;

            system("cls");

            wofstream outfile;                       // Tao doi tuong outfile
            outfile.open("book.txt", ios_base::app); // Mở file với chế độ ghi nối tiếp
            outfile << "\n"
                    << isbn << " "
                    << title << " "
                    << subject << " "
                    << author << " "
                    << publisher << " "
                    << date << " "
                    << pages << " "
                    << copies; // Ghi thông tin mới vào file
            outfile.close();   // Dong file
            wcout << L"\nĐã lưu \n";

            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
}

int main_add()
{ // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    while (true)
    {

        system("cls");
        wcout << L"Thêm Sách\n";
        wcout << L"( 0 ).Quay lại.\n( 1 ).Thêm số lượng của sách đã có trong thư viện.\n( 2 ).Thêm sách mới.\n>> ";
        int x;
        wcin >> x;

        if (x == 0)
        {
            return 0;
        }
        else if (x == 1)
        {
            old_book();
        }
        else if (x == 2)
        {
            new_book();
        }
        else
        {
            continue;
        }
    }
    return 0;
}
