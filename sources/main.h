/*
	Filer - an automatic rule-based file organizer
	
	Written by DarkWyrm <darkwyrm@gmail.com>, Copyright 2008
	Released under the MIT license.
*/

#ifndef MAIN_H
#define MAIN_H

#include <Application.h>
#include <Entry.h>
#include <Message.h>

#include "ObjectList.h"

class FilerRule;
class MainWindow;

class App : public BApplication
{
public:
					App();
					~App();

	void			MessageReceived(BMessage* msg);
	void			RefsReceived(BMessage* msg);
	void			ArgvReceived(int32 argc, char** argv);
	void			ReadyToRun();

	void			SetupTypeMenu();
	void			ShowHTML(const char* docfile);
	void			FileRef(entry_ref ref);
	
private:
	void			ProcessFiles();

	BObjectList<entry_ref>*	fRefList;
	BObjectList<FilerRule>*	fRuleList;
	MainWindow*		fMainWin;
	
	bool			fQuitRequested;
};

#endif	// MAIN_H