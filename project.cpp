#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <mutex>
#include <algorithm>
#include <sstream>
#include <conio.h>
#include <map>
#include <functional>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

std::mutex logMutex; // Mutex for thread-safe logging

// Base class for Sensor





map<string, string> subedarCredentials = {{"subedar", "subedarpass"}, {"majorSubedar", "majorSubedarpass"}};

 // Subedar and Major Subedar login credentials
map<string, string> captainCredentials = {{"captain", "captainpass"}, {"major", "majorpass"}};

 // Captain and Major login credentials
map<string, string> emergencyCredentials;

// Emergency order credentials, anyone with the correct username and password can log in

struct Order
{

    string orderName;
    string orderDetails;
};

vector<Order> orderList;

// To store all orders placed by users

// Function to handle password input securely (hidden password)

string getPassword()
 {
    string password = "";

    char ch;

    while(true)
        {

        ch = _getch();

        // Get a character without displaying it

        if(ch == 13)

         {
             // Enter key

            break;

        }
    else if(ch == 8)

        {
            // Backspace key

            if(password.length() > 0)

             {
                password.pop_back();

                cout << "\b \b"; // Erase the last character on screen
            }
        }
    else
        {
            password.push_back(ch);

            cout << "*";

            // Display a * for each entered character
        }
    }

    return password;
}

// Function to check if a username and password are valid for a map

bool validateLogin(map<string, string>& credentials)
{
    string username, password;

    cout << "Enter Username: ";

    cin >> username;

    cout << "Enter Password: ";

    password = getPassword();

    if (credentials.find(username) != credentials.end() && credentials[username] == password)
        {
        cout << "\nLogged in successfully!" << endl;

        return true;

    }
     else

        {
        return false;
    }
}

// Function for forgot password option

void forgotPassword(map<string, string>& credentials)
 {
    string username;

    cout << "Enter Username to reset password: ";

    cin >> username;

    if (credentials.find(username) != credentials.end())

        {

        string newPassword;

        cout << "Enter new password: ";

        newPassword = getPassword();

        credentials[username] = newPassword;

        cout << "Password reset successfully!" << endl;
    }
    else
        {
        cout << "Username not found!" << endl;
    }
}

// Function to display all orders placed

void viewOrders()
 {
    if (orderList.empty())

        {
        cout << "\nNo orders placed yet." << endl;

    }
     else
        {
        cout << "\n--- All Orders ---" << endl;

        for (int i = 0; i < orderList.size(); ++i)
            {
            cout << "Order #" << i + 1 << " - Name: " << orderList[i].orderName << ", Details: " << orderList[i].orderDetails << endl;
        }
    }
}

// Main menu for Subedar and Major Subedar

void subedarMenu()
 {
    int choice;

    while (true)

        {
        cout << "\n---- Main Menu ----";

        cout << "\n1. Place Order";

        cout << "\n2. Emergency Order";

        cout << "\n3. View Order";

        cout << "\n4. Logout";

        cout << "\nEnter your choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                 {
                string name, details;

                cout << "\nEnter Order Name: ";

                cin.ignore();

                 // To clear any leftover newline character

                getline(cin, name);

                // Get the name of the order

                cout << "Enter Order Details: ";

                getline(cin, details);

                // Get the details of the order

                orderList.push_back({name, details});

                 // Store the order

                cout << "Order placed successfully!" << endl;

                break;
            }

            case 2:
                 {
                string name, details;

                cout << "\nEnter Emergency Order Name: ";

                cin.ignore();

                 // To clear any leftover newline character

                getline(cin, name);

                 // Get the name of the emergency order

                cout << "Enter Emergency Order Details: ";

                getline(cin, details);

                 // Get the details of the emergency order

                orderList.push_back({name, details});

                 // Store the emergency order

                cout << "Emergency order placed successfully!" << endl;
                break;

            }
            case 3:
                 {

                viewOrders();

                // Show all orders

                break;
            }
            case 4:
                {

                cout << "\nLogging out...\n";

                return;
            }
            default:

                 {

                cout << "\nInvalid choice. Please try again.\n";

                break;
            }
        }
    }
}

// Main menu for Captain and Major

void captainMenu()
{
    int choice;

    while (true)
        {
        cout << "\n---- Main Menu ----";

        cout << "\n1. Place Order";

        cout << "\n2. Emergency Order";

        cout << "\n3. View Order";

        cout << "\n4. Logout";

        cout << "\nEnter your choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                {
                string name, details;

                cout << "\nEnter Order Name: ";

                cin.ignore();

                 // To clear any leftover newline character

                getline(cin, name);

                  // Get the name of the order

                cout << "Enter Order Details: ";

                getline(cin, details);

                 // Get the details of the order

                orderList.push_back({name, details});

                 // Store the order

                cout << "Order placed successfully!" << endl;
                break;

            }
            case 2:
                {
                string name, details;

                cout << "\nEnter Emergency Order Name: ";

                cin.ignore();

                // To clear any leftover newline character

                getline(cin, name);

                // Get the name of the emergency order

                cout << "Enter Emergency Order Details: ";

                getline(cin, details);

                 // Get the details of

                // the emergency order
                orderList.push_back({name, details});

                 // Store the emergency order

                cout << "Emergency order placed successfully!" << endl;
                break;
            }
            case 3: {
                viewOrders();

                 // Show all orders
                break;
            }
            case 4:

                 {
                cout << "\nLogging out...\n";
                return;
            }
            default:
                 {
                cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }
    }
}

// Main menu for Emergency order login

void emergencyOrderMenu()
 {
    int choice;
    while (true)

        {
        cout << "\n---- Main Menu ----";

        cout << "\n1. Place Emergency Order";

        cout << "\n2. View Order";

        cout << "\n3. Logout";

        cout << "\nEnter your choice: ";

        cin >> choice;

        switch(choice)
         {
            case 1:
                 {
                string name, details;

                cout << "\nEnter Emergency Order Name: ";

                cin.ignore();

                 // To clear any leftover newline character

                getline(cin, name);

                // Get the name of the emergency order

                cout << "Enter Emergency Order Details: ";

                getline(cin, details);

                 // Get the details of the emergency order

                orderList.push_back({name, details});

                 // Store the emergency order

                cout << "Emergency order placed successfully!" << endl;
                break;
            }
            case 2:
                 {
                viewOrders();

                // Show all orders
                break;
            }
            case 3:
                 {

                cout << "\nLogging out...\n";
                return;
            }
            default:
                {
                cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }
    }
}








class Sensor
{
public:
    std::string sensorType;

    // Type of sensor
    std::string unit;

      // Unit of measurement

    // Constructor for Sensor class

    Sensor(const std::string& type, const std::string& unitType) : sensorType(type), unit(unitType) {}

    // Pure virtual function for generating raw data

    virtual double generateRawData() = 0;
};

// Temperature sensor class

class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor() : Sensor("Temperature", "Celsius") {}

    // Generate random temperature data

    double generateRawData() override

    {
        return 15.0 + static_cast<double>(rand() % 1500) / 50.0; // Generate random temperature data
    }
};

// Humidity sensor class

class HumiditySensor : public Sensor
{
public:
    HumiditySensor() : Sensor("Humidity", "%") {}

    // Generate random humidity data

    double generateRawData() override
    {
        return 20.0 + static_cast<double>(rand() % 8000) / 50.0; // Generate random humidity data
    }
};

// GPS sensor class

class GPSSensor : public Sensor
{
public:
    GPSSensor() : Sensor("GPS", "Coordinates") {}

    // Generate random GPS data

    double generateRawData() override
    {
        return 37.0 + static_cast<double>(rand() % 10000) / 100000.0; // Generate random GPS data
    }
};

// Data processor for filtering sensor data

class DataProcessor
{
public:
    // Filter raw sensor data based on type

    double filterData(const std::string& sensorType, double rawData)
    {

        if (sensorType == "Temperature" && (rawData < 15.0 || rawData > 35.0)) return -1.0;

         // Filter invalid temperature data

        if (sensorType == "Humidity" && (rawData < 30.0 || rawData > 100.0)) return -1.0;

        // Filter invalid humidity data


        if (sensorType == "GPS" && (rawData < 36.0 || rawData > 38.0)) return -1.0;

         // Filter invalid GPS data
        return rawData;

        // Return valid data
    }
};

// Logger for handling file operations

class Logger
{
public:
    // Log data to file

    static void logData(const std::string& fileName, const std::string& data)

     {
        std::lock_guard<std::mutex> lock(logMutex);

         // Lock for thread safety
        std::ofstream outFile(fileName, std::ios::app);

        if (outFile) outFile << data << std::endl;

        // Log data to file
        else std::cerr << "Error: Unable to open file " << fileName << std::endl;

         // Log error if file fails to open
    }
};

// Function for acquiring and processing sensor data

void acquireAndProcessData(Sensor* sensor, DataProcessor* processor, const std::string& logFile, int intervalMs)
 {
    while (true)
        {
        double rawData = sensor->generateRawData();

         // Generate raw sensor data
        double processedData = processor->filterData(sensor->sensorType, rawData);

         // Filter sensor data

        // Prepare log line

        std::ostringstream logLine;

        if (processedData != -1.0)
            {

            logLine << "[" << sensor->sensorType << "] "

                    << std::fixed << std::setprecision(2) << processedData << " " << sensor->unit;
                    // Log valid data
        }
         else
            {
            logLine << "[" << sensor->sensorType << "] Invalid data (filtered)";

            // Log invalid data
        }

        Logger::logData(logFile, logLine.str());

        // Log data to file
        std::cout << logLine.str() << std::endl;

         // Print log to console

        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));

        // Wait before next data acquisition
    }
}

// Resource management structure

struct Resource {
    std::string name;

        // Resource name
    int total, available;

      // Total and available quantities
    std::map<std::string, int> allocationMap;

    // Map for allocations

    // Constructor for Resource structure

    Resource(std::string resourceName, int totalQuantity)

        : name(resourceName), total(totalQuantity), available(totalQuantity) {}

    // Allocate resources

    bool allocate(int quantity, const std::string& unit)

    {
        if (quantity <= available)

            {
            available -= quantity;
        // Deduct allocated quantity

            allocationMap[unit] += quantity;

             // Record allocation
            return true;
        }
        return false;

        // Allocation failed
    }

    // Release allocated resources

    void release(int quantity, const std::string& unit)
    {
        if (allocationMap.find(unit) != allocationMap.end() && allocationMap[unit] >= quantity)

            {
            allocationMap[unit] -= quantity;
        // Release allocated quantity

            available += quantity;

            // Add back to available resources
            if (allocationMap[unit] == 0) allocationMap.erase(unit);

            // Remove entry if zero
        }
    }

    // Display resource status

    void displayStatus() const
     {

        std::cout << name << ": Available = " << available << " / " << total << std::endl;

        // Display resource status

        for (const auto& allocation : allocationMap)

            {
            std::cout << "  Allocated to " << allocation.first << ": " << allocation.second << std::endl;
        }
    }

    // Replenish resources

    void replenish(int amount)
     {
        available += amount;

        // Add to available resources

        if (available > total) available = total;

        // Ensure it does not exceed total
    }
};

// Task structure for resource allocation

struct Task
{
    std::string name, unit;

    int vehicleReq, ammoReq, personnelReq, priority;

    // Constructor for Task structure

    Task(std::string taskName, std::string unitName, int vehicles, int ammo, int personnel, int prio)

        : name(taskName), unit(unitName), vehicleReq(vehicles), ammoReq(ammo), personnelReq(personnel), priority(prio) {}
};

// Function to compare tasks by priority

bool comparePriority(const Task& t1, const Task& t2)
 {
    return t1.priority > t2.priority;

     // Higher priority first


}

// Resource manager class

class ResourceManager
{
private:
    Resource vehicles, ammunition, personnel;

    std::ofstream logFile;

public:


    // Constructor for ResourceManager


    ResourceManager(int totalVehicles, int totalAmmo, int totalPersonnel)

        : vehicles("Vehicles", totalVehicles), ammunition("Ammunition", totalAmmo), personnel("Personnel", totalPersonnel)
        {
        logFile.open("log.txt", std::ios::out | std::ios::app);

        // Open log file
    }

    ~ResourceManager()
    {
        if (logFile.is_open()) logFile.close();

        // Close log file
    }

    // Allocate resources for a task

    bool allocateResources(const Task& task)
    {
        logFile << "Processing task: " << task.name << " from " << task.unit << std::endl;

         // Log task processing

        bool vehicleAllocated = vehicles.allocate(task.vehicleReq, task.unit);

        bool ammoAllocated = ammunition.allocate(task.ammoReq, task.unit);

        bool personnelAllocated = personnel.allocate(task.personnelReq, task.unit);

        if (vehicleAllocated && ammoAllocated && personnelAllocated)

            {
            logFile << "Task " << task.name << " allocated successfully to " << task.unit << ".\n";
        // Success log

            return true;

        }
        else
         {
            if (vehicleAllocated) vehicles.release(task.vehicleReq, task.unit);

            if (ammoAllocated) ammunition.release(task.ammoReq, task.unit);

            if (personnelAllocated) personnel.release(task.personnelReq, task.unit);

            logFile << "Task " << task.name << " failed due to insufficient resources for unit " << task.unit << ".\n";
            // Failure log
            return false;
        }
    }

    // Release resources allocated to a task

    void releaseResources(const Task& task)
     {
         // Release vehicle resources

        vehicles.release(task.vehicleReq, task.unit);

        // Release ammunition resources

        ammunition.release(task.ammoReq, task.unit);

        // Release personnel resources

        personnel.release(task.personnelReq, task.unit);

        logFile << "Resources released for task: " << task.name << " from unit " << task.unit << "\n";
        // Log resource release

    }

    // Display the status of all resources

    void displayAllResources() const
    {
        // Display vehicle resources

        vehicles.displayStatus();

        // Display ammunition resources

        ammunition.displayStatus();

        // Display personnel resources

        personnel.displayStatus();
    }

    // Replenish resources

    void replenishResources(int vehicleAmount, int ammoAmount, int personnelAmount)
     {
        vehicles.replenish(vehicleAmount);

        // Replenish vehicles
        ammunition.replenish(ammoAmount);

        // Replenish ammunition
        personnel.replenish(personnelAmount);

        // Replenish personnel

        logFile << "Resources replenished: " << vehicleAmount << " vehicles, "

                << ammoAmount << " ammo, " << personnelAmount << " personnel.\n";

                 // Log replenishment

        std::cout << "Resources replenished: " << vehicleAmount << " vehicles, "

                  << ammoAmount << " ammo, " << personnelAmount << " personnel.\n";

                   // Console output

        displayAllResources();
    }

    // Process tasks dynamically

    void processTaskDynamically()
     {
        std::vector<Task> tasks;

        while (true)
            {
            std::string taskName, unit;

            int vehicleReq, ammoReq, personnelReq, priority;

            // Input task details

            std::cout << "Enter task name (or 'exit' to quit): ";

            std::cin >> taskName;

            if (taskName == "exit") break;

            // Exit loop

            std::cout << "Enter unit name: ";

            std::cin >> unit;

            std::cout << "Enter vehicle requirement: ";

            std::cin >> vehicleReq;


            std::cout << "Enter ammunition requirement: ";

            std::cin >> ammoReq;


            std::cout << "Enter personnel requirement: ";

            std::cin >> personnelReq;

            std::cout << "Enter priority (higher number = higher priority): ";

            std::cin >> priority;

            // Create task and add to vector

            Task task(taskName, unit, vehicleReq, ammoReq, personnelReq, priority);

            tasks.push_back(task);

            std::sort(tasks.begin(), tasks.end(), comparePriority);

             // Sort by priority

            // Process tasks

            for (const auto& task : tasks)

                {
                if (allocateResources(task))

                {
                    std::cout << "Task " << task.name << " allocated successfully!\n";
                }
            else
                 {
                    std::cout << "Task " << task.name << " failed due to insufficient resources.\n";
                }
            }
            displayAllResources();
            // Display resource status
        }
    }


    void Function()
     {
        std::cout << "This is a  function " ;

        //  message
    }
};

// Location structure for device monitoring

struct Location
{
    double latitude, longitude;

    // Constructor for Location structure

    Location(double lat = 0.0, double lon = 0.0) : latitude(lat), longitude(lon) {}

    // Update location with random values

    void updateLocation()
    {
        latitude += (rand() % 200 - 100) / 1000.0;

        // Simulate random location update

        longitude += (rand() % 200 - 100) / 1000.0;

        // Simulate random location update
    }

    // Display location details

    void display() const
     {
        std::cout << std::fixed << std::setprecision(6)

                  << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;

                  // Display location
    }
};


// Device class for monitoring system

class Device
 {
private:

    std::string id;

    // Device ID

    Location location;

     // Device location

public:

    // Constructor for Device class

    Device(const std::string& deviceId) : id(deviceId), location() {}

    // Get device ID

    const std::string& getId() const { return id; }

    // Get device location

    Location& getLocation() { return location; }

    // Update device location

    void updateLocation() { location.updateLocation(); }

    // Display device details

    void display() const
    {
        std::cout << "Device ID: " << id << " - ";
        location.display();
    }


    void DeviceFunction()

    {
        std::cout << "This is a  function in the Device class.\n";
    }
};

