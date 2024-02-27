#pragma once

#include "persistence_interface.hpp"
#include <iostream>

//
// (SQL) Database - CONCRETE IMPLEMENTATION DETAIL
//
class Database : public PersistenceInterface
{
public:
    // access to data members
private:
    bool do_read(/* some arguments */) const override
    {
        std::cout << "Database.read()\n";
        return true;
    };
    bool do_write(/* some arguments */) override { return true; };
};
