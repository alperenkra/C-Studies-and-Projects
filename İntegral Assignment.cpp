//*************************************************************************************
//******                        STUDENT NAME: ALPEREN KARA                       ******
//******                        STUDENT NUMBER: B221202057                       ******
//******                            ASSIGNMENT # : 1                             ******
//******                              -HONOR CODE-                               ******
//*************************************************************************************

#include <iostream> // Add the 'iostream' library for getting inputs and printing the outputs.
#include<iomanip> // Add the 'iomanip' library for 'setw()' functions that enables us to proper and shapely outputs.

using namespace std; // Through this line, there is no need to write'std :: '


int main() // We need a main function to do our operations.
{
    float a, b; // Declare the [a,b] interval values.
    float n; // Declare the number of interval.


    // Get inputs from user for [a,b] and 'n' the number of intervals
    cout << "a  : "; cin >> a; cout << endl;
    cout << "b  : "; cin >> b; cout << endl;
    cout << "n  : "; cin >> n; cout << endl;


    // Declare and initialize sums of the functions
    float leftHandSum = 0, rightHandSum = 0, midPointSum = 0;

    // Declare and initialize Left hand, right hand and midpoint functions.
    float LHF = 0, RHF = 0, MF = 0;


    // Calcute delta_x from the inputs.
    float delta_x = (b - a) / n;

    float X_i = 0;
    float epsilon_i = 0;
    float Fx_i = 0;


    // Decorate the output screen for a shapely output.
    cout << "-------------------------------------------------------------------" << endl;

    // Writing the variable headings for lining up the outputs
    cout << setw(5) << "i" << setw(12) << "x[i]" << setw(15) << "epsilon[i]" << setw(10) << "LHF" << setw(10) << "RHF" << setw(12) << "MF" << endl;

    // Decorate the output screen for a shapely output.
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 1; i < n + 1; i++)//We need a for loop to calculate the equations and print values at every step.
    {
        X_i = a + (i - 1) * delta_x; // Calculate X[i] values 

        epsilon_i = X_i + (delta_x / 2); //Add to X[i] the half of deltaX and find the midpoints (epsilon[i]).

        LHF = delta_x * (pow(X_i, 3) + X_i * 4); // Calculate values according to Left Hand Rule
        RHF = delta_x * (pow(X_i + delta_x, 3) + (X_i + delta_x) * 4);// Calculate values according to Right Hand Rule
        MF = delta_x * (pow(epsilon_i, 3) + epsilon_i * 4);// Calculate values according to Midpoint Rule

        // Add every value to the sum to find the results(totals) according to the rule equations.
        leftHandSum += LHF;
        rightHandSum += RHF;
        midPointSum += MF;

        //Print the results in columns for regular output.
        cout << setw(5) << i << setw(10) << X_i << setw(15) << epsilon_i << setw(10)
            << setprecision(6) << LHF << setw(13) << setprecision(6) << RHF << setw(14) << setprecision(6) << MF << endl;


    }
    // Regulate the output screen and print the total results that were calculated according to the rules.
    cout << "-----------------------------------------" << endl;
    cout << "-----------INTEGRAL RESULTS------------" << endl;
    cout << "f(x)=x^3 + 4x from [" << a << "," << b << "] with " << n << " intervals" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "MIDPOINT RULE         : " << midPointSum << endl;
    cout << "LEFT HAND RULE        : " << leftHandSum << endl;
    cout << "RIGHT HAND RULE       : " << rightHandSum << endl;
    //I tried to explain the code I wrote as much as I could.
    //I hope my code is correct and my explanations are sufficient. I wish you a good day :).
}
