#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Device {
protected:
	string name;
	int DeviceID;
	bool active;

public:
	Device(const string& name, int DeviceID, bool active) : name(name), DeviceID(DeviceID), active(active) {}
	virtual void initialize() = 0;
	virtual void sendData(const std::string& data) = 0;
	virtual string receiveData() = 0;
	virtual ~Device() {}
	int getDeviceId() const {
		return DeviceID;
	}
	bool isActivated() const {
		return active;
	}
	virtual void activate() {
		if (active == false)
			cout << "Activating device: " << name << " ID:" << DeviceID << endl;
		else
			cout << "Device:" << DeviceID << " is Already active\n\n";
	}
	virtual void deactivate() {
		cout << "Deactivating device: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
	virtual void ConfigureDevice() {
		cout << "Specific Device Configs";
	}
};

// Printer
class Printer : public Device {
private:
	bool Color;
	bool doublesided;
public:
	Printer(const string& name, int DeviceID, bool active) : Device(name, DeviceID, active) {}
	void initialize() override {
		cout << "Initializing printer: " << name << " ID:" << DeviceID << endl;
	}
	void sendData(const std::string& data) override {
		if (active == true)
			cout << "ID:" << DeviceID << " Printing: " << data << endl;
		else
			cout << "No Device Detected";
	}
	string receiveData() override {
		if (active == true)
			return ""; // Not applicable for a printer
		else
			cout << "NO Device Detected";
	}
	void deactivate() override {
		cout << "Deactivate printer: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
	void ConfigureDevice() override {
		cout << "1 for Color or 0 Black and White: ";
		cin >> Color;
		cout << "Color changed to " << Color << endl;
		cout << "1 For doublesided 0 for Single: ";
		cin >> doublesided;
		cout << "Changed to " << doublesided << endl;
	}
};

//Keyboard
class Keyboard : public Device {
public:
	Keyboard(const string& name, int DeviceID, bool active) : Device(name, DeviceID, active) {}
	void initialize() override {
		cout << "Initializing keyboard: " << name << " ID:" << DeviceID << endl;
	}
	void sendData(const string& data) override {
		if (active == true)
			cout << "ID:" << DeviceID << " Typing: " << data << endl;
		else
			cout << "NO Device Detected";
	}
	string receiveData() override {
		if (active == true)
			return ""; // Not applicable for a keyboard
		else
			cout << "No Device Detected" << endl;
	}
	void deactivate() override {
		cout << "Deactivatating keyboard: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
};
//Mouse
class Mouse : public Device {
private:
	string Dpi;
	string PollingRate;
public:
	Mouse(const string& name, int DeviceID, bool active) : Device(name, DeviceID, active) {}
	void initialize() override {
		cout << "Initializing Mouse: " << name << " ID:" << DeviceID << endl;
	}
	void sendData(const string& data) override {
		if (active == true)
			cout << "ID:" << DeviceID << " Movement Detected: " << data << endl;
		else
			cout << "NO Device detected" << endl;
	}
	string receiveData() override {
		if (active == true)
			return ""; // Not applicable for a mouse
		else
			cout << "NO Device Detected" << endl;
	}
	void deactivate() override {
		cout << "Deactivating Mouse: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
	void ConfigureDevice() override {
		cout << "Change Dpi: ";
		cin >> Dpi;
		cout << "Dpi changed to " << Dpi << endl;
		cout << "Change Polling Rate: ";
		cin >> PollingRate;
		cout << "Polling Rate Changed To " << PollingRate << endl;
	}
};
// Speaker
class Speaker : public Device {
private:
	int volume;
public:
	Speaker(const string& name, int DeviceID, bool active) : Device(name, DeviceID, active), volume(50) {}
	void initialize() override {
		cout << "Initializing Speaker: " << name << " ID:" << DeviceID << endl;
	}
	void sendData(const string& data) override {
		if (active)
			cout << "ID:" << DeviceID << " Playing sound: " << data << endl;
		else
			cout << "No device detected" << endl;
	}
	string receiveData() override {
		if (active)
			return ""; // Not applicable for a speaker
		else
			cout << "No device detected" << endl;
	}
	void deactivate() override {
		cout << "Deactivating Speaker: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
	void ConfigureDevice() override {
		cout << "Change Volume: ";
		cin >> volume;
		cout << "Volume changed to " << volume << endl;
	}
};
// FlashDrive/Storage
class FlashDrive : public Device {
private:
	int capacityGB;
public:
	FlashDrive(const string& name, int DeviceID, bool active, int capacityGB) : Device(name, DeviceID, active), capacityGB(capacityGB) {}
	void initialize() override {
		cout << "Initializing Flash Drive: " << name << " ID:" << DeviceID << endl;
	}
	void sendData(const string& data) override {
		if (active)
			cout << "ID:" << DeviceID << " Writing data: " << data << endl;
		else
			cout << "No device detected" << endl;
	}
	string receiveData() override {
		if (active)
			return "Data received from Flash Drive"; // Simulated data retrieval
		else
			cout << "No device detected" << endl;
	}
	void deactivate() override {
		cout << "Deactivating Flash Drive: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
	void ConfigureDevice() override {
		cout << "Flash Drive Capacity: " << capacityGB << "GB" << endl;
	}
};

// Monitor/Tv
class Monitor : public Device {
private:
	int resolutionX;
	int resolutionY;
public:
	Monitor(const string& name, int DeviceID, bool active, int resolutionX, int resolutionY) : Device(name, DeviceID, active), resolutionX(resolutionX), resolutionY(resolutionY) {}
	void initialize() override {
		cout << "Initializing Monitor: " << name << " ID:" << DeviceID << endl;
	}
	void sendData(const string& data) override {
		if (active)
			cout << "ID:" << DeviceID << " Displaying data: " << data << endl;
		else
			cout << "No device detected" << endl;
	}
	string receiveData() override {
		if (active)
			return ""; // Not applicable for a monitor
		else
			cout << "No device detected" << endl;
	}
	void deactivate() override {
		cout << "Deactivating Monitor: " << name << " ID:" << DeviceID << endl;
		active = false;
	}
	void ConfigureDevice() override {
		cout << "Monitor Resolution: " <<"X" << endl;
		cin >> resolutionX;
		cout << "Y";
		cin >> resolutionY;
		cout << "Resolution Change to " << resolutionX << "X" << resolutionY << "y";
	}
};
// Device Manager class
class DeviceManager {
private:
	vector<Device*> devices;
public:
	void addDevice(Device* device) {
		devices.push_back(device);
	}

