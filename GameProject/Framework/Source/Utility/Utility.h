#pragma once

namespace fw {

	void outputMessage(const char* message, ...);
	char* loadCompleteFile(const char* filename, long* length);
	double GetHighPrecisionTime();

} // namespace fw
