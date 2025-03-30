//
// Created by FlifeX on 3/30/25.
//

#ifndef TYPES_H
#define TYPES_H
#include "../main.h"

namespace fck {
    struct ConnectionInfo {
        ComponentPtr from;
        ComponentList multiple_from;

        ComponentPtr to;
        ComponentList multiple_to;
    };
}

#endif //TYPES_H
