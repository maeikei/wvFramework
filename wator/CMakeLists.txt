include_directories(./)
include_directories(./http)
include_directories(./builder)
include_directories(./collector)
include_directories(./loader)

aux_source_directory(./ self_SRCS)
aux_source_directory(./http http_SRCS)
aux_source_directory(./builder builder_SRCS)
aux_source_directory(./collector collector_SRCS)
aux_source_directory(./loader loader_SRCS)



add_executable(wator 
  ${self_SRCS} ${http_SRCS} ${builder_SRCS} ${collector_SRCS} ${loader_SRCS} 
)
target_link_libraries( wator framework)
target_link_libraries( wator 
  boost_system
  boost_filesystem
  boost_log
)

install(TARGETS wator RUNTIME DESTINATION bin)
