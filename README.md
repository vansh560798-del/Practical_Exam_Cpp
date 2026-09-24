# C++ Practice Exam(Q1 – Q5)

A collection of five C++ programs that demonstrate core **Object-Oriented Programming (OOP)** concepts: classes and objects, encapsulation, constructors, inheritance, polymorphism, and abstraction.

---

## Project Structure

```
.
├── Q1.cpp   # Book class, array of objects, input/output
├── Q2.cpp   # Person class, private data, constructor, getters/setters
├── Q3.cpp   # Animal base class, Dog and Cat derived classes, virtual functions
├── Q4.cpp   # Same as Q3 with an explicit #include <string>
├── Q5.cpp   # Abstract Shape class, Circle and Rectangle
└── README.md
```

---

## Concepts Covered

| Concept | Where it appears |
|---|---|
| Class and object | Q1, Q2, Q3, Q4, Q5 |
| Array of objects | Q1 |
| Encapsulation (private data + public methods) | Q2, Q3, Q4 |
| Constructor | Q2, Q5 |
| Getters and setters | Q2, Q3, Q4 |
| Dynamic memory (`new`) | Q2 |
| Inheritance | Q3, Q4, Q5 |
| Virtual functions and `override` | Q3, Q4, Q5 |
| Runtime polymorphism (base-class pointers) | Q3, Q4, Q5 |
| Abstract class / pure virtual functions | Q5 |

---

## How to Compile and Run

You need a C++ compiler such as **g++** (GCC) or **clang++**. C++11 or newer is required because the code uses the `override` keyword.

```bash
# Compile
g++ -std=c++11 Q1.cpp -o Q1

# Run
./Q1          # Linux / macOS
Q1.exe        # Windows
```

Repeat for the other files:

```bash
g++ -std=c++11 Q2.cpp -o Q2
g++ -std=c++11 Q3.cpp -o Q3
g++ -std=c++11 Q4.cpp -o Q4
g++ -std=c++11 Q5.cpp -o Q5
```
---

## Q1 – Book Records (Class and Array of Objects)

### Problem
Store and display details of multiple books entered by the user.

### Approach
- A `Book` class holds three public data members: `title`, `author`, and `publishedYear`.
- The user enters the number of books `n`.
- An array of `n` `Book` objects is created.
- A first loop reads the details of each book, and a second loop prints them.

### Class Design

```cpp
class Book {
public:
    string title;
    string author;
    int publishedYear;
};
```

### Key Concepts
- Defining a class with public members
- Creating an array of objects
- Reading input with `cin`
- Using `for` loops for input and output

### Sample Run

```
Enter number of books: 1
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

Enter details for Book 1:
Title: Hamlet
Author: Shakespeare
Published Year: 1603

--- Book Details ---
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

Book 1
Title: Hamlet
Author: Shakespeare
Published Year: 1603
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
```

### Things to Watch Out For
- `cin >> title` reads only **one word**. A title such as "The Great Gatsby" would be split across inputs. Use `getline(cin, title)` for multi-word input.
- `#include <string>` is not included explicitly (it usually works because `<iostream>` pulls it in, but it is best practice to add it).

##Screenshots
###Code
<img width="1552" height="982" alt="Q1-1" src="https://github.com/user-attachments/assets/76b91d7f-8821-4c32-bbb8-ed4bc8953000" />
<img width="1552" height="982" alt="Q1-2" src="https://github.com/user-attachments/assets/1b32491d-e276-4dd6-8117-37dd483f0b95" />

###Output
<img width="1552" height="982" alt="Q1-Output" src="https://github.com/user-attachments/assets/1886546c-eace-45c0-8464-b8056ff0b1a2" />

---

## Q2 – Person Details (Encapsulation and Constructors)

### Problem
Store and display details of multiple people using proper encapsulation.

### Approach
- The `Person` class keeps `name`, `age`, and `address` **private**.
- A parameterized **constructor** initializes the object.
- Public **setters** (`setName`, `setAge`, `setAddress`) modify the data and **getters** (`getName`, `getAge`, `getAddress`) read it.
- `display()` prints all details using the getters.
- In `main()`, an array of `Person*` pointers is created and each object is allocated with `new`.

