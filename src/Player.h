#ifndef _PLAYER_H
#define _PLAYER_H

#include <list>
#include "libs.h"
#include "Ship.h"
#include "StarSystem.h"

class Mission;

class Player: public Ship {
public:
	OBJDEF(Player, Ship, PLAYER);
	Player(ShipType::Type shipType);
	Player() {}
	virtual ~Player();
	void PollControls();
	virtual void Render(const Frame *camFrame);
	void DrawHUD(const Frame *cam_frame);
	virtual void SetDockedWith(SpaceStation *, int port);
	void TimeStepUpdate(const float timeStep);
	enum FlightControlState { CONTROL_MANUAL, CONTROL_FIXSPEED, CONTROL_AUTOPILOT };
	FlightControlState GetFlightControlState() const { return m_flightControlState; }
	void SetFlightControlState(FlightControlState s);
	const SBodyPath *GetHyperspaceTarget() const { return &m_hyperspaceTarget; }
	void SetHyperspaceTarget(const SBodyPath *path);
	void TakeMission(Mission *);
	const std::list<Mission*> &GetMissions() const { return m_missions; }
protected:
	virtual void Save();
	virtual void Load();
private:
	std::list<Mission*> m_missions;
	void DrawTargetSquares();
	void DrawTargetSquare(const Body* const target);
	float m_mouseCMov[2];
	bool polledControlsThisTurn;
	enum FlightControlState m_flightControlState;
	float m_setSpeed;
	SBodyPath m_hyperspaceTarget;
};

#endif /* _PLAYER_H */
