#include "persistence_interface.hpp"
#include "nosql_database.hpp"

// single hidden instance for NoSQL database engine
static PersistenceInterface *noSqlInstance{nullptr};

// Specializations for NoSqlDatabase instance ----

template <>
PersistenceInterface *get_persistence_interface<NoSqlDatabase>()
{
    static bool init = []()
    {
        if (!noSqlInstance)
        {
            static NoSqlDatabase db;
            noSqlInstance = &db;
        }
        return true;
    }();

    return noSqlInstance;
}

template <>
void set_persistence_interface<NoSqlDatabase>(PersistenceInterface *persistence)
{
    noSqlInstance = persistence;
}
