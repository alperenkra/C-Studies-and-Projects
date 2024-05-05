// *********************************************************************************************
// ******                      STUDENT NAME: ALPEREN KARA                                *******
// *****                     STUDENT NUMBER: B221202057                                   ******
// *****                      ASSIGNMENT # : 2                                            ******
// *****  - I wrote my code entirely by myself and I feel proud of myself as I realize  - ******
// *****                - the skills that i have learned in this project -                ******
// *********************************************************************************************

#include <iostream> // Library for input and output operations
#include <ctime> // I add this library for generating random sizes and numbers of matrices.
#include <cmath> // I add this library for pow function.
#include <iomanip>// I add this library for the setw function that enables us to design outputs
#include <fstream> // I add this library for file operations
#include <string>// I add this library for controlling strings

using namespace std;// Thanks to this command, there is no need to type std::

// I declate the functions at the beginning of the code to make it look proper
int** createMatrix(int);
int** generateMatrix(string, int);
int** CalcOutputMatrix(int**, int**, int, int);
void printMatrix(string, int**, int);
void deleteMatrix(int**, int);

// I also declare the choice functions
void firstOption();
void secondOption();

// My main function
int main()
{
    srand(time(NULL));//In order not to get the same numbers every time, we are setting "srand" to "null"

    
    int selection; // I define the option variable that presents the users choice
    system("cls"); // Clearing the output screen

    // I explain the situation to the user and ask them to make a choice
    cout << "Please choose your calculating type:" << endl << "1 - Generate new matrixes" << endl << "2 - Read matrixes from existing file" << endl;
    cout << "Your Choice: ";
    cin >> selection; // Putting the selection from the user into the variable

    // There is switch-case for choosing the alternatives according to user's selection 
    switch (selection)
    {
    case 1:
        system("cls");// Clearing the output screen
        firstOption();// If users select 1, the program runs the predefined "firstOption()" function to execute the request
        break;
    case 2:
        system("cls");// Clearing the output screen
        secondOption();// If users select 2, the program runs the predefined "secondOption()" function to execute the request
        break;
    default:
        system("exit");// Finish the program
        cout << "INVALID ENTRY";
        break;
    }
}

// Function for creating dynamic matrix
int** createMatrix(int size)
{
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    return matrix;

}

// Function that assigns random numbers to input and core matrixes and writes the matrixes to the 'data.txt' file
int** generateMatrix(string matrixtype, int matrixSize)
{
    if (matrixtype == "INPUT")// Determine matrix type
    {
        int** inputMatrix = createMatrix(matrixSize); // Creating the dynamic matrix by using the function
        ofstream writeData("data.txt", ios::out); // Creating the file stream 
        writeData << "INPUT MATRIX" << endl; // Writing the type of the matrix 

        // Defining random numbers into matrices and writing them into the file
        for (int i = 0; i < matrixSize; i++)
        {
            for (int j = 0; j < matrixSize; j++)
            {
                inputMatrix[i][j] = rand() % 11 + 10; // Defining random numbers into Input Matrix
                writeData << setw(4) << inputMatrix[i][j];// I use setw function for the more proper matrix view
            }
            writeData << endl;
        }
        return inputMatrix; // Returning the matrix
    }

    // The same operations goes with Core Matrix here
    else if (matrixtype == "CORE")
    {
        int** coreMatrix = createMatrix(matrixSize);
        ofstream writeData("data.txt", ios::app);
        writeData << "CORE MATRIX" << endl;

        for (int i = 0; i < matrixSize; i++)
        {
            for (int j = 0; j < matrixSize; j++)
            {
                coreMatrix[i][j] = rand() % 10 + 1;
                writeData << setw(4) << coreMatrix[i][j];
            }
            writeData << endl;
        }
        return coreMatrix;
    }
}

// Function that calculates the output matrix
int** CalcOutputMatrix(int** inputMatrix, int** coreMatrix, int inputMatrixSize, int coreMatrixSize)
{
    int** outputMatrix = createMatrix(inputMatrixSize - coreMatrixSize + 1);// Creating the outputmatrix with dynamic array creating function

    int total = 0; // Declaring the sum of the special operation

    for (int i = 0; i < inputMatrixSize - coreMatrixSize + 1; i++)
    {// With these two for loops, we enter the output matrix into which we will write the results. In this way, when each value is written
     //into it, it will move to the next outputmatrix element and thus the matrix will be completed with the calculated results.
        for (int j = 0; j < inputMatrixSize - coreMatrixSize + 1; j++)
        {
            // Since each calculated output matrix element will assigned a new value when
            // moving to the next one, we reset it so that it is not added to the already calculated total.
            total = 0; 
            for (int k = 0; k < coreMatrixSize; k++)//With these two for loops, we move to the next element in the core matrix that we will perform the operation on.
            {                                           // (In the special operation, there will be a progression from the end to the beginning, I set this where I perform the total operation, I will explain it in that line)
                for (int l = 0; l < coreMatrixSize; l++)
                {
                    // After each calculation in the input matrix, we take 'i' and 'j' values to move on to the next one and add them with core matrix size to go to the last element.
                    // Then we subtract the increasing variables 'k' and 'l' to move from the end to the beginning.
                    // After these operations, we subtract '1' because the size becomes one more and overflows.
                    // And inside the core matrix we are moving to the next element with the variables 'k' and 'l' .
                    // And then we do the multiplication.
                    // Then we add result that we found to the total each time.
                    total += inputMatrix[i + coreMatrixSize - k - 1][j + coreMatrixSize - l - 1] * coreMatrix[k][l];
                }
            }
            outputMatrix[i][j] = total / (pow(coreMatrixSize, 2));// Here we divide the total calculated for each element of the output matrix by the number of elements of the core matrix and place it in output matrix
        }
    }
    return outputMatrix;// I return my outputmatrix
}