	void initializeDevices() {
		cout << "Initializing devices...\n";
		for (Device* device : devices) {
			device->initialize();
		}
	}
	void deactivateDevice(int deviceId)
	{
		bool found = false;
		for (Device* device : devices) {
			if (device->getDeviceId() == deviceId) {
				found = true;
				std::cout << "Sending data to device with ID " << deviceId << std::endl;
				device->deactivate();
				std::cout << "Deactivated\n";
				break;
			}
		}
		if (!found) {
			std::cerr << "Device with ID " << deviceId << " not found." << std::endl;
		}
	}
	void deactivateAllDevices() {
		cout << "Deactivating All Devices...\n\n";
		for (Device* device : devices) {
			device->deactivate();
		}
	}

	void sendDataToAllDevices(const string& data) {
		cout << "Sending data to all devices...\n";
		for (Device* device : devices) {
			if (device->isActivated()) {
				cout << "Sending data to device with ID " << device->getDeviceId() << ": " << data << endl;
				device->sendData(data);
			}
			else {
				cout << "Device with ID " << device->getDeviceId() << " is not activated" << endl;
			}
		}
	}

	void sendDataToDevice(int deviceId, const std::string& data) {
		bool found = false;
		for (Device* device : devices) {
			if (device->getDeviceId() == deviceId) {
				found = true;
				std::cout << "Sending data to device with ID " << deviceId << ": " << data << std::endl;
				device->sendData(data);
				std::cout << "Data sent successfully.\n";
				break;
			}
		}
		if (!found) {
			std::cerr << "Device with ID " << deviceId << " not found." << std::endl;
		}
	}

