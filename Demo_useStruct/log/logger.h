#pragma once

#include <iostream>

class Logger {
public:
	enum LogLevel
	{
		Info = 0,
		Warn,
		Error,
	};

public:
	static Logger* getInstancePtr();

	void Out(LogLevel level, const char* from, const char* message);

private:
	void Write(LogLevel level, const char* from, const char* message);

	void WriteInfo(const char* from, const char* message);

	void WriteWarn(const char* from, const char* message);

	void WriteError(const char* from, const char* message);

private:
	static Logger* m_instance;
	LogLevel m_level = Error;
};