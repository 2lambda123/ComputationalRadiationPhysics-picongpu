/* Copyright 2016-2023 Rene Widera
 *
 * This file is part of PMacc.
 *
 * PMacc is free software: you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License or
 * the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PMacc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License and the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * and the GNU Lesser General Public License along with PMacc.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "pmacc/assert.hpp"
#include "pmacc/types.hpp"


namespace pmacc
{
    /** Wrapper for cuplaEvent_t
     *
     * This class follows the RAII rules
     */
    class CudaEvent
    {
    private:
        /** native cupla event */
        cuplaEvent_t event;
        /** native cupla stream where the event is recorded
         *
         *  only valid if isRecorded is true
         */
        cuplaStream_t stream;
        /** state if event is recorded */
        bool isRecorded{false};
        /** state if a recorded event is finished
         *
         * avoid cupla driver calls after `isFinished()` returns the first time true
         */
        bool finished{true};

        /** number of CudaEventHandle's to the instance */
        uint32_t refCounter{0u};


    public:
        /** Constructor
         *
         * if called before the cupla device is initialized the behavior is undefined
         */
        CudaEvent();

        /** Destructor */
        ~CudaEvent();

        /** register a existing handle to a event instance */
        void registerHandle();

        /** free a registered handle */
        void releaseHandle();

        /** get native cuplaEvent_t object
         *
         * @return native cupla event
         */
        cuplaEvent_t operator*() const
        {
            return event;
        }

        /** get stream in which this event is recorded
         *
         * @return native cupla stream
         */
        cuplaStream_t getStream() const
        {
            assert(isRecorded);
            return stream;
        }

        /** check whether the event is finished
         *
         * @return true if event is finished else false
         */
        bool isFinished();

        /** record event in a device stream
         *
         * @param stream native cupla stream
         */
        void recordEvent(cuplaStream_t stream);
    };
} // namespace pmacc
