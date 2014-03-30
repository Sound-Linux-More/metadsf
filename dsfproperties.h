/***************************************************************************
    copyright            : (C) 2014 by Peking Duck Labs
    email                : pekingducklabs@gmail.com
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 ***************************************************************************/

#ifndef TAGLIB_DSFPROPERTIES_H
#define TAGLIB_DSFPROPERTIES_H

#include <taglib/taglib_export.h>
#include <taglib/audioproperties.h>

#include "dsfheader.h"

namespace TagLib {

  namespace DSF {

    class File;

    //! An implementation of audio property reading for DSF

    /*!
     * This reads the data from a DSF stream found in the
     * AudioProperties API.
     */

    class TAGLIB_EXPORT Properties : public AudioProperties
    {
    public:
      /*!
       * Create an instance of DSF::Properties with the data read from the
       * DSF::File \a file.
       */
      Properties(File *file, ReadStyle style = Average);

      /*!
       * Destroys this DSF Properties instance.
       */
      virtual ~Properties();

      // Reimplementations.

      virtual int length() const;
      virtual int bitrate() const;
      virtual int sampleRate() const;
      virtual int channels() const;

      /*!
       * Returns the DSF Version of the file.
       */
      Header::Version version() const;

      /*!
       * Returns the channel type
       */
      Header::ChannelType channelType() const;

      /*!
       * Returns the ID3v2 offset in the file
       */
      uint64_t ID3v2Offset() const;

      /*!
       * Returns the file size
       */
      uint64_t fileSize() const;

      /*!
       * Returns the sample count
       */
      uint64_t sampleCount() const;

      /*!
       * Returns the bits per sample
       */
      int bitsPerSample() const;

    private:
      Properties(const Properties &);
      Properties &operator=(const Properties &);

      void read();

      class PropertiesPrivate;
      PropertiesPrivate *d;
    };
  }
}

#endif
