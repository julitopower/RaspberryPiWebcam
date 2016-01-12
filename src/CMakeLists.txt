set(SRC Server.cpp)

add_library(server ${SRC})
target_link_libraries(server PocoFoundation PocoNet)
