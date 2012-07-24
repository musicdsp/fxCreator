/**
 *******************************************************************************
 * @file MainWindows.cpp
 * @brief Audio FX creator : main Windows diplayer (Sources)
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

#include <appl/Debug.h>
#include <MainWindows.h>

#include <ewol/widget/Button.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/SizerHori.h>
#include <ewol/widget/SizerVert.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Entry.h>
#include <ewol/widget/List.h>
#include <ewol/widget/ContextMenu.h>
#include <ewol/widget/PopUp.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Menu.h>
#include <ewol/widgetMeta/FileChooser.h>
#include <ewol/widgetMeta/Parameter.h>
#include <ewol/WidgetManager.h>
#include <ewol/EObject.h>

#include <appl/generator.h>

#undef __class__
#define __class__	"MainWindows"

MainWindows::MainWindows(void)
{
	APPL_DEBUG("CREATE WINDOWS ... ");
	ewol::SizerVert * mySizerVert = NULL;
	ewol::SizerVert * mySizerVert2 = NULL;
	ewol::SizerHori * mySizerHori = NULL;
	//ewol::Button * myButton = NULL;
	ewol::Menu * myMenu = NULL;
	
	mySizerVert = new ewol::SizerVert();
	SetSubWidget(mySizerVert);
	
		mySizerHori = new ewol::SizerHori();
		mySizerVert->SubWidgetAdd(mySizerHori);
			
			
			
		mySizerHori = new ewol::SizerHori();
		mySizerVert->SubWidgetAdd(mySizerHori);
			
			myMenu = new ewol::Menu();
			mySizerHori->SubWidgetAdd(myMenu);
			int32_t idMenuFile = myMenu->AddTitle("File");
				/*
				(void)myMenu->Add(idMenuFile, "New",          "", ednMsgGuiNew);
				(void)myMenu->AddSpacer();
				(void)myMenu->Add(idMenuFile, "Open",         "icon/Load.svg", ednMsgGuiOpen);
				(void)myMenu->Add(idMenuFile, "Close",        "icon/Close.svg", ednMsgGuiClose, "current");
				(void)myMenu->Add(idMenuFile, "Close (all)",  "", ednMsgGuiClose, "All");
				(void)myMenu->Add(idMenuFile, "Save",         "icon/Save.svg", ednMsgGuiSave, "current");
				(void)myMenu->Add(idMenuFile, "Save As ...",  "", ednMsgGuiSaveAs);
				*/
			
			m_widgetLabelFileName = new ewol::Label("FileName");
			m_widgetLabelFileName->SetExpendX(true);
			m_widgetLabelFileName->SetFillY(true);
			mySizerHori->SubWidgetAdd(m_widgetLabelFileName);
		
	// Generic event ...
	//RegisterMultiCast(ednMsgGuiSaveAs);
	
}


MainWindows::~MainWindows(void)
{
	
}


const char *const ednEventPopUpFileSelected = "edn-mainWindows-openSelected";
const char *const ednEventPopUpFileSaveAs   = "edn-mainWindows-saveAsSelected";

/**
 * @brief Receive a message from an other EObject with a specific eventId and data
 * @param[in] CallerObject Pointer on the EObject that information came from
 * @param[in] eventId Message registered by this class
 * @param[in] data Data registered by this class
 * @return ---
 */
void MainWindows::OnReceiveMessage(ewol::EObject * CallerObject, const char * eventId, etk::UString data)
{
	ewol::Windows::OnReceiveMessage(CallerObject, eventId, data);
	
	return;
}


/**
* @brief Inform object that an other object is removed ...
* @param[in] removeObject Pointer on the EObject remeved ==> the user must remove all reference on this EObject
* @note : Sub classes must call this class
* @return ---
*/
void MainWindows::OnObjectRemove(ewol::EObject * removeObject)
{
	ewol::Windows::OnObjectRemove(removeObject);
/*
	if (m_widgetLabelFileName == removeObject) {
		m_widgetLabelFileName = NULL;
	}
*/
}
