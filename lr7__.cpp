// lr7__.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"konfig.h"
#include <iostream>
#include"fun.h"
#include"String.h"
#include"input_function.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	std::list<supplier> ar;

	int q = 1;
	if (!load(ar)) {
		std::cout << "Вы первый раз зашли в программу, введите поставщиков" << std::endl;
		while (q) {
			supplier x;
			std::cin >> x;
			ar.push_back(x);

			std::cout << "Введите 0 ,чтобы больше никогда не вводить поставщиков" << std::endl;
			q = integer_input();
		}
	}
	do {
		std::cout << "Меню" << std::endl;
		std::cout << "Добавить поставщика 1" << std::endl;
		std::cout << "Найти по имени 2 " << std::endl;
		std::cout << "Вставить в n место списка 3 " << std::endl;
		std::cout << "Удалить  n место списка  4" << std::endl;
		std::cout << "Вывести всех поставщиков 5" << std::endl;
		std::cout << "Cортировка по названию 6" << std::endl;
		std::cout << "Cортировка по салдо 7" << std::endl;


		std::cout << "Выйти из программы 0" << std::endl;
		q = integer_input();

		switch (q)
		{
		case 1: {
			supplier x;
			std::cin >> x;
			ar.push_back(x);
			break;
		}
		case 2:
			print(findByName(ar));
			break;
		case 3:
			print(inputByN(ar));
			break;
		case 4:
			print(deleteByN(ar));
			break;
		case 5:
			print(ar);
			break;
		case 6:
			ar.sort(cmpByName);
			print(ar);
			break;
		case 7:
			ar.sort([](const supplier &l, const supplier &r) {return l.getSaldo() > r.getSaldo(); });
			print(ar);
			break;
	
		}


	} while (q != 0);

	save(ar);
}

