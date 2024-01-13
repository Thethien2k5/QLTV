#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>
//
using namespace std;
// import file
#include "all.h"

bool log_in()
{

    // lấy thông tin từ file admin
    wifstream ad("admin.txt"); // Tạo đối tượng ad mở và đọc file admin.txt
    wstring A[7][2], x;        // Tối đa bảy người quản lý được rồi, nhiều dễ bị tham nhũng :)))

    int run = 0; // Biến chạy cho A
    // Đối tượng ad sẽ lần lượt đọc các dòng trog file - 1 vòng là 1 dòng
    while (getline(ad, x)) // Nhập thông tin từ đối tượng ad vào biến x
    {
        // Tách phần tên và mật khẩu trong x
        wstring name = L"", pass = L"";
        bool kt = false;
        for (size_t i = 0; i < x.size(); ++i)
        {
            if (kt)
            {
                break;
            }
            if (x[i] == ' ')
            {
                for (size_t j = i + 1; j < x.size(); ++j)
                {
                    pass += x[j]; // Phần mật khẩu
                }
                kt = true;
                break;
            }
            name += x[i]; // Phần tên
        }

        // Đưa name và pass vào A
        A[run][0] = name;
        A[run][1] = pass;
        run++;
    }
    ad.close(); // Đóng file admin.txt

    int kt = 0;
    while (true)
    {
        system("cls");
        wstring user_name, pass;

        // Nếu nhập sai nhiều lần
        if (kt == 0)
        {
            wcout << L"Quyền admin : Đăng nhập :\n";
        }
        else
        {
            wcout << L"Sai lần: " << kt;
            wcout << L"\nTên đăng nhập hoặc mật khẩu không chính xác\nVui lòng nhập lại\n";
        }
        // Đăng nhập
        wcout << L"Tên Đăng Nhập: ";
        wcin >> user_name;
        wcout << L"Mật Khẩu: ";
        wcin >> pass;

        // Kiểm tra có name và pass trong admin.txt hay không
        for (int _ = 0; _ <= 7; _++)
        {
            if (_ == 7) // Không tìm được tk hợp lệ
            {
                kt++;
                if (kt >= 3)
                {
                    return false; // Đăng nhập thất bại
                }
            }
            if (user_name == A[_][0]) // Đã tìm được tài khoảng
            {
                if (pass == A[_][1])
                {
                    return true; // Đăng nhập thành công
                }
            }
        }
    }
}

int main()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    int role;
    while (true)
    {
        system("cls");

        // Xác định vai trò đầu vào
        wcout << L"Vai trò của bạn: \n";
        wcout << L"( 0 ):End\n( 1 ):Tôi là admin\n( 2 ):Tôi là user.\n>>";
        wcin >> role;

        if (role == 0) // Kết thúc chương trình
        {
            system("cls");
            wcout << L"End!!";
            return 0;
        }
        else if (role == 1 or role == 2) // Điều kiện đúng để thoát vòng xác định vai trò
        {
            break;
        }
        else
        {
            continue;
        }
    }
    if (role == 1) // Vai trò admin
    {
        bool kt = log_in(); // Đăng nhập với name và pass
        if (kt)
        {
            system("cls");
            wcout << L"Đăng Nhập Thành Công\n";
            while (true)
            {
                wcout << L"Quản Lý: \n( 0 ):End.\n( 1 ):Quản Lý Thư Viện.\n( 2 ):Quản Lý User.\n>> ";
                int x;
                wcin >> x;
                if (x == 0) // Kết thức công việc admin
                {
                    system("cls");
                    wcout << L"End!!";
                    return 0;
                }
                else if (x == 1) // Quản lý thư viện
                {
                    system("cls");
                    main_QLbook();
                    return 0;
                }
                else if (x == 2) // Quản lý user
                {
                    system("cls");
                    while (true)
                    {
                        wcout << L"Quản Lý User: \n( 0 ):Quay Lại.\n( 1 ):Quản Lý Black list.\n>> ";
                        int y;
                        wcin >> y;
                        if (y == 0)
                        {
                            break;
                        }
                        else if (y == 1)
                        {
                            main_QLblack_list(); // Đi đến quản lý danh sách đen
                            break;
                        }
                        else // Nhập sai yêu cầu nhập lại
                        {

                            continue;
                        }
                    }
                }
                else // Nhập sai yêu cầu nhập lại
                {
                    continue;
                }
            }
        }
        else // Đăng nhập sai quá số lần
        {
            system("cls");
            wcout << L"Đăng Nhập Thất Bại";
            return 0;
        }
    }
    if (role == 2)
    {
        main_user();
    }

    return 0;
}
