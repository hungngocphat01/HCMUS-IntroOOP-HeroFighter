﻿#pragma once
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

// Các môi trường
enum { NEUTRAL, GENERATIVE, DESTRUCTIVE };
enum { METAL, WOOD, WATER, FIRE, EARTH };
enum { LOST, VICTORY, FOUL };

// Thời gian chờ của cả trận đấu
extern float FightTime;

// Một số alias cho kiểu int để dùng ENUM (để code nhìn đẹp hơn)
typedef int attribute_t;
typedef int result_t;


class Hero
{
protected:
	string Name;
	float HP;	// máu
	float ATK;	// công
	float DEF;	// thủ
	float SPD;	// tốc độ

	// Cho hero này tấn công hero kia
	// Hàm này không thể được gọi bừa bãi mà chỉ có thể được gọi từ hàm public Fight
	void Attack(Hero&);

	float WAIT = 0; // thời gian chờ còn lại khi đánh

public:
	Hero(string name, float hp, float atk, float def, float spd);
	
	// Phân tích một chuỗi (đọc từ file) và tạo hero thích hợp
	static Hero* CreateNewHero(string);

	// Bắt đầu một trận đấu cho hero này với 1 hero khác, trả về kết quả (LOST, VICTORY, FOUL)
	virtual result_t Fight(Hero&);

	// Cập nhật lại các thông số khi hero 1 khắc hero 2 trong trận đấu (update points for conqured opponent)
	static void UpdtPntsForCnqrdOppnt(Hero&, Hero&);

	// Cập nhật lại các thông số khi bị khắc trong 1 team (update points when conqured by teammate)
	virtual void UpdtPntsWhnCnqrdByTmmt();

	// Cập nhật lại các thông số khi được sinh trong 1 team (update points when generated by teammate)
	virtual void UpdtPntsWhnGnrtdByTmmt();

	// Cập nhật lại các thuộc tính theo môi trường
	virtual void UpdtPntsBsdOnEnvrnmnt(attribute_t) = 0;

	// Trả về thuộc tính của hero hiện tại
	virtual attribute_t Attribute() const = 0;
};