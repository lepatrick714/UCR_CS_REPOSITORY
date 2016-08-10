#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

class Base  {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};

class CompositeOne : public Base {
    public:
        Base* data;

        CompositeOne(Base* data) {
            this->data = data;
        }
};

class CompositeTwo : public Base {
    public:
        Base* data1;
        Base* data2;

        CompositeTwo(Base* data1, Base* data2) {
            this->data1 = data1;
            this->data2 = data2;
        }

};

class Op : public Base  {
    private:
        double data;

    public:
        Op(double data) {
            this->data = data;
        }

        double getData() {
            return data;
        }

        double evaluate() {
            return data;
        }
};

class Mult : public CompositeTwo {
    public:
        Mult(Base* data1, Base* data2) : CompositeTwo(data1, data2) {}

        double evaluate() {
            return data1->evaluate()*data2->evaluate();
        }
};

class Div : public CompositeTwo  {
    public:
        Div(Base* data1, Base* data2) : CompositeTwo(data1, data2) {}

        double evaluate() {
            return data1->evaluate()/data2->evaluate();
        }
};

class Add : public CompositeTwo {
    public:
       Add(Base* data1, Base* data2) : CompositeTwo(data1, data2) {}

       double evaluate() {
            return data1->evaluate()+data2->evaluate();
       }
};

class Sub : public CompositeTwo {
    public:
        Sub(Base* data1, Base* data2) : CompositeTwo(data1, data2) {}

        double evaluate() {
            return data1->evaluate()-data2->evaluate();
        }
};

class Sqr : public CompositeOne {
    public:
        Sqr(Base* data) : CompositeOne(data) {}

        double evaluate() {
            return data->evaluate()*data->evaluate();
        }
};

class Abs : public CompositeOne {
    public:
        Abs(Base* data) : CompositeOne(data) {}

        double evaluate() {
            return abs(data->evaluate());
        }
};

class Floor : public CompositeOne {
    public:
        Floor(Base* data) : CompositeOne(data) {}

        double evaluate() {
            return floor(data->evaluate());
        }
};

class Ceiling : public CompositeOne {
    public:
        Ceiling(Base* data) : CompositeOne(data) {}

        double evaluate() {
            return ceil(data->evaluate());
        }
};

class Sort;

class Container {
    protected:
        Sort* sort_function;

    public:
        Container() : sort_function(NULL) {};
        Container(Sort* function) : sort_function(function) {};

        void set_sort_function(Sort* sort_function);

        virtual void add_element(Base* element) = 0;
        virtual void print() = 0;
        virtual void sort() = 0;

        virtual void swap(int i, int j) = 0;
        virtual Base* at(int i) = 0;
        virtual int size() = 0;
};

class Sort {
    public:
        Sort(){};

        virtual void sort(Container* container) = 0;
};

class SelectionSort : public Sort {
    public:
    SelectionSort() : Sort() {};

    void sort(Container *container) {
        for(int i=0; i<container->size(); i++) {
            int lowest = i;
            for(int j=i+1; j<container->size(); j++) {
                if(container->at(i)->evaluate() > container->at(j)->evaluate())
                    lowest = j;
            }
            if(lowest != i)
                container->swap(i, lowest);
        }
    }
};

class BubbleSort : public Sort {
    public:
    BubbleSort() : Sort() {};

    void sort(Container *container) {
        for(int i=0; i<container->size(); i++) {
            for(int j=0; j<container->size()-i-1; j++) {
                if(container->at(j)->evaluate() > container->at(j+1)->evaluate()) {
                    container->swap(j, j+1);
                }
            }
        }
    }
};


class VectorContainer : public Container {
    private:
        vector<Base* > a;

    public:
        VectorContainer() : Container() {};
        VectorContainer(Sort* function) : Container(function) {};

        void set_sort_function(Sort* sort_function)
        {
            this->sort_function = sort_function;
        }

        void add_element(Base* element) {
            a.push_back(element);
        }

        void print() {
            for(unsigned i=0; i<a.size(); i++) {
                cout << a.at(i)->evaluate() << " ";
            }
            cout << endl;
        }

        void sort() {
            sort_function->sort(this);
        }

        void swap(int i, int j) {
            Base* temp = a.at(i);
            a.at(i) = a.at(j);
            a.at(j) = temp;
        }

        Base* at(int i) {
            return a.at(i);
        }

        int size() {
            return a.size();
        }
};

class ListContainer : public Container {
    private:
        list<Base* > a;

    public:
        ListContainer() : Container() {};
        ListContainer(Sort* function) : Container(function) {};

        void set_sort_function(Sort* sort_function)
        {
            this->sort_function = sort_function;
        }

        void add_element(Base* element) {
            a.push_back(element);
        }

