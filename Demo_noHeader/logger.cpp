#pragma once

#include <iostream>

struct Logger {
public:
	enum LogLevel
	{
		Info = 0,
		Warn,
		Error,
	};

public:
	static Logger* getInstancePtr()
	{
		if (Logger::m_instance == nullptr) {
			Logger::m_instance = new Logger();
		}
		return Logger::m_instance;
	}

	void Out(LogLevel level, const char* from, const char* message)
	{
		if (level <= m_level) {
			Write(level, from, message);
		}
	}

private:
	void Write(LogLevel level, const char* from, const char* message)
	{
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

	void WriteInfo(const char* from, const char* message)
	{
		std::cout << "log info " << from << " -> " << message << std::endl;
	}

	void WriteWarn(const char* from, const char* message)
	{
		std::cout << "log warn " << from << " -> " << message << std::endl;
	}

	void WriteError(const char* from, const char* message)
	{
		std::cout << "log error " << from << " -> " << message << std::endl;
	}

private:
	static Logger* m_instance;
	LogLevel m_level = Error;
};

Logger* Logger::m_instance = nullptr;