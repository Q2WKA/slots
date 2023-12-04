#ifndef SLOTS_INCLUDE_STRUCTS_GLASS_H
#define SLOTS_INCLUDE_STRUCTS_GLASS_H

namespace slots {

struct Glass {
public:
    const int height, width;
    int *items;

    Glass(int height_, int width_);
    Glass(Glass&& other);
    ~Glass();

    void print();
};

}

#endif // SLOTS_INCLUDE_STRUCTS_GLASS_H