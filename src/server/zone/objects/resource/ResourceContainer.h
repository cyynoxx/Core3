/*
 *	server/zone/objects/resource/ResourceContainer.h generated by engine3 IDL compiler 0.60
 */

#ifndef RESOURCECONTAINER_H_
#define RESOURCECONTAINER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "server/zone/objects/resource/ResourceSpawn.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "engine/log/Logger.h"

#include "system/util/VectorMap.h"

#include "system/util/Vector.h"

#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace resource {

class ResourceContainer : public TangibleObject {
public:
	static const int MAXSIZE = 100000;

	ResourceContainer();

	void initializeTransientMembers();

	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void sendBaselinesTo(SceneObject* player);

	void setQuantity(int quantity);

	bool isResourceContainer();

	int getQuantity();

	void setSpawnObject(ResourceSpawn* spawn);

	String getSpawnName();

	String getSpawnType();

	unsigned long long getSpawnID();

	ResourceSpawn* getSpawnObject();

	void split(int newStackSize);

	void combine(ResourceContainer* fromContainer);

protected:
	ResourceContainer(DummyConstructorParameter* param);

	virtual ~ResourceContainer();

	String _return_getSpawnName;
	String _return_getSpawnType;

	friend class ResourceContainerHelper;
};

} // namespace resource
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::resource;

namespace server {
namespace zone {
namespace objects {
namespace resource {

class ResourceContainerImplementation : public TangibleObjectImplementation {
protected:
	ManagedReference<ResourceSpawn* > spawnObject;

	int stackQuantity;

public:
	static const int MAXSIZE = 100000;

	ResourceContainerImplementation();

	ResourceContainerImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void sendBaselinesTo(SceneObject* player);

	void setQuantity(int quantity);

	bool isResourceContainer();

	int getQuantity();

	void setSpawnObject(ResourceSpawn* spawn);

	String getSpawnName();

	String getSpawnType();

	unsigned long long getSpawnID();

	ResourceSpawn* getSpawnObject();

	void split(int newStackSize);

	void combine(ResourceContainer* fromContainer);

	ResourceContainer* _this;

	operator const ResourceContainer*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~ResourceContainerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class ResourceContainer;
};

class ResourceContainerAdapter : public TangibleObjectAdapter {
public:
	ResourceContainerAdapter(ResourceContainerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void destroyObjectFromDatabase(bool destroyContainedObjects);

	void sendBaselinesTo(SceneObject* player);

	void setQuantity(int quantity);

	bool isResourceContainer();

	int getQuantity();

	void setSpawnObject(ResourceSpawn* spawn);

	String getSpawnName();

	String getSpawnType();

	unsigned long long getSpawnID();

	ResourceSpawn* getSpawnObject();

	void split(int newStackSize);

	void combine(ResourceContainer* fromContainer);

};

class ResourceContainerHelper : public DistributedObjectClassHelper, public Singleton<ResourceContainerHelper> {
	static ResourceContainerHelper* staticInitializer;

public:
	ResourceContainerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ResourceContainerHelper>;
};

} // namespace resource
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::resource;

#endif /*RESOURCECONTAINER_H_*/
