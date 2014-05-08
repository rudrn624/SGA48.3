#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	/*
	#
	##
	###
	####
	#####
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << '#';
		}
		cout << endl;
	}
	/*
	#####
	####
	###
	##
	#
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5-i; j++)
		{
			cout << '#';
		}
		cout << endl;
	}
	/*
	    #
	   ##
	  ###
	 ####
	#####
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4-i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < i+1; j++)
		{
			cout << '#';
		}
		cout << endl;
	}
	/*
	#####
	 ####
	  ###
	   ##
	    #
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 5-i; j++)
		{
			cout << '#';
		}
		cout << endl;
	}

	_getch();
	return 0;
}
