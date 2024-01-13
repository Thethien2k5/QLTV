#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> //khả năng đọc chuỗi tốt hơn
#include <sstream>
#include <iomanip>
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>

using namespace std;

void input_all(wstring A[][8], int run)
{
    wcout << "|" << left << setw(7) << L"Id sách"
          << "|" << setw(45) << L"Tên sách"
          << "|" << setw(24) << L"Chủ đề"
          << "|" << setw(29) << L"Tác giả"
          << "|" << setw(24) << L"Nhà xuất bản"
          << "|" << setw(17) << L"Năm xuất bản"
          << "|" << setw(7) << L"Trang"
          << "|" << setw(7) << L"số bản copy" << "\n";

    for (size_t _ = 0; _ < 168; _++)
    {
        wcout << L"_";
    }
    wcout << L"\n";

    for (size_t _ = 0; _ < run; _++)
    {
        if (A[_][0] == L" ")
        {
            continue;
        }
        wcout << "|" << left << setw(7) << A[_][0]
              << "|" << setw(45) << A[_][1]
              << "|" << setw(24) << A[_][2]
              << "|" << setw(29) << A[_][3]
              << "|" << setw(24) << A[_][4]
              << "|" << setw(17) << A[_][5]
              << "|" << setw(7) << A[_][6]
              << "|" << setw(7) << A[_][7] << endl;
    }
}
int xem_va_timkiem()
{
    wifstream xvtk("book.txt");
    wstring A[999][8], x;

    int run = 0;

    while (getline(xvtk, x))
    {
        if (x.empty())
        {
            continue;
        }

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

    while (true)
    {
        system("cls");
        wcout << L"Menu Tìm Kiếm Sách " << endl;
        wcout << L"( 1 ).Theo Tên Sách\n( 2 ).Theo Chủ Đề\n( 3 ).Theo Tác Giả\n";
        wcout << L"( 4 ).Theo Nhà Xuất Bản\n( 5 ).Theo Năm Xuất Bản\n( 6 ).In ra tất cả\n";
        wcout << L">>  ";
        int choice;
        wcin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            wstring tensach;
            wcout << L"Nhập tên sách cần tìm kiếm: ";
            wcin >> tensach;
            int cnt = 0;
            for (size_t i = 0; i <= run; i++)
            {
                if (tensach == A[i][1])
                {
                    cnt++;
                    wcout << A[i][0] << " | " << A[i][1] << " | " << A[i][2] << " | " << A[i][3]
                          << " | " << A[i][4] << " | " << A[i][5] << " | " << A[i][6] << " | " << A[i][7] << "\n";
                }
            }
            if (cnt == 0)
            {
                wcout << L"Không tìm thấy.\n";
            }
            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
                break;
            else
                wcout << L"Xin cảm ơn!!";
            return 0;
        }
        case 2:
        {
            system("cls");
            wstring chude;
            wcout << L"Nhập chủ đề cần tìm kiếm: ";
            wcin >> chude;
            int cnt = 0;
            for (size_t i = 0; i <= run; i++)
            {
                if (chude == A[i][2])
                {
                    cnt++;
                    wcout << A[i][0] << " | " << A[i][1] << " | " << A[i][2] << " | " << A[i][3]
                          << " | " << A[i][4] << " | " << A[i][5] << " | " << A[i][6] << " | " << A[i][7] << "\n";
                }
            }
            if (cnt == 0)
            {
                wcout << L"Không tìm thấy.\n";
            }
            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
                break;
            else
                wcout << L"Xin cảm ơn!!";
            return 0;
        }
        case 3:
        {
            system("cls");
            wstring tacgia;
            wcout << L"Nhập tác giả cần tìm kiếm: ";
            wcin >> tacgia;
            int cnt = 0;
            for (size_t i = 0; i <= run; i++)
            {
                if (tacgia == A[i][3])
                {
                    cnt++;
                    wcout << A[i][0] << " | " << A[i][1] << " | " << A[i][2] << " | " << A[i][3]
                          << " | " << A[i][4] << " | " << A[i][5] << " | " << A[i][6] << " | " << A[i][7] << "\n";
                }
            }
            if (cnt == 0)
            {
                wcout << L"Không tìm thấy.\n";
            }
            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
                break;
            else
                wcout << L"Xin cảm ơn!!";
            return 0;
        }
        case 4:
        {
            system("cls");
            wstring nxb;
            wcout << L"Nhập tên nhà xuất bản cần tìm kiếm: ";
            wcin >> nxb;
            int cnt = 0;
            for (size_t i = 0; i <= run; i++)
            {
                if (nxb == A[i][4])
                {
                    cnt++;
                    wcout << A[i][0] << " | " << A[i][1] << " | " << A[i][2] << " | " << A[i][3]
                          << " | " << A[i][4] << " | " << A[i][5] << " | " << A[i][6] << " | " << A[i][7] << "\n";
                }
            }
            if (cnt == 0)
            {
                wcout << L"Không tìm thấy.\n";
            }
            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
                break;
            else
                wcout << L"Xin cảm ơn!!";
            return 0;
        }
        case 5:
        {
            system("cls");
            wstring ngxb;
            wcout << L"Nhập tên nhà xuất bản cần tìm kiếm: ";
            wcin >> ngxb;
            int cnt = 0;
            for (size_t i = 0; i <= run; i++)
            {
                if (ngxb == A[i][5])
                {
                    cnt++;
                    wcout << A[i][0] << " | " << A[i][1] << " | " << A[i][2] << " | " << A[i][3]
                          << " | " << A[i][4] << " | " << A[i][5] << " | " << A[i][6] << " | " << A[i][7] << "\n";
                }
            }
            if (cnt == 0)
            {
                wcout << L"Không tìm thấy.\n";
            }
            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
                break;
            else
                wcout << L"Xin cảm ơn!!";
            return 0;
        }
        case 6:
        {
            system("cls");

            input_all(A, run);

            wcout << L"Bạn có muốn tiếp tục không ( Y/N )?: ";
            wstring yc;
            wcin >> yc;
            if (yc == L"Y")
                break;
            else
                wcout << L"Xin cảm ơn!!";
            return 0;
        }
        default:
            continue;
        }
    }
    return 0;
}

int main_search_book()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    xem_va_timkiem();
    return 0;
}
