/*
#include <codecvt>


#include <sstream>
#include <corecrt_wstring.h>

#include <iostream>

#include "libxl.h"
using namespace libxl;

std::string wstring_to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(wstr);
}



int main()
{

   std:: locale::global(std::locale(""));
   
    int row = 0;
        int col = 0;

     
    Book* book = xlCreateBook();

    book->load(L"receipt.xls");
    
        
        Sheet * sheet = book->getSheet(0);
        
            for (int row_i = sheet->firstRow(); row_i < sheet->lastRow(); ++row)
            {
               
                    
                    if (sheet)
                    {
                       

                        const wchar_t* a = sheet->readStr(0, row);
                        std::wstring wstr(a);
                        std::wcout << wstr << std::endl;

                        


                        
                    }
               
               

            }

    book->release();
    return 0;


}*/