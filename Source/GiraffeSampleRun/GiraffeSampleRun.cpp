
#include "stdafx.h"





int main()
{

	MakeJsonData();



	//std::cout << sizeof(Giraffe::Bool8) << std::endl;

	//std::cout << WorkMain() << std::endl;

	system("pause");
    return 0;
}


void MakeJsonData()
{
	JsonData jdata;bangc

	/*
	GameSimulator
		:name
		:version
		WeakPtr<GameRole> gameRole;
		Vector<WeakPtr<UserData>> playUsers;

	GameDataSystem
		:name
		:version
		SharedPtr<GameRoleMng> gameRoles;
			Vector<SharedPtr<GameRole>> roleList;
		SharedPtr<JobMng> jobMng;
			Vector<SharedPtr<JobInfo>> jobList;
		SharedPtr<CardInfoMng> cardInfoMng;
			Vector<SharedPtr<CardInfo>> cardMap;
				WeakPtr<JobInfo> usingJob;
		Vector<SharedPtr<UserData>> userList;
			SharedPtr<DeckMng> myDecks;
				Vector<SharedPtr<Deck>> deckList;
					SharedPtr<JobInfo> myJob;
					Vector<SharedPtr<CardUnit>> cardList;
						SharedPtr<CardInfo> infoData;
							Vector<SharedPtr<JobInfo>> jobList;
	*/

	jdata["Giraffe"]["Name"] = "Giraffe";
	jdata["Giraffe"]["Version"]["Major"] = 0;
	jdata["Giraffe"]["Version"]["Minor"] = 0;
	jdata["Giraffe"]["Version"]["Revision"] = 1;
	jdata["Giraffe"]["Name"] = "Giraffe";
	jdata["Giraffe"]["Name"] = "Giraffe";
	jdata["Giraffe"]["Name"] = "Giraffe";
	jdata["Giraffe"]["Name"] = "Giraffe";

	auto jsonString = jdata.dump();


	std::cout << jsonString << std::endl;
}
