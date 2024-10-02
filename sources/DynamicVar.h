#ifndef __DYNAMIC_VAR_H_
#define __DYNAMIC_VAR_H_
#define INVALID_INT 0b11111111111111111111111111111111;

#include <functional>
#include <string>
#include <algorithm>
#include <stdexcept>

//#include <JSON.h>

using namespace std;
class DynamicVar{
private:
    string __data;
    string originalTypeName;
 
    template<typename T>
    void setOriginalType(){
        originalTypeName = typeid(T).name();
    }

    void setOriginalType_s(string typeInfo_name){
        originalTypeName = typeInfo_name;
    }


public:

    class ISerializable{
    public:
        virtual string serialize() = 0;
        virtual void deserialize(string data) = 0;
    };
    
    /**
     * @brief Construct a new Dynamic Var object
     */
    DynamicVar();
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(char const *value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(string value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(int value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(uint value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(double value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(bool value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(int64_t value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(uint64_t value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(ISerializable* value);
    
    /**
     * @brief Construct a new Dynamic Var object and initializes its value
     */
    DynamicVar(ISerializable &value);
    

    template<typename T>
    bool checkOriginalType(){
        return typeid(T).name() == originalTypeName;
    }

    bool checkOriginalType_s(string typeid_name){
        return typeid_name == originalTypeName;
    } 

    int getInt(function<void()> onError = [](){});
    void setInt(int value);

    uint getUint(function<void()> onError = [](){});
    void setUint(uint value);

    int64_t getInt64(function<void()> onError = [](){});
    void setInt64(int64_t value);

    uint64_t getUint64(function<void()> onError = [](){});
    void setUint64(uint64_t value);

    double getDouble(function<void()> onError = [](){});
    void setDouble(double value);

    string getString();
    void setString(string value);
    void setCStr(char* s);

    bool getBool(function<void()> onError = [](){});
    void setBool(bool value);

    void setISerializable(ISerializable *object);
    void setISerializable(ISerializable &object);
    ISerializable* getISerializable(ISerializable* object);
    ISerializable* getISerializable(function<ISerializable*()> createObjectF);

    template<typename T>
    void setPointer(T* object){
        this->setUint64((uint64_t)object);
    }

    template<typename T>
    T* getPointer(){
        return (T*)(this->getUint64());
    }


    #ifdef JSONMAKER_H
        DynamicVar(JsonMaker::JSON value);
        JsonMaker::JSON getJson(function<void()> onError = [](){});
        void setJson(JsonMaker::JSON data);
    #endif

    bool isEquals(DynamicVar* other);
    bool isEquals(DynamicVar &other);

    template<class T>
    operator T*(){ return getPointer<T>(); }
    operator string(){return getString(); }
    operator int(){return getInt(); }
    operator uint(){return getUint(); }
    operator int64_t(){return getInt64(); }
    operator uint64_t(){return getUint64(); }
    operator double(){return getDouble();}
    operator bool(){return getBool(); }
    operator signed long long(){ return getInt64(); }
    operator unsigned long long(){ return getUint64(); }


    template <typename T>
    void set(T value){
        if(typeid(T).name() == originalTypeName){
            if(typeid(T).name() == typeid(int).name()){
                int tmp=*((int*)(&value));
                setInt(tmp);
            }else if(typeid(T).name() == typeid(uint).name()){
                uint tmp=*((uint*)(&value));
                setUint(tmp);
            }else if(typeid(T).name() == typeid(int64_t).name()){
                int64_t tmp=*((int64_t*)(&value));
                setInt64(tmp);
            }else if(typeid(T).name() == typeid(uint64_t).name()){
                uint64_t tmp=*((uint64_t*)(&value));
                setUint64(tmp);
            }else if(typeid(T).name() == typeid(double).name()){
                double tmp=*((double*)(&value));
                setDouble(tmp);
            }else if(typeid(T).name() == typeid(bool).name()){
                bool tmp=*((bool*)(&value));
                setBool(tmp);
            }else if(typeid(T).name() == typeid(string).name()){
                string tmp=*((string*)(&value));
                setString(tmp);
            }else
                throw runtime_error("Type not supported. Suported types are int, uint, int64_t, uint64_t, double, bool and string");
        }
    }

    template <typename T>
    T get(function<void()> onError = [](){ }){
        if(typeid(T).name() == originalTypeName){
            if(typeid(T).name() == typeid(int).name()){
                auto tmp = (getInt(onError));
                return (T)(*((T*)(&tmp)));
            }else if(typeid(T).name() == typeid(uint).name()){
                auto tmp = (getUint(onError));
                return (T)(*((T*)(&tmp)));
            }else if(typeid(T).name() == typeid(int64_t).name()){
                auto tmp = (getInt64(onError));
                return (T)(*((T*)(&tmp)));
            }else if(typeid(T).name() == typeid(uint64_t).name()){
                auto tmp = (getUint64(onError));
                return (T)(*((T*)(&tmp)));
            }else if(typeid(T).name() == typeid(double).name()){
                auto tmp = (getDouble(onError));
                return (T)(*((T*)(&tmp)));
            }else if(typeid(T).name() == typeid(bool).name()){
                auto tmp = (getBool(onError));
                return (T)(*((T*)(&tmp)));
            }else if(typeid(T).name() == typeid(string).name()){
                auto tmp = (getString());
                return (T)(*((T*)(&tmp)));
            }else
                throw runtime_error("Type not supported. Suported types are int, uint, int64_t, uint64_t, double, bool and string");
        }
        return T();
    }
};
#endif