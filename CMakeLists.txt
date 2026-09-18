cmake_minimum_required(VERSION 3.16)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("SBGJ-2026" LANGUAGES CXX)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 4)
  set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
endif()

# DEPENDENCIES
add_subdirectory(external)

# GAME
add_executable(game 
	src/main.cpp
)

target_link_directories(game PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(game PRIVATE
  "sfml-graphics"
  "sfml-window"
  "sfml-system"
)


# ASSETS
file(MAKE_DIRECTORY data)
if(WIN32)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/data/" "$<TARGET_FILE_DIR:game>/data/"
  )
else()
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/data" "$<TARGET_FILE_DIR:game>/data"
  )
endif()

# INSTALL
install(TARGETS game
  RUNTIME DESTINATION bin
)
install(DIRECTORY data/
  DESTINATION bin/data
)
