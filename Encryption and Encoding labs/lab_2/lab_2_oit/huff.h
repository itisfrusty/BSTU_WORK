#pragma once
#include "ftable.h"
#include <queue>

class huff
{
protected:
    std::string fileName;
    ftable FTable;
    void saveCode(ftable::ByteStruct* root, std::string huffcod);
    double length();
public:
    huff() { }
    huff(std::string FileName);
    struct HuffmanCode;
    std::vector<HuffmanCode> codes;
    void buildHuffTable();
    void newFile(std::string FileName);
    void writeToFile(std::string FileName);

    ~huff() { }
};

struct huff::HuffmanCode
{
    ftable::ByteStruct byte;
    std::string code;
    HuffmanCode(ftable::ByteStruct Byte, std::string Code) : byte(Byte), code(Code) { }
    HuffmanCode() : byte(ftable::ByteStruct(0, 0)), code("") { }
};

huff::huff(std::string FileName) {
    fileName = FileName;
    FTable = ftable(fileName);
    FTable.buildTable();
}

void huff::saveCode(ftable::ByteStruct* koren, std::string huffcod)
{
    if (!koren)
    {
        return;
    }

    if (koren->byte != 256)
    {
        codes.push_back(HuffmanCode(*koren, huffcod));
    }

    saveCode(koren->lNode, huffcod + "0");
    saveCode(koren->rNode, huffcod + "1");
}

double huff::length()
{
    double length = 0;
    int allRepeats = FTable.Repeats;
    for (int i = 0; i < codes.size(); i++)
    {
        length += codes[i].byte.repeats * codes[i].code.length();
    }
    return length / allRepeats;
}

void huff::buildHuffTable()
{
    ftable::ByteStruct* left, * right, * top;

    std::priority_queue<ftable::ByteStruct*, std::vector<ftable::ByteStruct*>, ftable::ByteCompare> huffDerevo; // Создаем дерево
    for (int i = 0; i < FTable.table.size(); ++i)
        huffDerevo.push(new ftable::ByteStruct(FTable.table[i].byte, FTable.table[i].repeats)); // Заполняем дерево

    while (huffDerevo.size() != 1)
    {
        left = huffDerevo.top(); // Достаем левый лист
        huffDerevo.pop();
        right = huffDerevo.top(); // Достаем правый лист
        huffDerevo.pop();

        top = new ftable::ByteStruct(256, left->repeats + right->repeats);

        top->lNode = left;
        top->rNode = right;

        huffDerevo.push(top); // Добавляем общий
    }
    codes.erase(codes.begin(), codes.end());
    saveCode(huffDerevo.top(), "");
}

void huff::newFile(std::string FileName) {
    fileName = FileName;
    FTable = ftable(fileName);
    FTable.buildTable();
}

void huff::writeToFile(std::string FileName)
{
    std::cout << "Write HAF of " + fileName << std::endl;
    newFile(FileName);
    buildHuffTable();
    std::ofstream outputFile("Algoritm/Haf/" + fileName + ".haf"); // Создаем выходной файл
    outputFile << FTable.Entropy << '\n' << length() << std::endl;
    for (int i = 0; i < codes.size(); i++)
    {
        outputFile << "\n" << codes[i].byte.byte << "\t" << codes[i].code;
    }
    outputFile.close(); // Закрываем файл
}

