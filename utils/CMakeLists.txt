add_executable(encrypt encrypt.cpp uls_encrypt.cpp)
target_link_libraries(encrypt aes256)

add_executable(decrypt decrypt.cpp  uls_decrypt.cpp)
target_link_libraries(decrypt aes256)
