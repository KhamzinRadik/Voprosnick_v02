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
	//vector  <vector<wstring>>  vopr_otv;
	vector  <vector<string>>  vopr_otv;
	std::string namefile;
	
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
		ofs.close();
		system("pause");
		TEST();
	}
	void TEST()
	{
		
		
		std::vector <int> Bvec;

		srand((unsigned int)time(NULL));
		int SIZEVEC_vopr = 200;
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

				
		
			std::locale::global(std::locale(""));

			Book* book = xlCreateBook();

			book->load(L"Voprosy.xls");




			Sheet* sheet = book->getSheet(0);
			
			for (int row_i = 0; row_i < 20; ++row_i)
			{

				//vopr_otv.push_back(vector<wstring>());
				vopr_otv.push_back(vector<string>());
				for (int col = 0; col < 9; ++col) //sheet->lastCol()
				{
					if (sheet)
					{
						const wchar_t* a = sheet->readStr(Bvec[row_i], col);
						//std::wstring wstr(a);

						/////////////////
						
						wstring wstr =(a);
						size_t len = wcstombs(nullptr, wstr.c_str(), 0) + 1;
						char* buffer = new char[len];
						wcstombs(buffer, wstr.c_str(), len);
						string str(buffer);
						delete[] buffer;
						////////////////
						vopr_otv[row_i].push_back(str);
					}

				}
			}
			std::ofstream  Ofile_questions(namefile, std::ios::app);
			//Ofile_questions.open(namefile, std::ios::app);
			if (Ofile_questions.is_open())
			{
				for (int col = 1; col < 2; ++col)
				{
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

					//std::cout << vopr_otv[col][8];//вывод правильного ответа
				
					//wchar_t otwet[10];
					
							std::cout << "FILE OPEN";
							char otwet[10];
							while (true)
							{


								std::cout << "\n\n\t     введите ответ:";
								std::cin >> otwet;

								if (otwet[0] >= '1' && otwet[0] <= '4')
								{

									//std::wcout << "otwet< " << otwet;
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




								//////////////////////////запись правильного в ворд
							}

							else
							{

								std::cout << "\n\t\t\tНеправильно! (нажмите любую клавишу...)\n ";
								//////////////////////////запись неправильного в ворд
								Ofile_questions.open(namefile, std::ios::app);
								Ofile_questions << "\n\t Вопрос: ";



								Ofile_questions << vopr_otv[col][0] << " " << vopr_otv[col][3] << "\n\n"
									<< "\t   1 " << vopr_otv[col][4] << "\n"
									<< "\t   2 " << vopr_otv[col][5] << "\n"
									<< "\t   3 " << vopr_otv[col][6] << "\n"
									<< "\t   4 " << vopr_otv[col][7] << "\n";


							
								Ofile_questions << "Правильный ответ: "
									<< "\t  " << vopr_otv[col][8]
									<< "Ваш ответ: " << (int)otwet;


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
			Ofile_questions << correct_answers;
			Ofile_questions.close();
			std::cout << "правильных ответов: " << correct_answers<<endl;
		system("pause");
		
	}
	
};
