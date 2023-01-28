/*
 * Copyright (C) 2023 Paul Davis <paul@linuxaudiosystems.com>
 *
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __ardour_cliprec_h__
#define __ardour_cliprec_h__


#include "pbd/ringbufferNPT.h"

#include "ardour/processor.h"

namespace ARDOUR {

class AudioFileSource;
class Session;

template<typename T> class MidiRingBuffer;

class LIBARDOUR_API ClipRecProcessor : public Processor
{
  public:
	ClipRecProcessor (Session&, std::string const & name);
	void run (BufferSet& bufs, samplepos_t start_sample, samplepos_t end_sample, double speed, pframes_t nframes, bool result_required);
	bool can_support_io_configuration (const ChanCount& in, ChanCount& out);

  private:

};

} /* namespace */

#endif /* __ardour_cliprec_h__ */