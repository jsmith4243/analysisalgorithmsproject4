#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

class City
{

	public:
	
		int cityIdentifier;
	
		int xCoordinate;
		
		int yCoordinate;
		
		int orderVisited;
		
		bool isVisited;
		
		

};

class Edge
{

	public:
	
		City *city1;
		
		City *city2;
		
		int distance;

};

int displayCityVector(std::vector<City*> cityVector)
{

	for (std::vector<City*>::iterator iterator = cityVector.begin(); iterator != cityVector.end(); ++iterator)
	{
	
		std::cout << "cityIdentifier: " << (*iterator)->cityIdentifier << " xCoordinate: " << (*iterator)->xCoordinate << " yCoordinate: " << (*iterator)->yCoordinate << " orderVisited: " << (*iterator)->orderVisited  << std::endl;
		
	
	}

	return 0;

}

//calculates the distances between all cities and puts them in Edge vector
int calculateDistances(std::vector<City*> cityVector, std::vector<Edge*> edgesVector)
{

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
	
	std::vector<Edge*> edgesVector;
	
	calculateDistances(cityVector, edgesVector);
	
	
	clock_t begin = clock();
	
	
	
	
	
	
	
	
	
	
	
	clock_t end = clock();
	
	double timeTaken = double(end - begin) / CLOCKS_PER_SEC;
	
	
	
	
	
	
	
	std::string outputFileName;
	outputFileName = argv[1];
	outputFileName.append(".tour");
	
	std::ofstream outputFile(outputFileName);
	outputFile.close();
	
	
	

}