/*
 *	server/zone/objects/building/city/CityHallObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "CityHallObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/region/Region.h"

#include "server/zone/objects/tangible/terminal/city/CityTerminal.h"

#include "server/zone/objects/tangible/terminal/city/CityVoteTerminal.h"

/*
 *	CityHallObjectStub
 */

CityHallObject::CityHallObject() : BuildingObject(DummyConstructorParameter::instance()) {
	CityHallObjectImplementation* _implementation = new CityHallObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

CityHallObject::CityHallObject(DummyConstructorParameter* param) : BuildingObject(param) {
}

CityHallObject::~CityHallObject() {
}


void CityHallObject::insertToZone(Zone* zone) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(zone);

		method.executeWithVoidReturn();
	} else
		_implementation->insertToZone(zone);
}

void CityHallObject::removeFromZone() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		_implementation->removeFromZone();
}

void CityHallObject::spawnCityHallObjects() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		_implementation->spawnCityHallObjects();
}

void CityHallObject::despawnCityHallObjects() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		_implementation->despawnCityHallObjects();
}

void CityHallObject::trySetCityName(PlayerCreature* player, const String& name) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		_implementation->trySetCityName(player, name);
}

bool CityHallObject::checkRequisitesForPlacement(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->checkRequisitesForPlacement(player);
}

void CityHallObject::setCityName(const String& name) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		_implementation->setCityName(name);
}

String CityHallObject::getCityName() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		method.executeWithAsciiReturn(_return_getCityName);
		return _return_getCityName;
	} else
		return _implementation->getCityName();
}

void CityHallObject::sendStatusTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendStatusTo(player);
}

void CityHallObject::sendCitizenshipReportTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendCitizenshipReportTo(player);
}

void CityHallObject::sendStructureReportTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendStructureReportTo(player);
}

void CityHallObject::sendTreasuryReportTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendTreasuryReportTo(player);
}

void CityHallObject::sendChangeCityNameTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendChangeCityNameTo(player);
}

void CityHallObject::sendManageMilitiaTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendManageMilitiaTo(player);
}

void CityHallObject::sendAdjustTaxesTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendAdjustTaxesTo(player);
}

void CityHallObject::sendTreasuryDepositTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendTreasuryDepositTo(player);
}

void CityHallObject::sendTreasuryWithdrawalTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendTreasuryWithdrawalTo(player);
}

void CityHallObject::sendCitySpecializationSelectionTo(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendCitySpecializationSelectionTo(player);
}

void CityHallObject::toggleCityRegistration() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		method.executeWithVoidReturn();
	} else
		_implementation->toggleCityRegistration();
}

int CityHallObject::notifyStructurePlaced(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyStructurePlaced(player);
}

bool CityHallObject::isCityHallBuilding() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCityHallBuilding();
}

void CityHallObject::declareCitizenship(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->declareCitizenship(player);
}

void CityHallObject::declareCitizenship(unsigned long long playerID) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->declareCitizenship(playerID);
}

void CityHallObject::revokeCitizenship(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->revokeCitizenship(player);
}

void CityHallObject::revokeCitizenship(unsigned long long playerID) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->revokeCitizenship(playerID);
}

void CityHallObject::addZoningRights(unsigned long long playerID, unsigned int seconds) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addUnsignedLongParameter(playerID);
		method.addUnsignedIntParameter(seconds);

		method.executeWithVoidReturn();
	} else
		_implementation->addZoningRights(playerID, seconds);
}

void CityHallObject::removeZoningRights(unsigned long long playerID) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->removeZoningRights(playerID);
}

bool CityHallObject::hasZoningRights(unsigned long long playerID) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasZoningRights(playerID);
}

unsigned long long CityHallObject::getMayorObjectID() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getMayorObjectID();
}

void CityHallObject::setMayorObjectID(unsigned long long oid) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);
		method.addUnsignedLongParameter(oid);

		method.executeWithVoidReturn();
	} else
		_implementation->setMayorObjectID(oid);
}

bool CityHallObject::isMayorOf(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 36);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isMayorOf(player);
}

bool CityHallObject::isMayorOf(unsigned long long playerID) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 37);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isMayorOf(playerID);
}

bool CityHallObject::isCitizenOf(PlayerCreature* player) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 38);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCitizenOf(player);
}

