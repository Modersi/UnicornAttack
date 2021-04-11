cmake_minimum_required( VERSION 3.20.0 )
##### Declaring a project

# Project data #
project( UnicornAttack
         VERSION 0.0.1
         LANGUAGES CXX C
         DESCRIPTION "Unicorn Attack game clone with SDL2 and Box2D" )

# Adding project executable #
add_executable( ${PROJECT_NAME} main.cpp )

# Setting executable file destination folder #
install( TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/../Builded )

# Adding Textures and Fonts to game build folder to make it possible to run game from IDE #
install( DIRECTORY
			${PROJECT_SOURCE_DIR}/Textures
			${PROJECT_SOURCE_DIR}/Fonts
		 DESTINATION
			${PROJECT_BINARY_DIR} )

# Setting project C++ requirements #
set_target_properties( ${PROJECT_NAME} 
						PROPERTIES
							CMAKE_CXX_STANDARD 20
							CMAKE_CXX_STANDARD_REQUIRED ON )



##### Game files

# Adding Textures and Fonts to game install folder #
install( DIRECTORY
			${PROJECT_SOURCE_DIR}/Textures
			${PROJECT_SOURCE_DIR}/Fonts
		 DESTINATION
			${PROJECT_SOURCE_DIR}/../Builded )

# Including all header files #
target_include_directories( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Headers/Game )

# Variable with all game source files #
set( ${PROJECT_NAME}_SourceFiles

		# Game #
		Sources/Game/Camera.cpp
		Sources/Game/ContactListener.cpp
		Sources/Game/Game.cpp
		Sources/Game/GameTimer.cpp
		Sources/Game/Unicorn.cpp

		# Map #
		Sources/Game/Map/Map.cpp
		Sources/Game/Map/Tile.cpp

		# Entities #
		Sources/Game/Map/Entities/BasicEntity.cpp
		Sources/Game/Map/Entities/MultiVertexStaticEntity.cpp
		Sources/Game/Map/Entities/SquareStaticEntity.cpp

		# Components #
		Sources/Game/Components/CoordinatesComponent.cpp
		Sources/Game/Components/FontComponent.cpp
		Sources/Game/Components/TextureAnimationComponent.cpp
		Sources/Game/Components/TextureComponent.cpp
		Sources/Game/Components/TimerComponent.cpp )

# Setting source files of our game #
target_sources( ${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_SourceFiles} )



##### SDL2

# Including SDL2 header files #
target_include_directories( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Headers/SDL2 )

# Linking SDL2 library #
target_link_libraries ( ${PROJECT_NAME} 
							${PROJECT_SOURCE_DIR}/Libraries/SDL2/SDL2.lib
							${PROJECT_SOURCE_DIR}/Libraries/SDL2/SDL2main.lib )

# Adding SDL2 DLL's to game install folder #
install( FILES ${PROJECT_SOURCE_DIR}/Libraries/SDL2/SDL2.dll DESTINATION ${PROJECT_SOURCE_DIR}/../Builded )



##### SDL2 Image

# Including SDL2 Image header files #
target_include_directories( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Headers/SDL2Image )

# Linking SDL2 Image library #
target_link_libraries ( ${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/SDL2Image/SDL2_image.lib )

# Adding SDL2 Image DLL's to game install folder #
install( FILES 
			${PROJECT_SOURCE_DIR}/Libraries/SDL2Image/libpng16-16.dll
			${PROJECT_SOURCE_DIR}/Libraries/SDL2Image/SDL2_image.dll
			${PROJECT_SOURCE_DIR}/Libraries/SDL2Image/zlib1.dll
		 DESTINATION 
			${PROJECT_SOURCE_DIR}/../Builded )



##### SDL2 TTF

# Including SDL2 TTF header files #
target_include_directories( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Headers/SDL2TTF )

# Linking SDL2 TTF library #
target_link_libraries ( ${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/SDL2TTF/SDL2_ttf.lib )

# Adding SDL2 TTF DLL's to game install folder #
install( FILES 
			${PROJECT_SOURCE_DIR}/Libraries/SDL2TTF/libfreetype-6.dll
			${PROJECT_SOURCE_DIR}/Libraries/SDL2TTF/SDL2_ttf.dll
		 DESTINATION 
			${PROJECT_SOURCE_DIR}/../Builded )



##### Box2D

# Including Box2D header files #
target_include_directories( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Headers/Box2D )

# Linking Box2D library #
target_link_libraries( ${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/Box2D/box2d.lib )
