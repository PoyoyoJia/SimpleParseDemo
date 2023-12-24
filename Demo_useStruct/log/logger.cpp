#include "logger.h"

Logger* Logger::m_instance;

Logger* Logger::getInstancePtr() {
	if (Logger::m_instance == nullptr) {
		Logger::m_instance = new Logger();
	}
	return Logger::m_instance;
}

void Logger::Out(LogLevel level, const char* from, const char* message) {
	if (level <= m_level) {
		Write(level, from, message);
	}
}

void Logger::Write(LogLevel level, const char* from, const char* message) {
	switch (level)
	{
	case LogLevel::Info:
		WriteInfo(from, message);
		break;
	case LogLevel::Warn:
		WriteWarn(from, message);
		break;
	case LogLevel::Error:
		WriteError(from, message);
		break;
	default:
		break;
	}
}

void Logger::WriteInfo(const char* from, const char* message) {
	std::cout << "log info " << from << " -> " << message << std::endl;
}

void Logger::WriteWarn(const char* from, const char* message) {
	std::cout << "log warn " << from << " -> " << message << std::endl;
}

void Logger::WriteError(const char* from, const char* message) {
	std::cout << "log error " << from << " -> " << message << std::endl;
}
