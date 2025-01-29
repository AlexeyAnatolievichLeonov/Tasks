#include <DataWriter2.hh>

std::ofstream OutFile2::fout;
void OutFile2::Open()
{
 fout.open("info2.txt");
}
void OutFile2::Close(){fout.close();}
void OutFile2::Info(std::string a){fout << a << std::endl;}
