# About DynamicVar
DynamicVar is a dynamic type for C++ that holds data in an internal std::string object. DynamicVar was created to facilitate conversions between types in UI, Databases and other services. It allow you to set a value as int, double, string, boolean and some others and get its value as well in various types.

DynamicVar contains some useful constructors and functions with overloads to facilitate the use of the class.

# TL;DR - How to use
example 1
```c++
    #include "DynamicVar.h"
    
    int main(){
        DynamicVar tmp("10");
        
        DynamicVar tmp2;
        tmp2.setInt(5);

        DynamicVar tmp3;
        tmp3.set<int>(5)
        
        DynamicVar result = tmp.getInd() + tmp2.getInt() + tmp3.get<int>();
        cout << "Total sum is " << result.getString() << endl;
        return 0;
    }

```

# Input and output types

Allowed input types for values are 'int', 'int64_t', 'double', 'string' and 'bool'

You can set the value by a simple assignment operation ('='), by the costructor or by using the 'set*' methods.

The set* methods are:

```c++
void setInt(int value);
void setInt64(int64_t value);
void setDouble(double value);
void setString(string value);
void setCStr(char* s);
void setBool(bool value);
```

You can get the value by a simple assignment operation ('=') or by the 'get*' methods.

The get* methods are:

```c++
int getInt(function<void()> onError = [](){});
int64_t getInt64(function<void()> onError = [](){});
double getDouble(function<void()> onError = [](){});
string getString();
bool getBool(function<void()> onError = [](){});
void setBool(bool value);
```

Excluding the 'getString' function, all other calls to get functions can result in internal conversion errors. For these cases, you can specify an anonymous function to be notified. Also, if an internal error occurs, the function will return a default value (0 for numbers, false for boolean and an empty JSON object for json).

# Other usage examples 

## a simple var

```c++
DynamicVar tmp;
tmp.setInt(10);
cout << "The value of temp is " << tmp.getInt() << endl;
```

## setting as int ang getting as string

```c++
DynamicVar tmp;
tmp.setInt(10);
cout << "The value of temp is " << tmp.getString() << endl;
```

## Setting value on constructor
```c++
DynamicVar tmp(10);
cout << "The value of temp is " << tmp.getString() << endl;
```

## Using a DynamicVar var in a class constructor or class methods
```c++
class MyClass{
private:
    DynamicVar value;
public:
    MyClass(DynamicVar initialValue): value(initialValue){}
    DynamicVar getValue(){ return value }
};


MyClass tmp1(10);
MyClass tmp1("11");
MyClass tmp1(12.0);
cout << "The value of tmp1 is " << tmp1.getValue().getString() << endl;
cout << "The value of tmp2 is " << tmp2.getValue().getString() << endl;
cout << "The value of tmp3 is " << tmp3.getValue().getString() << endl;
```

## Simple attribuitions

```c++
DynamicVar tmp1 = 10;
DynamicVar tmp2 = "11";
DynamicVar tmp3 = 12.0;

cout << "The value of tmp1 is " << tmp1.getString() << endl;
cout << "The value of tmp2 is " << tmp2.getString() << endl;
cout << "The value of tmp3 is " << tmp3.getString() << endl;
```
