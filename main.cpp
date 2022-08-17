/*********
 * Kendall Boesch
 * 17 August 2022
 *
 * Giving Tree of Errors 3.0
 *********/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/***********
 *  TREENODE CLASS
 *
 *  treeNode()
 *  treeeNode(char)
 *  treeNode* getRight()
 *  treeNode* getLeft()
 *  void setRight(treeNode*)
 *  void removeRight()
 *  void setLeft(treeNode*)
 *  void removeLeft()
 *  char getData()
 *  void setData(char)
 *  void removeData();
 *  void swap();
 *  bool alpha();
 *
 ***********/
class treeNode
{
public:
    char data;
    treeNode* left;
    treeNode* right;

    /**********
     * DEFAULT CONSTRUCTOR
     **********/
    treeNode()
    {
        data = '\0';
        left = right = nullptr;
    }
    /**********
     * COPY CONSTRUCTOR
     * @param c
     **********/
    treeNode(char c)
    {
        data = c;
        left = right = nullptr;
    }
    /**********
     * GET RIGHT
     *
     * Returns address of right node
     *
     * @return right node
     **********/
    treeNode* getRight()
    {
        return this->right;
    }
    /**********
     * GET LEFT
     *
     * Returns address of left node
     *
     * @return
     **********/
    treeNode* getLeft()
    {
        return this-> left;
    }
    /**********
     * SET RIGHT
     *
     * Set right node pointer
     *
     * @param r
     **********/
    void setRight(treeNode* r)
    {
        this->right = r;
    }
    /**********
     * REMOVE RIGHT
     *
     * Removes right node
     **********/
    void removeRight()
    {
        this->right = nullptr;
    }
    /**********
     * SET LEFT
     *
     * Set left node pointer
     *
     * @param l
     **********/
    void setLeft(treeNode* l)
    {
        this->left = l;
    }
    /**********
     * REMOVE LEFT
     *
     * Remove left node
     **********/
    void removeLeft()
    {
        this->left = nullptr;
    }
    /**********
     * GET DATA
     *
     * Returns data value
     *
     * @return
     **********/
    char getData()
    {
        return this->data;
    }
    /**********
     * SET DATA
     *
     * Set Data value
     *
     * @param c
     **********/
    void setData(char c)
    {
        this->data = c;
    }
    /*********
     *  REMOVE DATA
     *
     *  Remove data value
     *********/
    void removeData()
    {
        this->data = '\0';
    }
    /**********
    *SWAP
    *
    * Swaps nodes left & right children
    *
    ************/
    void swap()
    {
        treeNode* nRight = this->left;
        this->left = this->right;
        this->right = nRight;

    }
    /*********
    *   ALPHA
    *
    * Checks ordering of parents' children.
    * Returns true if left child is smaller
    * than the right child, else false
    ***********/
    bool alpha()
    {
        return this->left->data < this->right->data;
    }
};
/**********
 * TREE CLASS
 *
 * tree()
 * bool isEmpty()
 * bool contains(char)
 * bool auxContains(treeNode*, char)
 * bool insert(char, char)
 * int auxInsert(treeNode*, char, char)
 * bool findConnect(char, char)
 * int auxFindConnect(treeNode*, char, char)
 * void generateSExpression()
 * void auxSExpression(treeNode *)
 *
 **********/
class tree
{
public:
    treeNode* root;

