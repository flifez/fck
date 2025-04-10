//
// Created by FlifeX on 3/29/25.
//

#ifndef EVENT_H
#define EVENT_H

namespace fck {
    enum class EventType {
        Unknown = 0,
    };

    class Event {
    public:
        virtual ~Event() = default;
        [[nodiscard]] virtual EventType get_type() const = 0;
        Event(const Event&) = delete;
        Event& operator=(const Event&) = delete;

        Event(Event&&) = default;
        Event& operator=(Event&&) = default;

    protected:
        Event() = default;
        EventType event_type = EventType::Unknown;
    };

} // fck

#endif //EVENT_H
