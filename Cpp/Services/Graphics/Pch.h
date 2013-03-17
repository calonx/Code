//==============================================================================
// Pch.h
// Paul Marden (2/12/2012)
//==============================================================================

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10math.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

#include <assert.h>

#include "../Types/Types.h"
#include "Graphics.h"
#include "GraphicsInt.h"
#include "Camera.h"
