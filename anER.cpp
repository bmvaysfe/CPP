#include<iostream>
#include<cstring>

class Animal
{
public:
    virtual void talk() const = 0;
};

class Mouse : public Animal
{
public:
    void talk() const { std::cout << "squeak! "; }
};

class Horse : public Animal
{
public:
    void talk() const { std::cout << "neigh! "; }
};

class Cat : public Animal
{
public:
    void talk() const { std::cout << "meow! "; }
};

class Dog : public Animal
{
public:
    void talk() const { std::cout << "woof! "; }
};

Animal *CreateAnimal(const char *animal)
{
    if(strcmp(animal, "mouse") == 0)
        return new Mouse;
    else if (strcmp(animal, "horse") == 0)
        return new Horse;
    else if (strcmp(animal, "cat") == 0)
        return new Cat;
    else if (strcmp(animal, "dog") == 0)
        return new Dog;
    return 0;
}

int main(int argc, char **argv)
{
    CreateAnimal("dog")->talk();
    CreateAnimal("cat")->talk();
    CreateAnimal("horse")->talk();
    CreateAnimal("mouse")->talk();
    return 0;
}

//  woof! meow! neigh! squeak!
