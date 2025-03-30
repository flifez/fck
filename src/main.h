//
// Created by FlifeX on 3/30/25.
//

#ifndef MAIN_H
#define MAIN_H

#include <vector>

namespace fck {
    class Component;

    using ComponentPtr = std::shared_ptr<Component>;
    using ComponentPtrList = std::vector<ComponentPtr>;
    using ComponentList = std::shared_ptr<ComponentPtrList>;

    class Wire;
    class Source;
    class Junction;

    class Event;

    class IRegistryContext;
    class Registry;
    class ComponentFactory;
    class Module;
    class Communication;
}

#endif //MAIN_H
