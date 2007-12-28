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

#include "objects.h"
#include "packets.h"

#include "ZoneServer.h"

#include "ZoneClientImplementation.h"
#include "ZoneProcessServerImplementation.h"

#include "Zone.h"

#include "managers/player/PlayerManager.h"
#include "managers/item/ItemManager.h"
#include "managers/radial/RadialManager.h"
#include "managers/planet/PlanetManager.h"

#include "objects/terrain/PlanetNames.h"

#include "../chat/ChatManager.h"

#include "ZonePacketHandler.h"

ZonePacketHandler::ZonePacketHandler(const string& s, ZoneProcessServerImplementation* serv) : Logger(s) {
		processServer = serv;
		
		server = processServer->getZoneServer();
} 

void ZonePacketHandler::handleMessage(Message* pack) {
	//info("parsing " + pack->toString());
	
	uint16 opcount = pack->parseShort();
	uint32 opcode = pack->parseInt();
	
	switch (opcount) {
	case 1:
		switch (opcode) {
		case 0x43FD1C22: //CmdSceneReady Zone done loading.
			handleCmdSceneReady(pack);
			break;
		case 0xC1B03B81: //FactionRequestMessage
			handleFactionRequestMessage(pack);
			break;
		case 0xB75DD5D7: //StomachRequestMessage
		    handleStomachRequestMessage(pack);
		    break;
		case 0x9D105AA1: //PlayerMoneyRequest
		    handlePlayerMoneyRequest(pack);
		    break;
		case 0x4C3D2CFA: //ChatRequestRoomList
			handleChatRequestRoomList(pack);
			break;
		}
		
		break;
	case 2:
		switch (opcode) {
		case 0xB5098D76: //SelectCharacter Request/zone insert.
			handleSelectCharacter(pack);
			break;
		case 0x8F251641: //ChatDeletePersistentMessage
			handleDeletePersistentMsg(pack);
			break;
		case 0x81EB4EF7: //GuildRequestMessage
		    handleGuildRequestMessage(pack);
		    break;
		}
		
		break;
	case 3:
		switch (opcode) {
		case 0xD5899226:
			handleClientPermissionsMessage(pack);
			break;
		case 0x07E3559F:
			handleRequestPersistentMsg(pack);
			break;
		case 0x7CA18726:
			handleRadialSelect(pack);
		    break;
		case 0x96405D4D: //Travel Points list
		    handleTravelListRequest(pack);
		    break;
		case 0xBC6BDDF2: // ChatEnterRoomById
			handleChatEnterRoomById(pack);
			break;
		case 0x94B2A77: // ChatDestroyRoom
			handleChatDestroyRoom(pack);
			break;
		case 0x493E3FFA: //  ChatRemoveAvatarFromRoom
			handleChatRemoveAvatarFromRoom(pack);
			break;
		}
		
		break;
	case 04:
		switch (opcode) {
		case 0x092D3564: // Selection box return
			handleSuiEventNotification(pack);
			break;
		}
		break;
	case 05:
		switch (opcode) {
		case 0x80CE5E46:
			handleObjectControllerMessage(pack);
			break;
		case 0x84BB21F7:
			handleTellMessage(pack);
			break;
		case 0xD6D1B6D1: //ClientRandomNameRequest
			handleClientRandomNameRequest(pack);
			break;
		case 0x1A7AB839: //GetMapLocationsRequestMessage
			handleGetMapLocationsRequestMessage(pack);
			break;
		case 0x20E4DBE3: //ClientChatRoomMessage
			handleChatRoomMessage(pack);
			break;
		}
		
		break;
	case 6:
		switch(opcode) {
		case 0x25A29FA6:
			handleSendMail(pack);
			break;
		}
		break;
	case 7:
		switch (opcode) {
		case 0x35366BED:
			handleChatCreateRoom(pack);
			break;
		}
		
		break;
	case 8:
		break;
	case 12:
		switch (opcode) {
		case 0xB97F3074: //ClientCreateCharacter
			handleClientCreateCharacter(pack);
			break;
		}
		
		break;
	default:
		//error("unhandled operand count" + pack->toString());
		break;
	}
}

void ZonePacketHandler::handleClientPermissionsMessage(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	uint32 accountID = ClientIDMessage::parse(pack);
	client->setSessionKey(accountID);
	
	Message* cpm = new ClientPermissionsMessage();
	client->sendMessage(cpm);

}

