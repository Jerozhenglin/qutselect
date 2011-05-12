/* vim:set ts=2 nowrap: ****************************************************

 qutselect - A simple Qt4 based GUI frontend for SRSS (utselect)
 Copyright (C) 2008 by Jens Langner <Jens.Langner@light-speed.de>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 $Id: main.cpp 46 2009-02-05 10:37:59Z langner $

**************************************************************************/

#ifndef _CAPPLICATION_HPP_
#define _CAPPLICATION_HPP_

#include <QApplication>

// forward declarations

class CApplication : public QApplication
{
	Q_OBJECT
  
	public:
		CApplication(int& argc, char** argv);
    ~CApplication();

		bool isInitialized() const { return m_bInitialized; }
		bool wasAborted() const { return m_bAbortFlag; }
		bool hasFailed() const { return m_bFailedFlag; }		
		bool dtLoginMode() const { return m_bDtLoginMode; }
		bool noSunrayServers() const { return m_bNoSRSS; }
		bool noListDisplay() const { return m_bNoList; }
		bool keepAlive() const { return m_bKeepAlive; }
		QString customServerListFile() const { return m_sServerListFile; }

	private:
		bool parseCommandLine(int& argc, char** argv);

	private:
		bool m_bInitialized;
		bool m_bAbortFlag;
		bool m_bFailedFlag;
		bool m_bQuietFlag;

		// for our configuration
		bool		m_bDtLoginMode;
		bool		m_bNoSRSS;
		bool		m_bNoList;
		bool		m_bKeepAlive;
		QString m_sServerListFile;
};

#endif // _CAPPLICATION_H_