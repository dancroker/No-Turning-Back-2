cmake_minimum_required(VERSION 3.31)
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

  "src/enums/GameState.hpp"
  "src/enums/CharacterAction.hpp"
  
  "src/GameObjects/GameObject.cpp"
  "src/GameObjects/PlayerCharacter.cpp"


  "src/gui/button.cpp"
  "src/gui/list.cpp"

  "src/Map/LevelGen/LevelGen.cpp"
  "src/Map/LevelGen/Level.cpp"
  "src/Map/MapDraw/MapDraw.cpp"
  "src/Map/GameMap.cpp"

  "src/Camera.cpp"
  "src/Game.cpp"
  "src/InputHandler.cpp"
 "src/AnimationManager.cpp"
 "src/OwnSound.cpp"
 

)

target_link_directories(game PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(game PRIVATE
  "SFML::Graphics"
  "SFML::Window"
  "SFML::System"
  "SFML::Audio"
)


# ASSETS
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/data/" "$<TARGET_FILE_DIR:game>/data/"
  )

# -- im only gonna add this when needed --

# # INSTALL
# install(TARGETS game
#   RUNTIME DESTINATION bin
# )
# install(DIRECTORY data/
#   DESTINATION bin/data
# )