### Class Design

```cpp
class Person {
private:
    string name;
    int age;
    string address;
public:
    Person(string n, int a, string addr);
    void setName(string n);   void setAge(int a);   void setAddress(string addr);
    string getName();         int getAge();         string getAddress();
    void display();
};
```

### Key Concepts
- **Encapsulation**: data is hidden, access is only through public methods
- **Constructor** with parameters
- **Getters and setters**
- **Dynamic allocation** with `new`
- Accessing members through a pointer with `->`

### Sample Run

```
Enter number of persons: 1

Enter details for Person 1:
Name: Riya
Age: 21
Address: Surat

--- Person Details ---
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

========= Person 1 =========
-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

Name: Riya
Age: 21
Address: Surat
```

### Things to Watch Out For
- **Memory leak:** objects created with `new` are never freed. Add a loop at the end of `main()`:
  ```cpp
  for (int i = 0; i < n; i++) delete persons[i];
  ```
- `cin >> address` reads only one word. Use `getline` for full addresses (remember to clear the newline with `cin.ignore()` first).
- There is no default constructor, so `Person p;` will not compile.

##Screenshots
###Code
<img width="1552" height="982" alt="Q2-1" src="https://github.com/user-attachments/assets/6de672ff-96ac-4e49-9810-2ccc38e671ca" />
<img width="1552" height="982" alt="Q2-2" src="https://github.com/user-attachments/assets/e2af581c-531f-43bd-8ec1-d005482eeb04" />

###Output
<img width="1552" height="982" alt="Q2-Output" src="https://github.com/user-attachments/assets/7fba18cc-8998-4a1d-b0c9-184a23075996" />

---

## Q3 – Animal Hierarchy (Inheritance and Polymorphism)

### Problem
Model animals with a common base class and show **runtime polymorphism** with `Dog` and `Cat`.

### Approach
- `Animal` is the base class with private `name` and `sound`, setters/getters, and a **virtual** `displayDetails()`.
- `Dog` and `Cat` inherit publicly from `Animal` and **override** `displayDetails()`.
- In `main()`, a `Dog` and a `Cat` are created and their addresses are stored in an array of `Animal*`.
- Looping over the array and calling `displayDetails()` runs the **correct derived version** for each object.

### Class Diagram

```
        +-----------+
        |  Animal   |
        |-----------|
        | -name     |
        | -sound    |
        | +virtual displayDetails() |
        +-----------+
           ^       ^
           |       |
      +------+   +------+
      | Dog  |   | Cat  |
      +------+   +------+
```

### Key Concepts
- **Inheritance** (`class Dog : public Animal`)
- **Virtual function** and the **`override`** specifier
- **Base-class pointer** pointing to derived objects (upcasting)
- **Runtime (dynamic) polymorphism**

### Output

```
--- Animal Details ---
Dog: Tommy
Sound: Woof Woof

Cat: Kitty
Sound: Meow Meow

```

### Things to Watch Out For
- `Animal` has no **virtual destructor**. This is harmless here (objects are on the stack), but if you delete a derived object through an `Animal*`, you get undefined behavior. Add `virtual ~Animal() {}`.
- `name` and `sound` are private, so derived classes must use the getters, which the code correctly does.

##Screenshots
###Code
<img width="1552" height="982" alt="Q3-1" src="https://github.com/user-attachments/assets/95f36c55-5dcb-4a60-a703-a4c72e637c21" />
<img width="1552" height="982" alt="Q3-2" src="https://github.com/user-attachments/assets/44fb399e-84ba-4d0f-a943-2ddbd34a5329" />
##Output
<img width="1552" height="982" alt="Q3-Output" src="https://github.com/user-attachments/assets/73de3325-c98f-4206-b80f-8ab6acbb73f5" />


---

## Q4 – Animal Hierarchy (with `<string>` header)

