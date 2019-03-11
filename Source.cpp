#include<iostream>
#include <stdlib.h>   
#include <time.h>   
using namespace std;


void input(char * str1, char * str2, char * str3)     //takes input
{
	cout << "NOTE : string 3 should be larger " << endl;

	cout << "enter string 1 : ";
	cin >> str1;

	cout << "enter string 2 : ";
	cin >> str2;

	cout << "enter string 3 : ";
	cin >> str3;



}

char * getDistinctCharacters(char * str1, char * str2, char * str3)  //get distinct characters from the strings and place the in an array
{
	char * result = new char[10];
	bool check = true;
	int index = 0;
	for (int i = 0; i < 10; i++)
	{
		result[i] = NULL;
	}
	
	for (int i = 0; i < strlen(str1); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (result[j] == str1[i])
			{
				check = false;
			}
		}
		if (check == true)
		{
			result[index] = str1[i];
			index++;
	
		}
		check = true;
	
	}
	check = true;

	for (int i = 0; i < strlen(str2); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (result[j] == str2[i])
			{
				check = false;
			}
		}
		if (check == true)
		{
			result[index] = str2[i];
			index++;
		}
		check = true;
		
	}
	check = true;

	for (int i = 0; i < strlen(str3); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (result[j] == str3[i])
			{
				check = false;
			}
		}
		if (check == true)
		{
			result[index] = str3[i];
			index++;
		}
		check = true;
		
	}
	return result;
}

void Print(char * generation)  // for printing array
{
	for (int i = 0; i < 10; i++)
	{
		cout << generation[i] << "->" << i << endl;
	}
}

int getIndex(char * generation, char  c)   // returns index of a character
{
	int x=-1;
	for (int i = 0; i < 10; i++)
	{
		if (generation[i] == c)
		{
			x = i;
			break;
			
		}
	}
	return x;
}
void generateNumberAgainstString(int &n1, int &n2, int &n3, char * str1, char *str2, char * str3, char * generation) // compute number against each string 
{
	char * n11 = new char[strlen(str1)];
	int g=0;
	int ind = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		n11[i] = -1;
	}
	for (int i = strlen(str1)-1; i>=0 ; i--)
	{
		int t = getIndex(generation, str1[ind]);
		int f = t*pow(10, i);
		g = g + f;
		ind++;
	}
	n1=g;
	ind = 0;
	g = 0;
	for (int i = strlen(str2) - 1; i >= 0; i--)
	{
		int t1 = getIndex(generation, str2[ind]);
		int f1 = t1*pow(10, i);
		g = g + f1;
		ind++;
	}
	n2 = g;
	ind = 0;
	g = 0;
	for (int i = strlen(str3) - 1; i >= 0; i--)
	{
		int t3 = getIndex(generation, str3[ind]);
		int f3 = t3*pow(10, i);
		g = g + f3;
		ind++;
	}
	n3 = g;
}
int Error(int n1, int n2, int n3)   // computes the error in current generation
{
	return (n1 + n2) - n3;
}
void nextGeneration(char * generation)  // generates two random numbers(x,y) several times and swaps that (xth and yth) index thus producing a next generation
{
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 10;
		int y = rand() % 10;
		swap(generation[x], generation[y]);
	}
}
int main()
{
	char * str1 = new char[10];
	char * str2 = new char[10];
	char * str3 = new char[10];
	char * generation = new char[10];
	char * newGeneration = new char[10];
	int n1, n2, n3;
	int itr = 1;
	int error = -1;
	int u = 0;
	input(str1, str2, str3);

	generation = getDistinctCharacters(str1, str2, str3);
	while (error!=0)
	{
		cout << endl << "----------------- iteration : " << itr << "-----------------------";

		cout << endl << " Generation number : "<<itr<<endl<<endl;
		Print(generation);
		
		generateNumberAgainstString(n1, n2, n3, str1, str2, str3, generation);
		error = Error(n1, n2, n3);
		cout << endl << "current values : " << endl<<endl;
		cout << endl << "String 1 : " << str1 << "-->" << n1;
		cout << endl << "String 2 : " << str2 << "-->" << n2;
		cout << endl << "String 3 : " << str3 << "-->" << n3<<endl;
		cout <<endl<< "Error : "<<error<<endl;
		itr++;
		nextGeneration(generation);
	}
	system("pause");
	
}