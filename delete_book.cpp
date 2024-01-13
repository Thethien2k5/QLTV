#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> //khả năng đọc chuỗi tốt hơn
#include <sstream>
#include <iomanip>
#include <vector>
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>

using namespace std;

int search(int n, wstring input)
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

    vector<int> name;
    int cnt = 0, retu = -1;
    bool kt = false;
    for (size_t _ = 0; _ <= run; _++)
    {
        if (input == A[_][n])
        {
            name.push_back(_);
            cnt++;
            wcout << A[_][0] << " | " << A[_][1] << " | " << A[_][2] << " | " << A[_][3] << " | " << A[_][4] << " | " << A[_][5] << " | " << A[_][6] << " | " << A[_][7] << "\n\n";
            kt = true;
        }
    }
    if (cnt == 0)
    {
        system("cls");
        wcout << L"Không tìm thấy.\n";
        wcout << L"\nNhập kí tự bất kì đề quay lại:\n>>"; // Quay lại với người yêu cũ :)))
        wstring n;
        wcin >> n;
        return 0;
    }
    if (kt)
    {
        while (true)
        {
            wcout << L"( 1 )Xóa tất cả sách vừa tìm được.\n( 2 )Chỉ xóa một loại và số lượng.\n( 0 )Không xóa và quay lại.\n>> ";
            int z;
            wcin >> z;

            if (z == 0)
            {
                return 0;
            }
            else if (1 == z)
            {
                wofstream user_in; // tạo đối tượng user ghi file
                user_in.open("book.txt");
                for (int _ = 0; _ <= run; _++)
                {
                    bool kt = true;
                    for (int i = 0; i < name.size(); i++)
                    {
                        if (_ == name[i])
                        {
                            kt = false;
                            break;
                        }
                    }
                    if (kt)
                    {
                        user_in << A[_][0] << " " << A[_][1] << " " << A[_][2] << " " << A[_][3] << " " << A[_][4] << " " << A[_][5] << " " << A[_][6] << " " << A[_][7] << "\n";
                    }
                    kt = true;
                }
                user_in.close();

                wcout << L"Đã hoàn thành.\nNhập kí tự bất kì đề quay lại:\n>>"; // Quay lại với người yêu cũ :)))
                wstring n;
                wcin >> n;
                return 0;
            }
            else if (2 == z)
            {
                wstring tensach;
                int soluong;
                wcout << L"Nhập tên sách muốn xóa: ";
                wcin >> tensach;
                wcout << L"Số lượng sách\n( Nếu nhập vào lớn hơn số sách trong thư viện thì xóa hết cách đó )\n>> ";
                wcin >> soluong;

                int cnt = 0;
                int _ = -1;
                for (size_t i = 0; i <= run; i++)
                {
                    if (tensach == A[i][1])
                    {
                        cnt++;
                        wcout << A[i][0] << " | " << A[i][1] << " | " << A[i][2] << " | " << A[i][3]
                              << " | " << A[i][4] << " | " << A[i][5] << " | " << A[i][6] << " | " << A[i][7] << "\n";
                        _ = i;
                        break;
                    }
                }
                if (cnt == 0)
                {
                    wcout << L"Không tìm thấy.\n";
                    wcout << L"Nhập kí tự bất kì đề quay lại :\n >> "; // Quay lại với người yêu cũ :)))
                    wstring n;
                    wcin >> n;
                    system("cls");
                    continue;
                }

                wofstream user_in; // tạo đối tượng user ghi file
                user_in.open("book.txt");
                for (int j = 0; j <= run; j++)
                {
                    if (j != _)
                    {
                        user_in << A[j][0] << " " << A[j][1] << " " << A[j][2] << " " << A[j][3] << " " << A[j][4] << " " << A[j][5] << " " << A[j][6] << " " << A[j][7] << "\n";
                    }
                    if (j == _)
                    {
                        if (soluong < stoi(A[j][7]))
                        {
                            user_in << A[j][0] << " " << A[j][1] << " " << A[j][2] << " " << A[j][3] << " " << A[j][4] << " " << A[j][5] << " " << A[j][6] << " " << stoi(A[j][7]) - soluong << "\n";
                        }
                    }
                }
                user_in.close();

                wcout << L"Đã hoàn thành.\nNhập kí tự bất kì đề quay lại:\n>>"; // Quay lại với người yêu cũ :)))
                wstring n;
                wcin >> n;
                return 0;
            }
        }
    }
    return 0;
}

int main_dele()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    while (true)
    {
        system("cls");
        wstring input;
        int x;
        wcout << L"Xóa sách trong thư viện\n( 0 ).Quay lại\n";
        wcout << L"( 1 ).Theo Tên Sách\n( 2 ).Theo Chủ Đề\n( 3 ).Theo Tác Giả\n";
        wcout << L"( 4 ).Theo Nhà Xuất Bản\n( 5 ).Theo Năm Xuất Bản\n";
        wcout << L">>  ";
        wcin >> x;
        system("cls");

        if (x == 0)
        {
            break;
        }
        wcout << L"Nhập thông tin liên qua: ";
        wcin >> input;
        if (x != 1 and x != 2 and x != 3 and x != 4 and x != 5)
        {
            continue;
        }

        search(x, input);
    }
    return 0;
}
