/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef ATTACKTARGETSKILL_H_
#define ATTACKTARGETSKILL_H_

#include "../TargetSkill.h"
#include "../PassiveSkill.h"
#include "../../../tangible/wearables/Armor.h"

#include "../../../../packets/object/ShowFlyText.h"

class CombatManager;

class AttackTargetSkill : public TargetSkill {
protected:
	float damageRatio;
	float healthCostMultiplier;
	float actionCostMultiplier;
	float mindCostMultiplier;
	float forceCostMultiplier;

	int healthPoolAttackChance;
	int strengthPoolAttackChance;
	int constitutionPoolAttackChance;

	int actionPoolAttackChance;
	int quicknessPoolAttackChance;
	int staminaPoolAttackChance;

	int mindPoolAttackChance;
	int focusPoolAttackChance;
	int willpowerPoolAttackChance;

	int areaRangeDamage;

	int accuracyBonus;

	bool hasStateChance;

	int knockdownStateChance;
	int postureDownStateChance;
	int postureUpStateChance;

	int dizzyStateChance;
	int blindStateChance;
	int stunStateChance;
	int intimidateStateChance;

	int requiredWeaponType;
	int skillType;

	int forceCost;

	String cbtSpamBlock;
	String cbtSpamCounter;
	String cbtSpamEvade;
	String cbtSpamHit;
	String cbtSpamMiss;

public:
	static const int DEBUFF = 1;
	static const int DIRECT = 2;
	static const int DOT = 3;
	static const int FORCE = 4;
	static const int RANDOM = 5;
	static const int WEAPONLESS = 6;
	static const int WOUNDS = 7;
	static const int OTHER = 0;

public:
	AttackTargetSkill(const String& name, const String& anim, int tp, ZoneProcessServerImplementation* serv) : TargetSkill(name, anim, ATTACK, serv) {
		healthPoolAttackChance = 0;
		strengthPoolAttackChance = 0;
		constitutionPoolAttackChance = 0;

		actionPoolAttackChance = 0;
		quicknessPoolAttackChance = 0;
		staminaPoolAttackChance = 0;

		mindPoolAttackChance = 0;
		focusPoolAttackChance = 0;
		willpowerPoolAttackChance = 0;

		damageRatio = 1.0f;

		forceCost = 0;

		healthCostMultiplier = 1;
		actionCostMultiplier = 1;
		mindCostMultiplier = 1;
		forceCostMultiplier = 0;

		areaRangeDamage = 0;

		accuracyBonus = 0;

		hasStateChance = false;

		knockdownStateChance = 0;
		postureDownStateChance = 0;
		postureUpStateChance = 0;
		dizzyStateChance = 0;
		blindStateChance = 0;
		stunStateChance = 0;
		intimidateStateChance = 0;

		requiredWeaponType = 0xFF; // NONE
		skillType = tp;
	}


	virtual int calculateDamage(CreatureObject* creature, SceneObject* target) = 0;

	virtual bool calculateCost(CreatureObject* creature) {
		return server->getCombatManager()->calculateCost(creature, healthCostMultiplier, actionCostMultiplier, mindCostMultiplier, forceCostMultiplier);
	}

	void doAnimations(CreatureObject* creature, SceneObject* target, bool doAnimations = true) {
	}

	void doMiss(CreatureObject* creature, CreatureObject* target, int32 damage) {
		if (hasCbtSpamMiss())
			creature->sendCombatSpam(target, NULL, -(int32)damage, getCbtSpamMiss());

		target->showFlyText("combat_effects", "miss", 0xFF, 0xFF, 0xFF);
	}

	void calculateStates(CreatureObject* creature, CreatureObject* targetCreature) {
		if (hasStateChance)
			server->getCombatManager()->calculateStates(creature, targetCreature, this);
	}

	void calculateDamageReduction(CreatureObject* creature, CreatureObject* targetCreature, float& damage) {
		// TODO: reintroduce for later testing
		//server->getCombatManager()->calculateDamageReduction(creature, targetCreature, damage);
	}

	void checkMitigation(CreatureObject* creature, CreatureObject* targetCreature, float& minDamage, float& maxDamage) {
		// TODO: reintroduce for later testing
		//server->getCombatManager()->checkMitigation(creature, targetCreature, minDamage, maxDamage);
	}

	void doDodge(CreatureObject* creature, CreatureObject* defender) {
		server->getCombatManager()->doDodge(creature, defender);
	}

	void doCounterAttack(CreatureObject* creature, CreatureObject* defender) {
		server->getCombatManager()->doCounterAttack(creature, defender);
	}

