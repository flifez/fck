//
// Created by FlifeX on 3/30/25.
//

#ifndef COMPONENT_TYPE_H
#define COMPONENT_TYPE_H

namespace fck {
    enum class ComponentType {
        Unknown,
        Wire,
        Source,
        Junction
    };

    inline const char* component_type_to_string(ComponentType type) {
        switch (type) {
            case ComponentType::Unknown:    return "Unknown";
            case ComponentType::Wire:       return "Wire";
            case ComponentType::Source:     return "Source";
            case ComponentType::Junction:   return "Junction";
            default:                        return "Invalid";
        }
    }

}

#endif //COMPONENT_TYPE_H
