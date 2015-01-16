include_directories(.)

aux_source_directory(./http http_SRCS)



add_executable(wator ${http_SRCS} )
target_link_libraries( wator framework)


install(TARGETS wator RUNTIME DESTINATION bin)
