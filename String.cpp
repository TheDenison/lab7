#include "String.h"


//using namespace ilau;
/*
 String::String()
{
    char buf[255];
    std::cout << "asdf";
    std::cin >> buf;
    size = strlen(buf);
    str = strcpy(new char[strlen(str) + 1], str);
}
*/
String::String(const char* str): size(strlen(str)), str(strcpy(new char[strlen(str) + 1], str))
{}
String::String(size_t n, char c) :
    size(n)
{
    this->str = new char[n + 1];
    for (int i = 0; i < n; ++i)
    {
        this->str[i] = c;
    };
    this->str[n] = '\0';
}


String::String(const String& other) :size(other.size), str(new char[size + 1])
{
    strcpy(this->str, other.str);
}
String::String(std::ifstream& is)
{
    is >> this->size;
    str = new char[size + 1];
    for (int i = 0; i <= size; i++)
        is >> str[i];
}

String::~String()
{
    delete[] str;
}

 String&  String::operator=(const String& other)
{
    String tmp(other);
    this->swap(tmp);
    return *this;
}

void  String::print(int n)
{
    if (n == -1) {
        std::cout << str;
    }
    else {
        std::cout << std::setw(n);
    }
}

char*  String::get_copy_c_string() const
{
    char* out = new char[size + 1];
    for (int i = 0; i <= size; i++) {
        out[i] = str[i];
    }
    return out;
}

void  String::save(std::ofstream& os)const
{

    os << size << " ";
    for (int i = 0; i <= size; i++) {
        os << str[i];
    }
}

const char*  String::get_const_point_str() const
{
    return str;
}

void  String::swap(String& other)
{
    std::swap(this->size, other.size);
    std::swap(this->str, other.str);
}


void  String::append(const String& other)
{
    char* buf = this->str;
    this->str = new char[this->size + other.size + 1];
    for (int j = 0; (this->size) > j; ++j) this->str[j] = buf[j];
    delete[] buf;
    for (int j = 0; other.size > j; ++j) this->str[j + this->size] = other.str[j];
    this->str[this->size + other.size] = '\0';
    this->size = this->size + other.size;
}

int  String::cmp(const String& right) const
{

    return strcmp(this->str, right.get_const_point_str());
}

size_t  String::get_size()
{
    return this->size;
}

