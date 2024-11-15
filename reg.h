#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string> 
#include <fstream>

#include <sstream>


#include <codecvt>
#include "zapisVfail.h"
#include <windows.h.>
#include "libxl.h"
#include <corecrt_wstring.h>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
using namespace libxl;



using namespace std;


class user
{
public:
	

	std::string f_name;
	std::string l_name;
	
	
	void uuser()

	{
		const int MAXLEN = 80;
		char s[MAXLEN];
		time_t t = time(0);
		strftime(s, MAXLEN, "%m_%d_%Y", localtime(&t));
		

		std::cout << "\n\n\n\n\t\t\t\t input first name :";
		std::cin >> f_name;
		std::cout << std::endl << "\t\t\t\t input last name :";
		std::cin >> l_name;

		std::string namefile = f_name + "_" + l_name +" " + s + ".doc";
		std::ofstream ofs(namefile, std::ios::app);

		if (ofs.is_open())
		{
			ofs <<s<<endl<< f_name << " " << l_name << std::endl << "test result :";
		}


	

	
		
		
		system("pause");
	}
	void TEST()
	{
		std::locale::global(std::locale(""));

		Book* book = xlCreateBook();

		book->load(L"Voprosy.xls");

		
		

		Sheet* sheet = book->getSheet(0);
		//std::vector<std::wstring> vopr_otv;
		vector <vector <wstring>>  vopr_otv;
		for (int col = 0; col < 1; ++col)
		{
			for (int row_i = 0; row_i < 3; ++row_i)
			{
				const wchar_t* a = sheet->readStr(col, row_i);
				std::wstring wstr(a);
				vopr_otv[col].push_back(wstr);
				std::wcout << wstr << " ";

			}
		}
			
		
		
		
		wchar_t otwet[100];
		std::wcin >> otwet;
		if (otwet == vopr_otv[0][2])
		{
			std::cout << "Привильно";
		}
		book->release();
		system("pause");
	}
};
