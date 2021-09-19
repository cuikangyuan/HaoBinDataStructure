#include<iostream>
using namespace std;

class Man {
    private:
        int age;
    public:
        Man();
        Man(int age);
        ~Man();
        void setAge(int age);
        int getAge(); 
};

void Man::setAge(int age) { 
    this->age = age;
}

int Man::getAge() { 
    return this->age;
}

Man::Man(int age) {
    this->age = age;
    cout << "Man class constructor called" << endl;
    //printf("Man class constructor called");
}

Man::~Man() {
    //printf("Man class destructor called");
    cout << "Man class destructor called" << endl;
}

 
int main(void)
{


    //Man man1;
    Man * man1 = new Man(123);
    cout << "man1'age: " << man1->getAge() << endl; 
    delete man1;
    
    return 0;
}