// Monitoring system class for managing devices

class MonitoringSystem
{
private:
    std::vector<Device> devices;

    // List of devices

public:

    // Constructor for MonitoringSystem class

    MonitoringSystem() {}

    // Add a device to the monitoring system

    void addDevice(const Device& device)
    {
        devices.push_back(device);

        // Add device to vector
    }

    // Update the locations of all devices

    void updateDeviceLocations()
     {
        for (auto& device : devices)
            {
            device.updateLocation(); // Update each device location
        }
    }

    // Display details of all devices

    void displayAllDevices() const

    {
        std::cout << "\nReal-Time Location Monitoring:\n";

        for (const auto& device : devices)

            {
            device.display();
        }
    }
};

void FunctionCode()
{
    // Simulate complex military logistics and supply chain operations

    // Step 1: Initialize inventory levels for various supplies

    std::map<std::string, int> inventory =

     {
        {"Food Rations", 5000},

        {"Ammunition", 15000},

        {"Medical Supplies", 3000},

        {"Fuel", 10000},

        {"Water", 8000}
    };

    // Step 2: Simulate daily consumption over a 14-day period

    for (int day = 1; day <= 14; ++day)
    {
        std::cout << "Day " << day << ": Logistics status update" << std::endl;

        // Daily consumption of food

        inventory["Food Rations"] -= 250;

        // Daily usage of ammunition

        inventory["Ammunition"] -= 1000;

        // Daily usage of medical supplies

        inventory["Medical Supplies"] -= 200;

        // Fuel consumption

        inventory["Fuel"] -= 500;

        // Daily water consumption

        inventory["Water"] -= 400;

        // Generate a random event affecting supplies

        if (rand() % 5 == 0)
            {
            std::cout << "Emergency situation: Increased consumption!" << std::endl;

            inventory["Food Rations"] -= 100;

            inventory["Water"] -= 100;

            inventory["Medical Supplies"] -= 100;
        }

        // Check for resupply needs

        for (auto &item : inventory)
        {
            if (item.second < 1000)
            {
                std::cout << "Day " << day << ": " << item.first << " needs immediate resupply!" << std::endl;

                item.second += 5000;
                // Resupply action
            }
        }
    }

    // Step 3: Calculate logistics weight and prioritize transportation

    std::map<std::string, int> itemWeights =
    {
        {"Food Rations", 2},

        // Weight per unit in kg

        {"Ammunition", 10},

        {"Medical Supplies", 3},

        {"Fuel", 20},

        {"Water", 1}
    };

    int totalWeight = 0;

    for (const auto &item : inventory)
    {
        totalWeight += item.second * itemWeights[item.first];
    }

    std::cout << "Total logistics weight after operations: " << totalWeight << " kg\n";

    // Step 4: Assign transport vehicles to supply loads

    std::vector<std::string> transportVehicles = {"Truck A", "Truck B", "Helicopter C", "Cargo Plane D"};

    std::map<std::string, int> vehicleCapacity =
    {
        {"Truck A", 10000},

        {"Truck B", 8000},

        {"Helicopter C", 6000},

        {"Cargo Plane D", 50000}
    };

    std::cout << "Transport assignment:\n";

    for (const auto &vehicle : transportVehicles)

    {
        std::cout << vehicle << " - Capacity: " << vehicleCapacity[vehicle] << " kg\n";
    }

    // Step 5: Simulate route planning and execution

    std::vector<std::string> routes =
    {
        "Base to Outpost Alpha",

        "Base to Outpost Beta",

        "Base to Forward Operating Base",

        "Base to Outpost Gamma"
    };

    for (const auto &route : routes)

    {
        std::cout << "Route planned: " << route << "\n";

        int loadDelivered = rand() % 4000 + 1000;

        std::cout << "Load delivered: " << loadDelivered << " kg\n";
    }

    // Step 6: Report on efficiency metrics

    double efficiency = (rand() % 20 + 80) / 100.0;

    std::cout << "Overall supply chain efficiency: " << efficiency * 100 << "%\n";

    // Step 7: Conduct after-action review

    std::cout << "After-action review:\n";

    for (const auto &item : inventory)
    {
        std::cout << item.first << " remaining: " << item.second << " units\n";
    }

    std::cout << "Military logistics simulation complete." << std::endl;
}



// Monitoring system class for managing devices


// Function to print the optimized route

void printOptimizedRoute(const std::vector<int>& optimizedRoute, const std::vector<std::string>& locations, int totalDistance)
{
    std::cout << "Optimized Route: ";

    for (int i = 0; i < optimizedRoute.size(); ++i)

        {
        std::cout << locations[optimizedRoute[i]];

        if (i < optimizedRoute.size() - 1)

            {

            std::cout << " -> ";

        }
    }

    std::cout << "\nTotal Distance: " << totalDistance << "\n";
}

// Function to display the distance matrix

void printDistanceMatrix(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<std::string>& locations)
 {
    int numLocations = distanceMatrix.size();

    std::cout << "Distance Matrix:\n";

    std::cout << std::setw(15) << " ";

    for (const auto& location : locations)

        {
        std::cout << std::setw(10) << location;
    }
    std::cout << "\n";

    for (int i = 0; i < numLocations; ++i)
        {

        std::cout << std::setw(15) << locations[i];

        for (int j = 0; j < numLocations; ++j)

        {
            std::cout << std::setw(10) << distanceMatrix[i][j];
        }
        std::cout << "\n";
    }
}

// Function to perform rote optimization for military logistics and supply chain with additional optimizations

void roteOptimization(

    const std::vector<std::vector<int>>& distanceMatrix,

    const std::vector<std::string>& locations,

    const int startLocationIndex,

    std::vector<int>& optimizedRoute,


    bool printSteps = false)
{
    int numLocations = distanceMatrix.size();

    std::vector<bool> visited(numLocations, false);

    visited[startLocationIndex] = true;

    optimizedRoute.push_back(startLocationIndex);


     int totalDistance = 0;

    int currentLocation = startLocationIndex;

    if (printSteps)
        {

        std::cout << "Starting from location: " << locations[startLocationIndex] << "\n";
    }

    // Greedy algorithm for nearest neighbor approach

    for (int i = 1; i < numLocations; ++i)
        {

        int nearestLocation = -1;

        int shortestDistance = INT_MAX;

        for (int j = 0; j < numLocations; ++j)
            {
            if (!visited[j] && distanceMatrix[currentLocation][j] < shortestDistance)
                {
                nearestLocation = j;

                shortestDistance = distanceMatrix[currentLocation][j];
            }
        }

        visited[nearestLocation] = true;

        optimizedRoute.push_back(nearestLocation);

        totalDistance += shortestDistance;

        currentLocation = nearestLocation;

        if (printSteps)

            {
            std::cout << "Visited " << locations[nearestLocation] << ", Distance: " << shortestDistance << "\n";
        }
    }

    // Closing the loop to the start location

    totalDistance += distanceMatrix[currentLocation][startLocationIndex];

    optimizedRoute.push_back(startLocationIndex);

    if (printSteps)

        {

        std::cout << "Returning to " << locations[startLocationIndex] << ", Distance: " << distanceMatrix[currentLocation][startLocationIndex] << "\n";
    }

    if (printSteps)

        {

        std::cout << "Optimization completed.\n";
    }
}


// Function to perform multiple optimizations (for different starting locations)

void performMultipleOptimizations
(
    const std::vector<std::vector<int>>& distanceMatrix,

    const std::vector<std::string>& locations,

    std::vector<std::vector<int>>& allOptimizedRoutes,

    std::vector<int>& totalDistances,

    bool printSteps = false)
{
    int numLocations = locations.size();

    for (int startLocationIndex = 0; startLocationIndex < numLocations; ++startLocationIndex)

        {
        std::vector<int> optimizedRoute;

        int totalDistance = 0;

        //roteOptimization(distanceMatrix, locations, startLocationIndex, optimizedRoute, totalDistance, printSteps);

        allOptimizedRoutes.push_back(optimizedRoute);

        totalDistances.push_back(totalDistance);
    }
}

// Function to find the best route out of all optimized routes

void findBestRoute
(
    const std::vector<std::vector<int>>& allOptimizedRoutes,

    const std::vector<int>& totalDistances,

    const std::vector<std::string>& locations)

{
    int bestRouteIndex = -1;

    int bestDistance = INT_MAX;

    for (int i = 0; i < totalDistances.size(); ++i)

        {
        if (totalDistances[i] < bestDistance)
         {
            bestDistance = totalDistances[i];

            bestRouteIndex = i;
        }
    }

    if (bestRouteIndex != -1)

        {

        std::cout << "Best Route found (starting from " << locations[allOptimizedRoutes[bestRouteIndex][0]] << "):\n";

        printOptimizedRoute(allOptimizedRoutes[bestRouteIndex], locations, bestDistance);

    }
    else

    {
        std::cout << "No valid routes found.\n";
    }
}

// Function to run a detailed optimization and print results

void runOptimizations
(
    const std::vector<std::vector<int>>& distanceMatrix,

    const std::vector<std::string>& locations,

    bool printSteps = false)
{
    std::vector<std::vector<int>> allOptimizedRoutes;

    std::vector<int> totalDistances;

    performMultipleOptimizations(distanceMatrix, locations, allOptimizedRoutes, totalDistances, printSteps);

    findBestRoute(allOptimizedRoutes, totalDistances, locations);
}


// Enum to represent different threat levels

enum class ThreatLevel
{
    Low,

    Moderate,

    High,

    Critical
};

// Structure to store resource and supply chain data


struct LogisticsData
{
    int resourceAvailability;

    int transportRoutes;

    int enemyActivity;

    int environmentalHazards;

    int timeToComplete;


    // Flag to represent whether there's a disruption

    bool supplyChainDisruption;

    // Weather impact factor (e.g., scale 1-10)

    int weatherSeverity;

    // Geopolitical risk (e.g., scale 1-10)

    int geopoliticalRisk;
};

// Function to calculate threat level based on various logistics data

ThreatLevel calculateThreatLevel(const LogisticsData& data)
 {
    int threatScore = 0;

    // Resource availability: If resources are low, it increases the threat

    threatScore += (100 - data.resourceAvailability) / 10;

    // Transport routes: If routes are fewer or vulnerable, the threat is higher

    threatScore += (5 - data.transportRoutes) * 2;

    // Enemy activity: Higher enemy activity increases the threat level

    threatScore += data.enemyActivity * 3;

    // Environmental hazards: Extreme environmental conditions raise the threat

    threatScore += data.environmentalHazards * 2;

    // Time to complete: Longer times increase vulnerability to threats

    threatScore += data.timeToComplete / 10;

    // Supply chain disruption: If there's disruption, threat level increases

    if (data.supplyChainDisruption)
        {
        threatScore += 5;

    // Disruptions are significant
    }

    // Weather severity: Severe weather conditions (scale 1-10)

    threatScore += data.weatherSeverity * 2;

    // Geopolitical risk: High geopolitical tensions (scale 1-10) contribute to risk

    threatScore += data.geopoliticalRisk * 3;

    // Determine the threat level based on the score

    if (threatScore < 10)

        {

        return ThreatLevel::Low;

    }
     else if (threatScore < 20)

     {
        return ThreatLevel::Moderate;

    }
     else if (threatScore < 30)

     {
        return ThreatLevel::High;

    }
    else

     {
        return ThreatLevel::Critical;
    }
}

// Function to simulate dynamic updates to threat levels over time

void updateThreatLevels(std::vector<LogisticsData>& logisticsDataList)
 {

    for (auto& data : logisticsDataList)
        {

        // Randomly modify some factors for simulation purposes

       // Simulate resource depletion

        data.resourceAvailability -= rand() % 5;

        // Simulate increased enemy activity

        data.enemyActivity += rand() % 3;

        // Simulate worsening weather conditions

        data.weatherSeverity += rand() % 2;

        // Simulate rising geopolitical risk

        data.geopoliticalRisk += rand() % 2;

        // Ensure values stay within reasonable bounds

        if (data.resourceAvailability < 0) data.resourceAvailability = 0;

        if (data.enemyActivity > 5) data.enemyActivity = 5;

        if (data.weatherSeverity > 10) data.weatherSeverity = 10;

        if (data.geopoliticalRisk > 10) data.geopoliticalRisk = 10;

        // Randomly determine if supply chain disruption occurs

        data.supplyChainDisruption = rand() % 2 == 0;

        // Calculate new threat level based on updated data

        ThreatLevel level = calculateThreatLevel(data);

        std::string levelStr;

        switch (level)
        {
            case ThreatLevel::Low: levelStr = "Low"; break;

            case ThreatLevel::Moderate: levelStr = "Moderate"; break;

            case ThreatLevel::High: levelStr = "High"; break;

            case ThreatLevel::Critical: levelStr = "Critical"; break;
        }

        // Display updated threat level information

        std::cout << "Updated Logistics Data:\n";

        std::cout << "Resource Availability: " << data.resourceAvailability << "%\n";

        std::cout << "Transport Routes: " << data.transportRoutes << "\n";

        std::cout << "Enemy Activity: " << data.enemyActivity << "\n";

        std::cout << "Environmental Hazards: " << data.environmentalHazards << "\n";

        std::cout << "Time to Complete (hrs): " << data.timeToComplete << "\n";

        std::cout << "Supply Chain Disruption: " << (data.supplyChainDisruption ? "Yes" : "No") << "\n";

        std::cout << "Weather Severity: " << data.weatherSeverity << "\n";

        std::cout << "Geopolitical Risk: " << data.geopoliticalRisk << "\n";

        std::cout << "Updated Threat Level: " << levelStr << "\n\n";
    }
}

// Function to simulate threat level assessment and display the results for multiple scenarios

void assessAndUpdateThreatLevels(std::vector<LogisticsData>& logisticsDataList, int numUpdates)
{
    // Display initial threat levels

    std::cout << "Initial Threat Levels:\n";

    for (const auto& data : logisticsDataList)
        {

        ThreatLevel level = calculateThreatLevel(data);

        std::string levelStr;

        switch (level)
        {
            case ThreatLevel::Low: levelStr = "Low"; break;

            case ThreatLevel::Moderate: levelStr = "Moderate"; break;

            case ThreatLevel::High: levelStr = "High"; break;

            case ThreatLevel::Critical: levelStr = "Critical"; break;
        }

        std::cout << "Resource Availability: " << data.resourceAvailability << "%\n";

        std::cout << "Transport Routes: " << data.transportRoutes << "\n";

        std::cout << "Enemy Activity: " << data.enemyActivity << "\n";

        std::cout << "Environmental Hazards: " << data.environmentalHazards << "\n";

        std::cout << "Time to Complete (hrs): " << data.timeToComplete << "\n";

        std::cout << "Supply Chain Disruption: " << (data.supplyChainDisruption ? "Yes" : "No") << "\n";

        std::cout << "Weather Severity: " << data.weatherSeverity << "\n";

        std::cout << "Geopolitical Risk: " << data.geopoliticalRisk << "\n";

        std::cout << "Threat Level: " << levelStr << "\n\n";
    }

    // Simulate updates over time

    for (int i = 0; i < numUpdates; ++i)
        {
        std::cout << "Update #" << (i + 1) << ":\n";

        updateThreatLevels(logisticsDataList);

        std::this_thread::sleep_for(std::chrono::seconds(5));  // Simulate time delay between updates
    }
}


// Define the Terrain structure

struct Terrain {

    std::string name;

    // A multiplier to adjust the difficulty of the terrain


    double difficultyFactor;

    // Type of terrain (e.g., "mountain", "desert", "forest", etc.)

    std::string terrainType;

    // Whether the terrain is considered rough (e.g., mountain, dense forest)

    bool isRough;
};

// Define the SupplyRoute structure

struct SupplyRoute {

    std::string start;

    std::string end;

    double distance;

    Terrain terrain;

    SupplyRoute(const std::string& start, const std::string& end, double distance, const Terrain& terrain)

        : start(start), end(end), distance(distance), terrain(terrain) {}
};

// Define the LogisticsSystem class



class LogisticsSystem
 {

public:

    std::vector<SupplyRoute> supplyRoutes;

    // Member function to create terrain

    Terrain createTerrain(const std::string& name, double difficultyFactor, const std::string& terrainType, bool isRough)

     {
        Terrain terrain;

        terrain.name = name;

        terrain.difficultyFactor = difficultyFactor;

        terrain.terrainType = terrainType;

        terrain.isRough = isRough;

        return terrain;
    }

    // Member function to add supply route

    void addSupplyRoute(const std::string& start, const std::string& end, double distance, const Terrain& terrain)
     {
        supplyRoutes.push_back(SupplyRoute(start, end, distance, terrain));
    }

    // Function to display supply routes

    void displaySupplyRoutes()
    {
        for (const auto& route : supplyRoutes)
            {
            std::cout << "From " << route.start << " to " << route.end << " with distance: "

                      << route.distance << " km and terrain: " << route.terrain.name << std::endl;
        }
    }
};

// Define the TerrainDifficultyCalculator class



