/**********************************************************************************************
*  COPYRIGHT (C) 2020 John Fahringer (jrf5001@yahoo.com )
*  All rights reserved.
*
*  Derivate Console Calculator
*
*  This Program will take in an input from the user
*  and find the derivative of the whole input.
*
**********************************************************************************************/


#include <fstream>
#include <iostream>
#include <sstream>
#include "../inc/internal/Derivative.h"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

using std::cin;
using std::cout;
using std::endl;


int main()
{
    std::cout << "Current path is " << fs::current_path() << '\n';

    string title;
    std::ifstream titleFile;
    titleFile.open("title.txt");
    title.assign(std::istreambuf_iterator<char>(titleFile), std::istreambuf_iterator<char>()); // read titleFile
    if (titleFile)
        cout << "EXISTS!";
    else
        cout << "NOEXIST!";
    cout << title << endl;

    cout << "Welcome to the Derivative Console Calculator!\n\n"
         << "Please enter a number in the form of a monomial to find the derivative\n"
         << "Follow general mathematical rules when inputing problems.\n"
         << "   ==> Use a single letter (x) as your variable only.\n"
         << "       (Inputing polynomials, logs, functions with 'e'simplifying like-terms not supported currently)\n"
         << "Constants and the rest of the term of a monomial is supported, but the constant goes first. For example:\n"
         << "\t2x\n"
         << "\t3x^2\n"
         << "\tx^2\n"
         << "are all valid monomials for input. \n\nHowever:\n"
		    << "\tx2\n"
		 << "is not.\n\n";
    cout << "Enter your problem into the function statement below: ";
    cout << endl;

    while (cin)
    {
        cout << "\nf(x) = ";
        string s;
        cin >> s;
        Polynomial p(s);
        if (p.getValid()) {
            Derivative d(p);
            if (d.getValid()) {
                cout << "The derivative of " << p << " is :" << endl << d << endl;
            }
            else {
                std::cerr << "Couldn't find derivative: " << endl;
            }
        }
        else {
            cout << "Please try again\n";
        }
    }
    return 0;
}


// Visual Studio:

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
