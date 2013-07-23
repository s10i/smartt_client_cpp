
# Compiler
CCC	= g++

LIBRARY_STATIC_FILE = libsmartt.a

RAW_CLIENT_EXECUTABLE = client_raw.run
TEST_EXECUTABLE = test.run

OBJECT_DIRECTORY = obj
SOURCES_DIRECTORY = src

# Flags passed to the C++ compiler.
CXXFLAGS = -g -Wall -W -Wextra -DNDEBUG -DIL_STD -std=c++0x

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    CMSFLAGS = 

    LDFLAGS = -lm -lcrypto -lnsl -lssl
endif
ifeq ($(UNAME), Darwin)
    CMSFLAGS = 

    LDFLAGS = -lm -lssl -lcrypto
endif

# Local objects
LOCAL_OBJECTS =	$(OBJECT_DIRECTORY)/smartt_client.o \
				$(OBJECT_DIRECTORY)/smartt_simple_connection.o \
				$(OBJECT_DIRECTORY)/smartt_simple_protocol.o \
				$(OBJECT_DIRECTORY)/smartt_socket.o

# rules
all: library client

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): library $(SOURCES_DIRECTORY)/test_main.cpp
	$(CCC) $(CXXFLAGS) $(CMSFLAGS) $(SOURCES_DIRECTORY)/test_main.cpp $(LIBRARY_STATIC_FILE) -o $(TEST_EXECUTABLE) $(LDFLAGS) 

library: $(OBJECT_DIRECTORY) $(LOCAL_OBJECTS)
	ar rvs $(LIBRARY_STATIC_FILE) $(LOCAL_OBJECTS)

client: library $(SOURCES_DIRECTORY)/main.cpp
	$(CCC) $(CXXFLAGS) $(CMSFLAGS) $(SOURCES_DIRECTORY)/main.cpp $(LIBRARY_STATIC_FILE) -o $(RAW_CLIENT_EXECUTABLE) $(LDFLAGS)

$(OBJECT_DIRECTORY):
	mkdir -p $(OBJECT_DIRECTORY)

$(OBJECT_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.cpp
	$(CCC) $(CXXFLAGS) $(CMSFLAGS) $(LDFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECT_DIRECTORY)/*.o $(SOURCES_DIRECTORY)/*~ *.dSYM $(LIBRARY_STATIC_FILE) $(RAW_CLIENT_EXECUTABLE)