class TerrainDifficultyCalculator
{
public:
    // Function to calculate the terrain difficulty

    double calculateTerrainDifficulty(const Terrain& terrain)
    {
        double adjustedDifficulty = terrain.difficultyFactor;

        // Adjust difficulty based on terrain type

        if (terrain.terrainType == "mountain")
            {
            adjustedDifficulty *= 2.0;

             // Mountains are twice as difficult
        }
        else if (terrain.terrainType == "desert")
        {
            adjustedDifficulty *= 1.5;

             // Deserts increase difficulty by 50%
        }
        else if (terrain.terrainType == "forest")
            {
            adjustedDifficulty *= 1.2;

            // Forests increase difficulty by 20%
        }

        // Further adjustment for rough terrain

        if (terrain.isRough)
            {
            adjustedDifficulty *= 1.5;

             // Rough terrains are 50% more difficult
        }

        return adjustedDifficulty;
    }

    // Function to display the terrain information



    void displayTerrainInfo(const Terrain& terrain)
    {
        std::cout << "Terrain Name: " << terrain.name << std::endl;

        std::cout << "Terrain Type: " << terrain.terrainType << std::endl;

        std::cout << "Difficulty Factor: " << terrain.difficultyFactor << std::endl;

        std::cout << "Is Rough: " << (terrain.isRough ? "Yes" : "No") << std::endl;
    }

    // Function to modify terrain difficulty dynamically

    void modifyTerrainDifficulty(Terrain& terrain, double newDifficulty)
     {
        terrain.difficultyFactor = newDifficulty;

        std::cout << "Terrain difficulty updated to: " << terrain.difficultyFactor << std::endl;
    }

    // Function to get a description of terrain based on its type

    std::string getTerrainDescription(const Terrain& terrain)
    {
        if (terrain.terrainType == "mountain")
            {
            return "Steep and difficult to navigate, often requiring specialized equipment.";
        }

        else if (terrain.terrainType == "desert")
         {
            return "Hot, arid, and harsh conditions with limited resources.";
         }

        else if (terrain.terrainType == "forest")
            {
            return "Dense and often difficult to traverse, with thick vegetation.";
        }
        else
            {
            return "A relatively simple terrain with minimal obstacles.";
        }
    }
};



// Assuming necessary structures and classes are already defined (e.g., LogisticsSystem, Device, Terrain, etc.)





class UserAuthentication
{
private:
    struct User
    {
        std::string username;

        std::string password;

        std::string role;

        // Role of the user (Admin, Logistics, Soldier, etc.)

        bool isAuthenticated;
    };

    std::map<std::string, User> userDatabase;

    // A simple log system

    std::vector<std::string> logs;

    // To track active user sessions

    std::map<std::string, std::string> activeSessions;

public:

    // Function to register a new user

    void registerUser(const std::string& username, const std::string& password, const std::string& role)

    {
        if (userDatabase.find(username) != userDatabase.end())

            {
            std::cout << "User already exists: " << username << std::endl;
        }
         else
            {
            User newUser{username, password, role, false};

            userDatabase[username] = newUser;

            logAction("User registered: " + username);

            std::cout << "User " << username << " registered successfully!" << std::endl;
        }
    }

    // Function to authenticate a user

    bool authenticateUser(const std::string& username, const std::string& password)
     {
        if (userDatabase.find(username) != userDatabase.end())

            {
            User& user = userDatabase[username];

            if (user.password == password)

             {
                user.isAuthenticated = true;

                activeSessions[username] = generateSessionId(username);

                logAction("User authenticated: " + username);

                std::cout << "Authentication successful for " << username << std::endl;

                return true;

            }

        else
            {
                std::cout << "Incorrect password for " << username << std::endl;
                return false;
            }
        }
         else

            {
            std::cout << "Username not found: " << username << std::endl;

            return false;
        }
    }

    // Function to change the password for a user

    bool changePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword)
     {
        if (userDatabase.find(username) != userDatabase.end())
            {
            User& user = userDatabase[username];

            if (user.password == oldPassword)

             {
                user.password = newPassword;

                logAction("Password changed for: " + username);

                std::cout << "Password updated successfully for " << username << std::endl;

                return true;
            }

        else {
                std::cout << "Old password is incorrect for " << username << std::endl;

                return false;
            }
        }
         else

            {
            std::cout << "Username not found: " << username << std::endl;

            return false;
        }
    }

    // Function to delete a user from the system

    bool deleteUser(const std::string& username, const std::string& password)
     {
        if (userDatabase.find(username) != userDatabase.end())
            {

            User& user = userDatabase[username];

            if (user.password == password)

             {
                userDatabase.erase(username);

                logAction("User deleted: " + username);

                std::cout << "User " << username << " deleted successfully." << std::endl;

                return true;
            }

        else {
                std::cout << "Incorrect password for " << username << std::endl;
                return false;
            }
        }

         else

            {
            std::cout << "Username not found: " << username << std::endl;

            return false;
        }
    }

    // Function to log actions

    void logAction(const std::string& action)
    {
        std::time_t now = std::time(nullptr);

        char timestamp[100];

        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        logs.push_back("[" + std::string(timestamp) + "] " + action);
    }

    // Function to display logs

    void displayLogs()
     {
        std::cout << "System Logs: \n";

        for (const auto& log : logs)
            {

            std::cout << log << std::endl;
        }
    }

    // Function to generate a session ID for active users

    std::string generateSessionId(const std::string& username)

    {
        std::hash<std::string> hash_fn;

        size_t hash = hash_fn(username + std::to_string(std::time(0)));

        return std::to_string(hash);
    }

    // Function to verify session validity

    bool verifySession(const std::string& sessionId)
    {
        for (const auto& session : activeSessions)
            {
            if (session.second == sessionId)
            {
                return true;
            }
        }
        return false;
    }

    // Function to display the users and their roles

    void displayUsers()
     {
        std::cout << "Registered users: \n";

        for (const auto& userPair : userDatabase)

            {
            const User& user = userPair.second;

            std::cout << "Username: " << user.username << ", Role: " << user.role << std::endl;
        }
    }

    // Function to check if a user has admin privileges



    bool hasAdminPrivileges(const std::string& username)
    {
        if (userDatabase.find(username) != userDatabase.end())
            {
            return userDatabase[username].role == "Admin";
        }
        return false;
    }

    // Function to assign roles to users

    void assignRole(const std::string& username, const std::string& role)
     {
        if (userDatabase.find(username) != userDatabase.end())

            {
            userDatabase[username].role = role;

            logAction("Role updated for user: " + username);

            std::cout << "Role for " << username << " updated to " << role << std::endl;
        }
         else

        {
            std::cout << "User not found: " << username << std::endl;
        }
    }

    // Function to view all active sessions



    void viewActiveSessions()
    {
        std::cout << "Active sessions: \n";

        for (const auto& session : activeSessions)

            {

            std::cout << "Username: " << session.first << ", Session ID: " << session.second << std::endl;
        }
    }

    // Function to logout a user

    void logoutUser(const std::string& username)

    {
        if (activeSessions.find(username) != activeSessions.end())

            {
            activeSessions.erase(username);

            logAction("User logged out: " + username);

            std::cout << "User " << username << " logged out successfully." << std::endl;
        }

        else

        {
            std::cout << "No active session for user: " << username << std::endl;
        }
    }

    // Function to retrieve the role of a user

    std::string getUserRole(const std::string& username)
    {
        if (userDatabase.find(username) != userDatabase.end())
            {

            return userDatabase[username].role;
        }
        else

        {
            return "User not found";
        }
    }

    // Function to check if a user is authenticated

    bool isAuthenticated(const std::string& username)

    {
        if (userDatabase.find(username) != userDatabase.end())
            {

            return userDatabase[username].isAuthenticated;

        }
        return false;
    }

    // Function to simulate user operations for demonstration

    void simulateUserOperations()
     {
        registerUser("admin", "admin123", "Admin");

        registerUser("logistics", "log123", "Logistics");

        registerUser("soldier", "sol123", "Soldier");

        authenticateUser("admin", "admin123");

        authenticateUser("logistics", "log123");

        displayUsers();

        assignRole("soldier", "Commander");

        assignRole("logistics", "Logistics Officer");

        changePassword("logistics", "log123", "log456");

        viewActiveSessions();

        logoutUser("logistics");
    }
};



// Assuming the LogisticsManager class and other necessary classes like ResourceManager, MonitoringSystem, etc. are defined above




// Structure to represent a supply item




// Assuming the LogisticsManager class and other necessary classes like ResourceManager, MonitoringSystem, etc. are defined above



// Structure to represent a supply item



struct User

{
    string username;

    string password;

    string role;
};

// Example function to reset password


void resetPassword(User& user)

{
    string newPassword;

    cout << "\nEnter new password: ";

    // Hide the new password input

    char ch;

    newPassword = "";

    while (true)

        {
        ch = _getch();

        if (ch == 13)
        {

                // Enter key pressed
            break;

        }
         else if (ch == 8 && newPassword.length() > 0)

        {
            // Backspace key handling

            newPassword.pop_back();

            cout << "\b \b";

            // Erase the last character
        }
        else

            {
            newPassword += ch;

            cout << "*";

            // Display '*' for each character
        }
    }
    user.password = newPassword;

    cout << "\nPassword reset successfully!\n";
}

bool validateLogin(const string& username, const string& password, const string& role)

 {
    // Example hardcoded users

    User validUsers[] =

    {
        {"captain123", "pass123", "Captain"},

        {"major123", "pass123", "Major"}
    };

    // Check if the username, password, and role match any of the valid users

    for (auto& user : validUsers)

        {

        if (user.username == username && user.password == password && user.role == role)

        {
            return true;

    // Login successful
        }
    }
    return false;

    // Login failed
}

void placeOrder(const string& role)

{
    cout << "\nWelcome, " << role << "! You are now authorized to place an order.\n";

    // Example order process (this can be expanded with real order functionality)


    cout << "Enter your order details below:\n";

    // Order logic goes here...

    cout << "Order placed successfully!\n";
}

void hidePasswordInput(string& password)

 {
    char ch;

    password = "";

    while (true)

        {
        ch = _getch();

    // Get a character from input without displaying it

        if (ch == 13)

            {

                // Enter key is pressed
            break;

        }
        else if (ch == 8 && password.length() > 0)

            {
                // Backspace key handling
            password.pop_back();

            cout << "\b \b";

            // Erase the last character from console output
        }
        else

            {
            password += ch;

            cout << "*";

            // Display '*' for each character typed
        }
    }
}





// Function to create a file with 10 real-time locations in India
void createLocationFile(const string &filename)
{
    ofstream file(filename);
    if (!file)
    {
        cerr << "\033[1;31mError: Unable to create file!\033[0m\n";
        return;
    }

    // Define 10 Indian cities and distances
    file << "Delhi Mumbai Chennai Kolkata Bangalore Hyderabad Ahmedabad Pune Jaipur Lucknow\n";
    int distances[10][10] = {
        {0, 1400, 2200, 1500, 2100, 1500, 900, 1400, 270, 500},
        {1400, 0, 1330, 2000, 980, 710, 520, 150, 1140, 580},
        {2200, 1330, 0, 1670, 360, 630, 1780, 1190, 2040, 2100},
        {1500, 2000, 1670, 0, 1860, 1500, 1700, 1850, 1520, 1000},
        {2100, 980, 360, 1860, 0, 570, 1230, 840, 1800, 1900},
        {1500, 710, 630, 1500, 570, 0, 1200, 560, 1500, 800},
        {900, 520, 1780, 1700, 1230, 1200, 0, 720, 500, 900},
        {1400, 150, 1190, 1850, 840, 560, 720, 0, 1180, 720},
        {270, 1140, 2040, 1520, 1800, 1500, 500, 1180, 0, 780},
        {500, 580, 2100, 1000, 1900, 800, 900, 720, 780, 0}};

    // Write distances to the file
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            file << distances[i][j] << (j == 9 ? "\n" : " ");
        }
    }

    file.close();
    cout << "\033[1;32mFile '" << filename << "' created successfully!\033[0m\n";
}

// Function to read locations and distances from the file
void readLocations(const string &filename, vector<string> &locations, vector<vector<int>> &distances)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "\033[1;31mError: Unable to read file!\033[0m\n";
        return;
    }

    string line;

    // Read locations
    getline(file, line);
    string loc;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            locations.push_back(loc);
            loc.clear();
        }
        else
        {
            loc += line[i];
        }
    }
    if (!loc.empty())
        locations.push_back(loc);

    // Read distances
    while (getline(file, line))
    {
        vector<int> row;
        size_t pos = 0;
        while ((pos = line.find(' ')) != string::npos)
        {
            row.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        if (!line.empty())
            row.push_back(stoi(line));
        distances.push_back(row);
    }

    file.close();
    cout << "\033[1;32mFile '" << filename << "' read successfully!\033[0m\n";
}

// Function to display the adjacency matrix of distances in a clean and neat table format
void displayAdjacencyMatrix(const vector<string> &locations, const vector<vector<int>> &distances)
{
    cout << "\n\033[1;34mAdjacency Matrix (Distances in km):\033[0m\n";

    // Print the top header
    cout << "       ";
    for (const auto &loc : locations)
    {
        cout << setw(10) << loc.substr(0, 8); // Truncate location names to 8 characters for clarity
    }
    cout << endl;

    // Print a separator line for the header
    cout << "       ";
    for (size_t i = 0; i < locations.size(); i++)
    {
        cout << "----------";
    }
    cout << endl;

    // Print each row with distances
    for (size_t i = 0; i < distances.size(); i++)
    {
        cout << setw(7) << locations[i].substr(0, 8) << " "; // Row label
        for (size_t j = 0; j < distances[i].size(); j++)
        {
            cout << setw(10) << distances[i][j];
        }
        cout << endl;
    }

    // Footer separator (optional, for symmetry)
    cout << "       ";
    for (size_t i = 0; i < locations.size(); i++)
    {
        cout << "----------";
    }
    cout << endl;
}

// Function to find all possible routes using a recursive approach and Dijkstra's algorithm
void findRoutes(const vector<vector<int>> &graph, int src, int dest, vector<int> &dist, vector<int> &prev, vector<vector<int>> &allRoutes)
{
    int n = graph.size();
    vector<int> route;

    // Helper function for depth-first search
    std::function<void(int)> dfs = [&](int node)
    {
        route.push_back(node);
        if (node == dest)
        {
            allRoutes.push_back(route);
        }
        else
        {
            for (int v = 0; v < n; v++)
            {
                if (graph[node][v] > 0 && dist[node] + graph[node][v] == dist[v])
                {
                    dfs(v);
                }
            }
        }
        route.pop_back();
    };

    dfs(src);
}

// Function to find the shortest path using Dijkstra's algorithm
pair<vector<int>, vector<int>> dijkstra(const vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, prev};
}