void ZonePacketHandler::handleSelectCharacter(Message* pack) {
	PlayerManager* playerManager = server->getPlayerManager();
	
	ZoneClientImplementation* clientimpl = (ZoneClientImplementation*) pack->getClient();
	ZoneClient* client = (ZoneClient*) clientimpl->_getStub();
	
	uint64 characterID = SelectCharacter::parse(pack);
	uint64 playerID = (characterID << 32) + 0x15;
	
	Player* player = NULL;

	SceneObject* obj = server->getObject(playerID);
	if (obj != NULL) {
		player = (Player*) obj;
		player->reload(client);
	} else {
		player = playerManager->load(characterID);
		player->setZone(server->getZone(player->getZoneIndex()));
		
		player->load(client);
	}
		
	clientimpl->setLockName("ZoneClient = " + player->getFirstName());
}

void ZonePacketHandler::handleCmdSceneReady(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Message* csr = new CmdSceneReady();
	client->sendMessage(csr);
	
	client->resetPacketCheckupTime();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;

	try {
		player->wlock();

		player->notifySceneReady();

		player->unlock();
	} catch (...) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler::handleCmdSceneReady(Message* pack)\n";
	}
}

void ZonePacketHandler::handleClientCreateCharacter(Message* pack) {
	PlayerManager* playerManager = server->getPlayerManager();

	ZoneClientImplementation* clientimpl = (ZoneClientImplementation*) pack->getClient();
	ZoneClient* client = (ZoneClient*) clientimpl->_getStub();
	
	PlayerImplementation* playerImpl = new PlayerImplementation();

	ClientCreateCharacter::parse(pack, playerImpl);

	if (!playerManager->validateName(playerImpl->getFirstName())) {
		Message* msg = new ClientCreateCharacterFailed("name_declined_in_use");
		client->sendMessage(msg);
		
		return;
	}
	
	Player* player = playerImpl->create(client);

	playerImpl->setZoneProcessServer(processServer);

	try {
		player->wlock();

		uint32 skey = client->getSessionKey();
		
		if (playerManager->create(player, skey)) {
			Message* hb = new HeartBeat();
			client->sendMessage(hb);
			
			Message* msg = new ClientCreateCharacterSuccess(player->getCharacterID());
			player->sendMessage(msg);
			
			Zone* zone = server->getZone(player->getZoneIndex());
			player->setZone(zone);
	
			player->createItems();

			player->insertToZone(zone);
			// It'll bounce back to login screen saying the server is offline.
			
			player->unlock();
			
			player->disconnect();
			
			player->wlock();
			
			server->removeCachedObject(player->getObjectID());
		} else {
			Message* msg = new ClientCreateCharacterFailed("name_declined_in_use");
			player->sendMessage(msg);
		}
	
		player->unlock();
	} catch (Exception& e) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler::handleClientCreateCharacter()\n" << e.getMessage() << "\n";
	} catch (...) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler::handleClientCreateCharacter()\n";
	}
}

void ZonePacketHandler::handleClientRandomNameRequest(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
}

void ZonePacketHandler::handleObjectControllerMessage(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	Player* player = client->getPlayer();	
	if (player == NULL)
		return;

	uint32 header1 = pack->parseInt();
	uint32 header2 = pack->parseInt();
	
	stringstream msg;
	
	try {
		player->wlock();
		if (!player->isOnline()) {
			player->unlock();
			return;
		}

		switch (header1) {
		case 0x21:
			switch (header2) {
			case 0x71:
				//msg << "light chaging position (" << player->getPositionX() << ", " << player->getPositionY() << ") ->";
			
				if (ObjectControllerMessage::parseDataTransform(player, pack)) {
					//msg << "(" << player->getPositionX() << ", " << player->getPositionY() << ")";
			
					//player->info(msg.str(), true);

					player->lightUpdateZone();
				} /*else 
					player->info(msg.str(), true);*/
				
				break;
			case 0xF1:
				/*uint64 parent = ObjectControllerMessage::parseDataTransformWithParent(player, pack);
				player->lightUpdateZoneWithParent(parent);*/
				break;
			}
			break;
		case 0x23:
			switch (header2) {
			case 0x71:
				//msg << "light chaging position (" << player->getPositionX() << ", " << player->getPositionY() << ") ->";

				if (ObjectControllerMessage::parseDataTransform(player, pack)) {
					/*msg << "(" << player->getPositionX() << ", " << player->getPositionY() << ")";
			
					player->info(msg.str(), true);*/

					player->updateZone();
				} /*else 
					player->info(msg.str(), true);*/
					
				break;
			case 0xF1:
				/*uint64 parent = ObjectControllerMessage::parseDataTransformWithParent(player, pack);
				player->updateZoneWithParent(parent);*/
				break;
			case 0x116:
				ObjectControllerMessage::parseCommandQueueEnqueue(player, pack, processServer);
				break;
			case 0x117:
				ObjectControllerMessage::parseCommandQueueClear(player, pack);
				break;
			case 0x146:
				ObjectControllerMessage::parseRadialRequest(player, pack, processServer->getRadialManager());
				break;
			}
			break;
		case 0x83:
			switch (header2) {
			case 0x126:
				ObjectControllerMessage::parseObjectTargetUpdate(player, pack);
				break;
			}
			break;
		default:
			//msg << "unhandled ObjectControllerMessageHeader [" << header2 << "] " << pack->toString();	
			//error(msg);
			break;
		}

		player->unlock();
	} catch (Exception& e) {
		player->unlock();
		
		cout << "exception on ZonePacketHandler:::handleObjectControllerMessage(Message* pack)\n";
		cout << e.getMessage() << "\n";
		
		e.printStackTrace();
	} catch (...) {
		player->unlock();
		
		cout << "unreported exception on ZonePacketHandler:::handleObjectControllerMessage(Message* pack)\n";
	}
}

