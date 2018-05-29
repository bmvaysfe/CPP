// ER.cpp
// Test for GS intermediate developer position
// 02.14.10
// Set up by Patricia Lee, Eric Robert, Inc.


#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;


void inh1()
{
class Animal
{
public:

    virtual const char *name_a() const { return "animal"; }
    const char         *name_b() const { return "animal"; }
};

class Mouse : public Animal
{
public:
    const char *name_a() const { return "mouse"; }
    const char *name_b() const { return "mouse"; }
};


    Animal *a = new Mouse;
    printf("a: %-10s b: %-10s c: %-10s d: %-10s\n", 
           a->name_a(), 
           a->name_b(), 
           ((Mouse *)a)->name_a(),
           ((Mouse *)a)->name_b());

//            ((Animal *)a)->name_a(),  // Mouse - name_a() is virtual 
//           ((Animal *)a)->name_b());    //  Animal - name_b() is not virtual 
}
//  a: mouse b: animal c: mouse d: mouse
//  Mouse is a derived class here

void incrdecr()
{
    int i = 5;
    std::cout << ++i << " ";
    std::cout << i++ << " ";
    std::cout << --i << " ";
    std::cout << i-- << std::endl;
}

void test_cast()
{
class A
{
public:
    virtual ~A() {}
};

class B : public A
{
};

class C : public A
{
};



    const A *ca = new C;
#if 0
    C *cast1 = reinterpret_cast<C *>(ca);  // cast #1 - INVALID 69 E:\CPP\ER.cpp reinterpret_cast from type `const test_cast()::A*' to type `test_cast()::C*' casts away constness 

    A *cast2 = reinterpret_cast<A *>(ca);  // cast #2 - INVALID 71 E:\CPP\ER.cpp reinterpret_cast from type `const test_cast()::A*' to type `test_cast()::A*' casts away constness 

    C *cast3 = const_cast<C *>(ca);        // cast #3 - invalid cast: from 73 E:\CPP\ER.cpp invalid const_cast from type `const test_cast()::A*' to type `test_cast()::C*' 
#endif
    A *cast4 = const_cast<A *>(ca);        // cast #4, OK

}

void inh2()
{
class ClassA
{
public:
    virtual void execute() { printf("I like A! "); }
};

class ClassB : public ClassA
{
public:
    void execute() { printf("I like B! "); }
};

class ClassC : public ClassA
{
public:
    void execute() { printf("I like C! "); }
};

class ClassD : public ClassB, public ClassC
{
public:
};
#if 0
    ClassA *a = new ClassD;  // Doesn't compile, it has to be a virtual inheritance.
    a->execute();
#endif
     
}

template <typename T>
void function(T *a, size_t sz)
{
    T *l = a, *r = a + sz - 1, t;
    while (r > l) { t = *l; *l = *r; *r = t; l++; r--; }
}

void templ1()
{
    char s[] = "hello there";  // prints: ereht olleh
    function(s, strlen(s));
    printf("%s\n", s);
}


int mtolower(int cc)
{
    return tolower(cc);
}
    
void test_transform()
{
    string s("ASDLKXLldskfjalsdSDLKJFLKSDN");
    const char *cstr=s.c_str();
    char *cptr=0;
    char *cptr1=0;
    
    size_t n = s.find_first_of("abc", 0);
    cout<<"src = ["<<s<<"] length = "<<s.length()<<endl;
    cout<<"From position "<<n<<": "<<cstr+n<<endl;
    cptr=strchr(cstr, 'a');
    cout<<"Found: "<<*cptr<<" at "<<cptr-cstr <<endl;
    transform(s.begin() + n, s.end(), s.begin() + n, mtolower);
    cout<<"n = "<<n<<"\ts = ["<<s<<"]"<<endl;
    
#if 0    
    n = s.find_first_of("abc", 1);
    cout<<"src = ["<<s<<"] length = "<<s.length()<<endl;
    cout<<"From position "<<n<<": "<<cstr+n<<endl;
#endif    
}

void process(const char *s)
{
    while (*s)
    {
        switch (*s)
        {
        case 'A': printf("A");
        case 'B': printf("B");      continue;
        case 'C': printf("C");      break;
        default : printf("%c", *s); break;
        }
        s++;
    }
}

void test_switch()
{
    process("ABCDCBA");
}


int main(int argc, char**argv)
{
    inh1();
//    inh2();   // Doesn't compile; evil diamond requires virtual inheritance.

#if 0
    
    test_cast();
#endif
    templ1();

    
//    test_transform();         // Don't know why result has n=13;
//    test_switch();          // infinite loop
//    incrdecr();
    return 0;
}
