// AVL.H - A AVL Tree (Self-Balancing BST)
// author Darcy Lyndon Cukrov Wilson

#ifndef AVL_H
#define AVL_H

#include <iostream>

using std::cout; //Allows for the usage of std::cout without needing std:: at the start (Printing Data)
using std::endl; //Allows for the usage of std::endl without needing std:: at the start (New Lines)

/**
* @class AVL
* @brief Creates a Templated AVL (Self-Balancing Binary Search Tree)
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 01/06/2022 Darcy Lyndon Cukrov Wilson
*/

//TEMPLATE CLASSES SOMETIMES HAVE THE DECLARATIONS & IMPLEMENTATIONS WITHIN THE HEADER FILE

template <class T> //Creates a template class of name T
class AVL {
public:
    struct Node;
        /**
        * @brief AVL Constructor
        *
        * The default constructor for the AVL
        */
    AVL();
        /**
        * @brief AVL Copy Constructor
        *
        * Copies the data from an input AVL to a new AVL
        */
    AVL(const AVL &inputAVL);
        /**
        * @brief AVL Destructor
        *
        * Destroys the AVL and frees it's memory once it goes outside of scope
        */
    ~AVL();
        /**
        * @brief Search Tree Function
        *
        * Takes an input element from the user and checks to see if it is within the AVL
        *
        * @return bool
        *
        * @param  const T searchElement - Element to be searched for in the AVL
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    bool SearchTree(const T& searchElement, void (*functionPointer) (const T& element));
        /**
        * @brief Insert Element Function (PUBLIC)
        *
        * Takes an input element from the user and inserts it into the AVL (CALLS THE PRIVATE FUNCTION)
        *
        * @return void
        *
        * @param  const T& inputValue - Element to be input into the AVL
        */
    void Insert(const T& inputValue);
        /**
        * @brief Public In Order Traversal Function
        *
        * Used to call the Private version of the function by the user
        *
        * @return void
        *
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    void InOrderTraversal(void (*functionPointer) (const T&)) const;
        /**
        * @brief Public Pre Order Traversal Function
        *
        * Used to call the Private version of the function by the user
        *
        * @return void
        *
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    void PreOrderTraversal(void (*functionPointer) (const T&)) const;
        /**
        * @brief Public Post Order Traversal Function
        *
        * Used to call the Private version of the function by the user
        *
        * @return void
        *
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    void PostOrderTraversal(void (*functionPointer) (const T&)) const;
        /**
        * @brief Assignment Operator Overloading
        *
        * Used to overload the = operator to make one AVL equal to another (Calls copy function)
        *
        * @return void
        *
        * @param  const T& inputBST - Element to be input into the AVL
        */
    void operator=(const T& inputBST);
private: //Usually Doxygen comments are NOT added for private variables, but for the sake of learning, they are here
        /**
        * @brief Copy AVL Function
        *
        * Called from the Copy Constructor, used to copy the elements from one AVL tree to the other
        *
        * @return void
        *
        * @param  Node* &nodeCopy - The AVL to be copied to
        * @param  Node* &inputNode - The AVL to be copied from
        */
    void CopyAVL(Node* &nodeCopy, Node *&inputNode);
        /**
        * @brief Maximum of Two Integers
        *
        * Used to find the maximum of two input integers
        *
        * @return int
        *
        * @param  int a - Integer to be compared against
        * @param  int b - Integer to be compared against
        */
    int MaxInteger(int a, int b);
        /**
        * @brief Get Current Node Height
        *
        * Used to return a node's current height
        *
        * @return Nint
        *
        * @param  Node* &inputRoot - Node who is to be used to return a height value
        */
    int GetNodeHeight(Node *&inputNode);
        /**
        * @brief Right Rotation of Node
        *
        * Used to perform a right rotation on a node
        *
        * @return Node*
        *
        * @param  Node* &inputRoot - Node who is to be used to perform the rotation
        */
    Node* RightRotate(Node *&inputNode);
        /**
        * @brief Left Rotation of Node
        *
        * Used to perform a left rotation on a node
        *
        * @return Node*
        *
        * @param  Node* &inputRoot - Node who is to be used to perform the rotation
        */
    Node* LeftRotate(Node *&inputNode);
        /**
        * @brief Get Balance Factor
        *
        * Used to find the height of a given input node
        *
        * @return int
        *
        * @param  Node* &inputRoot - Node whose height is to be checked
        */
    int GetBalanceFactor(Node *&inputNode);
        /**
        * @brief Insert Element Function (PRIVATE)
        *
        * Used to recursively loop through elements, add them to the AVL and balance them
        *
        * @return void
        *
        * @param  const int inputValue - Element to be input into the tree
        * @param  Node* &inputRoot - Node to be added to
        */
    Node* Insert(const T& inputValue, Node *&inputRoot);
        /**
        * @brief Search Tree Function
        *
        * Takes an input element from the user and checks to see if it is within the AVL
        *
        * @return void
        *
        * @param  const T searchElement - Element to be searched for in the AVL
        * @param  bool dataFound - A boolean to tell whether the data has been found or not
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        * @param  Node* &inputNode - The node to be searched from
        */
    void SearchTree(const T& searchElement, bool &dataFound, void (*functionPointer) (const T& element), Node *&inputNode);
        /**
        * @brief In Order Traversal (PRIVATE)
        *
        * Used to recursively loop through elements and print them out
        *
        * @return void
        *
        * @param  const Node* inputRoot - Tree to be printed from
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    void InOrderTraversal(const Node *inputRoot, void (*functionPointer) (const  T& element)) const;
        /**
        * @brief Pre Order Traversal (PRIVATE)
        *
        * Used to recursively loop through elements and print them out
        *
        * @return void
        *
        * @param  const Node* inputRoot - Tree to be printed from
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    void PreOrderTraversal(const Node *inputRoot, void (*functionPointer) (const  T& element)) const;
        /**
        * @brief Post Order Traversal (PRIVATE)
        *
        * Used to recursively loop through elements and print them out
        *
        * @return void
        *
        * @param  const Node* inputRoot - Tree to be printed from
        * @param  void (*functionPointer) (const  T& element) - A pointer to a function
        */
    void PostOrderTraversal(const Node *inputRoot, void (*functionPointer) (const  T& element)) const;
        /**
        * @brief Delete Tree Function
        *
        * Accessed by the destructor, used to delete the AVL and free it's memory
        *
        * @return void
        *
        * @param  Node* &inputNode - Tree to be deleted
        */
    void DeleteTree(Node *&inputRoot);
        /**
        * @param  Node* root - The root node of the AVL
        */
    Node* root;
};

