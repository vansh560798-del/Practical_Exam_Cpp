#include <iostream>
using namespace std;

class Animal{
private:
    string name;
    string sound;

public:
    void setName(string n){
        name = n;
    }

    void setSound(string s){
        sound = s;
    }

    string getName(){
        return name;
    }

    string getSound(){
        return sound;
    }

    virtual void displayDetails(){
        cout << "Animal: " << name << endl;
        cout << "Sound: " << sound << endl;
    }
};

class Dog : public Animal{
public:
    void displayDetails() override{
        cout << "Dog: " << getName() << endl;
        cout << "Sound: " << getSound() << endl;
    }
};

class Cat : public Animal{
public:
    void displayDetails() override{
        cout << "Cat: " << getName() << endl;
        cout << "Sound: " << getSound() << endl;
    }
};

int main(){
    Dog dog;
    Cat cat;

    dog.setName("Tommy");
    dog.setSound("Woof Woof");

    cat.setName("Kitty");
    cat.setSound("Meow Meow");

    Animal* animals[2];

    animals[0] = &dog;
    animals[1] = &cat;

    cout << "--- Animal Details ---" << endl;

    for (int i = 0; i < 2; i++){
        animals[i]->displayDetails();
        cout << endl;
    }
    return 0;
}