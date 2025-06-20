/*#ifndef STRINGKEY_H
#define STRINGKEY_H

#include "IKey.h"
#include <string>

class StringKey : public IKey {
private:
    std::string key;

public:
   bool equals(IKey*) const override; 
    StringKey(std::string k);
    std::string getKey() const;

    // Comparador necesario si tu diccionario lo usa
    bool operator==(const IKey& other) const;
    bool operator<(const IKey& other) const;

    virtual ~StringKey();
};

#endif
*/