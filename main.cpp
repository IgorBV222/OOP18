#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory>
#include "Printer.h"

using namespace Engine;

//Функторы - объекты класса, у которого перегружен оператор ()
//Лямбды


//Функторы
class Incrementer {
public:
    Incrementer (int x): _x(x){}

    int operator()(int y) {
        return _x + y;
    }

    int myFunc(int y) {
        const auto add = [this, y](int a) { //this дает лямбде видить _х по указателю а не по ссылке
            return _x + y + a;
        };
        return add(5);
    }

private:
    int _x;
};

class IVehicle {
public:
    virtual int getSpeed() const = 0;
    virtual void printType() const = 0;
    virtual ~IVehicle(){}
};

class Car : public IVehicle {
public:
    Car(int speed) : _speed(speed){}
    int getSpeed() const override {
        return _speed;
    }
    void printType() const override {
        std::cout << "Car" << std::endl;
    }
private:
    int _speed;
};

class Van : public IVehicle {
public:
    Van(int speed) : _speed(speed) {}
    int getSpeed() const override {
        return _speed;
    }
    void printType() const override {
        std::cout << "Van" << std::endl;
    }
private:
    int _speed;
};

class Bike : public IVehicle {
public:
    Bike(int speed) : _speed(speed) {}
    int getSpeed() const override {
        return _speed;
    }
    void printType() const override {
        std::cout << "Bike" << std::endl;
    }
private:
    int _speed;
};

//namespace


int main()
{
    //std::unique_ptr< IVehicle> v = std::make_unique<Car>(50); //тоже работает
    std::shared_ptr< IVehicle> v = std::make_shared<Car>(50);    
    std::cout << "Vehicle speed: " << v->getSpeed() << std::endl;
    v->printType();
    std::cout << "=============\n";

    std::shared_ptr< IVehicle> v1 = std::make_shared<Car>(50);
    std::shared_ptr< IVehicle> v2 = std::make_shared<Van>(50);
    std::shared_ptr< IVehicle> v3 = std::make_shared<Bike>(50);





    //Функторы
    Incrementer inc(50);
    int a = inc(5);
    std::cout << a << std::endl;

    //Лямбда - выражение (функция)
    //const auto myinc = [a](int num) { //capture clause - [] - захват, делает копию а.
    //    return num + 5 + a;
   // };

    const auto myinc = [=, &a](int num) { // [=] - захват всего, что видет myinc.[=, &a]- захватить все копированием кроме а, а взять по ссылке
        return num + 5 + a;
    };

   
    std::cout << myinc(6) << std::endl;

    std::cout <<inc.myFunc(3) << std::endl;
    std::cout << "=====================\n";

    std::vector<int> vec{ 1, -4, 3, -2 };
    for (const auto el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());

    for (const auto el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    //сортировка по модулю
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return std::abs(a) > std::abs(b);
    });

    for (const auto el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;



    //Engine::Printer p;
    Printer p; // после подключения using namespace Engine
    p.printDefault();



}