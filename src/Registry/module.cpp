//
// Created by FlifeX on 3/30/25.
//

#include "module.h"

namespace fck {
    bool Module::check_loop() {
        return check_loop(shared_from_this());
    }

    bool Module::check_loop(const std::shared_ptr<Module>& target) const {
        return std::ranges::any_of(submodules | std::views::values, [&](const auto& submodule) {
            return submodule == target || submodule->check_loop(target);
        });
    }

    void Module::add_submodule(const std::shared_ptr<Module>& submodule) {
        int id = 0;

        if (!submodules.empty()) {
            id = std::ranges::max_element(
                submodules,
                [](const auto& a, const auto& b) {
                    return a.first < b.first;
            }
            )->first + 1;
        }

        submodules[id] = submodule;
    }

    void Module::remove_submodule(int id) {
        if (auto it = submodules.find(id); it != submodules.end()) {
            submodules.erase(it);
        }
    }

    std::shared_ptr<Module> Module::clone() {
        //auto m = std::make_shared<Module>(this->name);
        //m->registry = this->registry->clone();
    }
}
