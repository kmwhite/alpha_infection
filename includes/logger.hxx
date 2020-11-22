#include <iostream>
#include <string>
#include <fstream>

namespace ai {
    class Logger {
        public:
            enum LogLevel {
                LOG_DEBUG,
                LOG_INFO,
                LOG_WARN,
                LOG_ERROR,
                LOG_FATAL
            };

        Logger() { _setup_logging(); }
        ~Logger() { _teardown_logging(); }

        void debug(std::string message);
        void info(std::string message);
        void warn(std::string message);
        void error(std::string message);
        void fatal(std::string message);

        private:
            void _setup_logging(void);
            void _teardown_logging(void);
            void _log_message(Logger::LogLevel logLevel, std::string message);
            std::string _generate_log_prefix(Logger::LogLevel logLevel);

            Logger::LogLevel currentLogLevel;
            std::fstream logFile;
    };
} // namespace ai