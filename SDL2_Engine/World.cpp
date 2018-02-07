#include "World.h"
#include "Rect.h"
#include "Renderer.h"
#include <string>

World::World(Renderer * _pRenderer, const char * _pFile, Rect * _pRect)
	: TexturedEntity(_pRenderer, _pFile, _pRect)
{
}

World::~World()
{
	// save counter of entities
	int count = m_pEntities.size();

	// delete all entities
	for (int i = 0; i < count; i++)
		m_pEntities.pop_front();
}

void World::LoadWorld(Renderer * _pRenderer)
{
	// string to identify world
	std::string s;

	/*
	Tree fill strings

	1 = Tree top left
	2 = Tree top mid
	3 = Tree top right
	4 = Tree left
	5 = Tree right
	6 = Tree mid
	7 = Tree bottom left
	8 = Tree bottom mid
	9 = Tree bottom right
	*/

	/*
	Gras fill strings
	 Q = gras01
	 W = gras02
	 E = dirt top left
	 R = dirt top mid
	 T = dirt top right
	 Z = dirt botom left
	 U = dirt botom mid
	 I = dirt botom right
	 O = dirt left
	 P = dirt right
	 + = dirt mid
	*/

	/*	
	Water fill strings
	 A = water top left
	 S = water top mid
	 D = water top right
	 F = water bottom left
	 G = water bottom  mid
	 H = water bottom right
	 J = water left
	 K = water right
	 L = water mid
	 N = water in top left
	 M = water in top right
	 ; = water in bottom left
	 : = water in bottom right
	*/

	/*
	Misc fill strings
	 Y = small tree top
	 X = samll tree bottom
	 C = wood
	 V = stone
	 B = barrel
	*/




	s += "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";
	s += "LNGGGGGGGGGGGGGGGGGGGGMLLLLLLLLLLLLLLLLLNGGGGGGGML";
	s += "LK12222222222222222223JLLLLLLLLLLLLLLLLNH1222223JL";
	s += "LK46666666666666666665FMLLLLLLLLLLLLLLNH16666665JL";
	s += "LK466666668888886666663FGMLLLLLLLLLLLNH166666665JL";
	s += "LK46666669++++++766666623FMLLLLLLLLLNH1666666665JL";
	s += "LK4666665++++++++466666663FGGMLLLLLLK16666666665JL";
	s += "LK4666665+++++++1666666666223FMLLLLNH46666666665JL";
	s += "LK7666666223++++46666666666663FGGGGH166666666665JL";
	s += "LK+4666666663+1266666666666665+++++1666666666669JL";
	s += "LK+7666666669+7666666666666669+++++466666666669+JL";
	s += "LK++46666669+++76666666666665++++++76666666689++JL";
	s += "L;D+4666665BB+BB4666666666669+++++++46666665++++JL";
	s += "LL;D4666665+BBB+466666666665++++++++78888889++++JL";
	s += "LLLK7666665B+++B466688866889++++UU++++++UUU+++++JL";
	s += "LLL;D466665+BBB+4689+++79+++++UIWWZUU++IWWWZU+++JL";
	s += "LLLLK766665++UU+79++U++++++++PWWWWWWWZIWWWWWWO++JL";
	s += "LLLLK+78889UIWWZUUUIWO++++++++RRTWWWWWWWWWWWE+++JL";
	s += "LLLL;D++++PWWWQWWWWWWO+++++++++++TWWWWWWWWWWZ+++JL";
	s += "LLLLL;D+++PWWWWWWWQWWO++++123++++PWWWWWWWWWWWO+A:L";
	s += "LLLLLL;D+++RTWWWETQWE++++16663++++RRTWWERRRRRAS:LL";
	s += "LLLLLLL;SSSD+RRR++RR++++16666623+++++RR+ASSSS:LLLL";
	s += "LLLLLLLLLLL;SSSSD+++++++78888889+++++++A:LLLLLLLLL";
	s += "LLLLLLLLLLLLLLLL;SSSSSSSSSSSSSSSSSSSSSS:LLLLLLLLLL";
	s += "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";

	// go through all char
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			// switch chars
			// S = 0 x on atlas map
			// 0 = 64
			// W = 128
			// X = 192
			switch (s[y * 50 + x])
			{
			case '1':
				m_world[x][y] = 0;
				break;
			case '2':
				m_world[x][y] = 16;
				break;
			case '3':
				m_world[x][y] = 32;
				break;
			case '4':
				m_world[x][y] = 48;
				break;
			case '5':
				m_world[x][y] = 64;
				break;
			case '6':
				m_world[x][y] = 80;
				break;
			case '7':
				m_world[x][y] = 96;
				break;
			case '8':
				m_world[x][y] = 112;
				break;
			case '9':
				m_world[x][y] = 128;
				break;
			case 'Q':
				m_world[x][y] = 144;
				break;
			case 'W':
				m_world[x][y] = 160;
				break;
			case 'E':
				m_world[x][y] = 176;
				break;
			case 'R':
				m_world[x][y] = 192;
				break;
			case 'T':
				m_world[x][y] = 208;
				break;
			case 'Z':
				m_world[x][y] = 224;
				break;
			case 'U':
				m_world[x][y] = 240;
				break;
			case 'I':
				m_world[x][y] = 256;
				break;
			case 'O':
				m_world[x][y] = 272;
				break;
			case 'P':
				m_world[x][y] = 288;
				break;
			case '+':
				m_world[x][y] = 304;
				break;
			case 'A':
				m_world[x][y] = 320;
				break;
			case 'S':
				m_world[x][y] = 336;
				break;
			case 'D':
				m_world[x][y] = 352;
				break;
			case 'F':
				m_world[x][y] = 368;
				break;
			case 'G':
				m_world[x][y] = 384;
				break;
			case 'H':
				m_world[x][y] = 400;
				break;
			case 'J':
				m_world[x][y] = 416;
				break;
			case 'K':
				m_world[x][y] = 432;
				break;
			case 'L':
				m_world[x][y] = 448;
				break;
			case 'Y':
				m_world[x][y] = 464;
				break;
			case 'X':
				m_world[x][y] = 480;
				break;
			case 'C':
				m_world[x][y] = 496;
				break;
			case 'V':
				m_world[x][y] = 512;
				break;
			case 'B':
				m_world[x][y] = 528;
				break;
			case 'N':
				m_world[x][y] = 544;
				break;
			case 'M':
				m_world[x][y] = 560;
				break;
			case ';':
				m_world[x][y] = 576;
				break;
			case ':':
				m_world[x][y] = 592;
				break;
			default:
				break;
			}
		}
	}

	// create new textured entities
	// screen resolution 1280x720
	// 1 block 16x16
	// 20 x 12 blocks
	for (int i = 0; i < 22 * 14; i++)
		m_pEntities.push_back(new TexturedEntity(_pRenderer, nullptr, new Rect(16, 16)));
}

