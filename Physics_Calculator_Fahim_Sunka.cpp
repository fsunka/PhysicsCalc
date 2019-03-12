/* Fahim Sunka 3-11-19 
Unit 1 Assignment - Physics Calculator
Dr. Tyson McMillan Spring 2019 COSC 1437-58000

8. After displaying any results, clear variables and show menu again.

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Input_Validation_Extended.h"
#include "Color_in_CPP.h"

using namespace std;
//test
void callVelocity();
void callAcceleration();
void callMotion();
void callNewton();
void callWeight();
void callMomentum();
void showMenu();

int main()
{	
	cout << fixed << setprecision(4);
	showMenu();
	return 0;
}

void showMenu()
{
	string input = "";
	//Repeat menu until exit condition with do-while loop
	do{
		changeColor(10);
		cout << "Physics Calculator Menu" << endl;
		changeColor(15);
		cout << "\nOPTION \tCALCULATOR" << endl;
		changeColor(11);
		cout << "V\tVelocity" << endl;
		changeColor(14);
		cout << "A\tAcceleration" << endl;
		changeColor(10);
		cout << "M\tMotion" << endl;
		changeColor(9);
		cout << "N\tNewton's 2nd Law" << endl;
		changeColor(13);
		cout << "W\tWeight" << endl;
		changeColor(3);
		cout << "P\tMomentum" << endl;
		changeColor(6);
		cout << "Clear\tClear Screen" << endl;
		changeColor(12);
		cout << "E\tExit Program" << endl;
		changeColor(10);
		cout <<"\n___________________________________\n" << endl;
		cout <<"Please select an option from above: ";
		changeColor(10);
		getline(cin, input);
		changeColor(7); 
		transform(input.begin(), input.end(), input.begin(), ::tolower); //transform input to lowercase prior to testing
		
		if(input == "v")
		{
			callVelocity();
		}
		else if(input == "a")
		{
			callAcceleration();
		}
		else if(input == "m")
		{
			callMotion();
		}
		else if(input == "n")
		{
			callNewton();
		}
		else if(input == "w")
		{
			callWeight();
		}
		else if(input == "p")
		{
			callMomentum();
		}
		else if(input == "exit" || input == "e")
		{
			system("cls");
			changeColor(10);
			cout << "Thanks for trying the calculator, goodbye!" << endl;
			changeColor(7);
		}
		else if(input == "clear" || input == "c")
		{
			system("cls");
		}
		else
		{
			changeColor(12);
			cout << "Invalid entry. Try again.\n" << endl;
			changeColor(7);
		}
	}while(input != "exit" && input!= "e");
}

void callVelocity()
{
	double ds = 0.0, dt = 0.0, velocity = 0.0;
	string dsUnit, dtUnit;
	changeColor(15);
	cout << "\n\nVelocity Calculator" << endl;
	cout << "Enter ds (change in distance): ";
	changeColor(11);
	ds = validateDouble(ds);
	while(ds < 0.0)
	{
		changeColor(12);
		cout << "\nA change in distance can't be negative!" << endl;
		changeColor(15);
		cout << "Enter ds (change in distance): ";
		changeColor(11);
		ds = validateDouble(ds);
	}
	changeColor(15);
	cout << "Enter unit of measure for ds: ";
	changeColor(11);
	getline(cin, dsUnit);
	changeColor(15);
	cout << "Enter dt (change in time): ";
	changeColor(11);
	dt = validateDouble(dt);
	while(dt < 0.0)
	{
		changeColor(12);
		cout << "\nA change in time can't be negative!" << endl;
		changeColor(15);
		cout << "Enter dt (change in time): ";
		changeColor(11);
		dt = validateDouble(dt);
	}
	changeColor(15);
	cout << "Enter unit of measure for dt: ";
	changeColor(11);
	getline(cin, dtUnit);
	changeColor(15);
	velocity = ds / dt;
	cout << "\nVelocity = ds / dt = " << ds << " " << dsUnit << " / " << dt << " " << dtUnit << 
	" = " << velocity << " " << dsUnit << "/" << dtUnit << endl << endl << endl;
}

void callAcceleration()
{
	double dv = 0.0, dt = 0.0, acceleration = 0.0;
	string dvUnit, dtUnit;
	changeColor(15);
	cout << "\n\nAcceleration Calculator" << endl;
	cout << "Enter dv (change in velocity): ";
	changeColor(14);
	dv = validateDouble(dv);
	while(dv < 0.0)
	{
		changeColor(12);
		cout << "\nA change in velocity can't be negative!" << endl;
		changeColor(15);
		cout << "Enter dv (change in velocity): ";
		changeColor(14);
		dv = validateDouble(dv);
	}
	changeColor(15);
	cout << "Enter unit of measure for dv: ";
	changeColor(14);
	getline(cin, dvUnit);
	changeColor(15);
	cout << "Enter dt (change in time): ";
	changeColor(14);
	dt = validateDouble(dt);
	while(dt < 0.0)
	{
		changeColor(12);
		cout << "\nA change in time can't be negative!" << endl;
		changeColor(15);
		cout << "Enter dt (change in time): ";
		changeColor(14);
		dt = validateDouble(dt);
	}
	changeColor(15);
	cout << "Enter unit of measure for dt: ";
	changeColor(14);
	getline(cin, dtUnit);
	changeColor(15);
	acceleration = dv / dt;
	cout << "\nAcceleration = dv / dt = " << dv << " " << dvUnit << " / " << dt << " " << dtUnit << 
	" = " << acceleration << " " << dvUnit << "/" << dtUnit << endl << endl << endl;
}

void callMotion()
{
	double initialVelocity = 0.0, finalVelocity = 0.0, acceleration = 0.0, time = 0.0,
	initialPosition = 0.0, finalPosition = 0.0, avgVelocity = 0.0, velocitySquared = 0.0;
	string option;
	//A menu allowing the user to pick which equation they want to use - repeat menu if invalid option is selected
	do{
		changeColor(15);
		cout << "\n\nMotion Calculator Menu" << endl;
		changeColor(15);
		cout << "\nOPTION \tEQUATION" << endl;
		changeColor(11);
		cout << "MA\tv = vo + at" << endl;
		changeColor(14);
		cout << "MS\ts0 + v0t + 0.5at^2" << endl;
		changeColor(10);
		cout << "MV2\tv^2 = v0^2 + 2a(s - s0)" << endl;
		changeColor(13);
		cout << "MV\tv_avg = 0.5(v + v0)" << endl;
		cout <<"\n___________________________________\n" << endl;
		changeColor(15);
		cout <<"Please select an option from above: ";
		changeColor(10);
		getline(cin, option);
		changeColor(7); 
		transform(option.begin(), option.end(), option.begin(), ::tolower); //transform input to lowercase prior to testing
		if(option == "ma")
		{
			changeColor(15);
			cout << "Enter initial velocity: ";
			changeColor(11);
			initialVelocity = validateDouble(initialVelocity);
			changeColor(15);
			cout << "Enter acceleration: ";
			changeColor(11);
			acceleration = validateDouble(acceleration);
			changeColor(15);
			cout << "Enter time: ";
			changeColor(11);
			time = validateDouble(time);
			while(time < 0.0)
			{
				changeColor(12);
				cout << "\nTime can't be negative!" << endl;
				changeColor(15);
				cout << "Enter time: ";
				changeColor(11);
				time = validateDouble(time);
			}
			changeColor(15);
			finalVelocity = initialVelocity + (acceleration * time);
			cout << "\nFinal Velocity = initial velocity + acceleration * time" << endl 
				 << "= " << initialVelocity << " + " << acceleration << " " << " * " 
				 << time << " = " << finalVelocity << endl << endl << endl;		
		}		
		else if(option == "ms")
		{
			changeColor(15);
			cout << "Enter initial position: ";
			changeColor(14);
			initialPosition = validateDouble(initialPosition);
			changeColor(15);
			cout << "Enter initial velocity: ";
			changeColor(14);
			initialVelocity = validateDouble(initialVelocity);
			changeColor(15);
			cout << "Enter acceleration: ";
			changeColor(14);
			acceleration = validateDouble(acceleration);
			changeColor(15);
			cout << "Enter time: ";
			changeColor(14);
			time = validateDouble(time);
			while(time < 0.0)
			{
				changeColor(12);
				cout << "\nTime can't be negative!" << endl;
				changeColor(15);
				cout << "Enter time: ";
				changeColor(14);
				time = validateDouble(time);
			}
			changeColor(15);
			finalPosition = initialPosition + (initialVelocity * time) + (0.5 * acceleration * time * time);
			cout << "\nFinal Position = initial position + (initial velocity * time) + 0.5(acceleration * time^2)" << endl
				 << "= " << initialPosition << " + (" << initialVelocity << " * " << time << ") + ½(" << acceleration << " * "
				 << time << "^2 = " << finalPosition << endl << endl << endl;		
		}	
		else if(option == "mv2")
		{
			changeColor(15);
			cout << "Enter initial velocity: ";
			changeColor(10);
			initialVelocity = validateDouble(initialVelocity);
			changeColor(15);
			cout << "Enter acceleration: ";
			changeColor(10);
			acceleration = validateDouble(acceleration);
			changeColor(15);
			cout << "Enter initial position: ";
			changeColor(10);
			initialPosition = validateDouble(initialPosition);
			changeColor(15);
			cout << "Enter final position: ";
			changeColor(10);
			finalPosition = validateDouble(finalPosition);
			changeColor(15);
			velocitySquared = (initialVelocity * initialVelocity) + (2.0 * acceleration * (finalPosition - initialPosition));
			cout << "\nFinal Velocity^2 = (initial velocity)^2 + [2 * acceleration * (final position - initial position)]" << endl
				 << "= (" << initialVelocity << ")^2 + [2 * " << acceleration << " * (" << finalPosition << " - " << initialPosition 
				 << ")] = " << velocitySquared << endl << "Final Velocity = " << sqrt(velocitySquared) << endl << endl << endl;;
				
		}
		else if(option == "mv")
		{
			changeColor(15);
			cout << "Enter initial velocity: ";
			changeColor(13);
			initialVelocity = validateDouble(initialVelocity);
			changeColor(15);
			cout << "Enter final velocity: ";
			changeColor(13);
			finalVelocity = validateDouble(finalVelocity);
			changeColor(15);
			avgVelocity = 0.5 * (initialVelocity + finalVelocity);
			cout << "\nAverage Velocity = 0.5 * (initial velocity + final velocity) = 0.5 * (" << initialVelocity << " + " << finalVelocity << ") = "
				 << avgVelocity << endl << endl << endl;	
		}
		else
		{
			changeColor(12);
			cout << "Invalid option. Try again.\n";
			changeColor(15);
		}
	}while(option != "ma" && option != "mv2" && option != "mv" && option != "ms");

}

void callNewton()
{
	double mass = 0.0, acceleration = 0.0, force = 0.0;
	string massUnit, accelerationUnit;
	changeColor(15);
	cout << "\n\nNewton's Second Law Force Calculator" << endl;
	cout << "Enter mass: ";
	changeColor(9);
	mass = validateDouble(mass);
	while(mass < 0.0)
	{
		changeColor(12);
		cout << "\nMass can't be negative!" << endl;
		changeColor(15);
		cout << "Enter mass: ";
		changeColor(9);
		mass = validateDouble(mass);
	}
	changeColor(15);
	cout << "Enter unit of measure for mass: ";
	changeColor(9);
	getline(cin, massUnit);
	changeColor(15);
	cout << "Enter acceleration: ";
	changeColor(9);
	acceleration = validateDouble(acceleration);
	changeColor(15);
	cout << "Enter unit of measure for acceleration: ";
	changeColor(9);
	getline(cin, accelerationUnit);
	changeColor(15);
	force = mass * acceleration;
	cout << "\nForce = mass * acceleration = " << mass << " " << massUnit << " * " << acceleration << " " << accelerationUnit << 
	" = " << force << " " << massUnit << "*" << accelerationUnit << endl << endl << endl;
}

void callWeight()
{
	double mass = 0.0, gravity = 0.0, weight = 0.0;
	string massUnit, gravityUnit;
	changeColor(15);
	cout << "\n\nWeight Calculator" << endl;
	cout << "Enter mass: ";
	changeColor(13);
	mass = validateDouble(mass);
	while(mass < 0.0)
	{
		changeColor(12);
		cout << "\nMass can't be negative!" << endl;
		changeColor(15);
		cout << "Enter mass: ";
		changeColor(13);
		mass = validateDouble(mass);
	}
	changeColor(15);
	cout << "Enter unit of measure for mass: ";
	changeColor(13);
	getline(cin, massUnit);
	changeColor(15);
	cout << "Enter gravity: ";
	changeColor(13);
	gravity = validateDouble(gravity);
	changeColor(15);
	cout << "Enter unit of measure for gravity: ";
	changeColor(13);
	getline(cin, gravityUnit);
	changeColor(15);
	weight = mass * gravity;
	cout << "\nWeight = mass * gravity = " << mass << " " << massUnit << " * " << gravity << " " << gravityUnit << 
	" = " << weight << " " << massUnit << "*" << gravityUnit << endl << endl << endl;
}

void callMomentum()
{
	double mass = 0.0, velocity = 0.0, momentum = 0.0;
	string massUnit, velocityUnit;
	changeColor(15);
	cout << "\n\nMomentum Calculator" << endl;
	cout << "Enter mass: ";
	changeColor(3);
	mass = validateDouble(mass);
	while(mass < 0.0)
	{
		changeColor(12);
		cout << "\nMass can't be negative!" << endl;
		changeColor(15);
		cout << "Enter mass: ";
		changeColor(3);
		mass = validateDouble(mass);
	}
	changeColor(15);
	cout << "Enter unit of measure for mass: ";
	changeColor(3);
	getline(cin, massUnit);
	changeColor(15);
	cout << "Enter velocity: ";
	changeColor(3);
	velocity = validateDouble(velocity);
	changeColor(15);
	cout << "Enter unit of measure for velocity: ";
	changeColor(3);
	getline(cin, velocityUnit);
	changeColor(15);
	momentum = mass * velocity;
	cout << "\nMomentum = mass * velocity = " << mass << " " << massUnit << " * " << velocity << " " << velocityUnit << 
	" = " << momentum << " " << massUnit << "*" << velocityUnit << endl << endl << endl;
}
