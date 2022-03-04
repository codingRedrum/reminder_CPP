#include <iostream>
#include <vector>

/**
 *   @brief IMPORTANT!
 *   Program was created for learning purpose, so you might encounter compilation errors, 
 *   which navigate me to check if the result of deduced type was same as I've expected before compiling.
 * 
 *   REMINDER 
 *  - auto type deduction works exactly the same as template type deduction
 *  - keep in mind that declaring template function with const parameter cause deprivation of T constness
 */
template <typename T>
class TypeIdentifier;

template <typename T>
void f(T& param)
{
    TypeIdentifier<T> tType;
    TypeIdentifier<decltype(param)> paramType;
}

template <typename T>
void f1(T&& param)
{
    TypeIdentifier<T> tType;
    TypeIdentifier<decltype(param)> paramType;
}

template <typename Object, typename Type>
auto changeObjectValue(Object& ref, Type value)
{ 
    ref = value;
    // auto deduces referencess after retutn we get int 
    return ref;
}

template <typename Object>
auto assignNewValue(Object& obj)
->decltype(obj)
{
    // thanks trailing return type we keep reference while type deduction / without returns rvalue
    return obj;
}

template <typename Object>
auto getRValue(Object& param)
{
    // auto deduces reference from param type
    return param;
}

template <typename Object>
auto getRvalReference(Object&& param)
{
    // without decltype passing an l-value as argument will give return l-value reerence 
    return param;
}


int
main()
{
    int x = 100;

    decltype(auto) newXValue = changeObjectValue(x,10);
    assignNewValue(x) = 100000;

    const int cx = 1;
    auto cxAuto = cx;                   // cxAuto deduced to be     const int / auto       int
    decltype(auto) cxDecltype = cx;     // cxDeclype                const int / auto const int 

}