template <class T>
struct AVL<T>::Node{
    T nodeData; //The data within the node

    Node* lLink; //The pointer to the left subtree
    Node* rLink; //The pointer to the right subtree

    int nodeHeight; //The height of the node

    Node(T inputElement): nodeData(inputElement), lLink(nullptr), rLink(nullptr), nodeHeight(1) {} //Constructor for the data structure
};

template <class T>
AVL<T>::AVL()
{
    root = nullptr; //Sets the root node to a null pointer
}

template <class T>
AVL<T>::AVL(const AVL &inputAVL)
{
    CopyAVL(root, inputAVL.root); //Calls the Copy AVL function
}

template <class T>
AVL<T>::~AVL()
{
    DeleteTree(root); //Calls a recursive function which deletes the tree
}

template <class T>
int AVL<T>::MaxInteger(int a, int b)
{
    return (a > b)? a : b; //Returns the maximum of the two integers
}

template <class T>
int AVL<T>::GetNodeHeight(Node *&inputNode)
{
    if(inputNode != nullptr) //If the node pointer is not equal to a null pointer
    {
        return(inputNode->nodeHeight); //Returns the height of the node
    }
    else
        return(0); //Return a node height of 0
}

template <class T>
typename AVL<T>::Node* AVL<T>::RightRotate(Node *&inputNode)
{
    Node *returnNode = inputNode->lLink; //Node to be returned
    Node *temporaryNode = returnNode->rLink; //Temporary node for storage

    //Perform rotation of the node
    returnNode->rLink = inputNode;
    inputNode->lLink = temporaryNode;

    //Update the heights of the nodes
    inputNode->nodeHeight = MaxInteger(GetNodeHeight(inputNode->lLink), GetNodeHeight(inputNode->rLink)) + 1;
    returnNode->nodeHeight = MaxInteger(GetNodeHeight(returnNode->lLink), GetNodeHeight(returnNode->rLink)) + 1;

    return(returnNode);
}

