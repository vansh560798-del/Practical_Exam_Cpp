#include <iostream>
using namespace std;

class Person{
private:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string addr){
        name = n;
        age = a;
        address = addr;
    }

    void setName(string n){
        name = n;
    }

    void setAge(int a){
        age = a;
    }

    void setAddress(string addr){
        address = addr;
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    string getAddress(){
        return address;
    }

    void display(){
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Address: " << getAddress() << endl;
    }
};

int main(){
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    Person* persons[n];

    for (int i = 0; i < n; i++){
        string name, address;
        int age;

        cout << "\nEnter details for Person " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Address: ";
        cin >> address;

        persons[i] = new Person(name, age, address);
    }

    cout << "\n--- Person Details ---\n";

    for (int i = 0; i < n; i++){
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n" << endl;
        cout << "========= Person " << i + 1 << " =========\n";
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n" << endl;
        persons[i]->display();
    }
    return 0;
}