bool CityHallObject::isCitizenOf(unsigned long long playerID) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 39);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCitizenOf(playerID);
}

CityTerminal* CityHallObject::getCityTerminal() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 40);

		return (CityTerminal*) method.executeWithObjectReturn();
	} else
		return _implementation->getCityTerminal();
}

CityVoteTerminal* CityHallObject::getCityVoteTerminal() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 41);

		return (CityVoteTerminal*) method.executeWithObjectReturn();
	} else
		return _implementation->getCityVoteTerminal();
}

Region* CityHallObject::getCityRegion() {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 42);

		return (Region*) method.executeWithObjectReturn();
	} else
		return _implementation->getCityRegion();
}

void CityHallObject::setCityRegion(Region* region) {
	CityHallObjectImplementation* _implementation = (CityHallObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 43);
		method.addObjectParameter(region);

		method.executeWithVoidReturn();
	} else
		_implementation->setCityRegion(region);
}

DistributedObjectServant* CityHallObject::_getImplementation() {
	return _impl;}

void CityHallObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	CityHallObjectImplementation
 */

CityHallObjectImplementation::CityHallObjectImplementation(DummyConstructorParameter* param) : BuildingObjectImplementation(param) {
	_initializeImplementation();
}


CityHallObjectImplementation::~CityHallObjectImplementation() {
}


void CityHallObjectImplementation::finalize() {
}

void CityHallObjectImplementation::_initializeImplementation() {
	_setClassHelper(CityHallObjectHelper::instance());

	_serializationHelperMethod();
}

void CityHallObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CityHallObject*) stub;
	BuildingObjectImplementation::_setStub(stub);
}

DistributedObjectStub* CityHallObjectImplementation::_getStub() {
	return _this;
}

CityHallObjectImplementation::operator const CityHallObject*() {
	return _this;
}

void CityHallObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void CityHallObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void CityHallObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void CityHallObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void CityHallObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void CityHallObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void CityHallObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void CityHallObjectImplementation::_serializationHelperMethod() {
	BuildingObjectImplementation::_serializationHelperMethod();

	_setClassName("CityHallObject");

	addSerializableVariable("declaredCitizens", &declaredCitizens);
	addSerializableVariable("playerZoningRights", &playerZoningRights);
	addSerializableVariable("cityRegion", &cityRegion);
	addSerializableVariable("cityName", &cityName);
	addSerializableVariable("mayorObjectID", &mayorObjectID);
	addSerializableVariable("cityTerminal", &cityTerminal);
	addSerializableVariable("cityVoteTerminal", &cityVoteTerminal);
}

CityHallObjectImplementation::CityHallObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/building/city/CityHallObject.idl(73):  		setLoggingName("CityHallObject");
	setLoggingName("CityHallObject");
	// server/zone/objects/building/city/CityHallObject.idl(75):  		cityName = "test city";
	cityName = "test city";
	// server/zone/objects/building/city/CityHallObject.idl(77):  		mayorObjectID = 0;
	mayorObjectID = 0;
	// server/zone/objects/building/city/CityHallObject.idl(79):  		playerZoningRights.setInsertPlan(3);
	(&playerZoningRights)->setInsertPlan(3);
	// server/zone/objects/building/city/CityHallObject.idl(80):  		playerZoningRights.setNullValue(0);
	(&playerZoningRights)->setNullValue(0);
}

void CityHallObjectImplementation::insertToZone(Zone* zone) {
	// server/zone/objects/building/city/CityHallObject.idl(90):  		super.insertToZone(zone);
	BuildingObjectImplementation::insertToZone(zone);
	// server/zone/objects/building/city/CityHallObject.idl(92):  		spawnCityHallObjects();
	spawnCityHallObjects();
}

void CityHallObjectImplementation::removeFromZone() {
	// server/zone/objects/building/city/CityHallObject.idl(96):  		despawnCityHallObjects();
	despawnCityHallObjects();
	// server/zone/objects/building/city/CityHallObject.idl(98):  		super.removeFromZone();
	BuildingObjectImplementation::removeFromZone();
	// server/zone/objects/building/city/CityHallObject.idl(100):  		updateToDatabaseWithoutChildren();
	updateToDatabaseWithoutChildren();
}

void CityHallObjectImplementation::setCityName(const String& name) {
	// server/zone/objects/building/city/CityHallObject.idl(111):  		cityName = name;
	cityName = name;
}

