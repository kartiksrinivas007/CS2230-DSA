#pragma once
#include<iostream>

class datum
{
public:
	std::string username;
	std::string password;
	datum();
	datum(std::string & s1, std::string& s2);
	std::string get_usnm();
	std::string get_psswd();
};
