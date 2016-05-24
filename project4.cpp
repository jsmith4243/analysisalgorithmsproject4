#include <iostream>
#include <fstream>



int main(int argc, char** argv)
{

	std::cout << argv[1] << std::endl;

	std::ifstream inputFile(argv[1]);
	//std::ifstream inputFile("inputFile");
	
	int cityIdentifier, xCoordinate, yCoordinate;
	
	while (inputFile >> cityIdentifier >> xCoordinate >> yCoordinate)
	{
	
		std::cout << cityIdentifier << " " << xCoordinate << " " << yCoordinate;
	
	}
	
	inputFile.close();
	
	std::string outputFileName;
	outputFileName = argv[1];
	outputFileName.append(".tour");
	
	std::ofstream outputFile(outputFileName);
	outputFile.close();
	
	
	

}