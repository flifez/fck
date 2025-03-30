//
// Created by FlifeX on 3/30/25.
//

#include "registry.h"

#include "../Components/component.h"

namespace fck {
    Registry::~Registry() = default;

    void Registry::initialize() {
        auto ctx = std::static_pointer_cast<IRegistryContext>(shared_from_this());
        component_factory = std::make_unique<ComponentFactory>(ctx);
    }

    std::shared_ptr<Registry> Registry::create() {
        auto instance = std::make_shared<Registry>();
        instance->initialize();
        return instance;
    }

    void Registry::add_component(ComponentPtr component) {
        int id = 0;

        if (!components.empty()) {
            id = std::ranges::max_element(
                components,
                [](const auto& a, const auto& b) {
                    return a.first < b.first;
            }
            )->first + 1;
        }

        component->set_id(id);
        components[id] = std::move(component);
    }

    void Registry::connect(ComponentPtr from, ComponentPtr to) {
        const int from_id = from->get_id();
        const int to_id = to->get_id();

        auto& from_info = connections[from_id];
        auto& to_info = connections[to_id];

        // Handle output from 'from' component
        if (from->has_multiple_output()) {
            if (!from_info.multiple_to) {
                from_info.multiple_to = std::make_shared<std::vector<ComponentPtr>>();
            }
            from_info.multiple_to->push_back(to);
        } else {
            if (from_info.multiple_to) {
                throw std::runtime_error("Single output already connected");
            }
            from_info.to = to;
        }

        // Handle input to 'to' component
        if (to->has_multiple_input()) {
            if (!to_info.multiple_from) {
                to_info.multiple_from = std::make_shared<std::vector<ComponentPtr>>();
            }
            to_info.multiple_from->push_back(from);
        } else {
            if (to_info.multiple_from) {
                throw std::runtime_error("Single input already connected");
            }
            to_info.from = from;
        }
}



}