### Problem
Same as Q3: demonstrate inheritance and polymorphism with `Animal`, `Dog`, and `Cat`.

### What Is Different From Q3?
The only difference is the explicit include:

```cpp
#include <string>
```

This is the **correct and portable** way to use `std::string`. In Q3 it works only because `<iostream>` happens to include it on most compilers.

### Output
Identical to Q3:

```
--- Animal Details ---
Dog: Tommy
Sound: Woof Woof

Cat: Kitty
Sound: Meow Meow

```

##Screenshots
###Code
<img width="1552" height="982" alt="Q4-1" src="https://github.com/user-attachments/assets/91460f1f-fc86-4918-8511-be797dbc491b" />
<img width="1552" height="982" alt="Q4-2" src="https://github.com/user-attachments/assets/29cd29fc-4ecd-4c93-8c99-7b0fb778e574" />

###Output
<img width="1552" height="982" alt="Q4-Output" src="https://github.com/user-attachments/assets/0cbc1162-7d72-40de-b47c-4902eae2a6ca" />

---

## Q5 – Shapes (Abstract Class and Pure Virtual Functions)

### Problem
Design a shape hierarchy where every shape must provide its own `area()` and `draw()` behaviour.

### Approach
- `Shape` is an **abstract class**: it declares two **pure virtual functions** (`= 0`), so it cannot be instantiated.
- `Circle` (radius) and `Rectangle` (length, width) inherit from `Shape`, use constructors to set their data, and **must** implement `area()` and `draw()`.
- `main()` stores both objects in an array of `Shape*` and calls `area()` and `draw()` polymorphically.

### Class Design

```cpp
class Shape {
public:
    virtual void area() = 0;
    virtual void draw() = 0;
};
```

| Class | Data | Area formula |
|---|---|---|
| `Circle` | `radius` | 3.14 × r × r |
| `Rectangle` | `length`, `width` | length × width |

### Key Concepts
- **Abstraction** through an abstract base class
- **Pure virtual functions** that force derived classes to implement behaviour
- **Polymorphism** via `Shape*`
- Constructors initializing private members

### Output

With `Circle(5)` and `Rectangle(10, 5)`:

```
--- Shape Details ---
Area of Circle: 78.5
Drawing Circle

Area of Rectangle: 50
Drawing Rectangle

```

### Things to Watch Out For
- `area()` **prints** the result instead of **returning** it. A more reusable design is `virtual float area() = 0;` and printing in `main()`.
- Pi is hard-coded as `3.14`. Use `M_PI` from `<cmath>` or define a `const double PI = 3.14159265;`.
- Add a `virtual ~Shape() {}` destructor for safe cleanup through base pointers.

##Screenshots
###Code
<img width="1552" height="982" alt="Q5-1" src="https://github.com/user-attachments/assets/905cc088-519b-4bb5-a0f8-36d4cf13da13" />
<img width="1552" height="982" alt="Q5-2" src="https://github.com/user-attachments/assets/692df879-448a-42ab-b722-4f2470275aca" />

###Output
<img width="1552" height="982" alt="Q5-Output" src="https://github.com/user-attachments/assets/856ed3e1-f777-4246-8717-200286013de1" />

---

## Summary Table

| File | Topic | Main OOP Idea | Uses Input? | Polymorphism? |
|---|---|---|---|---|
| Q1 | Book records | Class + array of objects | Yes | No |
| Q2 | Person details | Encapsulation, constructor, `new` | Yes | No |
| Q3 | Animals | Inheritance + virtual functions | No | Yes |
| Q4 | Animals (with `<string>`) | Inheritance + virtual functions | No | Yes |
| Q5 | Shapes | Abstract class + pure virtual | No | Yes |

---
## Learning Outcomes

After going through these programs you should be able to:

- Define classes and create objects and arrays of objects
- Protect data with `private` members and expose it through getters and setters
- Write and use constructors
- Build class hierarchies with inheritance
- Use `virtual` and `override` to achieve runtime polymorphism
- Design abstract classes with pure virtual functions
---
**Made By Vansh Soni**
