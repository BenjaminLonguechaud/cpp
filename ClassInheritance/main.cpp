
#include<iostream>
#include <string>

using namespace std;

class Pet {
protected:
  string Name;
public:
  Pet(string n) { Name = n;  MakeVirtualSound();  }
  void Run(void) {
    cout << Name << ": I'm running" << endl;
  }
  void MakeSound(void) { cout << Name << ": Shh! Shh!" << endl; }
  virtual void MakeVirtualSound(void) { cout << Name << ": Virtual Shh! Shh!" << endl; }
  void WakeUp() { MakeVirtualSound(); }
};

class Dog : public Pet {
public:
  Dog(string n) : Pet(n) {};
  void MakeSound(void) { cout << Name << ": Woof! Woof!" << endl; }
  void MakeVirtualSound(void) { cout << Name << ": Virtual Woof! Woof!" << endl; }
  void dogStuff() {};
};

class Cat : public Pet {
public:
  Cat(string n) : Pet(n) {};
  void MakeSound(void) { cout << Name << ": Meow! Meow!" << endl; }
  void MakeVirtualSound(void) { cout << Name << ": Virtual Meow! Meow!" << endl; }
  void catStuff() {};
};

class X {
public:
  virtual void shout() { std::cout << "X" << endl; }
};

class Y : public X {
public:
  void shout() { std::cout << "Y" << endl; }
};

class Z : public Y {
public:
  void shout() { std::cout << "Z" << endl; }
};

class A {
  int* val;
  const int constField;
public:
  A() : constField(0) {
    val = new int; *val = 0;
  }
  /*A(A&a) : constField(0) {
    val = new int;
    *val = a.getVal();
  }*/
  void inc() {
    (*val)++;
  }
  int getVal() {
    return ++(*val);
  }
};

class Compo {
public:
  // Defining your own copying constructor means you assume full responsibility for all the
  // activities needed to carry out responsible copying.
  Compo(Compo &src) : f1("DefaultDog"), f2("DefaultCat") { cout << "Copying Compo..." << endl; }
  Compo(void) : f1("DefaultDog"), f2("DefaultCat") { };
  Dog f1;
  Cat f2;
};

void PlayWithPet(Pet &pet) {
  try {
    dynamic_cast<Dog &>(pet).dogStuff();
    cout << "Dynamic cast successful" << endl;
  }
  catch (...) {
    cout << "Dynamic cast error" << endl;
  }
}

int main() {

  // Evaluation and print one at a time
  A a, b = a;
  cout << a.getVal();
  cout << b.getVal() << endl;

  // d.getVal() evaluated first !
  A c, d = c;
  cout << c.getVal() << d.getVal() << endl;

  // Returns Z
  Z*z = new Z();
  dynamic_cast<Y*>(z)->shout();

  /**
   * static_cast: the compiler isn’t able to check if the pointer being converted is
   * compatible with the object it points to. The compiler is forced to recognize the pointer as valid.
   * Full pointer validity verification is possible when and only when the program is being executed.
   * The C++ language has a second conversion operator designed especially for this case: dynamic_cast
   */
  cout << "-- Static cast" << endl;
  Pet *a_pet1 = new Cat("Tom");
  Pet *a_pet2 = new Dog("Spike");
  a_pet1->Run();
  static_cast<Cat*>(a_pet1)->MakeSound();

  /**
   * When a subclass declares a method of the name previously known in its superclass, the original method is overridden.
   * The effects of the overriding may be reversed (or voided) if you use the static_cast operator in reverse.
   * The uppercasting unhides the original implementation of the MakeSound method.
   */
  cout << "-- Static cast 2" << endl;
  Cat *a_cat;
  Dog *a_dog;
  Pet *a_pet;
  a_cat = new Cat("Kitty");
  a_dog = new Dog("Doggie");
  a_cat->MakeSound();
  static_cast<Pet *>(a_cat)->MakeSound();
  a_pet = a_cat;
  a_pet->MakeSound();

  /**
   * Polymorphism is the ability to realize class behaviour in multiple ways.
   * "virtual" means that the method won’t be overridden within any of the possible subclasses.
   * It also means that the method will be redefined (replaced) at the level of the original class.
   *
   * The binding between the origin of the virtual function and its replacement is created dynamically,
   * during the execution of the program.
   */
  cout << "-- Virtual function" << endl;
  a_pet = a_cat = new Cat("Kitty");
  a_pet->MakeSound();
  a_pet->MakeVirtualSound();
  a_cat->MakeSound();
  a_cat->WakeUp();

  /**
   * Dynamic cast
   */
  cout << "-- Dynamic cast" << endl;
  PlayWithPet(*a_dog);
  PlayWithPet(*a_cat);

  /**
   * Copying a class only copy it's element.
   * For arrays/pointer, we are in charge of copying
   */
  A* a_1 = new A;
  A a_2(*a_1);
  a_1->inc();
  a_2.inc();
  cout << "Access created class:" << a_1->getVal() << endl;
  cout << "Access copied class:" << a_2.getVal() << endl;

  /**
   * Const
   */
  int arr[5] = { 1, 2, 4, 8, 16 };
  // Pointers to constants
  const int *ptrToConst = arr + 2;
  // Constant pointers
  int * const constToPtr = arr + 2;
  // Constant pointers to constants
  const int * const constPtrtoConst = arr + 2;

  return 1;
}