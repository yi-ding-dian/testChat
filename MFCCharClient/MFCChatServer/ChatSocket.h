#pragma once

// CChatSocket ����Ŀ��

class CChatSocket : public CAsyncSocket
{
public:
	CChatSocket();
	virtual ~CChatSocket();
	
	virtual void OnReceive(int nErrorCode);
};


