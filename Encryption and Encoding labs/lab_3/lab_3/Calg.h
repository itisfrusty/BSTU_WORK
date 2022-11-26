#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef _CALG_H_

#define _CALG_H_

#include "freqtable.h"

#include <map>

class calg

{

protected:

	std::string fileName;

	freqtable ftable;

public:

	calg() { }

	calg(std::string _fileName);

	struct ByteAndCode;

	std::vector<ByteAndCode> codes;

	void update(std::string _fileName);

	std::string getCodeOfByte(int _byte);

	int FileSize;

	virtual void calculate() = 0;

	virtual void write() = 0;

	virtual void readFreqTable() = 0;

	virtual ~calg() { };

};

calg::calg(std::string _fileName)

{

	fileName = _fileName;

	ftable = freqtable(_fileName);

}

struct calg::ByteAndCode

{

	freqtable::ByteRepeats byte;

	std::string code;

	ByteAndCode() : byte(freqtable::ByteRepeats(0, 0)), code((std::string)"") { }

	ByteAndCode(freqtable::ByteRepeats _b, std::string _c) : byte(_b), code(_c) { }

};

std::string calg::getCodeOfByte(int _byte)

{

	for (std::vector<ByteAndCode>::iterator bac = codes.begin(); bac != codes.end(); bac++)

	{

		if (bac->byte.byte == _byte)

		{

			//std::cout << "Search byte:\t" << _byte << "\nFound byte:\t" << bac->byte.byte << "\tCode:\t" << bac->code << std::endl;

			return bac->code;

		}

	}

	return "";

}

void calg::update(std::string _fileName)

{

	fileName = _fileName;

	ftable = freqtable(_fileName);

	ftable.calculate();

}

#endif
