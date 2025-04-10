//
// Created by FlifeX on 3/30/25.
//

#ifndef REGISTRY_H
#define REGISTRY_H

#include <unordered_map>

#include "component_factory.h"
#include "i_registry_context.h"
#include "../main.h"
#include "../Common/types.h"

namespace fck {
    class Registry : public IRegistryContext, public std::enable_shared_from_this<Registry> {
    public:
        void initialize();
        static std::shared_ptr<Registry> create();

        template <typename T, typename... Args>
        std::shared_ptr<T> create_component(Args&&... args);

        ~Registry() override;

        void add_component(ComponentPtr component) override;
        void connect(ComponentPtr from, ComponentPtr to);

        std::shared_ptr<Registry> clone();

        friend class Debug;
    private:
        std::unique_ptr<ComponentFactory> component_factory;
        std::unordered_map<int, ComponentPtr> components;
        std::unordered_map<int, ConnectionInfo> connections;
    };

    template<typename T, typename... Args>
    std::shared_ptr<T> Registry::create_component(Args&&... args)  {
        return component_factory->create_component<T, Args...>(std::forward<Args>(args)...);
    }

}

#endif //REGISTRY_H
