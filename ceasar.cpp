
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>

int Index = 65;


std::string decrypt(const std::string &text, int key) {

	std::string to_decypher = text;

	int partial;
	for (int i = 0; i < to_decypher.length(); i++) {
		if (isalpha(to_decypher[i])) { // only decypher alphanumerics
			const char base = isupper(to_decypher[i]) ? 'A' : 'a';
			to_decypher[i] = base + ((to_decypher[i] - base - key + 26) % 26);
		}
	}

	return to_decypher;
}


std::string encrypt(const std::string &text, int key) {

	std::string to_encrypt = text;

	int partial;
	for (int i = 0; i < to_encrypt.length(); i++) {
		if (isalpha(to_encrypt[i])) { // only encrypt alphanumerics
			const char base = isupper(to_encrypt[i]) ? 'A' : 'a';
			to_encrypt[i] = base + ((to_encrypt[i] - base + key) % 26);
		}
	}

	return to_encrypt;
}

int main() {

	const std::string to_decypher = "XRPCTCRGNEI";

	for (int key = 1; key < 26; key++) 
		std:: cout << decrypt(to_decypher, key) << std::endl;

	std::cout << std::endl;

	std:: cout << encrypt(to_decypher, 3) << std::endl;

	return 0;
}

