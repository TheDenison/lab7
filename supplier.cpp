#include "supplier.h"

supplier::supplier(const char* name, const char* addres, double saldo):
    name(name),addres(addres),saldo(saldo)
{
}

supplier::supplier(const supplier& input)
{
    this->addres = input.addres;
    this->name = input.name;
    this->saldo = input.saldo;
    
}

supplier::supplier(std::ifstream& os):
name(os),addres(os)
{
    os >> saldo;
}

supplier& supplier::operator=(const supplier& input)
{
    if (&input != this) {
        this->addres = input.addres;
        this->name = input.name;
        this->saldo = input.saldo;
    }
    return *this;
}

void supplier::setName(const char* name)
{
    this->name = name;
}

void supplier::setAddres(const char* addres)
{
    this->addres = addres;
}

void supplier::setSaldo(double saldo)
{
    this->saldo = saldo;
}

char* supplier::getName() const
{
    return name.get_copy_c_string();
}

char* supplier::getAddres() const
{
    return addres.get_copy_c_string();
}

double supplier::getSaldo() const
{
    return saldo;
}

void supplier::save(std::ofstream& os) const
{
    name.save(os);
    addres.save(os);
    os << " " << saldo << std::endl;

}

void supplier::print() const
{
    std::cout << std::setw(LENGTH_NAME) <<name.get_const_point_str()
        << std::setw(LENGTH_ADDRES) << addres.get_const_point_str()
        << std::setw(LENGTH_SALDO) << saldo << std::endl;
}

void supplier::print_header()
{
    std::cout << std::setw(LENGTH_NAME) << "Наименование"
        << std::setw(LENGTH_ADDRES) << "Адрес"
        << std::setw(LENGTH_SALDO) << "Сальдо" << std::endl;
}

std::istream& operator>>(std::istream& left, supplier& right)
{
    char buf[255];
    std::cout << "Введите название товара:" << std::endl;
    left >> buf;
    right.name = buf;
    std::cout << "Введите адрес:" << std::endl;
    left >> buf;
    right.addres = buf;
    std::cout << "Введите салдо:" << std::endl;
    left >> right.saldo;
    return left;
}

std::ostream& operator<<(std::ostream& left, const supplier& right)
{
    left << std::setw(LENGTH_NAME) << right.name.get_const_point_str() 
        << std::setw(LENGTH_ADDRES) << right.addres.get_const_point_str() 
        << std::setw(LENGTH_SALDO) << right.saldo << std::endl;
    return left;
}
