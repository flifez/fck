//
// Created by FlifeX on 3/30/25.
//

#ifndef SOURCE_H
#define SOURCE_H
#include "component.h"

namespace fck {

    class Source : public Component {
    public:
        Source(bool powered);
        [[nodiscard]] ComponentType get_type() const override { return ComponentType::Source; };

        [[nodiscard]] bool has_input() const override { return false; }
        [[nodiscard]] bool has_multiple_input() const override { return false; }
        [[nodiscard]] bool has_output() const override { return true; }
        [[nodiscard]] bool has_multiple_output() const override { return false; }

    private:
        bool powered = false;
    };

} // fck

#endif //SOURCE_H
