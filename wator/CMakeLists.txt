include_directories(.)
include_directories(./http)

aux_source_directory(./http http_SRCS)



add_executable(wator main.cpp ${http_SRCS} )
target_link_libraries( wator framework)
target_link_libraries( wator 
  boost_system
  boost_filesystem
  boost_log
)

install(TARGETS wator RUNTIME DESTINATION bin)
