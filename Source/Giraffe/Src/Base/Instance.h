//! @file Instance.h
//! 싱글턴 관리

#pragma once

#include <memory>


namespace Giraffe
{

//////////////////////////////////////////////////////////////////////////
//CInstance////////////////////////////////////////////////////////////////////////

//! shared_ptr로 구현한 싱글턴 부모 객체
//! 사용예
//! class CInfinityGym : public CInstance<CInfinityGym>
//! { }
//! BCreateLockMode : 객체의 생성과 삭제를 Lock과 Unlock으로 제어한다.
template <typename TypeInstance, bool BCreateLockMode = false>
class CInstance
{
public:
	//! 에러 문자열
	enum E_InstanseError
	{
		E_IE_NoneCreate, //!< Get 이전에 생성 먼저 해주세요. (아님 지운이후 호출)
		E_IE_CreateLock, //!< CreateLockMode 중 언락하지 않고 객체를 생성하려 했다.
	};
protected:
	CInstance(); //!< 생성자

	template<typename TInitData>
	CInstance(TInitData tInitData); //!< 생성자
public:

	virtual ~CInstance(); //!< 소멸자
	
	//! 객체 생성. _CreateInstance()를 사용해서 객체를 만든다
	//! @return 객체 생성 성공 여부
	static bool CreateInstance();

	//! 객체 생성. _CreateInstance(TInitData) 를 사용해서 객체를 만든다
	//! @return 객체 생성 성공 여부
	template <typename TInitData>
	static bool CreateInstance(TInitData tInitData);

	static void DestoryInstance(); //!< 객체 소멸

	//! 부모가 자식을 생성하기 위해 자식::_CreateInstance() 를 호출한다
	//! 기본생성자가 아니라면
	//! 오버라이딩 해서 각자 상황에 맞게 객체 생성
	//! protected: 로하니 부모에서 자식의 protected 함수를 접근 못한다 ㅜ
	//! @return 객체 리턴
	static std::shared_ptr<TypeInstance> _CreateInstance();

	template<typename TInitData>
	static std::shared_ptr<TypeInstance> _CreateInstance(TInitData tInitData);
	
	//! 객체를 가져옴
	//! @return 객체 리턴
	static std::shared_ptr<TypeInstance> GetInstance();
	
	//! 객체를 가져옴 없으면 기본생성자를 이용해 만들어줌
	//! @return 객체 리턴
	static std::shared_ptr<TypeInstance> GetInstanceForce();


	//! 객체가 살아있는지 확인
	//! @return 살아있다면 True
	static bool IsLive();


	//! 생성 제한이 걸려있는지 확인한다.
	//! 제한중이면 에러를 발생
	static void CreateLockCheck();
	static void CreateLock(); //! 객체 생성을 락한다.
	static void CreateUnlock(); //! 객체 생성을 언락한다.

	
private:
	static std::shared_ptr<TypeInstance> m_sptrInstance; //!< 자신 객체를 가지고있음

	static bool m_bCreateLock; //!< LockAble 모드의 경우 m_bLock 이 true이면 객체 생성을 못한다.

};

//CInstance////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//CInstance////////////////////////////////////////////////////////////////////////

template <typename TypeInstance, bool BCreateLockMode>
std::shared_ptr<TypeInstance> CInstance<TypeInstance, BCreateLockMode>::m_sptrInstance;

template <typename TypeInstance, bool BCreateLockMode>
bool CInstance<TypeInstance, BCreateLockMode>::m_bCreateLock = true;

template <typename TypeInstance, bool BCreateLockMode>
CInstance<TypeInstance, BCreateLockMode>::CInstance()
{

}

template <typename TypeInstance, bool BCreateLockMode>
template <typename TInitData>
CInstance<TypeInstance, BCreateLockMode>::CInstance(TInitData tInitData)
{

}

template <typename TypeInstance, bool BCreateLockMode>
CInstance<TypeInstance, BCreateLockMode>::~CInstance()
{

}

template <typename TypeInstance, bool BCreateLockMode>
bool CInstance<TypeInstance, BCreateLockMode>::CreateInstance()
{
	CreateLockCheck();

	DestoryInstance();
	std::shared_ptr<TypeInstance> sptrThis = TypeInstance::_CreateInstance();
	if (!sptrThis)
	{
		return false;
	}

	m_sptrInstance = sptrThis;
	return true;	
}

template <typename TypeInstance, bool BCreateLockMode>
template<typename TInitData>
bool CInstance<TypeInstance, BCreateLockMode>::CreateInstance(TInitData tInitData)
{
	CreateLockCheck();

	DestoryInstance();
	std::shared_ptr<TypeInstance> sptrThis = TypeInstance::_CreateInstance(tInitData);
	if (!sptrThis)
	{
		return false;
	}

	m_sptrInstance = sptrThis;
	return true;
}

template <typename TypeInstance, bool BCreateLockMode>
std::shared_ptr<TypeInstance> CInstance<TypeInstance, BCreateLockMode>::_CreateInstance()
{
	return std::shared_ptr<TypeInstance>(new TypeInstance());
}

template <typename TypeInstance, bool BCreateLockMode>
template<typename TInitData>
std::shared_ptr<TypeInstance> CInstance<TypeInstance, BCreateLockMode>::_CreateInstance(TInitData tInitData)
{
	return std::shared_ptr<TypeInstance>(new TypeInstance(tInitData));
}

template <typename TypeInstance, bool BCreateLockMode>
void CInstance<TypeInstance, BCreateLockMode>::DestoryInstance()
{
	CreateLockCheck();

	m_sptrInstance.reset();
}

template <typename TypeInstance, bool BCreateLockMode>
std::shared_ptr<TypeInstance> CInstance<TypeInstance, BCreateLockMode>::GetInstance()
{
	if (!IsLive())
	{
		// 만들어진 객체 없음
		throw E_IE_NoneCreate;
	}
	return m_sptrInstance;
}

template <typename TypeInstance, bool BCreateLockMode>
std::shared_ptr<TypeInstance> CInstance<TypeInstance, BCreateLockMode>::GetInstanceForce()
{
	if (!IsLive())
	{
		CreateInstance();
	}

	return m_sptrInstance;
}


template <typename TypeInstance, bool BCreateLockMode>
bool CInstance<TypeInstance, BCreateLockMode>::IsLive()
{
	return (bool)m_sptrInstance;
}


template <typename TypeInstance, bool BCreateLockMode>
void CInstance<TypeInstance, BCreateLockMode>::CreateLockCheck()
{
	if (BCreateLockMode)
	{
		if (m_bCreateLock)
		{
			// CreateUnlock 후 생성하세요.
			throw E_IE_CreateLock;
		}
	}
}


template <typename TypeInstance, bool BCreateLockMode>
void CInstance<TypeInstance, BCreateLockMode>::CreateLock()
{
	if (BCreateLockMode)
	{
		m_bCreateLock = true;
	}
}

template <typename TypeInstance, bool BCreateLockMode>
void CInstance<TypeInstance, BCreateLockMode>::CreateUnlock(){
	if (BCreateLockMode)
	{
		m_bCreateLock = false;
	}
}



//CInstance////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


}