    /**********
     * COPY CONSTRUCTOR
     **********/
    tree()
    {
        root = nullptr;
    }
    /**********
     * IS EMPTY
     *
     * returns true if empty
     *
     * @return
     */
    bool isEmpty()
    {
        return root == nullptr;
    }
    /***********
     * CONTAINS & AUXCONTAINS
     *
     * Returns true if tree contains node
     * with char c
     *
     * @param c
     * @return
     */
    bool contains(char c)
    {
        //Start at tree root
        return auxContains(root, c);
    }
    bool auxContains(treeNode* t, char c)
    {
        if (t == nullptr)
        {
            return false;
        }
        else
        {
            if(t->data == c)
            {
                return (auxContains(t->left, c) || true || auxContains(t->right, c));
            }
            else
            {
                return(auxContains(t->left,c) || false || auxContains(t->right,c));
            }
        }
    }
    /**********
     * INSERT
     *
     * Starter function for inserting
     * returns true if a node is inserted
     *
     * @param p
     * @param c
     * @return
     */
    bool insert(char p, char c)
    {
        if (root == nullptr)
        {
            // if root id three is null
            root = new treeNode(p); // create new node for root -> value = parent
            //cout << "Root = null" << endl << "Root created: " << p << endl;
            if(root->left == nullptr)
            {
                // if no left, set left child to c
                root->setLeft(new treeNode(c));
                // cout << "Set left child: " << c << endl;
            }
            else
            {

                // root has left child already
                root->setRight(new treeNode(c));    // insert c right
                // check child ordering
                if(!root->alpha())
                {
                    //if not alphabetical, swap
                    root->swap();
                }


            }
        }
        else
        {
            //root is not null -> tree is populated
            //Call auxiliary insert function
            int att = auxInsert(root, p, c);
            //cout << "ATT: " << att << endl;
            if(att != 0)        // if auxInsert returns !0, no insertion
            {
                return false;
            }
        }

        return true;
    }
    /**********
     * AUX INSERT
     *
     * Recursive Function for insertion into tree
     * Returns !0 if node was not inserted
     *
     * @param t
     * @param p
     * @param c
     * @return
     */
    int auxInsert(treeNode* t, char p, char c)
    {

        if(t == nullptr)    // passed node is nullptr
        {
            return 0;
        }
        else
        {
            // passed node holds data
            if (t->data == p)
            {
                //passed node is desired parent node
                if(t->left == nullptr)  // if left child is null
                {

                    t->left = new treeNode(c);
                    //cout << "Inserted child left: " << c << endl;
                    return 0;
                }
                else
                {
                    //Node passed in has a left child
                    if(t->right == nullptr)     // check for right child
                    {
                        //create right child
                        t->right = new treeNode(c);
                        if(!t->alpha())
                        {
                            t->swap();
                        }
                        //cout << "Inserted child right: " << c << endl;
                        return 0;
                    }
                    else
                    {
                        // Node passed is NOT nullptr
                        // Node passed is desired parent node
                        // Node has pre existing left & right child --> ERROR
                        // cout << "Desired node has preexisting children" << endl;
                        return 1;
                    }
                }
            }
            else
            {
                // Node passed was not desired parent node
                //cout << "Searching next level" << endl;
                return(auxInsert(t->left,p,c) + auxInsert(t->right, p, c));
            }
        }
    }
/************
 * FIND CONNECTION
 *
 * Starter function for finding
 * parent, child connections in the tree
 * returns true if the connection exists
 *
 * @param p
 * @param c
 * @return bool
 */
    bool findConnect(char p, char c)
    {
        int att = auxFindConnect(root, p, c);
        if(att == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    /**********
     * AUX FIND CONNECT
     *
     *  Auxiliary function for finding
     * parent-child connection. Returns 0
     * if the connection exists.
     *
     * @param t
     * @param p
     * @param c
     * @return
     ***********/
    int auxFindConnect(treeNode* t, char p, char c)
    {
        if (t == nullptr)   // if t does not have any data
        {
            return 0;
        }
        else // t has data
        {
            if (t->data == p)   // if t data is parent node
            {
                // if left is not null & data is child OR right is not null & data is child
                if ((t->left != nullptr && t->left->data == c) || (t->right != nullptr && t->right->data == c))
                {
                    return 0;
                }
                return 1;
            }
            else    // is parent is not found yet
            {
                return (auxFindConnect(t->right, p, c) + auxFindConnect(t->right, p, c));
            }
        }
    }
    /************
    *GENERATE S-EXPRESSION
    *
    *  Wrapper function for S-Expression
    * generation
    *************/
    void generateSExpression()
    {
        auxSExpression(root);
    }
    /**********
    *AUX S-EXPRESSION
    *
    * Iterates through tree printing
    * out S-Expression
    ************/
    void auxSExpression(treeNode* t)
    {
        if( t == nullptr)
        {
            //reached end of tree
            return;
        }
        else
        {
            cout << '(' << t->data;
            auxSExpression(t->left);
            auxSExpression(t->right);
            cout << ')';
        }
    }

};

tree tree;
vector<pair<char, char>> nodes;
bool errors, E1, E2, E3, E4, E5;
string input;

// ERROR CODES
//  E1 - Invalid input format
//  E2 - Duplicate pair
//  E3 - Too many children
//  E4 - Multiple roots
//  E5 - Cyclical input

void getInput();
bool validateInputFormat();
void fillTree();
void displayError();

int main()
{
    // get input
    getInput();
    // ensure valid input formatting
    validateInputFormat();
    //if formatting valid, fill tree
    if(!errors)
    {
        fillTree();
    }
    //If errors were detected
    if(errors)
    {
        //Display error code
        displayError();
    }
    else
    {
        // if no errors, print s-expression
        tree.generateSExpression();
    }
    return 0;
}
/*************
 *GET INPUT
 *
 * Checks for input, if exists reads it in.
 * Assigns read in value to global variable
 * 'input'
 ************/
void getInput()
{
    //cout << "Enter Input: " << endl;

    //TODO: Change to WHILE for submission
    if(cin) // Check for input
    {
        getline(cin, input);
    }
    //cout << "INPUT: " << input << endl;
}
/*********
 * VALIDATE INPUT FORMATTING
 *
 * Checks to insure the input has been
 * entered properly
 * EX: (X,Y) (X,Y)
 *
 * returns true if input formatting is valid
 *
 * @return
 *********/
bool validateInputFormat()
{

    bool reading = true;
    // if input size < 5 the input is not valid
    if(input.size() < 5)
    {
        //Assign error code
        //cout << "Error Code E1" << endl;
        errors = E1 = true;
        reading = false;
    }
    //Strings for input manipulation
    string extract, manip;
    manip = input;
    char parent, child;
    while(reading)
    {
        //extract the substring of pairs
        extract = manip.substr(0, 5);
        // cout << "EXTRACT: " << extract << endl;

        // check that the pair formatting is valid
        if(extract[0] == '('
           && extract[4] == ')'
           && extract[2] == ',')
        {
            //Assign parent & child values
            parent = extract[1];
            child = extract[3];
            // cout << "Child: " << child << endl << "Parent: " << parent << endl;
            //create <char, char> pair of the connection
            pair<char, char> connection = make_pair(parent, child);

            //push back connection in vector
            nodes.push_back(connection);
            //cout << "Pushed" << endl;


            //cout << manip.size() << endl;
            if(manip.size() < 11)   //if the manipulated input string is shorter than 11
            {                           //Means there are no pairs left to be read
                //cout << "All pairs read" << endl;
                reading = false;
            }
            else
            {
                // remove the extracted pair
                manip = manip.substr(6);
            }

        }
        else
        {
            //Invalid formatting
            errors = E1 = true;
            //cout << "Error code E1: Invalid formatting" << endl;
            reading = false;
        }
    }
    if(!errors)
    {
        //cout << "input validated" << endl;
        return true;
    }
    else
    {
        // cout << "invalid input formatting" << endl;
        return false;
    }
}
/************
 * FILL TREE
 *
 * Iterates through vector of
 * node connections checking all error cases*
 * Checks error codes E2,E4,E5 & if valid,
 * attempts to insert, if insertion fails
 * throws error code E3. If function runs
 * to completion (no breaks), then the input
 * in its entirety is valid
 *
 * *Error code E1 checked in validateInputFormat()
 *
 *
 *************/
void fillTree()
{
    // iterate through vector of nodes passed in
    for(int i = 0; i < nodes.size(); i++)
    {
        //assign parent & child
        char p = nodes[i].first;
        char c = nodes[i].second;
        // cout << "Parent: " << p << endl << "Child: " << c << endl;

        //Check to see if the tree already contains the paren t or child nodes
        bool hasParent = tree.contains(p);
        bool hasChild = tree.contains(c);

        //If the tree already has the parent & the child
        if(hasParent && hasChild)
        {
            //If connection alrady exists
            if(tree.findConnect(p,c))
            {

                //cout << "Error code E2: Duplicate pair" << endl;
                errors = E2 = true;
                break;
            }
            else
            {
                //IF the connection doesnt exist directly then its cyclical
                //cout << "Error code E5: Cyclical input" << endl;
                errors = E5 = true;
                break;
            }
        }
        else
        {
            // The tree is NOT empty && the tree does NOT have the requested parent
            if(!tree.isEmpty() && !hasParent)
            {
                // Error: Multiple roots
                //cout << "Error code E4: Multiple roots" << endl;
                errors = E4 = true;
                break;
            }
            else
            {
                // Attempt to insert connection
                bool ins = tree.insert(p,c);
                if(ins == false)
                {
                    // Error: Too many children
                    //cout << "Error code E3: Too many children " << endl;
                    errors = E3 = true;
                    break;
                }
            }
        }

    }
}
/**********
 * DISPLAY ERROR
 *
 * Iterates through all error codes
 * & prints to console the one that was
 * thrown first
 *
 **********/
void displayError()
{
    if(E1)  // Invalid input formatting
    {
        cout << "E1" << endl;
    }
    else if(E2)     // Duplicate pair
    {
        cout << "E2" << endl;
    }
    else if(E3)     // too many children
    {
        cout << "E3" << endl;
    }
    else if(E4)     // Multiple roots
    {
        cout << "E4" << endl;
    }
    else if(E5)     // Cyclical input
    {
        cout << "E5" << endl;
    }
    else
    {
        cout << "UNK" << endl;
    }
}



