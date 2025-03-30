//
// Created by FlifeX on 3/30/25.
//

#ifndef I_REGISTRY_CONTEXT_H
#define I_REGISTRY_CONTEXT_H

#include "../main.h"

namespace fck {

class IRegistryContext {
public:
    virtual ~IRegistryContext() = default;
    virtual void add_component(ComponentPtr component) = 0;

protected:
    IRegistryContext() = default;
};

} // fck

#endif //I_REGISTRY_CONTEXT_H
