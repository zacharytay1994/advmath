/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "NDCTransformer.h"
#include "Cube.h"
#include "TexCube.h"
#include "Surface.h"
#include "TextureVertex.h"
#include "Pipeline.h"
#include "TextureEffect.h"
#include "ColorEffect.h"
#include "TextureEffectPerPixel.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Cube cube;
	Surface surf = Surface(300, 100);
	Surface texSurf = Surface("pikachumeme.bmp");
	static constexpr float dTheta = PI/4;
	float theta_x = 0.0f;
	float theta_y = 0.0f;
	float theta_z = 0.0f;
	float zVal = 2.5f;
	float time = 0.0f;

	// light pos values
	float lightPosX = 0.0f;
	float lightPosY = 0.0f;
	float lightPosZ = 2.5f;
	TextureVertex tvec1 = TextureVertex( { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f });
	TextureVertex tvec2 = TextureVertex({ 300.0f, 10.0f, 1.0f }, { 1.0f, 0.0f });
	TextureVertex tvec3 = TextureVertex({ 10.0f, 300.0f, 1.0f }, { 0.0f, 1.0f });
	TextureVertex tvec4 = TextureVertex({ 300.0f, 300.0f, 1.0f }, { 1.0f, 1.0f });
	
	TextureVertex tvec11 = TextureVertex({ 300.0f, 100.0f, 1.0f }, { 0.0f, 0.0f });
	TextureVertex tvec21 = TextureVertex({ 600.0f, 150.0f, 1.0f }, { 1.0f, 0.0f });
	TextureVertex tvec31 = TextureVertex({ 400.0f, 300.0f, 1.0f }, { 0.0f, 1.0f });
	TextureVertex tvec41 = TextureVertex({ 600.0f, 300.0f, 1.0f }, { 1.0f, 1.0f });

	// shared zBuffer
	std::shared_ptr<ZBuffer> zBuffer;
	// for testing texture effect
	Pipeline<TextureEffect> pipeline;
	IndexedTriangleList<Pipeline<TextureEffect>::Vertex> testList;
	IndexedTriangleList<Pipeline<TextureEffect>::Vertex> tessellateList;

	// pipeline for point light
	Pipeline<TextureEffect> pipelineLight;
	IndexedTriangleList<Pipeline<TextureEffect>::Vertex> lightList;

	// pipeline for per pixel light
	Pipeline<TextureEffectPerPixel> pipelinePerPixel;
	IndexedTriangleList<Pipeline<TextureEffectPerPixel>::Vertex> ppStartList;
	IndexedTriangleList<Pipeline<TextureEffectPerPixel>::Vertex> ppTesList;
	// for testing color effect
	//Pipeline<ColorEffect> cPipeline;
	//IndexedTriangleList<Pipeline<ColorEffect>::Vertex> colorList;
};