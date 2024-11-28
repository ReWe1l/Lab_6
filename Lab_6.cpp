#include <iostream>
#include <vector>

// Абстрактный класс
class Vehicle {
public:
    virtual ~Vehicle() = default;


    virtual void displayInfo() const = 0;     //  <-- Абстрактный метод

    double getPrice() const { return price; }

    void setPrice(double price) { this->price = price; }

    int getMaxSpeed() const { return maxSpeed; }                       // <-- Неабстрактные методы

    void setMaxSpeed(int maxSpeed) { this->maxSpeed = maxSpeed; }

    int getYear() const { return year; }

    void setYear(int year) { this->year = year; }

protected:
    double price;
    int maxSpeed;
    int year;
};

class Car : public Vehicle {
public:
    Car(double price, int maxSpeed, int year, int numDoors)
        : Vehicle(), numDoors(numDoors) {
        setPrice(price);
        setMaxSpeed(maxSpeed);
        setYear(year);
    }

    void displayInfo() const override {
        std::cout << "Car: Price = " << getPrice() << ", Max Speed = " << getMaxSpeed()
            << ", Year = " << getYear() << ", Number of Doors = " << numDoors << std::endl;
    }

private:
    int numDoors;
};

class Bicycle : public Vehicle {
public:
    Bicycle(double price, int maxSpeed, int year, bool hasGears)
        : Vehicle(), hasGears(hasGears) {
        setPrice(price);
        setMaxSpeed(maxSpeed);
        setYear(year);
    }

    void displayInfo() const override {
        std::cout << "Bicycle: Price = " << getPrice() << ", Max Speed = " << getMaxSpeed()
            << ", Year = " << getYear() << ", Has Gears = " << (hasGears ? "Yes" : "No") << std::endl;
    }

private:
    bool hasGears;
};

class Lorry : public Vehicle {
public:
    Lorry(double price, int maxSpeed, int year, double loadCapacity)
        : Vehicle(), loadCapacity(loadCapacity) {
        setPrice(price);
        setMaxSpeed(maxSpeed);
        setYear(year);
    }

    void displayInfo() const override {
        std::cout << "Lorry: Price = " << getPrice() << ", Max Speed = " << getMaxSpeed()
            << ", Year = " << getYear() << ", Load Capacity = " << loadCapacity << " tons" << std::endl;
    }

private:
    double loadCapacity;
};

class Garage {
public:
    ~Garage() {
        for (Vehicle* vehicle : vehicles) {
            delete vehicle;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAllVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo();
        }
    }

private:
    std::vector<Vehicle*> vehicles;
};

int main() {
    Garage garage;

    garage.addVehicle(new Car(20000, 200, 2020, 4));
    garage.addVehicle(new Bicycle(500, 30, 2019, true));
    garage.addVehicle(new Lorry(100000, 120, 2018, 10.5));

    garage.displayAllVehicles();

    return 0;
}
