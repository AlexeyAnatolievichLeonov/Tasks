#ifndef FINAL_DATAWRITER_HH
#define FINAL_DATAWRITER_HH

#include <fstream>
#include <iostream>
#include <sstream>

class OutFile{
private:

public:
    static std::ofstream fout;
    static void Open();
    static void Close();
    static void Info(std::string a);
};
#endif //FINAL_DATAWRITER_HH
