/*
Copyright (C) 2015 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PLATFORM_THREAD_20151013_H_
#define PLATFORM_THREAD_20151013_H_

#include "IThread.h"

namespace DebuggerCore {

class PlatformThread : public IThread {
	friend class DebuggerCore;
public:
	typedef std::shared_ptr<PlatformThread> pointer;
	
public:
	enum State {
		Stopped,
		Signaled
	};
public:
	PlatformThread();
	PlatformThread(edb::tid_t tid);
	virtual ~PlatformThread() override;
	
private:
	PlatformThread(const PlatformThread &) = delete;
	PlatformThread& operator=(const PlatformThread &) = delete;
	
public:
	virtual edb::tid_t tid() const override;
	
private:
	edb::tid_t tid_;
	int        status_;
	State      state_;
};

}

#endif
