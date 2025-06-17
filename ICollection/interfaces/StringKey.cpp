#include "StringKey.h"
#include <stdexcept>

StringKey::StringKey(std::string k) : key(k) {}

std::string StringKey::getKey() const {
    return key;
}

// Comparación por igualdad (==)
bool StringKey::operator==(const IKey& other) const {
    const StringKey* otherKey = dynamic_cast<const StringKey*>(&other);
    if (otherKey == nullptr)
        throw std::invalid_argument("Clave incompatible en operator==");
    return this->key == otherKey->key;
}

// Comparación por orden (<), útil para diccionarios ordenados
bool StringKey::operator<(const IKey& other) const {
    const StringKey* otherKey = dynamic_cast<const StringKey*>(&other);
    if (otherKey == nullptr)
        throw std::invalid_argument("Clave incompatible en operator<");
    return this->key < otherKey->key;
}