	void doBlock(CreatureObject* creature, CreatureObject* defender) {
		server->getCombatManager()->doBlock(creature, defender);
	}

	int checkSecondaryDefenses(CreatureObject* creature, CreatureObject* targetCreature) {
		// TODO: reintroduce for later testing
		//return server->getCombatManager()->checkSecondaryDefenses(creature, targetCreature);
		return 0;
	}

	virtual inline int getHitChance(CreatureObject* creature, CreatureObject* targetCreature) {
		return server->getCombatManager()->getHitChance(creature, targetCreature, accuracyBonus);
	}

	virtual inline float getSpeed() {
		return 1.0f;
	}

	float getTargetDefense(CreatureObject* creature, CreatureObject* targetCreature, Weapon* weapon) {
		return server->getCombatManager()->getTargetDefense(creature, targetCreature, weapon);
	}

	int applyDamage(CreatureObject* attacker, CreatureObject* target, int32 damage, int part) {
		return server->getCombatManager()->applyDamage(attacker, target, damage, part, this);
	}

	void doDotWeaponAttack(CreatureObject* creature, CreatureObject* targetCreature, bool areaHit) {
		server->getCombatManager()->doDotWeaponAttack(creature, targetCreature, areaHit);
	}

	// The following function adjusts incoming damage for Armor Piercing and Armor Rating.
	// The Values are:
	// @@ Armor* armor  -- Armor of the Defender
	// @@ Weapon* weapon -- Weapon of the Attacker
	// @@ int damage -- initial incoming damage
	// @@ bool isresisted -- To decide if the Benefit of AP/AR should be applied, IE. if Damage is stun, and armor has no stun resistance, you would not reduce damage by 50%, however you could still recieve the 25% inrease in damage from a Peircing weapon
	// ## Returns - apar damage reduction.
	int doArmorAPARReductions(Armor* armor, Weapon* weapon, int damage, bool isresisted = false)
	{
		int ap = 0;
		int ar = 0;
		int APARreduction = 0;

		if (weapon != NULL)
			ap = weapon->getArmorPiercing();
		if (armor != NULL)
			ar = armor->getRating() / 16; // this sucks, why are they stored differently?


		if (ap > ar)
			APARreduction = (damage - (int)(damage * powf(1.25f, ap - ar))); // If armor piercing is greater, increase by 25% per level

		if (ap < ar && isresisted)  // If damage type was resisted, and If armor rating is greater, decrease by half per level
			APARreduction = (damage - (int)(damage * powf(0.5f, ar - ap)));

		return APARreduction;
	}

	int doArmorResists(Armor* armor, Weapon* weapon, int dmg)
	{


		float resist = 0;

		int damageType = WeaponImplementation::KINETIC;

		if (weapon != NULL)
			damageType = weapon->getDamageType();

		if (armor != NULL)
			switch (damageType) {
			case WeaponImplementation::KINETIC:
				resist = armor->getKinetic();
				break;
			case WeaponImplementation::ENERGY:
				resist = armor->getEnergy();
				break;
			case WeaponImplementation::ELECTRICITY:
				resist = armor->getElectricity();
				break;
			case WeaponImplementation::STUN:
				resist = armor->getStun();
				break;
			case WeaponImplementation::BLAST:
				resist = armor->getBlast();
				break;
			case WeaponImplementation::HEAT:
				resist = armor->getHeat();
				break;
			case WeaponImplementation::COLD:
				resist = armor->getCold();
				break;
			case WeaponImplementation::ACID:
				resist = armor->getAcid();
				break;
			case WeaponImplementation::LIGHTSABER:
				resist = armor->getLightSaber();
				break;
			case WeaponImplementation::FORCE:
				resist = 0;
				break;
			}

		if (resist == 0)
			return 0;
		else
			return (int)(dmg * (resist / 100));

	}

	bool isArea() {
		if (areaRangeDamage != 0) {
			return true;
		} else
			return isConeSkill;
	}

	bool isCone() {
		return false;
	}

	bool isForce() {
		return forceCost > 0;
	}

	inline void setDamageRatio(float ratio) {
		damageRatio = ratio;
	}

	inline void setHealthCostMultiplier(float mult) {
		healthCostMultiplier = mult;
	}

	inline void setActionCostMultiplier(float mult) {
		actionCostMultiplier = mult;
	}

	inline void setMindCostMultiplier(float mult) {
		mindCostMultiplier = mult;
	}

	inline void setForceCostMultiplier(float mult) {
		forceCostMultiplier = mult;
	}