void World::RenderEntities(Renderer * _pRenderer, int _playerPosX, int _playerPosY)
{
	// player position in x, y coordinates
	int posX = (_playerPosX - 640) / 64 - 1;
	int posY = (_playerPosY - 360) / 64 - 1;

	// destination and source rect
	Rect destination;
	Rect source;
	Rect dirt;

	// go through all entities
	for (int y = 0; y < 14; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			// save position x, y and tile id
			int realX = posX + x;
			int realY = posY + y;
			int tile = 0;

			// get entity at index
			std::list<TexturedEntity*>::iterator entity = std::next(
				m_pEntities.begin(), y * 21 + x);

			// if position out of world set tile to water
			if (realX < 0 || realX > 49 || realY < 0 || realY > 24)
			{
				tile = 448;
				(*entity)->SetColType(ECollisionType::WALL);
			}

			// if position in world set tile and collision
			else
			{
				// set tile
				tile = m_world[realX][realY];
				

				// set collision
				if (tile == 0 || tile == 16 || tile == 32 || tile == 48 || tile == 64 || tile == 80 || tile == 96 || tile == 112 || tile == 128 || tile == 448)
					(*entity)->SetColType(ECollisionType::WALL);
				else
					(*entity)->SetColType(ECollisionType::NONE);
			}

			// set destination rect
			destination.x = realX * 64;
			destination.y = (posY + y) * 64;
			destination.h = 64;
			destination.w = 64;

			// set rect of entity
			(*entity)->SetRect(&destination);

			// set source rect
			source.x = tile;
			source.y = 0;
			source.h = 16;
			source.w = 16;
			// set dirt rect
			dirt = source;
			dirt.x = 304;

			// if texture got alpha map put dirt under it
			if (source.x < 144 || source.x > 304 && source.x < 448 || source.x > 448)
			{
				_pRenderer->RenderTexture(m_pTexture, &destination, &dirt, 0, true);
			}
			// render rect
				_pRenderer->RenderTexture(m_pTexture, &destination, &source, 0, true);
		}
	}
}