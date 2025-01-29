#include <Loader.hh>
#include <DataWriter.hh>
#include <DataWriter2.hh>

int main(int argc, char** argv) 
{
 OutFile::Open(); OutFile2::Open(); 
	
 Loader* loader = new Loader(argc,argv,OutFile::fout,OutFile2::fout);

 delete loader;
	
 OutFile::Close(); OutFile2::Close(); 

//system("pause");
 return 0;
}
