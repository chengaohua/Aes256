add_executable(encrypt encrypt.cpp )
target_link_libraries(encrypt ulsEncrypt)

add_executable(decrypt decrypt.cpp  )
target_link_libraries(decrypt ulsEncrypt)

add_executable(merge merge.cpp)
target_link_libraries(merge ulsEncrypt)