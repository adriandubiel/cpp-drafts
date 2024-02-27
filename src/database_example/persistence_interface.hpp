#pragma once

/* An abstract interface ready for injection */
class PersistenceInterface
{
public:
    virtual ~PersistenceInterface() = default;

    bool read(/* some arguments */) const { return do_read(); }
    bool write(/* some arguments */) { return do_write(); }

private:
    virtual bool do_read(/* some arguments */) const = 0;
    virtual bool do_write(/* some arguments */) = 0;
};

PersistenceInterface *get_persistence_interface();
void set_persistence_interface(PersistenceInterface *persistence);



//_________________________________________________________
// or an alternative solution for different db engines:
//

template <typename T>
PersistenceInterface *get_persistence_interface();

template <typename T>
void set_persistence_interface(PersistenceInterface *persistence);

// note:    persistance interface API does not need to be modified
//          when new database engine is introduced

//_________________________________________________________
