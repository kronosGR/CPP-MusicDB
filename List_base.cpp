#include "List_base.h"

using namespace std;
List_base::List_base()
{
    
}

List_base::~List_base()
{
}

/**
 * @brief clear the screen
 */
void List_base::clearScreen(){
    system("clear");
}

/**
 * @brief Read the file from the disk
 * @param filename to read
 * @return the file content to string
 */
vector<string> List_base::readFile(string filename){
    vector<string> content;
    string line;
    ifstream theFile(filename);
    if (theFile.is_open()){
        while(getline(theFile, line )){
            content.push_back(line);
        }
    }
    return content;    
}

/**
 * @brief write the content to the file with the filename given
 * @param filename name of the file
 * @param content vector<string> to be written
 */
void List_base::writeFile(string filename, vector<string> content){
    ofstream theFile;
    theFile.open(filename);
    
    vector<string>::iterator itLine = content.begin();
    while(itLine!= content.end()){
        theFile<< *itLine << endl;
        itLine++;
    }
    theFile.close();
}

/**
 * @brief create a new file
 * @param filename the path for the new file
 */
void List_base::createFile(string filename){
    fstream theFile;
    theFile.open(filename, ios::out);
    theFile.close();
}

/**
 * @brief check if the string is a number
 * @param s the string
 * @return true if a number
 */
bool List_base::isNumber(string s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
