#include"data.h"
#include<iostream>


datum::datum()
{
	username = "";
	password = "";
}
datum::datum(std::string& s1, std::string& s2)
{
	username = s1;
	password = s2;
}
std::string datum::get_psswd()
{
	return password;
}
std::string datum::get_usnm()
{
	return username;
}
