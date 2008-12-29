/*
 *	server/chat/ChatManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef CHATMANAGER_H_
#define CHATMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/Message.h"

#include "../zone/packets/object/StfParameter.h"

class ChatRoom;

class Player;

class CreatureObject;

class ZoneServer;

class ChatManager : public DistributedObjectStub {
public:
	ChatManager(ZoneServer* server, int initPlayers);

	void lock(bool doLock = true);

	void unlock(bool doLock = true);

	void addPlayer(Player* player);

	Player* getPlayer(String& name);

	Player* removePlayer(String& name);

	void sendMail(const String& sendername, UnicodeString& header, UnicodeString& body, const String& name);

	void sendMailBody(Player* receiver, unsigned int mailid);

	void listMail(Player* ply);

	void deleteMail(unsigned int mailid);

	void handleTellMessage(Player* player, Message* pack);

	void handleMessage(Player* player, Message* pack);

	void handleEmote(Player* player, Message* pack);

	void handleMood(Player* player, Message* pack);

	void sendSystemMessage(Player* player, UnicodeString& message);

	void sendSystemMessage(Player* player, const String& file, const String& str, StfParameter* param);

	void broadcastMessage(CreatureObject* player, UnicodeString& message, unsigned long long target = 0, unsigned int moodid = 0, unsigned int mood2 = 0);

	void broadcastMessage(CreatureObject* player, const String& file, const String& str, StfParameter* param, unsigned long long target = 0, unsigned int moodid = 0, unsigned int mood2 = 0);

	void broadcastMessage(const String& message);

	void broadcastMessageRange(Player* player, const String& message, float range);

	void handleGameCommand(Player* player, const String& command);

	void initiateRooms();

	void handleChatRoomMessage(Player* player, Message* pack);

	void handleGroupChat(Player* player, Message* pack);

	void handleGuildChat(Player* player, Message* pack);

	void handleCreateRoom(Player* player, Message* pack);

	void handleChatEnterRoomById(Player* player, Message* pack);

	void handleChatDestroyRoom(Player* player, Message* pack);

	void handleChatRemoveAvatarFromRoom(Player* player, Message* pack);

	ChatRoom* getChatRoom(unsigned int id);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void sendRoomList(Player* player);

	ChatRoom* createGroupRoom(unsigned int groupID, Player* creator);

	void sendGuildChat(Player* player);

	ChatRoom* createRoomByFullPath(const String& path);

	void destroyRoom(ChatRoom* room);

	void printRoomTree(ChatRoom* channel);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getGameRoom(const String& game);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	unsigned int getNextRoomID();

	int getPlayerCount();

	bool isMute();

	void setMute(bool isMuted);

protected:
	ChatManager(DummyConstructorParameter* param);

	virtual ~ChatManager();

	friend class ChatManagerHelper;
};

class ChatManagerImplementation;

class ChatManagerAdapter : public DistributedObjectAdapter {
public:
	ChatManagerAdapter(ChatManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void lock(bool doLock);

	void unlock(bool doLock);

	void addPlayer(Player* player);

	Player* getPlayer(String& name);

	Player* removePlayer(String& name);

	void sendMail(const String& sendername, UnicodeString& header, UnicodeString& body, const String& name);

	void sendMailBody(Player* receiver, unsigned int mailid);

	void listMail(Player* ply);

	void deleteMail(unsigned int mailid);

	void handleTellMessage(Player* player, Message* pack);

	void handleMessage(Player* player, Message* pack);

	void handleEmote(Player* player, Message* pack);

	void handleMood(Player* player, Message* pack);

	void sendSystemMessage(Player* player, UnicodeString& message);

	void sendSystemMessage(Player* player, const String& file, const String& str, StfParameter* param);

	void broadcastMessage(CreatureObject* player, UnicodeString& message, unsigned long long target, unsigned int moodid, unsigned int mood2);

	void broadcastMessage(CreatureObject* player, const String& file, const String& str, StfParameter* param, unsigned long long target, unsigned int moodid, unsigned int mood2);

	void broadcastMessage(const String& message);

	void broadcastMessageRange(Player* player, const String& message, float range);

	void handleGameCommand(Player* player, const String& command);

	void initiateRooms();

	void handleChatRoomMessage(Player* player, Message* pack);

	void handleGroupChat(Player* player, Message* pack);

	void handleGuildChat(Player* player, Message* pack);

	void handleCreateRoom(Player* player, Message* pack);

	void handleChatEnterRoomById(Player* player, Message* pack);

	void handleChatDestroyRoom(Player* player, Message* pack);

	void handleChatRemoveAvatarFromRoom(Player* player, Message* pack);

	ChatRoom* getChatRoom(unsigned int id);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void sendRoomList(Player* player);

	ChatRoom* createGroupRoom(unsigned int groupID, Player* creator);

	void sendGuildChat(Player* player);

	ChatRoom* createRoomByFullPath(const String& path);

	void destroyRoom(ChatRoom* room);

	void printRoomTree(ChatRoom* channel);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getGameRoom(const String& game);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	unsigned int getNextRoomID();

	int getPlayerCount();

	bool isMute();

	void setMute(bool isMuted);

protected:
	String _param0_getPlayer__String_;
	String _param0_removePlayer__String_;
	String _param0_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param1_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param2_sendMail__String_UnicodeString_UnicodeString_String_;
	String _param3_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param1_sendSystemMessage__Player_UnicodeString_;
	String _param1_sendSystemMessage__Player_String_String_StfParameter_;
	String _param2_sendSystemMessage__Player_String_String_StfParameter_;
	UnicodeString _param1_broadcastMessage__CreatureObject_UnicodeString_long_int_int_;
	String _param1_broadcastMessage__CreatureObject_String_String_StfParameter_long_int_int_;
	String _param2_broadcastMessage__CreatureObject_String_String_StfParameter_long_int_int_;
	String _param0_broadcastMessage__String_;
	String _param1_broadcastMessageRange__Player_String_float_;
	String _param1_handleGameCommand__Player_String_;
	String _param0_createRoomByFullPath__String_;
	String _param0_getChatRoomByFullPath__String_;
	String _param0_getGameRoom__String_;
	String _param1_getChatRoomByGamePath__ChatRoom_String_;
};

class ChatManagerHelper : public DistributedObjectClassHelper, public Singleton<ChatManagerHelper> {
	static ChatManagerHelper* staticInitializer;

public:
	ChatManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<ChatManagerHelper>;
};

class ChatManagerServant : public DistributedObjectServant {
public:
	ChatManager* _this;

public:
	ChatManagerServant();
	virtual ~ChatManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*CHATMANAGER_H_*/
