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
        wcout << L"Quản Lý thư viện: \n( 0 ):Quay lại.\n( 1 ):Thêm sách vào thư viện.\n( 2 ):Xóa sách khỏi thư viện.\n>> ";
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
        else
        {
            continue;
        }
    }
}
