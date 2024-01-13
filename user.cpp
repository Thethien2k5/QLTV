#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>
// import file
#include "all.h"

using namespace std;
int main_user()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    wifstream user("Black_list.txt"); // Tạo đối tượng user mở và đọc file Black_list.txt.txt
    wstring x, A[9999];
    int run = 0;
    while (getline(user, x)) // Nhập thông tin từ đối tượng ad vào biến x
    {
        if (x != L"")
        {
            A[run] = x;
            run++;
        }
    }
    user.close(); // Đóng file Black_list.txt

    wcout << L"Nhập tên của bạn ( Viết liền không dấu): ";
    wstring NameUser;
    wcin >> NameUser;

    for (size_t _ = 0; _ <= run; _++)
    {
        if (NameUser == A[_])
        {
            wcout << L"Bạn đã quy phạm các nội quy của thư viện\nVà hiện tại bạn không có quyền truy cập vào thư viện";
            return 0;
        }
    }
    xem_va_timkiem();
    return 0;
}
