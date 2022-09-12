# About DynamicVar
Dynamic var is a dynamic type for C++. I wrote this to use in some personal projects to facilitate conversions between types in UI and Databases. 

This type allows you to set its value as int, double, string, boolean and some others and get its value as well in various types.

The type contains some useful constructors and type overloading helping to use it with your application.

# Input types

Allowed input types for values are 'int', 'int64_t', 'double', 'string', 'bool', 'char const *' and JsonMaker::JSON (see more at http...)

You can set the value by a simple assignment operation ('='), by the costructor or by using the 'set*' methods.

The set* methods are:

```c++
void setInt(int value);
void setInt64(int64_t value);
void setDouble(double value);
void setString(string value);
void setCStr(char* s);
void setBool(bool value);
void setJson(JsonMaker::JSON data);
```

If you don't want to use the 'JsonMaker::JSON' type, currently you must remove the #include<JSON.h> from the DynamicVar.h header.

# Output types

You can get the value by a simple assignment operation ('=') or by the 'get*' methods.

The get* methods are:

```c++
int getInt(function<void()> onError = [](){});
int64_t getInt64(function<void()> onError = [](){});
double getDouble(function<void()> onError = [](){});
string getString();
bool getBool(function<void()> onError = [](){});
void setBool(bool value);
JsonMaker::JSON getJson(function<void()> onError = [](){});
```

Excluding the 'getString' function, all other calls to get functions can result in internal conversion errors. For these cases, you can specify a lambda function to be notified. Also, if an internal error occurs, the function will return a default value (0 for numbers, false for boolean and an empty JSON object for json).