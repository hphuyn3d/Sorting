/**
 * Hung Huynh
 * 3/8/16
 * Program which asks the user to enter an integer n of any size
 * then will generate n random numbers (between 0 and 99) 
 * and store them in an array. Program uses bubble sort to sort the array
 * After sorting, it will calculate the mean, median and mode. 
 */
 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions
void sort (int *aPtr, int size);
double Getmean(int *aPtr, int size);
double Getmedian(int *aPtr, int size);
int Getmode(int *array, int size);

int main() {
	int size, i, mode;
	double mean,median;

	printf("Please enter an integer n: ");
	scanf("%d", &size);
	int array[size];

	// allocate memory
	int *aPtr = malloc(sizeof(int) * size); 
	printf("The unsorted arrary is: ");
	
	/*Generates an array of random ints*/
	srand(time(NULL));
	for (i = 0; i < size; i++){
		aPtr[i] = rand() % 100;
		printf("%d ", aPtr[i]);
	}
	/*Sorts the array*/
	sort(aPtr,size);
	
	/*Finds the mean*/
	mean = Getmean(aPtr,size);
	printf("\nThe mean is: %.2f", mean);
	
	/*Finds the meadian*/
	median = Getmedian(aPtr,size);
	printf("\nThe median is: %.2f", median); 
	
	/*Finds the mode*/
	mode = Getmode(aPtr,size);				
	if (mode == -1)
	{
		printf("\nThere is no mode\n");
	}
	else
	{
		printf("\nThe mode is: %d\n", mode);
	}

	free(aPtr); 				




}


/*-------------------------------------------------------------*/
/*Bubble Sort*/
void sort (int *aPtr, int size) {
	int temp;
	int i, j;
	printf("\nThe sorted array is: " );
	for(i=0; i<size-1; i++){
		for (j=0; j<size-1-i; j++){
			if (aPtr[j+1] < aPtr[j]) {
				temp = aPtr[j];
				aPtr[j]  = aPtr[j+1]; 
				aPtr[j+1] = temp; 
			}
		}     
	}
	for(i=0;i<size;i++)
		printf("%d ", aPtr[i]);
}

/*-------------------------------------------------------------*/
double Getmean(int *aPtr, int size){
	int i, total=0;
	double mean;
	for( i=0; i < *aPtr; i++)     /* Gets the sum of the array */
	{
		total+=*(aPtr +i);
	}
	mean = (double)total/(double)size;
	return mean;

}


/*-------------------------------------------------------------*/

double Getmedian(int *aPtr, int size){
	int mid;
	double median;
	if ( (size%2 == 0))   /*If it is an even number of ints, then divide between the 2*/
	{                                       
		mid = (size/2) -1;
		median = (aPtr[mid] + aPtr[mid +1])/2;
	}
	else
	{
		mid = size/2;
		median =aPtr[mid];

	}                               
	return median;                                    
}
/*-------------------------------------------------------------*/
int Getmode(int *array, int size){

	int mode = *array;
	int temp, count = 0; 
	int j, i = 0;

	while(i < size){
		j = i + 1;
		temp = 0;

		while(j < size && array[j] == array[i]){ /*Checks the frequency of the int in the array*/
			temp++;
			j++;
			i++;
		}

		if(temp > count){
			mode = array[i];
			count = temp;
		}
		i++;
	}

	if (count == 0)		/*If there is no mode, then set mode to -1*/
	{
		mode = -1;
	}
	return mode; 

}





















