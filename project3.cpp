/*Project 3
 *Completed: March __, 2020
 *Author: Jackson Bradshaw, 113474543
 */

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
    //TODO: do deep copy on operator= method
    GLRow<DT>& operator= (GLRow<DT>& anotherOne);
    int getNext();
    int getDown();
    DT& getInfo();
    int setNext(int n);
    int setDown(int d);
    int setInfo(DT& x);
    ~GLRow(); //destructor
};

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
    _info = anotherOne._info;
    _next = anotherOne._next;
    _down = anotherOne._down;
}

template <class DT>
GLRow<DT>::~GLRow() {
    delete[] _info;
}

template <class DT>
class ArrayGLL {
    friend ostream& operator<< <DT>(ostream& s, ArrayGLL<DT>& OneGLL);
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
    firstElement = NULL;
    firstFree = NULL;
}

template <class DT>
ArrayGLL<DT>::ArrayGLL(int size) {
    myGLL = new GLRow<DT>[size];
    firstElement = NULL;
    firstFree = NULL;
}

template <class DT>
ArrayGLL<DT>::ArrayGLL(ArrayGLL<DT>& anotherOne) {
    myGLL = anotherOne.myGLL;
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree;
}

template <class DT>
ArrayGLL<DT>::~ArrayGLL() {
    delete[] myGLL;
}

int main() {
    
    
    return 0;
}