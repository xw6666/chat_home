aux_source_directory(. SRC_LIST)

add_executable(chat_server ${SRC_LIST})

target_link_libraries(chat_server muduo_net muduo_base pthread jsoncpp)