void ZonePacketHandler::handleTellMessage(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;

	try {
		player->wlock();

		if (player->isOnline()) {
			ChatManager* chatManager = server->getChatManager();
			chatManager->handleTellMessage(player, pack);
		}

		player->unlock();
	} catch (...) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler:::handleTellMessage(Message* pack)\n";
	}
}

void ZonePacketHandler::handleSendMail(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
	
	//cout << pack->toString() << "\n";
		
	unicode header, body;
	string name;
	
	pack->parseUnicode(body);
	pack->shiftOffset(8);

	pack->parseUnicode(header);
	pack->shiftOffset(4);

	pack->parseAscii(name);
	
	ChatManager* chatManager = server->getChatManager();
	chatManager->sendMail(player->getFirstName(), header, body, name);
}

void ZonePacketHandler::handleRequestPersistentMsg(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
	
	pack->shiftOffset(4); //skip spacer/unk
	uint32 mailid = pack->parseInt();
	
	ChatManager* chatManager = server->getChatManager();
	chatManager->sendMailBody(player, mailid);
}

void ZonePacketHandler::handleDeletePersistentMsg(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	uint32 mailid = pack->parseInt();
	
	ChatManager* chatManager = server->getChatManager();
	chatManager->deleteMail(mailid);
}

void ZonePacketHandler::handleFactionRequestMessage(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	Player* player = client->getPlayer();
	if (player == NULL)
		return;

	try {
		player->wlock();
		
		FactionResponseMessage* frm = new FactionResponseMessage(player->getFactionRank(), player->getRebelPoints(), player->getImperialPoints());
		
		//on live we would want to retrive factions for each player
		
		frm->addFactionCount(0x01);
		frm->addFactionName("SWGEmu");
		frm->addFactionCount(0x01);
		frm->addFactionPoint(2007.0f);
		
		player->sendMessage(frm);

		player->unlock();
	} catch (...) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler:::handleTellMessage(Message* pack)\n";
	}
}

void ZonePacketHandler::handleGetMapLocationsRequestMessage(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();

	string planet;
    pack->parseAscii(planet);
    
	GetMapLocationsResponseMessage* gmlr = new GetMapLocationsResponseMessage(planet);
	
	try {
		ResultSet* result;
		stringstream query;
		query << "SELECT * FROM planetmap WHERE lower(planet) = '" << planet << "';";
		result = ServerDatabase::instance()->executeQuery(query);

		while (result->next()) {
			gmlr->addMapLocation(result->getInt(1),result->getString(2), result->getFloat(3), result->getFloat(4), 
			(uint8)result->getInt(5), (uint8)result->getInt(6), (uint8)result->getInt(7));
		}
		
		delete result;
		
	} catch (DatabaseException& e) {
		cout << e.getMessage() << "\n";

		return;
	}
	
	gmlr->dumpLocationList();
	
	//these will be used for other locations on the planet map
	gmlr->addBlankList();
	gmlr->addBlankList();
	
	//unknown
	gmlr->addFooter();
	
	client->sendMessage(gmlr);
}

void ZonePacketHandler::handleStomachRequestMessage(Message* pack) {
	//Send a PLAY update here.
}

