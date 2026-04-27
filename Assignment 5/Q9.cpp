#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Vehicle {
protected:
    string make;
    string model;
    int year;
    double mileage;
public:
    Vehicle() {
        make = "Unknown";
        model = "Unknown";
        year = 2020;
        mileage = 0.0;
        cout << "Vehicle default constructor called" << endl;
    }
    Vehicle(string mk, string mdl, int yr) {
        make = mk;
        model = mdl;
        year = yr;
        mileage = 0.0;
        cout << "Vehicle created: " << year << " " << make << " " << model << endl;
    }
    void displayVehicleInfo() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << fixed << setprecision(1);
        cout << "Mileage: " << mileage << " km" << endl;
    }
    void addMileage(double km) {
        mileage += km;
        cout << "Added " << km << " km to mileage. Total: " << mileage << " km" << endl;
    }
       string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getMileage() const { return mileage; }
    int calculateAge() {
        return 2024 - year;
    }
    virtual ~Vehicle() {
        cout << "Vehicle destroyed: " << make << " " << model << endl;
    }};
class Truck : public Vehicle {
protected:
    double loadCapacity;
    double currentLoad;
public:
Truck() : Vehicle() {
loadCapacity = 0.0;
        currentLoad = 0.0;
        cout << "Truck default constructor called" << endl;
}
    Truck(string mk, string mdl, int yr, double capacity) : Vehicle(mk, mdl, yr) {
            loadCapacity = capacity;
        currentLoad = 0.0;
        cout << "Truck created with load capacity: " << capacity << " tons" << endl;
    }
    void displayTruckInfo() {
        displayVehicleInfo();  
        cout << fixed << setprecision(2);
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
        cout << "Current Load: " << currentLoad << " tons" << endl;
        cout << "Available Capacity: " << (loadCapacity - currentLoad) << " tons" << endl;
    }
    void loadCargo(double weight) {
        if (currentLoad + weight <= loadCapacity) {
            currentLoad += weight;
            cout << "Loaded " << weight << " tons. Current load: " << currentLoad << " tons" << endl;
        } else {
            cout << "Cannot load " << weight << " tons. Exceeds capacity!" << endl;
            cout << "Available space: " << (loadCapacity - currentLoad) << " tons" << endl;
        }
    }
    void unloadCargo(double weight) {
        if (currentLoad >= weight) {
            currentLoad -= weight;
            cout << "Unloaded " << weight << " tons. Remaining load: " << currentLoad << " tons" << endl;
        } else {
            cout << "Cannot unload " << weight << " tons. Current load is only " << currentLoad << " tons" << endl;
        }
    }
    bool isFullyLoaded() {
        return currentLoad >= loadCapacity;
    }
    double getLoadCapacity() const { return loadCapacity; }
    double getCurrentLoad() const { return currentLoad; }
    ~Truck() {
        cout << "Truck destroyed with capacity: " << loadCapacity << " tons" << endl;
    }};
