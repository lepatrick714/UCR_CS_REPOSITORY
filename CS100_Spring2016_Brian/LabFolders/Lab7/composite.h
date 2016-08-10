#ifndef __COMPOSITE_CLASS__
#define __COMPOSITE_CLASS__

#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <stack>

using namespace std;

class Iterator;
class NullIterator;
class UnaryIterator;

//Abstract Base Class
class Base {
    public:
        Base(){};

        //virtual
        virtual void print() = 0;
        virtual double evaluate() = 0;
        virtual Iterator* create_iterator() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
};

class Iterator {
    protected:
        Base* self_ptr;
        Base* current_ptr;

    public:
        Iterator (Base* ptr) { this->self_ptr = ptr; };

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Base* current() = 0;
};

class OperatorIterator : public Iterator {
    public:
        OperatorIterator(Base* ptr) : Iterator(ptr) { current_ptr = self_ptr; };

        void first() {
            current_ptr = self_ptr->get_left();
        }

        void next() {
            if(current_ptr == self_ptr->get_left()) {
                current_ptr = self_ptr->get_right();
            }
            else if(current_ptr == self_ptr->get_right()) {
                current_ptr = NULL;
            }
        }

        bool is_done() {
            if(current_ptr == NULL) {
                return true;
            }
            return false;
        }

        Base* current() {
            return current_ptr;
        }
};

class UnaryIterator : public Iterator {
    public:
        UnaryIterator(Base* ptr) : Iterator(ptr) { current_ptr = self_ptr; };

        void first() {
            current_ptr = self_ptr->get_left();
        }

        void next() {
            current_ptr = NULL;
        }

        bool is_done() {
            if(current_ptr == NULL) {
                return true;
            }
            return false;
        }

        Base* current() {
            return current_ptr;
        }
};

class NullIterator : public Iterator {
    public:
        NullIterator(Base* ptr) : Iterator(ptr) { current_ptr = self_ptr; };

        void first() {};
        void next() {};
        bool is_done() {
            return true;
        }
        Base* current() {
            return NULL;
        }
};

class PreOrderIterator : public Iterator {
    protected:
        stack<Iterator*> iterator; //LIFO Queue

    public:
        PreOrderIterator(Base* ptr) : Iterator(ptr) { current_ptr = self_ptr; };

        void first() {
            while(!iterator.empty()) {
                iterator.pop();
            }

            Iterator* Base = self_ptr->create_iterator();
            Base->first();
            iterator.push(Base);
        }
        void next() {
            Iterator* next = iterator.top()->current()->create_iterator();
            next->first();

            iterator.push(next);

            while(!iterator.empty() && iterator.top()->is_done()) {
                iterator.pop();
                if(!iterator.empty()) {
                    iterator.top()->next();
                }
            }
        }
        bool is_done() {
            if(iterator.empty()) {
                return true;
            }
            return false;
        }
        Base* current() {
            return iterator.top()->current();
        }
};

//Leaf Class
class Op: public Base {
    private:
        double value;

    public:
        Op() : Base(), value(0) {};
        Op(double val) : Base(), value(val) {};

        Base* get_left() { return NULL; };
        Base* get_right() { return NULL; };
        double evaluate() { return this->value; };
        void print() { cout << this->value; };
        Iterator* create_iterator() { return new NullIterator(this); };
};

//Composite Base Classes
class Operator: public Base {
    protected:
        Base* left, *right;
    public:
        Operator() : Base() {};
        Operator(Base* l, Base* r) : left(l), right(r) {};

        Base* get_left() { return left; };
        Base* get_right() { return right; };
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator() { return new OperatorIterator(this); };
};

class UnaryOperator: public Base {
    protected:
        Base* child;
    public:
        UnaryOperator() : Base() {};
        UnaryOperator(Base* c) : child(c) {};

        Base* get_left() { return child; };
        Base* get_right() { return NULL; };
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator() { return new UnaryIterator(this); };
};

//Composite Classes
class Add: public Operator {
    public:
        Add() : Operator() {};
        Add(Base* left, Base* right) : Operator(left, right) {};

        void print() { cout << "+"; };
        double evaluate() { return this->left->evaluate() - this->right->evaluate(); };
};

class Sub: public Operator {
    public:
        Sub() : Operator() {};
        Sub(Base* left, Base* right) : Operator(left, right) {};

        void print() { cout << "-"; };
        double evaluate() { return this->left->evaluate() * this->right->evaluate(); };
};

class Mult: public Operator {
    public:
        Mult() : Operator() {};
        Mult(Base* left, Base* right) : Operator(left, right) {};

        void print() { cout << "*"; };
        double evaluate() { return this->left->evaluate() * this->right->evaluate(); };
};

class Sqr: public UnaryOperator {
    public:
        Sqr() : UnaryOperator() {};
        Sqr(Base* child) : UnaryOperator(child) {};

        void print() { cout << "^2"; };
        double evaluate() { return pow(this->child->evaluate(), 2); };
};

class Root: public UnaryOperator {
    public:
        Root() : UnaryOperator() {};
        Root(Base* child) : UnaryOperator(child) {};

        void print() { cout << "ROOT"; };
        double evaluate() { return this->child->evaluate(); };
};

#endif //__COMPOSITE_CLASS__