void ZonePacketHandler::handleGuildRequestMessage(Message* pack) {
    ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
    Player* player = client->getPlayer();
    
	if (player == NULL)
		return;
	
	try {
		player->wlock();

   		uint64 objectid = pack->parseLong();
    	
    	SceneObject* obj = player->getZone()->lookupObject(objectid);
    	
    	if (obj == NULL) {
    		player->unlock();
    		return;
    	}
    	
    	if (obj->isNonPlayerCreature() || obj->isPlayer()) {
    		
    		CreatureObject* creo = (CreatureObject*) obj;
    		
    		if (creo != player)
    			creo->wlock(player);
		
			GuildResponseMessage* grm = new GuildResponseMessage(creo, objectid);
			client->sendMessage(grm);
			
			if (creo != player)
				creo->unlock();
    	}
    			
		player->unlock();
	} catch (...) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler:::handleGuildRequest(Message* pack)\\\\\\\\n";
	}
}

void ZonePacketHandler::handlePlayerMoneyRequest(Message* pack) {
    ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	Player* player = client->getPlayer();
	
	if (player == NULL)
		return;
	
	try {
		player->wlock();
		
		PlayerMoneyResponseMessage* pmrm = new PlayerMoneyResponseMessage(player);
		client->sendMessage(pmrm);
		
		player->unlock();
	} catch (...) {
		player->unlock();
		cout << "unreported exception on ZonePacketHandler:::handlePlayerMoneyRequest(Message* pack)\n";
	}
}

void ZonePacketHandler::handleTravelListRequest(Message* pack) {
    ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
    Player* player = client->getPlayer();
    
    if (player == NULL)
    	return;
    
	
	uint64 objectid;
	objectid = pack->parseLong();
	string planet;
	pack->parseAscii(planet);
	
	int id = Planet::getPlanetID(planet);
	
	Zone* zone = server->getZone(id);
	
	if (zone != NULL) {
		PlanetManager* planetManager = zone->getPlanetManager();
	
		planetManager->sendPlanetTravelPointListResponse(player);
	}
}

void ZonePacketHandler::handleRadialSelect(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
    Player* player = client->getPlayer();
    
    if (player == NULL)
		return;
    
    processServer->getRadialManager()->handleRadialSelect(player, pack);
}

void ZonePacketHandler::handleChatRoomMessage(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
	
	ChatManager* chatManager = server->getChatManager();
	chatManager->handleChatRoomMessage(player, pack);
}

void ZonePacketHandler::handleChatRequestRoomList(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
	
	ChatManager* chatManager = server->getChatManager();
	chatManager->sendRoomList(player);
}

void ZonePacketHandler::handleChatCreateRoom(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
		
	ChatManager* chatManager = server->getChatManager();
	chatManager->handleCreateRoom(player, pack);
}

void ZonePacketHandler::handleChatEnterRoomById(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
		
	ChatManager* chatManager = server->getChatManager();
	chatManager->handleChatEnterRoomById(player, pack);
}

void ZonePacketHandler::handleChatDestroyRoom(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
		
	ChatManager* chatManager = server->getChatManager();
	chatManager->handleChatDestroyRoom(player, pack);
}

void ZonePacketHandler::handleChatRemoveAvatarFromRoom(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	
	Player* player = client->getPlayer();
	if (player == NULL)
		return;
		
	ChatManager* chatManager = server->getChatManager();
	chatManager->handleChatRemoveAvatarFromRoom(player, pack);
}

void ZonePacketHandler::handleSuiEventNotification(Message* pack) {
	ZoneClientImplementation* client = (ZoneClientImplementation*) pack->getClient();
	Player* player = client->getPlayer();	
	if (player == NULL)
		return;
	
	uint32 opcode = pack->parseInt();
	
	uint32 cancel = pack->parseInt();
	uint32 unk1 = pack->parseInt();
	uint32 unk2 = pack->parseInt();
	unicode value;
	
	if (unk2 != 0)
		pack->parseUnicode(value);
	
	switch (opcode) {
	case 0x004D5553:
		if (cancel != 1)
			player->startPlayingMusic(value.c_str());
		break;
	case 0x0044414E:
		if (cancel != 1)
			player->startDancing(value.c_str());
		break;
	/*case 0x4347494C:
		if (cancel != 1)
			processServer->getGuildManager()->handleCreateGuildNameBox(player, value.c_str());
		break;
	case 0x47414242:
		if (cancel != 1)
			processServer->getGuildManager()->handleCreateGuildTagBox(player, value.c_str());
		else
			processServer->getGuildManager()->sendCreateGuildBox(player);
		break;*/		
	default:
		//error("Unknown SuiEventNotification opcode");
		break;
	}

}