template <class T>
typename AVL<T>::Node* AVL<T>::LeftRotate(Node *&inputNode)
{
    Node *returnNode = inputNode->rLink; //Node to be returned
    Node *temporaryNode = returnNode->lLink; //Temporary node for storage

    //Perform rotation of the node
    returnNode->lLink = inputNode;
    inputNode->rLink = temporaryNode;

    //Update the heights of the nodes
    inputNode->nodeHeight = MaxInteger(GetNodeHeight(inputNode->lLink), GetNodeHeight(inputNode->rLink)) + 1;
    returnNode->nodeHeight = MaxInteger(GetNodeHeight(returnNode->lLink), GetNodeHeight(returnNode->rLink)) + 1;

    return(returnNode);
}

template <class T>
int AVL<T>::GetBalanceFactor(Node *&inputNode)
{
    if(inputNode != nullptr) //If the node pointer is not equal to a null pointer
    {
        return(GetNodeHeight(inputNode->lLink) - GetNodeHeight(inputNode->rLink)); //Returns the height of the Left Link minus the height of the Right Link
    }
    else
        return(0); //Return a balance factor of 0
}

template <class T>
bool AVL<T>::SearchTree(const T& searchElement, void (*functionPointer) (const T& element))
{
    Node *currentNode; //The current node being searched through
    bool dataFound = false; //Sets the initial state of the data being found

    if(root == nullptr) //Checks to see if the tree is empty
    {
        cout << "ERROR: Tree is empty, cannot be searched!" << endl;

        return(false);
    }
    else
    {
        SearchTree(searchElement, dataFound, functionPointer, root);
    }

    return(dataFound);
}

template <class T>
void AVL<T>::SearchTree(const T& searchElement, bool &dataFound, void (*functionPointer) (const T& element), Node *&inputNode)
{
    if(inputNode != nullptr) //Loops through till the node is a null pointer or while the element is not found
    {
        if (inputNode->nodeData == searchElement) //If the element is found
        {
            (*functionPointer)(inputNode->nodeData); //Calls the function from the function pointer

            dataFound = true;
        }

        SearchTree(searchElement, dataFound, functionPointer, inputNode->lLink); //Searches through the Left Link
        SearchTree(searchElement, dataFound, functionPointer, inputNode->rLink); //Searches through the right Link
    }
}

template <class T>
void AVL<T>::CopyAVL(Node* &nodeCopy, Node *&inputNode)
{
    if(inputNode == nullptr) //Checks to see if the input tree is empty
    {
        nodeCopy = nullptr; //Sets the new tree to be empty
    }
    else
    {
        nodeCopy = new Node(inputNode->nodeData); //Allocates space for a node on the new tree with the data of the old tree's node

        CopyBST(nodeCopy->lLink, inputNode->lLink); //Copys the data from the left link of the input node
        CopyBST(nodeCopy->rLink, inputNode->rLink); //Copys the data from the right link of the input node
    }
}

template <class T>
void AVL<T>::Insert(const T& inputData)
{
    if(root == nullptr) //Checks to see if the root node is equal to a pull pointer
    {
        root = new Node(inputData); //If it is, create memory for a new node, set it's data to the input value, and set the root node
    }
    else
    {
        root = Insert(inputData, root); //Opens the Private Insert function
    }
}