// Function to reconstruct and display the optimized route
void printOptimizedRoute(const vector<int> &prev, int src, int dest, const vector<string> &locations)
{
    vector<int> path;
    for (int at = dest; at != -1; at = prev[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "\n\033[1;33mOptimized Route from " << locations[src] << " to " << locations[dest] << ":\033[0m\n";
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << "\033[1;36m" << locations[path[i]] << "\033[0m";
        if (i < path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

// Function to find all possible routes using a recursive approach and Dijkstra's algorithm
void findRoutes(const vector<vector<int>> &graph, int src, int dest, vector<int> &dist, vector<int> &prev, vector<pair<vector<int>, int>> &allRoutes)
{
    int n = graph.size();
    vector<int> route;
    int currentDistance = 0;

    // Helper function for depth-first search
    std::function<void(int)> dfs = [&](int node)
    {
        route.push_back(node);

        // If this is the destination, save the route and its distance
        if (node == dest)
        {
            allRoutes.push_back({route, currentDistance});
        }
        else
        {
            for (int v = 0; v < n; v++)
            {
                if (graph[node][v] > 0 && dist[node] + graph[node][v] == dist[v])
                {
                    currentDistance += graph[node][v];
                    dfs(v);
                    currentDistance -= graph[node][v];
                }
            }
        }

        route.pop_back();
    };

    dfs(src);
}

// Function to reconstruct and display the optimized route with its distance
void printOptimizedRoute(const vector<int> &prev, int src, int dest, const vector<string> &locations, const vector<vector<int>> &distances)
{
    vector<int> path;
    int totalDistance = 0;

    // Reconstruct the path from source to destination using the prev array
    for (int at = dest; at != -1; at = prev[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // Calculate the total distance by summing up the distances between consecutive locations in the path
    for (size_t i = 0; i < path.size() - 1; i++)
    {
        totalDistance += distances[path[i]][path[i + 1]];
    }

    // Display the optimized route and its distance
    cout << "\n\033[1;33mOptimized Route from " << locations[src] << " to " << locations[dest] << ":\033[0m\n";
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << "\033[1;36m" << locations[path[i]] << "\033[0m";
        if (i < path.size() - 1)
            cout << " -> ";
    }
    cout << " (Distance: " << totalDistance << " km)" << endl;
}

// Function to simulate traffic congestion factor
double getTrafficCongestionFactor(int hour)
{
    double congestionFactor = 1.0;

    // Simulate rush hour congestion
    if ((hour >= 8 && hour <= 9) || (hour >= 17 && hour <= 18))
    {
        congestionFactor = 1.5; // 50% more time during rush hours
    }
    else
    {
        // Random congestion factor between 1.0 and 1.5 during non-rush hours
        congestionFactor = 1.0 + (rand() % 6) / 10.0; // random between 1.0 and 1.5
    }
    return congestionFactor;
}

// Function to display the selected route's distance with traffic congestion
void displaySelectedRouteDistance(const vector<vector<int>> &distances, const vector<string> &locations, int src, int dest, int hour)
{
    double congestionFactor = getTrafficCongestionFactor(hour);

    int originalDistance = distances[src][dest];
    int adjustedDistance = static_cast<int>(originalDistance * congestionFactor);

    // Adding some fancy output formatting
    cout << "\n\033[1;36m==============================\033[0m\n";
    cout << "\033[1;32mTraffic Congestion Simulation\033[0m\n";
    cout << "\033[1;36m==============================\033[0m\n";
    cout << "\033[1;33mHour of the Day: " << hour << " :00\033[0m\n";
    cout << "\033[1;34mCongestion Factor: " << congestionFactor << " (Travel time increased by "
         << (congestionFactor - 1.0) * 100 << "%)\033[0m\n\n";

    cout << "\033[1;35mSelected Route:\033[0m " << locations[src] << " \033[1;37m->\033[0m " << locations[dest] << "\n";
    cout << "\033[1;34mOriginal Distance: \033[0m" << originalDistance << " km\n";
    cout << "\033[1;31mAdjusted Distance (with traffic): \033[0m" << adjustedDistance << " km\n";

    cout << "\n\033[1;36m==============================\033[0m\n";
}

// Vehicle selection function (your provided code here)

enum VehicleType
{
    HEAVY_DUTY = 1,
    MEDIUM,
    LIGHT_VAN,
    SMALL_TRUCK,  // New vehicle type
    ELECTRIC_VAN, // New vehicle type
    CARGO_VAN     // New vehicle type
};

struct Vehicle
{
    VehicleType type;
    string name;
    double fuelEfficiency; // km per liter (default efficiency without load)
    double capacity;       // in tons (for goods, for people assume 3 people per ton)
    double maxSpeed;       // in km/h
    double pricePerKm;     // Price per km for each vehicle type
    int passengerCapacity; // Capacity for people
    double costPerKm;      // Cost per km (including maintenance and other operating costs)

    // Function to calculate fuel cost
    double calculateFuelCost(double distance, double fuelCostPerLiter) const
    {
        double fuelRequired = distance / fuelEfficiency; // Fuel required in liters
        return fuelRequired * fuelCostPerLiter;
    } // Missing closing brace added here

    // Constructor to initialize vehicle
    Vehicle(VehicleType type, string name, double fuelEfficiency, double capacity, double maxSpeed, double pricePerKm, int passengerCapacity, double costPerKm)
        : type(type), name(name), fuelEfficiency(fuelEfficiency), capacity(capacity), maxSpeed(maxSpeed), pricePerKm(pricePerKm), passengerCapacity(passengerCapacity), costPerKm(costPerKm) {}

    // Function to calculate the fuel efficiency based on cargo load (const method)
    double getAdjustedFuelEfficiency(double weight) const
    {
        // Assuming fuel efficiency decreases by 10% for every ton of cargo carried over its own capacity
        double loadFactor = (weight > capacity) ? (weight - capacity) * 0.10 : 0; // 10% decrease for each ton over capacity
        return fuelEfficiency - (fuelEfficiency * loadFactor);
    }

    // Function to display vehicle details
    void displayDetails() const
    {

        // Display the vehicle details with proper alignment
        cout << setw(4) << "" << setw(25) << left << name
             << setw(18) << passengerCapacity
             << setw(18) << capacity
             << setw(22) << fuelEfficiency
             << setw(22) << maxSpeed
             << setw(18) << pricePerKm << endl;
    }
};

// Function to display vehicle details

// Define some subtle color constants using ANSI escape codes
const string CYAN = "\033[1;36m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string RESET = "\033[0m"; // Reset to default color

// Function to display available vehicles (display only once at the start)
void displayVehicles(const vector<Vehicle> &vehicles)
{
    cout << "\n"
         << CYAN << "--------------------------------------------------------------" << RESET << endl;
    cout << CYAN << "          Available Vehicles                                 " << RESET << endl;
    cout << CYAN << "--------------------------------------------------------------" << RESET << endl;

    // Properly formatted column headers with adequate spacing
    cout << setw(4) << ""
         << setw(25) << left << "Vehicle Name"
         << setw(18) << "Passenger Capacity"
         << setw(18) << "Cargo Capacity (tons)"
         << setw(22) << "Fuel Efficiency (km/l)"
         << setw(22) << "Max Speed (km/h)"
         << setw(18) << "Price/km" << endl;

    cout << "---------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < vehicles.size(); ++i)
    {
        cout << GREEN << setw(4) << i + 1 << RESET; // Numbering the vehicles
        vehicles[i].displayDetails();
    }

    cout << CYAN << "--------------------------------------------------------------" << RESET << endl;
}

// Function to display a decorated title
void displayTitle(string title)
{
    cout << "\n"
         << YELLOW << "--------------------------------------------------------------" << RESET << endl;
    cout << YELLOW << "*  " << setw(58) << left << title << " *" << RESET << endl;
    cout << YELLOW << "--------------------------------------------------------------" << RESET << endl;
}

// Function to suggest the best vehicle for people (army personnel) based on *efficiency*
void suggestBestVehicleForPeople(const vector<Vehicle> &vehicles, int numberOfPeople)
{
    displayTitle("Suggesting the Best Vehicle for Army Personnel");

    // Assuming average of 3 people per ton capacity
    int requiredCapacity = numberOfPeople / 3; // 3 people per ton capacity

    Vehicle *bestVehicle = nullptr;
    int minVehiclesNeeded = INT_MAX;

    // Find the best vehicle with the least number of required vehicles
    for (const auto &vehicle : vehicles)
    {
        int vehiclesNeeded = ceil((double)numberOfPeople / vehicle.passengerCapacity);
        if (vehiclesNeeded < minVehiclesNeeded)
        {
            minVehiclesNeeded = vehiclesNeeded;
            bestVehicle = const_cast<Vehicle *>(&vehicle);
        }
    }

    if (bestVehicle)
    {
        cout << GREEN << "For transporting " << numberOfPeople << " army personnel, the best vehicle is: " << RESET << endl;
        cout << "Vehicle: " << YELLOW << bestVehicle->name << RESET << endl;
        cout << "Passenger Capacity: " << YELLOW << bestVehicle->passengerCapacity << RESET << endl;
        cout << "Number of vehicles needed: " << YELLOW << minVehiclesNeeded << RESET << endl;
    }
}

// Function to suggest the best vehicle for goods (weapons, food, medicines) based on both *capacity* and *fuel efficiency*
void suggestBestVehicleForGoods(const vector<Vehicle> &vehicles, double weightOfGoods, bool isForWeapons = false)
{
    displayTitle(isForWeapons ? "Suggesting the Best Vehicle for Weapons" : "Suggesting the Best Vehicle for Goods");

    Vehicle *bestVehicle = nullptr;
    int minVehiclesNeeded = INT_MAX;
    double bestEfficiency = -1;

    // Find the best vehicle with the least number of required vehicles and highest fuel efficiency
    for (const auto &vehicle : vehicles)
    {
        int vehiclesNeeded = ceil(weightOfGoods / vehicle.capacity);

        // Get adjusted fuel efficiency based on cargo load
        double adjustedEfficiency = vehicle.getAdjustedFuelEfficiency(weightOfGoods);

        // Choose the vehicle that minimizes vehicles needed and maximizes fuel efficiency
        if (vehiclesNeeded < minVehiclesNeeded || (vehiclesNeeded == minVehiclesNeeded && adjustedEfficiency > bestEfficiency))
        {
            minVehiclesNeeded = vehiclesNeeded;
            bestVehicle = const_cast<Vehicle *>(&vehicle);
            bestEfficiency = adjustedEfficiency;
        }
    }

    if (bestVehicle)
    {
        cout << GREEN << "For transporting " << weightOfGoods << " tons of goods, the best vehicle is: " << RESET << endl;
        cout << "Vehicle: " << YELLOW << bestVehicle->name << RESET << endl;
        cout << "Capacity: " << YELLOW << bestVehicle->capacity << " tons" << RESET << endl;
        cout << "Adjusted Fuel Efficiency: " << YELLOW << bestVehicle->getAdjustedFuelEfficiency(weightOfGoods) << " km/l" << RESET << endl;
        cout << "Number of vehicles needed: " << YELLOW << minVehiclesNeeded << RESET << endl;
    }
}

// Function to clear input buffer before taking new input
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to calculate the total cost of a route
double calculateRouteCost(const vector<int> &route, const vector<vector<int>> &distances, const vector<Vehicle> &vehicles,
                          const vector<int> &tolls, double fuelCostPerLiter, bool isHeavyTraffic)
{

    double totalCost = 0.0;
    double distance = 0.0;

    // Calculate the total distance of the route
    for (size_t i = 0; i < route.size() - 1; ++i)
    {
        distance += distances[route[i]][route[i + 1]];
    }

    // Apply road conditions (isHeavyTraffic affects fuel efficiency)
    if (isHeavyTraffic)
    {
        distance *= 1.2; // Increase distance by 20% during heavy traffic
    }

    // Calculate the toll cost for the route (if applicable)
    double totalTollCost = 0.0;
    for (int toll : tolls)
    {
        totalTollCost += toll;
    }

    // Evaluate cost for each vehicle and choose the most cost-effective
    double minCost = numeric_limits<double>::max();
    for (const auto &vehicle : vehicles)
    {
        double fuelCost = vehicle.calculateFuelCost(distance, fuelCostPerLiter);
        double totalVehicleCost = fuelCost + totalTollCost + (distance * vehicle.costPerKm);
        minCost = min(minCost, totalVehicleCost); // Find the minimum cost route

        // Display vehicle cost details in a formatted way
        cout << "\n"
             << vehicle.name << " Cost Breakdown:\n";
        cout << "-----------------------------------------------------\n";
        cout << "Fuel Cost:         " << fixed << setprecision(2) << fuelCost << " units\n";
        cout << "Toll Cost:         " << totalTollCost << " units\n";
        cout << "Operational Cost:  " << (distance * vehicle.costPerKm) << " units\n";
        cout << "Total Cost:        " << totalVehicleCost << " units\n";
    }

    return minCost; // Return the minimum cost
}

void vehicleType(const vector<Vehicle>& vehicles){

            // Choose vehicle type
            displayVehicles(vehicles);
            cout << CYAN << "1. Army Personnel" << RESET << endl;
            cout << CYAN << "2. Weapons" << RESET << endl;
            cout << CYAN << "3. Medical Supplies" << RESET << endl;
            cout << CYAN << "4. Food Supplies" << RESET << endl;
            cout << CYAN << "5. Exit" << RESET << endl;
            cout << CYAN << "Enter your choice: " << RESET;


            int choice;
Choice:
            // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-7)." << endl;
            goto Choice;
        }
            switch (choice) {
    case 1: {
        // Unit Shipping for Army Personnel
        int numberOfPeople;
        cout << "Enter number of army personnel: ";
        cin >> numberOfPeople;
        suggestBestVehicleForPeople(vehicles, numberOfPeople);
        break;
    }
    case 2: {
        // Unit Shipping for Weapons


        int ton;
        cout << "Enter the weight of weapons: ";

        cin >> ton;

        suggestBestVehicleForGoods(vehicles, ton, true);

        break;
    }
    case 3:
    case 4: {
        // Unit Shipping for Medical or Food Supplies


        int ton;
        cout << "Enter the weight (in tons): ";

        cin >> ton;

        suggestBestVehicleForGoods(vehicles, ton, false);

         // False for non-weapons
        break;
    }
    case 5:
        cout << "Exiting the program..." << endl;
        break;
    default:
        cout << "\033[1;31mInvalid choice! Please try again.\033[0m" << endl;
        break;
}
}


//To use cout and cin
using namespace std;

// Struct to represent a bus route


struct BusRoute
{

    // Starting point


    string source;

    // Ending point


    string destination;

    // Distance between source and destination


    int distance;

    //Bus provided by the respective company


    string busCompany;

    // Cost of travelling
    int price;

};
//Similar to the structure where we can include all our functions


class BusBookingSystem
{
//Non local variables


private:

     // Store bus routes


    vector<BusRoute> routes;

    // Graph to store the routes as adjacency list


    map<string, vector<pair<string, int>>> graph;

//The functions and variables which are local to all


public:

    // Read bus routes from a file and build the graph


    void readBusRoutesFromFile(const string &filename)
    {

        // Open the file containing the bus routes


        ifstream file(filename);

        // temporary variable to store each individual line of text read from the file


        string line;

        // If the file cannot be opened


        if (!file.is_open())
        {

            cout << "Error opening file!" << endl;
            return;

        }

        // Read each line of the file and process it


        while (getline(file, line))
        {

            stringstream ss(line);

            //Variables for reading
            string source, destination, busCompany;

            int distance, price;

             // Read data from the file line by line, splitting by commas
             // Extract source
            getline(ss, source, ',');

            // Extract destination
            getline(ss, destination, ',');

            // Extract distance
            ss >> distance;

            ss.ignore();

            // Extract distance
            getline(ss, busCompany, ',');

            // Extract price
            ss >> price;

            // Add both directions to the graph
            routes.push_back({source, destination, distance, busCompany, price});

            graph[source].push_back({destination, distance});

            // Since routes are bidirectional
            graph[destination].push_back({source, distance});

        }

        //Close the file after reading
        file.close();

    }

    // Dijkstra's Algorithm to calculate the shortest distance between source and destination
    int calculateShortestDistance(const string &source, const string &destination)
    {
        // Min-heap priority queue to store the city and its distance from the source
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        // Store the shortest distance to each city
        map<string, int> dist;

        // Store the previous city for the shortest path reconstruction
        map<string, string> prev;

        // Initialize distances
        for (const auto &route : routes)
        {
            //Max distance of source
            dist[route.source] = INT_MAX;

            //Max distance of destination
            dist[route.destination] = INT_MAX;
        }

        // Initially the distance of source is 0
        dist[source] = 0;

        //initializing the priority queue and ensuring the algorithm starts from the source node (city)
        pq.push({0, source});

         // Dijkstra's algorithm to find the shortest path
        while (!pq.empty())
        {
             // Get the city with the shortest distance
            string u = pq.top().second;

            pq.pop();

            // If we reached the destination, no need to continue


            if (u == destination) break;

            // Explore all neighboring cities


            for (const auto &neighbor : graph[u])
            {

                // The neighboring city


                string v = neighbor.first;



                // Distance from city u to city v


                int weight = neighbor.second;

                // If a shorter path to the neighbor is found, update it


                if (dist[u] + weight < dist[v])
                {
                     // Update the shortest distance to v



                    dist[v] = dist[u] + weight;

                    // Mark city u as the previous city for v


                    prev[v] = u;

                    // Push the updated distance and city v to the priority queue


                    pq.push({dist[v], v});
                }

            }

        }

        // If the destination is unreachable, return a large value (INT_MAX)
        if (dist[destination] == INT_MAX)
        {
            cout << "No path found from " << source << " to " << destination << ".\n";

            // No valid path
            return -1;
        }

        // Return the shortest distance to the destination
        return dist[destination];

    }

    // Display the booking history in a tabular format


    void displayBookingHistory()
    {

        //Reading from booking_history.txt file

        ifstream file("booking_history.txt");


        //Checking the condition


        if (file.is_open())
        {

            string line;

            //From bus_route file

            vector<BusRoute> bookings;

            //Variables


            string source, destination, busCompany;

            int distance, price;

            // Parse the booking history file and store the details in a vector


            while (getline(file, line))
            {

                if (line.find("Source: ") != string::npos)
                {

                    // Extract source


                    source = line.substr(8);

                    // Skip "Destination" line


                    getline(file, line);

                    // Extract destination


                    destination = line.substr(12);

                    // Skip "Bus Company" line


                    getline(file, line);

                    // Extract bus company


                    busCompany = line.substr(12);

                    // Skip "Distance" line


                    getline(file, line);

                    // Extract distance


                    distance = stoi(line.substr(10));

                    // Skip "Price" line


                    getline(file, line);

                    // Extract price


                    price = stoi(line.substr(7));

                    bookings.push_back({source, destination, distance, busCompany, price});

                    // Skip separator line


                    getline(file, line);

                }
            }

            // Display booking details in a table format
            cout << "\n-------------------Booking History-------------------\n";

            cout << setw(15) << left << "Source" << " | "
                 << setw(15) << "Destination" << " | "
                 << setw(20) << "Bus Company" << " | "
                 << setw(12) << "Distance" << " | "
                 << setw(10) << "Price" << endl;

            cout << "------------------------------------------------------------" << endl;

            for (const auto &booking : bookings)
            {

                cout << setw(15) << left << booking.source << " | "
                     << setw(15) << booking.destination << " | "
                     << setw(20) << booking.busCompany << " | "
                     << setw(12) << booking.distance << " | "
                     << setw(10) << booking.price << endl;

            }

            cout << "------------------------------------------------------------\n";

            file.close();

        }

        else
        {

            cout << "Unable to open the booking history file!" << endl;

        }

    }


// Utility function to convert a string to lowercase


string toLowerCase(const string& str)

{
    string result = str;

    transform(result.begin(), result.end(), result.begin(), ::tolower);

    return result;
}

// Utility function to remove spaces from a string
  string removeSpaces(const string& str)
  {
    string result = str;

    result.erase(remove(result.begin(), result.end(), ' '), result.end());

    return result;
  }

// Method to book a ticket


  void bookTicket(const string &source, const string &destination)
{

    string busCompany;

    // Range of price in which user needs the ticket


    int minPrice, maxPrice;

    cout << "\nEnter the bus company name: ";

    cin.ignore();

    getline(cin, busCompany);

    cout << "Enter the minimum price: ";

    cin >> minPrice;

    cout << "Enter the maximum price: ";

    cin >> maxPrice;

    // Normalize and remove spaces from source and destination for comparison


    string normalizedSource = removeSpaces(toLowerCase(source));

    string normalizedDestination = removeSpaces(toLowerCase(destination));

    // Displaying the output
    for (const auto &route : routes)
    {
        // Normalize and remove spaces from route source, destination, and bus company


        string routeSource = removeSpaces(toLowerCase(route.source));


        string routeDestination = removeSpaces(toLowerCase(route.destination));


        string routeBusCompany = removeSpaces(toLowerCase(route.busCompany));


        // Checking the conditions for booking


        if (routeSource == normalizedSource && routeDestination == normalizedDestination &&

            routeBusCompany == toLowerCase(busCompany) && route.price >= minPrice && route.price <= maxPrice)
        {
            // Ticket successfully booked
            cout << "\n------------------------------------------------------------\n";

            cout << " Ticket Successfully Booked!\n";

            cout << "------------------------------------------------------------\n";

            cout << setw(15) << left << "Source" << " | "


                 << setw(15) << "Destination" << " | "


                 << setw(20) << "Bus Company" << " | "


                 << setw(10) << "Price" << endl;

            cout << "------------------------------------------------------------" << endl;

            cout << setw(15) << left << route.source << " | "

                 << setw(15) << route.destination << " | "




                 << setw(20) << route.busCompany << " | "


                 << setw(10) << route.price << endl;

            cout << "------------------------------------------------------------\n";

            // Calculate and display the shortest distance

            int shortestDistance = calculateShortestDistance(source, destination);

            cout << "Shortest distance: " << shortestDistance << " km" << endl;

            // Log the booked ticket to the booking history file
            logBookingToFile(route);

            return;
        }
    }

    // If no matching route is found


    cout << "No Specific ticket found from " << source << " to " << destination << ".\n";
}

    // Log the booking details to the history file

    void logBookingToFile(const BusRoute &route)
     {

        //Writing into the file
        ofstream file("booking_history.txt", ios::app);

        //Inserting into file
        if (file.is_open())
        {
            file << "\nBooking: " << endl;

            file << "Source: " << route.source << endl;

            file << "Destination: " << route.destination << endl;

            file << "Bus Company: " << route.busCompany << endl;

            file << "Distance: " << route.distance << " km" << endl;

            file << "Price: " << route.price << endl;

            file << "----------------------------------------" << endl;

            //Closing the file
            file.close();
        }

        //If the file didn't opened
        else
        {

            cout << "Unable to open the booking history file!" << endl;

        }

    }

    // Method to delete a booked ticket based on destination and bus company


   void deleteBookedTicket()
  {

    //Destination and bus company name used for deleting


    string destination, busCompany;

    cout << "Enter the destination city: ";

    cin >> destination;

    cout << "Enter the bus company: ";

    cin.ignore();

    getline(cin, busCompany);

    //Reading from file


    ifstream file("booking_history.txt");

    //Temporary writing in file


    ofstream tempFile("temp.txt");

    //If both the files are opened


    if (file.is_open() && tempFile.is_open())
    {
        string line;

        stringstream booking;

        bool found = false;

        // Read each line and accumulate the booking details


        while (getline(file, line))
        {

            booking << line << endl;


            // If we reach the end of a booking block (separator line)


            if (line == "----------------------------------------")
            {

                // Check if the accumulated booking contains a matching destination and bus company


                if (booking.str().find("Destination: " + destination) != string::npos &&booking.str().find("Bus Company: " + busCompany) != string::npos)
                {

                    // If a match is found, skip this booking (do not copy it to tempFile)

                    found = true;

                }

                // If we are not deleting this booking, copy the entire accumulated booking to the temp file

                if (!found)
                {

                    tempFile << booking.str();

                }

                // Reset for the next booking


                // Clear the stringstream


                booking.str("");

                // Reset the flags


                booking.clear();

            }

        }

        //Closing the booking_history.txt file


        file.close();

        //Closing the temp file
        tempFile.close();

        // If we found the matching booking, notify the user
        if (found)
        {

            cout << "Booking for destination " << destination << " with bus company " << busCompany << " deleted successfully.\n";

        }

         else
        {

            cout << "No matching booking found.\n";

        }

        // Replace the original file with the updated one (without the deleted booking)


        remove("booking_history.txt");



        //Rename the temp file to booking_history.txt file


        rename("temp.txt", "booking_history.txt");

    }

    else
    {

        cout << "Unable to open the booking history file!" << endl;

    }

}


    // Sorting function for booked tickets by price


    void sortBookingsByPrice()
    {
        //Reading from booking_hidtory.txt file


        ifstream file("booking_history.txt");


        vector<BusRoute> bookings;

        string line;

        // Variables for bus ticket records


        string source, destination, busCompany;

        int distance, price;

        //If booking_history.txt file is open


        if (file.is_open())
        {

            // Parse the booking history file


            while (getline(file, line))
            {

                //Checking the conditions for sorting until it comes to null

                if (line.find("Source: ") != string::npos)
                {
                    // Getting all the records
                    source = line.substr(8);

                    getline(file, line);

                    destination = line.substr(12);

                    getline(file, line);

                    busCompany = line.substr(12);

                    getline(file, line);

                    distance = stoi(line.substr(10));

                    getline(file, line);

                    price = stoi(line.substr(7));

                    bookings.push_back({source, destination, distance, busCompany, price});

                    getline(file, line);
                }

            }

            //Closing of file

            file.close();

            // Sorting the bookings by price in ascending order


            sort(bookings.begin(), bookings.end(), [](const BusRoute &a, const BusRoute &b)
            {

                return a.price < b.price;

            });

            // Display sorted bookings
            cout << "\n-------------------Sorted Booking History-------------------\n";

            cout << setw(15) << left << "Source" << " | "
                 << setw(15) << "Destination" << " | "
                 << setw(20) << "Bus Company" << " | "
                 << setw(12) << "Distance" << " | "
                 << setw(10) << "Price" << endl;

            cout << "------------------------------------------------------------" << endl;

            //Displaying the sorted tickets
            for (const auto &booking : bookings)
            {

                cout << setw(15) << left << booking.source << " | "
                     << setw(15) << booking.destination << " | "
                     << setw(20) << booking.busCompany << " | "
                     << setw(12) << booking.distance << " | "
                     << setw(10) << booking.price << endl;

            }

            cout << "------------------------------------------------------------\n";
        }

        //If file didn't opened
        else
        {

            cout << "Unable to open the booking history file!" << endl;

        }

    }

  // Method to display matched routes from a source city (based on prefix)


    void displayMatchedRoutes(const string &source, const string &prefix)


    {

        //To check if the route is found
        bool found = false;

        cout << "\nMatching routes from " << source << " where the destination starts with '" << prefix << "':\n";

        cout << setw(15) << left << "Destination"
             << setw(12) << "Distance (km)"
             << setw(20) << "Bus Company"
             << setw(10) << "Price" << endl;
        cout << "------------------------------------------------------------" << endl;

        //For displaying
        for (const auto &route : routes)
        {

            // Check if the route is from the specified source and the destination starts with the prefix
            if (route.source == source)
            {

                // Convert route.destination to lowercase for case-insensitive matching


                string lowerDestination = route.destination;


                // transform function is used to perform case-insensitive matching of strings.


                transform(lowerDestination.begin(), lowerDestination.end(), lowerDestination.begin(), ::tolower);


                // Convert prefix to lowercase for case-insensitive matching


                string lowerPrefix = prefix;



                transform(lowerPrefix.begin(), lowerPrefix.end(), lowerPrefix.begin(), ::tolower);



                // If the destination starts with the prefix


                if (lowerDestination.find(lowerPrefix) == 0)
                {

                    // Displaying the matched route in a formatted table

                    cout << setw(15) << left << route.destination

                         << setw(12) << route.distance

                         << setw(20) << route.busCompany

                         << setw(10) << route.price << endl;

                    found = true;

                }
            }

        }

        //If matches are not found
        if (!found)
        {

            cout << "No matching routes found.\n";

        }
    }


    // Start the bus booking system and present options to the user
    void startBooking()
    {

        string destination;

        string prefix;

        int option;

        cout << "\n-------------------------\n";

        cout << " Bus Booking System\n";

        cout << "-------------------------\n\n";

        do
        {
            cout << "\n";

            cout << "1. Search Bus Routes\n";

            cout << "2. Book a Ticket\n";

            cout << "3. Display Booking History\n";

            cout << "4. Delete Booked Ticket\n";

            cout << "5. Sort Bookings by Price\n";

            cout << "6. Exit\n";

            cout << "Enter your choice: ";

            cin >> option;

            switch (option)
            {

                //Searching the bus routes


                case 1:
                    cout << "\nEnter the destination city : ";

                    cin >> prefix;

                    displayMatchedRoutes("Delhi", prefix);

                    break;


                //Booking a ticket


                case 2:
                    cout << "\nEnter the destination city: ";

                    cin >> destination;

                    bookTicket("Delhi", destination);

                    break;

                //Display booking history


                case 3:
                    displayBookingHistory();

                    break;

                 //Deleting the booked ticket


                case 4:

                    deleteBookedTicket();

                    break;

                //Sorting the booked tickets by price


                case 5:
                    sortBookingsByPrice();

                    break;

                 //Exit after the desired operations

                case 6:
                    cout << "Exiting the system. Thank you for using the Bus Booking System!\n";

                    break;

                //Invalid choice


                default:
                    cout << "Invalid choice. Please try again.\n";

                    break;
            }

            //As only six operations are valid


        } while (option != 6);

    }

};











using namespace std;

// Struct to represent an army unit

struct ArmyUnit
{
    string unitName;


    int personnel;

    int vehicles;

    int weapons;

    int equipment;

    double totalWeight;

    // in kg
    double totalCost;

    // in dollars, track cost for each shift
    vector<string> weaponTypes;

    vector<int> weaponCounts;

    // Constructor to initialize army unit details


    ArmyUnit(string name, int p, int v, int w, int e, double weight)

        : unitName(name), personnel(p), vehicles(v), weapons(w), equipment(e), totalWeight(weight) {}

    // Function to display unit details
    void displayUnitDetails() const {
        cout << "\n\033[1;34m************************** Unit Details **************************\033[0m\n";
        cout << "\033[1;32mUnit Name: \033[0m" << unitName << "\n"
             << "\033[1;32m   Personnel: \033[0m" << personnel << "\n"
             << "\033[1;32m   Vehicles: \033[0m" << vehicles << "\n"
             << "\033[1;32m   Weapons: \033[0m" << weapons << "\n"
             << "\033[1;32m   Equipment: \033[0m" << equipment << "\n"
             << "\033[1;32m   Total Weight: \033[0m" << totalWeight << " kg\n";
        cout << "\033[1;34m********************************************************************\033[0m\n";
    }
};



// Distance matrix for locations

const string locations[] =
{"Delhi", "Mumbai", "Chennai", "Kolkata", "Bangalore",
                            "Hyderabad", "Ahmedabad", "Pune", "Jaipur", "Lucknow"};

const int numLocations = sizeof(locations) / sizeof(locations[0]);

const int distances[numLocations][numLocations] = {
    {0, 1400, 2200, 1500, 2100, 1500, 900, 1400, 270, 500},

    {1400, 0, 1330, 2000, 980, 710, 520, 150, 1140, 580},

    {2200, 1330, 0, 1670, 360, 630, 1780, 1190, 2040, 2100},

    {1500, 2000, 1670, 0, 1860, 1500, 1700, 1850, 1520, 1000},

    {2100, 980, 360, 1860, 0, 570, 1230, 840, 1800, 1900},

    {1500, 710, 630, 1500, 570, 0, 1200, 560, 1500, 800},

    {900, 520, 1780, 1700, 1230, 1200, 0, 720, 500, 900},

    {1400, 150, 1190, 1850, 840, 560, 720, 0, 1180, 720},

    {270, 1140, 2040, 1520, 1800, 1500, 500, 1180, 0, 780},

    {500, 580, 2100, 1000, 1900, 800, 900, 720, 780, 0}
};

// Forward declarations for functions

void selectVehicleForUnit(const ArmyUnit &unit);

void trackUnitMovement(const ArmyUnit &unit);

void displayDistanceMatrix();

// Function to create and write army unit details to a file

void createArmyUnitFile(const string &filename, const vector<ArmyUnit> &units)

 {
    ofstream file(filename);

    if (!file)

        {
        cerr << "Error: Could not create file '" << filename << "'\n";

        return;
    }

    file << "Army Unit Details:\n\n";

    for (size_t i = 0; i < units.size(); ++i)
        {

        file << i + 1 << ". Unit Name: " << units[i].unitName << "\n"

             << "   Personnel: " << units[i].personnel << "\n"

             << "   Vehicles: " << units[i].vehicles << "\n"

             << "   Weapons: " << units[i].weapons << "\n"

             << "   Equipment: " << units[i].equipment << "\n"

             << "   Total Weight: " << units[i].totalWeight << " kg\n\n";
    }

    file.close();

    cout << "File '" << filename << "' created successfully!\n";
}

// Function to display all units on the console

void displayAllUnits(const vector<ArmyUnit> &units)

 {
    cout << "\n\033[1;34m************************ Army Unit Details ************************\033[0m\n";

    for (size_t i = 0; i < units.size(); ++i)

        {

        cout << i + 1 << ". " << units[i].unitName << endl;

    }
    cout << "\033[1;34m***************************************************************\033[0m\n";
}

// Function to handle unit shift selection

void handleUnitShift(const vector<ArmyUnit> &units)
{
    int choice;

    // Ask the user to select a unit


    cout << "\nEnter the number of the unit that is going to shift: ";

    cin >> choice;

    // Validate input
    if (choice < 1 || choice > units.size())

        {
        cout << "\033[1;31mInvalid choice! Please enter a number between 1 and " << units.size() << ".\033[0m\n";


    }

    else

        {
        // Display details of the selected unit

        cout << "\n\033[1;36mDetails of selected unit:\033[0m\n";

        units[choice - 1].displayUnitDetails();

        // Call the Vehicle Selection function


        selectVehicleForUnit(units[choice - 1]);

        // Call the logistics movement function


        trackUnitMovement(units[choice - 1]);
    }
}

// Function to select vehicle type based on unit's weight and needs


void selectVehicleForUnit(const ArmyUnit &unit)

{
    cout << "\n\033[1;33m************************ Vehicle Selection ************************\033[0m\n";

    // Define vehicle capacities
    const int lightVehicleCapacity = 1000;  // Light vehicle capacity (in kg)

    const int mediumTruckCapacity = 5000;   // Medium truck capacity (in kg)

    const int heavyTruckCapacity = 10000;   // Heavy truck capacity (in kg)

    // Determine the total weight of the unit's personnel, vehicles, and equipment

    int totalWeight = unit.totalWeight;

    cout << "\033[1;32mTotal weight for transportation: \033[0m" << totalWeight << " kg\n";

    // Vehicle selection based on weight

    if (totalWeight <= lightVehicleCapacity)
        {

        cout << "\033[1;32mRecommended vehicle: Light Vehicle (capacity: \033[0m" << lightVehicleCapacity << " kg)\n";

        cout << "\033[1;32mNumber of Light Vehicles needed: 1\033[0m\n";

    } else if (totalWeight <= mediumTruckCapacity)
     {
        cout << "\033[1;32mRecommended vehicle: Medium Truck (capacity: \033[0m" << mediumTruckCapacity << " kg)\n";

        cout << "\033[1;32mNumber of Medium Trucks needed: 1\033[0m\n";

    } else if (totalWeight <= heavyTruckCapacity)
    {
        cout << "\033[1;32mRecommended vehicle: Heavy Truck (capacity: \033[0m" << heavyTruckCapacity << " kg)\n";

        cout << "\033[1;32mNumber of Heavy Trucks needed: 1\033[0m\n";

    }
    else
        {
        // If the total weight exceeds heavy truck capacity, calculate the number of trucks required

        int heavyTrucksNeeded = totalWeight / heavyTruckCapacity;

        if (totalWeight % heavyTruckCapacity != 0)
            {

            heavyTrucksNeeded++;
        // Add one more truck if there's a remainder
        }

        cout << "\033[1;32mRecommended vehicle: Heavy Truck (capacity: \033[0m" << heavyTruckCapacity << " kg)\n";

        cout << "\033[1;32mNumber of Heavy Trucks needed: \033[0m" << heavyTrucksNeeded << "\n";
    }
    cout << "\033[1;33m*****************************************************************\033[0m\n";
}

// Function to track the unit's movement (logistics)


void trackUnitMovement(const ArmyUnit &unit)

{
    string fromLocation, toLocation;

    int distance;

    // Ask for the movement details


    cout << "\n\033[1;35mEnter the current location of the unit: \033[0m";

    cin.ignore();

    // Ignore the previous newline character

    getline(cin, fromLocation);

    cout << "\033[1;35mEnter the destination location: \033[0m";

    getline(cin, toLocation);

    // Get distance from the matrix

    int fromIndex = -1, toIndex = -1;

    for (int i = 0; i < numLocations; ++i)

        {
        if (fromLocation == locations[i]) fromIndex = i;

        if (toLocation == locations[i]) toIndex = i;
    }

    if (fromIndex == -1 || toIndex == -1)

        {

        cout << "\033[1;31mInvalid locations entered. Please check the location names.\033[0m\n";

        return;
    }

    distance = distances[fromIndex][toIndex];

    // Estimate the transport time based on average speed (let's assume 60 km/h)

    int transportTime = distance / 60;

    // Display the logistics movement details


    cout << "\n\033[1;36m************************ Logistics Movement ************************\033[0m\n";


    cout << "Unit: " << unit.unitName << "\n"

         << "From: " << fromLocation << "  To: " << toLocation << "\n"

         << "Distance: " << distance << " km\n"

         << "Estimated Transport Time: " << transportTime << " hours\n";

    // Break down the cargo


    cout << "\n\033[1;32mCargo Breakdown:\033[0m\n";

    cout << "Personnel: " << unit.personnel << "\n"

         << "Vehicles: " << unit.vehicles << "\n"

         << "Weapons: " << unit.weapons << "\n"

         << "Equipment: " << unit.equipment << "\n"

         << "Total Weight: " << unit.totalWeight << " kg\n";


    cout << "\033[1;36m*****************************************************************\033[0m\n";
}







void displayDistanceMatrix()

 {
    cout << "\n\033[1;34m************************ Location Distance Matrix **********************\033[0m\n";

    cout << "    ";

    for (int i = 0; i < numLocations; ++i)

        {
        cout << setw(10) << locations[i];

    }
    cout << endl;

    for (int i = 0; i < numLocations; ++i)

        {
        cout << setw(10) << locations[i];

        for (int j = 0; j < numLocations; ++j)

            {
            cout << setw(10) << distances[i][j];

        }
        cout << endl;
    }
    cout << "\033[1;34m***********************************************************************\033[0m\n";
}

using namespace std;

// Colors for enhanced output display (minimal)

#define RESET   "\033[0m"

#define CYAN    "\033[36m"

#define YELLOW  "\033[33m"



// Function to calculate the transport cost in USD

double calculateTransportCost(const ArmyUnit &unit, double distance)

 {
    // Cost parameters in USD (adjusted for better example)

    const double fuelCostPerKmPerKg = 0.01;

    // Fuel cost per km per kg (in USD)

    const double tollCostPerVehicle = 4.0;

    // Toll cost per vehicle per km (in USD)

    const double maintenanceCostPerVehicle = 0.3;

    // Maintenance cost per vehicle per km (in USD)

    // Calculate individual costs

    double fuelCost = unit.totalWeight * distance * fuelCostPerKmPerKg;

    double tollCost = unit.vehicles * distance * tollCostPerVehicle;

    double maintenanceCost = unit.vehicles * distance * maintenanceCostPerVehicle;

    // Total cost in USD

    double totalCostUSD = fuelCost + tollCost + maintenanceCost;

    return totalCostUSD;
}

// Function to print a divider for separating output sections

void printDivider()

{
    cout << "-----------------------------------------------" << endl;
}

// Function to print the header with a title

void printHeader(const string& header)

{
    printDivider();

    cout << CYAN << header << RESET << endl;

    printDivider();
}

// Function to print the list of available Army Units

void displayUnits(const vector<ArmyUnit>& units)

{
    for (size_t i = 0; i < units.size(); ++i)

        {
        cout << i + 1 << ". " << units[i].unitName << endl;
    }
}

// Function to print the list of locations

void displayLocations(const vector<string>& locations)
 {
    for (size_t i = 0; i < locations.size(); ++i)

        {

        cout << i + 1 << ". " << locations[i] << endl;
    }
}

// Function to get the unit from the list based on user input

ArmyUnit getUnitByIndex(const vector<ArmyUnit>& units, int index)

 {
    return units[index - 1];
}

// Function to get the location from the list based on user input

string getLocationByIndex(const vector<string>& locations, int index)

 {
    return locations[index - 1];
}

// Function to calculate and display the transport cost

void displayTransportCost(const ArmyUnit& unit, const vector<vector<int>>& distances, int srcIndex, int destIndex)

 {
    double distance = distances[srcIndex][destIndex];

    // Get the distance between source and destination

    double transportCostUSD = calculateTransportCost(unit, distance);

    // Calculate transport cost in USD

    // Output the final transport cost


    cout << "\nTotal Transport Cost (in USD): $" << fixed << setprecision(2) << transportCostUSD << endl;
}




// Function to write unit details to file

void writeUnitDetailsToFile(const vector<ArmyUnit> &units)

{
    ofstream file("military_units_details.txt");

    // Open the file to write data

    if (!file.is_open())

        {
        cout << "Error: Could not open file for writing!" << endl;

        return;
    }

    file << "---- Military Unit Details ----" << endl;

    file << "Serial No. | Unit Name                | Personnel | Vehicles | Weapons | Equipment | Total Weight (kg) | Total Cost (USD) | Weapon Types and Counts" << endl;
    file << "--------------------------------------------------------------------------------------------" << endl;

    // Write details for each unit
    for (int i = 0; i < units.size(); ++i)

        {
        file << i + 1 << "         | " << units[i].unitName << " | "
             << units[i].personnel << "       | " << units[i].vehicles << "      | "
             << units[i].weapons << "      | " << units[i].equipment << "       | "
             << units[i].totalWeight << "           | $" << fixed << setprecision(2) << units[i].totalCost << "        | ";

        // Write weapon types and counts

        for (size_t j = 0; j < units[i].weaponTypes.size(); ++j)

            {
            file << units[i].weaponTypes[j] << ": " << units[i].weaponCounts[j];

            if (j < units[i].weaponTypes.size() - 1)

                {
                file << ", ";
            }
        }
        file << endl;
    }

    file << "--------------------------------------------------------------------------------------------" << endl;

    cout << "Details written to 'military_units_details.txt' successfully!" << endl;

    file.close();  // Close the file
}











// Function to generate monthly report
void generateMonthlyReport(const vector<ArmyUnit>& units)

 {
    double totalCost = 0;

    for (const auto& unit : units)
        {
        totalCost += unit.totalCost;
    }

    printHeader("Monthly Report");

    cout << "\033[1;32mTotal Monthly Cost: \033[0m$" << fixed << setprecision(2) << totalCost << endl;
}

// Function to generate weekly report

void generateWeeklyReport(const vector<ArmyUnit>& units)
 {
    double totalCost = 0;

    for (const auto& unit : units)
        {

        totalCost += unit.totalCost;
    }

    printHeader("Weekly Report");

    cout << "\033[1;32mTotal Weekly Cost: \033[0m$" << fixed << setprecision(2) << totalCost << endl;
}

// Function to generate vehicle cost report

void generateVehicleCostReport(const vector<ArmyUnit>& units)
{
    double totalVehicleCost = 0;

    for (const auto& unit : units)
        {
        totalVehicleCost += unit.vehicles * (unit.totalCost / unit.vehicles);

    // Simple assumption for cost per vehicle

    }

    printHeader("Vehicle Cost Report");

    cout << "\033[1;32mTotal Vehicle Cost: \033[0m$" << fixed << setprecision(2) << totalVehicleCost << endl;
}

// Function to generate weapon cost report

void generateWeaponCostReport(const vector<ArmyUnit>& units)

 {
    double totalWeaponCost = 0;

    for (const auto& unit : units)

        {
        for (size_t i = 0; i < unit.weaponCounts.size(); ++i)
        {
            totalWeaponCost += unit.weaponCounts[i] * (unit.totalCost / unit.weapons);

    // Simple assumption for cost per weapon

        }
    }

    printHeader("Weapon Cost Report");

    cout << "\033[1;32mTotal Weapon Cost: \033[0m$" << fixed << setprecision(2) << totalWeaponCost << endl;
}










struct SupplyItem

{
    std::string name;

    int quantity;

    std::string category;
    double price;               // New member to store item price

    SupplyItem(std::string itemName, int itemQuantity, std::string itemCategory)
        : name(itemName), quantity(itemQuantity), category(itemCategory) {}

};

// Structure to represent a movement record

struct MovementRecord

 {
    std::string itemName;

    int quantity;

    std::string fromLocation;
    std::string toLocation;
    std::string supplier;
    std::string deliveryRecipient;

    MovementRecord(std::string name, int qty, std::string from, std::string to, std::string supp, std::string recipient)
        : itemName(name), quantity(qty), fromLocation(from), toLocation(to), supplier(supp), deliveryRecipient(recipient) {}


};

// Structure to represent a military contract
struct MilitaryContract

{
    std::string supplier;
    std::string itemName;
    int quantity;
    std::string contractID;

    MilitaryContract(std::string supp, std::string item, int qty, std::string id)
        : supplier(supp), itemName(item), quantity(qty), contractID(id) {}
};

// Structure to represent an emergency order
struct EmergencyOrder {
    std::string orderID;
    std::string itemName;
    int quantity;
    std::string supplier;
    std::string recipient;

    EmergencyOrder(std::string id, std::string name, int qty, std::string supp, std::string rec)
        : orderID(id), itemName(name), quantity(qty), supplier(supp), recipient(rec) {}
};

// Class for managing logistics


class LogisticsManager

 {

private:
    std::vector<SupplyItem> inventory;
    std::vector<MovementRecord> movementLog;
    std::unordered_map<std::string, std::string> trackingInfo; // Tracks current location of goods
    std::unordered_map<std::string, std::string> placeNames; // Maps place IDs to names
    std::unordered_map<std::string, std::vector<std::string>> locationChangeLog; // Log of location changes
    std::unordered_map<std::string, std::string> users; // User management (username -> password)
    std::vector<MilitaryContract> contracts; // Military contracts
    std::vector<EmergencyOrder> emergencyOrders; // Store emergency orders
public:

//----------------------------------------
     void addUser(const std::string& username, const std::string& password)

     {

        users[username] = password;

    }

    // Validate user login
    bool validateUser(const std::string& username, const std::string& password)

     {
        return users.find(username) != users.end() && users[username] == password;
    }

    // Admin login
    void adminLogin()

     {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        if (validateUser(username, password))

        {

            std::cout << "Login successful.\n";

        }

        else

        {
            std::cout << "Invalid username or password.\n";
        }

    }
//---------------------------------------
    void addPlace(const std::string& placeID, const std::string& placeName)

    {
        placeNames[placeID] = placeName;

        std::cout << "Added place: " << placeName << " (ID: " << placeID << ")\n";
        savePlaceToHistory(placeID, placeName);
    }

    void savePlaceToHistory(const std::string& placeID, const std::string& placeName) const

     {
        std::ofstream outFile("logistics_history.txt", std::ios::app);
        if (outFile.is_open())

        {
            outFile << "Place Added: " << placeName << " (ID: " << placeID << ")\n";
            outFile.close();
        }


    }

    std::string getPlaceName(const std::string& placeID) const

    {
        auto it = placeNames.find(placeID);

        return it != placeNames.end() ? it->second : "Unknown Location";


    }

    void addItem(const std::string& name, int quantity, const std::string& category, const std::string& initialPlaceID = "Unknown")
    {
        if (quantity <= 0)
            {
            std::cout << "Quantity must be a positive number.\n";
            return;
        }

        auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const SupplyItem& item)
        {
            return item.name == name;
        });

        if (it != inventory.end())

            {
            it->quantity += quantity;
            std::cout << "Updated quantity of " << name << " to " << it->quantity << " units.\n";
        }
        else

        {

            inventory.emplace_back(name, quantity, category);
            std::string initialLocation = getPlaceName(initialPlaceID);
            trackingInfo[name] = initialLocation;


            locationChangeLog[name].push_back("Initial Location: " + initialLocation);
            std::cout << "Added new item: " << name << " (" << quantity << " units) at " << initialLocation << ".\n";
            saveItemToHistory(name, quantity, category);
        }


    }



    void saveItemToHistory(const std::string& name, int quantity, const std::string& category) const

     {
        std::ofstream outFile("logistics_history.txt", std::ios::app);
        if (outFile.is_open())
            {
            outFile << "Item Added: " << name << " | Quantity: " << quantity << " | Category: " << category << "\n";
            outFile.close();
        }

    }

    void removeItem(const std::string& name, int quantity)
     {
        if (quantity <= 0)

        {

            std::cout << "Quantity must be a positive number.\n";
            return;
        }

        auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const SupplyItem& item)
        {
            return item.name == name;
        });

        if (it != inventory.end())
            {
            if (it->quantity >= quantity)
            {
                it->quantity -= quantity;
                std::cout << "Removed " << quantity << " units of " << name << ".\n";
                saveRemoveToHistory(name, quantity);

                if (it->quantity == 0)
                    {
                    inventory.erase(it);
                    trackingInfo.erase(name);
                    std::cout << name << " is now out of stock and removed from inventory.\n";
                    saveRemoveToHistory(name, quantity, true);
                }

            }
             else
                {

                std::cout << "Insufficient quantity of " << name << " to remove.\n";
            }
        }
        else
            {

            std::cout << name << " not found in inventory.\n";
        }

    }

    void saveRemoveToHistory(const std::string& name, int quantity, bool isOutOfStock = false) const
    {
        std::ofstream outFile("logistics_history.txt", std::ios::app);
        if (outFile.is_open())
            {
            outFile << "Item Removed: " << name << " | Quantity: " << quantity;
            if (isOutOfStock)
             {
                outFile << " | Item is out of stock and removed.\n";
            }
        else
            {
                outFile << "\n";
            }
            outFile.close();
        }
    }
  //---------------------------------------------------
   void setItemPrice(const std::string& name, double price) {
        auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const SupplyItem& item) {
            return item.name == name;
        });

        if (it != inventory.end()) {
            it->price = price;
            std::cout << "Price of " << name << " updated to " << price << ".\n";
            savePriceToHistory(name, price);
        } else {
            std::cout << "Item not found in inventory.\n";
        }
    }

    void savePriceToHistory(const std::string& name, double price) const {
        std::ofstream outFile("logistics_history.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << "Price Updated: " << name << " | New Price: " << price << "\n";
            outFile.close();
        }
    }

    void displayItemPrice(const std::string& name) const {
        auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const SupplyItem& item) {
            return item.name == name;
        });

        if (it != inventory.end()) {
            std::cout << "Price of " << name << ": " << it->price << "\n";
        } else {
            std::cout << "Item not found in inventory.\n";
        }
    }


  //----------------------------------------
    // Calculate the total value of all items in the inventory
    void calculateTotalValue() const

    {
        double totalValue = 0.0;
        for (const auto& item : inventory)

        {
            totalValue += item.quantity * item.price;
        }

        std::cout << "Total inventory value: $" << totalValue << "\n";
    }
