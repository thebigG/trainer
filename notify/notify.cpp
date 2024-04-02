#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

#include "../common/utils.hpp"

#include "simpleble/SimpleBLE.h"

using namespace std::chrono_literals;


/**
* At the moment this is what I know about the device
* 
* Service: 00001800-0000-1000-8000-00805f9b34fb
  Characteristic: 00002a00-0000-1000-8000-00805f9b34fb
    Capabilities: read write_request
  Characteristic: 00002a01-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002a04-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002aa6-0000-1000-8000-00805f9b34fb
    Capabilities: read
Service: 00001801-0000-1000-8000-00805f9b34fb
  Characteristic: 00002a05-0000-1000-8000-00805f9b34fb
    Capabilities: indicate
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
Service: 0000180a-0000-1000-8000-00805f9b34fb
  Characteristic: 00002a25-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002a26-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002a27-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002a29-0000-1000-8000-00805f9b34fb
    Capabilities: read
Service: 0000180f-0000-1000-8000-00805f9b34fb
  Characteristic: 00002a19-0000-1000-8000-00805f9b34fb
    Capabilities: read notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
Service: 00001818-0000-1000-8000-00805f9b34fb
  Characteristic: 00002a5d-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002a63-0000-1000-8000-00805f9b34fb
    Capabilities: notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
  Characteristic: 00002a65-0000-1000-8000-00805f9b34fb
    Capabilities: read
  Characteristic: 00002a66-0000-1000-8000-00805f9b34fb
    Capabilities: write_request indicate
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
  Characteristic: a026e005-0a7d-4ab3-97fa-f1500f9feb8b
    Capabilities: write_request indicate
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
Service: a026ee01-0a7d-4ab3-97fa-f1500f9feb8b
  Characteristic: a026e002-0a7d-4ab3-97fa-f1500f9feb8b
    Capabilities: write_command notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
  Characteristic: a026e004-0a7d-4ab3-97fa-f1500f9feb8b
    Capabilities: notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
Service: a026ee03-0a7d-4ab3-97fa-f1500f9feb8b
  Characteristic: a026e00a-0a7d-4ab3-97fa-f1500f9feb8b
    Capabilities: write_command notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
Service: a026ee06-0a7d-4ab3-97fa-f1500f9feb8b
  Characteristic: a026e023-0a7d-4ab3-97fa-f1500f9feb8b
    Capabilities: write_command notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb
Service: a026ee0b-0a7d-4ab3-97fa-f1500f9feb8b
  Characteristic: a026e037-0a7d-4ab3-97fa-f1500f9feb8b
    Capabilities: read write_command notify
    Descriptor: 00002902-0000-1000-8000-00805f9b34fb














The following services and characteristics were found:
[0] 00001800-0000-1000-8000-00805f9b34fb 00002a00-0000-1000-8000-00805f9b34fb
[1] 00001800-0000-1000-8000-00805f9b34fb 00002a01-0000-1000-8000-00805f9b34fb
[2] 00001800-0000-1000-8000-00805f9b34fb 00002a04-0000-1000-8000-00805f9b34fb
[3] 00001800-0000-1000-8000-00805f9b34fb 00002aa6-0000-1000-8000-00805f9b34fb
[4] 00001801-0000-1000-8000-00805f9b34fb 00002a05-0000-1000-8000-00805f9b34fb
[5] 0000180a-0000-1000-8000-00805f9b34fb 00002a25-0000-1000-8000-00805f9b34fb
[6] 0000180a-0000-1000-8000-00805f9b34fb 00002a26-0000-1000-8000-00805f9b34fb
[7] 0000180a-0000-1000-8000-00805f9b34fb 00002a27-0000-1000-8000-00805f9b34fb
[8] 0000180a-0000-1000-8000-00805f9b34fb 00002a29-0000-1000-8000-00805f9b34fb
[9] 0000180f-0000-1000-8000-00805f9b34fb 00002a19-0000-1000-8000-00805f9b34fb
[10] 00001818-0000-1000-8000-00805f9b34fb 00002a5d-0000-1000-8000-00805f9b34fb
[11] 00001818-0000-1000-8000-00805f9b34fb 00002a63-0000-1000-8000-00805f9b34fb
[12] 00001818-0000-1000-8000-00805f9b34fb 00002a65-0000-1000-8000-00805f9b34fb
[13] 00001818-0000-1000-8000-00805f9b34fb 00002a66-0000-1000-8000-00805f9b34fb
[14] 00001818-0000-1000-8000-00805f9b34fb a026e005-0a7d-4ab3-97fa-f1500f9feb8b
[15] a026ee01-0a7d-4ab3-97fa-f1500f9feb8b a026e002-0a7d-4ab3-97fa-f1500f9feb8b
[16] a026ee01-0a7d-4ab3-97fa-f1500f9feb8b a026e004-0a7d-4ab3-97fa-f1500f9feb8b
[17] a026ee03-0a7d-4ab3-97fa-f1500f9feb8b a026e00a-0a7d-4ab3-97fa-f1500f9feb8b
[18] a026ee06-0a7d-4ab3-97fa-f1500f9feb8b a026e023-0a7d-4ab3-97fa-f1500f9feb8b
[19] a026ee0b-0a7d-4ab3-97fa-f1500f9feb8b a026e037-0a7d-4ab3-97fa-f1500f9feb8b


Sample from service/characteristic 11


Received: 14 00 00 00 a0 1a 2e 00 00 00 ed f7
Received: 14 00 00 00 a0 1a 2e 00 00 00 ed f7
Received: 14 00 00 00 a0 1a 2e 00 00 00 ed f7
Received: 14 00 00 00 a0 1a 2f 00 00 00 6e b6
Received: 14 00 4d 00 54 1c 30 00 00 00 52 bf
Received: 14 00 5b 00 d1 1d 31 00 00 00 e5 c5
Received: 14 00 63 00 6d 20 33 00 00 00 ac d1
Received: 14 00 4a 00 69 21 34 00 00 00 03 d7
Received: 14 00 2a 00 b0 22 36 00 00 00 c5 e1
Received: 14 00 18 00 07 23 37 00 00 00 7c e7
Received: 14 00 10 00 63 23 39 00 00 00 b7 f2
Received: 14 00 43 00 2a 24 3a 00 00 00 62 f7
Received: 14 00 80 00 c4 26 3c 00 00 00 88 00
Received: 14 00 68 00 67 29 3e 00 00 00 77 09
Received: 14 00 5c 00 68 2b 40 00 00 00 17 12
Received: 14 00 58 00 3f 2d 42 00 00 00 a8 1a
Received: 14 00 a6 00 df 2f 44 00 00 00 33 22
Received: 14 00 8f 00 11 33 46 00 00 00 7e 2a
Received: 14 00 5a 00 34 34 47 00 00 00 91 2f
Received: 14 00 11 00 73 34 48 00 00 00 5c 35




I believe, if I'm interpreting the HEX right, then 11th is what we're interested in and  bytes [1,3) are power.
*/

