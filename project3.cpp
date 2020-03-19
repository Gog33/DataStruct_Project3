/*Project 3
 *Completed: March __, 2020
 *Author: Jackson Bradshaw, 113474543
 */

#include <iostream>
using namespace std;

template <class DT>
class GLRow; //class prototype
template <class DT>
ostream& operator <<(ostream& s, const GLRow<DT>& oneGLRow);

template <class DT>
class GLRow {
    template <class T>
    friend ostream& operator<< (ostream& s, const GLRow<T>& oneGLRow);
protected:
    DT* _info;
    int _next;
    int _down;
public:
    GLRow(); //no-args constructor
    GLRow(const DT& newInfo); //args constructor
    GLRow(GLRow<DT>& anotherOne); //copy constructor
    GLRow<DT>& operator= (GLRow<DT>& anotherOne);
    int getNext(); //returns next
    int getDown(); //returns down
    DT& getInfo(); //returns info
    void setNext(int n); //sets next
    void setDown(int d); //sets down
    void setInfo(const DT& i); //sets info
    ~GLRow(); //destructor
};

template <class DT>
ostream& operator<< (ostream& s, const GLRow<DT>& oneGLRow) {
    s << *(oneGLRow._info);
    return s;
}

template <class DT>
GLRow<DT>::GLRow() {
    *_info = 999;
    _next = -1;
    _down = -1;
}

template <class DT>
GLRow<DT>::GLRow(const DT& newInfo) {
    *_info = newInfo;
    _next = -1;
    _down = -1;
}

template <class DT>
GLRow<DT>::GLRow(GLRow<DT>& anotherOne) {
    _info = new DT;
    *_info = *(anotherOne._info);
    _next = anotherOne._next;
    _down = anotherOne._down; //deep copies all variables from anotherOne
}

