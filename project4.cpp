#include <iostream>
#include <fstream>
#include <vector>

class City
{

	public:
	
		int cityIdentifier;
	
		int xCoordinate;
		
		int yCoordinate;
		
		int orderVisited;
		
		bool isVisited;
		
		

};

int displayCityVector(std::vector<City*> cityVector)
{

	for (std::vector<City*>::iterator iterator = cityVector.begin(); iterator != cityVector.end(); ++iterator)
	{
	
		std::cout << "cityIdentifier: " << (*iterator)->cityIdentifier << " xCoordinate: " << (*iterator)->xCoordinate << " yCoordinate: " << (*iterator)->yCoordinate << " orderVisited: " << (*iterator)->orderVisited  << std::endl;
		
	
	}

	return 0;

}

int main(int argc, char** argv)
{

	std::cout << argv[1] << std::endl;

	std::ifstream inputFile(argv[1]);
	//std::ifstream inputFile("inputFile");
	
	int cityIdentifier, xCoordinate, yCoordinate;
	
	std::vector<City*> cityVector;
	
	City *currentCity;
	
	while (inputFile >> cityIdentifier >> xCoordinate >> yCoordinate)
	{
	
		currentCity = new City;
		
		currentCity->cityIdentifier = cityIdentifier;
		currentCity->xCoordinate = xCoordinate;
		currentCity->yCoordinate = yCoordinate;
		
		cityVector.push_back(currentCity);
		
	
		//std::cout << cityIdentifier << " " << xCoordinate << " " << yCoordinate;
		
		
		
	
	}
	
	inputFile.close();
	
	displayCityVector(cityVector);
	
	
	
	
	
	
	
	
	
	
	std::string outputFileName;
	outputFileName = argv[1];
	outputFileName.append(".tour");
	
	std::ofstream outputFile(outputFileName);
	outputFile.close();
	
	
	

}