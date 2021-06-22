#include "fun.h"

void print(const std::list<supplier> ar)
{
	supplier::print_header();
	for (auto& it : ar)std::cout<< it;
}

void save(const std::list<supplier>& ar)
{
	std::ofstream ofs(FILE_NAME);
	ofs << ar.size() << std::endl;
	for (auto& it : ar) it.save(ofs);
	//std::copy(ar.begin(), ar.end(), std::ostream_iterator<Bank>(ofs));
	ofs.close();
}

bool load(std::list<supplier>& ar)
{

	std::ifstream ifs(FILE_NAME);
	supplier x;
	bool result;
	if (result = ifs.is_open()) {
		int n;
		ifs >> n;
		for (int i = 0; i < n; i++)
		{
			x = supplier(ifs);
			ar.push_back(x);
		}
	}
	//std::copy(std::istream_iterator<Bank>(ofs), std::istream_iterator<Bank>(), back_inserter(ar));
	ifs.close();
	return result;
	
}

std::list<supplier>& findByName(const std::list<supplier>& ar)
{
	char buf[255];
	std::cout << "Введите название товара:" << std::endl;
	std::cin >> buf;
	std::list<supplier>* out = new std::list<supplier>();
	for (auto& it : ar) {
		if (strcmp(it.getName(), buf) == 0) {
			(*out).push_back(it);
		}
	}
	return *out;
}


std::list<supplier>& inputByN( std::list<supplier>& ar)
{
	std::cout << "введите номер элемнта для вставки:" << std::endl;
	int k;
	std::cin >> k;
	std::cout << "введите поставщика" << std::endl;
	supplier buf;
	std::cin >> buf;
	auto it = ar.begin();
	int i = 0;
	while (i <= k)
	{
		if (i == k)
		{
			ar.insert(it, buf);
		}
		it++;
		i++;
	}
	return ar;
}

std::list<supplier>& deleteByN(std::list<supplier>& ar)
{
	std::cout << "введите номер элемента для удаления:" << std::endl;
	int k;
	std::cin >> k;
	int i = 0;
	auto it = ar.begin();
	while (i <= k)
	{
		if (i == k)
		{
			ar.erase(it);
		}
		it++;
		i++;
	}
	return ar;
}


bool cmpByName(const supplier& left, const supplier& right)
{

	return strcmp(left.getName(),right.getName())<0;
}
