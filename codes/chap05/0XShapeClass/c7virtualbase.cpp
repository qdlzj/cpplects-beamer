// 例05-c7：ex05-c7.cpp
// 虚继承和多重继承的示例

#include <iostream>
#include <cstring>

using namespace std;

class CAnimal
{
    char name[32];
    int age;
    int weight;
public:
    CAnimal(const char *strName = "", int a = 0, int w = 0)
    {
        strcpy(name, strName);
        age = a;
        weight = w;
        cout << "Animal constructor " << name << endl;
    }
    void Show()
    {
        cout << name << " " << age << " " << weight << endl;
    }
    ~CAnimal()
    {
        cout << "Animal destructor " << name << endl;
    }
};

class CBird: virtual public CAnimal
{
    int wingSpan;
public:

    CBird(int ws = 0, const char *strName = "", int a = 0, int w = 0): CAnimal(strName, a, w)
    {
        wingSpan = ws;
        cout << "Bird constructor " << endl;
    }
    void Show()
    {
        CAnimal::Show();
        cout << "Wingspan:" << wingSpan << endl;
    }
    void Fly()
    {
        cout << "I can fly! I can fly!!" << endl;
    }
    void Talk()
    {
        cout << "Chirp..." << endl;
    }
    ~CBird()
    {
        cout << "Bird destructor " << endl;
    }
};

class CHorse: virtual public CAnimal
{
    int power;
public:
    CHorse(int pow = 0, const char *strName = "", int a = 0, int w = 0): CAnimal(strName, a, w)
    {
        power = pow;
        cout << "Horse constructor " << endl;
    }
    void Show()
    {
        CAnimal::Show();
        cout << "Power:" << power << endl;
    }
    void Run()
    {
        cout << "I can run! I run because I love to!!" << endl;
    }
    void Talk()
    {
        cout << "Whinny!..." << endl;
    }
    ~CHorse()
    {
        cout << "Horse destructor "  << endl;
    }
};

class CPegasus : public CHorse, public CBird
{
public:
    CPegasus(const char *strName = "", int a = 0, int w = 0, int ws = 0, int pow = 0):
        CAnimal(strName, a, w),
        CHorse(pow, strName, a, w), CBird(ws, strName, a, w)
    {
        cout << "Pegasus constructor" << endl;
    }
    void Show()
    {
        CBird::Show();
        CHorse::Show();
    }
    void Talk()
    {
        CHorse::Talk();
    }
    ~CPegasus()
    {
        cout << "Pegasus destructor" << endl;
    }
};

int main()
{
    CPegasus pegObj("Pegasus", 5, 800, 2, 10000);
//
//    pegObj.Show();
//    pegObj.Fly();
//    pegObj.Run();
//    pegObj.Talk();

    return 0;
}

