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
	vector  <vector<wstring>>  vopr_otv;
	user()
	{
		std::locale::global(std::locale(""));

		Book* book = xlCreateBook();

		book->load(L"Voprosy.xls");




		Sheet* sheet = book->getSheet(0);
		std::cout << "загружено: столбцы " << sheet->lastCol() << " строки " << sheet->lastRow() << endl;
		

		for (int row_i = 0; row_i < sheet->lastRow(); ++row_i)
		{

			vopr_otv.push_back(vector<wstring>());
			for (int col = 0; col < sheet->lastCol(); ++col)
			{
				if (sheet)
				{
					const wchar_t* a = sheet->readStr(row_i, col);
					std::wstring wstr(a);
					vopr_otv[row_i].push_back(wstr);
				}

			}
		}
		/*for (int col = 0; col < sheet->lastRow(); ++col)
		{

			for (int row_i = 0; row_i < sheet->lastCol(); ++row_i)
			{

				std::wcout << vopr_otv[col][row_i] << " ";




			}
			std::cout << "\n";
		}


		std::cout << "\n\n\n\t\t\t введите ответ:";
		wchar_t otwet[100];
		std::wcin >> otwet;
		if (otwet == vopr_otv[0][2])
		{
			std::cout << "\n\t\t\t Привильно \n";
		}
		else std::cout << "\n\t\t\tНЕ Привильно! \n";
		book->release();
		system("pause");*/
		book->release();
	}
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
		std::vector <int> Bvec;
		srand((unsigned int)time(NULL));
		int SIZEVEC_vopr = vopr_otv.size();
		for (int i = 0; i < 20; i++)
		{

			int a = rand() % (SIZEVEC_vopr - 0);
			
			std::cout << a << " ";
			if (Bvec.empty())
			{
				Bvec.push_back(a);
			}
			
			else
			{
				auto it = find(Bvec.begin(), Bvec.end(), a);
			// Проверяем, найдено ли искомое значение
			
				while (true)
					if (it == Bvec.end())
					{
						Bvec.push_back(a);
						break;
					}
					else
					{
						if (a == SIZEVEC_vopr)
						{
							a = 0;
						}
						else 
						{
							a += 1;
						}
						
						it = find(Bvec.begin(), Bvec.end(), a);
					}
			}

			
			
			//std::cout << "\n\n\n\t\t\t введите ответ:";
		//wchar_t otwet[100];
		/*std::wcin >> otwet;
		if (otwet == vopr_otv[0][2])
		{
			std::cout << "\n\t\t\t Привильно \n";
		}
		else std::cout << "\n\t\t\tНЕ Привильно! \n";
		
		 */
		}
		system("pause");
	}
};