//---------------------------------------------------------
    void moveGoods(const std::string& name, int quantity, const std::string& fromID, const std::string& toID, const std::string& supplier, const std::string& recipient)

    {
        if (quantity <= 0)
        {
            std::cout << "Quantity must be a positive number.\n";
            return;
        }

        auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const SupplyItem& item)
        {
            return item.name == name;
        }
        );

        if (it != inventory.end() && it->quantity >= quantity)
            {
            it->quantity -= quantity;
            movementLog.emplace_back(name, quantity, getPlaceName(fromID), getPlaceName(toID), supplier, recipient);

            // Log the location change
            locationChangeLog[name].push_back("Moved from " + getPlaceName(fromID) + " to " + getPlaceName(toID));

            // Update the current location of the item
            trackingInfo[name] = getPlaceName(toID);

            std::cout << "Moved " << quantity << " units of " << name << " from " << getPlaceName(fromID) << " to " << getPlaceName(toID)
                      << " (Supplier: " << supplier << ", Recipient: " << recipient << ").\n";
            saveMovementToHistory(name, quantity, fromID, toID, supplier, recipient);

            if (it->quantity == 0)

                {

                inventory.erase(it);
                trackingInfo.erase(name);
                std::cout << name << " is now out of stock and removed from inventory.\n";
            }

        }
        else

            {
            std::cout << "Insufficient quantity of " << name << " or item not found in inventory for movement.\n";
        }
    }

    void saveMovementToHistory(const std::string& name, int quantity, const std::string& fromID, const std::string& toID, const std::string& supplier, const std::string& recipient) const
    {
        std::ofstream outFile("logistics_history.txt", std::ios::app);
        if (outFile.is_open())
            {
            outFile << "Goods Moved: " << name << " | Quantity: " << quantity
                    << " | From: " << getPlaceName(fromID) << " | To: " << getPlaceName(toID)
                    << " | Supplier: " << supplier << " | Recipient: " << recipient << "\n";
            outFile.close();
        }
    }
