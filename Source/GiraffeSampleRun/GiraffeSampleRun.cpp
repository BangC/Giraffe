
#include "stdafx.h"



int main()
{

	auto loadString = MakeJsonData();


	//std::cout << sizeof(Giraffe::Bool8) << std::endl;

	std::cout << WorkMain(loadString) << std::endl;

	system("pause");
    return 0;
}


Giraffe::AString MakeJsonData()
{
	//Giraffe::SharedPtr<JsonData> returnJData = Giraffe::SharedPtr<JsonData>(new JsonData());
	//JsonData &jdata = (*returnJData);
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
					Vector<WeakPtr<GameRole>> ableRoles;
					Vector<SharedPtr<CardUnit>> cardForms;
		GameDataPlay
			Vector<SharedPtr<UserData>> userList;
				SharedPtr<DeckMng> myDecks;
					Vector<SharedPtr<Deck>> deckList;
						SharedPtr<JobInfo> myJob;
						Vector<WeakPtr<CardUnit>> cardList;
	*/

	jdata["Giraffe"]["Name"] = "Giraffe";
	jdata["Giraffe"]["Version"]["Major"] = 0;
	jdata["Giraffe"]["Version"]["Minor"] = 0;
	jdata["Giraffe"]["Version"]["Revision"] = 2;
	jdata["Giraffe"]["Static"]["Roles"] = {
		{ // B.M.Role
			{"RoleName", "B.M.Role"}
			, 
		}
		,{ // B.B.Role
			{"RoleName", "B.B.Role"}
			,
		}
		, { // M.M.Role
			{"RoleName", "M.M.Role"}
			,
		}
		, 
	};
	jdata["Giraffe"]["Static"]["Jobs"] = {
		{ // B.1.Job
			{"JobName", "B.1.Job"}
		}
		, { // B.2.Job
			{"JobName", "B.2.Job"}
		}
		,{ // B.C.Job
			{"JobName", "B.C.Job"}
		}
		,{ // M.1.Job
			{"JobName", "M.1.Job"}
		}
		,
	};
	jdata["Giraffe"]["Static"]["Cards"] = {
		{ // 1.Card
			{"CardName", "1.Card"}
			, {"AbleRole", {"B.M.Role", "B.B.Role"}}
			, {"AbleForms", {
				{
					{"CardFormName", "1.Card.Gold"}
					, {"Gold", true}
				}
			}}
			, {"NeedJob", {"B.1.Job"}}
		}
		, { // 2.Card
			{"CardName", "2.Card"}
			, {"AbleRole", {"B.M.Role", "B.B.Role"}}
		}
	};
	jdata["Giraffe"]["Dynamic"]["Users"] = {
		{ // PlayerA
			{"UserName", "PlayerA"}
			, {"Decks", {
				{ // deck1
					{"DackName", "PlayerA.Deck1"}
					, {"UsingJob", "B.1.Job"}
					, {"CardUnits", {"1.Card","1.Card.Gold","2.Card"}}
				}
				, { // deck2
					{"DackName", "PlayerA.Deck2"}
					,{"UsingJob", "B.2.Job"}
					,{"CardUnits",{"2.Card"}}
				}
			}}
		}
		, { // PlayerB
			{"UserName", "PlayerB"}
			,{"Decks",{
				{
					{"DackName", "PlayerB.Deck1"}
					,{"UsingJob", "B.1.Job"}
					,{"CardUnits",{"1.Card","1.Card.Gold","2.Card"}}
				}
			}}
		}
	};

	auto jsonString = jdata.dump();


	std::cout << "Data : " << jsonString << std::endl << std::endl << std::endl;

	//return returnJData;
	return jsonString;
}
