/*Project 3
 *Completed: March __, 2020
 *Author: Jackson Bradshaw, 113474543
 */

#include <iostream>
using namespace std;

template <class DT>
class GLRow; //class prototype
template <class DT>
ostream& operator <<(ostream& s, GLRow<DT>& oneGLRow);

template <class DT>
class GLRow {
    friend ostream& operator<< <DT>(ostream& s, const GLRow<DT>& oneGLRow);
protected:
    DT* _info;
    int _next;
    int _down;
public:
    GLRow(); //no-args constructor
    GLRow(DT& newInfo); //args constructor
    GLRow(GLRow<DT>& anotherOne); //copy constructor
    GLRow<DT>& operator= (GLRow<DT>& anotherOne);
    int getNext(); //returns next
    int getDown(); //returns down
    DT& getInfo(); //returns info
    void setNext(int n); //sets next
    void setDown(int d); //sets down
    void setInfo(DT& i); //sets info
    ~GLRow(); //destructor
};

template <class DT>
ostream& operator<< (ostream& s, const GLRow<DT>& oneGLRow) {
    s << oneGLRow._info;
    return s;
}

template <class DT>
GLRow<DT>::GLRow() {
    _info = NULL;
    _next = NULL;
    _down = NULL;
}

template <class DT>
GLRow<DT>::GLRow(DT& newInfo) {
    _info = newInfo;
    _next = -1;
    _down = -1;
}

template <class DT>
GLRow<DT>::GLRow(GLRow<DT>& anotherOne) {
    _info = new DT;
    _info = anotherOne._info;
    _next = new int;
    _next = anotherOne._next;
    _down = new int;
    _down = anotherOne._down; //deep copies all variables from anotherOne
}

template <class DT>
GLRow<DT>& GLRow<DT>::operator= (GLRow<DT>& anotherOne) {
    _info = new DT;
    _info = anotherOne._info;
    _next = new int;
    _next = anotherOne._next;
    _down = new int;
    _down = anotherOne._down; //deep copies all variables from anotherOne
}

template <class DT>
int GLRow<DT>::getNext() {
    return _next;
}

template <class DT>
int GLRow<DT>::getDown() {
    return _down;
}

template <class DT>
DT& GLRow<DT>::getInfo() {
    return _info;
}

template <class DT>
void GLRow<DT>::setNext(int n) {
    _next = n;
}

template <class DT>
void GLRow<DT>::setDown(int d) {
    _down = d;
}

template <class DT>
void GLRow<DT>::setInfo(DT& i) {
    _info = i;
}

template <class DT>
GLRow<DT>::~GLRow() {
    delete[] _info;
}

template <class DT>
class ArrayGLL; //class prototype
template <class DT>
ostream& operator <<(ostream& s, ArrayGLL<DT>& oneGLL);

template <class DT>
class ArrayGLL {
    friend ostream& operator<< <DT>(ostream& s, ArrayGLL<DT>& oneGLL);
protected:
    GLRow<DT>* myGLL; //array of GLRows
    int maxSize; //maximum size of the array of GLRows
    int firstElement; 
    int firstFree;
public:
    ArrayGLL(); //no-args constructor
    ArrayGLL(int size); //args (size input) constructor
    ArrayGLL(ArrayGLL<DT>& anotherOne); //copy constructor
    ArrayGLL<DT>& operator= (ArrayGLL<DT>& anotherOne);
    void display(); //display in parenthesis format
    int find(DT& key);  //returns index position of the element key
                        //returns -1 if key is not present
    void findDisplayPath(DT& key); /*prints the values of nodes
                                    *visited along the route to
                                    *the element key
                                    */
    int noFree(); //returns the number of free locations
    int size(); //return number of elements stored
    int parentPos(DT& key); //provides the location of the parent
                            //of the element key in the array
    GLRow<DT>& operator [] (int pos); //returns the GLRow that is in
                                      //the position pos in the array
    int getFirstFree(); 
    int getFirstElement(); 
    void setFirstFree(int pos); 
    void setFirstElement(int pos); 
    ~ArrayGLL(); //destructor
};

template <class DT>
ArrayGLL<DT>::ArrayGLL() {
    myGLL = NULL;
    maxSize = NULL;
    firstElement = NULL;
    firstFree = NULL;
}

template <class DT>
ArrayGLL<DT>::ArrayGLL(int size) {
    myGLL = new GLRow<DT>[size];
    maxSize = size;
    firstElement = NULL;
    firstFree = NULL;
}

template <class DT>
ArrayGLL<DT>::ArrayGLL(ArrayGLL<DT>& anotherOne) {
    myGLL = new GLRow<DT>;
    myGLL = anotherOne.myGLL;
    maxSize = new int;
    maxSize = anotherOne.maxSize;
    firstElement = new int;
    firstElement = anotherOne.firstElement;
    firstFree = new int;
    firstFree = anotherOne.firstFree; //deep copy
}

template <class DT>
int ArrayGLL<DT>::find(DT& key) {
    //TODO: complete this recursively
    
    return -1; //retuns -1 if key is not in array
}

template <class DT>
int ArrayGLL<DT>::noFree() {
    GLRow<DT> freeRow = myGLL[firstFree]; //starts at first free location in myGLL array
    int numFree = 1; //initialized to 1 for first free location
    while (freeRow.getNext() != -1) { //while the node has a next
        freeRow = myGLL[freeRow.getNext()]; //sets freeRow to next node
        numFree++; //adds to numFree per node travelled
    }
    return numFree;
}

template <class DT>
int ArrayGLL<DT>::size() {
    int size = 0;
    for (int i = 0; i < maxSize; ++i) {
        if (myGLL[i].getInfo() != NULL && myGLL[i].getInfo() != 999) {  //if a non-free element 
                                                                        //with info is present
            ++size; //adds to size, the number of elements stored
        }
    }
    return size;
}

template <class DT>
GLRow<DT>& ArrayGLL<DT>::operator [] (int pos) {
    return myGLL[pos];
}

template <class DT>
int ArrayGLL<DT>::getFirstFree() {
    return firstFree;
}

template <class DT>
int ArrayGLL<DT>::getFirstElement() {
    return firstElement;
}

template <class DT>
void ArrayGLL<DT>::setFirstFree(int pos) {
    firstFree = pos;
}

template <class DT>
void ArrayGLL<DT>::setFirstElement(int pos) {
    firstElement = pos;
}

template <class DT>
ArrayGLL<DT>::~ArrayGLL() {
    delete[] myGLL;
}

int main() {
    
    //implemented after full class construction

    return 0;
}