//---------------------------------------------------
    void displayRemainingQuantity(const std::string& name) const {
        auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const SupplyItem& item) {
            return item.name == name;
        });

        if (it != inventory.end()) {
            std::cout << "Remaining quantity of " << name << ": " << it->quantity << "\n";
        } else {
            std::cout << "Item " << name << " not found in inventory.\n";
        }
    }
//-----------------------------
//-------------------------------------------------------
  void addEmergencyOrder(const std::string& orderID, const std::string& itemName, int quantity, const std::string& supplier, const std::string& recipient) {
        emergencyOrders.emplace_back(orderID, itemName, quantity, supplier, recipient);
        std::cout << "Emergency order added: " << orderID << " for " << itemName << " (Quantity: " << quantity << ").\n";
    }

    void processEmergencyOrder(const std::string& orderID) {
        auto it = std::find_if(emergencyOrders.begin(), emergencyOrders.end(), [&orderID](const EmergencyOrder& order) {
            return order.orderID == orderID;
        });

        if (it != emergencyOrders.end()) {
            auto itemIt = std::find_if(inventory.begin(), inventory.end(), [&it](const SupplyItem& item) {
                return item.name == it->itemName;
            });

            if (itemIt != inventory.end() && itemIt->quantity >= it ->quantity) {
                itemIt->quantity -= it->quantity;
                std::cout << "Processed emergency order: " << orderID << " for " << it->itemName << ".\n";
                emergencyOrders.erase(it);
            } else {
                std::cout << "Insufficient stock for emergency order: " << orderID << ".\n";
            }
        } else {
            std::cout << "Emergency order ID not found: " << orderID << ".\n";
        }
    }

    void displayEmergencyOrders() const {
        std::cout << "\nEmergency Orders:\n";
        for (const auto& order : emergencyOrders) {
            std::cout << "- Order ID: " << order.orderID << " | Item: " << order.itemName
                      << " | Quantity: " << order.quantity << " | Supplier: " << order.supplier
                      << " | Recipient: " << order.recipient << "\n";
        }
        if (emergencyOrders.empty()) {
            std::cout << "No emergency orders found.\n";
        }
    }
