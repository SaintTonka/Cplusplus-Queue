#ifndef EVENT_H
#define EVENT_H

class Event {
public:
    virtual ~Event() = default;
    virtual std::string toString() const = 0;
};

#endif