String CityHallObjectImplementation::getCityName() {
	// server/zone/objects/building/city/CityHallObject.idl(115):  		return cityName;
	return cityName;
}

bool CityHallObjectImplementation::isCityHallBuilding() {
	// server/zone/objects/building/city/CityHallObject.idl(138):  		return true;
	return true;
}

void CityHallObjectImplementation::declareCitizenship(PlayerCreature* player) {
	// server/zone/objects/building/city/CityHallObject.idl(146):  		declaredCitizens.put(player.getObjectID());
	(&declaredCitizens)->put(player->getObjectID());
}

void CityHallObjectImplementation::declareCitizenship(unsigned long long playerID) {
	// server/zone/objects/building/city/CityHallObject.idl(154):  		declaredCitizens.put(playerID);
	(&declaredCitizens)->put(playerID);
}

void CityHallObjectImplementation::revokeCitizenship(PlayerCreature* player) {
	// server/zone/objects/building/city/CityHallObject.idl(162):  		declaredCitizens.drop(player.getObjectID());
	(&declaredCitizens)->drop(player->getObjectID());
}

void CityHallObjectImplementation::revokeCitizenship(unsigned long long playerID) {
	// server/zone/objects/building/city/CityHallObject.idl(170):  		declaredCitizens.drop(playerID);
	(&declaredCitizens)->drop(playerID);
}

void CityHallObjectImplementation::removeZoningRights(unsigned long long playerID) {
	// server/zone/objects/building/city/CityHallObject.idl(185):  		playerZoningRights.drop(playerID);
	(&playerZoningRights)->drop(playerID);
}

unsigned long long CityHallObjectImplementation::getMayorObjectID() {
	// server/zone/objects/building/city/CityHallObject.idl(195):  		return mayorObjectID;
	return mayorObjectID;
}

void CityHallObjectImplementation::setMayorObjectID(unsigned long long oid) {
	// server/zone/objects/building/city/CityHallObject.idl(199):  		mayorObjectID = oid;
	mayorObjectID = oid;
}

bool CityHallObjectImplementation::isMayorOf(PlayerCreature* player) {
	// server/zone/objects/building/city/CityHallObject.idl(203):  		return player.getObjectID() == mayorObjectID;
	return player->getObjectID() == mayorObjectID;
}

bool CityHallObjectImplementation::isMayorOf(unsigned long long playerID) {
	// server/zone/objects/building/city/CityHallObject.idl(207):  		return playerID == mayorObjectID;
	return playerID == mayorObjectID;
}

bool CityHallObjectImplementation::isCitizenOf(PlayerCreature* player) {
	// server/zone/objects/building/city/CityHallObject.idl(211):  		return declaredCitizens.contains(player.getObjectID());
	return (&declaredCitizens)->contains(player->getObjectID());
}

bool CityHallObjectImplementation::isCitizenOf(unsigned long long playerID) {
	// server/zone/objects/building/city/CityHallObject.idl(215):  		return declaredCitizens.contains(playerID);
	return (&declaredCitizens)->contains(playerID);
}

CityTerminal* CityHallObjectImplementation::getCityTerminal() {
	// server/zone/objects/building/city/CityHallObject.idl(219):  		return cityTerminal;
	return cityTerminal;
}

CityVoteTerminal* CityHallObjectImplementation::getCityVoteTerminal() {
	// server/zone/objects/building/city/CityHallObject.idl(223):  		return cityVoteTerminal;
	return cityVoteTerminal;
}

Region* CityHallObjectImplementation::getCityRegion() {
	// server/zone/objects/building/city/CityHallObject.idl(227):  		return cityRegion;
	return cityRegion;
}

void CityHallObjectImplementation::setCityRegion(Region* region) {
	// server/zone/objects/building/city/CityHallObject.idl(231):  		cityRegion = region;
	cityRegion = region;
}

/*
 *	CityHallObjectAdapter
 */

CityHallObjectAdapter::CityHallObjectAdapter(CityHallObjectImplementation* obj) : BuildingObjectAdapter(obj) {
}

