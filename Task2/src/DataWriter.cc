#include <DataWriter.hh>

std::ofstream OutFile::fout;
void OutFile::Open()
{
 fout.open("info.txt");
}
void OutFile::Close(){fout.close();}
void OutFile::Info(std::string a){fout << a << std::endl;}
