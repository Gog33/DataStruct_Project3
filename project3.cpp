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

int main() {
    
    
    return 0;
}