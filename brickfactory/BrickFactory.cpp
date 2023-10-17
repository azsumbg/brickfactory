#include "pch.h"
#include "framework.h"
#include "brickfactory.h"
#include <fstream>

class BORDER :public BRICK_BASE
{

	public:

		BORDER(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
		{
			NewDims(50.0f, 50.0f);
			type = bricks::border;
			lifes = -1;
		}

		bool Move() override
		{
			std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
			log << L"Move() method called in BORDER CLASS !" << std::endl;
			log.close();
			return false;
		}

		void Transform() override
		{
			std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
			log << L"Transform() method called in BORDER CLASS !" << std::endl;
			log.close();
		}

		void Release() override
		{
			delete this;
		}
};

class CERRAMIC :public BRICK_BASE
{
	public:

		CERRAMIC(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
		{
			type = bricks::cerramic;
			lifes = 1;
		}

		bool Move() override
		{
			std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
			log << L"Move() method called in CERRAMIC CLASS !" << std::endl;
			log.close();
			return false;
		}

		void Transform() override
		{
			type = bricks::fall;
			
		}

		void Release() override
		{
			delete this;
		}
};

class GOLD :public BRICK_BASE
{
public:
	GOLD(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
	{
		type = bricks::gold;
		lifes = 4;
	}

	bool Move() override
	{
		std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
		log << L"Move() method called in GOLD CLASS !" << std::endl;
		log.close();
		return false;
	}

	void Transform() override
	{
		type = bricks::fall;

	}

	void Release() override
	{
		delete this;
	}
};

class NORMAL :public BRICK_BASE
{
public:
	NORMAL(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
	{
		type = bricks::normal;
		lifes = 1;
	}

	bool Move() override
	{
		std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
		log << L"Move() method called in NORMAL CLASS !" << std::endl;
		log.close();
		return false;
	}

	void Transform() override
	{
		type = bricks::fall;

	}

	void Release() override
	{
		delete this;
	}

};

class SILVER :public BRICK_BASE
{
public:
	SILVER(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
	{
		type = bricks::silver;
		lifes = 2;
	}

	bool Move() override
	{
		std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
		log << L"Move() method called in SILVER CLASS !" << std::endl;
		log.close();
		return false;
	}

	void Transform() override
	{
		type = bricks::fall;

	}

	void Release() override
	{
		delete this;
	}
};

class STONE :public BRICK_BASE
{
	public:
		STONE(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
		{
			type = bricks::stone;
			lifes = -1;
		}

		bool Move() override
		{
			std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
			log << L"Move() method called in BORDER CLASS !" << std::endl;
			log.close();
			return false;
		}

		void Transform() override
		{
			std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
			log << L"Transform() method called in STONE CLASS !" << std::endl;
			log.close();
		}

		void Release() override
		{
			delete this;
		}
};

class FALL :public BRICK_BASE
{
	public:

		FALL(float _sx, float _sy) :BRICK_BASE(_sx, _sy)
		{
			type = bricks::fall;
			lifes = 1;
		}

		bool Move() override
		{
			if (y + speed <= 500.0f)
			{
				y += speed;
				SetEdges();
				return true;
			}
			return false;
		}

		void Transform() override
		{
			std::wofstream log(L".\\res\\data\\log.dat", std::ios::app);
			log << L"Transform() method called in FALL CLASS !" << std::endl;
			log.close();
		}

		void Release() override
		{
			delete this;
		}

};


BrickObj iCreateBrick(float _where_x, float _where_y, bricks _which_type)
{
	BrickObj temp_obj = nullptr;

	switch (_which_type)
	{
		case bricks::border:
			temp_obj = new BORDER(_where_x, _where_y);
			break;

		case bricks::cerramic:
			temp_obj = new CERRAMIC(_where_x, _where_y);
			break;

		case bricks::gold:
			temp_obj = new GOLD(_where_x, _where_y);
			break;

		case bricks::normal:
			temp_obj = new NORMAL(_where_x, _where_y);
			break;

		case bricks::silver:
			temp_obj = new SILVER(_where_x, _where_y);
			break;
			
		case bricks::stone:
			temp_obj = new STONE(_where_x, _where_y);
			break;

		case bricks::fall:
			temp_obj = new FALL(_where_x, _where_y);
			break;
	}


	return temp_obj;
}