class RefrigeratedTruck : public Truck {
private:
    double temperatureControl; 
    double minTemperature;
    double maxTemperature;
    bool coolingSystemOn;
public:
    RefrigeratedTruck() : Truck() {
        temperatureControl = 5.0;
        minTemperature = -20.0;
        maxTemperature = 20.0;
        coolingSystemOn = false;
        cout << "RefrigeratedTruck default constructor called" << endl;
    }
    RefrigeratedTruck(string mk, string mdl, int yr, double capacity, double temp) 
        : Truck(mk, mdl, yr, capacity) {
        temperatureControl = temp;
        minTemperature = -20.0;
        maxTemperature = 20.0;
        coolingSystemOn = false;
        cout << "Refrigerated Truck created with temperature control: " << temp << "°C" << endl;
    }
    void displayRefrigeratedTruckInfo() {
        displayVehicleInfo();
        cout << fixed << setprecision(2);
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
        cout << "Current Load: " << currentLoad << " tons" << endl;
        cout << "Temperature Setting: " << temperatureControl << "°C" << endl;
        cout << "Temperature Range: " << minTemperature << "°C to " << maxTemperature << "°C" << endl;
        cout << "Cooling System: " << (coolingSystemOn ? "ON" : "OFF") << endl;
    }
    void startCooling() {
        if (!coolingSystemOn) {
            coolingSystemOn = true;
            cout << "Cooling system started. Maintaining temperature at " << temperatureControl << "°C" << endl;
        } else {
            cout << "Cooling system is already running." << endl;
        }
    }
    void stopCooling() {
        if (coolingSystemOn) {
            coolingSystemOn = false;
            cout << "Cooling system stopped." << endl;
        } else {
            cout << "Cooling system is already off." << endl;
        }}
    void setTemperature(double temp) {
        if (temp >= minTemperature && temp <= maxTemperature) {
            temperatureControl = temp;
            cout << "Temperature set to " << temperatureControl << "°C" << endl;
        } else {
            cout << "Temperature out of range! Must be between " << minTemperature 
                 << "°C and " << maxTemperature << "°C" << endl;
        }
    }
    void loadPerishableCargo(double weight, string cargoType) {
        if (!coolingSystemOn) {
            cout << "WARNING: Cooling system is OFF! Start cooling before loading perishables." << endl;
        }
        loadCargo(weight);  
        cout << "Loaded perishable cargo: " << cargoType << endl;
        if (coolingSystemOn) {
            cout << "Cargo is being kept at " << temperatureControl << "°C" << endl;
        }}
    bool isSuitableForCargo(string cargoType) {
        if (cargoType == "Frozen Food" && temperatureControl <= 0) {
            return true;
        } else if (cargoType == "Fresh Produce" && temperatureControl > 0 && temperatureControl <= 10) {
            return true;
        } else if (cargoType == "Dairy" && temperatureControl >= 2 && temperatureControl <= 8) {
            return true;
        }
        return false;
    }
    double getTemperature() const { return temperatureControl; }
    bool isCoolingOn() const { return coolingSystemOn; }
    ~RefrigeratedTruck() {
        cout << "Refrigerated Truck destroyed (Temp: " << temperatureControl << "°C)" << endl;
}};
int main() {
    cout << "\n--- Creating Base Vehicle (Level 1) ---" << endl;
    Vehicle vehicle1("Honda", "Civic", 2022);
    vehicle1.displayVehicleInfo();
    vehicle1.addMileage(5000);
    cout << "Vehicle age: " << vehicle1.calculateAge() << " years" << endl;
    cout << "\n--- Creating Truck (Level 2) ---" << endl;
    Truck truck1("Ford", "F-150", 2023, 3.5);
    truck1.displayTruckInfo();
    truck1.loadCargo(1.5);
    truck1.loadCargo(1.0);
    truck1.loadCargo(1.5); 
    truck1.addMileage(150);
    truck1.displayTruckInfo();
    cout << "\n--- Creating Refrigerated Truck (Level 3) ---" << endl;
    RefrigeratedTruck refTruck1("Volvo", "FH16", 2024, 15.0, 5.0);
    refTruck1.displayRefrigeratedTruckInfo();
    cout << "\n--- Operating Refrigerated Truck ---" << endl;
    refTruck1.startCooling();
    refTruck1.setTemperature(3.0);
    cout << "\n--- Loading Perishable Cargo ---" << endl;
    refTruck1.loadPerishableCargo(5.0, "Fresh Vegetables");
    refTruck1.loadPerishableCargo(4.0, "Dairy Products");
    refTruck1.loadPerishableCargo(3.5, "Fruits");
    cout << "\n--- Checking Cargo Suitability ---" << endl;
    cout << "Suitable for Dairy? " << (refTruck1.isSuitableForCargo("Dairy") ? "Yes" : "No") << endl;
    cout << "Suitable for Frozen Food? " << (refTruck1.isSuitableForCargo("Frozen Food") ? "Yes" : "No") << endl;
    refTruck1.addMileage(350);
    refTruck1.displayRefrigeratedTruckInfo();
    cout << "\n--- Delivering Cargo ---" << endl;
    refTruck1.unloadCargo(5.0);
    refTruck1.unloadCargo(4.0);
    refTruck1.stopCooling();
    refTruck1.displayRefrigeratedTruckInfo();
    cout << "\n--- Creating Frozen Food Transport Truck ---" << endl;
    RefrigeratedTruck refTruck2("Mercedes", "Actros", 2024, 20.0, -18.0);
    refTruck2.startCooling();
    refTruck2.loadPerishableCargo(10.0, "Frozen Meat");
    refTruck2.loadPerishableCargo(8.0, "Ice Cream");
    refTruck2.displayRefrigeratedTruckInfo();
    cout << "Level 1: Vehicle (make, model, year, mileage)" << endl;
    cout << "   |" << endl;
    cout << "   v" << endl;
    cout << "Level 2: Truck (inherits Vehicle + adds loadCapacity, currentLoad)" << endl;
    cout << "   |" << endl;
    cout << "   v" << endl;
    cout << "Level 3: RefrigeratedTruck (inherits Truck + adds temperatureControl, cooling)" << endl;
    cout << "\nKEY BENEFITS" << endl;
    cout << "1. RefrigeratedTruck has access to ALL features from Vehicle and Truck" << endl;
    cout << "2. Gradual specialization: Vehicle -> Truck -> RefrigeratedTruck" << endl;
    cout << "3. Code reusability at each level" << endl;
    cout << "4. Each level adds more specific functionality" << endl;
    cout << "5. Easy to maintain and extend the hierarchy" << endl;
    return 0;
}