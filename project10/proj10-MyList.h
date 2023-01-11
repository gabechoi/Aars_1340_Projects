/**
 * file: proj10-MyList.h
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: project 10
 * due date: 12/5/2022
 *
 * date modified: 12/1/2022
 *      - code created
 *
 * date modified: 12/4/2022
 *      - all functions created
 *
 */

#ifndef PROJ10_1_PROJ10_MYLIST_H
#define PROJ10_1_PROJ10_MYLIST_H

#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"

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

private:
    Node<T> *head;
    Node<T> *tail;
};

template <class T>
MyList<T>::MyList(){
    this->head = nullptr;
    this->tail = nullptr;
}


template <class T>
MyList<T>::~MyList(){

    this->erase();
}

template <class T>
MyList<T>::MyList(const MyList& that){
    //need to set head to nullptr
    if(that.head == nullptr){
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        this->head = new Node<T>(that.head->data);
        Node<T> *temp = that.head;
        this->tail = this->head;
        while(temp->next != nullptr){
            temp = temp->next;
            this->tail->next = new Node<T>(temp->data);
            this->tail = this->tail->next;
        }
    }

}

template <class T>
MyList <T>& MyList<T>:: operator = (const MyList& that){
    this->erase();
    if(this->head != that.head){
        if(that.head == nullptr){
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            this->head = new Node<T>(that.head->data);
            Node<T> *temp = that.head;
            this->tail = this->head;
            while(temp->next != nullptr){
                temp = temp->next;
                this->tail->next = new Node<T>(temp->data);
                this->tail = this->tail->next;
            }
        }
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushFront(T t){
    //if list is empty
    Node<T> *temp = new Node<T>(t);
    if(this->head == nullptr){
        this->head = temp;
        this->tail = temp;
        //this->head->next = nullptr;
    }
    else {
        temp->next = this->head;
        this->head = temp;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushBack(T t){
    //if list is empty
    Node<T> *temp = new Node<T>(t);
    if(this->head == nullptr){
        this->head = temp;
        this->tail = temp;
        //this->head->next = nullptr;
    }
    else if(this->head->next == nullptr){
        this->head->next = this->tail;
        this->tail->next = temp;
        this->tail = this->tail->next;
        //this->tail->next = nullptr;
    }
    else{
        this->tail->next = temp;
        this->tail = this->tail->next;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::popFront(T& t){
    if(this->head == nullptr){
        throw BADINDEX();
    }
    t = this->head->data;
    Node<T> *temp = this->head;

    if(this->head->next == nullptr){
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        this->head = this->head->next;
    }
    delete &temp->data;
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
    if(this->head->next == nullptr){
        t = this->head->data;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else{
        Node<T> *temp2;
        while(temp1->next != nullptr){
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = nullptr;
        this->tail = temp2;
    }
    delete &temp1->data;
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

    return this->tail->data;
}

template <class T>
T& MyList<T>::operator [](int ndx){
    //if list is empty or index is out of bounds
    if(ndx >= this->getSize() || isEmpty()){
        throw BADINDEX();
    }
    Node<T> *temp = this->head;
    for(int i = 0; i < ndx; ++i){
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
    this->tail = this->head;
}

#endif //PROJ10_1_PROJ10_MYLIST_H