//==============================================================
    void displayInventory() const
     {
        std::cout << "\nCurrent Inventory:\n";
        for (const auto& item : inventory)
            {
            std::cout << "- " << item.name << " | Quantity: " << item.quantity << " | Category: " << item.category
                      << " | Location: " << (trackingInfo.find(item.name) != trackingInfo.end() ? trackingInfo.at(item.name) : "Unknown") << "\n";
        }
        if (inventory.empty())
         {
            std::cout << "Inventory is empty.\n";
        }

    }

    void displayMovementLog() const
     {
        std::cout << "\nMovement Log:\n";
        for (const auto& record : movementLog)
            {
            std::cout << "- " << record.itemName << " | Quantity: " << record.quantity
                      << " | From: " << record.fromLocation << " | To: " << record.toLocation
                      << " | Supplier: " << record.supplier << " | Recipient: " << record.deliveryRecipient << "\n";
        }
        if (movementLog.empty())
        {
            std::cout << "No movements recorded.\n";
        }

    }

    void trackItem(const std::string& name) const

     {
        auto it = trackingInfo.find(name);
        if (it != trackingInfo.end())
            {
            std::cout << "Current location of " << name << ": " << it->second << "\n";
        }
        else
            {
            std::cout << "Item " << name << " not found in tracking records.\n";

        }


    }

    void displayLocationHistory(const std::string& name) const
     {
        auto it = locationChangeLog.find(name);
        if (it != locationChangeLog.end())
            {
            std::cout << "Location history of " << name << ":\n";
            for (const auto& location : it->second)
            {
                std::cout << "- " << location << "\n";
            }
        }
        else
        {
            std::cout << "No location history found for " << name << ".\n";
        }

    }
   //-------------------------------

void addMilitaryContract(const std::string& supplier, const std::string& itemName, int quantity, const std::string& contractID)

    {
        contracts.emplace_back(supplier, itemName, quantity, contractID);
        std::cout << "Added military contract for " << itemName << " with supplier " << supplier << ".\n";
        saveContractToHistory(supplier, itemName, quantity, contractID);
    }

    void saveContractToHistory(const std::string& supplier, const std::string& itemName, int quantity, const std::string& contractID) const

    {
        std::ofstream outFile("logistics_history.txt", std::ios::app);
        if (outFile.is_open())
        {
            outFile << "Military Contract: " << contractID << " | Supplier: " << supplier
                    << " | Item: " << itemName << " | Quantity: " << quantity << "\n";
            outFile.close();
        }
    }

    void displayContracts() const
     {
        std::cout << "\nMilitary Contracts:\n";
        for (const auto& contract : contracts)
        {
            std::cout << "- Contract ID: " << contract.contractID << " | Supplier: " << contract.supplier
                      << " | Item: " << contract.itemName << " | Quantity: " << contract.quantity << "\n";
        }
        if (contracts.empty())

        {
            std::cout << "No military contracts found.\n";
        }

    }
};
  //----------------------------------








  struct Item {
    std::string name;
    int quantity;
    int space_required; // Space required per unit
};

// Structure to represent a military base
struct Base {
    std::string name;
    int total_space;
    int used_space;
    std::vector<Item> items;

    // Function to calculate available space
    int available_space() const {
        return total_space - used_space;
    }

