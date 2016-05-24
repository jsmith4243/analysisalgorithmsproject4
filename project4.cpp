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
	
	
	
	
	

}