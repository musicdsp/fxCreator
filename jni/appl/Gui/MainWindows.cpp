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
#include <ewol/widget/Slider.h>
#include <ewol/widget/Menu.h>
#include <ewol/widgetMeta/FileChooser.h>
#include <ewol/widgetMeta/Parameter.h>
#include <ewol/WidgetManager.h>
#include <ewol/EObject.h>

#include <appl/generator.h>

#undef __class__
#define __class__	"MainWindows"

static const char* const l_applEventPlay = "appl-play";
static const char* const l_applEventBlit = "appl-Blit";
static const char* const l_applEventJump = "appl-Jump";
static const char* const l_applEventHit = "appl-Hit";
static const char* const l_applEventPowerUp = "appl-PowerUp";
static const char* const l_applEventExplosion = "appl-Explosion";
static const char* const l_applEventLaser = "appl-Laser";
static const char* const l_applEventPick = "appl-Pick";
static const char* const l_applEventRandom = "appl-Random";
static const char* const l_applEventMutant = "appl-Mutant";


MainWindows::MainWindows(void)
{
	APPL_DEBUG("CREATE WINDOWS ... ");
	ewol::SizerVert * mySizerVert = NULL;
	ewol::SizerVert * mySizerVert2 = NULL;
	ewol::SizerHori * mySizerHori = NULL;
	ewol::SizerHori * mySizerHori2 = NULL;
	ewol::Button * myButton = NULL;
	ewol::Slider * mySlider = NULL;
	ewol::Label * myLabel = NULL;
	ewol::Menu * myMenu = NULL;
	ewol::Spacer * mySpacer = NULL;
	
	mySizerVert = new ewol::SizerVert();
	SetSubWidget(mySizerVert);
	
		mySizerHori = new ewol::SizerHori();
		mySizerVert->SubWidgetAdd(mySizerHori);
			
			mySizerVert2 = new ewol::SizerVert();
			mySizerHori->SubWidgetAdd(mySizerVert2);
				myButton = new ewol::Button("Play");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventPlay);
				mySizerVert2->SubWidgetAdd(myButton);
				
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				myButton = new ewol::Button("Blip/Select");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventBlit);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Jump");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventJump);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Hit/Hurt");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventHit);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Power up");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventPowerUp);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Explosion");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventExplosion);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Laser/Shoot");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventLaser);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Pick up/Coin");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventPick);
				mySizerVert2->SubWidgetAdd(myButton);
				
				myButton = new ewol::Button("Random");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventRandom);
				mySizerVert2->SubWidgetAdd(myButton);
				myButton = new ewol::Button("Mutant");
				myButton->RegisterOnEvent(this, ewolEventButtonPressed,  l_applEventMutant);
				mySizerVert2->SubWidgetAdd(myButton);
				
			mySizerVert2 = new ewol::SizerVert();
			mySizerHori->SubWidgetAdd(mySizerVert2);
				
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("HP filter cutoff sweep");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("HP filter cutoff");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
					
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("LP filter resonance");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
					
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("LP filter cutoff sweep");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
					
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("LP filter cutoff");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
					
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Phaser sweep");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Phaser offset");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Repeat speed");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Duty sweep");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Square duty");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Change speed");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Change amount");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
	
	
	
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Vibrato speed");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Vibrato depth");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Delta slide");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Slide");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Min frequency");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Start frequency");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySpacer = new ewol::Spacer();
				mySpacer->SetExpendY(true);
				mySizerVert2->SubWidgetAdd(mySpacer);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Decay time");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Sustain punch");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Sustain time");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
				mySizerHori2 = new ewol::SizerHori();
				mySizerVert2->SubWidgetAdd(mySizerHori2);
					myLabel = new ewol::Label("Attack time");
					mySizerHori2->SubWidgetAdd(myLabel);
					mySpacer = new ewol::Spacer();
					mySpacer->SetExpendX(true);
					mySizerHori2->SubWidgetAdd(mySpacer);
					mySlider = new ewol::Slider();
					mySlider->SetMinSize(300);
					mySlider->SetMin(0);
					mySlider->SetMax(100);
					mySizerHori2->SubWidgetAdd(mySlider);
				
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
	if (eventId == l_applEventPlay) {
		generator::PlaySample();
	} else if (eventId == l_applEventBlit) {
		generator::GenerateBasicBlipSelect();
	} else if (eventId == l_applEventJump) {
		generator::GenerateBasicJump();
	} else if (eventId == l_applEventHit) {
		generator::GenerateBasicHitHurt();
	} else if (eventId == l_applEventPowerUp) {
		generator::GenerateBasicPowerUp();
	} else if (eventId == l_applEventExplosion) {
		generator::GenerateBasicExplosion();
	} else if (eventId == l_applEventLaser) {
		generator::GenerateBasicLaserShoot();
	} else if (eventId == l_applEventPick) {
		generator::GenerateBasicPickUpCoin();
	} else if (eventId == l_applEventRandom) {
		generator::GenerateBasicRandom();
	} else if (eventId == l_applEventMutant) {
		generator::GenerateBasicMutate();
	}
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