template <class T>
typename AVL<T>::Node* AVL<T>::Insert(const T& inputData, Node *&inputRoot)
{
    if(inputData == inputRoot->nodeData) //Checks to see if the input value is equal to the current root value
    {
        return(inputRoot); //If it is, it will ignore the value and leave the function
    }

    if(inputData < inputRoot->nodeData) //Checks if the input data is less than the current node data
    {
        if(inputRoot->lLink != nullptr)
        {
            inputRoot->lLink = Insert(inputData, inputRoot->lLink); //Loops back to the start of the function with the left link being the root node
        }
        else
            inputRoot->lLink = new Node(inputData); //If it is, create memory for a new node, set it's data to the input value, and set the root node
    }
    else
    {
        if(inputRoot->rLink != nullptr)
        {
            inputRoot->rLink = Insert(inputData, inputRoot->rLink); //Loops back to the start of the function with the left link being the root node
        }
        else
            inputRoot->rLink = new Node(inputData); //If it is, create memory for a new node, set it's data to the input value, and set the root node
    }

    inputRoot->nodeHeight = MaxInteger(GetNodeHeight(inputRoot->lLink), GetNodeHeight(inputRoot->rLink)) + 1; //Updates the node height

    int balanceFactor = GetBalanceFactor(inputRoot); //Finds the Balance Factor of the input node

    //Left Left Rotation
    if((balanceFactor > 1) && (inputData < inputRoot->lLink->nodeData))
    {
        return(RightRotate(inputRoot));
    }

    //Right Right Rotation
    if((balanceFactor < -1) && (inputData > inputRoot->rLink->nodeData))
    {
        return(LeftRotate(inputRoot));
    }

    //Left Right Rotation
    if((balanceFactor > 1) && (inputData > inputRoot->lLink->nodeData))
    {
        inputRoot->lLink = LeftRotate(inputRoot->lLink);

        return(RightRotate(inputRoot));
    }

    //Right Left Rotation
    if((balanceFactor < -1) && (inputData < inputRoot->rLink->nodeData))
    {
        inputRoot->rLink = RightRotate(inputRoot->rLink);

        return(LeftRotate(inputRoot));
    }

    return(inputRoot);
}

template <class T>
void AVL<T>::InOrderTraversal(void (*functionPointer) (const T& element)) const
{
    cout << "--------------------------------------" << endl;
    cout << "Running In Order Traversal..." << endl;
    cout << "--------------------------------------" << endl;

    InOrderTraversal(root, *functionPointer);
}

template <class T>
void AVL<T>::InOrderTraversal(const Node *inputRoot, void (*functionPointer) (const T& element)) const
{
    if(inputRoot != nullptr) //Checks to see if the current node has elements
    {
        InOrderTraversal(inputRoot->lLink, *functionPointer); //Prints the left link of the node

        (*functionPointer)(inputRoot->nodeData);

        InOrderTraversal(inputRoot->rLink, *functionPointer); //Prints the right link of the node
    }
}

template <class T>
void AVL<T>::PreOrderTraversal(void (*functionPointer) (const T& element)) const
{
    cout << "--------------------------------------" << endl;
    cout << "Running Pre Order Traversal..." << endl;
    cout << "--------------------------------------" << endl;

    PreOrderTraversal(root, *functionPointer);
}

template <class T>
void AVL<T>::PreOrderTraversal(const Node *inputRoot, void (*functionPointer) (const T& element)) const
{
    if(inputRoot != nullptr)  //Checks to see if the current node has elements
    {
        (*functionPointer)(inputRoot->nodeData);

        PreOrderTraversal(inputRoot->lLink, *functionPointer); //Prints the left link of the node
		PreOrderTraversal(inputRoot->rLink, *functionPointer); //Prints the right link of the node
    }
}

template <class T>
void AVL<T>::PostOrderTraversal(void (*functionPointer) (const T& element)) const
{
    cout << "--------------------------------------" << endl;
    cout << "Running Post Order Traversal..." << endl;
    cout << "--------------------------------------" << endl;

    PostOrderTraversal(root, *functionPointer);
}

template <class T>
void AVL<T>::PostOrderTraversal(const Node *inputRoot, void (*functionPointer) (const T& element)) const
{
    if(inputRoot != nullptr)  //Checks to see if the current node has elements
    {
        PostOrderTraversal(inputRoot->lLink, *functionPointer); //Prints the left link of the node
		PostOrderTraversal(inputRoot->rLink, *functionPointer); //Prints the right link of the node

		(*functionPointer)(inputRoot->nodeData);
    }
}

template <class T>
void AVL<T>::DeleteTree(Node *&inputRoot)
{
    if(inputRoot != nullptr) //Checks to see if the input node is not equal to a null pointer
    {
        DeleteTree(inputRoot->lLink); //Calls the left leaf of the input node and deletes it
        DeleteTree(inputRoot->rLink); //Calls the right leaf of the input node and deletes it

        delete inputRoot; //Deletes the input node

        inputRoot = nullptr; //Sets the input node to point to nothing in memory
    }
}

template <class T>
void AVL<T>::operator=(const T& inputAVL)
{
    CopyAVL(root, inputAVL.root); //Calls the Copy AVL function
}

#endif
