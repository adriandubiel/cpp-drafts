#include <iostream>

#include "persistence_interface.hpp"

class Widget
{
public:
    bool read() const
    {
        return get_persistence_interface()->read();
    }
};

//_________________________________________________________
// alternative when more than one db engine has to be used in app:

#include "db_engines.hpp"

class Gadget
{
public:
    bool read() const
    {
        return get_persistence_interface<NoSqlDatabase>()->read();
    }
};

class Fooget
{
public:
    bool read() const
    {
        return get_persistence_interface<Database>()->read();
    }
};

/* Test code with mocked PersistenceInterface */
// ...

/* optionally set the persistence interface to custom db engine */
void setPostgreDb()
{
    class PostgreDatabase : public PersistenceInterface
    {
    public:
        bool do_read(/* some arguments */) const override
        {
            std::cout << "PostgreDatabase.read()\n";
            return true;
        };
        bool do_write(/* some arguments */) override { return true; };
    };

    static PostgreDatabase db{};
    set_persistence_interface(&db);
}

int main()
{
    std::cout << "\nDatabase Example\n\n";

    Widget w1{};
    w1.read();

    Gadget g1{};
    g1.read();

    Fooget f1{};
    f1.read();

    setPostgreDb();
    // we operate on a global and care must be always taken!
    w1.read();

    // no changes for no-sql
    g1.read();

    std::cout << "\n";

    return 0;
}