// Function to print matrices according to their size and type
void printMatrix(string matrixtype, int** matrix, int matrixSize)
{
    cout << matrixtype << " MATRIX" << endl;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << setw(4) << matrix[i][j]; // Here too I used setw for a proper output
        }
        cout << endl;
    }
}
// Function to deallocate memory that I have dynamically allocated
void deleteMatrix(int** matrix,int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {   
        delete[] matrix[i];
    }
    delete[] matrix;   
}

// The function that will run when the user selects the first option
void firstOption()
{
    // I define the matrix sizes as random (I defined it as a constant because I need to call it in other functions.)
    const int inputMatrixSize = rand() % 16 + 5; 
    const int coreMatrixSize = rand() % 4 + 2;
    const int outputMatrixSize = inputMatrixSize - coreMatrixSize + 1;

    // Here I create the matrices using my function that both creates the matrix and assigns random numbers to it.
    int** inputMatrix = generateMatrix("INPUT", inputMatrixSize);
    int** coreMatrix = generateMatrix("CORE", coreMatrixSize);

    // Here I obtain the output matrix with the function that performs the special matrix operation.
    int** outputMatrix = CalcOutputMatrix(inputMatrix, coreMatrix, inputMatrixSize, coreMatrixSize);

    // Here I print the matrices with the function
    printMatrix("INPUT", inputMatrix, inputMatrixSize);
    printMatrix("CORE", coreMatrix, coreMatrixSize);
    printMatrix("OUTPUT", outputMatrix, outputMatrixSize);
    
    // Deallocating the memory with the 'deleteMatrix' function
    deleteMatrix(inputMatrix, inputMatrixSize);
    deleteMatrix(coreMatrix, coreMatrixSize);
    deleteMatrix(outputMatrix, outputMatrixSize);
}

// The function that will run when the user selects the second option
void secondOption()
{
    // I define the counters that will help me determine the size of matrices
    int inputLine = 0;
    int coreLine = 0;
    int outputLine;

    // Opening the 'data.txt' file to read the matrices in it
    ifstream readFile("data.txt", ios::in);
    // We check whether the file has been opened or not (it also checks whether the file exists or not)
    if (readFile.is_open())
    {
        string readLine; // We define a string variable to put the lines into
        getline(readFile, readLine); // We skip the "INPUT MATRIX" line in the file

        while (getline(readFile, readLine) && !readLine.empty()) // Determining the size of the input matrix by counting its rows (I'm also checking for empty lines here, just in case.)
        {
            if (readLine == "CORE MATRIX") // When it comes to the "CORE MATRIX" text, the loop stops and we determine the size of the input matrix.
            {
                break;
            }
            inputLine++;// Increase input matrix size counter
        }

        while (getline(readFile, readLine))// Determining the size of the core matrix by counting its rows
        {
            coreLine++;
        }

        // Creating dynamic matrixes again to import the contents of the file into it
        int** input_matrix = createMatrix(inputLine);
        int** core_matrix = createMatrix(inputLine);
        outputLine = (inputLine - coreLine) + 1;
        int** output_matrix = createMatrix(outputLine);

        readFile.close(); // Close the file
        readFile.open("data.txt", ios::in); // And open the file again for going the beginning of the file

        
        while (getline(readFile, readLine))
        {
            // Read values into the input matrix
            for (int i = 0; i < inputLine; i++)
            {
                for (int j = 0; j < inputLine; j++)
                {
                    readFile >> input_matrix[i][j];
                }
            }

            // These two getline commands to skip "CORE MATRIX" line
            getline(readFile, readLine); 
            getline(readFile, readLine);

            //Read values into the core matrix
            for (int i = 0; i < coreLine; i++)
            {
                for (int j = 0; j < coreLine; j++)
                {
                    readFile >> core_matrix[i][j];
                }
            }
        }
        
        output_matrix = CalcOutputMatrix(input_matrix, core_matrix, inputLine, coreLine);// Calculate the output matrix 

        // Here I print the matrices with the function
        printMatrix("Input", input_matrix, inputLine);
        printMatrix("Core", core_matrix, coreLine);
        printMatrix("Output", output_matrix, outputLine);

        // Deallocating the memory with the function
        deleteMatrix(input_matrix, inputLine);
        deleteMatrix(core_matrix, coreLine);
        deleteMatrix(output_matrix, outputLine);

        readFile.close();// Close the file
    }
    else
    {
        // Since there is no "data.txt" file, go to option 1
        cout << "There isn't a data.txt so the program continues with '1'. option" << endl << endl;
        firstOption();
    }
}
