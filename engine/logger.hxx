#ifndef LOGGER_H
#define LOGGER_H

#include <mutex>

namespace Log {
    std::mutex lock;
}

#endif