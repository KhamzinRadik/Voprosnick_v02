#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string> 
#include <fstream>
#include <sstream>
#include <codecvt>
#include "zapisVfail.h"
#include <Windows.h.>
#include "libxl.h"
#include <corecrt_wstring.h>
#include <iostream>
#include <vector>
#include <ctime>


#include <stdio.h>
#include <conio.h>

using namespace std;
using namespace libxl;



using namespace std;


class user
{
public:
	
	std::string namefile;
	std::string f_name;
	std::string l_name;
	vector  <vector<wstring>>  vopr_otv;
	
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

		namefile = f_name + "_" + l_name +" " + s + ".doc";
		std::ofstream ofs(namefile, std::ios::app);

		if (ofs.is_open())
		{
			ofs <<s<<endl<< f_name << " " << l_name << std::endl << "test result :";
		}

		system("pause");
		system("cls");

		TEST();
	}
	void TEST()
	{
		std::ofstream ofs;
		ofs.open(namefile);
			
		std::vector <int> Bvec;
		srand((unsigned int)time(NULL));
		int SIZEVEC_vopr = 200;
		for (int i = 0; i < 20; i++)
		{

			int a = rand() % (SIZEVEC_vopr - 0);
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

		}

				
		
			std::locale::global(std::locale(""));

			Book* book = xlCreateBook();

			book->load(L"Voprosy.xls");




			Sheet* sheet = book->getSheet(0);
			
			for (int row_i = 0; row_i < 20; ++row_i)
			{

				vopr_otv.push_back(vector<wstring>());
				for (int col = 0; col < 9; ++col) //sheet->lastCol()
				{
					if (sheet)
					{
						const wchar_t* a = sheet->readStr(Bvec[row_i], col);
						std::wstring wstr(a);
						vopr_otv[row_i].push_back(wstr);
					}

				}
			}
			
			for (int col = 1; col < 20; ++col)
			{



				std::cout << "\n " << "Метод:    ";
				std::wcout << vopr_otv[col][1];
				std::cout << " \n Документ: ";
				std::wcout << vopr_otv[col][2] << "\n\n";
				std::cout << " \n\tВопрос : "; 
				std::wcout << vopr_otv[col][3] << "\n\n"
					<< "\t   1 " << vopr_otv[col][4] << "\n"
					<< "\t   2 " << vopr_otv[col][5] << "\n"
					<< "\t   3 " << vopr_otv[col][6] << "\n"
					<< "\t   4 " << vopr_otv[col][7] << "\n";

				//std::wcout << vopr_otv[col][8];//вывод правильного ответа
				
				wchar_t otwet[10];
				while (true)
				{
					
					int c ;
					std::cout << "\n\n\t     введите ответ:";
					std::wcin >> otwet;

					c=_wtoi(otwet);
					if (c >= 1 && c <=4)
					{
						
						break;
					}
					else
					{
						std::cout << "\n\n\t     введите число от 1 до 4х";
						col -= 1;
						break;
					}

				}

				

				
				
				if (otwet == vopr_otv[col][8])
				{
					std::cout << "\n\t\t\t Привильно (нажмите любую клавишу...)\n";


					if (ofs.is_open())
					{
						std::cout << " FILE OPEN";

					}
					else
					{
						std::cout << " NOT OPEN!!!";
					}

					//////////////////////////запись правильного в ворд count+=1
				}
				
				else 
				{
					std::cout << "\n\t\t\tНепривильно! (нажмите любую клавишу...)\n ";
				//////////////////////////запись неправильного в ворд весь вопрос с неправильнфым ответом а затем вывод правильного
					if (ofs.is_open())
					{
						std::cout << " FILE OPEN";

					}
					else
					{
						std::cout << " NOT OPEN!!!";
					}
				}
				
				int getch();
				getch();
				
				system("cls");




			}


			book->release();
		
		system("pause");
	}
};
