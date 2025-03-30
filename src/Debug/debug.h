//
// Created by FlifeX on 3/30/25.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include "../main.h"
#include "../Registry/registry.h"
#include "../Components/component.h"

namespace fck {
    class Debug {
    public:
        static void print_connections(const Registry& registry) {
            std::cout << "Registry Debug Output\n";

            for (const auto& [id, component] : registry.components) {
                std::cout << "Component #" << id << " (" << typeid(*component).name() << ")\n";

                auto it = registry.connections.find(id);
                if (it != registry.connections.end()) {
                    const auto& conn = it->second;

                    if (component->has_multiple_input()) {
                        std::cout << "  Inputs (multiple): ";
                        if (conn.multiple_from) {
                            for (const auto& in : *conn.multiple_from) {
                                std::cout << in->get_id() << " ";
                            }
                        }
                        std::cout << "\n";
                    } else if (conn.from) {
                        std::cout << "  Input (single): " << conn.from->get_id() << "\n";
                    }

                    if (component->has_multiple_output()) {
                        std::cout << "  Outputs (multiple): ";
                        if (conn.multiple_to) {
                            for (const auto& out : *conn.multiple_to) {
                                std::cout << out->get_id() << " ";
                            }
                        }
                        std::cout << "\n";
                    } else if (conn.to) {
                        std::cout << "  Output (single): " << conn.to->get_id() << "\n";
                    }
                } else {
                    std::cout << "  No connections.\n";
                }
            }
        }
    };
}

#endif //DEBUG_H
