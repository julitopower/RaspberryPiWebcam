set(SRC webcam.cpp)

add_executable(webcamserver ${SRC})
target_link_libraries(webcamserver server PocoNet)
