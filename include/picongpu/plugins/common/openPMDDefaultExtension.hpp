/* Copyright 2022 Sergei Bastrakov
 *
 * This file is part of PIConGPU.
 *
 * PIConGPU is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PIConGPU is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PIConGPU.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <string>

#include <openPMD/openPMD.hpp>

namespace picongpu
{
    namespace openPMD
    {
        enum class ExtensionPreference
        {
            ADIOS,
            HDF5
        };

        /** Get default extension for openPMD files
         *
         * Make a uniform choice when several valid backends are available.
         * Check that at least one valid backend is available.
         *
         * This function can only be compiled when openPMD is enabled.
         */
        inline std::string getDefaultExtension(ExtensionPreference ep = ExtensionPreference::ADIOS)
        {
            using EP = ExtensionPreference;
            auto getADIOSExtension = []()
            {
                auto availableExtensions = ::openPMD::getFileExtensions();
                for(auto const& ext : availableExtensions)
                {
                    if(ext == "bp4")
                    {
                        return "bp4";
                    }
                }
                /*
                 * BP4 engine is always available in all supported ADIOS2 versions,
                 * but the bp4 extensions is new in openPMD, so we might need to
                 * fallback to "bp".
                 */
                return "bp";
            };
#if openPMD_HAVE_ADIOS2 && openPMD_HAVE_HDF5
            switch(ep)
            {
            case EP::ADIOS:
                return getADIOSExtension();
            case EP::HDF5:
                return "h5";
            }
            /*
             * This silences compiler warnings
             */
            return "[openPMD::getDefaultExtension()] Unreachable!";
#elif openPMD_HAVE_ADIOS2
            return getADIOSExtension();
#elif openPMD_HAVE_HDF5
            return "h5";
#else
            // Neither ADIOS2 nor HDF5 is not allowed when openPMD is enabled (we can only be here in this case)
            static_assert(
                false,
                "Error: openPMD API dependency is enabled but has neither ADIOS2 nor HDF5 backend available.");
#endif
        }
    } // namespace openPMD
} // namespace picongpu
