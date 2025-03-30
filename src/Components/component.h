//
// Created by FlifeX on 3/30/25.
//

#ifndef COMPONENT_H
#define COMPONENT_H
#include <memory>
#include "component_type.h"

namespace fck {
    class Component {
    public:
        virtual ~Component() = default;
        Component(const Component&) = delete;
        Component& operator=(Component&) = delete;

        Component(Component&&) = default;
        Component& operator=(Component&&) = default;

        [[nodiscard]] virtual ComponentType get_type() const = 0;
        [[nodiscard]] virtual bool has_input() const { return false; }
        [[nodiscard]] virtual bool has_multiple_input() const { return false; }
        [[nodiscard]] virtual bool has_output() const { return false; }
        [[nodiscard]] virtual bool has_multiple_output() const { return false; }

        [[nodiscard]] int get_id() const { return id; }
        void set_id(const int id) { this->id = id; }

    protected:
        int id = -1;
        Component() = default;
        ComponentType component_type = ComponentType::Unknown;
    };
}

#endif //COMPONENT_H
