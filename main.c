/*
Name:NAYANA M P
Date:18/08/2023
Title:Provide a menu to manipulate or display the value of variable of type t
Sample O/P:Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
-------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 1
Enter the int : 10
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4
*/

#include <stdlib.h>

typedef union                                                                   
{
    int intValue;                                     //declare the variables in structure
    char charValue;
    float floatValue;
    double doubleValue;
} Data;

int main() 
{
    int choice;             
    int count = 0;
    Data *array = (Data *)malloc(8 * sizeof(Data));        

    while (1) {
	printf("Menu:\n");                              //creating the menu
	printf("1. Add element\n");                     //add any elemnts in menu
	printf("2. Remove element\n");                  //remove elements in menu
	printf("3. Display element\n");                 //display any elements in menu
	printf("4. Exit from the program\n\n");          //exit from the program
	printf("Choice ---> ");                          //then ask choice
	scanf("%d", &choice);                            //read the choice

	switch (choice) {                                //switch the choice
	    case 1:
		if (count < 8)                           //count is less than 8
		{
		    int dataType;                           //declare the datatype
		    printf("\nEnter the type you want to insert:\n");      //which type you want to insert 
		    printf("1. int\n");                                      //declare the variables in structure
		    printf("2. char\n");
		    printf("3. float\n");
		    printf("4. double\n\n");
		    printf("Choice ---> ");
		    scanf("%d", &dataType);

		    switch (dataType)                                              //which datatype we select in case
		    {
			case 1:
			    printf("Enter the int: ");                            //enter the int
			    scanf("%d", &(array[count].intValue));                 //read the intvalue
			    break;
			case 2:
			    printf("Enter the char: ");                           //enter the char 
			    scanf(" %c", &(array[count].charValue));              //read the character value
			    break;
			case 3:
			    printf("Enter the float: ");                          //enter the float
			    scanf("%f", &(array[count].floatValue));              //read the float value
			    break;
			case 4:
			    printf("Enter the double: ");                        //enter the double
			    scanf("%lf", &(array[count].doubleValue));           //read the doble value
			    break;
			default:
			    printf("Invalid choice\n");                          //if it is not in the datatype then shows invalid choice
		    }
		    count++;                                                    //then count will be incremented
		} else                                                          //count value be incremented
		{
		    printf("Array is full\n");                                  //then array will be filled
		}
		break;
	    case 2:
		if (count > 0)                                                      //count is greater than 0
		{
		    int index;
		    printf("Enter the index value to be deleted: ");                  //then index value will be deleated
		    scanf("%d", &index);                                                 //read the index

		    if (index >= 0 && index < count) {                         //if the index is greater than or equal 0 and and with index will be less than count
			for (int i = index; i < count - 1; i++)              //itrate the loop upto index to count -1 value
			{
			    array[i] = array[i + 1];                         //array of i is equal to array of i+1 
			}
			count--;                                             //count will bw decremented
			printf("Index %d successfully deleted\n", index);      //index  value will be successfully deleated
		    } else {
			printf("Invalid index\n");                               //otherwise invalid index
		    }
		} else {                                                         //otherwise
		    printf("Array is empty\n");                                    //array is empty
		}
		break;
	    case 3:
		printf("------------------------\n");                              //then print the spaces in new line
		for (int i = 0; i < count; i++)                                     //then iterate the count                                 
		{
		    printf("%d -> ", i);                                              
		    if (sizeof(array[i].intValue) <= 8)                                 //if the size of array is less than or equal to 8
		    {
			printf("%d (int)\n", array[i].intValue);                        //print the intvalue
		    } 
		    else if (sizeof(array[i].charValue) <= 8)                           //if the size of array is less than or equal to 8
		    {
			printf("%c (char)\n", array[i].charValue);                        //print the charvalue
		    } 
		    else if (sizeof(array[i].floatValue) <= 8)                          //if the size of array is less than or equal to 8
		    {
			printf("%f (float)\n", array[i].floatValue);                    //print the float value
		    } 
		    else if (sizeof(array[i].doubleValue) <= 8)                         //if the size of array is less than or equal to 8
		    {
			printf("%lf (double)\n", array[i].doubleValue);                  //print the double value
		    }
		}
		printf("------------------------\n");                                      //print the spaces
		break;
	    case 4:
		free(array);
		return 0;
	    default:
		printf("Invalid choice\n");                                                //then default invalid choice
	}
    }

    return 0;
}
