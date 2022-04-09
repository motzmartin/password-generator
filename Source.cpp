#include <iostream>
#include <string>
#include <sodium.h>

#pragma comment(lib, "libsodium.lib")

int main()
{
	if (sodium_init() == -1)
	{
		std::cout << "sodium_init() failed" << std::endl;
		return 1;
	}

	std::string base62 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::string password = "";

	for (int i = 0; i < 20; i++)
	{
		if (i == 6 || i == 13)
		{
			password += "-";
		}
		else
		{
			password += base62[randombytes_uniform(base62.size())];
		}
	}

	char hash[crypto_pwhash_STRBYTES];

	if (crypto_pwhash_str(hash,
		password.c_str(),
		password.size(),
		crypto_pwhash_OPSLIMIT_SENSITIVE,
		crypto_pwhash_MEMLIMIT_SENSITIVE) == -1)
	{
		std::cout << "crypto_pwhash_str() failed" << std::endl;
		return 1;
	}

	std::cout << "password: " << password << std::endl;
	std::cout << "hash: " << hash << std::endl;

	return 0;
}