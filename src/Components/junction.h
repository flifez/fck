//
// Created by FlifeX on 3/30/25.
//

#ifndef JUNCTION_H
#define JUNCTION_H
#include "component.h"

namespace fck {

    class Junction : public Component {
    public:
        Junction();
        [[nodiscard]] ComponentType get_type() const override { return ComponentType::Junction; };

        [[nodiscard]] bool has_input() const override { return true; }
        [[nodiscard]] bool has_multiple_input() const override { return true; }
        [[nodiscard]] bool has_output() const override { return true; }
        [[nodiscard]] bool has_multiple_output() const override { return true; }
    };

} // fck

#endif //JUNCTION_H
