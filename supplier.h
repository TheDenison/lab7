#pragma once
#include"String.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include"konfig.h"
class supplier
{
	String name;
	String addres;
	double saldo;
public:
	explicit supplier(const char *name = "",const char * addres = "",double saldo = 0);
	explicit supplier(const supplier& input);
	explicit supplier(std::ifstream& os);
	supplier& operator=(const supplier& input);

	void setName(const char* name);
	void setAddres(const char* addres);
	void setSaldo(double saldo);
	char* getName()const ;
	char* getAddres()const;
	double getSaldo()const;
	friend std::istream& operator>>(std::istream &left,supplier& right);
	friend std::ostream& operator<<(std::ostream& left ,const supplier& right);
	void save(std::ofstream& is)const;
	void print()const;
	static void print_header();







};