    // Function to add an item to the base
    bool add_item(const Item& item) {
        int required_space = item.quantity * item.space_required;
        if (required_space <= available_space()) {
            items.push_back(item);
            used_space += required_space;
            std::cout << "Item added successfully to " << name << ".\n";
            return true;
        } else {
            std::cout << "Not enough space in " << name << " to add item: " << item.name << "\n";
            return false; // Not enough space
        }
    }
    // Function to save base details to a text file
void save_to_file(const std::vector<Base>& bases, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    file << "Military Base Details:\n";
    for (const auto& base : bases) {
        file << "Base: " << base.name << "\n";
        file << "Total Space: " << base.total_space << "\n";
        file << "Used Space: " << base.used_space << "\n";
        file << "Available Space: " << base.available_space() << "\n";
        file << "Items:\n";
        for (const auto& item : base.items) {
            file << "  - " << item.name << ": " << item.quantity << " units (" << item.space_required << " space/unit)\n";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Base data saved to " << filename << "\n";
}

    // Function to display base details
    void display() const {
        std::cout << "Base: " << name << "\n";
        std::cout << "Total Space: " << total_space << "\n";
        std::cout << "Used Space: " << used_space << "\n";
        std::cout << "Available Space: " << available_space() << "\n";
        std::cout << "Items:\n";
        for (const auto& item : items) {
            std::cout << "  - " << item.name << ": " << item.quantity << " units (" << item.space_required << " space/unit)\n";
        }
        std::cout << "\n";
    }
};

// Structure to represent a supplier
struct Supplier {
    std::string name;
    std::vector<Item> items;
    std::vector<int> distances; // Distance to each base

    // Function to display supplier details
    void display() const {
        std::cout << "Supplier: " << name << "\n";
        std::cout << "Items:\n";
        for (const auto& item : items) {
            std::cout << "  - " << item.name << ": " << item.quantity << " units\n";
        }
        std::cout << "\n";
    }
};

// Function to find the nearest supplier for a requested item
int find_nearest_supplier(const std::vector<Supplier>& suppliers, int base_index, const std::string& item_name) {
    int min_distance = std::numeric_limits<int>::max();
    int nearest_supplier_index = -1;

    for (size_t i = 0; i < suppliers.size(); ++i) {
        for (const auto& item : suppliers[i].items) {
            if (item.name == item_name && item.quantity > 0) {
                if (suppliers[i].distances[base_index] < min_distance) {
                    min_distance = suppliers[i].distances[base_index];
                    nearest_supplier_index = i;
                }
            }
        }
    }

    return nearest_supplier_index;
}

// Function to save supplier details to a text file
void save_suppliers_to_file(const std::vector<Supplier>& suppliers, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    file << "Supplier Details:\n";
    for (const auto& supplier : suppliers) {
        file << "Supplier: " << supplier.name << "\n";
        file << "Items:\n";
        for (const auto& item : supplier.items) {
            file << "  - " << item.name << ": " << item.quantity << " units\n";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Supplier data saved to " << filename << "\n";
}











// Structure to hold the order details



int main()

{
    // Step 1: Call the login function first

     // Wait until login is successful


        // Step 1: Call the login function first


    string username, password, role;

    int attempts = 3;

    bool loggedIn = false;

    // Login attempt loop


    while (attempts > 0)

        {
        cout << "\nEnter Username: ";

        cin >> username;

        cout << "Enter Password: ";

        hidePasswordInput(password);

        cout << "\nEnter Role (Captain/Major): ";

        cin >> role;

        // Validate login credentials

        if (validateLogin(username, password, role))

            {
            cout << "\nLogin successful!\n";

            loggedIn = true;

            break;

             // Break the loop on successful login
        }
         else

            {
            attempts--;

            cout << "\nInvalid credentials! You have " << attempts << " attempt(s) left.\n";

            if (attempts == 0)

                {
                cout << "Too many failed attempts. Exiting...\n";

                return 0; // Halt the program after 3 failed attempts
            }
        }
    }

    // If the user is logged in, allow placing orders



//------------------------------------------------





 LogisticsManager manager;


    int choice;


    do
        {
        std::cout << "\nLogistics Management System\n";
        std::cout << "1. Add Place\n";
        std::cout << "2. Add Item\n";
        std::cout << "3. Remove Item\n";
        std::cout << "4. Move Goods\n";
        std::cout << "5. Display Inventory\n";
        std::cout << "6. Display Movement Log\n";
        std::cout << "7. Set Item Price\n";  // Option for setting price
        std::cout << "8. Display Item Price\n"; // Option for displaying price
        std::cout << "9. Calculate Total Inventory Value\n";
        std::cout << "10. Display Remaining Quantity\n"; // New option
        std::cout << "11. Track Item\n";
        std::cout << "12. Display Location History\n";
        std::cout << "13. Add Military Contract\n";
        std::cout << "14. Display Military Contracts\n";
        std::cout << "15. Add Emergency Order\n";
        std::cout << "16. Process Emergency Order\n";
        std::cout << "17. Display Emergency Orders\n";
        std::cout << "18. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
         {
            case 1:
                {
                std::string placeID, placeName;
                std::cout << "Enter Place ID: ";
                std::cin >> placeID;
                std::cin.ignore();  // To clear the newline from the input buffer
                std::cout << "Enter Place Name: ";
                std::getline(std::cin, placeName);
                manager.addPlace(placeID, placeName);
                break;
            }


            case 2:
                {
                std::string name, category, initialPlaceID;
                int quantity;
                std::cout << "Enter Item Name: ";
                std::cin >> name;
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cin.ignore();  // To clear the newline from the input buffer
                std::cout << "Enter Category: ";
                std::getline(std::cin, category);
                std::cout << "Enter Initial Place ID (or leave empty for 'Unknown'): ";
                std::getline(std::cin, initialPlaceID);
                if (initialPlaceID.empty()) initialPlaceID = "Unknown";
                manager.addItem(name, quantity, category, initialPlaceID);
                break;

            }

            case 3:
                {

                std::string name;
                int quantity;
                std::cout << "Enter Item Name: ";
                std::cin >> name;
                std::cout << "Enter Quantity to Remove: ";
                std::cin >> quantity;
                manager.removeItem(name, quantity);
                break;

            }

            case 4:
                 {

                std::string name, fromID, toID, supplier, recipient;
                int quantity;
                std::cout << "Enter Item Name: ";
                std::cin >> name;
                std::cout << "Enter Quantity to Move: ";
                std::cin >> quantity;
                std::cin.ignore();  // To clear the newline from the input buffer
                std::cout << "Enter From Place ID: ";
                std::getline(std::cin, fromID);
                std::cout << "Enter To Place ID: ";
                std::getline(std::cin, toID);
                std::cout << "Enter Supplier Name: ";
                std::getline(std::cin, supplier);
                std::cout << "Enter Recipient Name: ";
                std::getline(std::cin, recipient);
                manager.moveGoods(name, quantity, fromID, toID, supplier, recipient);
                break;

            }

            case 5:

                manager.displayInventory();
                break;

            case 6:

                manager.displayMovementLog();
                break;


            case 7: {

                std::string name;

                double price;

                std::cout << "Enter Item Name: ";
                std::cin >> name;
                std::cout << "Enter New Price: ";
                std::cin >> price;
                manager.setItemPrice(name, price);
                break;

            }

            case 8: {
                std::string name;
                std::cout << "Enter Item Name to View Price: ";
                std::cin >> name;
                manager.displayItemPrice(name);
                break;
            }

            case 9:
                manager.calculateTotalValue();
                break;


            case 10:
            {
                std::string name;
                std::cout << "Enter Item Name to View Remaining Quantity: ";
                std::cin >> name;
                manager.displayRemainingQuantity(name);
                break;
            }

//---------------------------------

                case 11:


                {

                std::string name;
                std::cout << "Enter Item Name to Track: ";
                std::cin >> name;
                manager.trackItem(name);
                break;

            }


            case 12:
                {


                std::string name;
                std::cout << "Enter Item Name to View Location History: ";
                std::cin >> name;
                manager.displayLocationHistory(name);
                break;

            }




            case 13: {
                std::string supplier, itemName, contractID;
                int quantity;
                std::cout << "Enter Supplier Name: ";
                std::cin >> supplier;
                std::cout << "Enter Item Name: ";
                std::cin >> itemName;
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cout << "Enter Contract ID: ";
                std::cin >> contractID;
                manager.addMilitaryContract(supplier, itemName, quantity, contractID);
                break;
            }

            case 14:
                manager.displayContracts();
                break;


          case 15: {
                std::string orderID, itemName, supplier, recipient;
                int quantity;
                std::cout << "Enter Order ID: ";
                std::cin >> orderID;
                std::cout << "Enter Item Name: ";
                std::cin >> itemName;
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cout << "Enter Supplier Name: ";
                std::cin >> supplier;
                std::cout << "Enter Recipient Name: ";
                std::cin >> recipient;
                manager.addEmergencyOrder(orderID, itemName, quantity, supplier, recipient);
                break;
            }
            case 16: {
                std::string orderID;
                std::cout << "Enter Order ID to Process: ";
                std::cin >> orderID;
                manager.processEmergencyOrder(orderID);
                break;
            }
            case 17:
                manager.displayEmergencyOrders();
                break;



            case 18:


                std::cout << "Exiting system. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    }
     while (choice != 18);

//--------------------------------------------------





std::vector<Base> bases = {
        {"Delhi Base", 1000, 0, {}}, {"Mumbai Base", 1200, 0, {}}, {"Chennai Base", 1500, 0, {}},
        {"Kolkata Base", 800, 0, {}},  {"Bangalore Base", 900, 0, {}},  {"Hyderabad Base", 1100, 0, {}},
        {"Pune Base", 1300, 0, {}}, {"Ahmedabad Base", 1400, 0, {}}, {"Jaipur Base", 1600, 0, {}},
        {"Lucknow Base", 1000, 0, {}}
    };

    // Initialize suppliers
    std::vector<Supplier> suppliers = {
        {"Supplier A", {{"Food Materials", 500, 5}, {"Medicines", 200, 2}}, {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}},
        {"Supplier B", {{"Weapons", 100, 15}, {"Ammunition", 300, 10}}, {20, 15, 25, 35, 45, 55, 65, 75, 85, 95}},
        {"Supplier C", {{"Clothes", 400, 3}, {"Water Supplies", 600, 2}}, {30, 25, 20, 15, 10, 5, 10, 15, 20, 25}}
    };

    //int choice = 0;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. View Base Details\n";
        std::cout << "2. View Supplier Details\n";
        std::cout << "3. Order Items from Suppliers\n";
        std::cout << "4. Save Data to Files\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            for (size_t i = 0; i < bases.size(); ++i) {
                std::cout << i + 1 << ". " << bases[i].name << "\n";
            }
            std::cout << "Select a base to view details: ";
            int base_choice;
            std::cin >> base_choice;
            if (base_choice > 0 && base_choice <= static_cast<int>(bases.size())) {
                bases[base_choice - 1].display();
            } else {
                std::cout << "Invalid choice.\n";
            }
        } else if (choice == 2) {
            for (const auto& supplier : suppliers) {
                supplier.display();
            }
        } else if (choice == 3) {
            std::cout << "Enter the base index (1-10): ";
            int base_index;
            std::cin >> base_index;
            --base_index; // Adjust for 0-based index

            if (base_index >= 0 && base_index < static_cast<int>(bases.size())) {
                std::cout << "Enter the item name to order: ";
                std::string item_name;
                std::cin.ignore();
                std::getline(std::cin, item_name);

                int supplier_index = find_nearest_supplier(suppliers, base_index, item_name);
                if (supplier_index != -1) {
                    std::cout << "Nearest supplier: " << suppliers[supplier_index].name << "\n";
                    for (auto& item : suppliers[supplier_index].items) {
                        if (item.name == item_name) {
                            std::cout << "Available quantity: " << item.quantity << "\n";
                            std::cout << "Enter quantity to order: ";
                            int quantity;
                            std::cin >> quantity;

                            if (quantity <= item.quantity) {
                                if (bases[base_index].add_item({item.name, quantity, item.space_required})) {
                                    item.quantity -= quantity;
                                    std::cout << "Order successful!\n";
                                } else {
                                    std::cout << "Order failed due to insufficient space at the base.\n";
                                }
                            } else {
                                std::cout << "Not enough stock available.\n";
                            }
                            break;
                        }
                    }
                } else {
                    std::cout << "No supplier found for the requested item.\n";
                }
            } else {
                std::cout << "Invalid base index.\n";
            }
        } else if (choice == 4) {
            save_suppliers_to_file(suppliers, "suppliers.txt");

        } else {
            std::cout << "Invalid choice.\n";
        }
    }














































    // Step 2: Proceed with the rest of the program after successful login


    srand(static_cast<unsigned int>(time(0)));

    // Seed random number generator

    // Example locations and distance matrix for the route optimization

    std::vector<std::string> locations = {};

    std::vector<std::vector<int>> distanceMatrix =

    {
        {0, 10, 20, 30},

        {10, 0, 15, 25},

        {20, 15, 0, 35},

        {30, 25, 35, 0}
    };

    // Resource manager simulation


    ResourceManager resourceManager(100, 200, 1000);

    // Example resource quantities

    resourceManager.processTaskDynamically();


    // Monitoring system simulation with devices++++

    MonitoringSystem monitoringSystem;


    monitoringSystem.addDevice(Device("Device_1"));

    monitoringSystem.addDevice(Device("Device_2"));

    monitoringSystem.addDevice(Device("Device_3"));

    // Simulate real-time device monitoring with GPS and Temperature data


    std::thread monitoringThread([&monitoringSystem]()

                                 {
        for (int i = 0; i < 10; ++i)

            {
            monitoringSystem.updateDeviceLocations();

            monitoringSystem.displayAllDevices();

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    )
    ;

    // Start temperature sensor thread

    std::thread tempThread([&]()

                            {

        TemperatureSensor tempSensor;

        DataProcessor dataProcessor;

        for (int i = 0; i < 10; ++i)

            {
            double rawData = tempSensor.generateRawData();

            double processedData = dataProcessor.filterData("Temperature", rawData);

            std::cout << "[Temperature] " << processedData << " Celsius\n";

            std::this_thread::sleep_for(std::chrono::seconds(2));

        }
    }

    )
    ;

    // Start GPS sensor thread

    std::thread gpsThread([&]()

                          {
        GPSSensor gpsSensor;

        DataProcessor dataProcessor;

        for (int i = 0; i < 10; ++i)

            {
            double rawData = gpsSensor.generateRawData();

            double processedData = dataProcessor.filterData("GPS", rawData);

            std::cout << "[GPS] " << processedData << " Coordinates\n";

            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
    )
    ;

    // Invoke the route optimization function

    std::vector<int> optimizedRoute;

     int totalDistance;

    //roteOptimization(distanceMatrix, locations, 0, optimizedRoute, totalDistance, true);

     // Using 0 as start location

    // Output the optimized route and total distance

    std::cout << "Optimized Route: ";

    for (int i : optimizedRoute)

        {

        std::cout << locations[i] << " ";

    }

    std::cout << "\nTotal Distance: " << totalDistance << "\n";

    // Logistics data for simulation

    std::vector<LogisticsData> logisticsDataList =

    {
        {80, 3, 2, 1, 24, false, 5, 6},

        {60, 2, 3, 4, 48, true, 7, 8},

        {90, 4, 1, 2, 12, false, 4, 3}
    }
    ;

    // Invoke the threat level assessment and updates

    assessAndUpdateThreatLevels(logisticsDataList, 5);

    // Update 5 times

    // Create an instance of LogisticsSystem and add supply routes


    LogisticsSystem logisticsSystem;

    Terrain flatTerrain = logisticsSystem.createTerrain("Flat Terrain", 1.0, "flat", false);

    Terrain hillyTerrain = logisticsSystem.createTerrain("Hilly Terrain", 1.5, "mountain", true);

    logisticsSystem.addSupplyRoute("Base A", "Base B", 100.0, hillyTerrain);

    logisticsSystem.addSupplyRoute("Base B", "Base C", 50.0, flatTerrain);

    // Join all threads to ensure they complete before program exits

    monitoringThread.join();

    tempThread.join();

    gpsThread.join();












//-----------------------------------------------------------------
const string filename = "locations.txt";
    //vector<string> locations;
    vector<vector<int>> distances;

    // Create the location file and read the locations and distances
    createLocationFile(filename);
    readLocations(filename, locations, distances);

    srand(static_cast<unsigned int>(time(0))); // Initialize random seed

    vector<Vehicle> vehicles = {
        Vehicle(HEAVY_DUTY, "Heavy Duty Truck", 5.0, 20.0, 80.0, 2.5, 50, 3.0),
        Vehicle(MEDIUM, "Medium Duty Truck", 8.0, 10.0, 100.0, 1.8, 30, 2.0),
        Vehicle(LIGHT_VAN, "Light Van", 12.0, 5.0, 120.0, 1.0, 10, 1.5),
        Vehicle(SMALL_TRUCK, "Small Truck", 15.0, 2.0, 60.0, 1.2, 5, 1.8),
        Vehicle(ELECTRIC_VAN, "Electric Van", 20.0, 3.0, 100.0, 0.8, 7, 0.6),
        Vehicle(CARGO_VAN, "Cargo Van", 10.0, 8.0, 110.0, 1.5, 20, 2.2)};

    int taskChoice;
    do
    {
        // Interactive user choice menu
        cout << "\n\033[1;36m==============================\033[0m\n";
        cout << "\033[1;32mChoose an option:\033[0m\n";
        cout << "\033[1;36m==============================\033[0m\n";
        cout << "1. Calculate Optimized Route\n";
        cout << "2. Simulate Traffic Condition\n";
        cout << "3. Choose Vehicle Type\n";
        cout << "4. Route Cost Calculation\n";
        cout << "5. Unit Shipping\n";
        cout << "6. Exit\n";
        cout << "\033[1;33mEnter your choice: \033[0m";
        cin >> taskChoice;

        switch (taskChoice)
        {
        case 1:
        {
            // Step 1: Create the file with locations
    createLocationFile(filename);

    // Step 2: Read locations and distances from the file
    vector<string> locations;
    vector<vector<int>> distances;
    readLocations(filename, locations, distances);

    // Step 3: Display locations
    cout << "\n\033[1;34mAvailable Locations:\033[0m\n";
    for (size_t i = 0; i < locations.size(); i++) {
        cout << i + 1 << ". " << locations[i] << endl;
    }

    // Optional: Display adjacency matrix
    displayAdjacencyMatrix(locations, distances);

    // Step 4: Ask user for source and destination
    int src, dest;
    while (true) {
        cout << "\nEnter the source location number (1-" << locations.size() << "): ";
        cin >> src;
        cout << "Enter the destination location number (1-" << locations.size() << "): ";
        cin >> dest;

        if (src >= 1 && src <= (int)locations.size() && dest >= 1 && dest <= (int)locations.size()) {
            break;
        } else {
            cout << "\033[1;31mInvalid input! Please try again.\033[0m\n";
        }
    }

    // Step 5: Calculate all possible routes and the shortest path
    vector<int> shortestDistances, previousNodes;
    tie(shortestDistances, previousNodes) = dijkstra(distances, src - 1);

    vector<pair<vector<int>, int>> allRoutes; // Pair of route and its distance
    findRoutes(distances, src - 1, dest - 1, shortestDistances, previousNodes, allRoutes);

    // Step 6: Display all possible routes with distances
    cout << "\n\033[1;32mAll possible routes from " << locations[src - 1] << " to " << locations[dest - 1] << ":\033[0m\n";
    for (const auto &routePair : allRoutes) {
        const auto &route = routePair.first;
        int distance = routePair.second;

        for (size_t i = 0; i < route.size(); i++) {
            cout << locations[route[i]];
            if (i < route.size() - 1) cout << " -> ";
        }
        cout << " (Distance: " << distance << " km)" << endl;
    }

    // Step 7: Print the optimized route along with its distance
    printOptimizedRoute(previousNodes, src - 1, dest - 1, locations, distances);

            break;
        }
        case 2:
        {


           srand(static_cast<unsigned int>(time(0)));  // Initialize random seed



    // Step 1: Display locations to the user
    cout << "\033[1;36m==============================\033[0m\n";
    cout << "\033[1;32mAvailable Locations:\033[0m\n";
    cout << "\033[1;36m==============================\033[0m\n";
    for (size_t i = 0; i < locations.size(); i++) {
        cout << "\033[1;35m" << i + 1 << ". " << locations[i] << "\033[0m\n";
    }
   int src, dest;
    while (true) {
        cout << "\nEnter the source location number (1-" << locations.size() << "): ";
        cin >> src;
        cout << "Enter the destination location number (1-" << locations.size() << "): ";
        cin >> dest;

        if (src >= 1 && src <= (int)locations.size() && dest >= 1 && dest <= (int)locations.size()) {
            break;
        } else {
            cout << "\033[1;31mInvalid input! Please try again.\033[0m\n";
        }
    }
    // Step 2: Ask user for source and destination locations



    // Step 3: Ask the user for the current hour (to simulate traffic congestion)
    int hour;
    cout << "\n\033[1;33mEnter the current hour (0-23): \033[0m";
    cin >> hour;

    // Validate hour input
    if (hour < 0 || hour > 23) {
        cout << "\033[1;31mInvalid hour! Please enter a value between 0 and 23.\033[0m\n";
        return 1;
    }

    // Step 4: Display the selected route's distance and adjusted distance with traffic
    displaySelectedRouteDistance(distances, locations, src - 1, dest - 1, hour);
            break;
        }
        case 3:
        {
            vehicleType(vehicles);
            break;
        }
        case 4:
        {
            // Route cost calculation
            int src, dest;
            cout << "\nEnter the source location number (1-" << locations.size() << "): ";
            cin >> src;
            cout << "Enter the destination location number (1-" << locations.size() << "): ";
            cin >> dest;

            vector<int> tolls = {10, 5, 7};                                                                 // Example: tolls for different road segments
            double fuelCostPerLiter = 1.5;                                                                  // Example: 1.5 units of cost per liter
            vector<int> route = {src - 1, dest - 1};                                                        // Simple route: src to dest
            double minCost = calculateRouteCost(route, distances, vehicles, tolls, fuelCostPerLiter, true); // Assuming heavy traffic
            cout << "\n\033[1;36mThe minimum cost for the route is: \033[1;32m" << minCost << " units\033[0m\n";
            break;
        }
        case 5:
        {
             //shifting of unit
              // Define the army units with the provided data
    vector<ArmyUnit> units = {
        {"The Rajput Regiment", 120, 5, 200, 50, 21900},
        {"The Sikh Regiment", 200, 8, 300, 100, 35500},
        {"The Gorkha Rifles", 150, 7, 250, 70, 28950},
        {"The Dogra Regiment", 180, 6, 280, 60, 29400},
        {"The Jat Regiment", 140, 4, 220, 80, 21900},
        {"61 Cavalry Regiment", 170, 10, 260, 90, 36700},
        {"51 Artillery Brigade", 130, 5, 210, 40, 22650},
        {"Parachute Regiment (Special Forces)", 190, 9, 300, 110, 36900},
        {"Rashtriya Rifles", 160, 8, 270, 95, 32200},
        {"14 Corps (Fire and Fury Corps)", 110, 4, 150, 30, 18250}
    };

    // Create the army unit file first
    string filename = "army_units.txt";
    createArmyUnitFile(filename, units);

    // Display all units first
    displayAllUnits(units);

    // Display the distance matrix
    displayDistanceMatrix();
vector<string> validLocations = {
        "Delhi", "Mumbai", "Chennai", "Kolkata", "Bangalore",
        "Hyderabad", "Ahmedabad", "Pune", "Jaipur", "Lucknow"
    };
   cout << "\033[1;32mAvailable Locations:\033[0m\n"; // Green text for headings
    for (const string& loc : validLocations) {
        cout << "- " << loc << endl;
    }


    // Ask the user which unit is going to shift
    handleUnitShift(units);

// Army Units list with personnel, vehicles, weapons, etc.


    // Locations list for source and destination
    vector<string> locations = {"Delhi", "Mumbai", "Chennai", "Kolkata", "Bangalore", "Hyderabad", "Ahmedabad", "Pune", "Jaipur", "Lucknow"};

    // Distance adjacency matrix (in km)
    vector<vector<int>> distances = {
        {0, 1400, 2200, 1500, 2100, 1500, 900, 1400, 270, 500},
        {1400, 0, 1330, 2000, 980, 710, 520, 150, 1140, 580},
        {2200, 1330, 0, 1670, 360, 630, 1780, 1190, 2040, 2100},
        {1500, 2000, 1670, 0, 1860, 1500, 1700, 1850, 1520, 1000},
        {2100, 980, 360, 1860, 0, 570, 1230, 840, 1800, 1900},
        {1500, 710, 630, 1500, 570, 0, 1200, 560, 1500, 800},
        {900, 520, 1780, 1700, 1230, 1200, 0, 720, 500, 900},
        {1400, 150, 1190, 1850, 840, 560, 720, 0, 1180, 720},
        {270, 1140, 2040, 1520, 1800, 1500, 500, 1180, 0, 780},
        {500, 580, 2100, 1000, 1900, 800, 900, 720, 780, 0}
    };

    // Display Army Units
    printHeader("Available Army Units");
    displayUnits(units);

    // Input unit choice
    int unitChoice;
    cout << YELLOW << "\nEnter the serial number of the Army Unit: " << RESET;
    cin >> unitChoice;

    if (unitChoice < 1 || unitChoice > units.size()) {
        cout << "Error: Invalid Army Unit choice!" << endl;
        return 1;
    }

    // Display Locations
    printHeader("Available Locations");
    displayLocations(locations);

    // Input source and destination location numbers
    int sourceNum, destinationNum;
    cout << YELLOW << "\nEnter the serial number of the source location: " << RESET;
    cin >> sourceNum;
    cout << YELLOW << "Enter the serial number of the destination location: " << RESET;
    cin >> destinationNum;

    if (sourceNum < 1 || sourceNum > locations.size() || destinationNum < 1 || destinationNum > locations.size()) {
        cout << "Error: Invalid location choice!" << endl;
        return 1;
    }

    // Get the selected unit and locations
    ArmyUnit selectedUnit = getUnitByIndex(units, unitChoice);
    string sourceLocation = getLocationByIndex(locations, sourceNum);
    string destinationLocation = getLocationByIndex(locations, destinationNum);

    // Display the transport cost for the unit
    printHeader("Transport Cost Calculation");
    cout << "Transporting " << selectedUnit.unitName << " from " << sourceLocation << " to " << destinationLocation << endl;

    // Calculate and display the transport cost in USD
    displayTransportCost(selectedUnit, distances, sourceNum - 1, destinationNum - 1);






    // Get starting location


    // Get destination location
    // List of Army Units



    // Calculate transport cost for each unit (Example with distance of 1500 km)
    for (int i = 0; i < units.size(); ++i) {
        double transportCost = calculateTransportCost(units[i], 1500);  // Assume 1500 km for all units
        units[i].totalCost = transportCost;  // Store total cost in the unit's totalCost
    }

    // Write all unit details into the file
    writeUnitDetailsToFile(units);

    // Menu for report selection
    int choice;
    do {
        printHeader("Select a report option");
        cout << "1. Generate Monthly Report" << endl;
        cout << "2. Generate Weekly Report" << endl;
        cout << "3. Generate Vehicle Cost Report" << endl;
        cout << "4. Generate Weapon Cost Report" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                generateMonthlyReport(units);
                break;
            case 2:
                generateWeeklyReport(units);
                break;
            case 3:
                generateVehicleCostReport(units);
                break;
            case 4:
                generateWeaponCostReport(units);
                break;
            case 5:
                cout << "\033[1;31mExiting program...\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mInvalid choice, please try again.\033[0m" << endl;
        }

    }
    while (choice != 5);

    return 0;
}while (choice != 5);


        }

        //default:
            //cout << "\033[1;31mInvalid choice! Please try again.\033[0m\n";
        }



while (choice != 5);
        clearInputBuffer(); // Clear input buffer to prevent incorrect input handling
             return 0;
    }










