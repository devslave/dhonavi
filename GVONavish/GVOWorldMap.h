#pragma once
#include "GVONoncopyable.h"
#include "GVOImage.h"
#include "GVOConfig.h"
#include "GVOVector.h"
#include "GVONormalizedPoint.h"




//!@brief 世界地図
//!@brief 表示座標系と世界座標系の変換などが仕事。
class GVOWorldMap : private GVONoncopyable {
	friend class GVORenderer;
public:
private:
	GVOImage m_mapImage;

public:
	GVOWorldMap()
	{
	}

	virtual ~GVOWorldMap()
	{
	}

	bool loadFromFile( const std::wstring& fileNmee );

	const GVOImage& image() const
	{
		return m_mapImage;
	}

	POINT imageCoordFromWorldCoord( const POINT& worldCoord ) const;

	GVONormalizedPoint normalizedPoint( const POINT worldCoord ) const
	{
		return GVONormalizedPoint( worldCoord.x / (float)k_worldWidth, worldCoord.y / (float)k_worldHeight );
	}
};
