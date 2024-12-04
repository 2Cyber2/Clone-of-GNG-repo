#pragma once

// This header includes all files inside the framework project.
// It is meant for use by game projects ONLY.
// As new files are created, include them here so the game has easy access to them.
// It should **not** be included by any files inside the framework project.

#if GAME_PROJECT

#include "Core/CoreHeaders.h"

#include "Core/FWCore.h"
#include "Core/FWWindows.h"
#include "Core/GameCore.h"
#include "Shaders/ShaderProgram.h"
#include "Vector/Vector.h"
#include "Utility/Utility.h"
#include "Mesh/Mesh.h"
#include "Texture/Texture.h" 
#include "Libraries/json.hpp"
#include "Camera/Camera.h"
#include "Animation/Animation.h"
#include "AnimationCollection/AnimationCollection.h"
#include "GameObject/GameObject.h"
#include "Camera/Camera.h"
#include "SpriteSheet/SpriteSheet.h"
#include "AnimationPlayer/AnimationPlayer.h"

#endif // GAME_PROJECT
