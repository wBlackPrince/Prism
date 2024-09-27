#include <vector>
#include <string>

class Options{
};

void pbrtInit(Options options);
void pbrtCleanup();

void pbrtInit(Options options){}
void pbrtCleanup(){};



int main(int argc, char * argv[]){
	Options options;
	std::vector<std::string> filenames;
	
	//TODO Process comand-line arguments

	pbrtInit(options);

	//TODO Process scene-description

	pbrtCleanup();
	return 0;
}