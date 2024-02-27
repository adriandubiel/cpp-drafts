#include "persistence_interface.hpp"
#include "database.hpp"

// single hidden instance
static PersistenceInterface *instance{nullptr};

// a single global point of access
PersistenceInterface *get_persistence_interface()
{
    /* set default db engine once using immediately called lambda */
    static bool init = []()
    {
        if (!instance)
        {
            static Database db;
            instance = &db;
        }
        return true;
    }();

    return instance;
}

void set_persistence_interface(PersistenceInterface *persistence)
{
    instance = persistence;
}


//___________________________________________
// specializations for Database instance ----

template <>
PersistenceInterface *get_persistence_interface<Database>()
{
    static bool init = []()
    {
        if (!instance)
        {
            static Database db;
            instance = &db;
        }
        return true;
    }();

    return instance;
}

template <>
void set_persistence_interface<Database>(PersistenceInterface *persistence)
{
    instance = persistence;
}
