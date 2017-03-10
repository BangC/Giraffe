//! @file Instance.h
//! �̱��� ����

#pragma once

#include <memory>


namespace Giraffe
{

//////////////////////////////////////////////////////////////////////////
//CInstance////////////////////////////////////////////////////////////////////////

//! shared_ptr�� ������ �̱��� �θ� ��ü
//! ��뿹
//! class CInfinityGym : public CInstance<CInfinityGym>
//! { }
//! BCreateLockMode : ��ü�� ������ ������ Lock�� Unlock���� �����Ѵ�.
template <typename TypeInstance, bool BCreateLockMode = false>
class CInstance
{
public:
	//! ���� ���ڿ�
	enum E_InstanseError
	{
		E_IE_NoneCreate, //!< Get ������ ���� ���� ���ּ���. (�ƴ� �������� ȣ��)
		E_IE_CreateLock, //!< CreateLockMode �� ������� �ʰ� ��ü�� �����Ϸ� �ߴ�.
	};
protected:
	CInstance(); //!< ������

	template<typename TInitData>
	CInstance(TInitData tInitData); //!< ������
public:

	virtual ~CInstance(); //!< �Ҹ���
	
	//! ��ü ����. _CreateInstance()�� ����ؼ� ��ü�� �����
	//! @return ��ü ���� ���� ����
	static bool CreateInstance();

	//! ��ü ����. _CreateInstance(TInitData) �� ����ؼ� ��ü�� �����
	//! @return ��ü ���� ���� ����
	template <typename TInitData>
	static bool CreateInstance(TInitData tInitData);

	static void DestoryInstance(); //!< ��ü �Ҹ�

	//! �θ� �ڽ��� �����ϱ� ���� �ڽ�::_CreateInstance() �� ȣ���Ѵ�
	//! �⺻�����ڰ� �ƴ϶��
	//! �������̵� �ؼ� ���� ��Ȳ�� �°� ��ü ����
	//! protected: ���ϴ� �θ𿡼� �ڽ��� protected �Լ��� ���� ���Ѵ� ��
	//! @return ��ü ����
	static std::shared_ptr<TypeInstance> _CreateInstance();

	template<typename TInitData>
	static std::shared_ptr<TypeInstance> _CreateInstance(TInitData tInitData);
	
	//! ��ü�� ������
	//! @return ��ü ����
	static std::shared_ptr<TypeInstance> GetInstance();
	
	//! ��ü�� ������ ������ �⺻�����ڸ� �̿��� �������
	//! @return ��ü ����
	static std::shared_ptr<TypeInstance> GetInstanceForce();


	//! ��ü�� ����ִ��� Ȯ��
	//! @return ����ִٸ� True
	static bool IsLive();


	//! ���� ������ �ɷ��ִ��� Ȯ���Ѵ�.
	//! �������̸� ������ �߻�
	static void CreateLockCheck();
	static void CreateLock(); //! ��ü ������ ���Ѵ�.
	static void CreateUnlock(); //! ��ü ������ ����Ѵ�.

	
private:
	static std::shared_ptr<TypeInstance> m_sptrInstance; //!< �ڽ� ��ü�� ����������

	static bool m_bCreateLock; //!< LockAble ����� ��� m_bLock �� true�̸� ��ü ������ ���Ѵ�.

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
		// ������� ��ü ����
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
			// CreateUnlock �� �����ϼ���.
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