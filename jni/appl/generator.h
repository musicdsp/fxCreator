/**
 *******************************************************************************
 * @file appl/generator.cpp
 * @brief Fx Creator : audio generator (Sources)
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
 
#ifndef __GENERATOR_H__
#define __GENERATOR_H__

namespace generator {
	void PlaySample(void);
	
	void GenerateAudio(int16_t * bufferInterlace, int32_t nbSample, int32_t nbChannels);
	void GenerateBasicPickUpCoin(void);
	void GenerateBasicLaserShoot(void);
	void GenerateBasicExplosion(void);
	void GenerateBasicPowerUp(void);
	void GenerateBasicHitHurt(void);
	void GenerateBasicJump(void);
	void GenerateBasicBlipSelect(void);
	void GenerateBasicRandom(void);
	void GenerateBasicMutate(void);
	void    SetWaveType(int32_t newVal);
	int32_t GetWaveType(void);
	void  SetBaseFreq(float newVal);
	float GetBaseFreq(void);
	void  SetFreqLimit(float newVal);
	float GetFreqLimit(void);
	void  SetFreqRamp(float newVal);
	float GetFreqRamp(void);
	void  SetFreqDRamp(float newVal);
	float GetFreqDRamp(void);
	void  SetDuty(float newVal);
	float GetDuty(void);
	void  SetDutyRamp(float newVal);
	float GetDutyRamp(void);
	void  SetVibStrength(float newVal);
	float GetVibStrength(void);
	void  SetVibSpeed(float newVal);
	float GetVibSpeed(void);
	void  SetVibDelay(float newVal);
	float GetVibDelay(void);
	void  SetEnvAttack(float newVal);
	float GetEnvAttack(void);
	void  SetEnvSustain(float newVal);
	float GetEnvSustain(void);
	void  SetEnvDecay(float newVal);
	float GetEnvDecay(void);
	void  SetEnvPunch(float newVal);
	float GetEnvPunch(void);
	void  SetFilterOn(bool newVal);
	bool  GetFilterOn(void);
	void  SetLPFResonance(float newVal);
	float GetLPFResonance(void);
	void  SetLPFFreq(float newVal);
	float GetLPFFreq(void);
	void  SetLPFRamp(float newVal);
	float GetLPFRamp(void);
	void  SetHPFFreq(float newVal);
	float GetHPFFreq(void);
	void  SetHPFRamp(float newVal);
	float GetHPFRamp(void);
	void  SetPhaseOffset(float newVal);
	float GetPhaseOffset(void);
	void  SetPhaseRamp(float newVal);
	float GetPhaseRamp(void);
	void  SetRepeatSpeed(float newVal);
	float GetRepeatSpeed(void);
	void  SetArpSpeed(float newVal);
	float GetArpSpeed(void);
	void  SetArpMod(float newVal);
	float GetArpMod(void);
	void  SetMasterVolume(float newVal);
	float GetMasterVolume(void);
	void  SetSoundVolume(float newVal);
	float GetSoundVolume(void);

};

#endif
