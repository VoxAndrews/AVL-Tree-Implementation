// Program created to read data files from the Murdoch University Weather Station
// author Darcy Lyndon Cukrov Wilson

#include <iostream>
#include <fstream>
#include <string>

#include "AVL.H"

using std::cout; //Allows for the usage of cout without needing std:: at the start (Output to screen)
using std::endl; //Allows for the usage of endl without needing std:: at the start (New Lines)
using std::string; //Allows for the usage of string without needing std:: at the start (New Lines)

void PrintIntegerData(const int &inputData)
{
    cout << inputData << endl; //Prints input integer data
}

void PrintStringData(const string &inputData)
{
    cout << inputData << endl; //Prints input string data
}

void PrintCharacterData(const char &inputData)
{
    cout << inputData << endl; //Prints input character data
}

int main()
{
    AVL<int> intData;
    AVL<string> stringData;
    AVL<char> charData;

    //INSERTING INTEGER DATA
    intData.Insert(274);
    intData.Insert(3245);
    intData.Insert(5342);
    intData.Insert(4235);

    //INSERTING STRING DATA
    stringData.Insert("This ");
    stringData.Insert("is ");
    stringData.Insert("a ");
    stringData.Insert("Test!");

    //INSERTING CHARACTER DATA
    charData.Insert('a');
    charData.Insert('b');
    charData.Insert('c');
    charData.Insert('d');

    //PRINTING DATA FROM TRAVERSALS USING FUNCTION POINTERS (INTEGER DATA)
    cout << "--------------------------------------" << endl;
    cout << "In Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    intData.InOrderTraversal(PrintIntegerData);

    cout << "--------------------------------------" << endl;
    cout << "Pre Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    intData.PreOrderTraversal(PrintIntegerData);

    cout << "--------------------------------------" << endl;
    cout << "Post Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    intData.PostOrderTraversal(PrintIntegerData);

    //PRINTING DATA FROM TRAVERSALS USING FUNCTION POINTERS (STRING DATA)
    cout << "--------------------------------------" << endl;
    cout << "In Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    stringData.InOrderTraversal(PrintStringData);

    cout << "--------------------------------------" << endl;
    cout << "Pre Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    stringData.PreOrderTraversal(PrintStringData);

    cout << "--------------------------------------" << endl;
    cout << "Post Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    stringData.PostOrderTraversal(PrintStringData);

    //PRINTING DATA FROM TRAVERSALS USING FUNCTION POINTERS (CHARACTER DATA)
    cout << "--------------------------------------" << endl;
    cout << "In Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    charData.InOrderTraversal(PrintCharacterData);

    cout << "--------------------------------------" << endl;
    cout << "Pre Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    charData.PreOrderTraversal(PrintCharacterData);

    cout << "--------------------------------------" << endl;
    cout << "Post Order Traversal Data" << endl;
    cout << "--------------------------------------" << endl;
    charData.PostOrderTraversal(PrintCharacterData);

    return 0;
}
