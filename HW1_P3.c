#include <stdio.h>
#include <stdlib.h>

/**
 * Define the car struct
 */
typedef struct car
	{
		char make[25]; //An array of chars of max length 25 characters since the name of the brand is a word
		char model[15]; //An array of chars since the model name is a word (can contain numbers)
		char year[5]; //array of chars. Only required to store a 4 numbers (a model year), and not required to be mathmatically editable
		char color[15]; //An array of chars specifying the color since it is a word
	};

/**
 * Prints the sorted records based on car make field
 *  - prints out the car information based on alphabetical order of make
 *
 *@param  n			number of cars in inventory
 *@param  inventory	array of cars
 */
void sort_print_make(struct car inventory[], int n)
{
	struct car temp; //temp holds a car temporarily
	
	for (int i = 0; i < n; i++)
	{
   		for (int j = 0; j < n-1; j++)
		{
    		if (strcmp(inventory[j].make, inventory[j+1].make) > 0)
			{
      			temp = inventory[j];
      			inventory[j] = inventory[j+1];
      	    	inventory[j+1] = temp;
      	   	}
		}
   	}
   	
   	for (int k = 0; k < n; k++)
   	{
   		printf("\nMake: %s, Model: %s, Year: %s, Color: %s", inventory[k].make, inventory[k].model, inventory[k].year, inventory[k].color);
	}
}

/**
 * Prints the sorted records based on car year field
 *  - prints out the car information based on year
 *
 *@param  n			number of cars in inventory
 *@param  inventory	array of cars
 */
void sort_print_year(struct car inventory[], int n)
{
	struct car temp; //temp holds a car temporarily
	
	for (int i = 0; i < n; i++)
	{
   		for (int j = 0; j < n-1; j++)
		{
    		if (strcmp(inventory[j].year, inventory[j+1].year) < 0)
			{
      			temp = inventory[j+1];
      			inventory[j+1] = inventory[j];
      	    	inventory[j] = temp;
      	   	}
		}
   	}
   	
   	for (int k = 0; k < n; k++)
   	{
   		printf("\nMake: %s, Model: %s, Year: %s, Color: %s", inventory[k].make, inventory[k].model, inventory[k].year, inventory[k].color);
	}
}

/**
 * Finds and prints repeats
 *  - Iterates through and compares car data. prints matches
 *
 *@param  n			number of cars in inventory
 *@param  inventory	array of cars
 */
void find_repeats(struct car inventory[], int n)
{
	struct car temp[n]; //temp holds the matching record(s)
	int match_num = 0; //number of matching records
	
	for (int i = 0; i < n; i++)
	{
   		for (int j = i+1; j < n; j++)
		{
    		if (strcmp(inventory[i].make, inventory[j].make) == 0)
			{
      			if (strcmp(inventory[i].model, inventory[j].model) == 0)
      			{
      				if (strcmp(inventory[i].year, inventory[j].year) == 0)
      				{
      					if (strcmp(inventory[i].color, inventory[j].color) == 0)
      					{
      						temp[match_num] = inventory[i];
      						match_num++;
						}
					}
				}
      	   	}
		}
   	}
   	
   	for (int k = 0; k < match_num; k++)
   	{
   		printf("\nMake: %s, Model: %s, Year: %s, Color: %s", inventory[k].make, inventory[k].model, inventory[k].year, inventory[k].color);
	}
}

int main()
{
	
	
	struct car car_inventory[10] = 
	{
		{"Toyota","Camry","2014","Black"},
		{"Porsche","Cayenne","2012","Black"},
		{"Audi","S4","2014","Blue"},
		{"BMW","M3","2009","Green"},
		{"BMW","M3","2009","Green"},
		{"Mercedes-Benz","SLR","2008","Yellow"},
		{"Audi","R8","2011","Pink"},
		{"Porsche","Cayman","2015","Blue"},
		{"Mercedes-Benz","GLK350","2010","Navy"},
		{"Koenigsegg","Agera RS","2007","Purple"}
	};
	
	printf("\nBy Make, A-Z:");
	sort_print_make(car_inventory, 10);
	printf("\nBy Year, Descending:");
	sort_print_year(car_inventory, 10);
	printf("\nRepeated Records:");
	find_repeats(car_inventory, 10);
	
	return 0;
}