Packet* CityHallObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		insertToZone((Zone*) inv->getObjectParameter());
		break;
	case 7:
		removeFromZone();
		break;
	case 8:
		spawnCityHallObjects();
		break;
	case 9:
		despawnCityHallObjects();
		break;
	case 10:
		trySetCityName((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_trySetCityName__PlayerCreature_String_));
		break;
	case 11:
		resp->insertBoolean(checkRequisitesForPlacement((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 12:
		setCityName(inv->getAsciiParameter(_param0_setCityName__String_));
		break;
	case 13:
		resp->insertAscii(getCityName());
		break;
	case 14:
		sendStatusTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 15:
		sendCitizenshipReportTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 16:
		sendStructureReportTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 17:
		sendTreasuryReportTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 18:
		sendChangeCityNameTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 19:
		sendManageMilitiaTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 20:
		sendAdjustTaxesTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 21:
		sendTreasuryDepositTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 22:
		sendTreasuryWithdrawalTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 23:
		sendCitySpecializationSelectionTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 24:
		toggleCityRegistration();
		break;
	case 25:
		resp->insertSignedInt(notifyStructurePlaced((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 26:
		resp->insertBoolean(isCityHallBuilding());
		break;
	case 27:
		declareCitizenship((PlayerCreature*) inv->getObjectParameter());
		break;
	case 28:
		declareCitizenship(inv->getUnsignedLongParameter());
		break;
	case 29:
		revokeCitizenship((PlayerCreature*) inv->getObjectParameter());
		break;
	case 30:
		revokeCitizenship(inv->getUnsignedLongParameter());
		break;
	case 31:
		addZoningRights(inv->getUnsignedLongParameter(), inv->getUnsignedIntParameter());
		break;
	case 32:
		removeZoningRights(inv->getUnsignedLongParameter());
		break;
	case 33:
		resp->insertBoolean(hasZoningRights(inv->getUnsignedLongParameter()));
		break;
	case 34:
		resp->insertLong(getMayorObjectID());
		break;
	case 35:
		setMayorObjectID(inv->getUnsignedLongParameter());
		break;
	case 36:
		resp->insertBoolean(isMayorOf((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 37:
		resp->insertBoolean(isMayorOf(inv->getUnsignedLongParameter()));
		break;
	case 38:
		resp->insertBoolean(isCitizenOf((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 39:
		resp->insertBoolean(isCitizenOf(inv->getUnsignedLongParameter()));
		break;
	case 40:
		resp->insertLong(getCityTerminal()->_getObjectID());
		break;
	case 41:
		resp->insertLong(getCityVoteTerminal()->_getObjectID());
		break;
	case 42:
		resp->insertLong(getCityRegion()->_getObjectID());
		break;
	case 43:
		setCityRegion((Region*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CityHallObjectAdapter::insertToZone(Zone* zone) {
	((CityHallObjectImplementation*) impl)->insertToZone(zone);
}

void CityHallObjectAdapter::removeFromZone() {
	((CityHallObjectImplementation*) impl)->removeFromZone();
}

void CityHallObjectAdapter::spawnCityHallObjects() {
	((CityHallObjectImplementation*) impl)->spawnCityHallObjects();
}

void CityHallObjectAdapter::despawnCityHallObjects() {
	((CityHallObjectImplementation*) impl)->despawnCityHallObjects();
}

void CityHallObjectAdapter::trySetCityName(PlayerCreature* player, const String& name) {
	((CityHallObjectImplementation*) impl)->trySetCityName(player, name);
}

bool CityHallObjectAdapter::checkRequisitesForPlacement(PlayerCreature* player) {
	return ((CityHallObjectImplementation*) impl)->checkRequisitesForPlacement(player);
}

void CityHallObjectAdapter::setCityName(const String& name) {
	((CityHallObjectImplementation*) impl)->setCityName(name);
}

String CityHallObjectAdapter::getCityName() {
	return ((CityHallObjectImplementation*) impl)->getCityName();
}

void CityHallObjectAdapter::sendStatusTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendStatusTo(player);
}

void CityHallObjectAdapter::sendCitizenshipReportTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendCitizenshipReportTo(player);
}

void CityHallObjectAdapter::sendStructureReportTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendStructureReportTo(player);
}

void CityHallObjectAdapter::sendTreasuryReportTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendTreasuryReportTo(player);
}

void CityHallObjectAdapter::sendChangeCityNameTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendChangeCityNameTo(player);
}

void CityHallObjectAdapter::sendManageMilitiaTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendManageMilitiaTo(player);
}

void CityHallObjectAdapter::sendAdjustTaxesTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendAdjustTaxesTo(player);
}

void CityHallObjectAdapter::sendTreasuryDepositTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendTreasuryDepositTo(player);
}

void CityHallObjectAdapter::sendTreasuryWithdrawalTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendTreasuryWithdrawalTo(player);
}

void CityHallObjectAdapter::sendCitySpecializationSelectionTo(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->sendCitySpecializationSelectionTo(player);
}

void CityHallObjectAdapter::toggleCityRegistration() {
	((CityHallObjectImplementation*) impl)->toggleCityRegistration();
}

int CityHallObjectAdapter::notifyStructurePlaced(PlayerCreature* player) {
	return ((CityHallObjectImplementation*) impl)->notifyStructurePlaced(player);
}

bool CityHallObjectAdapter::isCityHallBuilding() {
	return ((CityHallObjectImplementation*) impl)->isCityHallBuilding();
}

void CityHallObjectAdapter::declareCitizenship(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->declareCitizenship(player);
}

void CityHallObjectAdapter::declareCitizenship(unsigned long long playerID) {
	((CityHallObjectImplementation*) impl)->declareCitizenship(playerID);
}

void CityHallObjectAdapter::revokeCitizenship(PlayerCreature* player) {
	((CityHallObjectImplementation*) impl)->revokeCitizenship(player);
}

void CityHallObjectAdapter::revokeCitizenship(unsigned long long playerID) {
	((CityHallObjectImplementation*) impl)->revokeCitizenship(playerID);
}

void CityHallObjectAdapter::addZoningRights(unsigned long long playerID, unsigned int seconds) {
	((CityHallObjectImplementation*) impl)->addZoningRights(playerID, seconds);
}

void CityHallObjectAdapter::removeZoningRights(unsigned long long playerID) {
	((CityHallObjectImplementation*) impl)->removeZoningRights(playerID);
}

bool CityHallObjectAdapter::hasZoningRights(unsigned long long playerID) {
	return ((CityHallObjectImplementation*) impl)->hasZoningRights(playerID);
}

unsigned long long CityHallObjectAdapter::getMayorObjectID() {
	return ((CityHallObjectImplementation*) impl)->getMayorObjectID();
}

void CityHallObjectAdapter::setMayorObjectID(unsigned long long oid) {
	((CityHallObjectImplementation*) impl)->setMayorObjectID(oid);
}

bool CityHallObjectAdapter::isMayorOf(PlayerCreature* player) {
	return ((CityHallObjectImplementation*) impl)->isMayorOf(player);
}

bool CityHallObjectAdapter::isMayorOf(unsigned long long playerID) {
	return ((CityHallObjectImplementation*) impl)->isMayorOf(playerID);
}

bool CityHallObjectAdapter::isCitizenOf(PlayerCreature* player) {
	return ((CityHallObjectImplementation*) impl)->isCitizenOf(player);
}

bool CityHallObjectAdapter::isCitizenOf(unsigned long long playerID) {
	return ((CityHallObjectImplementation*) impl)->isCitizenOf(playerID);
}

CityTerminal* CityHallObjectAdapter::getCityTerminal() {
	return ((CityHallObjectImplementation*) impl)->getCityTerminal();
}

CityVoteTerminal* CityHallObjectAdapter::getCityVoteTerminal() {
	return ((CityHallObjectImplementation*) impl)->getCityVoteTerminal();
}

Region* CityHallObjectAdapter::getCityRegion() {
	return ((CityHallObjectImplementation*) impl)->getCityRegion();
}

void CityHallObjectAdapter::setCityRegion(Region* region) {
	((CityHallObjectImplementation*) impl)->setCityRegion(region);
}

/*
 *	CityHallObjectHelper
 */

CityHallObjectHelper* CityHallObjectHelper::staticInitializer = CityHallObjectHelper::instance();

CityHallObjectHelper::CityHallObjectHelper() {
	className = "CityHallObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CityHallObjectHelper::finalizeHelper() {
	CityHallObjectHelper::finalize();
}

DistributedObject* CityHallObjectHelper::instantiateObject() {
	return new CityHallObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* CityHallObjectHelper::instantiateServant() {
	return new CityHallObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CityHallObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CityHallObjectAdapter((CityHallObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

