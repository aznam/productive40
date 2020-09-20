#include <sstream>
#include <iostream>

int
main (
	int argc,
	char ** argv
) {
	std::string uuid = "37ecdf48b22f4185815af00b0039ddb6";
	unsigned char buffer[16];
	if(uuid.length() % 2 != 0) {
		uuid.append("0");
	}
	unsigned long s = uuid.length() / 2;
	char* src = (char*)uuid.c_str();
	for(int i = 0; i < s; i++) {
		sscanf_s(src, "%2hhX", buffer+i);
		src += 2;
	}

	std::string hex_str;
	for(size_t sz = 0; sz < 16; sz++) {
		char buf[3];
		sprintf_s(buf, "%02hhx", *(buffer + sz));
		hex_str.append(buf);
	}

	std::cout << hex_str << std::endl;

	return 0;
}