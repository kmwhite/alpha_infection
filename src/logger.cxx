#include "logger.hxx"

void ai::Logger::debug(std::string message) {
    _log_message(LOG_DEBUG, message);
}

void ai::Logger::info(std::string message) {
    _log_message(LOG_INFO, message);
}

void ai::Logger::warn(std::string message) {
    _log_message(LOG_WARN, message);
}

void ai::Logger::error(std::string message) {
    _log_message(LOG_ERROR, message);
}

void ai::Logger::fatal(std::string message) {
    _log_message(LOG_FATAL, message);
}

void ai::Logger::_setup_logging(void) {
    logFile.open("ai.log", std::ios::out | std::ios::app);
}

void ai::Logger::_teardown_logging(void) {
    logFile.close();
}

void ai::Logger::_log_message(LogLevel logLevel, std::string message) {
    std::cerr << _generate_log_prefix(logLevel)
        << message
        << std::endl;
}

std::string ai::Logger::_generate_log_prefix(LogLevel logLevel) {
  switch (logLevel) {
        case LOG_DEBUG:
            return "[debug]";
            break;
        case LOG_INFO:
            return "[info]";
            break;
        case LOG_WARN:
            return "[warn]";
            break;
        case LOG_ERROR:
            return "[error]";
            break;
        case LOG_FATAL:
            return "[fatal]";
            break;
        default:
            return "[unknown]";
  }
}
