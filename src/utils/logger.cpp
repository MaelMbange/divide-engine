//
// Created by @IceCurim on 15/09/2024.
//
#include "utils/logger.hpp"

using namespace divide_engine;
using namespace std::string_literals;

LogLevel::LogLevel(const Level level) : level(level) {}

std::string LogLevel::name() const {
    switch (level) {
        case Level::INFO:
            return "[INFO]";
        case Level::WARNING:
            return "[WARNING]";
        case Level::ERROR:
            return "[ERROR]";
        case Level::SUCCESS:
            return "[SUCCESS]";
        case Level::FINISHED:
            return "[FINISHED]";
        case Level::TERMINATED:
            return "[TERMINATED]";
        case Level::CLOSED:
            return "[CLOSED]";
        default:
            return "[UNKNOWN]";
    }
}

std::shared_ptr<Logger> Logger::logger = nullptr;

Logger::Logger(const bool show_date, const bool show_date_first, std::ostream& stream) : stream(stream), show_date_first(show_date_first), show_date(show_date){}

std::shared_ptr<Logger> Logger::get_instance(const bool show_date, const bool show_date_first, std::ostream &stream) {
    if(logger == nullptr){
        logger = std::shared_ptr<Logger>(new Logger(show_date, show_date_first, stream));
    }
    return logger;
}

std::string Logger::get_current_time_as_string() {
    std::ostringstream oss;
    oss << std::chrono::system_clock::now();
    return oss.str();
}

void Logger::log(std::string&& message, const LogLevel& message_level) const {
    std::string message2log;

    if(this->show_date) {
        if(this->show_date_first) {
            message2log = get_current_time_as_string() + " : " + message_level.name() + " " + message;
        } else {
            message2log = message_level.name() + " " + message + " : " + get_current_time_as_string();
        }
    }else {
        message2log = message_level.name() + " " + message;
    }
    this->stream << message2log << std::endl;
}

void Logger::log(const std::string& message, const LogLevel& message_level) const {
    std::string message2log;

    if(this->show_date) {
        if(this->show_date_first) {
            message2log = get_current_time_as_string() + " : " + message_level.name() + " " + message;
        } else {
            message2log = message_level.name() + " " + message + " : " + get_current_time_as_string();
        }
    }else {
        message2log = message_level.name() + " " + message;
    }
    this->stream << message2log << std::endl;
}