template <class DT>
GLRow<DT>& GLRow<DT>::operator= (GLRow<DT>& anotherOne) {
    _info = new DT;
    *_info = *(anotherOne._info);
    _next = anotherOne._next;
    _down = anotherOne._down; //deep copies all variables from anotherOne
    return *this;
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
    return *_info;
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
void GLRow<DT>::setInfo(const DT& i) {
    *_info = i;
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
    template <class T>
    friend ostream& operator<< (ostream& s, ArrayGLL<T>& oneGLL);
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
    string parenFormat(int startPos); //recursive call, develops string to print in parenthesis format
    void display(); //display in parenthesis format
    int find(DT& key);  //returns index position of the element key
                        //returns -1 if key is not present
    void printPath(DT* path, int length); //prints out path for findDisplayPath (declared below)
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
private:
    int find(DT& key, int startPos); //part of find recursive algorithm
    bool findPathRecur(DT& key, int startPos, DT* path, int length); //recursive call for print path method
    int parentPos(DT& key, int startPos, int lastPos); //part of parentPos recursive call
};

template <class DT>
ArrayGLL<DT>::ArrayGLL() {
    myGLL = new GLRow<DT>[0];
    maxSize = 0;
    firstElement = -1;
    firstFree = -1;
}

template <class DT>
ArrayGLL<DT>::ArrayGLL(int size) {
    myGLL = new GLRow<DT>[size];
    maxSize = size;
    firstElement = -1;
    firstFree = -1;
}

template <class DT>
ArrayGLL<DT>::ArrayGLL(ArrayGLL<DT>& anotherOne) {
    myGLL = new GLRow<DT>;
    myGLL = anotherOne.myGLL;
    maxSize = anotherOne.maxSize;
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree; //deep copy
}

template <class DT>
ArrayGLL<DT>& ArrayGLL<DT>::operator= (ArrayGLL<DT>& anotherOne) {
    myGLL = new GLRow<DT>;
    myGLL = anotherOne.myGLL;
    maxSize = anotherOne.maxSize;
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree; //deep copy
    return *this;
}

template <class DT>
string ArrayGLL<DT>::parenFormat(int startPos) {
    string s = "";
    s += myGLL[startPos].getInfo(); //adds info to string
    int currPos = myGLL[startPos].getDown();
    if (currPos != -1) { //if node has a down connection
        s += "(";
        s += parenFormat(currPos); //recursive call to add next print string
        while (myGLL[currPos].getNext() != -1) { //while there is a next node
            currPos = myGLL[currPos].getNext();
            s += " ";
            s += parenFormat(currPos);
        }
        s += ")";
    }
    return s;
}

template <class DT>
ostream& operator<< (ostream& s, ArrayGLL<DT>& oneGLL) {
    s << oneGLL.parenFormat(oneGLL.firstElement);
    return s;
}

template <class DT>
void ArrayGLL<DT>::display() {
    cout << parenFormat(firstElement);
}

template <class DT>
int ArrayGLL<DT>::find(DT& key, int startPos) {
    if (myGLL[startPos].getInfo() == key) {
        return startPos; //index with the correct key
    }
    int currPos = myGLL[startPos].getDown();
    if (currPos != -1) { //if node has a down connection
        int result = find(key, currPos); //first recursive call
                                         //set to result so that -1 is not automatically returned
        while (myGLL[currPos].getNext() != -1 && result == -1) { //while there is a next node
            currPos = myGLL[currPos].getNext();                  //and result is still -1 (key not found)
            result = find(key, currPos); //recursive call
        }
        return result; //returns result, -1 or otherwise
    }
    return -1; //returns -1 if startPos node lacks key and has no down node
}

template <class DT>
int ArrayGLL<DT>::find(DT& key) {
    find(key, firstElement); //goes to recursive find algorithm
    
    return -1; //returns -1, in case of error with recursive call (may not be necessary)
}

template <class DT>
void ArrayGLL<DT>::printPath(DT* path, int length) {
    for (int i = 0; i < length; ++i) {
        cout << path[i];
        if (i < length - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

template <class DT>
bool ArrayGLL<DT>::findPathRecur(DT& key, int startPos, DT* path, int length) {
    if (startPos == -1) { //if there is no next location
        return false; 
    }
    else if (myGLL[startPos].getInfo() == key) {
        path[length] = myGLL[startPos].getInfo();
        printPath(path, length + 1);
        return true;
    }
    int currPos = myGLL[startPos].getDown();
    if (currPos != -1) {
        path[length] = myGLL[startPos].getInfo();
        while ((myGLL[currPos].getNext() != -1)) {
            currPos = myGLL[currPos].getNext();
            if (findPathRecur(key, currPos, path, length + 1)) {
                return true; //if the forward path contains the printed statement
            }
        }
    }
    return false;
}

template <class DT>
void ArrayGLL<DT>::findDisplayPath(DT& key) {
    DT* path = new DT[maxSize]; //creates path to store GLRows on the way to key

    findPathRecur(key, firstElement, path, 0);
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
        if (myGLL[i].getInfo() != 999) { //if a non-free element 
                                                                           //with info is present
            ++size; //adds to size, the number of elements stored
        }
    }
    return size;
}

template <class DT>
int ArrayGLL<DT>::parentPos(DT& key, int startPos, int lastPos) {
    if (myGLL[startPos].getInfo() == key) {
        return lastPos; //index with the correct key
    }
    int pastPos = startPos;
    int currPos = myGLL[startPos].getDown();
    if (currPos != -1) { //if node has a down connection 
        int result = parentPos(key, currPos, pastPos);
        while (myGLL[currPos].getNext() != -1 && result == -1) { //while there is a next node
            pastPos = currPos; //set pastPos to currPos
            currPos = myGLL[currPos].getNext(); //sends currPos to next node
            result = parentPos(key, currPos, pastPos); //recursive call
        }
        return result; //returns result, -1 or otherwise
    }
    return -1; //returns -1 if startPos node lacks key and has no down node
}

template <class DT>
int ArrayGLL<DT>::parentPos(DT& key) {
    parentPos(key, firstElement, -1); //goes to recursive parentPos algorithm
                                      //-1 initially, because first Element has no parent position
    
    return -1; //returns -1, in case of error with recursive call (may not be necessary)
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
    
    ArrayGLL<int> firstGLL(20);
    int noElements, v, n, d, parentPos;
    int pos = -1;
    int keyValue;
    int tempValue = 0;
    GLRow<int> oneRow(0);

    //first line of input contains number of sequences
    cin >> noElements;
    for (int i = 0; i < noElements; ++i) {
        cin >> v >> n >> d;
        oneRow.setInfo(v);
        oneRow.setNext(n);
        oneRow.setDown(d);
        firstGLL[i] = oneRow;
    }
    firstGLL.setFirstFree(8);
    firstGLL.setFirstElement(2);
    cout << firstGLL << endl;
    firstGLL.display();

    ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);

    (*secondGLL)[1].setInfo(600);
    (*secondGLL)[2].setInfo(700);

    cout << *secondGLL << endl;
    (*secondGLL).display();

    keyValue = 700;
    pos = (*secondGLL).find(keyValue);
    if (pos != -1) {
        cout << (*secondGLL)[pos] << endl;
        (*secondGLL).findDisplayPath(keyValue);
    }
    parentPos = (*secondGLL).parentPos(keyValue);
    if (parentPos != -1) {
        cout << (*secondGLL)[parentPos] << endl;
    }
    cout << (*secondGLL).size();
    cout << (*secondGLL).noFree();

    delete secondGLL;
    
    return 0;
}