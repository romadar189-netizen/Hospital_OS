
#ifndef HOSPITALOS_ROOM_H
#define HOSPITALOS_ROOM_H


enum Type {
    GeneralWard,
  PrivateRoom,
  ICU,
  OperatingRoom
};

class Room {
private:
    static int Nextid;
    static int NextNumberRoom;
    int id;
    int RoomNumber;
    Type type;
    int capacity;
     int occupied;
public:
    Room(Type type, int capacity, int occupied);
    // Getery
    Type getType() const;
    int getCapacity() const;
    int getOccupied() const;
    int getId() const;
    int getRoomNumber() const;
    //Setery
    void setRoomNumber(int RoomNumber);
    void setType(Type type);
    void setCapacity(int capacity);
    void setOccupied(int occupied);
};
#endif //HOSPITALOS_ROOM_H