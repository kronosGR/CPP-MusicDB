#ifndef LIST_BASE_H
#define LIST_BASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class List_base
{
public:
    List_base();
    ~List_base();
protected:
    void clearScreen();
    std::vector<std::string> readFile(std::string filename);
    void writeFile(std::string filename, std::vector<std::string> content);
    void createFile(std::string filename);
    bool isNumber(std::string s);
};

#endif // LIST_BASE_H
