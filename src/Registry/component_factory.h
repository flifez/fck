//
// Created by FlifeX on 3/30/25.
//

#ifndef COMPONENT_FACTORY_H
#define COMPONENT_FACTORY_H

#include <functional>

#include "i_registry_context.h"
#include "../main.h"

namespace fck {
    class ComponentFactory {
    public:
        explicit ComponentFactory(std::shared_ptr<IRegistryContext> irc) : ctx(std::move(irc)) {}

        template <typename T, typename... Args>
        std::shared_ptr<T> create_component(Args&&... args) {
            static_assert(std::is_base_of_v<Component, T>, "Must be a component");

            auto component = std::make_shared<T>(std::forward<Args>(args)...);
            ctx->add_component(std::static_pointer_cast<Component>(component));
            return component;
        }

    private:
        std::shared_ptr<IRegistryContext> ctx;
    };
}

#endif //COMPONENT_FACTORY_H
