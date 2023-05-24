#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Ninja.hpp"

namespace ariel{
    class OldNinja : public Ninja{
    public:
    OldNinja(std::string name, Point point);
    ~OldNinja() override = default;
    OldNinja(const OldNinja&) = default;
    OldNinja& operator=(const OldNinja&) = default;
    OldNinja(OldNinja&&) = default;
    OldNinja& operator=(OldNinja&&) = default;};
}
#endif
