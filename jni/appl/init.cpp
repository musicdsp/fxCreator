/**
 *******************************************************************************
 * @file init.cpp
 * @brief Fx Creator main file
 * @author Edouard DUPIN
 * @date 24/07/2012
 * @par Project
 * fxCreator
 *
 * @par Copyright
 * Copyright 2010 Edouard DUPIN, all right reserved
 *
 * This software is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY.
 *
 * Licence summary : 
 *    You can modify and redistribute the sources code and binaries.
 *    You can send me the bug-fix
 *    You can not earn money with this Software (if the source extract from Edn
 *        represent less than 50% of original Sources)
 * Term of the licence in in the file licence.txt.
 *
 *******************************************************************************
 */

#include <etk/UString.h>
#include <ewol/ewol.h>
#include <ewol/EObject.h>
#include <ewol/WidgetManager.h>

#include <appl/Debug.h>
#include <etk/File.h>
#include <etk/tool.h>
#include <Gui/MainWindows.h>
#include <unistd.h>
#include <globalMsg.h>
#include <ewol/Audio/audio.h>
#include <appl/generator.h>

MainWindows * basicWindows = NULL;


/**
 * @brief main application function Initialisation
 */
void APP_Init(void)
{
	#ifdef __PLATFORM__Linux
		#ifdef MODE_RELEASE
			APPL_INFO("==> Init "PROJECT_NAME" (START) (Linux) (Release)");
		#else
			APPL_INFO("==> Init "PROJECT_NAME" (START) (Linux) (Debug)");
		#endif
	#else
		#ifdef MODE_RELEASE
			APPL_INFO("==> Init "PROJECT_NAME" (START) (Android) (Release)");
		#else
			APPL_INFO("==> Init "PROJECT_NAME" (START) (Android) (Debug)");
		#endif
	#endif
	ewol::ChangeSize(800, 600);
	etk::InitDefaultFolder(PROJECT_NAME);

	ewol::SetFontFolder("Font");
	
	#ifdef __PLATFORM__Android
		ewol::SetDefaultFont("freefont/FreeSerif.ttf", 19);
	#else
		ewol::SetDefaultFont("freefont/FreeSerif.ttf", 14);
	#endif
	
	basicWindows = new MainWindows();
	
	if (NULL == basicWindows) {
		APPL_ERROR("Can not allocate the basic windows");
		ewol::Stop();
		return;
	}
	// create the specific windows
	ewol::DisplayWindows(basicWindows);
	// set basic random sound
	generator::GenerateBasicRandom();
	// initialize output audio :
	ewol::audio::Init();
	ewol::audio::AddCallbackOutput(&generator::GenerateAudio);
	// add files
	APPL_INFO("show list of files : ");
	
	APPL_INFO("==> Init Edn (END)");
}


etk::File APP_Icon(void)
{
	return "";
}

/**
 * @brief main application function Un-Initialisation
 */
void APP_UnInit(void)
{
	APPL_INFO("==> Un-Init Edn (START)");
	// Remove windows :
	ewol::DisplayWindows(NULL);
	
	if (NULL != basicWindows) {
		basicWindows->MarkToRemove();
		basicWindows = NULL;
	}
	APPL_INFO("==> Un-Init Edn (END)");
}

