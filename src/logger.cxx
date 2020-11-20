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

// TODO: Make use of variable arguments and forward to libmft for all-in-one lib
void ai::Logger::_log_message(LogLevel logLevel, std::string message) {
    // message = forward_to_libfmt_to_build_str()
    std::cerr << _generate_log_prefix(logLevel)
        << " "
        << message
        << std::endl;
}

/*

Colorize based on Log Level, utilizing ANSI escape sequences

Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/
std::string ai::Logger::_generate_log_prefix(LogLevel logLevel) {
  switch (logLevel) {
        case LOG_DEBUG:
            return "\033[1;90;36m[   debug ]\033[0m";
            break;
        case LOG_INFO:
            return "\033[1;90;34m[    info ]\033[0m";
            break;
        case LOG_WARN:
            return "\033[1;90;33m[    warn ]\033[0m";
            break;
        case LOG_ERROR:
            return "\033[1;90;31m[   error ]\033[0m";
            break;
        case LOG_FATAL:
            return "\033[1;90;31m[   fatal ]\033[0m";
            break;
        default:
            return "\033[1;90;37m[ unknown ]\033[0m";
  }
}
