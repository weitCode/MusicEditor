/**************************************************************************
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**************************************************************************/

#ifndef MEAUIDOENCODER_H
#define MEAUIDOENCODER_H
#include <QtCore>
#include "OtherClass/ffmpeg.h"
class MEAudioDecoder;
class MEAuidoEncoder
{
public:
    MEAuidoEncoder();
    ~MEAuidoEncoder();
    int OpenFile(const QString& fileName,int sampleRate,int bitRate,int channels);
    int init();
    void dealloc();
    int encode(MEAudioDecoder* decoder);
    const AVCodecContext* getAVCodecContext();
    const AVFormatContext* getAVFormatContext();
    const AVCodec* getAVCodec();
private:
    AVFormatContext *oFmtCtx;
    AVCodecContext *oCodecCtx;
    AVCodec *pOutCodec;

    AVOutputFormat * oFormat;
    AVStream *oStream;
};

#endif // MEAUIDOENCODER_H