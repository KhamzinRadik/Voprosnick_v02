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
	

	std::string f_name;
	std::string l_name;
	int nam_sheet = 0;
	vector  <vector<string>>  vopr_otv;
	std::string namefile;
	int count_questions = 0;
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
			ofs <<s<<endl<< f_name << "\n" << l_name << std::endl << "\nРезультаты теста :\n";
		}
		ofs.close();
		system("pause");






		sheet_list(nam_sheet);

		TEST();
	}

	int sheet_list(int& nam_list)
	{
		int count = 0;
		int getch();
		std::string ukaz[3] = { "=>"," "," " };
		char x;
		int size = ukaz->size() + 1;
		while (true)
		{
			for (int i = 0; i < size; i++)
			{
				if (i == count)ukaz[i] = "=>";
				else ukaz[i] = "  ";
			}
			std::cout << "\n\n\n\n\t\t\t\t" << "Выберете метод контроля для теста\n";
			std::cout << "\t\t\t\t" << ukaz[0] << "ВИК " << std::endl;
			std::cout << "\t\t\t\t" << ukaz[1] << "УЗК " << std::endl;
			std::cout << "\t\t\t\t" << ukaz[2] << "РК " << std::endl;
			x = 0;

			x = getch();

			if (x == 72)
			{
				if (count == 0) count = 2;
				else count -= 1;
			}



			if (x == 80)
			{
				if (count == 2) count = 0;
				else count += 1;
			}
			if (count == 0 && x == '\r')
			{
				system("cls");
				nam_list = 0;
				break;
			}
			if (count == 1 && x == '\r')
			{
				system("cls");

				nam_list = 1;
				break;
			}
			if (count == 2 && x == '\r')
			{
				system("cls");
				nam_list = 2;
				break;
			}
			system("cls");
			
		}
		return nam_list;
	}





	void TEST()
	{
		
		if (nam_sheet == 0)
		{
			std::ofstream  Ofile_questions(namefile, std::ios::app);
			Ofile_questions << "Метод ВИК \n";
			Ofile_questions.close();
		
		}
		if (nam_sheet == 1)
		{
			std::ofstream  Ofile_questions(namefile, std::ios::app);
			Ofile_questions << "Метод УК \n";
			Ofile_questions.close();
			
		}
		if (nam_sheet == 2)
		{
			std::ofstream  Ofile_questions(namefile, std::ios::app);
			Ofile_questions << "Метод РК \n";
			Ofile_questions.close();
			
		}
		




		
		
		
		std::vector <int> Bvec;

		srand((unsigned int)time(NULL));
		std::locale::global(std::locale(""));

		Book* book = xlCreateBook();

		book->load(L"Voprosy.xls");
		Sheet* sheet = book->getSheet(nam_sheet);
		int SIZEVEC_vopr = sheet->lastRow();
		int correct_answers = 0;
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

				
		
			




			
			for (int row_i = 0; row_i < 20; ++row_i)
			{

				
				vopr_otv.push_back(vector<string>());
				for (int col = 0; col < 9; ++col) 
				{
					if (sheet)
					{
						const wchar_t* a = sheet->readStr(Bvec[row_i], col);
						
						
						wstring wstr =(a);//convert wstr to str
						size_t len = wcstombs(nullptr, wstr.c_str(), 0) + 1;
						char* buffer = new char[len];
						wcstombs(buffer, wstr.c_str(), len);
						string str(buffer);
						delete[] buffer;
						
						vopr_otv[row_i].push_back(str);
					}

				}
			}
			std::ofstream  Ofile_questions(namefile, std::ios::app);
			if (Ofile_questions.is_open())
			{
				std::cout << "FILE OPEN";
				for (int col = 0; col <20; ++col)
				{
					count_questions += 1;
					std::cout << "\n Метод" << ":    ";
					std::cout << vopr_otv[col][1] << " \n ";//wcout
					std::cout << "Документ: ";
					std::cout << vopr_otv[col][2] << "\n\n";//wcout
					std::cout << "\t Вопрос: ";

						std::cout << vopr_otv[col][0]<<" "<< vopr_otv[col][3] << "\n\n"//wcout
						<< "\t   1 " << vopr_otv[col][4] << "\n"
						<< "\t   2 " << vopr_otv[col][5] << "\n"
						<< "\t   3 " << vopr_otv[col][6] << "\n"
						<< "\t   4 " << vopr_otv[col][7] << "\n";

					
					
							
							char otwet[10];
							while (true)
							{


								std::cout << "\n\n\t     введите ответ:";
								std::cin >> otwet;

								if (otwet[0] >= '1' && otwet[0] <= '4')
								{

									
									break;

								}
								else
								{
									std::cout << "\n\n\t     введите число от 1 до 4х";

								}

							}






							if (otwet == vopr_otv[col][8])
							{
								std::cout << "\n\t\t\t Правильно (нажмите любую клавишу...)\n";
								correct_answers += 1;

							}

							else
							{

								std::cout << "\n\t\t\tНеправильно! (нажмите любую клавишу...)\n ";
								
								Ofile_questions << "\n\t Вопрос: "



									<<  vopr_otv[col][0] << " " << vopr_otv[col][3] << "\n\n"
									<< "\t   1 " << vopr_otv[col][4] << "\n"
									<< "\t   2 " << vopr_otv[col][5] << "\n"
									<< "\t   3 " << vopr_otv[col][6] << "\n"
									<< "\t   4 " << vopr_otv[col][7] << "\n\n"


							
									<< "Правильный ответ: "
									 << vopr_otv[col][8] << "\t  "
									<< "Ваш ответ: " << otwet<<"\n\n\n";


							}
							int getch();
							getch();

							system("cls");
				}
					
				




			}
			else
			{
				std::cout << "FILE NOT OPEN";
				
			}


			book->release();
			Ofile_questions <<"Всего вопросов: "<<count_questions <<"  правильных ответов : " << correct_answers;
			Ofile_questions.close();
			std::cout << "правильных ответов: " << correct_answers<<endl;
		system("pause");
		
	}
	
};
