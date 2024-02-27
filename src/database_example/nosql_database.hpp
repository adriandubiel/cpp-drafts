#pragma once

#include <iostream>
#include "persistence_interface.hpp"

//
// NO SQL Database - CONCRETE IMPLEMENTATION DETAIL
//
class NoSqlDatabase : public PersistenceInterface
{
public:
    // access to data members
private:
    bool do_read(/* some arguments */) const override
    {
        std::cout << "NoSqlDatabase.read()\n";
        return true;
    };
    bool do_write(/* some arguments */) override { return true; };
};
