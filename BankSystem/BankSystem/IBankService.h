#pragma once

class IBankService {

public:

	// pure virtual functions, have to be implemented/overrided in the child classes
	virtual void executeBankService()=0;
	virtual void respondFlirt()=0;
};