        void print() {
            for(list<Base* >::iterator i=a.begin(); i!=a.end(); i++)
            {
                cout << (*i)->evaluate() << " ";
            }
            cout << endl;
        }

        void sort() {
            sort_function->sort(this);
        }

        void swap(int i, int j) {
            list<Base* >::iterator temp1 = a.begin();
            list<Base* >::iterator temp2 = a.begin();

            int ctr=0;
            while(ctr < i) {
                temp1++;
                ctr++;
            }
            ctr=0;
            while(ctr < j) {
                temp2++;
                ctr++;
            }

            Base* temp3 = *temp1;
            *temp1 = *temp2;
            *temp2 = temp3;
        }

        Base* at(int i) {
            int ctr = 0;
            list<Base *>::iterator temp=a.begin();
            while(ctr < i) {
                temp++;
                ctr++;
            }
            return *temp;
        }

        int size() {
            return a.size();
        }
};


int main(int argc, char**argv)  {
    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    Op* op3 = new Op(3);
    iu
    Op* op2 = new Op(2);
    Op* op10 = new Op(10);

    Mult* A = new Mult(op7,op4);
    Add* B = new Add(op3,A);
    Sub* C = new Sub(B,op2);
    Sqr* D = new Sqr(C);
    Mult* E = new Mult(op3, op10);

    //Testing the DecoratorLab
    Op* a = new Op(7.1);
    Op* b = new Op(-4.5);

    Mult* F = new Mult(a, b);
    Abs* abs = new Abs(F);
    Floor* floor = new Floor(F);
    Ceiling* ceiling = new Ceiling(F);

    cout << "7.1 * -4.5 = " << F->evaluate() << endl;
    cout << "Testing Abs(): " << abs->evaluate() << endl;
    cout << "Testing Floor(): " << floor->evaluate() << endl;
    cout << "Testing Ceiling(): " << ceiling->evaluate() << endl;
    VectorContainer* vectorContainer = new VectorContainer();



    /*Testing the CompositeLab
    VectorContainer* vectorContainer = new VectorContainer();
    vectorContainer->add_element(A);
    vectorContainer->add_element(B);
    vectorContainer->add_element(C);
    vectorContainer->add_element(D);
    vectorContainer->add_element(E);
    ListContainer* listContainer = new ListContainer();
    listContainer->add_element(A);
    listContainer->add_element(B);
    listContainer->add_element(C);
    listContainer->add_element(D);
    listContainer->add_element(E);
    //Start of test cases
    //Test #1: printing both VectorContainer* and ListContainer*
    cout << "Test #1: Printing" << endl;
    cout << "Printing vectorContainer*" << endl;
    vectorContainer->print();
    cout << "Printing listContainer*" << endl;
    listContainer->print();
    cout << "-----------End of Test-----------\n" << endl;
    //Test #2: SelectionSort()
    cout << "Test #2: SelectionSort()" << endl;
    cout << "vectorContainer Before SelectionSort" << endl;
    vectorContainer->print();
    cout << "vectorContainer After SelectionSort" << endl;
    vectorContainer->set_sort_function(new SelectionSort());
    vectorContainer->sort();
    vectorContainer->print();
    cout << endl;
    cout << "listContainer Before SelectionSort" << endl;
    listContainer->print();
    cout << "listContainer After SelectionSort" << endl;
    listContainer->set_sort_function(new SelectionSort());
    listContainer->sort();
    listContainer->print();
    cout << "-----------End of Test-----------\n" << endl;
    //Test #3: BubbleSort()
    VectorContainer* vectorContainer2 = new VectorContainer();
    vectorContainer2->add_element(A);
    vectorContainer2->add_element(B);
    vectorContainer2->add_element(C);
    vectorContainer2->add_element(D);
    vectorContainer2->add_element(E);
    ListContainer* listContainer2 = new ListContainer();
    listContainer2->add_element(A);
    listContainer2->add_element(B);
    listContainer2->add_element(C);
    listContainer2->add_element(D);
    listContainer2->add_element(E);
    cout << "Test #3: BubbleSort()" << endl;
    cout << "vectorContainer Before BubbleSort()" << endl;
    vectorContainer2->print();
    cout << "vectorContainer After BubbleSort()" << endl;
    vectorContainer2->set_sort_function(new BubbleSort());
    vectorContainer2->sort();
    vectorContainer2->print();
    cout << endl;
    cout << "listContainer Before BubbleSort" << endl;
    listContainer2->print();
    cout << "listContainer After BubbleSort" << endl;
    listContainer2->set_sort_function(new BubbleSort());
    listContainer2->sort();
    listContainer2->print();
    cout << "-----------End of Test-----------\n" << endl;
    */
    return 0;
}