int main() {
    auto adapter_optional = Utils::getAdapter();

    if (!adapter_optional.has_value()) {
        return EXIT_FAILURE;
    }

    auto adapter = adapter_optional.value();

    std::vector<SimpleBLE::Peripheral> peripherals;

    adapter.set_callback_on_scan_found([&](SimpleBLE::Peripheral peripheral) {
        std::cout << "Found device: " << peripheral.identifier() << " [" << peripheral.address() << "]" << std::endl;
        peripherals.push_back(peripheral);
    });

    adapter.set_callback_on_scan_start([]() { std::cout << "Scan started." << std::endl; });
    adapter.set_callback_on_scan_stop([]() { std::cout << "Scan stopped." << std::endl; });
    // Scan for 5 seconds and return.
    adapter.scan_for(10000);

    std::cout << "The following devices were found:" << std::endl;
    for (size_t i = 0; i < peripherals.size(); i++) {
        std::cout << "[" << i << "] " << peripherals[i].identifier() << " [" << peripherals[i].address() << "]"
                  << std::endl;
    }

    auto selection = Utils::getUserInputInt("Please select a device to connect to", peripherals.size() - 1);
    if (!selection.has_value()) {
        return EXIT_FAILURE;
    }

    auto peripheral = peripherals[selection.value()];
    std::cout << "Connecting to " << peripheral.identifier() << " [" << peripheral.address() << "]" << std::endl;
    peripheral.connect();

    std::cout << "Successfully connected, printing services and characteristics.." << std::endl;

    // Store all service and characteristic uuids in a vector.
    std::vector<std::pair<SimpleBLE::BluetoothUUID, SimpleBLE::BluetoothUUID>> uuids;
    for (auto service : peripheral.services()) {
        for (auto characteristic : service.characteristics()) {
            uuids.push_back(std::make_pair(service.uuid(), characteristic.uuid()));
        }
    }

    std::cout << "The following services and characteristics were found:" << std::endl;
    for (size_t i = 0; i < uuids.size(); i++) {
        std::cout << "[" << i << "] " << uuids[i].first << " " << uuids[i].second << std::endl;
    }

    selection = Utils::getUserInputInt("Please select a characteristic to read", uuids.size() - 1);

    if (!selection.has_value()) {
        return EXIT_FAILURE;
    }

    // Subscribe to the characteristic.
    peripheral.notify(uuids[selection.value()].first, uuids[selection.value()].second, [&](SimpleBLE::ByteArray bytes) {
        std::cout << "Received: ";
        Utils::print_byte_array(bytes);
    });

    std::this_thread::sleep_for(500s);

    peripheral.unsubscribe(uuids[selection.value()].first, uuids[selection.value()].second);

    peripheral.disconnect();

    return EXIT_SUCCESS;
}
