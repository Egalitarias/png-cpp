#pragma once

#include <stdio.h>

// 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.

class Log
{
public:
	static void LogMessage(const char* message) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, "%s", message);
		fclose(out);
	}

	static void LogMessage(const char* format, const char* value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void LogMessage(const char* format, int value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void LogMessage(const char* format, int value0, int value1) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0, value1);
		fclose(out);
	}

	static void LogMessage(const char* format, int value0, int value1, int value2) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0, value1, value2);
		fclose(out);
	}

	static void LogMessage(const char* format, long value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void LogMessage(const char* format, long value0, long value1) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0, value1);
		fclose(out);
	}

	static void LogMessage(const char* format, long value0, long value1, long value2, long value3) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0, value1, value2, value3);
		fclose(out);
	}

	static void LogMessage(const char* format, unsigned value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void LogMessage(const char* format, unsigned long value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void LogMessage(const char* format, float value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void LogMessage(const char* format, float value0, float value1) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0, value1);
		fclose(out);
	}

	static void LogMessage(const char* format, size_t value0) {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "at");
		if (err != 0) {
			return;
		}

		fprintf(out, format, value0);
		fclose(out);
	}

	static void Clear() {
		FILE* out;
		errno_t err = fopen_s(&out, "log.txt", "wt");
		if (err != 0) {
			return;
		}

		fclose(out);
	}
};
