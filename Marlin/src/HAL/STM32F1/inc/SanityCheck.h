/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Test STM32F1-specific configuration values for errors at compile-time.
 */

#if ENABLED(EMERGENCY_PARSER)
  #error "EMERGENCY_PARSER is not yet implemented for STM32F1. Disable EMERGENCY_PARSER to continue."
#endif

#if ENABLED(SDIO_SUPPORT) && DISABLED(SDSUPPORT)
  #error "SDIO_SUPPORT requires SDSUPPORT. Enable SDSUPPORT to continue."
#endif

#if ENABLED(FAST_PWM_FAN)
  #error "FAST_PWM_FAN is not yet implemented for this platform."
#endif

#if !defined(HAVE_SW_SERIAL) && HAS_TMC_SW_SERIAL
  #warning "With TMC2208/9 consider using SoftwareSerialM with HAVE_SW_SERIAL and appropriate SS_TIMER."
  #error "Missing SoftwareSerial implementation."
#endif

#if ENABLED(SDCARD_EEPROM_EMULATION) && DISABLED(SDSUPPORT)
  #undef SDCARD_EEPROM_EMULATION // Avoid additional error noise
  #if USE_FALLBACK_EEPROM
    #warning "EEPROM type not specified. Fallback is SDCARD_EEPROM_EMULATION."
  #endif
  #error "SDCARD_EEPROM_EMULATION requires SDSUPPORT. Enable SDSUPPORT or choose another EEPROM emulation."
#endif

#if ENABLED(SERIAL_STATS_MAX_RX_QUEUED)
  #error "SERIAL_STATS_MAX_RX_QUEUED is not supported on this platform."
#endif

#if ENABLED(SERIAL_STATS_DROPPED_RX)
  #error "SERIAL_STATS_DROPPED_RX is not supported on this platform."
#endif  
