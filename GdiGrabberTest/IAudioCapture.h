#ifndef IAUDIOCAPTURE_H
#define IAUDIOCAPTURE_H

#include "MediaRecordTypeDef.h"

namespace MediaFileRecorder
{
	class IAudioCaptureDataCb
	{
	public:
		virtual void OnCapturedMicData(const void* audioSamples, int nSamples, const AUDIO_INFO& audioInfo) = 0;

		virtual void OnCapturedSoundCardData(const void* audioSamples, int nSamples, const AUDIO_INFO& audioInfo) = 0;

	protected:
		virtual ~IAudioCaptureDataCb(){};
	};


	class IAudioCapture
	{
	public:
		virtual int RegisterCaptureDataCb(IAudioCaptureDataCb* pDataCb) = 0;
		virtual int UnRegisterCaptureDataCb(IAudioCaptureDataCb* pDataCb) = 0;
		virtual int SetMic(int index) = 0;
		virtual int SetSpeaker(int index) = 0;
		virtual int StartCaptureMic() = 0;
		virtual int StopCaptureMic() = 0;
		virtual int StartCaptureSoundCard() = 0;
		virtual int StopCaptureSoundCard() = 0;

		virtual ~IAudioCapture(){};
	};

	IAudioCapture* CreateAudioCapture();
	void DestroyAudioCatpure(IAudioCapture* pAudioCapture);
}

#endif