	inline void setHealthPoolAttackRatio(int ratio) {
		healthPoolAttackChance = ratio;
	}

	inline void setStrengthPoolAttackRatio(int ratio) {
		strengthPoolAttackChance = ratio;
	}

	inline void setConstitutionPoolAttackRatio(int ratio) {
		constitutionPoolAttackChance = ratio;
	}

	inline void setActionPoolAttackRatio(int ratio) {
		actionPoolAttackChance = ratio;
	}

	inline void setQuicknessPoolAttackRatio(int ratio) {
		quicknessPoolAttackChance = ratio;
	}

	inline void setStaminaPoolAttackRatio(int ratio) {
		staminaPoolAttackChance = ratio;
	}

	inline void setMindPoolAttackRatio(int ratio) {
		mindPoolAttackChance = ratio;
	}

	inline void setFocusPoolAttackRatio(int ratio) {
		focusPoolAttackChance = ratio;
	}

	inline void setWillpowerPoolAttackRatio(int ratio) {
		willpowerPoolAttackChance = ratio;
	}

	inline void setKnockdownChance(int chance) {
		knockdownStateChance = chance;
		hasStateChance = true;
	}

	inline int getKnockdownChance(){
		return knockdownStateChance;
	}

	inline void setPostureDownChance (int chance) {
		postureDownStateChance = chance;
		hasStateChance = true;
	}

	inline int getPostureDownChance() {
		return postureDownStateChance;
	}

	inline void setPostureUpChance (int chance) {
		postureUpStateChance = chance;
		hasStateChance = true;
	}

	inline int getPostureUpChance() {
		return postureUpStateChance;
	}

	inline void setDizzyChance(int chance) {
		dizzyStateChance = chance;
		hasStateChance = true;
	}

	inline int getDizzyChance() {
		return dizzyStateChance;
	}

	inline void setBlindChance(int chance) {
		blindStateChance = chance;
		hasStateChance = true;
	}

	inline int getBlindChance() {
		return blindStateChance;
	}

	inline void setStunChance(int chance) {
		stunStateChance = chance;
		hasStateChance = true;
	}

	inline int getStunChance() {
		return stunStateChance;
	}

	inline void setIntimidateChance(int chance) {
		intimidateStateChance = chance;
		hasStateChance = true;
	}

	inline int getIntimidateChance() {
		return intimidateStateChance;
	}

	inline void setAreaRangeDamage(int area) {
		areaRangeDamage = area;
	}

	void setCbtSpamBlock(const String& ename) {
		cbtSpamBlock = ename;
	}

	void setCbtSpamCounter(const String& ename) {
		cbtSpamCounter = ename;
	}

	void setCbtSpamEvade(const String& ename) {
		cbtSpamEvade = ename;
	}

	void setCbtSpamHit(const String& ename) {
		cbtSpamHit = ename;
	}

	void setCbtSpamMiss(const String& ename) {
		cbtSpamMiss = ename;
	}

	void setRequiredWeaponType(int wea) {
		requiredWeaponType = wea;
	}

	void setAccuracyBonus(int acc) {
		accuracyBonus = acc;
	}

	bool hasCbtSpamBlock() {
		return cbtSpamBlock.length() != 0;
	}

	bool hasCbtSpamCounter() {
		return cbtSpamCounter.length() != 0;
	}

	bool hasCbtSpamEvade() {
		return cbtSpamEvade.length() != 0;
	}

	bool hasCbtSpamHit() {
		return cbtSpamHit.length() != 0;
	}

	bool hasCbtSpamMiss() {
		return cbtSpamMiss.length() != 0;
	}

	inline String& getCbtSpamBlock() {
		return cbtSpamBlock;
	}

	inline String& getCbtSpamCounter() {
		return cbtSpamCounter;
	}

	inline String& getCbtSpamEvade() {
		return cbtSpamEvade;
	}

	inline String& getCbtSpamHit() {
		return cbtSpamHit;
	}

	inline String& getCbtSpamMiss() {
		return cbtSpamMiss;
	}

	inline int getAreaRange() {
		return areaRangeDamage;
	}

	inline int getRequiredWeaponType() {
		return requiredWeaponType;
	}

	int getSkillType() {
		return skillType;
	}

	inline int getAccuracyBonus() {
		return accuracyBonus;
	}

	virtual float calculateSpeed(CreatureObject* creature) {
		return server->getCombatManager()->calculateWeaponAttackSpeed(creature, this);
	}

	friend class CombatManager;

};

#endif /*ATTACKTARGETSKILL_H_*/
