#pragma once
#include<list>
#include<fstream>
#include<iostream>
#include"supplier.h"
#include"konfig.h"
#include<iterator>
void print(const std::list<supplier> ar);
void print(std::list<supplier> ar);
void save(const std::list<supplier>& ar);
bool load(std::list<supplier>& ar);

std::list<supplier>& findByName(const std::list<supplier>& ar);
std::list<supplier>& inputByN( std::list<supplier>& ar);
std::list<supplier>& deleteByN(std::list<supplier>& ar);
bool cmpByName(const  supplier& left, const supplier& right);