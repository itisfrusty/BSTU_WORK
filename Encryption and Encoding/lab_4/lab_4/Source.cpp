#include <iostream>
#include <fstream>
#include <string>

void Encode(std::string fileName, int size) {
	unsigned char byte;
	std::ofstream encodedFile("e_" + fileName, std::ios_base::binary);
	std::ifstream dataFile(fileName, std::ios_base::binary);
	for (int i = 0; i < size; i++) {
		dataFile.read((char*)&byte, sizeof byte);
		encodedFile << byte << byte << byte;
	}
	dataFile.close();
	encodedFile.close();
}
void Decode(std::string fileName) {
	unsigned char firstByte, secondByte, thirdByte, byte = 0;
	bool firstBit, secondBit, thirdBit;
	std::ifstream encodedFile(fileName, std::ios_base::binary);
	std::ofstream decodedFile("d_" + fileName, std::ios_base::binary);
	while (!encodedFile.eof()) {
		encodedFile.read((char*)&firstByte, sizeof(firstByte));
		encodedFile.read((char*)&secondByte, sizeof(secondByte));
		encodedFile.read((char*)&thirdByte, sizeof(thirdByte));
		if (encodedFile.eof())
			break;
		if (firstByte == secondByte && secondByte == thirdByte) {
			byte = firstByte;
			decodedFile << byte;
			byte = 0;
		}
		else {
			for (int j = 0; j < 8; j++) {
				firstBit = firstByte & (1 << j);
				secondBit = secondByte & (1 << j);
				thirdBit = thirdByte & (1 << j);
				if (firstBit + secondBit + thirdBit <= 1)
					byte |= (0 << j);
				else
					byte |= (1 << j);
			}
			decodedFile << byte;
			byte = 0;
		}
	}
	encodedFile.close();
	decodedFile.close();
}
int main() {
	int size = 0;
	int key = 0;
	while (key != 3) {
		std::cout << "0 - Encode;\t1 - Decode;\t2 - All;\t3 - Exit" << std::endl;
		std::cin >> key;
		if (key == 3)
			return 0;
		std::string fileName;
		std::cout << "File name: ";
		std::cin >> fileName;
		std::ifstream file(fileName, std::ios_base::binary);
		if (!file.is_open()) {
			std::cout << "File is busy.";
			return 0;
		}
		file.seekg(0, file.end);
		size = file.tellg();
		file.seekg(0, file.beg);
		file.close();
		switch (key) {
		case 0:
			std::cout << "Encode " + fileName << std::endl;
			Encode(fileName, size);
			break;
		case 1:
			std::cout << "Decode " + fileName << std::endl;
			Decode(fileName);
			break;
		case 2:
			std::cout << "Encode " + fileName << std::endl;
			Encode(fileName, size);
			std::cout << "Decode " + fileName << std::endl;
			Decode(fileName);
			break;
		default:
			break;
		};
	}
	return 0;
}