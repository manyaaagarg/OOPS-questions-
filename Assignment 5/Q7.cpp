#include <iostream>
#include <iomanip>
using namespace std;
class Speedometer {
protected:
    double speed;  
    double maxSpeed;
public:
    Speedometer() {
        speed = 0.0;
        maxSpeed = 200.0;
        cout << "Speedometer initialized" << endl;
    }
    void setSpeed(double s) {
        if (s >= 0 && s <= maxSpeed) {
            speed = s;
        } else if (s > maxSpeed) {
            speed = maxSpeed;
            cout << "Speed limited to maximum: " << maxSpeed << " km/h" << endl;
        } else {
            speed = 0;
        }
    }
    double getSpeed() const {
        return speed;
    }
    void displaySpeed() {
        cout << fixed << setprecision(1);
        cout << "Speed: " << speed << " km/h";
        if (speed > 120) {
            cout << " [SPEEDING!]";
        }
        cout << endl;
    }
    
    ~Speedometer() {
        cout << "Speedometer destroyed" << endl;
    }};
class FuelGauge {
protected:
    double fuelLevel;  
    double tankCapacity;
public:
    FuelGauge() {
        fuelLevel = 50.0;
        tankCapacity = 60.0;
        cout << "Fuel Gauge initialized" << endl;
    }
    void setFuelLevel(double fuel) {
        if (fuel >= 0 && fuel <= tankCapacity) {
            fuelLevel = fuel;
        } else if (fuel > tankCapacity) {
            fuelLevel = tankCapacity;
        } else {
            fuelLevel = 0;
        }
    }
    void consumeFuel(double amount) {
        if (fuelLevel >= amount) {
            fuelLevel -= amount;
        } else {
            fuelLevel = 0;
        }
    }
    void refuel(double amount) {
        if (fuelLevel + amount <= tankCapacity) {
            fuelLevel += amount;
            cout << "Refueled " << amount << " liters" << endl;
        } else {
            cout << "Tank full! Added " << (tankCapacity - fuelLevel) << " liters" << endl;
            fuelLevel = tankCapacity;
        }
    }
    double getFuelLevel() const {
        return fuelLevel;}
    void displayFuel() {
        cout << fixed << setprecision(1);
        cout << "Fuel Level: " << fuelLevel << "/" << tankCapacity << " liters";
        double fuelPercentage = (fuelLevel / tankCapacity) * 100;
        if (fuelPercentage < 15) {
  cout << " [LOW FUEL WARNING!]";
        }
        cout << " (" << fuelPercentage << "%)" << endl;
    }
    ~FuelGauge() {
        cout << "Fuel Gauge destroyed" << endl;
}};
class Thermometer {
protected:
    double temperature;  
    double normalTemp;
    double maxTemp;
    
public:
    Thermometer() {
        temperature = 90.0;
        normalTemp = 90.0;
maxTemp = 120.0;
        cout << "Thermometer initialized" << endl;
    }
    void setTemperature(double temp) {
        temperature = temp;
    }
    void updateTemperature(double speedFactor) {
        temperature = normalTemp + (speedFactor * 0.15);
        if (temperature > maxTemp) {
            temperature = maxTemp;
}}
    double getTemperature() const {
        return temperature;
    }
    void displayTemperature() {
        cout << fixed << setprecision(1);
        cout << "Engine Temperature: " << temperature << "°C";
        
        if (temperature > 110) {
            cout << " [OVERHEATING WARNING!]";
        } else if (temperature > 100) {
            cout << " [HOT]";
        }
        cout << endl;
    }
    ~Thermometer() {
        cout << "Thermometer destroyed" << endl;
    }
};
class CarDashboard : public Speedometer, public FuelGauge, public Thermometer {
private:
    string carModel;
    bool engineOn;
public:
    CarDashboard(string model) : Speedometer(), FuelGauge(), Thermometer() {
        carModel = model;
        engineOn = false;
        cout << "Car Dashboard created for: " << carModel << endl;
    }
    void startEngine() {
        if (!engineOn) {
            engineOn = true;
            cout << carModel << " is ready to drive!" << endl;
        } else {
            cout << "Engine is already running!" << endl;
        }}
    void stopEngine() {
        if (engineOn) {
            engineOn = false;
            setSpeed(0);
        }
    }
    void drive(double newSpeed, double duration) {
        if (!engineOn) {
            cout << "Please start the engine first!" << endl;
            return;
        }
        setSpeed(newSpeed);
        double distance = (newSpeed * duration) / 60.0; 
        double fuelConsumed = distance * 0.08;
        consumeFuel(fuelConsumed);
        updateTemperature(newSpeed);
        cout << "\nDriving for " << duration << " minutes at " << newSpeed << " km/h" << endl;
        cout << "Distance covered: " << distance << " km" << endl;
        cout << "Fuel consumed: " << fuelConsumed << " liters" << endl;
    }
    void displayDashboard() {
        cout << "Engine Status: " << (engineOn ? "ON" : "OFF") << endl;
        displaySpeed();
        displayFuel();
        displayTemperature();
    }
    ~CarDashboard() {
        cout << "Car Dashboard destroyed for: " << carModel << endl;
    }
};
int main() {
    cout << "\nCreating Car Dashboard (Multiple Inheritance)" << endl;
    
    CarDashboard myCar("Tesla Model S");
    
    cout << "\n--- Initial Dashboard Status ---" << endl;
    myCar.displayDashboard();
    myCar.startEngine();
    myCar.displayDashboard();
    cout << "\n--- Scenario 1: City Driving ---" << endl;
    myCar.drive(60, 15);
    myCar.displayDashboard();
    
    cout << "\n--- Scenario 2: Highway Driving ---" << endl;
    myCar.drive(120, 30);
    myCar.displayDashboard();
    
    cout << "\n--- Scenario 3: High Speed (Testing Limits) ---" << endl;
    myCar.drive(180, 10);  
    myCar.displayDashboard();
    myCar.refuel(30);
    myCar.displayDashboard();
    myCar.stopEngine();
    myCar.displayDashboard();
    return 0;
}