#pragma once
#include<iostream>
#include<iomanip>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <algorithm> // std::swap
#include<fstream>


#define _CRT_SECURE_NO_WARNINGS
class String
{
public:
		//String();
		String(const char* str="");
	    String(size_t n, char c);
	    String(const String& other);
	    String(std::ifstream& is);

		~String();

		String& operator=(const String& other);

		void print(int n = -1);
		char* get_copy_c_string()const;
		void save(std::ofstream& os)const;
		const char* get_const_point_str()const;

		void swap(String& other);
		void append(const String& other);
		int cmp(const String& right)const;
		size_t get_size();
	private:
		size_t size;
		char* str;
};
