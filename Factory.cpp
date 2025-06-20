#include "Factory.h"

ISistema * Factory::getInstance () {
    return Sistema::getInstance();
}