	void receiveDataFromAllDevices() {
		cout << "Receiving data from all devices...\n";
		for (Device* device : devices) {
			string receivedData = device->receiveData();
			if (!receivedData.empty()) {
				cout << "Received data: " << receivedData << endl;
			}
		}
	}
	void activateAllDevices() {
		cout << "Activating All Devices\n\n";
		for (Device* device : devices) {
			device->activate();
		}
	}
	void ActivateDevice(int deviceId) {
		bool found = false;
		for (Device* device : devices) {
			if (device->getDeviceId() == deviceId) {
				found = true;
				std::cout << "Activating device with ID " << deviceId << std::endl;
				device->activate();
				std::cout << "Activated successfully.\n";
				break;
			}
		}
		if (!found) {
			std::cerr << "Device with ID " << deviceId << " not found." << std::endl;
		}
	}
	void removeDevice(int deviceID) {
		for (auto it = devices.begin(); it != devices.end(); ++it) {
			if ((*it)->getDeviceId() == deviceID) {
				delete* it; // Free memory allocated for the device
				devices.erase(it); // Remove device from the vector
				cout << "Device with ID " << deviceID << " removed successfully.\n";
				return;
			}
		}
		cerr << "Device with ID " << deviceID << " not found.\n";
	}
	void ConfigureDevice(int deviceId) {
		for (Device* device : devices) {
			if (device->getDeviceId() == deviceId) {
				cout << "Configuring device with ID " << deviceId << endl;
				device->ConfigureDevice(); // Call the specific device's ConfigureDevice method
				return;
			}
		}
		cout << "Device with ID " << deviceId << " not found." << endl;
	}
	~DeviceManager() {
		for (Device* device : devices) {
			delete device; // Free memory allocated for each device
		}
	}
};

int main() {
	DeviceManager manager;
	string filename = "DeviceManager.txt"; // Change this to the name of your text file

	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Unable to open file " << filename << endl;
		return 1;
	}

	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		char action;
		iss >> action;
		switch (action) {
		case 'A': {
			string deviceType, name;
			int deviceId;
			bool active;
			iss >> deviceType >> name >> deviceId >> active;
			cout << "Adding device: " << deviceType << " " << name << " ID:" << deviceId << " Active: " << active << endl;
			if (deviceType == "PRINTER") {
				Printer* printer = new Printer(name, deviceId, active);
				manager.addDevice(printer);
				
			}
			else if (deviceType == "KEYBOARD") {
				Keyboard* keyboard = new Keyboard(name, deviceId, active);
				manager.addDevice(keyboard);
				
			}
			else if (deviceType == "MOUSE") {
				Mouse* mouse = new Mouse(name, deviceId, active);
				manager.addDevice(mouse);
				
			}
			else if (deviceType == "SPEAKER") {
				Speaker* speaker = new Speaker(name, deviceId, active);
				manager.addDevice(speaker);
			}
			else if (deviceType == "FLASHDRIVE") {
				int capacityGB;
				iss >> capacityGB;
				FlashDrive* flashDrive = new FlashDrive(name, deviceId, active, capacityGB);
				manager.addDevice(flashDrive);
			}
			else if (deviceType == "MONITOR") {
				int resolutionX, resolutionY;
				iss >> resolutionX >> resolutionY;
				Monitor* monitor = new Monitor(name, deviceId, active, resolutionX, resolutionY);
				manager.addDevice(monitor);
			}
			break;
		}
		case 'I':
			manager.initializeDevices();
			break;
		case 'S': {
			string data;
			getline(iss >> ws, data); // Read the rest of the line as data
			manager.sendDataToAllDevices(data);
			break;
		}
		case 'D':
			int deviceId;
			iss >> deviceId;
			manager.deactivateDevice(deviceId);
			break;
			// Add more cases for other actions...
		case 'C': {
			int deviceId;
			iss >> deviceId;
			manager.ConfigureDevice(deviceId);
			break;
		}
		case 'R': {
			string data;
			getline(iss >> ws, data);
			manager.receiveDataFromAllDevices();
			break;
		}
		case 'P': {
			int deviceId;
			iss >> deviceId;
			string data;
			getline(iss >> ws, data); // Read the rest of the line as data
			manager.sendDataToDevice(deviceId, data);
			break;
		}
		default:
			cerr << "Error: Unknown action in input file" << endl;
			break;
		}
		
	}

	file.close();
	return 0;
}