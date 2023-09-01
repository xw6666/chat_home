aux_source_directory(. SRC_LIST)

add_executable(chat_client ${SRC_LIST})

target_link_libraries(chat_client pthread jsoncpp)