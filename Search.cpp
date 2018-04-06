
#include "Person.h"
#include "PersonSort.h"
#include "Search.h"

using namespace std;


bool SequentialSearch(Person folks[], int total, string target, int *position, int *pNumCompares)
{
	*position = -1;
	*pNumCompares = 0;
	bool searchFlag;
	searchFlag = false;
	//start at the first element & check persons for target name
	for (int i=0; i < total; ++i) 
	{
		if (folks[i].GetName() == target) 
		{
			// if == location return;
			*position = i + 1;
			searchFlag = true;
		} 
		if (target > folks[i].GetName()) 
		{
			break;
		}
	}
	return searchFlag;
}

bool BinarySearch(Person folks[], int total, string target, int *position, int *pNumCompares) 
{
	bool binaryFlag = false;
	int upperLimit = 0;
	int lowerLimit = 0;

	//This is the iterative approach
	while (lowerLimit <= upperLimit)
	{
		int midPoint =  (upperLimit + lowerLimit) / 2;

		// Check if x is present at mid
		if (target < folks[midPoint].GetName()) 
		{
			pNumCompares++;
			binaryFlag = true;
			return binaryFlag;
		}

		if (target >folks[midPoint].GetName()) 
		{
			pNumCompares++;
			total = midPoint + 1;
			return true;
		}
			
		 if(target == folks[midPoint].GetName())
		{
			
			target = midPoint - 1;
			return binaryFlag;
		}
	}

	return binaryFlag;
}

//bool RunRecursiveSearch(Person folks[], int total, string target, int *position, int *pNumCompares) 
//{
//	bool bRecursiveFlag = false;
//	int upperLimit = 0;
//	int lowerLimit = 0;
//	//Recursive approach
//	if (lowerLimit >= upperLimit)
//	{
//		//get the mid of the array 
//		int midPoint = (upperLimit + lowerLimit) / 2;
//
//		//Base case
//		if  (target ==folks[midPoint].GetName())
//		{
//			return midPoint;
//		}
//
//		if (target > folks[midPoint].GetName())
//		{
//			return RunRecursiveSearch(folks, total-1/* , midPoint- 1,*/ );
//		}
//		return RunRecursiveSearch(folks, midPoint + 1, /*stuff, stuff*/);
//	}
//	return false;
//}


