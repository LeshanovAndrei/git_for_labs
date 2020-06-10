#pragma once

class mexception
{
	const char* _message;
public:
	mexception() : _message("unknown exception") {}
	explicit mexception(const char* what) : _message(what) {}

	virtual const char* what() { return _message; };
	virtual ~mexception() { delete[] _message; }
};