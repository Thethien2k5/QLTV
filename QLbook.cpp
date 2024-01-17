#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>
//
#include "all.h"
using namespace std;
int main_QLbook()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    while (true)
    {
        system("cls");
        wcout << L"Quản Lý thư viện: \n( 0 ):Quay lại.\n( 1 ):Thêm sách \
vào thư viện.\n( 2 ):Xóa sách khỏi thư viện.\n( 3 ).Chỉnh sửa thông tin sách\n( 4 ).Xem\n>> ";
        int x;
        wcin >> x;

        if (x == 0)
        {
            return 0;
        }
        else if (x == 1)
        {
            main_add();
        }
        else if (x == 2)
        {
            main_dele();
        }
        else if (x== 3)
        {
            editBook();
        }
        else if (x ==4)
        {
            xem_va_timkiem();
        }
        else
        {
            continue;
        }
    }
}
