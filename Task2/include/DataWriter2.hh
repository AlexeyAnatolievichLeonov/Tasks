#ifndef FINAL_DATAWRITER2_HH
#define FINAL_DATAWRITER2_HH

#include <fstream>
#include <iostream>
#include <sstream>

class OutFile2
{
 private:

 public:
    static std::ofstream fout;
    static void Open();
    static void Close();
    static void Info(std::string a);
};
#endif //FINAL_DATAWRITER2_HH
