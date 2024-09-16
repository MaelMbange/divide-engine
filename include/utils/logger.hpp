//
// Created by @IceCurim on 15/09/2024.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <chrono>
#include <iostream>

namespace divide_engine{

    struct LogLevel {
        enum class Level{
            INFO,
            WARNING,
            ERROR,
        };

        explicit LogLevel(Level level);
        std::string name() const;

    private:
        Level level;
    };

    class Logger{
        private:
            std::ostream& stream;
            bool show_date_first;
            bool show_date;

            static std::string get_current_time_as_wstring();

        public:
            explicit Logger(bool show_date = false, bool show_date_first = false, std::ostream& stream = std::cout);
            ~Logger() = default;
            void log(std::string&& message, const LogLevel& message_level = LogLevel(LogLevel::Level::INFO)) const;
            void log(const std::string& message, const LogLevel& message_level = LogLevel(LogLevel::Level::INFO)) const;
    };
}

#endif //LOGGER_H
