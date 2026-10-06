#include "Room.h"

#include <stdexcept>
#include <string>
int Room::NextNumberRoom = 1;
int Room::Nextid = 1000;
Room::Room(Type type, int capacity, int occupied) : type(type){
    // capacity
    if (capacity < 0 || capacity > 50) {
        throw std::invalid_argument("capacity must be greater than");
    }
    else {
        Room::capacity = capacity;
    }
    // occupied
    if (occupied < 0 || occupied > 50 || occupied > capacity) {
        throw std::invalid_argument("ocupied must be greater than");
    }
    else {
        Room::occupied = occupied;
    }

    // id

    RoomNumber = NextNumberRoom++;
    id = Nextid++;
}

//getery

int Room::getCapacity() const {
    return Room::capacity;
}
int Room::getOccupied() const {
    return Room::occupied;
}
Type Room::getType() const {
    return Room::type;
}
int Room::getRoomNumber() const {
    return Room::RoomNumber;
}
int Room::getId() const {
    return Room::id;
}

//Setery

void Room::setCapacity(int capacity) {
    if (capacity < 0 || capacity > 50 || capacity < occupied) {
        throw std::invalid_argument("capacity must be greater than");
    }
    else {
        Room::capacity = capacity;
    }
}
void Room::setOccupied(int occupied) {
    if (occupied < 0 || occupied > 50 || occupied > capacity) {
        throw std::invalid_argument("occupied must be greater than");
    }
    else {
        Room::occupied = occupied;
    }
}
void Room::setType(Type type) {
    Room::type = type;
}
void Room::setRoomNumber(int RoomNumber) {
    Room::RoomNumber = RoomNumber;
}