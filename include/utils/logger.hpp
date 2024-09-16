//
// Created by @IceCurim on 15/09/2024.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <chrono>
#include <iostream>

namespace divide_engine{

    /**
     * @brief Represents the log level.
     */
    struct LogLevel {
        enum class Level{
            INFO,
            WARNING,
            ERROR,
        };

        /**
         * @brief Constructs a LogLevel with the specified level.
         * @param level The log level to be set.
         */
        explicit LogLevel(Level level);

        /**
         * @brief Returns the name of the log level.
         * @return A string representing the log level name.
         */
        [[nodiscard]] std::string name() const;

    private:
        Level level;
    };

    /**
     * @brief Logger class for logging messages with optional timestamps and log levels.
     * It is a singleton class.
     * @var logger is a shared pointer to the logger instance.
     */
    class Logger{
        private:
            static std::shared_ptr<Logger> logger;

            std::ostream& stream;
            bool show_date_first;
            bool show_date;

            /**
             * @brief Returns the current time as a string.
             * @return A string representing the current time.
             */
            static std::string get_current_time_as_string();

            /**
             * @brief Constructs a Logger with the specified parameters.
             * @param show_date A boolean indicating whether the date should be shown.
             * @param show_date_first A boolean indicating whether the date should be shown first.
             * @param stream The output stream to be used.
             */
            explicit Logger(bool show_date = false, bool show_date_first = false, std::ostream& stream = std::cout);

        public:
            /**
             * @brief Returns the singleton instance of the Logger.
             * @param show_date Whether to show the date in the log.
             * @param show_date_first Whether to show the date first in the log.
             * @param stream The output stream for the log.
             * @return A shared pointer to the Logger instance.
             */
            static std::shared_ptr<Logger> get_instance(bool show_date = false, bool show_date_first = false, std::ostream &stream = std::cout);

            ~Logger() = default;

            /**
             * @brief Logs a message with the specified log level.
             * @param message The message to log (passed by r-value).
             * @param message_level The log level of the message.
             */
            void log(std::string&& message, const LogLevel& message_level = LogLevel(LogLevel::Level::INFO)) const;

            /**
             * @brief Logs a message with the specified log level.
             * @param message The message to log (passed by l-value).
             * @param message_level The log level of the message.
             */
            void log(const std::string& message, const LogLevel& message_level = LogLevel(LogLevel::Level::INFO)) const;
    };
}

#endif //LOGGER_H
