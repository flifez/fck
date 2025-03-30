//
// Created by FlifeX on 3/30/25.
//

#ifndef WIRE_H
#define WIRE_H
#include "component.h"

namespace fck {

    class Wire : public Component {
    public:
        Wire();
        [[nodiscard]] ComponentType get_type() const override { return ComponentType::Wire; };

        [[nodiscard]] bool has_input() const override { return true; }
        [[nodiscard]] bool has_multiple_input() const override { return false; }
        [[nodiscard]] bool has_output() const override { return true; }
        [[nodiscard]] bool has_multiple_output() const override { return false; }

    private:
        bool powered = false;
        std::shared_ptr<Component> source;
        std::shared_ptr<Component> destination;
    };

}

#endif //WIRE_H
