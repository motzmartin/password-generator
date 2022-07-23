#include <sodium.h>
#include <iostream>
#include <string>

int main(void)
{
	if (sodium_init() == -1)
	{
		return 1;
	}

	std::string base62 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::string password;

	for (int i = 0; i < 20; i++)
	{
		if (i == 6 || i == 13)
		{
			password += '-';
		}
		else
		{
			password += base62[randombytes_uniform(base62.size())];
		}
	}

	std::cout << password << std::endl;

	return 0;
}
