#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <math.h>

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

int greedyTour(std::vector<City*> &cityVector, std::vector<Edge*> &edgesVector)
{

	int lengthOfTour = 0;
	
	Edge *currentEdge;
	City* currentCity;
	
	
	
	int numberOfCities;
	numberOfCities = cityVector.size();
	
	int startingCityPos;
	std::vector<City*>::iterator startingCity;
	startingCity = cityVector.begin();
	startingCityPos = (rand() % numberOfCities); 
	for (int i = 0; i < startingCityPos; i++)
	{
		startingCity++;
	}

	int orderVisited = 1;
	
	currentCity = *startingCity;
	currentCity->orderVisited = orderVisited;
	currentCity->isVisited = true;
	
	
	int smallestDistance = INT_MAX;
	Edge *smallestEdge;
	
	int numberOfCitiesVisited = 0;
	
	
	while (numberOfCitiesVisited < numberOfCities)
	{
	
		for(std::vector<Edge*>::iterator iterator = edgesVector.begin(); iterator != edgesVector.end(); ++iterator)
		{
	
			if ((*iterator)->city1 == currentCity)
			{
		
				if ((*iterator)->city2->isVisited == false)
				{
			
					if ((*iterator)->distance < smallestDistance)
					{
				
						smallestEdge = *iterator;
				
					}
				
			
				}
			
		
			}
		
	
	
		}
		
		currentCity = smallestEdge->city2;
		
		currentCity->orderVisited = orderVisited;
		orderVisited++;
		currentCity->isVisited = true;
		lengthOfTour += smallestEdge->distance;
		numberOfCitiesVisited++;
		
	}
	
	
	
	return lengthOfTour;

}

int displayCityVector(std::vector<City*> cityVector)
{

	for (std::vector<City*>::iterator iterator = cityVector.begin(); iterator != cityVector.end(); ++iterator)
	{
	
		std::cout << "cityIdentifier: " << (*iterator)->cityIdentifier << " xCoordinate: " << (*iterator)->xCoordinate << " yCoordinate: " << (*iterator)->yCoordinate << " orderVisited: " << (*iterator)->orderVisited  << std::endl;
		
	
	}

	return 0;

}


int displayEdgesVector(std::vector<Edge*> edgesVector)
{

	std::cout << "edgesVector: " << std::endl;

	for (std::vector<Edge*>::iterator iterator = edgesVector.begin(); iterator != edgesVector.end(); ++iterator)
	{
	
		std::cout << "city1: " << (*iterator)->city1 << " city2: " << (*iterator)->city2 << " distance: " << (*iterator)->distance   << std::endl;
		
	
	}

	return 0;

}

//calculates the distances between all cities and puts them in Edge vector
int calculateDistances(std::vector<City*> &cityVector, std::vector<Edge*> &edgesVector)
{




	for (std::vector<City*>::iterator iterator1 = cityVector.begin(); iterator1 != cityVector.end(); ++iterator1)
	{
	
		for (std::vector<City*>::iterator iterator2 = cityVector.begin(); iterator2 != cityVector.end(); ++iterator2)
		{
		
		
		
			int x1;
			int x2;
			int y1;
			int y2;
			
			int distance;
			
			
			
			x1 = (*iterator1)->xCoordinate;
			x2 = (*iterator2)->xCoordinate;
			y1 = (*iterator1)->yCoordinate;
			y2 = (*iterator2)->yCoordinate;
			
			distance = floor( sqrt( (x1 - x2)^2 + ( y1 - y2)^2 ) );
			
			/*
			std::cout << "x1 is : " << x1 << std::endl;
			std::cout << "x2 is : " << x2 << std::endl;
			std::cout << "y1 is : " << y1 << std::endl;
			std::cout << "y2 is : " << y2 << std::endl;
			std::cout << "distance is : " << distance << std::endl;
			//std::cout << "equation is: " << (x1 - x2)^2 + ( y1 - y2)^2 << std::endl;
			*/
			
			Edge *currentEdge = new Edge();
			currentEdge->city1 = *iterator1;
			currentEdge->city2 = *iterator2;
			currentEdge->distance = distance;
			
			if (*iterator1 != *iterator2)
			{
				edgesVector.push_back(currentEdge);
			}

		}
	
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
		currentCity->orderVisited = 0;
		
		cityVector.push_back(currentCity);
		
	
		//std::cout << cityIdentifier << " " << xCoordinate << " " << yCoordinate;
		
		
		
	
	}
	
	inputFile.close();
	
	
	
	std::vector<Edge*> edgesVector;
	
	calculateDistances(cityVector, edgesVector);
	
	displayEdgesVector(edgesVector);
	
	int lengthOfTour = 0;
	
	
	clock_t begin = clock();
	
	
	
	
	lengthOfTour = greedyTour(cityVector, edgesVector);
	
	displayCityVector(cityVector);
	
	
	
	
	clock_t end = clock();
	
	double timeTaken = double(end - begin) / CLOCKS_PER_SEC;
	
	
	
	
	
	
	
	std::string outputFileName;
	outputFileName = argv[1];
	outputFileName.append(".tour");
	std::ofstream outputFile(outputFileName);
	
	outputFile << lengthOfTour << std::endl;
	for (std::vector<City*>::iterator iterator = cityVector.begin(); iterator != cityVector.end(); ++iterator)
	{
	
		outputFile << (*iterator)->cityIdentifier << std::endl;
		
	
	}
	
	
	outputFile.close();
	
	
	

}