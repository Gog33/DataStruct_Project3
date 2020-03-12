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
    friend ostream& operator<< <DT>(ostream& s, GLRow<DT>& oneGLRow);
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
ostream& operator<< <DT>(ostream& s, GLRow<DT>& oneGLRow) {
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
    _next = NULL;
    _down = NULL;
}

template <class DT>
GLRow<DT>::GLRow(GLRow<DT>& anotherOne) {
    _info = new DT(*anotherOne._info);
    _next = new int(*anotherOne._next);
    _down = new int(*anotherOne._down); //deep copies all variables from anotherOne
}

template <class DT>
GLRow<DT>& GLRow<DT>::operator= (GLRow<DT>& anotherOne) {
    _info = new DT(*anotherOne._info);
    _next = new int(*anotherOne._next);
    _down = new int(*anotherOne._down); //deep copies all variables from anotherOne
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
    myGLL = new myGLL(*anotherOne.myGLL);
    maxSize = new int(*anotherOne.maxSize);
    firstElement = new int(*anotherOne.firstElement);
    firstFree = new int(*anotherOne.firstFree);
}

template <class DT>
int ArrayGLL<DT>::find(DT& key) {
    for (int i = 0; i < maxSize; ++i) {
        if (myGLL[i].getInfo() == key) {
            return i; //returns index of key searched for
        }
    }
    return -1; //retuns -1 if key is not in array
}

template <class DT>
int ArrayGLL<DT>::noFree() {
    return 0; //TODO: complete this
}

template <class DT>
int ArrayGLL<DT>::size() {
    int size = 0;
    for (int i = 0; i < maxSize; ++i) {
        if (myGLL[i].getInfo() != NULL) { //if an element with info is present
            ++size; //adds to size, the number of elements stored
        }
    }
    return size;
}

template <class DT>
ArrayGLL<DT>::~ArrayGLL() {
    delete[] myGLL;
}

int main() {
    
    //implemented after full class construction

    return 0;
}