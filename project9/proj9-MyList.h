/**
* file: proj9-MyList.h
* author: Gabriel Choi
* course: CSI 1440
* assignment: Project 9
* due date: 11/28/22
*
* data modified: 11/26/22
*  - file created
*  - most of coding finished
*
* Linked Lists
*/

#ifndef PROJ9_1_PROJ9_MYLIST_H
#define PROJ9_1_PROJ9_MYLIST_H

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

template <class T>
class MyList : public ContainerIfc <T> {
public:
    /**
     * MyList
     *
     * class constructor
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    MyList();

    /**
     * ~MyList
     *
     * class destructor
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    ~MyList();

    /**
     * MyList
     *
     * class copy constructor
     *
     * Parameters:
     *      n: reference to MyVector object
     *
     * Output:
     *      return: none
     *      reference parameters: MyVector object
     *      stream: none
     */
    MyList(const MyList&);

    /**
     * operator =
     *
     * overloaded assignment operator
     *
     * Parameters:
     *      n: reference to MyVector object
     *
     * Output:
     *      return: reference to MyVector object
     *      reference parameters: MyVector object
     *      stream: none
     */
    MyList <T>& operator = (const MyList&);

    /**
     * pushFront
     *
     * add data element e to the front of the vector
     *
     * Parameters:
     *      n: value of type T
     *
     * Output:
     *      return: reference to self
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& pushFront(T);

    /**
     * pushBack
     *
     * add data element e to the back of the vector
     *
     * Parameters:
     *      n: value of type T
     *
     * Output:
     *      return: reference to self
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& pushBack(T);

    /**
     * popFront
     *
     * removes a data element from the front of the data structure
     *
     * Parameters:
     *      n: value of type T
     *
     * Output:
     *      return: reference to self
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& popFront(T&);

    /**
     * popBack
     *
     * removes a data element from the end of the data structure
     *
     * Parameters:
     *      n: value of type T
     *
     * Output:
     *      return: reference to self
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& popBack(T&);

    /**
     * getSize
     *
     * returns a the size of MyList
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: int
     *      reference parameters: none
     *      stream: none
     */
    int getSize();

    /**
     * isEmpty
     *
     * returns if the size of MyList is 0 or not
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: bool
     *      reference parameters: none
     *      stream: none
     */
    bool isEmpty();

    /**
     * front
     *
     * returns a copy of the first data item in the MyList
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: type T
     *      reference parameters: none
     *      stream: none
     */
    T front();

    /**
     * back
     *
     * returns a copy of the last data item in the MyList
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: type T
     *      reference parameters: none
     *      stream: none
     */
    T back();

    /**
     * operator[]
     *
     * returns a reference to data element n in MyList
     *
     * Parameters:
     *      n: int
     *
     * Output:
     *      return: return type T
     *      reference parameters: none
     *      stream: none
     */
    T& operator [](int);

    /**
     * erase
     *
     * deletes all variables of MyList
     *
     * Parameters:
     *      none
     *
     * Output:
     *      return: bool
     *      reference parameters: none
     *      stream: none
     */
    void erase();

protected:
    Node<T> *head;
};

template <class T>
MyList<T>::MyList(){
    this->head = nullptr;
}

template <class T>
MyList<T>::~MyList(){
    Node<T> *temp;
    while(this->head != nullptr){
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

template <class T>
MyList<T>::MyList(const MyList& that){
    //need to set head to nullptr
    this->head = nullptr;
    if(that.head != nullptr){
        this->head = new Node<T>(that.head->data);
        Node<T> *temp = that.head->next;
        Node<T> *thisTemp = this->head;
        while(temp != nullptr){
            thisTemp->next = new Node<T>(temp->data);
            thisTemp = thisTemp->next;
            temp = temp->next;
        }
    }

}

template <class T>
MyList <T>& MyList<T>:: operator = (const MyList& that){
    if(this->head != that.head){
        this->erase();
        this->head = nullptr;
        if(that.head != nullptr){
            this->head = new Node<T>(that.head->data);
            Node<T> *thisTemp = this->head;
            Node<T> *thatTemp = that.head->next;

            while(thatTemp != nullptr){
                thisTemp->next = new Node<T>(thatTemp->data);
                thisTemp = thisTemp->next;
                thatTemp = thatTemp->next;
            }
        }
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushFront(T t){
    //if list is empty
    if(this->head == nullptr){
        this->head = new Node<T>(t);
        this->head->data = t;
        this->head->next = nullptr;
    }
    else {
        Node<T> *temp = new Node<T>(t);
        temp->data = t;
        temp->next = this->head;
        this->head = temp;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushBack(T t){
    //if list is empty
    if(this->head == nullptr){
        this->head = new Node<T>(t);
        this->head->data = t;
        this->head->next = nullptr;
    }
    else{
        Node<T> *temp1 = this->head;
        while(temp1->next != nullptr){
            temp1 = temp1->next;
        }
        Node<T> *temp2 = new Node<T>(t);
        temp2->data = t;
        temp2->next = nullptr;
        temp1->next = temp2;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::popFront(T& t){
    //if list is empty
    if(this->head == nullptr){
        throw BADINDEX();
    }
    Node<T> *temp = this->head;
    t = this->head->data;
    this->head = this->head->next;
    delete temp;
    return *this;
}

template <class T>
MyList <T>& MyList<T>::popBack(T& t){
    //if list is empty
    if(this->head == nullptr){
        throw BADINDEX();
    }
    Node<T> *temp1 = this->head;

    //if list has one item
    if(temp1->next == nullptr){
        t = temp1->data;
        delete temp1;
        this->head = nullptr;
    }
    else{
        while(temp1->next->next != nullptr){
            temp1 = temp1->next;
        }
        t = temp1->next->data;
        delete temp1->next;
        temp1->next = nullptr;
    }
    return *this;
}

template <class T>
int MyList<T>::getSize(){
    int size = 0;
    Node<T> *temp = this->head;
    while(temp != nullptr){
        ++size;
        temp = temp->next;
    }
    return size;
}

template <class T>
bool MyList<T>::isEmpty(){
    return this->head == nullptr;
}

template <class T>
T MyList<T>::front(){
    //if list is empty
    if(this->head == nullptr){
        throw BADINDEX();
    }

    return this->head->data;
}

template <class T>
T MyList<T>::back(){
    //if list is empty
    if(this->head == nullptr){
        throw BADINDEX();
    }
    Node<T> *temp = this->head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
T& MyList<T>::operator [](int ndx){
    //if list is empty or index is out of bounds
    if(ndx >= this->getSize() || isEmpty()){
        throw BADINDEX();
    }
    Node<T> *temp = this->head;
    for(int i = 0; i < ndx; ++ i){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void MyList<T>::erase(){
    Node<T> *temp;

    while(this->head != nullptr){
        temp = this->head;
        this->head = this->head->next;

        delete temp;
    }
}

#endif
