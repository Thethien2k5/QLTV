#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
// xuất nhập tiếng Việt
#include <io.h>
#include <fcntl.h>
// 0
using namespace std;

int xem()
{
    // lấy thông tin từ file black_list.txt
    wifstream user("Black_list.txt"); // Tạo đối tượng user mở và đọc file Black_list.txt.txt
    wstring x;
    system("cls");
    wcout << L"Tất cả trong danh sách đen:\n";
    while (getline(user, x)) // Nhập thông tin từ đối tượng ad vào biến x
    {
        // In ra tất cả
        wcout << L"" << x << "\n";
    }
    user.close(); // Đóng file Black_list.txt

    wcout << L"\nNhập kí tự bất kì đề quay lại:\n>>"; // Quay lại với người yêu cũ :)))
    wstring n;
    wcin >> n;
    return 0;
}

void search()
{
    // lấy thông tin từ file black_list.txt
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

    system("cls");
    while (true)
    {
        wcout << L"Tìm Kiếm User\n";
        wcout << L"Nhập tên cần tìm kiếm: ";
        wstring name;
        wcin >> name;

        int x = 0;
        bool dk = false;
        for (int _ = 0; _ <= run; _++) // Vong tim
        {
            if (name == A[_])
            {
                wcout << L"Đã tìm được: " << A[_] << "\n"; // Da tim duoc
                wcout << L"Tiếp tục tìm kiếm ( Y/N ): ";
                wchar_t Y;
                wcin >> Y;
                if (Y == 'Y')
                {
                    dk = true;
                    system("cls");
                }
            }
            else
            {
                x++; // điều kiện để biết user mới đã có trong danh sách hay chưa
            }
        }
        if (x > run) // Khong tim duoc
        {
            wcout << L"Không tìm được: " << name << "\n";
            wcout << L"Tiếp tục tìm kiếm ( Y/N ): ";
            wchar_t Y;
            wcin >> Y;
            if (Y == 'Y')
            {
                dk = true;
                system("cls");
            }
        }
        if (dk)
        {
            dk = false;
            continue;
        }
        else
        {
            break;
        }
    }
}

void add()
{
    // lấy thông tin từ file black_list.txt
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

    system("cls");

    while (true)
    {
        wcout << L"Thêm User Vào Danh Sách Đen:\n";
        wcout << L"Tên user cần thêm: ";
        wstring name;
        wcin >> name; // Nhap ten can luu vao

        int x = 0;
        bool dk = false;
        for (int _ = 0; _ <= run; _++) // Vong tim
        {
            if (name == A[_])
            {
                dk = false;
                wcout << L"Đã tồn tai: " << A[_] << "\n"; // Đã có trong danh sách
                wcout << L"Tiếp tục: ( Y/N ): ";
                wchar_t Y;
                wcin >> Y;
                if (Y == 'Y')
                {
                    dk = true;
                    system("cls");
                    break; // Thoát khỏi vòng tìm kiếm
                }
            }
            else
            {
                x++; // điều kiện để biết user mới đã có trong danh sách hay chưa
            }
        }
        if (x > run and !dk) // Khong tim duoc
        {
            wcout << L"Xác nhận thêm: " << name << "\n";
            wcout << L"Xác nhận ( Y/N ): ";
            wchar_t Y;
            wcin >> Y;
            if (Y == 'Y')
            {
                system("cls");
                wofstream outfile;                             // Tao doi tuong outfile
                outfile.open("Black_list.txt", ios_base::app); // Mở file với chế độ ghi nối tiếp
                outfile << "\n"
                        << name; // Ghi thông tin mới vào file
                outfile.close(); // Dong file
                wcout << L"Đã lưu [" << name << "]\n";
                // Tiếp tuc hoặc không
                wcout << L"Tiếp tục: ( Y/N ): ";
                wchar_t Y;
                wcin >> Y;
                if (Y == 'Y')
                {
                    dk = true;
                    system("cls");
                }
            }
        }
        if (dk)
        {
            dk = false;
            continue;
        }
        else
        {
            break;
        }
    }
}

void dele()
{
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

    system("cls");

    while (true)
    {
        wcout << L"Xóa User Khỏi Danh Sách Đen:\n";
        wcout << L"Tên user cần xóa: ";
        wstring name;
        wcin >> name; // Nhap ten can luu vao

        int x = 0;
        bool dk = false;
        for (int _ = 0; _ <= run; _++) // Vong tim
        {
            if (name == A[_])
            {
                dk = false;
                wcout << L"Đã tìm thấy: " << name << "\n"; // có trong danh sách
                wcout << L"Xác nhận xóa ( Y/N ): ";
                wchar_t Y;
                wcin >> Y;
                if (Y == 'Y')
                {
                    A[_] = L"";
                    // Tiếp tuc hoặc không
                    wcout << L"Tiếp tục: ( Y/N ): ";
                    wchar_t Y;
                    wcin >> Y;
                    if (Y == 'Y')
                    {
                        dk = true;
                        system("cls");
                    }
                }
            }
            else
            {
                x++; // điều kiện để biết user mới đã có trong danh sách hay chưa
            }
        }
        if (x > run and !dk) // Khong tim duoc
        {
            wcout << L"Không tìm thấy: " << name << "\n";
            wcout << L"Tiếp tục: ( Y/N ): ";
            wchar_t Y;
            wcin >> Y;
            if (Y == L'Y')
            {
                dk = true;
                system("cls");
                break; // Thoát khỏi vòng tìm kiếm
            }
        }
        if (dk)
        {
            dk = false;
            continue;
        }
        else
        {
            break;
        }
    }

    wofstream user_out; // tạo đối tượng user ghi file
    user_out.open("Black_list.txt");
    for (size_t i = 0; i <= run; i++)
    {
        if (A[i] != L"")
        {
            user_out << A[i] << "\n";
        }
    }
    user_out.close();
}

int main_QLblack_list()
{
    // xuất nhập tiếng Việt
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    // Nhận dạng công việc
    int in;
    while (true)
    {
        system("cls");
        wcout << L"QUẢN LÝ DANH SÁCH ĐEN\n";
        wcout << L"( 0 ): Quay lại\n( 1 ): Xem tất cả\n( 2 ): Tìm kiếm\n( 3 ): Thêm\n( 4 ): Xóa\n>> ";
        wcin >> in;

        if (in == 0)
        {

            system("cls");
            wcout << "End!!";
            // Sắp xếp tại black_lít.txt
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
            user.close();

            wofstream user_out; // tạo đối tượng user ghi file
            user_out.open("Black_list.txt");
            for (size_t i = 0; i <= run; i++)
            {
                if (A[i] != L"")
                {
                    user_out << A[i] << "\n";
                }
            }
            user_out.close();

            return 0;
        }
        else if (in == 1)
        {
            xem();
            continue;
        }
        else if (in == 2)
        {
            search();
            continue;
        }
        else if (in == 3)
        {
            add();
            continue;
        }
        else if (in == 4)
        {
            dele();
            continue;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
