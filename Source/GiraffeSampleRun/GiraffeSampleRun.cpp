
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
	JsonData jdata;

	/*
	GiraffeMain
		:version
		GameSimulator
			WeakPtr<GameRole> gameRole;
			Vector<WeakPtr<UserData>> playUsers;

		GameDataSystem
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
	jdata["Giraffe"]["UniqueKey"] = "Giraffe";
	jdata["Giraffe"]["Version"]["Major"] = 0;
	jdata["Giraffe"]["Version"]["Minor"] = 0;
	jdata["Giraffe"]["Version"]["Revision"] = 1;
	jdata["Giraffe"]["Roles"] = {
		{
			{"RoleName", "B.M.Role"}
			,{"UniqueKey", "Role.47D72AE1-93AF-4C79-95A4-2ECF5F2A312D"}
			, 
		}
		,{
			{"RoleName", "B.B.Role"}
			,{"UniqueKey", "Role.2025D374-D22D-4653-A752-2FD2A405E8E9"}
			,
		}
		, {
			{"RoleName", "M.M.Role"}
			,{"UniqueKey", "Role.5D10EEF0-C9E6-4554-8991-AC55C1AABF53"}
			,
		}
		, 
	};
	jdata["Giraffe"]["Jobs"] = {
		{
			{"JobName", "B.1.Job"}
			,{"UniqueKey", "Job.DC814C2E-34B6-4C6D-8263-8EFA6D08D8CE"}
			,
		}
		, {
			{"JobName", "B.2.Job"}
			,{"UniqueKey", "Job.00F8D969-2C8C-4FD9-9EA4-60104BFA1A62"}
			,
		}
		,{
			{"JobName", "B.C.Job"}
			,{"UniqueKey", "Job.A811C6D2-5B49-4DF3-BD3C-C631C207CE66"}
			,
		}
		,
	};
	jdata["Giraffe"]["Cards"] = {
		{
			{"CardName", "1.Card"}
			, {"UniqueKey", "Card.7A35EB5C-E6A5-4768-8C1D-FEC75A128DBE"}
			, {"NeedJob", {"Job.DC814C2E-34B6-4C6D-8263-8EFA6D08D8CE"}}
			, {"AbleRole", {"Role.47D72AE1-93AF-4C79-95A4-2ECF5F2A312D"
				, "Role.2025D374-D22D-4653-A752-2FD2A405E8E9"}}
		}
		, {
			{"CardName", "2.Card"}
			,{"UniqueKey", "Card.A5B28563-2F6B-47F9-B263-435080287414"}
		}
	};

	auto jsonString = jdata.dump();


	std::cout << jsonString << std::endl;
}
