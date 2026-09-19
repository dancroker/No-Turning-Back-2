cmake_minimum_required(VERSION 3.16)
project("SBGJ-2026" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 4)
  set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
endif()

# DEPENDENCIES
add_subdirectory(external)

# GAME
add_executable(game 
  "src/main.cpp"

  "src/Game.cpp"
  
  "src/LevelGen/LevelGen.cpp"
  "src/LevelGen/Level.cpp"
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
if(WIN32)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/data/" "$<TARGET_FILE_DIR:game>/data/"
  )
else()
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/data" "$<TARGET_FILE_DIR:game>/data"
  )
endif()

# -- im only gonna add this when needed --

# # INSTALL
# install(TARGETS game
#   RUNTIME DESTINATION bin
# )
# install(DIRECTORY data/
#   DESTINATION bin/data
# )
