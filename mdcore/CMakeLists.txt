add_library(mdcore STATIC
	command_listener.cpp
	command.cpp
	dispatcher.cpp
	json_utils.cpp
	listener.cpp
	logger.cpp
	member.cpp
	utils.cpp
)

find_package(Threads)

target_include_directories(mdcore
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/lib
		${PROJECT_SOURCE_DIR}/lib/sleepy-discord/include
		${PROJECT_SOURCE_DIR}/lib/sleepy-discord/deps/include
		${PROJECT_SOURCE_DIR}/lib/sleepy-discord/deps/asio/asio/include
		${websocketpp_SOURCE_DIR}
		${asio_SOURCE_DIR}/asio/include
		${PROJECT_SOURCE_DIR}/lib/sleepy-discord/deps/cpr/include
		${PROJECT_SOURCE_DIR}/lib/opus/include
		${CMAKE_THREAD_LIBS_INIT}
	PRIVATE
		${PROJECT_SOURCE_DIR}/include/mdcore
)

list(APPEND LIBRARIES_TO_LINK "opus")